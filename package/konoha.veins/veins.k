/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Software Foundation License 1.0
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

using konoha.clearsilver.*;
using konoha.io.*;
using konoha.json.*;
using konoha.posix.*;
using konoha.sql.*;
using konoha.wsgi.*;
using konoha.ntrace.*;

/* ======================================================================== */
/* Native methods. */

include "lib:gluelink";

@Native @Singleton class Uuid;

@Native String Uuid.getUuid4();

@Native @Public int Date.getYear();
@Native @Public void Date.setYear(int year);
@Native @Public int Date.getMonth();
@Native @Public void Date.setMonth(int month);
@Native @Public int Date.getDay();
@Native @Public void Date.setDay(int day);
@Native @Public int Date.getHour();
@Native @Public void Date.setHour(int hour);
@Native @Public int Date.getMin();
@Native @Public void Date.setMin(int min);
@Native @Public int Date.getSec();
@Native @Public void Date.setSec(int sec);
@Native @Public int Date.getGmtoff();
@Native @Public void Date.setGmtoff(int gmtoff);
@Native @Public String Date.toRFC1123();

@Native @Public Path InputStream.getPath();
@Native @Public Path OutputStream.getPath();
@Native @Public String Func.getName();
@Native @Public String Exception.toString();

/* ======================================================================== */
/* Utilities. */

@Public String String.escapeHtml()
{
    return Cgi.htmlEscape(this);
}

