function konoha() {
    this.OUT = "";
    this.ERR = "";
    this.THROWN = false;
    this.THROWNMSG = "";
    this.printOUT = function() {
        if (this.OUT == "") return;
        var code = document.createElement('pre');
        if (typeof code.textContent != "undefined") {
            code.textContent = this.OUT;
        } else {
            code.innerText = this.OUT;
        }
        var body = document.getElementsByTagName('body').item(0);
        body.appendChild(code);
        window.scrollTo(0, document.body.scrollHeight);
    }
    this.printERR = function() {
        if (this.ERR == "") return;
        var code = document.createElement('pre');
        if (typeof code.textContent != "undefined") {
            code.textContent = this.ERR;
        } else {
            code.innerText = this.ERR;
        }
        var body = document.getElementsByTagName('body').item(0);
        body.appendChild(code);
        window.scrollTo(0, document.body.scrollHeight);
    }
}

/* for web workers */
//function document() {
//    this._body = "<html><head></head><body></body></html>";
//    this.getElementsByTagName = function(tagname) {
//        return null;
//    };
//}

konoha = new konoha();
konoha.Object = function(rawptr) {
    this.rawptr = rawptr;
}
konoha.Object.prototype.konohaclass = "konoha.Object";
konoha.Object.prototype.getClass = function() {
    return new Class(this.konohaclass);
}
konoha.Object.prototype.toString = function() {
    if (typeof(this.rawptr) == "string") {
        return this.rawptr;
    } else {
        var res = "{";
        for (var i in this) {
            if (typeof(this[i]) != "function" && i != "rawptr" && i != "konohaclass") {
                console.log(i);
                console.log(typeof(this[i]));
                console.log(this[i]);
                res += this[i] + " ";
            }
        }
        res += "}";
        return res;
    }
}

konoha.Object.prototype.neq = function(obj) {
    return this.rawptr != obj.rawptr;
}

konoha.Object.prototype.eq = function(obj) {
    return this.rawptr == obj.rawptr;
}

/* Infinite Loop Detector */
konoha.loopcount = 0;

konoha.checkLoopCount = function(limit) {
    if(konoha.loopcount >= limit) {
        throw("Runtime!!: loop count exceeded " + limit + " times.\nYour script may have fallen into infinite loop.");
    }
}

/* Class */
konoha.Class = function(rawptr) {
    this.rawptr = rawptr;
}
konoha.Class.prototype = new konoha.Object();
konoha.Class.prototype.konohaclass = "konoha.Class";

/* Method */
konoha.Method = function(rawptr) {
    this.rawptr = rawptr;
}
konoha.Method.prototype = new konoha.Object();
konoha.Class.prototype.konohaclass = "konoha.Method";

/* OutputStream */
konoha.OutputStream = function(isCwb) {
    this.cwb = "";
    this.println = function() {
        konoha.OUT += (this.cwb);
        this.cwb = "";
        for (var i=0; i < arguments.length; i++) {
            if (arguments[i].rawptr) {
                konoha.OUT += arguments[i].toString();
            } else {
                konoha.OUT += arguments[i];
            }
        }
        konoha.OUT += '\n';
    }
    this.print = function() {
        konoha.OUT += (this.cwb);
        this.cwb = "";
        for (var i=0; i < arguments.length; i++) {
            if (arguments[i].rawptr) {
                konoha.OUT += (arguments[i].toString());
            } else {
                konoha.OUT += (arguments[i]);
            }

        }
    }
    this.flush = function() {
        konoha.printOUT();
        konoha.PROMPT = konoha.OUT.split("\n").pop();
        konoha.OUT = "";
    }

    if (!isCwb) {
        this.send = function() {
            konoha.OUT += (this.cwb);
            this.cwb = "";
            for (var i = 0; i < arguments.length; i++) {
                if (arguments[i].rawptr) {
                    konoha.OUT += (arguments[i].toString());
                } else {
                    konoha.OUT += (arguments[i]);
                }
            }
        }
    } else {
        this.send = function() {
            for (var i = 0; i < arguments.length; i++) {
                if (arguments[i].rawptr) {
                    this.cwb += arguments[i].toString();
                } else {
                    this.cwb += arguments[i];
                }
            }
        }
    }
    this.tostr = function() {
        var res = this.cwb;
        this.cwb = "";
        return new konoha.String(res);
    }
}
konoha.OutputStream.prototype = new konoha.Object();
konoha.OutputStream.prototype.konohaclass = "konoha.OutputStream";

