/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with K_UNDER_GPL)
 * (2) Konoha Non-Disclosure License 1.0
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

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef K_INCLUDE_BUILTINAPI

/* ------------------------------------------------------------------------ */

static knh_bool_t bytes_startsWithLink(knh_bytes_t t, knh_bytes_t scheme)
{
	if(knh_bytes_startsWith(t, scheme)) {
		if(t.text[scheme.len] == ':') return 1;
	}
	return 0;
}

static knh_bytes_t bytes_trim(knh_bytes_t t)
{
	while(isspace(t.utext[0])) {
		t.utext++;
		t.len--;
	}
	if(t.len == 0) return t;
	while(isspace(t.utext[t.len-1])) {
		t.len--;
		if(t.len == 0) return t;
	}
	return t;
}

/* ------------------------------------------------------------------------ */
/* [new] */

//## @Hidden method This Object.new();

static KMETHOD Object_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(sfp[0].o);
}

/* ------------------------------------------------------------------------ */

//static void ObjectField_setValue(CTX ctx, knh_ObjectField_t *of, knh_index_t idx, knh_type_t type, Object *value)
//{
//	knh_class_t tcid = CLASS_t(type);
//	knh_class_t scid = O_cid(value);
//	DBG_ASSERT_cid(tcid);
//	DBG_ASSERT_cid(scid);
//	if(scid == tcid || knh_class_instanceof(ctx, scid, tcid)) {
//		goto L_SETVAL;
//	}
//	DBG_P("COERCION %s -> %s", CLASS__(scid), CLASS__(tcid));
//	TODO();
////		BEGIN_LOCAL(ctx, lsfp);
////		KNH_LPUSH(ctx, o);
////		VM_MAP(ctx, tcid);
////		o = ctx->esp[0].o;
////		END_LOCAL(ctx, lsfp);
//	return ;
//
//	L_SETVAL:;
//	if(IS_Tint(type)) {
//		knh_int_t *data = (knh_int_t*)(of->fields + idx);
//		data[0] = N_toint(value);
//	}
//	else if(IS_Tfloat(type)) {
//		knh_float_t *data = (knh_float_t*)(of->fields + idx);
//		data[0] = N_tofloat(value);
//	}
//	else if(IS_Tbool(type)) {
//		knh_boolean_t *data = (knh_boolean_t*)(of->fields +idx);
//		data[0] = N_tobool(value);
//	}
//	else {
//		DBG_ASSERT(of->fields[idx] != NULL);
//		KNH_SETv(ctx, of->fields[idx], value);
//	}
//}

/* ------------------------------------------------------------------------ */
//## @Hidden method This Object.new:MAP(dynamic value, ...);

static KMETHOD Object_newMAP(CTX ctx, knh_sfp_t *sfp _RIX)
{
//	knh_ObjectField_t *of = (knh_ObjectField_t*)sfp[0].o;
//	knh_class_t cid = O_cid(of);
//	knh_sfp_t *v = sfp + 1;
//	size_t i, ac = knh_stack_argc(ctx, v);
//	for(i = 0; i < ac; i+= 2) {
//		if(IS_bString(v[i].s)) {
//			knh_fieldn_t fn = knh_getfnq(ctx, S_tobytes(v[i].s), FN_NONAME);
//			if(fn == FN_NONAME) continue;
//			knh_index_t idx = knh_Class_queryField(ctx, cid, fn);
//			if(idx == -1) continue;
//			knh_fields_t *cf = knh_Class_fieldAt(ctx, cid, idx);
//			knh_type_t type = knh_type_tocid(ctx, cf->type, cid);
//			if(type == TYPE_void) continue;
//			DBG_P("[%d] %s %s", (int)(idx), TYPE__(type), S_totext(v[i].s));
//			ObjectField_setValue(ctx, of, idx, type, v[i+1].o);
//		}
//	}
//	RETURN_(of);
}

/* ------------------------------------------------------------------------ */
//## @Const @FastCall method Class! Object.getClass();

static KMETHOD Object_getClass(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(new_Type(ctx, O_cid(sfp[0].o)));
}

/* ------------------------------------------------------------------------ */
//## @FastCall @Const method Int Object.hashCode();

static KMETHOD Object_hashCode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_hashcode_t h = ClassTBL(O_bcid(sfp[0].o))->cdef->hashCode(ctx, sfp[0].p);
	RETURNi_(h);
}

/* ------------------------------------------------------------------------ */
//## @Const @Hidden @FastCall method Boolean Object.isNull();

static KMETHOD Object_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(IS_NULL(sfp[0].o));
}

/* ------------------------------------------------------------------------ */
//## @Const @Hidden @FastCall method Boolean Object.isNotNull();

static KMETHOD Object_isNotNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(IS_NOTNULL(sfp[0].o));
}

///* ------------------------------------------------------------------------ */
////## @Const @Hidden @FastCall method String Object.getKey();
//
//static KMETHOD Object_getKey(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	knh_String_t *s = ClassTBL(O_bcid(sfp[0].o))->cdef->getkey(ctx, sfp);
//	KNH_ASSERT(IS_String(s));
//	RETURN_(s);
//}
//
///* ------------------------------------------------------------------------ */
////## @Const @Hidden method This Object.copy();
//
//static KMETHOD Object_copy(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	knh_Object_t *src = sfp[0].o;
//	knh_class_t cid = O_cid(src);
//	if(knh_class_canObjectCopy(ctx, cid) && IS_NOTNULL(src)) {
//		const knh_ClassTBL_t *ct = O_cTBL(src);
//		knh_Object_t *o = new_hObject_(ctx, ct);
//		o->h.magicflag = src->h.magicflag;
//		ct->cdef->initcopy(ctx, RAWPTR(o), RAWPTR(src));
//		src = o;
//	}
//	sfp[K_RIX].ndata = sfp[0].ndata;
//	RETURN_(src);
//}

/* ------------------------------------------------------------------------ */
//## @Const @Hidden @Private method dyn Object.cast(TypeMap tmr);

static KMETHOD Object_cast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	sfp[0].ndata = O_ndata(sfp[0].o); // UNBOX
	knh_TypeMap_exec(ctx, sfp[1].tmr, sfp, K_RIX);
}

/* ------------------------------------------------------------------------ */
//## @Const @Hidden @Private method dynamic Object.to(Class auto);

static KMETHOD Object_to(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_class_t scid = O_cid(sfp[0].o), tcid = (sfp[1].c)->cid;
	if(scid != tcid) {
		knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, scid, tcid);
		if(tmr != NULL) {
			sfp[0].ndata = O_ndata(sfp[0].i); // UNBOX
			knh_TypeMap_exec(ctx, tmr, sfp, K_RIX);
		}
		else {
			sfp[K_RIX].ivalue = 0;
			RETURN_(KNH_NULVAL(tcid));
		}
	}
	else {
		RETURN_(sfp[0].o);
	}
}

/* ------------------------------------------------------------------------ */
//## @Const @Hidden @Private method dynamic Object.typeCheck(Class auto);

static KMETHOD Object_typeCheck(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_class_t scid = O_cid(sfp[0].o), tcid = (sfp[1].c)->cid;
	if(scid != tcid && !class_isa(scid, tcid)) {
		knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, scid, tcid);
		if(tmr != NULL && TypeMap_isSemantic(tmr)) {
			sfp[0].ndata = O_ndata(sfp[0].i); // UNBOX
			knh_TypeMap_exec(ctx, tmr, sfp, K_RIX);
		}
		else {
			DBG_P("reqt=%s", TYPE__(tcid));
			THROW_TypeError(ctx, sfp, tcid, scid);
		}
	}
	else {
		sfp[K_RIX].ndata = O_ndata(sfp[0].o);
		RETURN_(sfp[0].o);
	}
}

/* ------------------------------------------------------------------------ */
//## @Hidden method dynamic Object.opWITH(Map data, NameSpace _, Boolean _);

static KMETHOD Object_opWITH(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_setData(ctx, sfp[0].o, sfp[1].m, sfp[2].ns, sfp[3].bvalue);
	RETURN_(sfp[0].o);
}

/* ------------------------------------------------------------------------ */
/* %empty */

//## method void Object.%empty();
static KMETHOD Object__empty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	if(CTX_isDebug(ctx)) {
		KNH_LOG("%%empty(%s)", O__(sfp[1].o));
	}
}

/* ------------------------------------------------------------------------ */
/* %s */

//## method void Object.%s();
static KMETHOD Object__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_Object(ctx, sfp[0].w, sfp[1].o, FMT_s);
}

/* ------------------------------------------------------------------------ */
/* %s */

//## method void Object.%k();
static KMETHOD Object__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_Object(ctx, sfp[0].w, sfp[1].o, FMT_line);
}

/* ------------------------------------------------------------------------ */
/* %s */

//## method void Object.%data();
static KMETHOD Object__data(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_Object(ctx, sfp[0].w, sfp[1].o, FMT_data);
}

/* ------------------------------------------------------------------------ */
/* %s */

//## method void Object.%dump();
static KMETHOD Object__dump(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_Object(ctx, sfp[0].w, sfp[1].o, FMT_dump);
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Static @Const method Tdynamic Tdynamic.opLINK(String path, NameSpace _);

static KMETHOD Tdynamic_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t t = knh_bytes_next(S_tobytes(sfp[1].s), ':');
	const knh_ClassTBL_t *ct = knh_NameSpace_getLinkClassTBLNULL(ctx, sfp[2].ns, t, CLASS_Tdynamic);
	if(ct != NULL) {
		RETURN_(new_Type(ctx, ct->cid));
	}
	RETURN_(KNH_NULL);
}

/* ------------------------------------------------------------------------ */
//## method void Boolean.%s();
//## method void Boolean.%k();
//## method void Boolean.%data();
//## method void Boolean.%dump();

static KMETHOD Boolean__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_bool(ctx, sfp[0].w, sfp[1].bvalue);
}

/* ------------------------------------------------------------------------ */
//## method void Int.%s();
//## method void Int.%d();

static KMETHOD Int__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_ifmt(ctx, sfp[0].w, K_INT_FMT, sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## method void Float.%s();
//## method void Float.%f();

static KMETHOD Float__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_ffmt(ctx, sfp[0].w, K_FLOAT_FMT, sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */
//## method void Int.%k();
//## method void Int.%data();
//## method void Int.%dump();

static KMETHOD Int__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
#if defined(K_USING_SEMANTICS)
	knh_Semantics_t *u = knh_getSemantics(ctx, O_cid(sfp[1].o));
	knh_write_intx(ctx, sfp[0].w, u, sfp[1].ivalue);
#else
	knh_write_ifmt(ctx, sfp[0].w, K_INT_FMT, sfp[1].ivalue);
#endif
}

/* ------------------------------------------------------------------------ */
//## method void Float.%k();
//## method void Float.%data();
//## method void Float.%dump();

static KMETHOD Float__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
#if defined(K_USING_SEMANTICS)
	knh_Semantics_t *u = knh_getSemantics(ctx, O_cid(sfp[1].o));
	knh_write_floatx(ctx, sfp[0].w, u, sfp[1].fvalue);
#else
	knh_write_ffmt(ctx, sfp[0].w, K_FLOAT_FMT, sfp[1].fvalue);
#endif
}

/* ------------------------------------------------------------------------ */
//## @Static @FastCall method void System.setRandomSeed(Int seed);

static KMETHOD System_setRandomSeed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_uint_t seed = Int_to(knh_uint_t, sfp[1]);
	knh_srand(seed);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## @Static @FastCall method Int Int.random(Int n);

static KMETHOD Int_random(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_uint_t n = knh_rand();
	knh_uint_t max = Int_to(knh_uint_t, sfp[1]);
	if(max > 0) {
		n = n % max;
	}
	RETURNi_(n);
}

/* ------------------------------------------------------------------------ */
//## @Static @FastCall method Float! Float.random();

static KMETHOD Float_random(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(knh_float_rand());
}

/* ------------------------------------------------------------------------ */
//## method void Int.%c();

static KMETHOD Int__c(CTX ctx, knh_sfp_t *sfp _RIX)
{
	char buf[16];
	knh_uint_t c = (knh_uint_t) sfp[1].ivalue;
	knh_format_utf8(buf, sizeof(buf), c);
	knh_write(ctx, sfp[0].w, B(buf));
}

/* ------------------------------------------------------------------------ */
//## method void Int.%u();

