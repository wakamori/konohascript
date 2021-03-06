//QCompleter QCompleter.new(QObject parent);
KMETHOD QCompleter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQCompleter *ret_v = new KQCompleter(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QCompleter QCompleter.new(QAbstractItemModel model, QObject parent);
KMETHOD QCompleter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQCompleter *ret_v = new KQCompleter(model, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QCompleter.getCaseSensitivity();
KMETHOD QCompleter_getCaseSensitivity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		Qt::CaseSensitivity ret_v = qp->caseSensitivity();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QCompleter.getCompletionColumn();
KMETHOD QCompleter_getCompletionColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		int ret_v = qp->completionColumn();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QCompleter.completionCount();
KMETHOD QCompleter_completionCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		int ret_v = qp->completionCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QCompleter.getCompletionMode();
KMETHOD QCompleter_getCompletionMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QCompleter::CompletionMode ret_v = qp->completionMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QAbstractItemModel QCompleter.completionModel();
KMETHOD QCompleter_completionModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QAbstractItemModel* ret_v = qp->completionModel();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemModel*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QCompleter.getCompletionPrefix();
KMETHOD QCompleter_getCompletionPrefix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QString ret_v = qp->completionPrefix();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QCompleter.getCompletionRole();
KMETHOD QCompleter_getCompletionRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		int ret_v = qp->completionRole();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QCompleter.currentCompletion();
KMETHOD QCompleter_currentCompletion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QString ret_v = qp->currentCompletion();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QModelIndex QCompleter.currentIndex();
KMETHOD QCompleter_currentIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QModelIndex ret_v = qp->currentIndex();
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QCompleter.getCurrentRow();
KMETHOD QCompleter_getCurrentRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		int ret_v = qp->currentRow();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QCompleter.getMaxVisibleItems();
KMETHOD QCompleter_getMaxVisibleItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		int ret_v = qp->maxVisibleItems();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QAbstractItemModel QCompleter.getModel();
KMETHOD QCompleter_getModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QAbstractItemModel* ret_v = qp->model();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemModel*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QCompleter.getModelSorting();
KMETHOD QCompleter_getModelSorting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QCompleter::ModelSorting ret_v = qp->modelSorting();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual String QCompleter.pathFromIndex(QModelIndex index);
KMETHOD QCompleter_pathFromIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QString ret_v = qp->pathFromIndex(index);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAbstractItemView QCompleter.getPopup();
KMETHOD QCompleter_getPopup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QAbstractItemView* ret_v = qp->popup();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemView*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QCompleter.setCaseSensitivity(int caseSensitivity);
KMETHOD QCompleter_setCaseSensitivity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		Qt::CaseSensitivity caseSensitivity = Int_to(Qt::CaseSensitivity, sfp[1]);
		qp->setCaseSensitivity(caseSensitivity);
	}
	RETURNvoid_();
}

//void QCompleter.setCompletionColumn(int column);
KMETHOD QCompleter_setCompletionColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qp->setCompletionColumn(column);
	}
	RETURNvoid_();
}

//void QCompleter.setCompletionMode(int mode);
KMETHOD QCompleter_setCompletionMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QCompleter::CompletionMode mode = Int_to(QCompleter::CompletionMode, sfp[1]);
		qp->setCompletionMode(mode);
	}
	RETURNvoid_();
}

//void QCompleter.setCompletionRole(int role);
KMETHOD QCompleter_setCompletionRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		int role = Int_to(int, sfp[1]);
		qp->setCompletionRole(role);
	}
	RETURNvoid_();
}

//boolean QCompleter.setCurrentRow(int row);
KMETHOD QCompleter_setCurrentRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		bool ret_v = qp->setCurrentRow(row);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QCompleter.setMaxVisibleItems(int maxItems);
KMETHOD QCompleter_setMaxVisibleItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		int maxItems = Int_to(int, sfp[1]);
		qp->setMaxVisibleItems(maxItems);
	}
	RETURNvoid_();
}