/* System */
konoha.System = function() {
}
konoha.System.prototype = new konoha.Object();
konoha.System.prototype.konohaclass = "konoha.System";
konoha.System.getOut = function() {
    var os = new konoha.OutputStream(false);
    return os;
}
konoha.System.getErr = function() {
    var os = new konoha.OutputStream(false);
    return os;
}
konoha.System.currentTimeMillis = function() {
    return new Date().getTime();
}
konoha.System.exit = function(s) {
    throw("exited with status " + s);
}
konoha.System.getIn = function() {
    return new function() {
        this.readLine = function() {
            var ret;
            if (konoha.PROMPT != '') {
                ret = new konoha.Object(prompt(konoha.PROMPT, ''));
            }
            else {
                ret = new konoha.Object(prompt('Input text', ''));
            }
            return ret;
        }
    }
}

/* Map */
konoha.Map = function(rawptr) {
    this.rawptr = rawptr = {};
}

konoha.Map.prototype = new konoha.Object();
konoha.Map.prototype.konohaclass = "konoha.Map";

konoha.Map.prototype._new = function(init) {
    return this;
}
konoha.Map.prototype.set = function(key, value) {
    this.rawptr[key.rawptr] = value;
}
konoha.Map.prototype.get = function(key) {
    var obj = this.rawptr[key.rawptr];
    if (obj == null) {
        return 0;
    }
    return obj;
}
konoha.Map.prototype.remove = function(key) {
    delete this.rawptr[key.rawptr];
}
konoha.Map.prototype.keys = function() {
    var res = [];
    for(var elem in this.rawptr) {
        res.push(elem);
    }
    return res;
}
konoha.Map.prototype.getSize = function() {
    var res = 0;
    for(var elem in this.rawptr) {
        res ++;
    }
    return res;
}