static KMETHOD Int__u(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_ifmt(ctx, sfp[0].w, K_UINT_FMT, sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## method void Int.%f();

static KMETHOD Int__f(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_ffmt(ctx, sfp[0].w, K_FLOAT_FMT, (knh_float_t)sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## method void Int.%x();

static KMETHOD Int__x(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_ifmt(ctx, sfp[0].w, K_INT_XFMT, sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */

static void knh_write_bits(CTX ctx, knh_OutputStream_t *w, knh_uint64_t n, size_t bits)
{
	size_t i;
	knh_uint64_t flag = 1ULL << (bits - 1);
	for(i = 0; i < bits; i++) {
		if(i > 0 && i % 8 == 0) {
			knh_putc(ctx, w, ' ');
		}
		if((flag & n) == flag) {
			knh_putc(ctx, w, '1');
		}else{
			knh_putc(ctx, w, '0');
		}
		flag = flag >> 1;
	}
}

/* ------------------------------------------------------------------------ */
//## method void Int.%bits();

static KMETHOD Int__bits(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_bits(ctx, sfp[0].w, sfp[1].ivalue, sizeof(knh_int_t) * 8);
}

/* ------------------------------------------------------------------------ */
//## method void Float.%d();

static KMETHOD Float__d(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_ifmt(ctx, sfp[0].w, K_INT_FMT, (knh_int_t)sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */
//## method void Float.%bits();

static KMETHOD Float__bits(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_bits(ctx, sfp[0].w, sfp[1].ndata, sizeof(knh_float_t) * 8);
}

/* ------------------------------------------------------------------------ */
//## @Const mapper Boolean String;

static TYPEMAP Boolean_String(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s = (Boolean_to(int, (sfp[0]))) ? new_T("true") : new_T("false");
	RETURN_(s);
}

/* ------------------------------------------------------------------------ */
//## @Const mapper Int String;

static TYPEMAP Int_String(CTX ctx, knh_sfp_t *sfp _RIX)
{
	char buf[80];
	knh_snprintf(buf, sizeof(buf), K_INT_FMT, sfp[0].ivalue);
	RETURN_(new_String2(ctx, CLASS_String, buf, knh_strlen(buf), K_SPOLICY_ASCII|K_SPOLICY_POOLALWAYS));
}

/* ------------------------------------------------------------------------ */
//## @Const  mapper Float String;

static TYPEMAP Float_String(CTX ctx, knh_sfp_t *sfp _RIX)
{
	char buf[256];
	knh_snprintf(buf, sizeof(buf), K_FLOAT_FMT, sfp[0].fvalue);
	RETURN_(new_String2(ctx, CLASS_String, buf, knh_strlen(buf), K_SPOLICY_ASCII|K_SPOLICY_POOLALWAYS));
}

/* ------------------------------------------------------------------------ */
//## @Const @Semantic mapper Float Int;

static TYPEMAP Float_Int(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_int_t v = (knh_int_t)sfp[0].fvalue;
	RETURNi_(v);
}

/* ------------------------------------------------------------------------ */
//## @Const @Semantic mapper Int Float;

static TYPEMAP Int_Float(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_float_t v = (knh_float_t)sfp[0].ivalue;
	RETURNf_(v);
}

/* ------------------------------------------------------------------------ */

static void Date_reset(knh_date_t *dt)
{
	dt->year  = (knh_short_t)0;
	dt->month = (knh_short_t)0;
	dt->day   = (knh_short_t)0;
	dt->hour  = (knh_short_t)0;
	dt->min   = (knh_short_t)0;
	dt->sec   = (knh_short_t)0;
}

static void Date_setsfp(knh_date_t *dt, knh_sfp_t *sfp)
{
	dt->year  = (knh_short_t)sfp[1].ivalue;
	dt->month = (knh_short_t)sfp[2].ivalue;
	dt->day   = (knh_short_t)sfp[3].ivalue;
	dt->hour  = (knh_short_t)(sfp[4].ivalue % 60);
	dt->min   = (knh_short_t)(sfp[5].ivalue % 60);
	dt->sec   = (knh_short_t)(sfp[6].ivalue % 60);
}

static knh_bool_t bytes_parsedt(knh_bytes_t *t, knh_short_t *value, int delim, knh_short_t def)
{
	if(t->len == 0) {
		value[0] = def;
		return 1;
	}
	int p = 0, ch = t->text[0], num = 0;
	while(p < t->len) {
		if(!isdigit(ch)) return 0;
		num += (ch - '0'); p++; ch = t->text[p];
		if(ch == delim) {
			p++;
			t->text += (p);
			t->len  -= (p);
			value[0] = (knh_short_t)num;
			return 1;
		}
		if(ch == 0) {
			t->text = "";
			t->len  = 0;
			value[0] = (knh_short_t)num;
			return 1;
		}
		num *= 10;
	}
	return 0;
}

/* ------------------------------------------------------------------------ */
//## method Date Date.new(Int year, Int month, Int day, Int hour, Int min, Int sec);

static KMETHOD Date_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Date_t *dt = sfp[0].dt;
	if(sfp[2].ivalue > 0) {
		Date_setsfp(&dt->dt, sfp);
		if(sfp[1].ivalue != 0) {
			Date_reset(&dt->dt);
			dt->dt.year = (knh_short_t)sfp[1].ivalue;
		}
	}
	RETURN_(dt);
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Static @Const method Date Date.opLINK(String path, NameSpace _);

static KMETHOD Date_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t t = knh_bytes_next(S_tobytes(sfp[1].s), ':');
	knh_Date_t *dt = (knh_Date_t*)new_Object_init2(ctx, ClassTBL(CLASS_Date));
	KNH_SETv(ctx, sfp[2].o, dt); // TO AVOIDGC
	if(bytes_parsedt(&t, &dt->dt.year, '-', 0)   &&
		bytes_parsedt(&t, &dt->dt.month, '-', 1) &&
		bytes_parsedt(&t, &dt->dt.day, 'T', 1) &&
		bytes_parsedt(&t, &dt->dt.hour, ':', 0) &&
		bytes_parsedt(&t, &dt->dt.min, ':', 0) &&
		bytes_parsedt(&t, &dt->dt.sec, '+', 0)) {
		RETURN_(dt);
	}
	else {
		RETURN_(KNH_TNULL(Date));
	}
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Static @Const method Path Path.opLINK(String path, NameSpace _);

static KMETHOD Path_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const knh_StreamDPI_t *dpi = knh_NameSpace_getStreamDPINULL(ctx, sfp[2].ns, S_tobytes(sfp[1].s));
	knh_Path_t *pth = new_(Path);
	KNH_SETv(ctx, pth->urn, sfp[1].s);
	pth->dpi = dpi;
	dpi->ospath(ctx, pth, sfp[2].ns);
	RETURN_(pth);
}

/* ------------------------------------------------------------------------ */
//## @Const @Semantic mapper String Path;

static TYPEMAP String_Path(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(new_Path(ctx, sfp[K_TMRIDX].s));
}

/* ------------------------------------------------------------------------ */
//## @Const @Semantic mapper Path String;

static TYPEMAP Path_String(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *pth = (knh_Path_t*)sfp[K_TMRIDX].o;
	RETURN_(pth->urn);
}

/* ------------------------------------------------------------------------ */
//## mapper Path Boolean;

static TYPEMAP Path_Boolean(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *pth = (knh_Path_t*)sfp[K_TMRIDX].o;
	RETURNb_(pth->dpi->existsSPI(ctx, pth));
}

/* ------------------------------------------------------------------------ */
//## mapper Path InputStream;

static TYPEMAP Path_InputStream(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *path = (knh_Path_t*)sfp[K_TMRIDX].o;
	knh_InputStream_t *in = new_InputStreamNULL(ctx, path, "r");
	if(in == NULL) in = KNH_TNULL(InputStream);
	RETURN_(in);
}

/* ------------------------------------------------------------------------ */
//## method Bytes Bytes.new(Int init);

static KMETHOD Bytes_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *ba = sfp[0].ba;
	size_t init = sfp[1].ivalue <= K_FASTMALLOC_SIZE ? K_FASTMALLOC_SIZE : k_goodsize(Int_to(size_t, sfp[1]));
	DBG_ASSERT(ba->dim->capacity == 0);
	ba->bu.ubuf = (knh_uchar_t*)KNH_MALLOC(ctx, init);
	knh_bzero(ba->bu.ubuf, init);
	ba->dim = new_dim(ctx, init, 1);
	ba->bu.len = 0;
	RETURN_(ba);
}

/* ------------------------------------------------------------------------ */
//## method Bytes Bytes.new:ARRAY(Int init);

static KMETHOD Bytes_newARRAY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t size = sfp[1].ivalue <=0 ? 0 : Int_to(size_t, sfp[1]);
	Bytes_new(ctx, sfp, K_RIX);
	sfp[K_RIX].ba->bu.len = size;
}

/* ------------------------------------------------------------------------ */
//## method void Bytes.putc(Int char);

static KMETHOD Bytes_putc(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *o = (knh_Bytes_t*)sfp[0].o;
	knh_Bytes_putc(ctx, o, Int_to(size_t, sfp[1]));
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void Bytes.write(BytesIm buf, Int offset, Int length);
//## method void Bytes.add(BytesIm buf, Int offset, Int length);

static KMETHOD Bytes_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *ba = sfp[0].ba;
	knh_bytes_t t = BA_tobytes(sfp[1].ba);
	if(sfp[2].ivalue != 0) {
		size_t n = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[2]), t.len);
		t = knh_bytes_last(t, n);
	}
	if(sfp[3].ivalue != 0) {
		size_t l = Int_to(size_t, sfp[3]);
		if(l < t.len) t.len = l;
	}
	knh_Bytes_write(ctx, ba, t);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method String String.new(Bytes buf, StringDecoder c);

static KMETHOD String_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s;
	if(IS_NULL(sfp[2].o)) {
		s = new_String2(ctx, CLASS_String, BA_totext(sfp[1].ba), BA_size(sfp[1].ba), 0);
	}
	else {
		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
		knh_StringDecoder_t *c = (knh_StringDecoder_t*)sfp[2].o;
		c->dpi->dec(ctx, c->conv, BA_totext(sfp[1].ba), BA_size(sfp[1].ba), cwb->ba);
		s = CWB_newString(ctx, cwb, 0);
	}
	RETURN_(s);
}

/* ------------------------------------------------------------------------ */
//## @Const method Regex Regex.new(String pattern, String option);

static KMETHOD Regex_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Regex_t *re = (knh_Regex_t*)sfp[0].o;
	const char *ptn = S_totext(sfp[1].s);
	const char *opt = IS_NULL(sfp[2].o) ? "" : S_totext(sfp[2].s);
	knh_Regex_setGlobalOption(ctx, re, opt);
	KNH_SETv(ctx, re->pattern, sfp[1].s);
	re->spi = knh_getRegexSPI();
	re->reg = re->spi->regmalloc(ctx, sfp[1].s);
	re->spi->regcomp(ctx, re->reg, ptn, re->spi->parse_cflags(ctx, opt));
	re->eflags = re->spi->parse_eflags(ctx, opt);
	RETURN_(sfp[0].o);
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Private method dynamic String.opLINK(String path, NameSpace _, Class _);

static KMETHOD String_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_class_t cid = (sfp[3].c)->cid;
	DBG_ASSERT(IS_NameSpace(sfp[2].ns));
	DBG_ASSERT(IS_String(sfp[1].s));
	if(!bytes_startsWithLink(S_tobytes(sfp[1].s), S_tobytes(sfp[0].s))) {
		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
		knh_Bytes_write(ctx, cwb->ba, S_tobytes(sfp[0].s));
		knh_Bytes_putc(ctx, cwb->ba, ':');
		knh_Bytes_write(ctx, cwb->ba, S_tobytes(sfp[1].s));
		KNH_SETv(ctx, sfp[1].s, CWB_newString(ctx, cwb, K_SPOLICY_POOLALWAYS));
	}
	knh_Object_t* v = knh_NameSpace_newObject(ctx, sfp[2].ns, sfp[1].s, cid);
	DBG_P("v=%p, true=%p, false=%p", v, KNH_TRUE, KNH_FALSE);
	RETURN_(v);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method Boolean String.opEXISTS(NameSpace _);

static KMETHOD String_opEXISTS(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DBG_ASSERT(IS_NameSpace(sfp[1].ns));
	knh_Object_t* btf = knh_NameSpace_newObject(ctx, sfp[1].ns, sfp[0].s, CLASS_Boolean);
	DBG_P("btf=%p, true=%p, false=%p", btf, KNH_TRUE, KNH_FALSE);
	RETURNb_(btf == KNH_TRUE);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean String.equals(String s);

static KMETHOD String_equals(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_((S_size(sfp[0].s) == S_size(sfp[1].s) &&
		knh_bytes_strcmp(S_tobytes(sfp[0].s), S_tobytes(sfp[1].s)) == 0));
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean String.startsWith(String s);

static KMETHOD String_startsWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(knh_strncmp(S_totext(sfp[0].s), S_totext(sfp[1].s), S_size(sfp[1].s)) == 0);
	//RETURNb_(knh_bytes_startsWith(S_tobytes(sfp[0].s), S_tobytes(sfp[1].s))); older
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean String.endsWith(String s);

static KMETHOD String_endsWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(knh_bytes_endsWith(S_tobytes(sfp[0].s), S_tobytes(sfp[1].s)));
}

/* ------------------------------------------------------------------------ */
//## @Const method String String.concat(Object value, ...);
//## @Const method String String.opADD(dynamic value);

static KMETHOD String_concat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int i, ac = knh_stack_argc(ctx, sfp);
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	for(i = 0; i < ac; i++) {
		if(IS_bString(sfp[i].o)) {
			knh_Bytes_write(ctx, cwb->ba, S_tobytes(sfp[i].s));
		}
		else {
			knh_write_Object(ctx, cwb->w, sfp[i].o, FMT_s);
		}
	}
	RETURN_(CWB_newString(ctx, cwb, 0));
}

/* ------------------------------------------------------------------------ */
//## @Const method Int String.indexOf(String s);

static KMETHOD String_indexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	long loc = -1;
	knh_bytes_t base = S_tobytes(sfp[0].s);
	char *p = strstr(base.text, S_totext(sfp[1].s));
	if (p != NULL) {
		loc = p - base.text;
		if(!String_isASCII(sfp[0].s)) {
			base.len = (size_t)loc;
			loc = knh_bytes_mlen(base);
		}
	}
	RETURNi_(loc);
}

/* ------------------------------------------------------------------------ */
//## @Const method Int String.lastIndexOf(String s);

static KMETHOD String_lastIndexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t base = S_tobytes(sfp[0].s);
	if (IS_NULL(sfp[1].o)) RETURNi_(-1);
	knh_bytes_t delim = S_tobytes(sfp[1].s);
	knh_index_t loc = base.len - delim.len;
	if(delim.len == 0) loc--;
	for(; loc >= 0; loc--) {
		if(base.utext[loc] == delim.utext[0]) {
			knh_bytes_t sub = {{base.text + loc}, delim.len};
			if(knh_bytes_strcmp(sub, delim) == 0) break;
		}
	}
	if (loc >= 0 && !String_isASCII(sfp[0].s)) {
		base.len = (size_t)loc;
		loc = knh_bytes_mlen(base);
	}
	RETURNi_(loc);
}

/* ------------------------------------------------------------------------ */

static void regmatch_init(knh_regmatch_t *pmatch, int nmatch)
{
	int idx;
	for (idx = 0; idx < nmatch; idx++) {
		pmatch[idx].rm_so = -1;
		pmatch[idx].rm_eo = -1;
		pmatch[idx].rm_name.len = 0;
	}
}

static void LOG_regex(CTX ctx, knh_sfp_t *sfp, int res, knh_Regex_t *re, const char *str)
{
	char ebuf[512];
	re->spi->regerror(res, re->reg, ebuf, 512);
	knh_ldata_t ldata[] = {LOG_s("driver", re->spi->name), LOG_s("pattern", S_totext(re->pattern)), LOG_s("text", str), LOG_msg(ebuf)};
	KNH_NTRACE(ctx, "regex", K_FAILED, ldata);
}

static void CWB_write_regexfmt(CTX ctx, CWB_t *cwb, knh_bytes_t *fmt, const char *base, knh_regmatch_t *r, size_t matched)
{
	const char *ch = fmt->text;
	const char *eof = ch + fmt->len; // end of fmt
	for (; ch < eof; ch++) {
		if (*ch == '\\') {
			knh_Bytes_putc(ctx, cwb->ba, *ch);
			ch++;
		} else if (*ch == '$' && isdigit(ch[1])) {
			size_t grpidx = (size_t)ch[1] - '0'; // get head of grourp_index
			if (grpidx < matched) {
				ch++;
				while (isdigit(ch[1])) {
					size_t nidx = grpidx * 10 + (ch[1] - '0');
					if (nidx < matched) {
						grpidx = nidx;
						ch++;
						if (ch < eof) {
							continue;
						}
					}
				}
				knh_regmatch_t *rp = &r[grpidx];
				knh_Bytes_write(ctx, cwb->ba, new_bytes2(base + rp->rm_so, rp->rm_eo - rp->rm_so));
				continue; // skip putc
			}
		}
		knh_Bytes_putc(ctx, cwb->ba, *ch);
	}
}

static size_t knh_regex_matched(knh_regmatch_t* r, size_t maxmatch)
{
	size_t n = 0;
	for (; n < maxmatch && r[n].rm_so != -1; n++) ;
	return n;
}

#define _ALWAYS K_SPOLICY_POOLALWAYS
#define _NEVER  K_SPOLICY_POOLALWAYS
#define _ASCII  K_SPOLICY_ASCII
#define _UTF8   K_SPOLICY_UTF8
#define _SUB(s0) (String_isASCII(s0) ? _ASCII|_ALWAYS : _ALWAYS)
#define _SUBCHAR(s0) (String_isASCII(s0) ? _ASCII : 0)
#define _CHARSIZE(len) (len==1 ? _ASCII : _UTF8)


static knh_Array_t *knh_String_toCharArray(CTX ctx, knh_String_t *bs, int istrim)
{
	knh_bytes_t base = S_tobytes(bs);
	size_t i, n = base.len;
	knh_Array_t *a = new_Array(ctx, CLASS_String, n);
	if(String_isASCII(bs)) {
		for(i = 0; i < n; i++) {
			if(istrim && isspace(base.utext[i])) continue;
			knh_Array_add(ctx, a, new_String2(ctx, CLASS_String, base.text+i, 1, _ALWAYS|_ASCII));
		}
	}
	else {
		n = knh_bytes_mlen(base);
		for(i = 0; i < n; i++) {
			if(istrim && isspace(base.utext[i])) continue;
			knh_bytes_t sub = knh_bytes_mofflen(base, i, 1);
			knh_Array_add(ctx, a, new_String2(ctx, CLASS_String, sub.text, sub.len, _ALWAYS|((sub.len == 1) ? _ASCII:_UTF8)));
		}
	}
	return a;
}

/* ------------------------------------------------------------------------ */
//## @Const method Int String.search(Regex re);

static KMETHOD String_search(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Regex_t *re = sfp[1].re;
	knh_index_t loc = -1;
	if(!IS_NULL(re) && S_size(re->pattern) > 0) {
		knh_regmatch_t pmatch[2]; // modified by @utrhira
		const char *str = S_totext(sfp[0].s);  // necessary
		int res = re->spi->regexec(ctx, re->reg, str, 1, pmatch, re->eflags);
		if(res == 0) {
			loc = pmatch[0].rm_so;
			if (loc != -1 && !String_isASCII(sfp[0].s)) {
				knh_bytes_t base = {{str}, loc};
				loc = knh_bytes_mlen(base);
			}
		}
		else {
			LOG_regex(ctx, sfp, res, re, str);
		}
	}
	RETURNi_(loc);
}

/* ------------------------------------------------------------------------ */
//## @Const method String[] String.match(Regex re);

static KMETHOD String_match(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s0 = sfp[0].s;
	knh_Regex_t *re = sfp[1].re;
	knh_Array_t *a = NULL;
	if(IS_NOTNULL(re) && S_size(re->pattern) > 0) {
		const char *str = S_totext(s0);  // necessary
		const char *base = str;
		const char *eos = base + S_size(s0);
		size_t nmatch = re->spi->regnmatchsize(ctx, re->reg);
		knh_regmatch_t *p, pmatch[nmatch+1];
		int i, isGlobalOption = Regex_isGlobalOption(re);
		a = new_Array(ctx, CLASS_String, nmatch);
		do {
			int res = re->spi->regexec(ctx, re->reg, str, nmatch, pmatch, re->eflags);
			if(res != 0) {
				LOG_regex(ctx, sfp, res, re, str);
				break;
			}
			for(p = pmatch, i = 0; i < nmatch; p++, i++) {
				if (p->rm_so == -1) break;
				//DBG_P("[%d], rm_so=%d, rm_eo=%d", i, p->rm_so, p->rm_eo);
				knh_bytes_t sub = {{str + (p->rm_so)}, ((p->rm_eo) - (p->rm_so))};
				knh_Array_add(ctx, a, new_String2(ctx, CLASS_String, sub.text, sub.len, _SUB(s0)));
			}
			if(isGlobalOption) {
				size_t eo = pmatch[0].rm_eo; // shift matched pattern
				str += (eo > 0) ? eo : 1;
				if(!(str < eos)) isGlobalOption = 0; // stop iteration
			}
		} while(isGlobalOption);
	}
	else {
		a = new_Array(ctx, CLASS_String, 0);
	}
	RETURN_(a);
}

/* ------------------------------------------------------------------------ */
//## @Const method String String.replace(Regex re, String s);

static KMETHOD String_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s0 = sfp[0].s;
	knh_Regex_t *re = sfp[1].re;
	knh_bytes_t fmt = S_tobytes(sfp[2].s);
	knh_String_t *s = s0;
	if(IS_NOTNULL(re) && S_size(re->pattern) > 0) {
		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
		const char *str = S_totext(s0);  // necessary
		const char *base = str;
		const char *eos = str + S_size(s0); // end of str
		knh_regmatch_t pmatch[K_REGEX_MATCHSIZE+1];
		while (str < eos) {
			int res = re->spi->regexec(ctx, re->reg, str, K_REGEX_MATCHSIZE, pmatch, re->eflags);
			if(res != 0) {
				LOG_regex(ctx, sfp, res, re, str);
				break;
			}
			size_t len = pmatch[0].rm_eo;
			if (pmatch[0].rm_so > 0) {
				knh_Bytes_write(ctx, cwb->ba, new_bytes2(str, pmatch[0].rm_so));
			}
			size_t matched = knh_regex_matched(pmatch, K_REGEX_MATCHSIZE);
			if (len > 0) {
				CWB_write_regexfmt(ctx, cwb, &fmt, base, pmatch, matched);
				str += len;
			} else {
				if (str == base) { // 0-length match at head of string
					CWB_write_regexfmt(ctx, cwb, &fmt, base, pmatch, matched);
				}
				break;
			}
		}
		knh_Bytes_write(ctx, cwb->ba, new_bytes((char*)str)); // write out remaining string
		s = CWB_newString(ctx, cwb, 0); // close cwb
	}
	RETURN_(s);
}

