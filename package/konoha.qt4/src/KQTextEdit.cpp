//QTextEdit QTextEdit.new(QWidget parent);
KMETHOD QTextEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQTextEdit *ret_v = new KQTextEdit(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextEdit QTextEdit.new(String text, QWidget parent);
KMETHOD QTextEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQTextEdit *ret_v = new KQTextEdit(text, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QTextEdit.getAcceptRichText();
KMETHOD QTextEdit_getAcceptRichText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->acceptRichText();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QtAlignment QTextEdit.getAlignment();
KMETHOD QTextEdit_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		Qt::Alignment ret_v = qp->alignment();
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTextEdit.anchorAt(QPoint pos);
KMETHOD QTextEdit_anchorAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		QString ret_v = qp->anchorAt(pos);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextEditAutoFormatting QTextEdit.getAutoFormatting();
KMETHOD QTextEdit_getAutoFormatting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QTextEdit::AutoFormatting ret_v = qp->autoFormatting();
		QTextEdit::AutoFormatting *ret_v_ = new QTextEdit::AutoFormatting(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTextEdit.canPaste();
KMETHOD QTextEdit_canPaste(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->canPaste();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QMenu QTextEdit.createStandardContextMenu();
KMETHOD QTextEdit_createStandardContextMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QMenu* ret_v = qp->createStandardContextMenu();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenu*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QMenu QTextEdit.createStandardContextMenu(QPoint position);
KMETHOD QTextEdit_createStandardContextMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		QMenu* ret_v = qp->createStandardContextMenu(position);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenu*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QTextCharFormat QTextEdit.getCurrentCharFormat();
KMETHOD QTextEdit_getCurrentCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QTextCharFormat ret_v = qp->currentCharFormat();
		QTextCharFormat *ret_v_ = new QTextCharFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFont QTextEdit.getCurrentFont();
KMETHOD QTextEdit_getCurrentFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QFont ret_v = qp->currentFont();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCursor QTextEdit.cursorForPosition(QPoint pos);
KMETHOD QTextEdit_cursorForPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		QTextCursor ret_v = qp->cursorForPosition(pos);
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QTextEdit.cursorRect(QTextCursor cursor);
KMETHOD QTextEdit_cursorRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[1]);
		QRect ret_v = qp->cursorRect(cursor);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRect QTextEdit.cursorRect();
KMETHOD QTextEdit_cursorRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->cursorRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QTextEdit.getCursorWidth();
KMETHOD QTextEdit_getCursorWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		int ret_v = qp->cursorWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextDocument QTextEdit.getDocument();
KMETHOD QTextEdit_getDocument(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QTextDocument* ret_v = qp->document();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextDocument*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTextEdit.getDocumentTitle();
KMETHOD QTextEdit_getDocumentTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QString ret_v = qp->documentTitle();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextEdit.ensureCursorVisible();
KMETHOD QTextEdit_ensureCursorVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		qp->ensureCursorVisible();
	}
	RETURNvoid_();
}

//boolean QTextEdit.find(String exp, int options);
KMETHOD QTextEdit_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QString exp = String_to(const QString, sfp[1]);
		QTextDocument::FindFlags options = Int_to(QTextDocument::FindFlags, sfp[2]);
		bool ret_v = qp->find(exp, options);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QTextEdit.getFontFamily();
KMETHOD QTextEdit_getFontFamily(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QString ret_v = qp->fontFamily();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTextEdit.getFontItalic();
KMETHOD QTextEdit_getFontItalic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->fontItalic();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QTextEdit.getFontPointSize();
KMETHOD QTextEdit_getFontPointSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->fontPointSize();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QTextEdit.getFontUnderline();
KMETHOD QTextEdit_getFontUnderline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->fontUnderline();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTextEdit.getFontWeight();
KMETHOD QTextEdit_getFontWeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		int ret_v = qp->fontWeight();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTextEdit.isReadOnly();
KMETHOD QTextEdit_isReadOnly(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isReadOnly();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextEdit.isUndoRedoEnabled();
KMETHOD QTextEdit_isUndoRedoEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isUndoRedoEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTextEdit.getLineWrapColumnOrWidth();
KMETHOD QTextEdit_getLineWrapColumnOrWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		int ret_v = qp->lineWrapColumnOrWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextEdit.getLineWrapMode();
KMETHOD QTextEdit_getLineWrapMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QTextEdit::LineWrapMode ret_v = qp->lineWrapMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QVariant QTextEdit.loadResource(int type, QUrl name);
KMETHOD QTextEdit_loadResource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		int type = Int_to(int, sfp[1]);
		const QUrl  name = *RawPtr_to(const QUrl *, sfp[2]);
		QVariant ret_v = qp->loadResource(type, name);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextEdit.mergeCurrentCharFormat(QTextCharFormat modifier);
KMETHOD QTextEdit_mergeCurrentCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QTextCharFormat  modifier = *RawPtr_to(const QTextCharFormat *, sfp[1]);
		qp->mergeCurrentCharFormat(modifier);
	}
	RETURNvoid_();
}

//void QTextEdit.moveCursor(int operation, int mode);
KMETHOD QTextEdit_moveCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QTextCursor::MoveOperation operation = Int_to(QTextCursor::MoveOperation, sfp[1]);
		QTextCursor::MoveMode mode = Int_to(QTextCursor::MoveMode, sfp[2]);
		qp->moveCursor(operation, mode);
	}
	RETURNvoid_();
}

