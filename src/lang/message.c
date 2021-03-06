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

#include"commons.h"

#ifdef __cplusplus 
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [tokenizer] */

/* error */
#define KC_ERR       LOG_ERR
#define KC_TERROR    LOG_ERR
/* warning */
#define KC_EWARN     LOG_WARNING
#define KC_DWARN     LOG_WARNING
/* info */
#define KC_BAD       LOG_NOTICE
#define KC_NOTICE    LOG_NOTICE
#define KC_TINFO     LOG_INFO
#define KC_INFO      LOG_INFO
#define KC_DEBUG     LOG_DEBUG

/* ------------------------------------------------------------------------ */
/* @data */

static const char* KC__(int p)
{
	switch(p) {
	case LOG_EMERG:
	case LOG_ALERT:
	case LOG_CRIT:
	case LOG_ERR:  return "(error) ";
	case LOG_WARNING: return "(warning) ";
	case LOG_NOTICE:  return "(bad manner) ";
	case LOG_INFO:    return "(info) ";
	case LOG_DEBUG:   return "(debug) ";
	}
	return "(debug) ";
}

#ifdef K_USING_POSIX_
#define CTX_isTERM(ctx)  CTX_isInteractive(ctx)
#else
#define CTX_isTERM(ctx)  0
#endif

const char* TERM_BBOLD(CTX ctx)
{
	return CTX_isTERM(ctx) ? "\x1b[1m" : "";
}

const char* TERM_EBOLD(CTX ctx)
{
	return CTX_isTERM(ctx) ? "\x1b[0m" : "";
}

const char* TERM_BNOTE(CTX ctx, int pe)
{
	if(CTX_isTERM(ctx)) {
		if(pe <= LOG_ERR) {
			return "\x1b[1m\x1b[31m";
		}
		else if(pe == LOG_WARNING) {
			return "\x1b[1m\x1b[35m";
		}
		return "\x1b[1m\x1b[34m";
	}
	return "";
}

const char* TERM_ENOTE(CTX ctx, int pe)
{
	return CTX_isTERM(ctx) ? "\x1b[0m" : "";
}

static kString *GammaBuilder_vperror(CTX ctx, int pe, const char *fmt, va_list ap)
{
	kString *msg = TS_EMPTY;
	int isPRINT = (pe <= KC_DWARN) ? 1 : 0;
	if(pe != KC_DEBUG && (CTX_isInteractive(ctx) || knh_isCompileOnly(ctx))) {
		isPRINT = 1;
	}
	if(GammaBuilder_isQuiet(ctx->gma) || ctx->gma->uline == 0) {
		isPRINT = 0;
	}
	if(isPRINT == 1) {
		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
		knh_write_uline(ctx, cwb->w, ctx->gma->uline);
		knh_write_ascii(ctx, cwb->w, KC__(pe));
		knh_vprintf(ctx, cwb->w, fmt, ap);
		msg = CWB_newString(ctx, cwb, SPOL_POOLNEVER);
		knh_Array_add(ctx, DP(ctx->gma)->errmsgs, msg);
		fprintf(stderr, "%s - %s%s\n", TERM_BNOTE(ctx, pe), S_totext(msg), TERM_ENOTE(ctx, pe));
		knh_logprintf("konoha", 0, S_totext(msg));
	}
	return msg;
}

static kTerm *GammaBuilder_perror(CTX ctx, int pe, const char *fmt, ...)
{
	kString *msg;
	va_list ap;
	va_start(ap, fmt);
	msg = GammaBuilder_vperror(ctx, pe, fmt, ap);
	va_end(ap);
	if(pe < KC_DWARN) {
		kTerm *tkERR = new_(Term);
		tkERR->tt = TT_ERR;
		tkERR->uline = (ctx->gma)->uline;
		KNH_SETv(ctx, (tkERR)->data, msg);
		return tkERR;
	}
	return NULL;
}

static kTerm *kTermoERR(CTX ctx, kTerm *tk, const char *fmt, ...)
{
	if(TT_(tk) != TT_ERR) {
		kString *msg;
		va_list ap;
		va_start(ap, fmt);
		ctx->gma->uline = tk->uline;
		msg = GammaBuilder_vperror(ctx, KC_ERR, fmt, ap);
		va_end(ap);
		TT_(tk) = TT_ERR;
		KNH_SETv(ctx, (tk)->data, msg);
	}
	return tk;
}