/* ------------------------------------------------------------------------ */
//## @Const method String[] String.split(Regex re);

static KMETHOD String_split(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s0 = sfp[0].s;
	knh_Regex_t *re = sfp[1].re;
	knh_Array_t *a = NULL;
	if (IS_NOTNULL(re) && S_size(re->pattern) > 0) {
		const char *str = S_totext(s0);  // necessary
		const char *eos = str + S_size(s0);
		knh_regmatch_t pmatch[K_REGEX_MATCHSIZE+1];
		if (str < eos) {
			a = new_Array(ctx, CLASS_String, 0);
			while (str <= eos) {
				int res = re->spi->regexec(ctx, re->reg, str, K_REGEX_MATCHSIZE, pmatch, re->eflags);
				if (res == 0) {
					size_t len = pmatch[0].rm_eo;
					if (len > 0) {
						knh_bytes_t sub = {{str},  pmatch[0].rm_so};
						knh_Array_add(ctx, a, new_String2(ctx, CLASS_String, sub.text, sub.len, _SUB(s0)));
						str += len;
						continue;
					}
				}
				knh_Array_add(ctx, a, new_String(ctx, str)); // append remaining string to array
				break;
			}
		} else { // for 0-length patterh
			a = knh_String_toCharArray(ctx, new_String(ctx, str), 0);
		}
	}
	else {
		a = knh_String_toCharArray(ctx, s0, 0);
	}
	RETURN_(a);
}

/* ------------------------------------------------------------------------ */
//## @Const method Map String.extract(Regex re);

static KMETHOD String_extract(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s = sfp[0].s;
	knh_Regex_t *re = sfp[1].re;
	knh_DictMap_t *m = new_DictMap0(ctx, 0, 0/*isCase*/, "regex");
	if (IS_NOTNULL(re) && S_size(re->pattern) > 0) {
		size_t nmatch = re->spi->regnmatchsize(ctx, re->reg);  //
		const char *str = s->str.text;
		knh_regmatch_t p[nmatch + 1];
		regmatch_init(p, sizeof(p)/sizeof(knh_regmatch_t));
		int res = re->spi->regexec(ctx, re->reg, str, nmatch, p, re->eflags);
		if (res == 0) {
			int idx, matched = knh_regex_matched(p, nmatch);
			for (idx = 0; idx < matched && p[idx].rm_so != -1; idx++) {
				knh_regmatch_t *rp = &p[idx];
				if (rp->rm_name.len > 0) {
					knh_String_t *s_name = new_String2(ctx, CLASS_String, rp->rm_name.text, rp->rm_name.len, _SUB(s));
					knh_String_t *s_value = new_String2(ctx, CLASS_String, &str[rp->rm_so], (rp->rm_eo - rp->rm_so), _SUB(s));
					knh_DictMap_set(ctx, m, s_name, s_value);
				}
			}
		}
		else {
			LOG_regex(ctx, sfp, res, re, str);
		}
	}
	RETURN_(m);
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Static @Const method Converter Converter.opLINK(String path, NameSpace _);

static KMETHOD Converter_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t t = S_tobytes(sfp[1].s);
	const knh_ConverterDPI_t *dpi = knh_NameSpace_getConverterDPINULL(ctx, sfp[2].ns, t);
	if(dpi != NULL && dpi->conv != NULL) {
		knh_Converter_t *c = new_(Converter);
		c->dpi  = dpi;
		c->conv = NULL;
		RETURN_(c);
	}
	RETURN_(KNH_TNULL(Converter));
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Static @Const method StringEncoder StringEncoder.opLINK(String path, NameSpace _);

static KMETHOD StringEncoder_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t t = S_tobytes(sfp[1].s);
	const knh_ConverterDPI_t *dpi = knh_NameSpace_getConverterDPINULL(ctx, sfp[2].ns, t);
	if(dpi != NULL && dpi->enc != NULL) {
		knh_StringEncoder_t *c = new_(StringEncoder);
		c->dpi  = dpi;
		c->conv = NULL;
		RETURN_(c);
	}
	RETURN_(KNH_TNULL(StringEncoder));
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Static @Const method StringDecoder StringDecoder.opLINK(String path, NameSpace _);

static KMETHOD StringDecoder_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t t = S_tobytes(sfp[1].s);
	const knh_ConverterDPI_t *dpi = knh_NameSpace_getConverterDPINULL(ctx, sfp[2].ns, t);
	if(dpi != NULL && dpi->dec != NULL) {
		knh_StringDecoder_t *c = new_(StringDecoder);
		c->dpi  = dpi;
		c->conv = NULL;
		RETURN_(c);
	}
	RETURN_(KNH_TNULL(StringDecoder));
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Static @Const method StringConverter StringConverter.opLINK(String path, NameSpace _);

static KMETHOD StringConverter_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t t = S_tobytes(sfp[1].s);
	const knh_ConverterDPI_t *dpi = knh_NameSpace_getConverterDPINULL(ctx, sfp[2].ns, t);
	if(dpi != NULL && dpi->sconv != NULL) {
		knh_StringConverter_t *c = new_(StringConverter);
		c->dpi  = dpi;
		c->conv = NULL;
		RETURN_(c);
	}
	RETURN_(KNH_TNULL(StringConverter));
}

/* ------------------------------------------------------------------------ */
//## @Const method Bytes Bytes.(Converter enc);

static KMETHOD Bytes_convert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_Converter_t *c = sfp[1].conv;
	knh_bytes_t t = BA_tobytes(sfp[0].ba);
	c->dpi->conv(ctx, c->conv, t.text, t.len, cwb->ba);
	knh_Bytes_t *ba = new_Bytes(ctx, NULL, CWB_size(cwb));
	knh_Bytes_write(ctx, ba, CWB_tobytes(cwb));
	CWB_close(cwb);
	RETURN_(ba);
}

/* ------------------------------------------------------------------------ */
//## @Const method Bytes String.encode(StringEncoder enc);

static KMETHOD String_encode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_Converter_t *c = sfp[1].conv;
	//fprintf(stderr, "%s, c=%p, c->dpi=%p, c->dpi->enc=****\n", CLASS__(c->h.cid), c, c->dpi);
	c->dpi->enc(ctx, c->conv, S_totext(sfp[0].s), S_size(sfp[0].s), cwb->ba);
	knh_Bytes_t *ba = new_Bytes(ctx, NULL, CWB_size(cwb));
	knh_Bytes_write(ctx, ba, CWB_tobytes(cwb));
	CWB_close(cwb);
	RETURN_(ba);
}

/* ------------------------------------------------------------------------ */
//## @Const method String Bytes.decode(StringDecoder c);

static KMETHOD Bytes_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_Converter_t *c = sfp[1].conv;
	c->dpi->dec(ctx, c->conv, BA_totext(sfp[0].ba), BA_size(sfp[0].ba), cwb->ba);
	RETURN_(CWB_newString(ctx, cwb, 0));
}

/* ------------------------------------------------------------------------ */
//## @Const method String String.(StringConverter c);
//## @Const method String String.convert(StringConverter c);

static KMETHOD String_convert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_Converter_t *c = sfp[1].conv;
	if (!IS_NULL(c)) {
		c->dpi->sconv(ctx, c->conv, S_totext(sfp[0].s), S_size(sfp[0].s), cwb->ba);
	}
	RETURN_(CWB_newString(ctx, cwb, 0));
}

/* ------------------------------------------------------------------------ */
//## @Const method String String.trim();

static KMETHOD String_trim(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s = sfp[0].s;
	knh_bytes_t t = S_tobytes(s);
	knh_bytes_t t2 = bytes_trim(t);
	if(t.len > t2.len) {
		s = new_String2(ctx, CLASS_String, t2.text, t2.len, _SUB(s));
	}
	RETURN_(s);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Regex.opHAS(String s);

static KMETHOD Regex_opHAS(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Regex_t *re = sfp[0].re;
	knh_regmatch_t pmatch[2]; // modified by @utrhira
	const char *str = S_totext(sfp[1].s);
	int res = re->spi->regexec(ctx, re->reg, str, 1, pmatch, re->eflags);
	RETURNb_(res == 0);
}

/* ------------------------------------------------------------------------ */
//## @Const mapper String Int;

static TYPEMAP String_Int(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_int_t v = 0;
	if(!knh_bytes_parseint(S_tobytes(sfp[K_TMRIDX].s), &v)) {
		KNH_SETv(ctx, sfp[K_RIX].o, KNH_NULVAL(CLASS_Int));
	}
	RETURNi_(v);
}

/* ------------------------------------------------------------------------ */
//## @Const mapper String Float;

static TYPEMAP String_Float(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_float_t v = 0.0;
	if(!knh_bytes_parsefloat(S_tobytes(sfp[K_TMRIDX].s), &v)) {
		KNH_SETv(ctx, sfp[K_RIX].o, KNH_NULVAL(CLASS_Float));
	}
	RETURNf_(v);
}

/* ------------------------------------------------------------------------ */
//## @Const mapper String Bytes;

static TYPEMAP String_Bytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *b = new_Bytes(ctx, "UTF8", S_size(sfp[K_TMRIDX].s) + 1);
	knh_Bytes_write(ctx, b, S_tobytes(sfp[K_TMRIDX].s));
	RETURN_(b);
}

/* ------------------------------------------------------------------------ */

static ITRNEXT String_nextChar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Iterator_t *itr = ITR(sfp);
	knh_String_t *s = (knh_String_t*)DP(itr)->source;
	knh_bytes_t base = S_tobytes(s);
	size_t pos = (size_t)DP(itr)->m.index;
	if(pos < knh_bytes_mlen(base)) {
		knh_bytes_t sub = knh_bytes_mofflen(base, pos, 1);
		s = new_String2(ctx, CLASS_String, sub.text, sub.len, _SUB(s));
		DP(itr)->m.index = pos + 1;
		ITRNEXT_(s);
	}
	ITREND_();
}

/* ------------------------------------------------------------------------ */
//## method String.. String.opITR();

static TYPEMAP String_Iterator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(new_IteratorG(ctx, CLASS_StringITR, sfp[0].o, String_nextChar));
}

/* ------------------------------------------------------------------------ */
//## mapper Bytes InputStream;

static TYPEMAP Bytes_InputStream(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(new_BytesInputStream(ctx, sfp[0].ba));
}

/* ------------------------------------------------------------------------ */
//## @Const @Semantic mapper String Regex!;

static KMETHOD String_Regex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Regex_t *re = new_(Regex);
	const char *ptn = S_totext(sfp[0].s);
	KNH_SETv(ctx, re->pattern, sfp[0].s);
	re->reg = re->spi->regmalloc(ctx, sfp[0].s);
	re->spi->regcomp(ctx, re->reg, ptn, 0);
	re->eflags = 0;
	RETURN_(re);
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Const method This Tuple.new:TUPLE(dynamic value, ...);