/* Array */
konoha.Array = function(rawptr) {
    if (rawptr != null) {
        this.rawptr = rawptr;
        this.capacity = rawptr.length;
    }
}
konoha.Array.prototype = new konoha.Object();
konoha.Array.prototype.konohaclass = "konoha.Array";
konoha.Array.prototype.new_ARRAY = function() {
    var args = Array.prototype.slice.call(arguments);
    var initCapacity = args[0];
    args = args.slice(1);
    if (args.length == 0) {
        this.rawptr = new Array(initCapacity);
        for(var i = 0; i < initCapacity; i++) {
            this.rawptr[i] = 0;
        }
        this.capacity = initCapacity;
    }
    else {
        this.rawptr = new Array(initCapacity);
        for (var i = 0; i < initCapacity; i++) {
            this.rawptr[i] = new konoha.Array();
            this.rawptr[i].new_ARRAY.apply(this.rawptr[i], args);
        }
        this.capacity = initCapacity;
    }
    if (konoha.memview != null) {
        konoha.memview.new(this);
    }
    return this;
}
konoha.Array.prototype.new_ARRAY2 = konoha.Array.prototype.new_ARRAY;
konoha.Array.prototype.new_LIST = function() {
    this.capacity = arguments.length;
    this.rawptr = new Array(this.capacity);
    for (var i = 0; i < arguments.length; i++) {
        this.rawptr[i] = arguments[i];
    }
    if (konoha.memview != null) {
        konoha.memview.new(this);
    }
    return this;
}
konoha.Array.prototype.get = function(n) {
    if (n < this.capacity) {
        return this.rawptr[n];
    } else {
        throw('ArrayIndexOutOfBoundsException!!\nArraySize=' + this.capacity + ', index=' + n);
    }
}
konoha.Array.prototype.get2 = function(x, y) {
    if (x < this.capacity) {
        return this.rawptr[x].get(y);
    } else {
        throw('ArrayIndexOutOfBoundsException!!\nArraySize=' + this.capacity + ', index=' + x);
    }
}
konoha.Array.prototype.get3 = function(x, y, z) {
    if (x < this.capacity) {
        return this.rawptr[x].get2(y, z);
    } else {
        throw('ArrayIndexOutOfBoundsException!!\nArraySize=' + this.capacity + ', index=' + x);
    }
}
konoha.Array.prototype.get4 = function(x, y, z, w) {
    if (x < this.capacity) {
        return this.rawptr[x].get3(y, z, w);
    } else {
        throw('ArrayIndexOutOfBoundsException!!\nArraySize=' + this.capacity + ', index=' + x);
    }
}
konoha.Array.prototype.set = function(n, v) {
    if (n < this.capacity) {
        this.rawptr[n] = v;
    } else {
        throw('ArrayIndexOutOfBoundsException!!\nArraySize=' + this.capacity + ', index=' + n);
    }
    if (konoha.memview != null) {
        konoha.memview.set(this, n, v);
    }
}
konoha.Array.prototype.set2 = function(x, y, v) {
    if (x < this.capacity) {
        this.rawptr[x].set(y, v);
    } else {
        throw('ArrayIndexOutOfBoundsException!!\nArraySize=' + this.capacity + ', index=' + x);
    }
    if (konoha.memview != null) {
        konoha.memview.set(this, x, y, v);
    }
}
konoha.Array.prototype.set3 = function(x, y, z, v) {
    if (x < this.capacity) {
        this.rawptr[x].set2(y, z, v);
    } else {
        throw('ArrayIndexOutOfBoundsException!!\nArraySize=' + this.capacity + ', index=' + x);
    }
    if (konoha.memview != null) {
        konoha.memview.set2(this, x, y, z, v);
    }
}
konoha.Array.prototype.set4 = function(x, y, z, w, v) {
    if (x < this.capacity) {
        this.rawptr[x].set3(y, z, w, v);
    } else {
        throw('ArrayIndexOutOfBoundsException!!\nArraySize=' + this.capacity + ', index=' + x);
    }
    if (konoha.memview != null) {
        konoha.memview.set3(this, x, y, z, w, v);
    }
}
konoha.Array.prototype.getSize = function() {
    return this.capacity;
}
konoha.Array.prototype.getLength = konoha.Array.prototype.getSize;
konoha.Array.prototype.add = function(v) {
    this.capacity++;
    this.rawptr.push(v);
    if (konoha.memview != null) {
        konoha.memview.add(this, v);
    }
}
konoha.Array.prototype.clear = function() {
    this.capacity = 0;
    this.rawptr = [];
    if (konoha.memview != null) {
        konoha.memview.clear(this);
    }
}
konoha.Array.prototype.remove = function(n) {
    if (n >= 0 && n < this.capacity) {
        this.rawptr.splice(n, 1);
        this.capacity--;
    } else {
        throw('ArrayIndexOutOfBoundsException!!\nArraySize=' + this.capacity + ', index=' + n);
    }
    if (konoha.memview != null) {
        konoha.memview.remove(this, n);
    }
}
konoha.Array.prototype.toString = function() {
    var res = '[';
    for(var i = 0; i < this.rawptr.length; i++) {
        res += this.rawptr[i].toString();
        if (i != this.rawptr.length-1) {
            res += ', ';
        }
    }
    res += ']';
    return res;
}
konoha.Array.prototype.swap = function(m, n) {
    var b = this.rawptr[m];
    this.rawptr[m] = this.rawptr[n];
    this.rawptr[n] = b;
    if (konoha.memview != null) {
        konoha.memview.swap(this, m, n);
    }
}

/* Iterator */
konoha.Iterator = function(rawptr) {
    this.rawptr = rawptr;
    this.cur = 0;
    this.capacity = rawptr.getSize();
}
konoha.Iterator.prototype = new konoha.Object();
konoha.Iterator.prototype.konohaclass = "konoha.Iterator";
konoha.Iterator.prototype.next = function() {
    if (this.cur == this.capacity) {
        return null;
    } else {
        var res = this.rawptr.get(this.cur);
        this.cur++;
        return res;
    }
}

