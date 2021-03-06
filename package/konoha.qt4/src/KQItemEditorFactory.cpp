//QItemEditorFactory QItemEditorFactory.new();
KMETHOD QItemEditorFactory_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQItemEditorFactory *ret_v = new KQItemEditorFactory();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//@Virtual QWidget QItemEditorFactory.createEditor(int type, QWidget parent);
KMETHOD QItemEditorFactory_createEditor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemEditorFactory *  qp = RawPtr_to(QItemEditorFactory *, sfp[0]);
	if (qp) {
		QVariant::Type type = Int_to(QVariant::Type, sfp[1]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
		QWidget* ret_v = qp->createEditor(type, parent);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QItemEditorFactory.registerEditor(int type, QItemEditorCreatorBase creator);
KMETHOD QItemEditorFactory_registerEditor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemEditorFactory *  qp = RawPtr_to(QItemEditorFactory *, sfp[0]);
	if (qp) {
		QVariant::Type type = Int_to(QVariant::Type, sfp[1]);
		QItemEditorCreatorBase*  creator = RawPtr_to(QItemEditorCreatorBase*, sfp[2]);
		qp->registerEditor(type, creator);
	}
	RETURNvoid_();
}

//@Virtual QByteArray QItemEditorFactory.valuePropertyName(int type);
KMETHOD QItemEditorFactory_valuePropertyName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemEditorFactory *  qp = RawPtr_to(QItemEditorFactory *, sfp[0]);
	if (qp) {
		QVariant::Type type = Int_to(QVariant::Type, sfp[1]);
		QByteArray ret_v = qp->valuePropertyName(type);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QItemEditorFactory QItemEditorFactory.getDefaultFactory();
KMETHOD QItemEditorFactory_getDefaultFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QItemEditorFactory* ret_v = QItemEditorFactory::defaultFactory();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QItemEditorFactory*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QItemEditorFactory.setDefaultFactory(QItemEditorFactory factory);
KMETHOD QItemEditorFactory_setDefaultFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QItemEditorFactory*  factory = RawPtr_to(QItemEditorFactory*, sfp[1]);
		QItemEditorFactory::setDefaultFactory(factory);
	}
	RETURNvoid_();
}

//Array<String> QItemEditorFactory.parents();
KMETHOD QItemEditorFactory_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemEditorFactory *qp = RawPtr_to(QItemEditorFactory*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQItemEditorFactory::DummyQItemEditorFactory()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQItemEditorFactory::~DummyQItemEditorFactory()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQItemEditorFactory::setSelf(knh_RawPtr_t *ptr)
{
	DummyQItemEditorFactory::self = ptr;
}

bool DummyQItemEditorFactory::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQItemEditorFactory::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQItemEditorFactory::event_map->bigin();
	if ((itr = DummyQItemEditorFactory::event_map->find(str)) == DummyQItemEditorFactory::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQItemEditorFactory::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQItemEditorFactory::slot_map->bigin();
	if ((itr = DummyQItemEditorFactory::slot_map->find(str)) == DummyQItemEditorFactory::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQItemEditorFactory::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQItemEditorFactory::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQItemEditorFactory::connection(QObject *o)
{
	QItemEditorFactory *p = dynamic_cast<QItemEditorFactory*>(o);
	if (p != NULL) {
	}
}

KQItemEditorFactory::KQItemEditorFactory() : QItemEditorFactory()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQItemEditorFactory();
}

KQItemEditorFactory::~KQItemEditorFactory()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QItemEditorFactory_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQItemEditorFactory *qp = RawPtr_to(KQItemEditorFactory *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QItemEditorFactory]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QItemEditorFactory]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QItemEditorFactory_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQItemEditorFactory *qp = RawPtr_to(KQItemEditorFactory *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QItemEditorFactory]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QItemEditorFactory]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QItemEditorFactory_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQItemEditorFactory *qp = (KQItemEditorFactory *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QItemEditorFactory*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QItemEditorFactory_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQItemEditorFactory *qp = (KQItemEditorFactory *)p->rawptr;
		KQItemEditorFactory *qp = static_cast<KQItemEditorFactory*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QItemEditorFactory_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQItemEditorFactory::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQItemEditorFactory(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QItemEditorFactory";
	cdef->free = QItemEditorFactory_free;
	cdef->reftrace = QItemEditorFactory_reftrace;
	cdef->compareTo = QItemEditorFactory_compareTo;
}