/* ------------------------------------------------------------------------ */
/* script */

kTerm* ERROR_NotFound(CTX ctx, const char *whatis, const char *t)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("%s not found: %s"), whatis, t);
}
void WARN_NotFound(CTX ctx, const char *whatis, const char *t)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("%s not found: %s"), whatis, t);
}
kTerm* ERROR_Incompatible(CTX ctx, const char *whatis, const char *name)
{
	return GammaBuilder_perror(ctx, KC_ERR, "incompatible %s: %s", whatis, name);
}
kTerm* ERROR_SingleParam(CTX ctx)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("syntax error: always takes only one parameter"));
}
//kTerm* ErrorExtendingFinalClass(CTX ctx, kclass_t cid)
//{
//	return GammaBuilder_perror(ctx, KC_ERR, _("cannot extends final class %C"), cid);
//}
void WARN_MuchBetter(CTX ctx, const char *token, const char *token2)
{
	if(token2 != NULL) {
		GammaBuilder_perror(ctx, KC_DWARN, _("%s is better than %s"), token, token2);
	}
	else {
		GammaBuilder_perror(ctx, KC_DWARN, _("%s is better"), token);
	}
}
void WarningMethodName(CTX ctx, const char *name)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("%s should starts with lowercase"), name);
}

void WARN_MustCloseWith(CTX ctx, int ch)
{
	char buf[40];
	knh_snprintf(buf, sizeof(buf), "%c", ch);
	GammaBuilder_perror(ctx, KC_DWARN, "must close with %s", buf);
}

