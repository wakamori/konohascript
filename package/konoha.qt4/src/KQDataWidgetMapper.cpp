//QDataWidgetMapper QDataWidgetMapper.new(QObject parent);
KMETHOD QDataWidgetMapper_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQDataWidgetMapper *ret_v = new KQDataWidgetMapper(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QDataWidgetMapper.addMapping(QWidget widget, int section);
KMETHOD QDataWidgetMapper_addMapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int section = Int_to(int, sfp[2]);
		qp->addMapping(widget, section);
	}
	RETURNvoid_();
}

/*
//void QDataWidgetMapper.addMapping(QWidget widget, int section, QByteArray propertyName);
KMETHOD QDataWidgetMapper_addMapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int section = Int_to(int, sfp[2]);
		const QByteArray  propertyName = *RawPtr_to(const QByteArray *, sfp[3]);
		qp->addMapping(widget, section, propertyName);
	}
	RETURNvoid_();
}
*/
//void QDataWidgetMapper.clearMapping();
KMETHOD QDataWidgetMapper_clearMapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		qp->clearMapping();
	}
	RETURNvoid_();
}

//int QDataWidgetMapper.getCurrentIndex();
KMETHOD QDataWidgetMapper_getCurrentIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		int ret_v = qp->currentIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QAbstractItemDelegate QDataWidgetMapper.getItemDelegate();
KMETHOD QDataWidgetMapper_getItemDelegate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		QAbstractItemDelegate* ret_v = qp->itemDelegate();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemDelegate*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QDataWidgetMapper.mappedPropertyName(QWidget widget);
KMETHOD QDataWidgetMapper_mappedPropertyName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		QByteArray ret_v = qp->mappedPropertyName(widget);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDataWidgetMapper.mappedSection(QWidget widget);
KMETHOD QDataWidgetMapper_mappedSection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int ret_v = qp->mappedSection(widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QDataWidgetMapper.mappedWidgetAt(int section);
KMETHOD QDataWidgetMapper_mappedWidgetAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		int section = Int_to(int, sfp[1]);
		QWidget* ret_v = qp->mappedWidgetAt(section);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAbstractItemModel QDataWidgetMapper.getModel();
KMETHOD QDataWidgetMapper_getModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		QAbstractItemModel* ret_v = qp->model();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemModel*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDataWidgetMapper.getOrientation();
KMETHOD QDataWidgetMapper_getOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		Qt::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QDataWidgetMapper.removeMapping(QWidget widget);
KMETHOD QDataWidgetMapper_removeMapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->removeMapping(widget);
	}
	RETURNvoid_();
}

//QModelIndex QDataWidgetMapper.getRootIndex();
KMETHOD QDataWidgetMapper_getRootIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		QModelIndex ret_v = qp->rootIndex();
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QDataWidgetMapper.setItemDelegate(QAbstractItemDelegate delegate);
KMETHOD QDataWidgetMapper_setItemDelegate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		QAbstractItemDelegate*  delegate = RawPtr_to(QAbstractItemDelegate*, sfp[1]);
		qp->setItemDelegate(delegate);
	}
	RETURNvoid_();
}

//void QDataWidgetMapper.setModel(QAbstractItemModel model);
KMETHOD QDataWidgetMapper_setModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[1]);
		qp->setModel(model);
	}
	RETURNvoid_();
}

//void QDataWidgetMapper.setOrientation(int aOrientation);
KMETHOD QDataWidgetMapper_setOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		Qt::Orientation aOrientation = Int_to(Qt::Orientation, sfp[1]);
		qp->setOrientation(aOrientation);
	}
	RETURNvoid_();
}

//void QDataWidgetMapper.setRootIndex(QModelIndex index);
KMETHOD QDataWidgetMapper_setRootIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->setRootIndex(index);
	}
	RETURNvoid_();
}

//void QDataWidgetMapper.setSubmitPolicy(int policy);
KMETHOD QDataWidgetMapper_setSubmitPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		QDataWidgetMapper::SubmitPolicy policy = Int_to(QDataWidgetMapper::SubmitPolicy, sfp[1]);
		qp->setSubmitPolicy(policy);
	}
	RETURNvoid_();
}

//int QDataWidgetMapper.getSubmitPolicy();
KMETHOD QDataWidgetMapper_getSubmitPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		QDataWidgetMapper::SubmitPolicy ret_v = qp->submitPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QDataWidgetMapper.revert();
KMETHOD QDataWidgetMapper_revert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		qp->revert();
	}
	RETURNvoid_();
}