static KMETHOD Tuple_newTUPLE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Tuple_t *tpl = (knh_Tuple_t*)sfp[0].o;
	knh_sfp_t *v = sfp + 1;
	size_t i, ti = 0, ac = knh_stack_argc(ctx, v);
	knh_fields_t *tf = O_cTBL(tpl)->fields;
	for(i = 0; i < ac; i++) {
		if(tf[ti].israw == 1) {
			knh_ndata_t *n = (knh_ndata_t*)(tpl->fields + ti);
			n[0] = v[i].ndata;
			DBG_P("i=%d, ti=%d, n=%d", i, ti, n[0]);
			ti++;
			DBLNDATA_(ti++);
		}
		else {
			KNH_SETv(ctx, tpl->fields[ti], v[i].o);
			ti++;
		}
	}
	RETURN_(tpl);
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Const method This Range.new:LIST(T1 start, T1 end);

static KMETHOD Range_newLIST(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Range_t *rng = (knh_Range_t*)sfp[0].o;
	if(Range_isNDATA(rng)) {
		rng->nstart = sfp[1].ndata;
		rng->nend =   sfp[2].ndata;
	}
	else {
		KNH_SETv(ctx, rng->ostart, sfp[1].o);
		KNH_SETv(ctx, rng->oend, sfp[2].o);
	}
	RETURN_(rng);
}

/* ------------------------------------------------------------------------ */
/* [Array] */

//## method This Array.new(Int initCapacity);

static KMETHOD Array_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_grow(ctx, sfp[0].a, Int_to(size_t, sfp[1]), 0);
	DBG_ASSERT((sfp[0].a)->size == 0);
	RETURN_(sfp[0].a);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method This Array.new:ARRAY(Int size, ...);

static KMETHOD Array_newARRAY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	knh_int_t init, x = 0, y = 1, z = 1, w = 1;
	size_t dim = knh_stack_argc(ctx, sfp+1);
	switch(dim) {
		case 4: w = sfp[4].ivalue;
		case 3: z = sfp[3].ivalue;
		case 2: y = sfp[2].ivalue;
		case 1: x = sfp[1].ivalue;
	}
	init = x * y * z * w;
	DBG_P("x=%d,y=%d,z=%d,w=%d,dim=%d,init=%d",x,y,z,w,dim, init);
	if(0 <= init && init < LONG_MAX) {
		knh_Array_grow(ctx, a, (size_t)init, 0);
		a->size = (size_t)init;
		if(!Array_isNDATA(a)) {
			knh_class_t p1 = O_p1(a);
			Object *v = knh_getClassDefaultValue(ctx, p1);
			size_t i;
			for(i = 0; i < a->size; i++) {
				KNH_INITv(a->list[i], v);
			}
		}
	}
	else if(unlikely(init < 0)) {
		THROW_OutOfRange(ctx, sfp, init, 0);
	}
	if(init > 0 && dim > 1) {
		((knh_dim_t*)a->dim)->dim = dim;
		((knh_dim_t*)a->dim)->x = (size_t)x;
		((knh_dim_t*)a->dim)->xy = (size_t)(x * y);
		((knh_dim_t*)a->dim)->xyz = (size_t)(x * y * z);
	}
	RETURN_(a);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method This Array.new:LIST(T1 value, ...);

static KMETHOD Array_newLIST(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	a->api->multiadd(ctx, a, sfp+1);
	RETURN_(a);
}

/* ------------------------------------------------------------------------ */

static ITRNEXT Iterator_next(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DBG_ASSERT(IS_bIterator(sfp[0].it));
	knh_Iterator_t *itr = ITR(sfp);
	knh_sfp_t *lsfp = ctx->esp;
	DBG_ASSERT(sfp < lsfp);
	long rtnidx_ = 0, thisidx = rtnidx_ + K_CALLDELTA;
	KNH_SETv(ctx, lsfp[thisidx].o, DP(itr)->source);
	KNH_SCALL(ctx, lsfp, rtnidx_, DP(itr)->mtdNULL, 0);
	if(IS_NULL(lsfp[rtnidx_].o)) {
		ITREND_();
	}
	else {
		ITRNEXT_(lsfp[rtnidx_].o);
	}
}

/* ------------------------------------------------------------------------ */
//## @Hidden method This Iterator.new(Object value, Method mtd);

static KMETHOD Iterator_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Iterator_t *it = sfp[0].it;
	KNH_SETv(ctx, DP(it)->source, sfp[1].o);
	KNH_INITv(DP(it)->mtdNULL, sfp[2].mtd);
	it->fnext_1 = Iterator_next;
	RETURN_(it);
}


/* ------------------------------------------------------------------------ */
//## @Immutable method T1 Array.get(Int n);

static KMETHOD Array_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	size_t n2 = a->api->index(ctx, sfp, Int_to(knh_int_t, ctx->esp[-1]), a->size);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

/* ------------------------------------------------------------------------ */
//## @Immutable @Hidden method T1 Array.get2(Int x, Int y);

static KMETHOD Array_get2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	const knh_dim_t *dim = a->dim;
	knh_int_t n = sfp[1].ivalue + (sfp[2].ivalue * dim->x);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

/* ------------------------------------------------------------------------ */
//## @Immutable @Hidden method T1 Array.get3(Int x, Int y, Int z);

static KMETHOD Array_get3(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	const knh_dim_t *dim = a->dim;
	knh_int_t n = sfp[1].ivalue + (sfp[2].ivalue * dim->x) + (sfp[3].ivalue * dim->xy);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

/* ------------------------------------------------------------------------ */
//## @Immutable @Hidden method T1 Array.get4(Int x, Int y, Int z, Int w);

static KMETHOD Array_get4(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	const knh_dim_t *dim = a->dim;
	knh_int_t n = sfp[1].ivalue + (sfp[2].ivalue * dim->x) + (sfp[3].ivalue * dim->xy) + (sfp[4].ivalue * dim->xyz);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

/* ------------------------------------------------------------------------ */
//## method T1 Array.set(Int n, T1 v);

static KMETHOD Array_set(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	knh_int_t n = sfp[1].ivalue;
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->set(ctx, sfp[0].a, n2, sfp+2);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method T1 Array.set2(Int x, Int y, T1 v);

static KMETHOD Array_set2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	const knh_dim_t *dim = (sfp[0].a)->dim;
	knh_int_t n = sfp[1].ivalue + (sfp[2].ivalue * dim->x);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->set(ctx, a, n2, sfp+3);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method T1 Array.set3(Int x, Int y, Int z, T1 v);

static KMETHOD Array_set3(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	const knh_dim_t *dim = (sfp[0].a)->dim;
	knh_int_t n = sfp[1].ivalue + (sfp[2].ivalue * dim->x) + (sfp[3].ivalue * dim->xy);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->set(ctx, a, n2, sfp+4);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method T1 Array.set4(Int x, Int y, Int z, Int, w, T1 v);

static KMETHOD Array_set4(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	const knh_dim_t *dim = (sfp[0].a)->dim;
	knh_int_t n = sfp[1].ivalue + (sfp[2].ivalue * dim->x) + (sfp[3].ivalue * dim->xy) + (sfp[4].ivalue * dim->xyz);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->set(ctx, a, n2, sfp+5);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

/* ------------------------------------------------------------------------ */
//## method T1 Array.setAll(T1 v);

static KMETHOD Array_setAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t i;
	for(i = 0; i < (sfp[0].a)->size; i++) {
		(sfp[0].a)->api->set(ctx, sfp[0].a, i, sfp+1);
	}
	if((sfp[0].a)->size > 0) {
		(sfp[0].a)->api->fastget(ctx, sfp, 0, K_RIX);
	}
	else {
		sfp[K_RIX].ndata = sfp[1].ndata;
		RETURN_(sfp[1].o);
	}
}

/* ------------------------------------------------------------------------ */
//## method void Array.add(T1 value, ...);
//## method void Array.send(T1 value, ...);

static KMETHOD Array_add(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	a->api->multiadd(ctx, a, sfp+1);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void Array.insert(Int n, T1 value);

static KMETHOD Array_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	size_t n = a->api->index(ctx, sfp, Int_to(knh_int_t, sfp[1]), a->size);
	const knh_dim_t *dim = a->dim;
//	BEGIN_LOCAL(ctx, lsfp, 1);
	if(a->size == dim->capacity) {
		knh_Array_grow(ctx, a, k_grow(dim->capacity), a->size + 1);
	}
	if(Array_isNDATA(a)) {
		knh_memmove(a->nlist+(n+1), a->nlist+n, sizeof(knh_ndata_t) * (a->size - n));
	}else {
		knh_memmove(a->list+(n+1), a->list+n, sizeof(knh_Object_t*) * (a->size - n));
		KNH_INITv(a->list[n], KNH_NULL); // for RCGC
	}
	a->size++;
	a->api->set(ctx, a, n, sfp+2);
//	END_LOCAL(ctx, lsfp);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## @FastCall method void Array.clear();

static KMETHOD Array_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_clear(ctx, sfp[0].a, 0);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */

static void knh_Array_remove_(CTX ctx, knh_Array_t *a, size_t n)
{
	DBG_ASSERT(n < a->size);
	if (Array_isNDATA(a)) {
		knh_memmove(a->nlist+n, a->nlist+(n+1), sizeof(knh_ndata_t) * (a->size - n - 1));
	} else {
		KNH_FINALv(ctx, a->list[n]);
		knh_memmove(a->list+n, a->list+(n+1), sizeof(knh_Object_t*) * (a->size - n - 1));
	}
	a->size--;
}

/* ------------------------------------------------------------------------ */
//## method void Array.remove(Int n);

static KMETHOD Array_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *o = (knh_Array_t*)sfp[0].o;
	size_t n = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[1]), o->size);
	knh_Array_remove_(ctx, o, n);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## @FastCall method T1! Array.pop();

static KMETHOD Array_pop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	if (a->size > 0) {
		(a)->api->fastget(ctx, sfp, a->size - 1, K_RIX);
		knh_Array_clear(ctx, a, a->size - 1);
	}
}
/* ------------------------------------------------------------------------ */
//## method Int Array.indexOf(T1 value);

static KMETHOD Array_indexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	knh_int_t res = -1;
	size_t i;
	if(Array_isNDATA(a)) {
		knh_ndata_t ndata = sfp[1].ndata;
		for(i = 0; i < a->size; i++) {
			if(a->nlist[i] == ndata) {
				res = i; break;
			}
		}
	}else {
		knh_Object_t *o = sfp[1].o;
		for(i = 0; i < a->size; i++) {
			if(knh_Object_compareTo(a->list[i], o) == 0) {
				res = i; break;
			}
		}
	}
	RETURNi_(res);
}
/* ------------------------------------------------------------------------ */
//## method Int Array.lastIndexOf(T1 value);

static KMETHOD Array_lastIndexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	long i;
	if(Array_isNDATA(a)) {
		knh_ndata_t ndata = sfp[1].ndata;
		for(i = a->size - 1; i >= 0; i--) {
			if(a->nlist[i] == ndata) {
				break;
			}
		}
	}else {
		knh_Object_t *o = sfp[1].o;
		for(i = a->size - 1; i >= 0; i--) {
			if(knh_Object_compareTo(a->list[i], o) == 0) {
				break;
			}
		}
	}
	RETURNi_(i);
}

/* ------------------------------------------------------------------------ */

static int qsort_icmp(const void* ap, const void* bp)
{
	knh_int_t a = *((knh_int_t*)ap);
	knh_int_t b = *((knh_int_t*)bp);
	if(a < b) return -1;
	return (a > b);
}

static int qsort_fcmp(const void* ap, const void* bp)
{
	knh_float_t a = *((knh_float_t*)ap);
	knh_float_t b = *((knh_float_t*)bp);
	if(a < b) return -1;
	return (a > b);
}

static int qsort_ocmp(const void *ap, const void* bp)
{
	knh_RawPtr_t* o1 = *((knh_RawPtr_t**)ap);
	knh_RawPtr_t* o2 = *((knh_RawPtr_t**)bp);
	knh_class_t bcid1 = O_bcid(o1);
	knh_class_t bcid2 = O_bcid(o2);
	int res;
	if(bcid1 == bcid2) {
		res = O_cTBL(o1)->cdef->compareTo(o1, o2);
	}
	else {
		res = (int)(o1 - o2);
	}
	return res;
}

// added by @shinpei_NKT
static int knh_compare_i(knh_Func_t *fo, const void *v1, const void *v2)
{
	knh_int_t a = *((knh_int_t*)v1);
	knh_int_t b = *((knh_int_t*)v2);
	CLOSURE_start(2);
	CLOSURE_putArg(1, Int, a);
	CLOSURE_putArg(2, Int, b);
	CLOSURE_call(fo);
	int ret = CLOSURE_getReturn(Int);
	CLOSURE_end(return ret);
}

static int dummyCallbackCompareInt(const void *v1, const void *v2)
{
  return knh_compare_i((knh_Func_t*)CALLBACK_MARKER, v1, v2);
}

static int knh_compare_f(knh_Func_t *fo, const void *v1, const void *v2)
{
	knh_float_t a = *((knh_float_t*)v1);
	knh_float_t b = *((knh_float_t*)v2);
	CLOSURE_start(2);
	CLOSURE_putArg(1, Float, a);
	CLOSURE_putArg(2, Float, b);
	CLOSURE_call(fo);
	int ret = CLOSURE_getReturn(Int);
	CLOSURE_end(return ret);
}

static int dummyCallbackCompareFloat(const void *v1, const void *v2)
{
	return knh_compare_f((knh_Func_t*)CALLBACK_MARKER, v1, v2);
}

static int knh_compare_o(knh_Func_t *fo, const void *v1, const void *v2)
{
	knh_Object_t *a = *((knh_Object_t**)v1);
	knh_Object_t *b = *((knh_Object_t**)v2);
	CLOSURE_start(2);
	lsfp[1].o = a;
	lsfp[2].o = b;
	CLOSURE_call(fo);
	int ret = CLOSURE_getReturn(Int);
	CLOSURE_end(return ret);
}

static int dummyCallbackCompareObject(const void *v1, const void *v2)
{
	return knh_compare_o((knh_Func_t*)CALLBACK_MARKER, v1, v2);
}

typedef int (*fcompare)(const void *, const void *);
typedef int (*fcompare2)(knh_Func_t *, const void *, const void *);
struct asortf {
	size_t size; /* sizeof(T) */
	fcompare  fcmp1;
	fcompare  fdummy;
	fcompare2 fcmp2;
	knh_Map_t *map; /* TODO Map<Func, fcmp2(generated)> */
};
struct asortf asorts[] = {
	{sizeof(knh_boolean_t), qsort_icmp, dummyCallbackCompareInt   , knh_compare_i, NULL},
	{sizeof(knh_int_t)    , qsort_icmp, dummyCallbackCompareInt   , knh_compare_i, NULL},
	{sizeof(knh_float_t)  , qsort_fcmp, dummyCallbackCompareFloat , knh_compare_f, NULL},
	{sizeof(knh_Object_t*), qsort_ocmp, dummyCallbackCompareObject, knh_compare_o, NULL},
};

static struct asortf *getasortf(CTX ctx, knh_class_t cid)
{
	switch (cid) {
		case CLASS_Boolean: return &asorts[0];
		case CLASS_Int:     return &asorts[1];
		case CLASS_Float:   return &asorts[2];
		default:            return &asorts[3];
	}
}

/* ------------------------------------------------------------------------ */
//## method void Array.sort(CmprT1 cmr);

static KMETHOD Array_sort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a  = sfp[0].a;
	knh_Func_t  *fo = sfp[1].fo;
	struct asortf *sortf = getasortf(ctx, O_p1(a));
	fcompare cmp;
	if(IS_NULL(fo)) {
		cmp = sortf->fcmp1;
	}
	else {
		cmp = (fcompare) knh_copyCallbackFunc(ctx, (void*)sortf->fdummy, (void*)sortf->fcmp2, fo);
	}
	knh_qsort(a->list, a->size, sortf->size, cmp);
}