//void QCompleter.setModel(QAbstractItemModel model);
KMETHOD QCompleter_setModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[1]);
		qp->setModel(model);
	}
	RETURNvoid_();
}

//void QCompleter.setModelSorting(int sorting);
KMETHOD QCompleter_setModelSorting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QCompleter::ModelSorting sorting = Int_to(QCompleter::ModelSorting, sfp[1]);
		qp->setModelSorting(sorting);
	}
	RETURNvoid_();
}

//void QCompleter.setPopup(QAbstractItemView popup);
KMETHOD QCompleter_setPopup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QAbstractItemView*  popup = RawPtr_to(QAbstractItemView*, sfp[1]);
		qp->setPopup(popup);
	}
	RETURNvoid_();
}

//void QCompleter.setWidget(QWidget widget);
KMETHOD QCompleter_setWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setWidget(widget);
	}
	RETURNvoid_();
}

//QWidget QCompleter.getWidget();
KMETHOD QCompleter_getWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->widget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QCompleter.getWrapAround();
KMETHOD QCompleter_getWrapAround(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		bool ret_v = qp->wrapAround();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QCompleter.complete(QRect rect);
KMETHOD QCompleter_complete(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		qp->complete(rect);
	}
	RETURNvoid_();
}

//void QCompleter.setCompletionPrefix(String prefix);
KMETHOD QCompleter_setCompletionPrefix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		const QString prefix = String_to(const QString, sfp[1]);
		qp->setCompletionPrefix(prefix);
	}
	RETURNvoid_();
}

//void QCompleter.setWrapAround(boolean wrap);
KMETHOD QCompleter_setWrapAround(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCompleter *  qp = RawPtr_to(QCompleter *, sfp[0]);
	if (qp) {
		bool wrap = Boolean_to(bool, sfp[1]);
		qp->setWrapAround(wrap);
	}
	RETURNvoid_();
}


DummyQCompleter::DummyQCompleter()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQCompleter::~DummyQCompleter()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQCompleter::setSelf(knh_RawPtr_t *ptr)
{
	DummyQCompleter::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQCompleter::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQCompleter::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCompleter::event_map->bigin();
	if ((itr = DummyQCompleter::event_map->find(str)) == DummyQCompleter::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQCompleter::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCompleter::slot_map->bigin();
	if ((itr = DummyQCompleter::slot_map->find(str)) == DummyQCompleter::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQCompleter::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQCompleter::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQCompleter::connection(QObject *o)
{
	QCompleter *p = dynamic_cast<QCompleter*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQCompleter::KQCompleter(QObject* parent) : QCompleter(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQCompleter();
	dummy->connection((QObject*)this);
}

KQCompleter::~KQCompleter()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QCompleter_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCompleter *qp = RawPtr_to(KQCompleter *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QCompleter]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCompleter]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QCompleter_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCompleter *qp = RawPtr_to(KQCompleter *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QCompleter]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCompleter]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QCompleter_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQCompleter *qp = (KQCompleter *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QCompleter*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QCompleter_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQCompleter *qp = (KQCompleter *)p->rawptr;
		KQCompleter *qp = static_cast<KQCompleter*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QCompleter_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQCompleter::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQCompleter::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QCompleter::event(event);
		return false;
	}
//	QCompleter::event(event);
	return true;
}

static knh_IntData_t QCompleterConstInt[] = {
	{"PopupCompletion", QCompleter::PopupCompletion},
	{"InlineCompletion", QCompleter::InlineCompletion},
	{"UnfilteredPopupCompletion", QCompleter::UnfilteredPopupCompletion},
	{"UnsortedModel", QCompleter::UnsortedModel},
	{"CaseSensitivelySortedModel", QCompleter::CaseSensitivelySortedModel},
	{"CaseInsensitivelySortedModel", QCompleter::CaseInsensitivelySortedModel},
	{NULL, 0}
};

DEFAPI(void) constQCompleter(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QCompleterConstInt);
}


DEFAPI(void) defQCompleter(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QCompleter";
	cdef->free = QCompleter_free;
	cdef->reftrace = QCompleter_reftrace;
	cdef->compareTo = QCompleter_compareTo;
}