@Public String String.escapeSql()
{
    if (this.indexOf(";") >= 0) {
        throw new Script!!("Invalid sql.");
    }
    return this.replace($/'/, "''").replace($/\\/, "\\\\");
}

/* ======================================================================== */
/* Private methods. */

boolean isDebug()
{
    String debug = $DEBUG;
    if (debug == "true" || debug == "on") {
        return true;
    }
    return false;
}

String getDatabase(String dbname)
{
    if (dbname == null) {
        dbname = "default";
    }
    Map dbs = $DATABASES;
    if (dbs == null) {
        throw new Script!!("$DATABASES is null");
    }
    if (dbs[dbname] == null) {
        if (isDebug()) {
            ERR << "$DATABASES['" + dbname + "'] is null" << EOL;
        }
        dbname = "default";
        if (dbs[dbname] == null) {
            throw new Script!!("$DATABASES['default'] is null");
        }
    }
    if (dbs[dbname]["name"] == null) {
        throw new Script!!("$DATABASES['" + dbname + "']['name'] is null");
    }
    String engine = dbs[dbname]["engine"];
    if (engine == "mysql") {
        String urn = "mysql://" + dbs[dbname]["user"] + ":" + dbs[dbname]["password"];
        urn += "@" + dbs[dbname]["host"] + ":" + dbs[dbname]["port"] + "/";
        urn += dbs[dbname]["name"];
        if (isDebug()) {
            ERR << "urn: " << urn << EOL;
        }
        return urn;
    }
    else if (engine == "sqlite3") {
        String urn = "sqlite3:" + dbs[dbname]["name"];
        if (isDebug()) {
            ERR << "urn: " << urn << EOL;
        }
        return urn;
    }
    throw new Script!!("$DATABASES['" + engine + "']['engine'] is invalid.");
}

String getMediaDir()
{
    String mediadir = $MEDIA_DIR;
    if (mediadir == null) {
        throw new Script!!("$MEDIA_DIR is null");
    }
    return mediadir;
}

String getModelDir()
{
    String modeldir = $MODEL_DIR;
    if (modeldir == null) {
        throw new Script!!("$MODEL_DIR is null");
    }
    return modeldir;
}

String getViewDir()
{
    String viewdir = $VIEW_DIR;
    if (viewdir == null) {
        throw new Script!!("$VIEW_DIR is null");
    }
    return viewdir;
}

String getTmpDir()
{
    String tmpdir = $TMP_DIR;
    if (tmpdir == null) {
        if (isDebug()) {
            ERR << "$TMP_DIR is null" << EOL;
        }
        tmpdir = "/tmp/";
    }
    return tmpdir;
}

String getBaseUrl()
{
    String baseurl = $BASE_URL;
    if (baseurl == null) {
        throw new Script!!("$BASE_URL is null");
    }
    return baseurl;
}

String getStaticUrl()
{
    String staticurl = $STATIC_URL;
    if (staticurl == null) {
        throw new Script!!("$STATIC_URL is null");
    }
    return staticurl;
}

String[] getMiddlewares()
{
    String[] middlewares = $MIDDLEWARES;
    if (middlewares == null) {
        if (isDebug()) {
            ERR << "$MIDDLEWARES is null" << EOL;
        }
        middlewares = [];
    }
    return middlewares;
}

String escapeSqlValue(dynamic sql)
{
    Class c = sql.class;
    if (c == String) {
        return "'" + sql.escapeSql() + "'";
    }
    else if (c == int) {
        int i = sql;
        return ((to String)i).escapeSql();
    }
    else {
        throw new Script!!("sql: Unsupported type is included.");
    }
}

/* ======================================================================== */
/* Classes. */

class AutoIncrementInt;

class Model
{
    String db_path;
    String name;
    int id;

    boolean isMysql() {
        return db_path.startsWith("mysql");
    }

    Model(String name, Map<Class> scheme, String[] primary_keys) {
        name = name.escapeSql();
        _db_path = getDatabase(name);
        _name = name;
        String query = "create table if not exists " + name + "(";
        String[] keys = scheme.keys();
        Map<String> types = {};
        for (int i = 0; i < |keys|; i++) {
            String key = keys[i];
            String column = key.escapeSql();
            String type = "";
            Class c = scheme[key];
            if (c == String) {
                type = "text";
                types[column] = "text";
            }
            else if (c == int) {
                type = "integer";
                types[column] = "integer";
            }
            else if (c == AutoIncrementInt) {
                type = "integer auto_increment";
                types[column] = "integer";
            }
            else {
                throw new Script!!("scheme['" + key + "']: Unsupported type is given.");
            }
            if (i < |keys| - 1) {
                query += column + " " + type + ", ";
            }
            else {
                query += column + " " + type;
                if (|primary_keys| > 0) {
                    query += ", primary key(";
                    for (int j = 0; j < |primary_keys|; j++) {
                        String primary_key = primary_keys[j].escapeSql();
                        if (j < |primary_keys| - 1) {
                            if (isMysql() && types[primary_key] == "text") {
                                query += primary_key + "(128), ";
                            }
                            else {
                                query += primary_key + ", ";
                            }
                        }
                        else {
                            if (isMysql() && types[primary_key] == "text") {
                                query += primary_key + "(128))";
                            }
                            else {
                                query += primary_key + ")";
                            }
                        }
                    }
                }
                query += ")";
            }
        }
        if (isDebug()) {
            ERR << "model query: " << query << EOL;
        }
        Connection con = new Connection(db_path);
        con.exec(query);
        con.close();
    }

    Map[] get(String column, Map param) {
        column = column.escapeSql();
        String query = "select " + column + " from " + name;
        if (param != null && |param| > 0) {
            query += " where ";
            String[] keys = param.keys();
            for (int i = 0; i < |keys|; i++) {
                String key = keys[i];
                String value = escapeSqlValue(param[key]);
                if (i < |keys| - 1) {
                    query += key + " = " + value + " and ";
                }
                else {
                    query += key + " = " + value;
                }
            }
        }
        if (isDebug()) {
            ERR << "get query: " << query << EOL;
        }
        Connection con = new Connection(db_path);
        ResultSet r = con.query(query);
        Map[] results = [];
        while (r.next()) {
            Map record = {};
            for (int i = 0; i < |r|; i++) {
                String name = r.getName(i);
                if (r[name] != null) {
                    record[name] = r[name];
                }
            }
            if (isDebug()) {
                ERR << "record: " << record << EOL;
            }
            results.add(record);
        }
        con.close();
        return results;
    }

    void set(Map record) {
        String query;
        if (isMysql()) {
            query = "insert into " + name + "(";
        }
        else {
            query = "insert or replace into " + name + "(";
        }
        String[] values = [];
        String[] keys = record.keys();
        for (int i = 0; i < |keys|; i++) {
            String key = keys[i];
            values.add(escapeSqlValue(record[key]));
            if (i < |keys| - 1) {
                query += key.escapeSql() + ", ";
            }
            else {
                query += key.escapeSql() + ") values(";
            }
        }
        for (int i = 0; i < |values|; i++) {
            if (i < |values| - 1) {
                query += values[i] + ", ";
            }
            else {
                query += values[i] + ")";
            }
        }
        if (isMysql()) {
            query += " on duplicate key update ";
            for (int i = 0; i < |keys|; i++) {
                if (i < |keys| - 1) {
                    query += keys[i] + " = " + values[i] + ", ";
                }
                else {
                    query += keys[i] + " = " + values[i];
                }
            }
        }
        if (isDebug()) {
            ERR << "set query: " << query << EOL;
        }
        Connection con = new Connection(db_path);
        con.exec(query);
        _id = con.getInsertId();
        con.close();
    }

    void add(Map record) {
        String query = "insert into " + name + "(";
        String[] values = [];
        String[] keys = record.keys();
        for (int i = 0; i < |keys|; i++) {
            String key = keys[i];
            values.add(escapeSqlValue(record[key]));
            if (i < |keys| - 1) {
                query += key.escapeSql() + ", ";
            }
            else {
                query += key.escapeSql() + ") values(";
            }
        }
        for (int i = 0; i < |values|; i++) {
            if (i < |values| - 1) {
                query += values[i] + ", ";
            }
            else {
                query += values[i] + ")";
            }
        }
        if (isDebug()) {
            ERR << "add query: " << query << EOL;
        }
        Connection con = new Connection(db_path);
        con.exec(query);
        _id = con.getInsertId();
        con.close();
    }

    void remove(Map record) {
        String query = "delete from " + name + " where ";
        String[] keys = record.keys();
        for (int i = 0; i < |keys|; i++) {
            String key = keys[i];
            if (i < |keys| - 1) {
                query += key.escapeSql() + " = " + escapeSqlValue(record[key]) + " and ";
            }
            else {
                query += key.escapeSql() + " = " + escapeSqlValue(record[key]);
            }
        }
        if (isDebug()) {
            ERR << "remove query: " << query << EOL;
        }
        Connection con = new Connection(db_path);
        con.exec(query);
        con.close();
    }

    void update(Map record, Map param) {
        String query = "update " + name + " set ";
        String[] keys = record.keys();
        int i;
        for (i = 0; i < |keys|; i++) {
            String key = keys[i];
            if (i < |keys| - 1) {
                query += key.escapeSql() + " = " + escapeSqlValue(record[key]) + ", ";
            }
            else {
                query += key.escapeSql() + " = " + escapeSqlValue(record[key]);
            }
        }
        if (param != null && |param| > 0) {
            query += " where ";
            keys = param.keys();
            for (i = 0; i < |keys|; i++) {
                String key = keys[i];
                if (i < |keys| - 1) {
                    query += key.escapeSql() + " = " + escapeSqlValue(param[key]) + " and ";
                }
                else {
                    query += key.escapeSql() + " = " + escapeSqlValue(param[key]);
                }
            }
        }
        if (isDebug()) {
            ERR << "update query: " << query << EOL;
        }
        Connection con = new Connection(db_path);
        con.exec(query);
        con.close();
    }
}

/* ------------------------------------------------------------------------ */
/* matsu */

@Singleton class FileStorage
{
    String getRoot() {
        return getMediaDir();
    }

    String checkName(String name) {
        if(name.indexOf("..") != -1) return null;
        Regex r = new Regex("^[\\w_\\.\\-/]+$");
        if(name.search(r) < 0) return null;
        return getMediaDir() + name;
    }

    InputStream open(String name, String mode) {
        name = checkName(name);
        if(name != null) {
            return new InputStream(name, mode);
        }
        return null;
    }

    OutputStream newFile(String name, String mode) {
        name = checkName(name);
        if (isDebug()) {
            ERR << "newFile: " << name << EOL;
        }
        if(name != null) {
            return new OutputStream(name, mode);
        }
        return null;
    }

    boolean mkdir(String name, int mode) {
        name = checkName(name);
        if (isDebug()) {
            ERR << "mkdir: " << name << EOL;
        }
        if (name.endsWith("/")) {
            name = name.substring(0, |name| - 1);
        }
        String[] dirnames = name.split("/");
        if (!chdir("/")) {
            return false;
        }
        for (int i = 0; i < |dirnames| - 1; i++) {
            if (dirnames[i] != "" && !chdir(dirnames[i])) {
                return false;
            }
        }
        return System.mkdir(name, mode);
    }
}

class Permission
{
    String name;
    Permission(String name) { _name = name; }
}

class Group
{
    String name;
    Model group;

    Group(String name) {
        _name = name;
        _group = new Model("group_perms", {
            "name": String,
            "permissions": String
        });
    }

    boolean hasPermission(Permission perm) {
        Map[] m = group.get("*", {"name": name});
        if (|m| == 1) {
            String perms = (m[0]["permissions"] == null) ? "" : m[0]["permissions"];
            foreach (String p in perms.split(",")) {
                if (p == perm.name) return true;
            }
        }
        return false;
    }
}

class User
{
    int id;
    String name;
    String[] perms;
    String[] groups;

    User(int id, String name, String[] perms, String[] groups) {
        _id = id;
        _name = name;
        _perms = perms;
        _groups = groups;
    }

    boolean hasPermission(Permission perm) {
        foreach(String p in perms) {
            if(p == perm.name) return true;
        }
        foreach(String g in groups) {
            if(new Group(g).hasPermission(perm)) return true;
        }
        return false;
    }

    @Static int getUserId(String name) {
        Model user = new Model("users", {
            "id": AutoIncrementInt,
            "name": String,
            "password": String,
            "permissions": String,
            "groups": String
        }, ["id"]);
        Map[] m = user.get("id", {
            "name": name
        });
        int id = -1;
        if (|m| == 1) {
            id = m[0]["id"];
        }
        return id;
    }

    @Static User authenticate(String name, String password) {
        Model user = new Model("users", {
            "id": AutoIncrementInt,
            "name": String,
            "password": String,
            "permissions": String,
            "groups": String
        }, ["id"]);
        Map[] m = user.get("id,permissions,groups", {
            "name": name,
            "password": password.convert(to:SHA256)
        });
        if (|m| == 1) {
            int id = m[0]["id"];
            String[] p;
            String[] g;
            try {
                String perms = m[0]["permissions"];
                p = perms.split(",");
            } catch (Exception!! e) {
                p = [];
            }
            try {
                String groups = m[0]["groups"];
                g = groups.split(",");
            } catch (Exception!! e) {
                g = [];
            }
            return new User(id, name, p, g);
        }
        if (isDebug()) {
            ERR << "authenticate result: " << m << EOL;
        }
        return null;
    }

    @Static boolean hasUser(String name) {
        Model user = new Model("users", {
            "id": AutoIncrementInt,
            "name": String,
            "password": String,
            "permissions": String,
            "groups": String
        }, ["id"]);
        Map[] m = user.get("id", {
            "name": name
        });
        if (|m| == 1) {
            if (isDebug()) {
                ERR << "user '" + name + "' exists" << EOL;
            }
            return true;
        }
        if (isDebug()) {
            ERR << "user '" + name + "' does not exist" << EOL;
        }
        return false;
    }

    @Static User addUser(String name, String password) {
        if (User.hasUser(name)) {
            return null;
        }
        Model user = new Model("users", {
            "id": AutoIncrementInt,
            "name": String,
            "password": String,
            "permissions": String,
            "groups": String
        }, ["id"]);
        user.add({
            "name": name,
            "password": password.convert(to:SHA256)
        });
        return new User(user.id, name, [], []);
    }

    @Static String[] getList() {
        Model user = new Model("users", {
            "id": AutoIncrementInt,
            "name": String,
            "password": String,
            "permissions": String,
            "groups": String
        }, ["id"]);
        Map[] maps = user.get("name");
        String[] list = [];
        foreach (Map m in maps) {
            list.add(m["name"]);
        }
        return list;
    }
}

/* ------------------------------------------------------------------------ */

class TemplateContext
{
    Cs cs;
    String str;
    Path file;

    TemplateContext(String context) {
        _str = context;
    }

    void parseFile(Path path) {
        if (!((to String)path).startsWith("/")) {
            path = getViewDir() + path;
        }
        _file = path;
    }

    void loadSettingValues(Hdf hdf) {
        hdf.setValue("STATIC_URL", getStaticUrl());
        hdf.setValue("BASE_URL", getBaseUrl());
        hdf.setValue("hdf.loadpaths.0", getViewDir());
        hdf.setValue("hdf.loadpaths.1", getModelDir());
    }

    void loadHdf(Hdf hdf) {
        loadSettingValues(hdf);
        if (isDebug()) {
            hdf.writeFile("/tmp/hdf");
        }
        _cs = new Cs(hdf);
        if (str != null) {
            cs.parseString(str);
        }
        if (file != null) {
            cs.parseFile(file);
        }
    }
}

class Template
{
    Hdf hdf;
    String buf;

    Template(String template) {
        _hdf = new Hdf();
        if (template != null) {
            hdf.readString(template);
        }
    }

    void set(String key, dynamic value) {
        if (value.class == int) {
            int ival = value;
            hdf.setIntValue(key, ival);
        }
        else if (value.class == String) {
            String sval = value;
            hdf.setValue(key, sval.escapeHtml());
        }
        else if (value.class == Array) {
            int i = 0;
            for (; i < |value|; i++) {
                this[key + "." + (to String)i] = value[i];
            }
        }
        else if (value.class == Map) {
            String[] mkeys = value.keys();
            for (int i = 0; i < |mkeys|; i++) {
                this[key + "." + mkeys[i]] = value[mkeys[i]];
            }
        }
        else if (value == null) {
            if (isDebug()) {
                ERR << "Template['" + key + "']: value is null. ignored." << EOL;
            }
        }
        else {
            throw new Script!!("Template['" + key + "']: Unsupported type is given.");
        }
    }

    int getInt(String key) {
        return hdf.getIntValue(key);
    }

    String get(String key) {
        return hdf.getValue(key);
    }

    void readFile(Path path) {
        if (!((to String)path).startsWith("/")) {
            path = getModelDir() + path;
        }
        hdf.readFile(path);
    }

    void readString(String s) {
        hdf.readString(s);
    }

    int render_cb(String s) {
        buf += s;
        return Cs.STATUS_OK;
    }

    String render(TemplateContext context) {
        _buf = "";
        context.loadHdf(hdf);
        context.cs.render(delegate(this, render_cb));
        return buf;
    }

    boolean save(String name) {
        String path = FileStorage.checkName(name);
        if (path == null) return false;
        hdf.writeFileAtomic(path);
        return true;
    }

    boolean load(String name) {
        String path = FileStorage.checkName(name);
        if (path == null) return false;
        if (System.stat(path) == null) {
            return false;
        }
        hdf.readFile(path);
        return true;
    }
}

@Expando class HttpRequest
{
    String path;
    String method;
    Map<String> params_get;
    Map<String> params_post;
    Map<String> cookies;

    HttpRequest(String path, String method, String query, String cookie) {
        _path = path;
        _method = method;
        Map<String> m = {};
        foreach (String param in query.split("&")) {
            String[] k_v = param.split("=");
            if (|k_v| == 2 && k_v[1] != null) {
                m[k_v[0]] = k_v[1].convert(to:durl);
            }
            else {
                m[k_v[0]] = "";
            }
        }
        if (method == "GET") {
            _params_get = m;
        }
        else if (method == "POST") {
            _params_post = m;
        }
        m = {};
        if (cookie != null) {
            foreach (String ck in cookie.replace($/ /, "").split(";")) {
                String[] k_v = ck.split("=");
                m[k_v[0]] = k_v[1];
            }
        }
        _cookies = m;
    }
}

class HttpResponse
{
    String content;
    int status;
    Tuple<String,String>[] h;

    HttpResponse(String content, Tuple<String,String>[] headers) {
        _content = content;
        _h = headers;
        if (h == null) {
            _h = [];
        }
    }

    void set(String header, String value) {
        h.add((header, value));
    }

    String[] get(String header) {
        String[] ret = [];
        foreach (Tuple<String,String> t in _h) {
            if (t[0] == header) {
                ret.add(t[1]);
            }
        }
        return ret;
    }

    String[] keys(void) {
        String[] keys = [];
        foreach (Tuple<String,String> t in _h) {
            if (not (t[0] in? keys)) {
                keys.add(t[0]);
            }
        }
        return keys;
    }

    void setCookie(String key, String value, String expires, String path) {
        path = (path == null) ? "/" : path;
        String cookie = key + "=" + value + "; ";
        if (expires != null && expires != "") {
            cookie += "expires=" + expires + "; ";
        }
        cookie += "path=" + path + ";";
        this["Set-Cookie"] = cookie;
        if (isDebug()) {
            ERR << "Set-Cookie: " << cookie << EOL;
        }
    }

    void deleteCookie(String key, String path) {
        path = (path == null) ? "/" : path;
        String cookie = key + "=dummy; ";
        Date past = new Date();
        past.year = 1970;
        cookie += "expires=" + past.toRFC1123();
        this["Set-Cookie"] = cookie;
        if (isDebug()) {
            ERR << "Delete-Cookie: " << cookie << EOL;
        }
    }
}

class HttpResponseRedirect extends HttpResponse
{
    HttpResponseRedirect(String location) {
        _h = [("Location", location)];
        _status = 302;
    }
}

@Singleton class Url
{
    Tuple<Regex,Func<HttpRequest,String[]=>HttpResponse>>[] getPatterns() {
        Tuple<Regex,Func<HttpRequest,String[]=>HttpResponse>>[] patterns = $veins.urlpatterns;
        if (patterns == null) {
            $veins.urlpatterns = new Tuple<Regex,Func<HttpRequest,String[]=>HttpResponse>>[0];
        }
        return $veins.urlpatterns;
    }

    void setPatterns(Tuple<Regex,Func<HttpRequest,String[]=>HttpResponse>>[] patterns) {
        $veins.urlpatterns = patterns;
    }
}

@Singleton class Middleware
{
    @Virtual HttpResponse hookRequest(HttpRequest req);
    @Virtual HttpResponse hookHandler(HttpRequest req,
            Func<HttpRequest,String[]=>HttpResponse> callback, String[] args);
    @Virtual HttpResponse hookResponse(HttpRequest req, HttpResponse res);
    @Virtual HttpResponse hookException(HttpRequest req, Exception e);
}

class Session
{
    Path path;
    String fname;
    String origname;
    Json j;

    Session(String name) {
        if (name != null && name != "") {
            _origname = name;
            _fname = name.convert(to:SHA256);
        }
        else {
            _origname = Uuid.getUuid4();
            _fname = origname.convert(to:SHA256);
        }
        _path = getTmpDir() + fname;
        if (load()) {
            if (isDebug()) {
                ERR << "load succeeded" << EOL;
            }
        }
        else {
            if (isDebug()) {
                ERR << "load failed" << EOL;
            }
        }
    }

    Session renew(String name) {
        if (System.unlink(path)) {
            if (isDebug()) {
                ERR << "unlink: " << path << EOL;
            }
        }
        else {
            if (isDebug()) {
                ERR << "unlink failed: " << path << EOL;
            }
        }
        return new Session(name);
    }

    boolean load() {
        if (System.stat(path)== null) {
            _j = new Json();
            return false;
        }
        else {
            InputStream ins = new InputStream(path);
            _j = Json.parse(ins.read().decode(to:xor));
            ins.close();
            return true;
        }
    }

    dynamic get(String key) {
        return j[key];
    }

    String[] keys() {
        return j.getKeys();
    }

    void remove(String key) {
        j.delete(key);
    }

    String toString() {
        return j.stringify();
    }

    void set(String key, dynamic val) {
        Class[] classes = [String, int, float];
        if (val.class in? classes) {
            j[key] = val;
        }
        else {
            throw new Script!!("Session['" + key + "']: Unsupported type is given.");
        }
    }

    void store() {
        OutputStream ous = new OutputStream(path);
        ous.write(j.stringify().encode(to:xor));
        ous.close();
    }
}


/* ======================================================================== */
/* Builtin middlwares. */

@Singleton class SessionMiddleware extends Middleware
{
    HttpResponse hookRequest(HttpRequest req) {
        if (isDebug()) {
            ERR << "hook request: " << req << EOL;
        }
        if (req.cookies["KSESSIONID"] != null) {
            if (isDebug()) {
                ERR << "KSESSIONID: " << req.cookies["KSESSIONID"] << EOL;
            }
            req.session = new Session(req.cookies["KSESSIONID"]);
        }
        else {
            req.session = new Session();
        }
        return null;
    }

    HttpResponse hookHandler(HttpRequest req,
            Func<HttpRequest,String[]=>HttpResponse> callback, String[] args) {
        if (isDebug()) {
            ERR << "hook handler: " << req << callback << args << EOL;
        }
        return null;
    }

    HttpResponse hookResponse(HttpRequest req, HttpResponse res) {
        if (isDebug()) {
            ERR << "hook response" << EOL;
        }
        if (req.cookies["KSESSIONID"] == null ||
                req.cookies["KSESSIONID"] != req.session.origname) {
            if (isDebug()) {
                ERR << "old session: " << req.cookies["KSESSIONID"] << EOL;
                ERR << "new session: " << req.session.fname.convert(to:SHA256) << EOL;
            }
            //Date now = new Date();
            //if (now.day < 15) {
            //    now.day += 14;
            //}
            //else if (now.month < 12) {
            //    now.day -= 14;
            //    now.month += 1;
            //}
            //else {
            //    now.year += 1;
            //    now.day -= 14;
            //    now.month -= 11;
            //}
            //res.setCookie("KSESSIONID", req.session.fname, now.toRFC1123());
            res.setCookie("KSESSIONID", req.session.origname);
        }
        req.session.store();
        req.session = null;
        return res;
    }

    HttpResponse hookException(HttpRequest req, Exception e) {
        if (isDebug()) {
            ERR << "hook exception: " << req << e << EOL;
        }
        return null;
    }
}

@Singleton class LoggingMiddleware extends Middleware
{
    HttpResponse hookRequest(HttpRequest req) {
        Map m = {};
        m["path"] = req.path;
        m["method"] = req.method;
        try {
            if (req.session != null) {
                m["session"] = req.session.toString();
            }
        } catch (Exception!! e) {
            m["session"] = "none";
        }
        System.ntraceNotice("Veins:Request", m);
        return null;
    }

    HttpResponse hookHandler(HttpRequest req,
            Func<HttpRequest,String[]=>HttpResponse> callback, String[] args) {
        Map m = {};
        m["handler"] = callback.name;
        String argstr = "[";
        foreach (String arg in args) {
            argstr += arg + ",";
        }
        argstr += "]";
        m["args"] = argstr;
        System.ntraceNotice("Veins:Handler", m);
        return null;
    }

    HttpResponse hookResponse(HttpRequest req, HttpResponse res) {
        Map m = {};
        m["status"] = (res.status == 0) ? 200 : res.status;
        foreach (String h in res.keys()) {
            for (int i = 0; i < |res[h]|; i++) {
                String key = "header:" + h + "+" + (to String)i;
                m[key] = res[h][i];
            }
        }
        System.ntraceNotice("Veins:Response", m);
        return res;
    }

    HttpResponse hookException(HttpRequest req, Exception e) {
        Map m = {};
        m["message"] = e.toString();
        System.ntraceFailed("Veins:Exception", m);
        return null;
    }
}

/* ======================================================================== */

HttpRequest g_req;
HttpResponse g_res;
Func<HttpRequest,String[]=>HttpResponse> g_handler;
String[] g_args;
Exception!! g_e;

@Public String Wsgi.application(Map<String> environ,
        Func<String,Tuple<String,String>[]> start_response)
{
    // initialize global variables
    g_req = null;
    g_res = null;
    g_handler = null;
    g_args = null;
    g_e = null;

    String[] middlewares = getMiddlewares();
    String path = environ["URI"];
    if (|path| >= 1 && path != "/") {
        path = path.substring(1);
    }
    if (isDebug()) {
        foreach (String e in environ.keys()) {
            ERR << "env[" + e + "]=" + environ[e] << EOL;
        }
        ERR << "path: " + path << EOL;
    }
    try {
        String method = environ["REQUEST_METHOD"];
        String query = environ["QUERY_STRING"];
        String cookie = environ["Cookie"];
        g_req = new HttpRequest(path, method, query, cookie);
        foreach (String middleware in middlewares) {
            if (isDebug()) {
                ERR << "call " << middleware + ".hookRequest()" << EOL;
            }
            eval("g_res = " + middleware + ".hookRequest(g_req);");
            if (g_res != null) {
                break;
            }
        }
        if (g_res == null) {
            foreach (Tuple<Regex,Func<HttpRequest,String[]=>HttpResponse>> t in Url.getPatterns()) {
                if (path.search(t[0]) >= 0) {
                    g_args = path.split("/");
                    if (|g_args| > 0) {
                        g_args.remove(0);
                    }
                    g_handler = t[1];
                    if (isDebug()) {
                        ERR << "handler: " << g_handler << EOL;
                        ERR << "args: [";
                        foreach (String g_arg in g_args) {
                            ERR << g_arg << ", ";
                        }
                        ERR << "]" << EOL;
                    }
                    foreach (String middleware in middlewares) {
                        if (isDebug()) {
                            ERR << "call " << middleware + ".hookHandler()" << EOL;
                        }
                        eval("g_res = " + middleware + ".hookHandler(g_req, g_handler, g_args);");
                    }
                    if (g_res != null) {
                        break;
                    }
                    g_res = g_handler(g_req, g_args);
                    break;
                }
            }
        }
        if (g_res != null) {
            foreach (String middleware in middlewares) {
                if (isDebug()) {
                    ERR << "call " << middleware + ".hookResponse()" << EOL;
                }
                eval("g_res = " + middleware + ".hookResponse(g_req, g_res);");
            }
        }
    } catch (Exception!! e) {
        g_e = e;
        foreach (String middleware in middlewares) {
            if (isDebug()) {
                ERR << "call " << middleware + ".hookException()" << EOL;
            }
            eval("g_res = " + middleware + ".hookException(g_req, g_e);");
            if (g_res != null) {
                break;
            }
        }
    }
    if (g_res != null) {
        Tuple<String,String>[] headers = g_res.h;
        if (not "Content-Type" in? g_res.keys()) {
            headers.add(("Content-Type", "text/html; charset=UTF-8"));
        }
        String status = "";
        switch (g_res.status) {
        case 301:
            status = "301 Moved Permanently";
            break;
        case 302:
            status = "302 Found";
            break;
        case 404:
            status = "404 Not Found";
            break;
        case 200:
        default:
            status = "200 OK";
            break;
        }
        start_response(status, headers);
        return g_res.content;
    }
    if (not path.endsWith("/")) {
        String redirect_url = environ["URI"] + "/";
        start_response("302 Found", [
            ("Content-Type", "text/html; charset=UTF-8"),
            ("Location", redirect_url)
        ]);
        return "";
    }
    start_response("404 Not Found", [("Content-Type", "text/html; charset=UTF-8")]);
    return "";
}
