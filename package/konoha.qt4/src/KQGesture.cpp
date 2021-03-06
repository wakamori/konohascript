//QGesture QGesture.new(QObject parent);
KMETHOD QGesture_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQGesture *ret_v = new KQGesture(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QGesture.getGestureCancelPolicy();
KMETHOD QGesture_getGestureCancelPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGesture *  qp = RawPtr_to(QGesture *, sfp[0]);
	if (qp) {
		QGesture::GestureCancelPolicy ret_v = qp->gestureCancelPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGesture.gestureType();
KMETHOD QGesture_gestureType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGesture *  qp = RawPtr_to(QGesture *, sfp[0]);
	if (qp) {
		Qt::GestureType ret_v = qp->gestureType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QGesture.hasHotSpot();
KMETHOD QGesture_hasHotSpot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGesture *  qp = RawPtr_to(QGesture *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasHotSpot();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QPointF QGesture.getHotSpot();
KMETHOD QGesture_getHotSpot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGesture *  qp = RawPtr_to(QGesture *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->hotSpot();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGesture.setGestureCancelPolicy(int policy);
KMETHOD QGesture_setGestureCancelPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGesture *  qp = RawPtr_to(QGesture *, sfp[0]);
	if (qp) {
		QGesture::GestureCancelPolicy policy = Int_to(QGesture::GestureCancelPolicy, sfp[1]);
		qp->setGestureCancelPolicy(policy);
	}
	RETURNvoid_();
}

//void QGesture.setHotSpot(QPointF value);
KMETHOD QGesture_setHotSpot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGesture *  qp = RawPtr_to(QGesture *, sfp[0]);
	if (qp) {
		const QPointF  value = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setHotSpot(value);
	}
	RETURNvoid_();
}

//int QGesture.state();
KMETHOD QGesture_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGesture *  qp = RawPtr_to(QGesture *, sfp[0]);
	if (qp) {
		Qt::GestureState ret_v = qp->state();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGesture.unsetHotSpot();
KMETHOD QGesture_unsetHotSpot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGesture *  qp = RawPtr_to(QGesture *, sfp[0]);
	if (qp) {
		qp->unsetHotSpot();
	}
	RETURNvoid_();
}


DummyQGesture::DummyQGesture()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQGesture::~DummyQGesture()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGesture::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGesture::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQGesture::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGesture::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGesture::event_map->bigin();
	if ((itr = DummyQGesture::event_map->find(str)) == DummyQGesture::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGesture::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGesture::slot_map->bigin();
	if ((itr = DummyQGesture::slot_map->find(str)) == DummyQGesture::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGesture::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGesture::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGesture::connection(QObject *o)
{
	QGesture *p = dynamic_cast<QGesture*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQGesture::KQGesture(QObject* parent) : QGesture(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQGesture();
	dummy->connection((QObject*)this);
}

KQGesture::~KQGesture()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGesture_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGesture *qp = RawPtr_to(KQGesture *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGesture]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGesture]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGesture_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGesture *qp = RawPtr_to(KQGesture *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGesture]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGesture]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGesture_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGesture *qp = (KQGesture *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGesture*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGesture_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGesture *qp = (KQGesture *)p->rawptr;
		KQGesture *qp = static_cast<KQGesture*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGesture_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGesture::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGesture::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGesture::event(event);
		return false;
	}
//	QGesture::event(event);
	return true;
}

static knh_IntData_t QGestureConstInt[] = {
	{"CancelNone", QGesture::CancelNone},
	{"CancelAllInContext", QGesture::CancelAllInContext},
	{NULL, 0}
};

DEFAPI(void) constQGesture(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGestureConstInt);
}


DEFAPI(void) defQGesture(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGesture";
	cdef->free = QGesture_free;
	cdef->reftrace = QGesture_reftrace;
	cdef->compareTo = QGesture_compareTo;
}