/* ------------------------------------------------------------------------ */

static inline void NArray_swap(CTX ctx, knh_Array_t *a, size_t n, size_t m)
{
	knh_ndata_t temp = a->nlist[n];
	a->nlist[n] = a->nlist[m];
	a->nlist[m] = temp;
}

static inline void OArray_swap(CTX ctx, knh_Array_t *a, size_t n, size_t m)
{
	knh_sfp_t *esp1 = ctx->esp + 1;
	esp1[0].o = a->list[n];
	a->list[n] = a->list[m];
	a->list[m] = esp1[0].o;
}

/* ------------------------------------------------------------------------ */
//## method void Array.swap(Int m, Int n);

static KMETHOD Array_swap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	size_t m = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[1]), a->size);
	size_t n = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[2]), a->size);
	if(Array_isNDATA(a)) {
		NArray_swap(ctx, a, n, m);
	}
	else {
		OArray_swap(ctx, a, n, m);
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void Array.shuffle();

static KMETHOD Array_shuffle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t i;
	knh_Array_t *a = sfp[0].a;
	if(Array_isNDATA(a)) {
		for(i = 0; i < a->size * 2; i++) {
			size_t m = knh_rand() % a->size;
			size_t n = knh_rand() % a->size;
			NArray_swap(ctx, a, m, n);
		}
	}
	else {
		for(i = 0; i < a->size * 2; i++) {
			size_t m = knh_rand() % a->size;
			size_t n = knh_rand() % a->size;
			OArray_swap(ctx, a, m, n);
		}
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void Array.reverse();

static KMETHOD Array_reverse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t i;
	knh_Array_t *a = sfp[0].a;
	if(Array_isNDATA(a)) {
		for(i = 0; i < a->size / 2; i++) {
			size_t n = a->size - i - 1;
			NArray_swap(ctx, a, i, n);
		}
	}
	else {
		for(i = 0; i < a->size / 2; i++) {
			size_t n = a->size - i - 1;
			OArray_swap(ctx, a, i, n);
		}
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */

static ITRNEXT ITR_where(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DBG_ASSERT(IS_bIterator(sfp[0].it));
	knh_Iterator_t *itr = ITR(sfp);
	knh_sfp_t *lsfp = ctx->esp;
	DBG_ASSERT(sfp < lsfp);
	long rtnidx_ = 0, thisidx = rtnidx_ + K_CALLDELTA;
	knh_Iterator_t *itrIN = (knh_Iterator_t*)DP(itr)->source;
	KNH_SETv(ctx, lsfp[thisidx+2].o, itrIN);
	klr_setesp(ctx, lsfp + thisidx+2);
	while(itrIN->fnext_1(ctx, lsfp+thisidx+2, -1)) {
		knh_Func_t *fo = DP(itr)->funcNULL;
		KNH_FINVOKE(ctx, lsfp, rtnidx_, fo, 1);
		if(lsfp[rtnidx_].bvalue) {
			sfp[K_RIX].ndata = lsfp[thisidx+1].ndata;
			ITRNEXT_(lsfp[thisidx+1].o);
		}
		KNH_SETv(ctx, lsfp[thisidx+2].o, itrIN);
		klr_setesp(ctx, lsfp + thisidx+2);
	}
	ITREND_();
}

static ITRNEXT ITR_each(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DBG_ASSERT(IS_bIterator(sfp[0].it));
	knh_Iterator_t *itr = ITR(sfp);
	knh_sfp_t *lsfp = ctx->esp;
	DBG_ASSERT(sfp < lsfp);
	long rtnidx_ = 0, thisidx = rtnidx_ + K_CALLDELTA;
	knh_Iterator_t *itrIN = (knh_Iterator_t*)DP(itr)->source;
	KNH_SETv(ctx, lsfp[thisidx+2].o, itrIN);
	klr_setesp(ctx, lsfp + thisidx+2);
	if(!itrIN->fnext_1(ctx, lsfp+thisidx+2, -1)) {
		ITREND_();
	}
	knh_Func_t *fo = DP(itr)->funcNULL;
	KNH_FINVOKE(ctx, lsfp, rtnidx_, fo, 1);
	sfp[K_RIX].ndata = lsfp[rtnidx_].ndata;
	ITRNEXT_(lsfp[rtnidx_].o);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method This Iterator.opWHERE(FuncWhere f);

static KMETHOD Iterator_opWHERE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Iterator_t *it = (knh_Iterator_t*)new_Object_init2(ctx, O_cTBL(sfp[0].it));
	KNH_SETv(ctx, DP(it)->source, sfp[1].o);
	KNH_INITv(DP(it)->funcNULL, sfp[1].o);
	it->fnext_1 = ITR_where;
	RETURN_(it);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method This Iterator.opEACH(FuncEach f);

static KMETHOD Iterator_opEACH(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Iterator_t *it = (knh_Iterator_t*)new_Object_init2(ctx, O_cTBL(sfp[0].it));
	KNH_SETv(ctx, DP(it)->source, sfp[1].o);
	KNH_INITv(DP(it)->funcNULL, sfp[1].o);
	it->fnext_1 = ITR_each;
	RETURN_(it);
}


/* ------------------------------------------------------------------------ */
//## method This Map.new(Int init);

static KMETHOD Map_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *m = (knh_Map_t *)sfp[0].o;
	size_t init = sfp[1].ivalue <= 0 ? 0: Int_to(size_t, sfp[1]);
	m->spi = knh_getDefaultMapDSPI(ctx, O_p1(m), O_p2(m));
	m->mapptr = m->spi->init(ctx, init, NULL, NULL);
	RETURN_(m);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method This Map.new:MAP(T1 value, ...);

static KMETHOD Map_newMAP(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *m = sfp[0].m;
	knh_sfp_t *v = sfp + 1;
	size_t i, ac = knh_stack_argc(ctx, v);
	m->spi = knh_getDictMapDSPI(ctx, O_p1(m), O_p2(m));
	KNH_ASSERT(m->spi != NULL); // if NULL, it is unsupported
	m->mapptr  = m->spi->init(ctx, 0, NULL, NULL);
	for(i = 0; i < ac; i+=2) {
		m->spi->set(ctx, m->mapptr, v + i);
	}
	RETURN_(m);
}

/* ------------------------------------------------------------------------ */
//## @Static @Throwable @Smart method Map Map.open(String path, Map _, NameSpace _, Class _);

static KMETHOD Map_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const knh_ClassTBL_t *ct = (sfp[4].c)->cTBL;
	const knh_MapDPI_t *spi = knh_NameSpace_getMapDPINULL(ctx, sfp[3].ns, S_tobytes(sfp[1].s));
	knh_Map_t *m = NULL;
	DBG_P("reqt = %s", CLASS__(ct->cid));
	if(ct->bcid != CLASS_Map) ct = ClassTBL(CLASS_Map);
	if(spi == NULL) {
		LANG_LOG("unknown Map driver: %s", S_totext(sfp[1].s));
		goto L_RETURN;
	}
	spi = spi->config(ctx, ct->p1, ct->p2);
	if(spi == NULL) {
		LANG_LOG("Map driver %s does not support for %s", S_tobytes(sfp[1].s), TYPE__(ct->cid));
		goto L_RETURN;
	}
	knh_DictMap_t *opt = knh_toDictMap(ctx, sfp[2].m, 1/*isCreation*/);
	KNH_SETv(ctx, sfp[2].o, opt);
	knh_mapptr_t *mapptr = spi->init(ctx, 0, S_totext(sfp[1].s), opt);
	if(mapptr != NULL) {
		m = (knh_Map_t*)new_Object_init2(ctx, ct);
		m->mapptr = mapptr;
		m->spi = spi;
	}
	L_RETURN: ;
	if(m == NULL) {
		m = (knh_Map_t*)KNH_NULVAL(ct->cid);
	}
	RETURN_(m);
}


/* ------------------------------------------------------------------------ */
//## method Exception! Exception.new(String event, String msg);

static KMETHOD Exception_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_write(ctx, cwb->w, S_tobytes(sfp[1].s));
	if(IS_NULL(sfp[2].s)) {
		knh_write_ascii(ctx, cwb->w, "!!");
	}
	else {
		knh_write_ascii(ctx, cwb->w, "!!: ");
		knh_write(ctx, cwb->w, S_tobytes(sfp[2].s));
	}
	KNH_SETv(ctx, (sfp[0].e)->emsg, CWB_newString(ctx, cwb, K_SPOLICY_POOLNEVER));
	RETURN_(sfp[0].e);
}

/* ------------------------------------------------------------------------ */
//## method This Func.new(dynamic base, Method method);

static KMETHOD Func_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Func_t   *fo = sfp[0].fo;
	knh_Method_t *mtd = sfp[2].mtd;
	KNH_SETv(ctx, (fo)->mtd, sfp[2].mtd);
	if(!Method_isStatic(mtd)) {
		KNH_INITv((fo)->baseNULL, sfp[1].o);
	}
	//(sfp[0].cc)->envsfp = NULL;
	RETURN_(fo);
}

/* ------------------------------------------------------------------------ */
//## @Const method Assurance Assurance.new(String msg);

static KMETHOD Assurance_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Assurance_t *Assurance = sfp[0].as;
	KNH_SETv(ctx, Assurance->msg, sfp[1].s);
	RETURN_(sfp[0].o);
}

/* ------------------------------------------------------------------------ */
/* [Operator] */

/* ------------------------------------------------------------------------ */
//## @Const method Int Object.opADDR();