void WARN_Semicolon(CTX ctx)
{
	if(!CTX_isInteractive(ctx)) GammaBuilder_perror(ctx, KC_BAD, "needs ");
}
void WARN_UnxpectedMultiByteChar(CTX ctx, const char *ch)
{
	if(ch == NULL) ch = "???";
	GammaBuilder_perror(ctx, KC_DWARN, _("unexpected multi-byte character: '%s'"), ch);
}
kTerm *ErrorHazardousStatement(CTX ctx)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("hazardous statement"));
}
void WarningNoEffect(CTX ctx)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("no effect"));
}
kTerm* ErrorMisplaced(CTX ctx)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("misplaced"));
}
//kTerm* ErrorStaticType(CTX ctx, const char *msg)
//{
//	kTerm* tkERR = GammaBuilder_perror(ctx, KC_ERR, _("%s is not dynamic"), msg);
//	DBG_ABORT("stop why?");
//	return tkERR;
//}
kTerm* ERROR_UnableToAdd(CTX ctx, kclass_t cid, const char *whatis)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("%T is unable to add new %s"), cid, whatis);
}
kTerm* ERROR_Block(CTX ctx, const char* block)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("syntax error: wrong %s"), block);
}
kTerm* ERROR_WrongFFILink(CTX ctx, const char* link)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("syntax error: ffi link: %s"), link);
}
kTerm* ERROR_text(CTX ctx, const char *keyword K_TRACEARGV)
{
	kTerm *tk = GammaBuilder_perror(ctx, KC_ERR, ("syntax error: %s"), keyword);
	KNH_HINT(ctx, keyword);
	DBG_ABORT("why?");
	return tk;
}
kTerm* ERROR_Term(CTX ctx, kTerm *tk K_TRACEARGV)
{
	if(TT_(tk) != TT_ERR) {
		tk = ERROR_text(ctx, IS_String((tk)->text) ? S_totext((tk)->text) : Term__(tk) K_TRACEDATA);
	}
	return tk;
}
kTerm* ERROR_Stmt(CTX ctx, kStmtExpr *stmt K_TRACEARGV)
{
	DBG_ASSERT(STT_(stmt) != STT_ERR);
	return ERROR_text(ctx, TT__(stmt->stt) K_TRACEDATA);
}
kTerm* ERROR_TermIsNot(CTX ctx, kTerm *tk, const char* whatis)
{
	return GammaBuilder_perror(ctx, KC_ERR, ("%O is not %s"), tk, whatis);
}
kTerm* ERROR_TermIs(CTX ctx, kTerm *tk, const char* whatis)
{
	return GammaBuilder_perror(ctx, KC_ERR, ("%O is not %s"), tk, whatis);
}
kTerm* ERROR_Required(CTX ctx, kTerm *tk, const char *stmtexpr, const char *token)
{
	return kTermoERR(ctx, tk, _("%s? needs %s"), stmtexpr, token);
}
void WarningNotInitialized(CTX ctx, kTerm *tk, const char *tool)
{
	GammaBuilder_perror(ctx, KC_EWARN, _("%s is not installed"), tool);
}
kTerm* ERROR_RegexCompilation(CTX ctx, kTerm *tk, const char *regname, const char *regdata)
{
	return kTermoERR(ctx, tk, _("%s compile error: %s"), regname, regdata);
}
kTerm* ERROR_Undefined(CTX ctx, const char *whatis, kclass_t cid, kTerm *tk)
{
	if(cid != CLASS_unknown) {
		return kTermoERR(ctx, tk, _("undefined %s: %T.%O"), whatis, cid, tk);
	}
	else {
		return kTermoERR(ctx, tk, _("undefined %s: %O"), whatis, tk);
	}
}
kTerm* ERROR_UndefinedName(CTX ctx, kTerm *tk)
{
	return kTermoERR(ctx, tk, _("undefined name: %O"), tk);
}
void WARN_Undefined(CTX ctx, const char *whatis, kclass_t cid, kTerm *tk)
{
	if(cid != CLASS_unknown) {
		GammaBuilder_perror(ctx, KC_EWARN, _("undefined %s: %T.%O"), whatis, cid, tk);
	}
	else {
		GammaBuilder_perror(ctx, KC_EWARN, _("undefined %s: %O"), whatis, tk);
	}
}
kTerm* ERROR_AlreadyDefined(CTX ctx, const char *whatis, Object *o)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("already defined %s: %O"), whatis, o);
}
void WARN_AlreadyDefined(CTX ctx, const char *whatis, Object *o)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("already defined %s: %O"), whatis, o);
}
void WARN_AlreadyDefinedClass(CTX ctx, kclass_t cid, kclass_t oldcid)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("%C is already defined: %C"), cid, oldcid);
}
kTerm* ERROR_Denied(CTX ctx, const char *why, kTerm *tk)
{
	return kTermoERR(ctx, tk, _("%s: %O"), why, tk);
}
void WarningUnknownClass(CTX ctx, kTerm *tk, kclass_t defc)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("unknown class: %L ==> %T"), tk, defc);
}
kTerm* ERROR_UnableToAssign(CTX ctx, kTerm *tk)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("unable to make assignment"));
}
kTerm* ErrorUnsupportedConstructor(CTX ctx, kclass_t mtd_cid)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("the constructor of %T is not supported"), mtd_cid);
}
kTerm* ERROR_UndefinedBehavior(CTX ctx, const char *token)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("undefined behavior: %s"), token);
}
kTerm* ERROR_CompilerControlledParameter(CTX ctx, kclass_t mtd_cid, kmethodn_t mn, int n)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("compiler controlled parameter: %C.%M(#%d)"), mtd_cid, mn, n);
}