//@Virtual void QDataWidgetMapper.setCurrentIndex(int index);
KMETHOD QDataWidgetMapper_setCurrentIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qp->setCurrentIndex(index);
	}
	RETURNvoid_();
}

//void QDataWidgetMapper.setCurrentModelIndex(QModelIndex index);
KMETHOD QDataWidgetMapper_setCurrentModelIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->setCurrentModelIndex(index);
	}
	RETURNvoid_();
}

//boolean QDataWidgetMapper.submit();
KMETHOD QDataWidgetMapper_submit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		bool ret_v = qp->submit();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QDataWidgetMapper.toFirst();
KMETHOD QDataWidgetMapper_toFirst(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		qp->toFirst();
	}
	RETURNvoid_();
}

//void QDataWidgetMapper.toLast();
KMETHOD QDataWidgetMapper_toLast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		qp->toLast();
	}
	RETURNvoid_();
}

//void QDataWidgetMapper.toNext();
KMETHOD QDataWidgetMapper_toNext(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		qp->toNext();
	}
	RETURNvoid_();
}

//void QDataWidgetMapper.toPrevious();
KMETHOD QDataWidgetMapper_toPrevious(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDataWidgetMapper *  qp = RawPtr_to(QDataWidgetMapper *, sfp[0]);
	if (qp) {
		qp->toPrevious();
	}
	RETURNvoid_();
}


DummyQDataWidgetMapper::DummyQDataWidgetMapper()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	current_index_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("current-index-changed", NULL));
}
DummyQDataWidgetMapper::~DummyQDataWidgetMapper()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQDataWidgetMapper::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDataWidgetMapper::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQDataWidgetMapper::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDataWidgetMapper::currentIndexChangedSlot(int index)
{
	if (current_index_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = index;
		knh_Func_invoke(lctx, current_index_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDataWidgetMapper::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDataWidgetMapper::event_map->bigin();
	if ((itr = DummyQDataWidgetMapper::event_map->find(str)) == DummyQDataWidgetMapper::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDataWidgetMapper::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDataWidgetMapper::slot_map->bigin();
	if ((itr = DummyQDataWidgetMapper::slot_map->find(str)) == DummyQDataWidgetMapper::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		current_index_changed_func = (*slot_map)["current-index-changed"];
		return true;
	}
}

knh_Object_t** DummyQDataWidgetMapper::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQDataWidgetMapper::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, current_index_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQDataWidgetMapper::connection(QObject *o)
{
	QDataWidgetMapper *p = dynamic_cast<QDataWidgetMapper*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(currentIndexChanged(int)), this, SLOT(currentIndexChangedSlot(int)));
	}
	DummyQObject::connection(o);
}

KQDataWidgetMapper::KQDataWidgetMapper(QObject* parent) : QDataWidgetMapper(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQDataWidgetMapper();
	dummy->connection((QObject*)this);
}

KQDataWidgetMapper::~KQDataWidgetMapper()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QDataWidgetMapper_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDataWidgetMapper *qp = RawPtr_to(KQDataWidgetMapper *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDataWidgetMapper]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDataWidgetMapper]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDataWidgetMapper_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDataWidgetMapper *qp = RawPtr_to(KQDataWidgetMapper *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDataWidgetMapper]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDataWidgetMapper]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDataWidgetMapper_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQDataWidgetMapper *qp = (KQDataWidgetMapper *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QDataWidgetMapper*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QDataWidgetMapper_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQDataWidgetMapper *qp = (KQDataWidgetMapper *)p->rawptr;
		KQDataWidgetMapper *qp = static_cast<KQDataWidgetMapper*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QDataWidgetMapper_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDataWidgetMapper::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQDataWidgetMapper::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QDataWidgetMapper::event(event);
		return false;
	}
//	QDataWidgetMapper::event(event);
	return true;
}

static knh_IntData_t QDataWidgetMapperConstInt[] = {
	{"AutoSubmit", QDataWidgetMapper::AutoSubmit},
	{"ManualSubmit", QDataWidgetMapper::ManualSubmit},
	{NULL, 0}
};

DEFAPI(void) constQDataWidgetMapper(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QDataWidgetMapperConstInt);
}


DEFAPI(void) defQDataWidgetMapper(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDataWidgetMapper";
	cdef->free = QDataWidgetMapper_free;
	cdef->reftrace = QDataWidgetMapper_reftrace;
	cdef->compareTo = QDataWidgetMapper_compareTo;
}