static KMETHOD Object_opADDR(CTX ctx, knh_sfp_t *sfp _RIX)
{
	void *p = NULL;
	if(IS_Boolean(sfp[0].o)) {
		p = (sfp[0].bvalue) ? (void*)(KNH_TRUE) : (void*)(KNH_FALSE);
	}
	else {
		p = (void*)sfp[0].o;
	}
	RETURNi_((knh_uintptr_t)p);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Object.opOF(Class c);

static KMETHOD Object_opOF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_type_t reqt = Class_tocid(sfp[1]);
	DBG_P("cid=%s", O__(sfp[0].o));
	RETURNb_(ClassTBL_isa(O_cTBL(sfp[0].o), reqt));
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Object.opEQ(dynamic value);

static KMETHOD Object_opEQ(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(knh_Object_compareTo(sfp[0].o, sfp[1].o) == 0);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Object.opNOTEQ(dynamic value);

static KMETHOD Object_opNOTEQ(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(knh_Object_compareTo(sfp[0].o, sfp[1].o) != 0);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Object.opLT(dynamic value);

static KMETHOD Object_opLT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(knh_Object_compareTo(sfp[0].o, sfp[1].o) < 0);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Object.opLTE(dynamic value);

static KMETHOD Object_opLTE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(knh_Object_compareTo(sfp[0].o, sfp[1].o) <= 0);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Object.opGT(dynamic value);

static KMETHOD Object_opGT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(knh_Object_compareTo(sfp[0].o, sfp[1].o) > 0);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Object.opGTE(dynamic value);

static KMETHOD Object_opGTE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(knh_Object_compareTo(sfp[0].o, sfp[1].o) >= 0);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Int.opEQ(Int value);

static KMETHOD Int_opEQ(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(sfp[0].ivalue == sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## @Const  method Boolean Int.opNOTEQ(Int value);

static KMETHOD Int_opNOTEQ(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(sfp[0].ivalue != sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Int.opLT(Int value);

static KMETHOD Int_opLT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(sfp[0].ivalue < sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Int.opLTE(Int value);

static KMETHOD Int_opLTE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(sfp[0].ivalue <= sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Int.opGT(Int value);

static KMETHOD Int_opGT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(sfp[0].ivalue > sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Int.opGTE(Int value);

static KMETHOD Int_opGTE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(sfp[0].ivalue >= sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Float.opEQ(Float value);

static KMETHOD Float_opEQ(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(sfp[0].fvalue == sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Float.opNOTEQ(Float value);

static KMETHOD Float_opNOTEQ(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(sfp[0].fvalue != sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Float.opLT(Float! value);

static KMETHOD Float_opLT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(sfp[0].fvalue < sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Float.opLTE(Float! value);

static KMETHOD Float_opLTE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(sfp[0].fvalue <= sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Float.opGT(Float! value);

static KMETHOD Float_opGT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(sfp[0].fvalue > sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Float.opGTE(Float! value);

static KMETHOD Float_opGTE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(sfp[0].fvalue >= sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */
/* [opHAS] */

/* ------------------------------------------------------------------------ */
//## @Const method Boolean String.opHAS(String s);

static KMETHOD String_opHAS(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(strstr(S_totext(sfp[0].s), S_totext(sfp[1].s)) != NULL);
}

///* ------------------------------------------------------------------------ */
////## method Boolean Range.opHAS(dynamic v);
//
//static KMETHOD Range_opHAS(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	int res = 0/*NotFound*/;
//	knh_Range_t *o = sfp[0].range;
//	if(IS_Int((o)->start) && IS_Float(sfp[1].o)) {
//		KNH_SETv(ctx, sfp[1].o, new_Int_(ctx, CLASS_Int, (knh_int_t)sfp[1].fvalue));
//	}
//	else if(IS_Float((o)->start) && IS_Int(sfp[1].o)) {
//		KNH_SETv(ctx, sfp[1].o, new_Float_(ctx, CLASS_Float, (knh_float_t)sfp[1].ivalue));
//	}
//	else {
//		knh_stack_boxing(ctx, sfp + 1);
//	}
//	if(knh_Object_compareTo(ctx, o->start, sfp[1].o) <= 0) {
//		if(Range_isInclusive(o)) {
//			if(knh_Object_compareTo(ctx, sfp[1].o, o->end) <= 0) {
//				res = 1;
//			}
//		}
//		else {
//			if(knh_Object_compareTo(ctx, sfp[1].o, o->end) < 0) {
//				res = 1;
//			}
//		}
//	}
//	RETURNb_(res);
//}

/* ------------------------------------------------------------------------ */
//## method Boolean Array.opHAS(dynamic v);

static KMETHOD Array_opHAS(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = (knh_Array_t*)sfp[0].o;
	size_t i, res = 0/*NotFound*/;
	if(Array_isNDATA(a)) {
		knh_ndata_t d = O_data(sfp[1].o);
		for(i = 0; i < knh_Array_size(a); i++) {
			if(d == a->nlist[i]) { res = 1; break; }
		}
	}
	else {
		for(i = 0; i < knh_Array_size(a); i++) {
			if(knh_Object_compareTo(a->list[i], sfp[1].o) == 0) {
				res = 1; break;
			}
		}
	}
	RETURNb_(res);
}

///* ------------------------------------------------------------------------ */
////## method Boolean Tuple.opHAS(dynamic v);

//static KMETHOD Tuple_opHAS(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	if(Tuple_isTriple(sfp[0].tuple)) {
//		knh_Tuple_t *t = sfp[0].tuple;
//		int res;
//		knh_stack_boxing(ctx, sfp + 1);
//		res = ((knh_Object_compareTo(ctx, t->first, sfp[1].o) == 0)
//				|| (knh_Object_compareTo(ctx, t->second, sfp[1].o) == 0)
//				|| (t->thirdNULL != NULL && (knh_Object_compareTo(ctx, t->thirdNULL, sfp[1].o) == 0)));
//		RETURNb_(res);
//	}
//	else {
//		Array_opHAS(ctx, sfp, rix); // reuse
//	}
//}

/* ------------------------------------------------------------------------ */
/* [Semantic Comparator] */

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Object.opIS(dynamic v);

static KMETHOD Object_opIS(CTX ctx, knh_sfp_t *sfp _RIX)
{
//	knh_class_t scid = O_cid(sfp[0].o);
//	knh_class_t tcid = O_cid(sfp[1].o);
//	DBG_P("Semantic Matching %s === %s", CLASS__(scid), CLASS__(tcid));
//	if(scid == tcid) {
//		Object_opEQ(ctx, sfp. rix);
//	}
//	else if(IS_NULL(sfp[1].o)) {
//		RETURNb_(IS_NULL(sfp[0].o));
//	}
//	else
	{
		TODO();
		RETURNb_(0);
//		BEGIN_LOCAL(ctx, lsfp);
//		KNH_LPUSH(ctx, sfp[1].o);
//		VM_MAP(ctx, scid);
//		KNH_SETv(ctx, sfp[1].o, ctx->esp[0].o);
//		END_LOCAL(ctx, lsfp);
//		if(IS_NULL(sfp[1].o)) {
//			RETURNb_(0);
//		}
//		else {
//			Object_opEQ(ctx, sfp);
//		}
	}
}

/* ------------------------------------------------------------------------ */
//## method Boolean Map.opHAS(T1 key);

static KMETHOD Map_opHAS(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *m = sfp[0].m;
	RETURNb_(m->spi->get(ctx, m->mapptr, sfp + 1, sfp + K_RIX));
}

/* ------------------------------------------------------------------------ */
//## method T2 Map.get(T1 key);

static KMETHOD Map_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *m = sfp[0].m;
	if(!m->spi->get(ctx, m->mapptr, sfp + 1, sfp + K_RIX)) {
		knh_class_t cid = O_cTBL(m)->p2;
		sfp[K_RIX].ndata = 0;
		RETURN_(KNH_NULVAL(cid));
	}
}

/* ------------------------------------------------------------------------ */
//## method void Map.set(T1 key, T2 value);

static KMETHOD Map_set(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *m = sfp[0].m;
	m->spi->set(ctx, m->mapptr, sfp + 1);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void Map.remove(T1 key);

static KMETHOD Map_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *m = sfp[0].m;
	m->spi->remove(ctx, m->mapptr, sfp + 1);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method T1[] Map.keys();

static KMETHOD Map_keys(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *m = sfp[0].m;
	size_t size = m->spi->size(ctx, m->mapptr);
	knh_class_t p1 = O_cTBL(m)->p1;
	knh_Array_t *a = new_Array(ctx, p1, size);
	knh_sfp_t *lsfp = ctx->esp;
	knh_nitr_t mitrbuf = K_NITR_INIT, *mitr = &mitrbuf;
	klr_setesp(ctx, lsfp+1);
	while(m->spi->next(ctx, m->mapptr, mitr, lsfp)) {
		a->api->add(ctx, a, lsfp);
		klr_setesp(ctx, lsfp+1);
	}
	RETURN_(a);
}

/* ------------------------------------------------------------------------ */
/* [Arithemetic] */

/* ------------------------------------------------------------------------ */
/* [Int] */

//## @Const method Int Int.opADD(Int v);

static KMETHOD Int_opADD(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(sfp[0].ivalue + sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Int Int.opNEG();

static KMETHOD Int_opNEG(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(-(sfp[0].ivalue));
}

/* ------------------------------------------------------------------------ */
//## @Const method Int Int.opSUB(Int n);

static KMETHOD Int_opSUB(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(sfp[0].ivalue - sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Int Int.opMUL(Int n);

static KMETHOD Int_opMUL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(sfp[0].ivalue * sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Int Int.opDIV(Int n);

static KMETHOD Int_opDIV(CTX ctx, knh_sfp_t *sfp _RIX)
{
	SYSLOG_iZERODIV(ctx, sfp, sfp[1].ivalue);
	RETURNi_(sfp[0].ivalue / sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Int Int.opMOD(Int n);

static KMETHOD Int_opMOD(CTX ctx, knh_sfp_t *sfp _RIX)
{
	SYSLOG_iZERODIV(ctx, sfp, sfp[1].ivalue);
	RETURNi_(sfp[0].ivalue % sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
/* [Float] */
//## @Const method Float! Float.opADD(Float! v);

static KMETHOD Float_opADD(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(sfp[0].fvalue + sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Float! Float.opNEG();

static KMETHOD Float_opNEG(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(-(sfp[0].fvalue));
}

/* ------------------------------------------------------------------------ */
//## @Const method Float! Float.opSUB(Float! n);

static KMETHOD Float_opSUB(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(sfp[0].fvalue - sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Float! Float.opMUL(Float! n);

static KMETHOD Float_opMUL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(sfp[0].fvalue * sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Float! Float.opDIV(Float! n);

static KMETHOD Float_opDIV(CTX ctx, knh_sfp_t *sfp _RIX)
{
	SYSLOG_fZERODIV(ctx, sfp, sfp[1].fvalue);
	RETURNf_(sfp[0].fvalue / sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method String String.opSUB(String s);

static KMETHOD String_opSUB(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t base = S_tobytes(sfp[0].s);
	knh_bytes_t t = S_tobytes(sfp[1].s);
	knh_uchar_t c = t.utext[0];
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	size_t i;
	for(i = 0; i < base.len; i++) {
		if(base.utext[i] == c) {
			size_t j;
			for(j = 1; j < t.len; j++) {
				if(base.utext[i+j] != t.utext[j]) break;
			}
			if(j == t.len) {
				i += t.len - 1;
				continue;
			}
		}
		knh_Bytes_putc(ctx, cwb->ba, base.utext[i]);
	}
	if(base.len == CWB_size(cwb)) {
		CWB_close(cwb);
		RETURN_(sfp[0].o);
	}
	else {
		RETURN_(CWB_newString(ctx, cwb, 0));
	}
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Boolean.opNOT();

static KMETHOD Boolean_opNOT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(!sfp[0].bvalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Int Int.opLAND(Int n, ...);

static KMETHOD Int_opLAND(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t i, ac = knh_stack_argc(ctx, sfp);
	knh_int_t n = sfp[0].ivalue;
	for(i = 1; i < ac; i++) {
		n = n & sfp[i].ivalue;
	}
	RETURNi_(n);
}

/* ------------------------------------------------------------------------ */
//## @Const method Int Int.opLOR(Int n, ...);

static KMETHOD Int_opLOR(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t i, ac = knh_stack_argc(ctx, sfp);
	knh_int_t n = sfp[0].ivalue;
	for(i = 1; i < ac; i++) {
		n = n | sfp[i].ivalue;
	}
	RETURNi_(n);
}

/* ------------------------------------------------------------------------ */
//## @Const method Int Int.opLXOR(Int n);

static KMETHOD Int_opLXOR(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(sfp[0].ivalue ^ sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Int Int.opLNOT();

static KMETHOD Int_opLNOT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(~(sfp[0].ivalue));
}

/* ------------------------------------------------------------------------ */
//## @Const method Int Int.opLSFT(Int n);
//## @Const @Hidden method Int Int.send(Int n);

static KMETHOD Int_opLSFT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(sfp[0].ivalue << sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## @Const method Int Int.opRSFT(Int n);

static KMETHOD Int_opRSFT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(sfp[0].ivalue >> sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## method Int Bytes.getSize();
//## method Int Array.getSize();

KMETHOD Bytes_getSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	//fprintf(stderr, "** rix=%ld sfp[K_RIX]=%p\n", rix, sfp + rix);
	RETURNi_((sfp[0].ba)->bu.len);
}

/* ------------------------------------------------------------------------ */
//## method Int Tuple.getSize();

KMETHOD Tuple_getSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(O_cTBL(sfp[0].o)->cparam->psize);
}

/* ------------------------------------------------------------------------ */
//## method @Const Int String.getSize();

static KMETHOD String_getSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t size = IS_bString(sfp[0].s) ? S_size(sfp[0].s) : 0;
	if(!String_isASCII(sfp[0].s)) {
		size = knh_bytes_mlen(S_tobytes(sfp[0].s));
	}
	RETURNi_(size);
}

/* ------------------------------------------------------------------------ */
//## method Int Map.getSize();

KMETHOD Map_getSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *m = sfp[0].m;
	RETURNi_(m->spi->size(ctx, m->mapptr));
}

/* ------------------------------------------------------------------------ */
/* [get,set] */

/* ------------------------------------------------------------------------ */
//## method Int Bytes.get(Int n);

static KMETHOD Bytes_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *ba = sfp[0].ba;
	size_t n2 = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[1]), ba->bu.len);
	RETURNi_(ba->bu.utext[n2]);
}

/* ------------------------------------------------------------------------ */
//## method Int Bytes.set(Int n, Int c);

static KMETHOD Bytes_set(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *ba = sfp[0].ba;
	size_t n2 = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[1]), ba->bu.len);
	ba->bu.ubuf[n2] = Int_to(knh_uchar_t, sfp[2]);
	RETURNi_(ba->bu.utext[n2]);
}

/* ------------------------------------------------------------------------ */
//## method void Bytes.setAll(Int c);

static KMETHOD Bytes_setAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *ba = sfp[0].ba;
	size_t i, n = Int_to(size_t, sfp[1]);
	for(i = 0; i < ba->bu.len; i++) {
		ba->bu.ubuf[i] = n;
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## @Const method String String.get(Int n);

static KMETHOD String_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t base = S_tobytes(sfp[0].s);
	knh_String_t *s;
	if(String_isASCII(sfp[0].s)) {
		size_t n = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[1]), S_size(sfp[0].s));
		s = new_String2(ctx, CLASS_String, base.text + n, 1, _ALWAYS|_ASCII);
	}
	else {
		size_t off = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[1]), knh_bytes_mlen(base));
		knh_bytes_t sub = knh_bytes_mofflen(base, off, 1);
		s = new_String2(ctx, CLASS_String, sub.text, sub.len, _ALWAYS|_CHARSIZE(sub.len));
	}
	RETURN_(s);
}

/* ------------------------------------------------------------------------ */
/* [range] */

static void _rangeUNTIL(CTX ctx, knh_sfp_t *sfp, size_t size, size_t *s, size_t *e)
{
	*s = sfp[1].ivalue == 0 ? 0 : knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[1]), size);
	*e = sfp[2].ivalue == 0 ? (size) : knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[2]), size);
}

static void _rangeTO(CTX ctx, knh_sfp_t *sfp, size_t size, size_t *s, size_t *e)
{
	*s = sfp[1].ivalue == 0 ? 0 : knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[1]), size);
	*e = sfp[2].ivalue == 0 ? (size) : knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[2]), size) + 1;
}

/* ------------------------------------------------------------------------ */

static knh_Bytes_t *new_BytesRANGE(CTX ctx, knh_Bytes_t *ba, size_t s, size_t e)
{
	knh_Bytes_t *newa = new_(Bytes);
	if(e < s) {
		size_t t = s; s = e; e = t;
	}
	DBG_ASSERT(e <= BA_size(ba));
	if(s < e) {
		size_t newsize = e - s;
		size_t capacity = newsize;
		if(newsize > 0) {
			if(capacity < 256) capacity = 256;
			newa->bu.ubuf = (knh_uchar_t*)KNH_MALLOC(ctx, capacity);
			knh_bzero(newa->bu.ubuf, capacity);
			knh_memcpy(newa->bu.ubuf, ba->bu.utext + s, newsize);
		}
		else {
			newa->bu.ubuf = NULL;
		}
		newa->dim = new_dim(ctx, capacity, 1);
		newa->bu.len = newsize;
	}
	return newa;
}

/* ------------------------------------------------------------------------ */
//## method Bytes Bytes.opUNTIL(Int s, Int e);

static KMETHOD Bytes_opUNTIL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t s, e;
	_rangeUNTIL(ctx, sfp, (sfp[0].ba)->bu.len, &s, &e);
	RETURN_(new_BytesRANGE(ctx, sfp[0].ba, s, e));
}

/* ------------------------------------------------------------------------ */
//## method Bytes Bytes.opTO(Int s, Int e);

static KMETHOD Bytes_opTO(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t s, e;
	_rangeTO(ctx, sfp, (sfp[0].ba)->bu.len, &s, &e);
	RETURN_(new_BytesRANGE(ctx, sfp[0].ba, s, e));
}

/* ------------------------------------------------------------------------ */
//## @Const method String String.substring(Int offset, Int length);

static KMETHOD String_substring(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s;
	knh_bytes_t base = S_tobytes(sfp[0].s);
	knh_bytes_t t;
	if(String_isASCII(sfp[0].s)) {
		size_t offset = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[1]), base.len);
		t = knh_bytes_last(base, offset);
		if(sfp[2].ivalue != 0) {
			size_t len = (size_t)sfp[2].ivalue;
			if(len < t.len) t = knh_bytes_first(t, len);
		}
	}
	else { // multibytes
		size_t mlen = knh_bytes_mlen(base);
		size_t offset = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[1]), mlen);
		size_t length = sfp[2].ivalue == 0  ? (mlen - offset) : (size_t)sfp[2].ivalue;
		t = knh_bytes_mofflen(base, offset, length);
	}
	s = new_String2(ctx, CLASS_String, t.text, t.len, _SUBCHAR(sfp[0].s));
	RETURN_(s);
}

/* ------------------------------------------------------------------------ */
//## @Const method String String.opUNTIL(Int s, Int e);

static KMETHOD String_opUNTIL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t t = S_tobytes(sfp[0].s);
	if(sfp[2].ivalue != 0) {
		if(!String_isASCII(sfp[0].s)) {
			size_t mlen = knh_bytes_mlen(t);
			size_t offset = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[1]), mlen);
			size_t length = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[2]), mlen) - offset;
			t = knh_bytes_mofflen(t, offset, length);
			RETURN_(new_String2(ctx, CLASS_String, t.text, t.len, 0));
		}
		else {
			size_t offset = Int_to(size_t, sfp[1]);
			sfp[2].ivalue = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[2]), (sfp[0].s)->str.len) - offset;
		}
	}
	String_substring(ctx, sfp, K_RIX);
}

/* ------------------------------------------------------------------------ */
//## @Const method String String.opTO(Int s, Int e);

static KMETHOD String_opTO(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t t = S_tobytes(sfp[0].s);
	if(sfp[2].ivalue != 0) {
		if(!String_isASCII(sfp[0].s)) {
			size_t mlen = knh_bytes_mlen(t);
			size_t offset = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[1]), mlen);
			size_t length = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[2]), mlen) - offset + 1;
			t = knh_bytes_mofflen(t, offset, length);
			RETURN_(new_String2(ctx, CLASS_String, t.text, t.len, 0));
		}
		else {
			size_t offset = Int_to(size_t, sfp[1]);
			sfp[2].ivalue = knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[2]), (sfp[0].s)->str.len) - offset + 1;
		}
	}
	String_substring(ctx, sfp, K_RIX);
}

/* ------------------------------------------------------------------------ */

static knh_Array_t *new_ArrayRANGE(CTX ctx, knh_Array_t *a, size_t s, size_t e /*until*/)
{
	knh_Array_t *newa = new_O(Array, O_cid(a));
	if(e < s) {
		size_t t = s; s = e; e = t;
	}
	if(s < e) {
		DBG_ASSERT(e <= a->size);
		size_t newsize = e - s;
		size_t sizeofdata = a->dim->wsize;
		if(newsize > 0) {
			char *p = (char*)a->list;
			knh_Array_grow(ctx, newa, newsize, newsize);
			knh_memcpy(newa->list, p + (s * sizeofdata), newsize * sizeofdata);
			if(!Array_isNDATA(a)) {
				size_t i;
				for(i = 0; i < newsize; i++) {
					knh_Object_RCinc(newa->list[i]);
				}
			}
		}
		newa->size = newsize;
	}
	return newa;
}

/* ------------------------------------------------------------------------ */
//## method This Array.opUNTIL(Int s, Int e);

static KMETHOD Array_opUNTIL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t s, e;
	_rangeUNTIL(ctx, sfp, knh_Array_size(sfp[0].a), &s, &e);
	RETURN_(new_ArrayRANGE(ctx, sfp[0].a, s, e));
}