kTerm* ERROR_RequiredParameter(CTX ctx)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("needs a parameter to infer its type"));
}
void WARN_WrongTypeParam(CTX ctx, kclass_t cid)
{
	if(cid != CLASS_unknown) {
		kbytes_t bname = C_bname(cid);
		GammaBuilder_perror(ctx, KC_DWARN, "%B<>: wrong type parameter", bname);
	}
}
void INFO_Typing(CTX ctx, const char *prefix, kbytes_t name, ktype_t type)
{
	GammaBuilder_perror(ctx, KC_TINFO, "suppose %s%B has %T type", prefix, name, type);
}
void WARN_Overflow(CTX ctx, const char *floatorint, kbytes_t t)
{
	GammaBuilder_perror(ctx, KC_EWARN, _("%s overflow: %B"), floatorint, t);
}
void WARN_Unused(CTX ctx, kTerm *tk, ksymbol_t fn)
{
	kline_t uline = ctx->gma->uline;
	ctx->gma->uline = tk->uline;
	GammaBuilder_perror(ctx, KC_DWARN, _("unused %N"), fn);
	ctx->gma->uline = uline;
}
kTerm* ERROR_AlreadyDefinedType(CTX ctx, ksymbol_t fn, ktype_t type)
{
	return GammaBuilder_perror(ctx, KC_TERROR, _("already defined: previous type %T %N"), type, fn);
}
kTerm* ErrorTooManyVariables(CTX ctx)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("too many variables"));
}
//void WarningTooManyReturnValues(CTX ctx)
//{
//	GammaBuilder_perror(ctx, KC_DWARN, _("too many return values"));
//}
void WARN_UseDefaultValue(CTX ctx, const char *whatis, ktype_t type)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("%s default value of %T"), whatis, type);
}
void WarningNoFmt(CTX ctx, const char *fmt)
{
	GammaBuilder_perror(ctx, KC_DWARN, "no such formatter: '%s'", fmt);
}
void WarningIllegalFormatting(CTX ctx, const char *fmt)
{
	GammaBuilder_perror(ctx, KC_DWARN, "illegal formatting at: `.. %s`", fmt);
}
kTerm* ERROR_MethodIsNot(CTX ctx, kMethod *mtd, const char *how)
{
	if(IS_Method(mtd)) {
		return GammaBuilder_perror(ctx, KC_ERR, _("%C.%M is not %s"), (mtd)->cid, (mtd)->mn, how);
	}
	else {
		return GammaBuilder_perror(ctx, KC_ERR, _("method is not %s"), how);
	}
}
void WARN_MethodIs(CTX ctx, kMethod *mtd, const char *how)
{
	if(IS_Method(mtd)) {
		GammaBuilder_perror(ctx, KC_DWARN, _("%C.%M is %s"), (mtd)->cid, (mtd)->mn, how);
	}
	else {
		GammaBuilder_perror(ctx, KC_DWARN, _("method is %s"), how);
	}
}
kTerm *ERROR_Unsupported(CTX ctx, const char *whatis, kclass_t cid, const char *symbol)
{
	if(symbol == NULL) {
		return GammaBuilder_perror(ctx, KC_ERR, "unsupported %s", whatis);
	}
	else if(cid == CLASS_unknown) {
		return GammaBuilder_perror(ctx, KC_ERR, "unsupported %s: %s", whatis, symbol);
	}
	else {
		return GammaBuilder_perror(ctx, KC_ERR, "unsupported %s: %s in %C", whatis, symbol, cid);
	}
}
void WARN_Unsupported(CTX ctx, const char *msg)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("unsupported %s"), msg);
}
void WARN_Ignored(CTX ctx, const char *whatis, kclass_t cid, const char *symbol)
{
	if(symbol == NULL) {
		GammaBuilder_perror(ctx, KC_DWARN, "ignored %s", whatis, symbol);
	}
	else if(cid == CLASS_unknown) {
		GammaBuilder_perror(ctx, KC_DWARN, "ignored %s: %s", whatis, symbol);
	}
	else {
		GammaBuilder_perror(ctx, KC_DWARN, "ignored %s: %C.%s", whatis, cid, symbol);
	}
}
void WARN_Unnecesary(CTX ctx, kTerm *tk)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("unnecessary %O"), tk);
}
void WarningUnnecessaryOperation(CTX ctx, const char *msg)
{
	GammaBuilder_perror(ctx, KC_DWARN, "unnecessary operation: %s", msg);
}
void WARN_TooMany(CTX ctx, const char *whatis, const char *symbol)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("%s: too many %s, and be ignored."), symbol, whatis);
}
kTerm* ERROR_Needs(CTX ctx, const char *whatis)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("%s is necessary"), whatis);
}
kTerm* ERROR_MustBe(CTX ctx, const char *whatis, const char* token)
{
	if(token == NULL) {
		return GammaBuilder_perror(ctx, KC_ERR, "must be %s", whatis);
	}
	else {
		return GammaBuilder_perror(ctx, KC_ERR, "%s must be %s", token, whatis);
	}
}
kTerm* ERROR_OutOfIndex(CTX ctx, kint_t s, kint_t n, kint_t e)
{
	return GammaBuilder_perror(ctx, KC_ERR, "index must be %i <= %i < %i", s, n, e);
}
void WarningNullable(CTX ctx, kclass_t cid)
{
	GammaBuilder_perror(ctx, KC_DWARN, "%C doesn't take null", cid);
}
kTerm* ErrorComparedDiffrentType(CTX ctx, ktype_t t1, ktype_t t2)
{
	return GammaBuilder_perror(ctx, KC_TERROR, _("comparison of different type: %T %T"), t1, t2);
}
/* type error */
kTerm *TERROR_Term(CTX ctx, kTerm *tk, kclass_t type, kclass_t reqt)
{
	return kTermoERR(ctx, tk, ("%O has type %T, not %T"), tk, reqt, type);
}
kTerm *TypeErrorStmtNN(CTX ctx, kStmtExpr *stmt, int n, ktype_t reqt, ktype_t type)
{
	return GammaBuilder_perror(ctx, KC_TERROR, _("%s(%d) has type %T, not %T"), TT__(SP(stmt)->stt), n, reqt, type);
}
kTerm* TypeErrorCallParam(CTX ctx, int n, kMethod *mtd, kclass_t reqt, kclass_t type)
{
	if(IS_Method(mtd)) {
		return GammaBuilder_perror(ctx, KC_TERROR, _("%C.%M(#%d) has type %T, not %T"), (mtd)->cid, (mtd)->mn, n - 1, reqt, type);
	}
	else {
		KNH_ASSERT(IS_String(mtd));
		const char *fname = S_totext((kString*)mtd);
		return GammaBuilder_perror(ctx, KC_TERROR, _("%s(#d) has type %T, not %T"), fname, n - 1, reqt, type);
	}
}
void WARN_Cast(CTX ctx, const char *whatis, kclass_t tcid, kclass_t scid)
{
	GammaBuilder_perror(ctx, KC_EWARN, _("%s (%T)%T"), whatis, tcid, scid);
}
kTerm* ERROR_ForeachNotIterative(CTX ctx, kclass_t p1, kclass_t type)
{
	if(p1 == CLASS_Tvar) {
		return GammaBuilder_perror(ctx, KC_ERR, "foreach %T is not iterative", type);
	}
	else {
		return GammaBuilder_perror(ctx, KC_ERR, "foreach: %T is not iteration of %T", p1, type);
	}
}
void WarningDuplicatedDefault(CTX ctx)
{
	GammaBuilder_perror(ctx, KC_EWARN, _("multiple default in switch"));
}
void WarningNotConstant(CTX ctx)
{
GammaBuilder_perror(ctx, KC_DWARN, _("case takes a constant value"));
}
void WarningAlwaysFalseAssertion(CTX ctx)
{
GammaBuilder_perror(ctx, KC_EWARN, _("always throw Assertion!!"));
}
void WarningDifferentMethodClass(CTX ctx, kbytes_t name, kclass_t cid)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("different class: %B ==> %C"), name, cid);
}
void WarningDeprecated(CTX ctx, const char *msg)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("depreciated %s"), msg);
}
kTerm* ErrorFinalMethod(CTX ctx, kclass_t cid, kmethodn_t mn)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("%C.%M is final"), cid, mn);
}
kTerm* ErrorDifferentlyDefinedMethod(CTX ctx, kclass_t mtd_cid, kmethodn_t mn)
{
	return GammaBuilder_perror(ctx, KC_TERROR, _("%C.%M must be defined the same"), mtd_cid, mn);
}

/* ------------------------------------------------------------------------ */

kTerm* ERROR_OnlyTopLevel(CTX ctx, const char* stmt)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("available only at the top level: %s"), stmt);
}
kTerm* ErrorUndefinedLabel(CTX ctx, kTerm *tk)
{
	return GammaBuilder_perror(ctx, KC_ERR, _("undefined label: %L"), tk);
}
void WarningAbstractMethod(CTX ctx, kMethod *mtd)
{
	GammaBuilder_perror(ctx, KC_DWARN, "abstract? %C.%M", (mtd)->cid, (mtd)->mn);
}
void WARN_DividedByZero(CTX ctx)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("divided by zero"));
}

void WarningUndefinedFmt(CTX ctx, kclass_t cid, kmethodn_t mn)
{
	GammaBuilder_perror(ctx, KC_DWARN, _("undefined formatter: %M for %C"), mn, cid);
}

void NoticeInliningMethod(CTX ctx, kMethod *mtd)
{
	GammaBuilder_perror(ctx, KC_DEBUG, _("inlining: %C.%M"), (mtd)->cid, (mtd)->mn);
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