//boolean QTextEdit.getOverwriteMode();
KMETHOD QTextEdit_getOverwriteMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->overwriteMode();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTextEdit.print(QPrinter printer);
KMETHOD QTextEdit_print(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QPrinter*  printer = RawPtr_to(QPrinter*, sfp[1]);
		qp->print(printer);
	}
	RETURNvoid_();
}

//void QTextEdit.setAcceptRichText(boolean accept);
KMETHOD QTextEdit_setAcceptRichText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool accept = Boolean_to(bool, sfp[1]);
		qp->setAcceptRichText(accept);
	}
	RETURNvoid_();
}

//void QTextEdit.setAutoFormatting(QTextEditAutoFormatting features);
KMETHOD QTextEdit_setAutoFormatting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		initFlag(features, QTextEdit::AutoFormatting, sfp[1]);
		qp->setAutoFormatting(features);
	}
	RETURNvoid_();
}

//void QTextEdit.setCurrentCharFormat(QTextCharFormat fmt);
KMETHOD QTextEdit_setCurrentCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QTextCharFormat  format = *RawPtr_to(const QTextCharFormat *, sfp[1]);
		qp->setCurrentCharFormat(format);
	}
	RETURNvoid_();
}

//void QTextEdit.setCursorWidth(int width);
KMETHOD QTextEdit_setCursorWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		qp->setCursorWidth(width);
	}
	RETURNvoid_();
}

//void QTextEdit.setDocument(QTextDocument document);
KMETHOD QTextEdit_setDocument(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QTextDocument*  document = RawPtr_to(QTextDocument*, sfp[1]);
		qp->setDocument(document);
	}
	RETURNvoid_();
}

//void QTextEdit.setDocumentTitle(String title);
KMETHOD QTextEdit_setDocumentTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QString title = String_to(const QString, sfp[1]);
		qp->setDocumentTitle(title);
	}
	RETURNvoid_();
}

//void QTextEdit.setLineWrapColumnOrWidth(int w);
KMETHOD QTextEdit_setLineWrapColumnOrWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		int w = Int_to(int, sfp[1]);
		qp->setLineWrapColumnOrWidth(w);
	}
	RETURNvoid_();
}

//void QTextEdit.setLineWrapMode(int mode);
KMETHOD QTextEdit_setLineWrapMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QTextEdit::LineWrapMode mode = Int_to(QTextEdit::LineWrapMode, sfp[1]);
		qp->setLineWrapMode(mode);
	}
	RETURNvoid_();
}

//void QTextEdit.setOverwriteMode(boolean overwrite);
KMETHOD QTextEdit_setOverwriteMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool overwrite = Boolean_to(bool, sfp[1]);
		qp->setOverwriteMode(overwrite);
	}
	RETURNvoid_();
}

//void QTextEdit.setReadOnly(boolean ro);
KMETHOD QTextEdit_setReadOnly(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool ro = Boolean_to(bool, sfp[1]);
		qp->setReadOnly(ro);
	}
	RETURNvoid_();
}

//void QTextEdit.setTabChangesFocus(boolean b);
KMETHOD QTextEdit_setTabChangesFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setTabChangesFocus(b);
	}
	RETURNvoid_();
}