/* ------------------------------------------------------------------------ */
//## method This Array.opTO(Int s, Int e);

static KMETHOD Array_opTO(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t s, e;
	_rangeTO(ctx, sfp, knh_Array_size(sfp[0].a), &s, &e);
	RETURN_(new_ArrayRANGE(ctx, sfp[0].a, s, e));
}

/* ------------------------------------------------------------------------ */
//## @Hidden method void Func.();

static KMETHOD Func_invoke(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Func_t* fo = sfp[0].fo;
	if(fo->baseNULL != NULL) {
		KNH_SETv(ctx, sfp[0].o, fo->baseNULL);
	}
	klr_setmtdNC(ctx, sfp[K_MTDIDX], fo->mtd);
	KNH_SELFCALL(ctx, sfp, fo->mtd, K_RIX);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method T1 Thunk.();

static KMETHOD Fmethod_returnConst(CTX ctx, knh_sfp_t *sfp _RIX)
{
	// return values are always set at sfp[_rix] correctly
}

/* ------------------------------------------------------------------------ */
//## method T1 Thunk.eval();

static KMETHOD Thunk_eval(CTX ctx, knh_sfp_t *sfp _RIX)
{

	knh_Thunk_t *thk = (knh_Thunk_t*)sfp[0].o;
	knh_sfp_t *lsfp = ctx->esp;
	//DBG_P("rix=%d, sfpidx=%d, espidx=%d", rix, sfp-ctx->stack, ctx->esp - ctx->stack);
	knh_Method_t *mtd = (thk)->envsfp[K_CALLDELTA+K_MTDIDX].mtdNC;
	size_t i;
	for(i = 0; i < (thk)->envsize; i++) {
		KNH_SETv(ctx, lsfp[i].o, (thk)->envsfp[i].o);
		lsfp[i].ndata = (thk)->envsfp[i].ndata;
	}
	KNH_SCALL(ctx, lsfp, 0, mtd, ((thk)->envsize-K_CALLDELTA));
	KNH_SETv(ctx, (thk)->envsfp[0].o, lsfp[0].o);
	(thk)->envsfp[0].ndata = lsfp[0].ndata;
	Thunk_setEvaluated(thk, 1);
	KNH_SETv(ctx, sfp[K_RIX].o, (thk)->envsfp[0].o);
	sfp[K_RIX].ndata = (thk)->envsfp[0].ndata;
}

/* ------------------------------------------------------------------------ */
//## method T1 Thunk.getValue();
//## mapper Thunk Tvoid;

static KMETHOD Thunk_value(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Thunk_t *thk = (knh_Thunk_t*)sfp[0].o;
	if(Thunk_isEvaluated(thk)) {
		KNH_SETv(ctx, sfp[K_RIX].o, (thk)->envsfp[0].o);
		sfp[K_RIX].ndata = (thk)->envsfp[0].ndata;
	}
	else {
		Thunk_eval(ctx, sfp, K_RIX);
	}
}

/* ------------------------------------------------------------------------ */
//## @Throwable method InputStream InputStream.new(Path urn, String mode, Map _);

static KMETHOD InputStream_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_InputStream_t *in = sfp[0].in;
	knh_Path_t *pth = sfp[1].pth;
	const char *mode = IS_NULL(sfp[2].s) ? "r" : S_totext(sfp[2].s);
	in->dpi = pth->dpi;
	DP(in)->fio = in->dpi->fopenSPI(ctx, pth, mode, knh_toDictMap(ctx, sfp[3].m, 0/*isCreation*/));
	if(DP(in)->fio != IO_NULL) {
		knh_Bytes_ensureSize(ctx, DP(in)->ba, K_PAGESIZE);
	}
	else {
		knh_Object_toNULL(ctx, in);
		in->dpi = knh_getDefaultStreamDPI();
	}
	KNH_SETv(ctx, DP(in)->path, pth);
	RETURN_(in);
}


/* ------------------------------------------------------------------------ */

size_t knh_InputStream_read(CTX ctx, knh_InputStream_t *in, char *buf, size_t bufsiz)
{
	if(knh_isFILEStreamDPI(in->dpi)) {
		return in->dpi->freadSPI(ctx, DP(in)->fio, buf, bufsiz);
	}
	else {
		size_t inbufsiz = (DP(in)->posend - DP(in)->pos);
		if(bufsiz <= inbufsiz) {
			knh_memcpy(buf, DP(in)->ba->bu.ubuf + DP(in)->pos, bufsiz);
			DP(in)->pos += bufsiz;
			{
				DP(in)->stat_size += bufsiz;
			}
			return bufsiz;
		}
		// XXX when both InputStream.read and InputStream.readLine method call,
		// it seams strange. so, move DP(o)->buf's pointer to bufpos.
		knh_memcpy(buf, DP(in)->ba->bu.ubuf + DP(in)->pos, bufsiz);
		DP(in)->pos += inbufsiz;
		DP(in)->stat_size += bufsiz;
		buf += inbufsiz;
		size_t s = in->dpi->freadSPI(ctx, DP(in)->fio, buf+inbufsiz, bufsiz-inbufsiz);
		DP(in)->stat_size += s;
		return s + inbufsiz;
	}
}

/* ------------------------------------------------------------------------ */
//## method void InputStream.close();

static KMETHOD InputStream_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_InputStream_close(ctx, sfp[0].in);
}

/* ------------------------------------------------------------------------ */
//## @Iterative method String InputStream.readLine();

static KMETHOD InputStream_readLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(knh_InputStream_readLine(ctx, sfp[0].in));
}

/* ------------------------------------------------------------------------ */
/* [iterators] */

//static ITRNEXT knh_InputStream_nextLine(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	int ch;
//	knh_Iterator_t *it = sfp[0].it;
//	knh_InputStream_t *in = (knh_InputStream_t*)DP(it)->source;
//	CWB_t cwbbuf;
//	CWB_t *cwb = CWB_open(ctx, &cwbbuf);
//	while((ch = knh_InputStream_getc(ctx, in)) != EOF) {
//		if(ch == 13) continue;
//		if(ch == 10) {
//			//ITRNEXT_(new_String2_cwbconv(ctx, cwb, DP(in)->bconv));
//			ITRNEXT_(CWB_newString(ctx, cwb, K_SPOLICY_POOLNEVER));
//		}
//		knh_Bytes_putc(ctx, cwb->ba, ch);
//	}
//	if(CWB_size(cwb) != 0) {
//		ITRNEXT_(CWB_newString(ctx, cwb, K_SPOLICY_POOLNEVER));
//	}
//	ITREND_();
//}
////
////static int readbuf(CTX ctx, knh_InputStream_t *in, char *buf, knh_nitr_t *m)
////{
////	long ssize = in->dpi->freadSPI(ctx, DP(in)->fio, buf, K_PAGESIZE);
////	if(ssize > 0) {
////		m->index = 0;
////		m->max   = ssize;
////		return 1;
////	}
////	knh_InputStream_close(ctx, in);
////	return 0;
////}
////
////static ITRNEXT knh_InputStream_nextLine(CTX ctx, knh_sfp_t *sfp _RIX)
////{
////	knh_Iterator_t *itr = sfp[0].it;
////	knh_InputStream_t *in = (knh_InputStream_t*)DP(itr)->source;
////	const char *buf = (const char*)DP(itr)->m.nptr;
////	knh_nitr_t *m = &(DP(itr)->m);
////	if(!(m->index < m->max) && readbuf(ctx, in, (char*)buf, m) == 0) {
////		ITREND_();
////	}
////	int prev = 0, policy = K_SPOLICY_ASCII;
////	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
////	while(1) {
////		size_t i, pos = m->index, posend = m->max;
////		for(i = pos; i < posend; i++) {
////			int ch = buf[i];
////			if(ch == '\n') {
////				knh_Bytes_write2(ctx, cwb->ba, buf + pos, i - pos);
////				m->index = i + 1;
////				goto L_TOSTRING;
////			}
////			if(ch < 0) policy = K_SPOLICY_UTF8;
////			prev = ch;
////		}
////		knh_Bytes_write2(ctx, cwb->ba, buf + pos, posend - pos);
////		if(readbuf(ctx, in, (char*)buf, m) == 0) {
////			goto L_TOSTRING;
////		}
////	}
////	L_TOSTRING:;
////	knh_String_t *s;
////	if(prev == '\r') {
////		knh_Bytes_reduce(cwb->ba, 1);
////	}
////	if(in->decNULL == NULL || policy == K_SPOLICY_ASCII) {
////		s = CWB_newString(ctx, cwb, K_SPOLICY_POOLNEVER|policy);
////	}
////	else {
////		s = CWB_newStringDECODE(ctx, cwb, in->decNULL);
////	}
////	ITRNEXT_(s);
////}
//

static ITRNEXT InputStream_nextLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Iterator_t *itr = sfp[0].it;
	knh_InputStream_t *in = (knh_InputStream_t*)DP(itr)->source;
	knh_String_t *line = knh_InputStream_readLine(ctx, in);
	if(IS_NULL(line)) {
		ITREND_();
	}
	ITRNEXT_(line);
}

/* ------------------------------------------------------------------------ */
//## @Final mapper InputStream String..;
//## method String.. InputStream.opITR();

static TYPEMAP InputStream_String__(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Iterator_t *itr = new_IteratorG(ctx, CLASS_StringITR, sfp[0].o, InputStream_nextLine);
	RETURN_(itr);
}

/* ------------------------------------------------------------------------ */
//## @Final mapper Path String..;
//## method String.. Path.opITR();

static TYPEMAP Path_String__(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *path = (knh_Path_t*)sfp[K_TMRIDX].o;
	knh_Iterator_t *itr;
	if(path->ospath != NULL && knh_isdir(ctx, path->ospath)) {
		itr = new_ArrayIterator(ctx, knh_PathDir_toArray(ctx, path));
	}
	else {
		knh_InputStream_t *in = new_InputStreamNULL(ctx, path, "r");
		if(in == NULL) in = KNH_TNULL(InputStream);
		itr = new_IteratorG(ctx, CLASS_StringITR, (Object*)in, InputStream_nextLine);
	}
	RETURN_(itr);
}

/* ------------------------------------------------------------------------ */
/* [OutputStream] */

//## @Throwable method OutputStream OutputStream.new(Path path, String mode, Map _);

static KMETHOD OutputStream_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_Path_t *pth = sfp[1].pth;
	const char *mode = IS_NULL(sfp[2].s) ? "w" : S_totext(sfp[2].s);
	w->dpi = pth->dpi;
	DP(w)->fio = w->dpi->fopenSPI(ctx, pth, mode, knh_toDictMap(ctx, sfp[3].m, 0/*isCeation*/));
	KNH_SETv(ctx, DP(w)->path, pth);
	if(DP(w)->fio == IO_NULL) {
		knh_Object_toNULL(ctx, w);
		w->dpi = knh_getDefaultStreamDPI();
	}
	RETURN_(w);
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.write(Bytes buf, Int offset, Int length);

static KMETHOD OutputStream_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t t = BA_tobytes(sfp[1].ba);
	size_t offset = (sfp[2].ivalue == 0) ? 0 : knh_array_index(ctx, sfp, Int_to(knh_int_t, sfp[2]), t.len);
	size_t len = (sfp[3].ivalue == 0) ? (t.len - offset) : Int_to(size_t, sfp[3]);
	if(offset + len > t.len) len = t.len - offset;
	t.utext = &(t.utext[offset]);
	t.len = len;
	knh_OutputStream_write(ctx, sfp[0].w, t);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.print(Object value, ...);