/* String */
konoha.String = function(rawptr) {
    this.rawptr = rawptr;
}
konoha.String.prototype = new konoha.Object();
konoha.String.prototype.get = function(num) {
    return new konoha.String(this.rawptr[num]);
}
konoha.String.prototype.charAt = konoha.String.prototype.get;
konoha.String.prototype.equals = function(str) {
    return this.rawptr == str.rawptr;
}
konoha.String.prototype.startsWith = function(str) {
    return this.rawptr.indexOf(str.rawptr) == 0;
}
konoha.String.prototype.endsWith = function(str) {
    var correctIndex = this.rawptr.length - str.rawptr.length;
    return this.rawptr.lastIndexOf(str.rawptr) == correctIndex;
}
konoha.String.prototype.concat = function() {
    var res = this.rawptr;
    for (var i = 0; i < arguments.length; i++) {
        if (arguments[i].rawptr) {
            res += arguments[i].rawptr;
        } else {
            res += arguments[i];
        }
    }
    return new konoha.String(res);
}
konoha.String.prototype.indexOf = function(str) {
    return this.rawptr.indexOf(str.rawptr);
}
konoha.String.prototype.lastIndexOf = function(str) {
    return this.rawptr.lastIndexOf(str.rawptr);
}
konoha.String.prototype.match = function (re) {
    var list = this.rawptr.match(re.rawptr);
    var res = [];
    for (element in list) {
        res.push(new konoha.String(list[element]));
    }
    return new konoha.Array(res);
}
konoha.String.prototype.split = function(re) {
    var list = this.rawptr.split(re.rawptr);
    var res = [];
    for (element in list) {
        res.push(new konoha.String(list[element]));
    }
    return new konoha.Array(res);
}
konoha.String.prototype.search = function(re) {
    return this.rawptr.search(re.rawptr);
}
konoha.String.prototype.replace = function(source, target) {
    return new konoha.String(this.rawptr.replace(source.rawptr, target.rawptr));
}
konoha.String.prototype.getSize = function() {
    return this.rawptr.length;
}
konoha.String.prototype.getLength = konoha.String.prototype.getSize;
konoha.String.prototype.length = konoha.String.prototype.getSize;

konoha.String.prototype.toLowerCase = function() {
	return new konoha.String(this.rawptr.toLowerCase());
}

konoha.String.prototype.toUpperCase = function() {
	return new konoha.String(this.rawptr.toUpperCase());
}

konoha.String.prototype.substring = function(from, to) {
	return new konoha.String(this.rawptr.substring(from, to));
}

konoha.String.prototype.toCharArray = function() {
	return new konoha.Array(this.rawptr.split(''));
}

konoha.String.prototype.konohaclass = "konoha.String";

/* Regex */
konoha.Regex = function(rawptr) {
    this.rawptr = rawptr;
}
konoha.Regex.prototype._new = function(pattern, option) {
    this.rawptr = new RegExp(pattern.rawptr, option.rawptr);
    return this;
}

konoha.Regex.prototype = new konoha.Object();
konoha.Regex.prototype.konohaclass = "konoha.Regex";
/* Number */
konoha.Number = function(rawptr) {
    this.rawptr = rawptr;
}
konoha.Number.prototype = new konoha.Object();
konoha.Number.prototype.konohaclass = "konoha.Number";

/* Int */
konoha.Int = function(rawptr) {
    this.rawptr = rawptr;
}
konoha.Int.prototype = new konoha.Number();
konoha.Int.prototype.konohaclass = "konoha.Int";

konoha.Int.random = function(arg) {
    if (arg != null) {
        return Math.floor(Math.random() * arg);
    }
    return Math.floor(Math.random());
}
konoha.Int.format = function(i, format) {
    switch (format.rawptr) {
        case "%x":
            return new konoha.String(i.toString(16));
        case "%02x":
            var res = '00' + i.toString(16);
        return new konoha.String(res.substring(res.length-2, res.length));
    }
}

/* Float */
konoha.Float = function(rawptr) {
    this.rawptr = rawptr;
}
konoha.Float.prototype = new konoha.Number();
konoha.Float.prototype.konohaclass = "konoha.Float";

konoha.Float.random = function() {
    return Math.random();
}