//void QTextEdit.setTabStopWidth(int width);
KMETHOD QTextEdit_setTabStopWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		qp->setTabStopWidth(width);
	}
	RETURNvoid_();
}

//void QTextEdit.setTextCursor(QTextCursor cursor);
KMETHOD QTextEdit_setTextCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[1]);
		qp->setTextCursor(cursor);
	}
	RETURNvoid_();
}

//void QTextEdit.setTextInteractionFlags(QtTextInteractionFlags flags);
KMETHOD QTextEdit_setTextInteractionFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		initFlag(flags, Qt::TextInteractionFlags, sfp[1]);
		qp->setTextInteractionFlags(flags);
	}
	RETURNvoid_();
}

//void QTextEdit.setUndoRedoEnabled(boolean enable);
KMETHOD QTextEdit_setUndoRedoEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setUndoRedoEnabled(enable);
	}
	RETURNvoid_();
}

//void QTextEdit.setWordWrapMode(int policy);
KMETHOD QTextEdit_setWordWrapMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QTextOption::WrapMode policy = Int_to(QTextOption::WrapMode, sfp[1]);
		qp->setWordWrapMode(policy);
	}
	RETURNvoid_();
}

//boolean QTextEdit.getTabChangesFocus();
KMETHOD QTextEdit_getTabChangesFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->tabChangesFocus();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTextEdit.getTabStopWidth();
KMETHOD QTextEdit_getTabStopWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		int ret_v = qp->tabStopWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QColor QTextEdit.getTextBackgroundColor();
KMETHOD QTextEdit_getTextBackgroundColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QColor ret_v = qp->textBackgroundColor();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QTextEdit.getTextColor();
KMETHOD QTextEdit_getTextColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QColor ret_v = qp->textColor();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCursor QTextEdit.getTextCursor();
KMETHOD QTextEdit_getTextCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QTextCursor ret_v = qp->textCursor();
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtTextInteractionFlags QTextEdit.getTextInteractionFlags();
KMETHOD QTextEdit_getTextInteractionFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		Qt::TextInteractionFlags ret_v = qp->textInteractionFlags();
		Qt::TextInteractionFlags *ret_v_ = new Qt::TextInteractionFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTextEdit.toHtml();
KMETHOD QTextEdit_toHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toHtml();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTextEdit.toPlainText();
KMETHOD QTextEdit_toPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toPlainText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextEdit.getWordWrapMode();
KMETHOD QTextEdit_getWordWrapMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		QTextOption::WrapMode ret_v = qp->wordWrapMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextEdit.append(String text);
KMETHOD QTextEdit_append(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->append(text);
	}
	RETURNvoid_();
}

//void QTextEdit.clear();
KMETHOD QTextEdit_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//void QTextEdit.copy();
KMETHOD QTextEdit_copy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		qp->copy();
	}
	RETURNvoid_();
}

//void QTextEdit.cut();
KMETHOD QTextEdit_cut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		qp->cut();
	}
	RETURNvoid_();
}

//void QTextEdit.insertHtml(String text);
KMETHOD QTextEdit_insertHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->insertHtml(text);
	}
	RETURNvoid_();
}

//void QTextEdit.insertPlainText(String text);
KMETHOD QTextEdit_insertPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->insertPlainText(text);
	}
	RETURNvoid_();
}

//void QTextEdit.paste();
KMETHOD QTextEdit_paste(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		qp->paste();
	}
	RETURNvoid_();
}

//void QTextEdit.redo();
KMETHOD QTextEdit_redo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		qp->redo();
	}
	RETURNvoid_();
}

//void QTextEdit.scrollToAnchor(String name);
KMETHOD QTextEdit_scrollToAnchor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		qp->scrollToAnchor(name);
	}
	RETURNvoid_();
}

//void QTextEdit.selectAll();
KMETHOD QTextEdit_selectAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		qp->selectAll();
	}
	RETURNvoid_();
}

//void QTextEdit.setAlignment(QtAlignment a);
KMETHOD QTextEdit_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		initFlag(a, Qt::Alignment, sfp[1]);
		qp->setAlignment(a);
	}
	RETURNvoid_();
}

//void QTextEdit.setCurrentFont(QFont f);
KMETHOD QTextEdit_setCurrentFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QFont  f = *RawPtr_to(const QFont *, sfp[1]);
		qp->setCurrentFont(f);
	}
	RETURNvoid_();
}