static KMETHOD OutputStream_print(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_sfp_t *v = sfp + 1;
	size_t i, ac = knh_stack_argc(ctx, v);
	for(i = 0; i < ac; i++) {
		knh_write_Object(ctx, w, v[i].o, FMT_s);
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.println(dynamic value, ...);

static KMETHOD OutputStream_println(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_sfp_t *v = sfp + 1;
	size_t i, ac = knh_stack_argc(ctx, v);
	for(i = 0; i < ac; i++) {
		knh_write_Object(ctx, w, v[i].o, FMT_s);
	}
	knh_write_EOL(ctx, w);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## @Hidden method void OutputStream.send(String s, ...);

static KMETHOD OutputStream_send(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_sfp_t *v = sfp + 1;
	size_t i, ac = knh_stack_argc(ctx, v);
	for(i = 0; i < ac; i++) {
		knh_String_t *s = v[i].s;
		if(s == TS_EOL) {
			knh_write_EOL(ctx, w);
		}
		else {
			knh_write_utf8(ctx, w, S_tobytes(s), !String_isASCII(s));
		}
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.flush();

static KMETHOD OutputStream_flush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_flush(ctx, sfp[0].w, 0);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.close();

static KMETHOD OutputStream_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_close(ctx, sfp[0].w);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
/* [format] */

static const char *newfmt(char *buf, size_t bufsiz, knh_bytes_t fmt, const char *t)
{
	char *p = buf + (fmt.len - 1);
	strncpy(buf, fmt.text, bufsiz);
	strncpy(p, t, bufsiz - fmt.len);
	DBG_P("FMT='%s'", buf);
	return (const char*)buf;
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Const method String Int.format(String fmt);

static KMETHOD Int_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_sfp_t *arg = ctx->esp - 1;
	DBG_ASSERT(arg == sfp+1);
	knh_bytes_t fmt = S_tobytes(arg[0].s);
	L_RETRY:;
	int ch = fmt.utext[fmt.len - 1];
	if(fmt.utext[0] == '%' && (ch == 'u' || ch == 'd' || ch == 'x')) {
		char fmtbuf[40], buf[80];
		const char *ifmt = (ch == 'd') ? K_INT_FMT : ((ch == 'x') ? K_INT_XFMT : K_UINT_FMT);
		knh_snprintf(buf, sizeof(buf), newfmt(fmtbuf, sizeof(fmtbuf), fmt, ifmt + 1), sfp[0].ivalue);
		RETURN_(new_String2(ctx, CLASS_String, buf, knh_strlen(buf), _ALWAYS|_ASCII));
	}
	if(fmt.len != 0) {
		knh_ldata_t ldata[] = {LOG_msg("invalid format"), LOG_s("format", fmt.text), LOG_END};
		KNH_NTRACE(ctx, "konoha:format", K_FAILED, ldata);
	}
	fmt = STEXT("%d");
	goto L_RETRY;
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Const method String Float.format(String fmt);

static KMETHOD Float_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_sfp_t *arg = ctx->esp - 1;
	DBG_ASSERT(arg == sfp+1);
	knh_bytes_t fmt = S_tobytes(arg[0].s);
	L_RETRY:;
	int ch = fmt.utext[fmt.len - 1];
	if(fmt.utext[0] == '%' && (ch == 'f' || ch == 'e')) {
		char fmtbuf[40], buf[80];
		const char *ifmt = (ch == 'f') ? K_FLOAT_FMT : K_FLOAT_FMTE;
		knh_snprintf(buf, sizeof(buf), newfmt(fmtbuf, sizeof(fmtbuf), fmt, ifmt + strlen(ifmt)-1), sfp[0].fvalue);
		RETURN_(new_String2(ctx, CLASS_String, buf, knh_strlen(buf), _ALWAYS|_ASCII));
	}
	if(fmt.len != 0) {
		knh_ldata_t ldata[] = {LOG_msg("invalid format"), LOG_s("format", fmt.text), LOG_END};
		KNH_NTRACE(ctx, "konoha:format", K_FAILED, ldata);
	}
	fmt = STEXT("%f");
	goto L_RETRY;
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Const method String String.format(String fmt);

static KMETHOD String_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_sfp_t *arg = ctx->esp - 1;
	DBG_ASSERT(arg == sfp+1);
	knh_bytes_t fmt = S_tobytes(arg[0].s);
	if(fmt.utext[0] == '%' && fmt.utext[fmt.len-1] == 's') {
		char buf[256];
		knh_snprintf(buf, sizeof(buf), fmt.text, S_totext(sfp[0].s));
		RETURN_(new_String2(ctx, CLASS_String, buf, knh_strlen(buf), _ALWAYS|_ASCII));
	}
	if(fmt.len != 0) {
		knh_ldata_t ldata[] = {LOG_msg("invalid format"), LOG_s("format", fmt.text), LOG_END};
		KNH_NTRACE(ctx, "konoha:format", K_FAILED, ldata);
	}
	RETURN_(sfp[0].s);
}

/* ------------------------------------------------------------------------ */

static knh_bool_t knh_NameSpace_addLinkObject(CTX ctx, knh_NameSpace_t *ns, knh_String_t *name, knh_Object_t *o, int typeCheck)
{
	if(DP(ns)->linkDictMapNULL == NULL) {
		KNH_INITv(DP(ns)->linkDictMapNULL, new_DictMap0(ctx, 0, 1/*isCaseMap*/, "linkDictMap"));
	}
	if(typeCheck) {

	}
	knh_DictMap_set(ctx, DP(ns)->linkDictMapNULL, name, o);
	return 1;
}

static Object *knh_NameSpace_getLinkObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	while(ns != NULL) {
		if(DP(ns)->linkDictMapNULL != NULL) {
			knh_Object_t *o = knh_DictMap_getNULL(ctx, DP(ns)->linkDictMapNULL, path);
			if(o != NULL) return o;
		}
		ns = ns->parentNULL;
	}
	return NULL;
}

void knh_DataMap_log(CTX ctx, knh_DictMap_t *conf, knh_type_t type, const char *key)
{
	if(conf->uline != 0) {
		knh_uri_t uri = ULINE_uri(conf->uline);
		knh_uintptr_t line = ULINE_line(conf->uline);
		knh_logprintf("CONFIG", 1, "(%s:%ld) key='%s' must have type %s", FILENAME__(uri), line, key, TYPE__(type));
	}
	else {
		knh_logprintf("CONFIG", 1, "key='%s' must have type %s", key, TYPE__(type));
	}
}

knh_bool_t knh_DataMap_check(CTX ctx, knh_DictMap_t *conf, knh_type_t type, const char *key, const char *key2)
{
	knh_bytes_t t = {{key}, knh_strlen(key)};
	knh_Object_t *v = knh_DictMap_getNULL(ctx, conf, t);
	if(v == NULL) {
		if(key2 != NULL) {
			t.text = key2;
			t.len = knh_strlen(key2);
			v = knh_DictMap_getNULL(ctx, conf, t);
			if(v == NULL) {
				knh_DataMap_log(ctx, conf, type, key);
				return 0;
			}
			key = key2;
		}
	}
	if(O_cid(v) == type) return 1;
	knh_DataMap_log(ctx, conf, type, key);
	return 0;
}

knh_String_t *knh_DataMap_getString(CTX ctx, knh_DictMap_t *conf, const char *key, const char *key2, knh_String_t *def)
{
	knh_bytes_t t = {{key}, knh_strlen(key)};
	knh_String_t *v = (knh_String_t*)knh_DictMap_getNULL(ctx, conf, t);
	if(v == NULL) {
		if(key2 != NULL) {
			t.text = key2;
			t.len = knh_strlen(key2);
			v = (knh_String_t*)knh_DictMap_getNULL(ctx, conf, t);
		}
		if(v == NULL) {
			v = def;
		}
	}
	if(!IS_bString(v)) {
		v = def;
	}
	return def;
}

knh_String_t *knh_View_getQuery(CTX ctx, knh_View_t *view)
{
	return knh_DataMap_getString(ctx, view->conf, "query", NULL, TS_EMPTY);
}

static void THROW_Undefined(CTX ctx, knh_sfp_t *sfp, const char *whatis, const char *what)
{
//	knh_ldata_t ldata[] = {LOG_s("driver", what), LOG_END};
//	KNH_NTHROW("Undefined", "Script!!");
}

/* ------------------------------------------------------------------------ */
//## @Static method void View.addView(String name, NameSpace _, Map _);

static KMETHOD View_addView(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bool_t tf = 0;
	knh_DictMap_t *conf = knh_toDictMap(ctx, sfp[3].m, 1/*isCreation*/);
	KNH_SETv(ctx, sfp[3].o, conf);
	tf = knh_DataMap_check(ctx, conf, TYPE_Path, "path", NULL);
	tf &= knh_DataMap_check(ctx, conf, TYPE_String, "query", NULL);
	if(tf == 1) {
		knh_Path_t *path = (knh_Path_t*)knh_DictMap_getNULL(ctx, conf, STEXT("path"));
		knh_String_t *dtype = knh_DataMap_getString(ctx, conf, "type", "driver", NULL);
		if(dtype != NULL) {
			const knh_StreamDPI_t *dpi = knh_NameSpace_getStreamDPINULL(ctx, sfp[2].ns, S_tobytes(dtype));
			if(dpi != NULL) {
				path->dpi = dpi;
			}
			else {
				THROW_Undefined(ctx, sfp, "driver", S_totext(dtype));
			}
		}
//		if(!dpi->existsSPI(ctx, path)) {
//			THROW_NotFound(ctx, sfp, "path", S_totext(path->urn));
//		}
		knh_View_t *view = new_(View);
		KNH_SETv(ctx, view->conf, conf);
		KNH_SETv(ctx, view->path, path);
		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
		knh_Bytes_write(ctx, cwb->ba, STEXT("view:"));
		knh_Bytes_write(ctx, cwb->ba, S_tobytes(sfp[1].s));
		tf = knh_NameSpace_addLinkObject(ctx, sfp[2].ns, CWB_newString(ctx, cwb, K_SPOLICY_POOLALWAYS), UPCAST(view), 0);
		CWB_close(cwb);
	}
	RETURNb_(tf);
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Static @Const method View View.opLINK(String path, NameSpace _);

static KMETHOD View_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Object *o = knh_NameSpace_getLinkObjectNULL(ctx, sfp[2].ns, S_tobytes(sfp[1].s));
	if(o != NULL) {
		RETURN_(o);
	}
	RETURN_(KNH_TNULL(View));
}

/* ------------------------------------------------------------------------ */
//## @Hidden method DataITR View.opITR();

static KMETHOD View_opITR(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_View_t *view = sfp[0].rel;
	knh_Path_t *path = view->path;
	knh_Fitrnext fnext = NULL;
	if(!IS_NULL(path)) {
		fnext = path->dpi->qnextData;
	}
	RETURN_(new_IteratorG(ctx, CLASS_DataITR, UPCAST(view), fnext));
}

/* ------------------------------------------------------------------------ */
//## @Static method InputStream System.getIn();

static KMETHOD System_getIn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(ctx->share->in);
}

/* ------------------------------------------------------------------------ */
//## @Static method OutputStream System.getOut();

static KMETHOD System_getOut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(ctx->share->out);
}

/* ------------------------------------------------------------------------ */
//## @Static method OutputStream System.getErr();

static KMETHOD System_getErr(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(ctx->share->err);
}

/* ------------------------------------------------------------------------ */
//## @Static method dynamic System.getProperty(String key);

static KMETHOD System_getProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *v = (knh_Object_t*)knh_getPropertyNULL(ctx, S_tobytes(sfp[1].s));
	if(v == NULL) {
		v = KNH_NULVAL(CLASS_String);
		knh_setProperty(ctx, sfp[1].s, v);
	}
	sfp[K_RIX].ndata = O_ndata(v);
	RETURN_(v);
}

/* ------------------------------------------------------------------------ */
//## @Static method dynamic System.setProperty(String key, dynamic value);

static KMETHOD System_setProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_setProperty(ctx, sfp[1].s, sfp[2].o);
	sfp[K_RIX].ndata = O_ndata(sfp[2].o);
	RETURN_(sfp[2].o);
}

/* ------------------------------------------------------------------------ */

static knh_bool_t bytes_matchWildCard(knh_bytes_t t, knh_bytes_t p)
{
	if(p.utext[0] == '*') {
		p.utext = p.utext + 1;
		p.len = p.len - 1;
		return knh_bytes_endsWith(t, p);
	}
	else if(p.utext[p.len-1] == '*') {
		p.len -= 1;
		return knh_bytes_startsWith(t, p);
	}
	else {
		knh_index_t idx = knh_bytes_index(p, '*');
		if(idx == -1) {
			return knh_bytes_startsWith(t, p);
		}
		else {
			return knh_bytes_startsWith(t, knh_bytes_first(p, idx)) &&
				knh_bytes_endsWith(t, knh_bytes_last(p, idx+1));
		}
	}
}

/* ------------------------------------------------------------------------ */
//## @Hidden method String[] System.listProperties(String key);

static KMETHOD System_listProperties(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = new_Array(ctx, CLASS_String, 0);
	knh_bytes_t prefix = IS_NULL(sfp[1].s) ? STEXT("") : S_tobytes(sfp[1].s);
	knh_DictMap_t *map = ctx->share->props;
	size_t i;
	for(i = 0; i < knh_Map_size(map); i++) {
		knh_String_t *key = knh_DictMap_keyAt(map, i);
		if(bytes_matchWildCard(S_tobytes(key), prefix)) {
			knh_Array_add(ctx, a, key);
		}
	}
	RETURN_(a);
}

/* ------------------------------------------------------------------------ */
//## @Static method void System.gc();

static KMETHOD System_gc(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_System_gc(ctx, 0/*needsStackTrace*/);
}

/* ------------------------------------------------------------------------ */
//## method Int System.getTime();

static KMETHOD System_getTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_getTimeMilliSecond());
}

/* ------------------------------------------------------------------------ */
//## @Restricted method void System.exit(Int status);

static KMETHOD System_exit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int status = IS_NULL(sfp[1].o) ? 0 : Int_to(size_t, sfp[1]);
	knh_ldata_t ldata[] = {LOG_i("user_specified_status", status)};
	KNH_NTRACE(ctx, "exit", K_NOTICE, ldata);
	exit(status);
}

///* ------------------------------------------------------------------------ */
////## @Static method InputStream Context.setIn(InputStream? in);
//
//static KMETHOD CTX_setIn(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	KNH_SETv(ctx, ((knh_context_t*)ctx)->in, sfp[1].o);
//	RETURN_(sfp[1].o);
//}
//
///* ------------------------------------------------------------------------ */
////## @Static method OutputStream Context.setOut(OutputStream? out);
//
//static KMETHOD CTX_setOut(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	KNH_SETv(ctx, ((knh_context_t*)ctx)->out, sfp[1].o);
//	RETURN_(sfp[1].o);
//}
//
///* ------------------------------------------------------------------------ */
////## @Static method OutputStream Context.setErr(OutputStream? out);
//
//static KMETHOD CTX_setErr(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	KNH_SETv(ctx, ((knh_context_t*)ctx)->err, sfp[1].o);
//	RETURN_(sfp[1].o);
//}

/* ------------------------------------------------------------------------ */
//## method Boolean Exception.opOF(String event);

static KMETHOD Exception_opOF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_event_t eid = knh_geteid(ctx, S_tobytes(sfp[1].s));
	knh_event_t eid0 = knh_geteid(ctx, S_tobytes((sfp[0].e)->emsg));
	int isa = event_isa(ctx, eid0, eid);
	RETURNb_(isa);
}

/* ------------------------------------------------------------------------ */
//## @Static @Restricted method String System.exec(String cmd);

static KMETHOD System_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
#ifdef K_DEOS_TRACE
	char cmd[1024];
	knh_snprintf(cmd, sizeof(cmd), "%s=%s %s", K_DEOS_TRACE, ctx->trace, S_totext(sfp[1].s));
#else
	const char *cmd = S_totext(sfp[1].s);
#endif
	//NOTE_(ctx, "fork command='%s'", cmd);
#ifdef K_USING_POSIX_
	FILE *fp = popen((const char*)cmd, "r+");
	if(fp != NULL) {
		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
		char buf[K_PAGESIZE];
		while(1) {
			size_t size = fread(buf, 1, sizeof(buf), fp);
			if(size > 0) {
				knh_bytes_t t = {{buf}, size};
				knh_Bytes_write(ctx, cwb->ba, t);
			}
			else {
				break;
			}
		};
		pclose(fp);
		RETURN_(CWB_newString(ctx, cwb, K_SPOLICY_POOLNEVER));
	}
	else {
		KNH_LOG("command failed: %s", cmd);
	}
#endif
	RETURN_(KNH_NULVAL(CLASS_String));
}

/* ------------------------------------------------------------------------ */
//## @Restricted method Tvar System.eval(String cmd, Script _, NameSpace _, Class _);

static KMETHOD System_eval(CTX ctx, knh_sfp_t *sfp _RIX)
{
//	fprintf(stderr, "TESTING: '%s'\n", 	S_totext(sfp[1].s));
//	fprintf(stderr, "RETURN VALUE: '%s'\n", CLASS__(sfp[4].c->cid));
	knh_Script_t *scr = ctx->gma->scr;
	knh_NameSpace_t *ns = K_GMANS;
	if(scr != sfp[2].scr) {
		KNH_SETv(ctx, ctx->gma->scr, sfp[2].scr);
		sfp[2].scr = scr;
	}
	if(ns != sfp[3].ns) {
		KNH_SETv(ctx, K_GMANS, sfp[3].ns);
		sfp[3].ns = ns;
	}
	KNH_SETv(ctx, ((knh_context_t*)ctx)->evaled, KNH_NULL);
	KNH_SETv(ctx, ((knh_context_t*)ctx)->e, KNH_NULL);
	knh_InputStream_t *bin = new_StringInputStream(ctx, sfp[1].s);
	knh_class_t tcid = sfp[4].c->cid;
	knh_beval(ctx, bin);
	scr = ctx->gma->scr;
	ns = K_GMANS;
	if(scr != sfp[2].scr) {
		KNH_SETv(ctx, ctx->gma->scr, sfp[2].scr);
		sfp[2].scr = scr;
	}
	if(ns != sfp[3].ns) {
		KNH_SETv(ctx, K_GMANS, sfp[3].ns);
		sfp[3].ns = ns;
	}
	if(ctx->isEvaled == 1) {
		knh_Object_t *v = ctx->evaled;
		WCTX(ctx)->isEvaled = 0;
		if(tcid == CLASS_Tvoid) return;
		if(v != KNH_NULL && ClassTBL_isa(O_cTBL(v), tcid)) {
			if(IS_Tunbox(tcid)) {
				RETURNi_(N_toint(v));
			}
			else {
				RETURN_(v);
			}
		}
	}
	sfp[K_RIX].ndata = 0;
	RETURN_(KNH_NULVAL(tcid));
}

/* ------------------------------------------------------------------------ */
//## method String System.readLine(String cmd)

static KMETHOD System_readLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const char *line = ctx->spi->readline(S_totext(sfp[1].s));
	knh_String_t *s = new_String(ctx, line);
	free((void*)line);
	RETURN_(s);
}

#endif/*K_INCLUDE_BUILTINAPI*/

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