//void QTextEdit.setFontFamily(String fontFamily);
KMETHOD QTextEdit_setFontFamily(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QString fontFamily = String_to(const QString, sfp[1]);
		qp->setFontFamily(fontFamily);
	}
	RETURNvoid_();
}

//void QTextEdit.setFontItalic(boolean italic);
KMETHOD QTextEdit_setFontItalic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool italic = Boolean_to(bool, sfp[1]);
		qp->setFontItalic(italic);
	}
	RETURNvoid_();
}

//void QTextEdit.setFontPointSize(float s);
KMETHOD QTextEdit_setFontPointSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		qreal s = Float_to(qreal, sfp[1]);
		qp->setFontPointSize(s);
	}
	RETURNvoid_();
}

//void QTextEdit.setFontUnderline(boolean underline);
KMETHOD QTextEdit_setFontUnderline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		bool underline = Boolean_to(bool, sfp[1]);
		qp->setFontUnderline(underline);
	}
	RETURNvoid_();
}

//void QTextEdit.setFontWeight(int weight);
KMETHOD QTextEdit_setFontWeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		int weight = Int_to(int, sfp[1]);
		qp->setFontWeight(weight);
	}
	RETURNvoid_();
}

//void QTextEdit.setHtml(String text);
KMETHOD QTextEdit_setHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setHtml(text);
	}
	RETURNvoid_();
}

//void QTextEdit.setPlainText(String text);
KMETHOD QTextEdit_setPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setPlainText(text);
	}
	RETURNvoid_();
}

//void QTextEdit.setText(String text);
KMETHOD QTextEdit_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setText(text);
	}
	RETURNvoid_();
}

//void QTextEdit.setTextBackgroundColor(QColor c);
KMETHOD QTextEdit_setTextBackgroundColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QColor  c = *RawPtr_to(const QColor *, sfp[1]);
		qp->setTextBackgroundColor(c);
	}
	RETURNvoid_();
}

//void QTextEdit.setTextColor(QColor c);
KMETHOD QTextEdit_setTextColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		const QColor  c = *RawPtr_to(const QColor *, sfp[1]);
		qp->setTextColor(c);
	}
	RETURNvoid_();
}

//void QTextEdit.undo();
KMETHOD QTextEdit_undo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		qp->undo();
	}
	RETURNvoid_();
}

//void QTextEdit.zoomIn(int range);
KMETHOD QTextEdit_zoomIn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		int range = Int_to(int, sfp[1]);
		qp->zoomIn(range);
	}
	RETURNvoid_();
}

//void QTextEdit.zoomOut(int range);
KMETHOD QTextEdit_zoomOut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit *  qp = RawPtr_to(QTextEdit *, sfp[0]);
	if (qp) {
		int range = Int_to(int, sfp[1]);
		qp->zoomOut(range);
	}
	RETURNvoid_();
}


DummyQTextEdit::DummyQTextEdit()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	copy_available_func = NULL;
	current_char_format_changed_func = NULL;
	cursor_position_changed_func = NULL;
	redo_available_func = NULL;
	selection_changed_func = NULL;
	text_changed_func = NULL;
	undo_available_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("copy-available", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("current-char-format-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("cursor-position-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("redo-available", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("selection-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("text-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("undo-available", NULL));
}
DummyQTextEdit::~DummyQTextEdit()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQTextEdit::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextEdit::self = ptr;
	DummyQAbstractScrollArea::setSelf(ptr);
}

bool DummyQTextEdit::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractScrollArea::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextEdit::copyAvailableSlot(bool yes)
{
	if (copy_available_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = yes;
		knh_Func_invoke(lctx, copy_available_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQTextEdit::currentCharFormatChangedSlot(const QTextCharFormat f)
{
	if (current_char_format_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QTextCharFormat, f);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, current_char_format_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQTextEdit::cursorPositionChangedSlot()
{
	if (cursor_position_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, cursor_position_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQTextEdit::redoAvailableSlot(bool available)
{
	if (redo_available_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = available;
		knh_Func_invoke(lctx, redo_available_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQTextEdit::selectionChangedSlot()
{
	if (selection_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, selection_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQTextEdit::textChangedSlot()
{
	if (text_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, text_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQTextEdit::undoAvailableSlot(bool available)
{
	if (undo_available_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = available;
		knh_Func_invoke(lctx, undo_available_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQTextEdit::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextEdit::event_map->bigin();
	if ((itr = DummyQTextEdit::event_map->find(str)) == DummyQTextEdit::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractScrollArea::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextEdit::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextEdit::slot_map->bigin();
	if ((itr = DummyQTextEdit::slot_map->find(str)) == DummyQTextEdit::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractScrollArea::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		copy_available_func = (*slot_map)["copy-available"];
		current_char_format_changed_func = (*slot_map)["current-char-format-changed"];
		cursor_position_changed_func = (*slot_map)["cursor-position-changed"];
		redo_available_func = (*slot_map)["redo-available"];
		selection_changed_func = (*slot_map)["selection-changed"];
		text_changed_func = (*slot_map)["text-changed"];
		undo_available_func = (*slot_map)["undo-available"];
		return true;
	}
}

knh_Object_t** DummyQTextEdit::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextEdit::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 8;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, copy_available_func);
	KNH_ADDNNREF(ctx, current_char_format_changed_func);
	KNH_ADDNNREF(ctx, cursor_position_changed_func);
	KNH_ADDNNREF(ctx, redo_available_func);
	KNH_ADDNNREF(ctx, selection_changed_func);
	KNH_ADDNNREF(ctx, text_changed_func);
	KNH_ADDNNREF(ctx, undo_available_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQAbstractScrollArea::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQTextEdit::connection(QObject *o)
{
	QTextEdit *p = dynamic_cast<QTextEdit*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(copyAvailable(bool)), this, SLOT(copyAvailableSlot(bool)));
		connect(p, SIGNAL(currentCharFormatChanged(const QTextCharFormat)), this, SLOT(currentCharFormatChangedSlot(const QTextCharFormat)));
		connect(p, SIGNAL(cursorPositionChanged()), this, SLOT(cursorPositionChangedSlot()));
		connect(p, SIGNAL(redoAvailable(bool)), this, SLOT(redoAvailableSlot(bool)));
		connect(p, SIGNAL(selectionChanged()), this, SLOT(selectionChangedSlot()));
		connect(p, SIGNAL(textChanged()), this, SLOT(textChangedSlot()));
		connect(p, SIGNAL(undoAvailable(bool)), this, SLOT(undoAvailableSlot(bool)));
	}
	DummyQAbstractScrollArea::connection(o);
}

KQTextEdit::KQTextEdit(QWidget* parent) : QTextEdit(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTextEdit();
	dummy->connection((QObject*)this);
}

KQTextEdit::~KQTextEdit()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QTextEdit_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextEdit *qp = RawPtr_to(KQTextEdit *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextEdit]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextEdit]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextEdit_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextEdit *qp = RawPtr_to(KQTextEdit *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextEdit]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextEdit]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextEdit_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTextEdit *qp = (KQTextEdit *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTextEdit*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTextEdit_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTextEdit *qp = (KQTextEdit *)p->rawptr;
		KQTextEdit *qp = static_cast<KQTextEdit*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextEdit_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextEdit::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTextEdit::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTextEdit::event(event);
		return false;
	}
//	QTextEdit::event(event);
	return true;
}

static knh_IntData_t QTextEditConstInt[] = {
	{"AutoNone", QTextEdit::AutoNone},
	{"AutoBulletList", QTextEdit::AutoBulletList},
	{"AutoAll", QTextEdit::AutoAll},
	{"NoWrap", QTextEdit::NoWrap},
	{"WidgetWidth", QTextEdit::WidgetWidth},
	{"FixedPixelWidth", QTextEdit::FixedPixelWidth},
	{"FixedColumnWidth", QTextEdit::FixedColumnWidth},
	{NULL, 0}
};

DEFAPI(void) constQTextEdit(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextEditConstInt);
}


DEFAPI(void) defQTextEdit(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextEdit";
	cdef->free = QTextEdit_free;
	cdef->reftrace = QTextEdit_reftrace;
	cdef->compareTo = QTextEdit_compareTo;
}

//## QTextEditAutoFormatting QTextEditAutoFormatting.new(int value);
KMETHOD QTextEditAutoFormatting_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextEdit::AutoFormattingFlag i = Int_to(QTextEdit::AutoFormattingFlag, sfp[1]);
	QTextEdit::AutoFormatting *ret_v = new QTextEdit::AutoFormatting(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QTextEditAutoFormatting QTextEditAutoFormatting.and(int mask);
KMETHOD QTextEditAutoFormatting_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextEdit::AutoFormatting *qp = RawPtr_to(QTextEdit::AutoFormatting*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QTextEdit::AutoFormatting ret = ((*qp) & i);
		QTextEdit::AutoFormatting *ret_ = new QTextEdit::AutoFormatting(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextEditAutoFormatting QTextEditAutoFormatting.iand(QTextEdit::QTextEditAutoFormatting other);
KMETHOD QTextEditAutoFormatting_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextEdit::AutoFormatting *qp = RawPtr_to(QTextEdit::AutoFormatting*, sfp[0]);
	if (qp != NULL) {
		QTextEdit::AutoFormatting *other = RawPtr_to(QTextEdit::AutoFormatting *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextEditAutoFormatting QTextEditAutoFormatting.or(QTextEditAutoFormatting f);
KMETHOD QTextEditAutoFormatting_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit::AutoFormatting *qp = RawPtr_to(QTextEdit::AutoFormatting*, sfp[0]);
	if (qp != NULL) {
		QTextEdit::AutoFormatting *f = RawPtr_to(QTextEdit::AutoFormatting*, sfp[1]);
		QTextEdit::AutoFormatting ret = ((*qp) | (*f));
		QTextEdit::AutoFormatting *ret_ = new QTextEdit::AutoFormatting(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextEditAutoFormatting QTextEditAutoFormatting.ior(QTextEdit::QTextEditAutoFormatting other);
KMETHOD QTextEditAutoFormatting_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextEdit::AutoFormatting *qp = RawPtr_to(QTextEdit::AutoFormatting*, sfp[0]);
	if (qp != NULL) {
		QTextEdit::AutoFormatting *other = RawPtr_to(QTextEdit::AutoFormatting *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextEditAutoFormatting QTextEditAutoFormatting.xor(QTextEditAutoFormatting f);
KMETHOD QTextEditAutoFormatting_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEdit::AutoFormatting *qp = RawPtr_to(QTextEdit::AutoFormatting*, sfp[0]);
	if (qp != NULL) {
		QTextEdit::AutoFormatting *f = RawPtr_to(QTextEdit::AutoFormatting*, sfp[1]);
		QTextEdit::AutoFormatting ret = ((*qp) ^ (*f));
		QTextEdit::AutoFormatting *ret_ = new QTextEdit::AutoFormatting(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextEditAutoFormatting QTextEditAutoFormatting.ixor(QTextEdit::QTextEditAutoFormatting other);
KMETHOD QTextEditAutoFormatting_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextEdit::AutoFormatting *qp = RawPtr_to(QTextEdit::AutoFormatting*, sfp[0]);
	if (qp != NULL) {
		QTextEdit::AutoFormatting *other = RawPtr_to(QTextEdit::AutoFormatting *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QTextEditAutoFormatting.testFlag(int flag);
KMETHOD QTextEditAutoFormatting_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextEdit::AutoFormatting *qp = RawPtr_to(QTextEdit::AutoFormatting *, sfp[0]);
	if (qp != NULL) {
		QTextEdit::AutoFormattingFlag flag = Int_to(QTextEdit::AutoFormattingFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QTextEditAutoFormatting.value();
KMETHOD QTextEditAutoFormatting_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextEdit::AutoFormatting *qp = RawPtr_to(QTextEdit::AutoFormatting *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QTextEditAutoFormatting_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QTextEdit::AutoFormatting *qp = (QTextEdit::AutoFormatting *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QTextEditAutoFormatting_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QTextEdit::AutoFormatting *qp = (QTextEdit::AutoFormatting *)p->rawptr;
		(void)qp;
	}
}

static int QTextEditAutoFormatting_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QTextEdit::AutoFormatting*)p1->rawptr);
//		int v2 = int(*(QTextEdit::AutoFormatting*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QTextEdit::AutoFormatting v1 = *(QTextEdit::AutoFormatting*)p1->rawptr;
		QTextEdit::AutoFormatting v2 = *(QTextEdit::AutoFormatting*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQTextEditAutoFormatting(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextEditAutoFormatting";
	cdef->free = QTextEditAutoFormatting_free;
	cdef->reftrace = QTextEditAutoFormatting_reftrace;
	cdef->compareTo = QTextEditAutoFormatting_compareTo;
}

