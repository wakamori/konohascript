//QSystemSemaphore QSystemSemaphore.new(String key, int initialValue, int mode);
KMETHOD QSystemSemaphore_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString key = String_to(const QString, sfp[1]);
	int initialValue = Int_to(int, sfp[2]);
	QSystemSemaphore::AccessMode mode = Int_to(QSystemSemaphore::AccessMode, sfp[3]);
	KQSystemSemaphore *ret_v = new KQSystemSemaphore(key, initialValue, mode);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QSystemSemaphore.acquire();
KMETHOD QSystemSemaphore_acquire(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemSemaphore *  qp = RawPtr_to(QSystemSemaphore *, sfp[0]);
	if (qp) {
		bool ret_v = qp->acquire();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QSystemSemaphore.error();
KMETHOD QSystemSemaphore_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemSemaphore *  qp = RawPtr_to(QSystemSemaphore *, sfp[0]);
	if (qp) {
		QSystemSemaphore::SystemSemaphoreError ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QSystemSemaphore.errorString();
KMETHOD QSystemSemaphore_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemSemaphore *  qp = RawPtr_to(QSystemSemaphore *, sfp[0]);
	if (qp) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QSystemSemaphore.getKey();
KMETHOD QSystemSemaphore_getKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemSemaphore *  qp = RawPtr_to(QSystemSemaphore *, sfp[0]);
	if (qp) {
		QString ret_v = qp->key();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QSystemSemaphore.release(int n);
KMETHOD QSystemSemaphore_release(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemSemaphore *  qp = RawPtr_to(QSystemSemaphore *, sfp[0]);
	if (qp) {
		int n = Int_to(int, sfp[1]);
		bool ret_v = qp->release(n);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QSystemSemaphore.setKey(String key, int initialValue, int mode);
KMETHOD QSystemSemaphore_setKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemSemaphore *  qp = RawPtr_to(QSystemSemaphore *, sfp[0]);
	if (qp) {
		const QString key = String_to(const QString, sfp[1]);
		int initialValue = Int_to(int, sfp[2]);
		QSystemSemaphore::AccessMode mode = Int_to(QSystemSemaphore::AccessMode, sfp[3]);
		qp->setKey(key, initialValue, mode);
	}
	RETURNvoid_();
}

//Array<String> QSystemSemaphore.parents();
KMETHOD QSystemSemaphore_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemSemaphore *qp = RawPtr_to(QSystemSemaphore*, sfp[0]);
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

DummyQSystemSemaphore::DummyQSystemSemaphore()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQSystemSemaphore::~DummyQSystemSemaphore()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQSystemSemaphore::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSystemSemaphore::self = ptr;
}

bool DummyQSystemSemaphore::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSystemSemaphore::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSystemSemaphore::event_map->bigin();
	if ((itr = DummyQSystemSemaphore::event_map->find(str)) == DummyQSystemSemaphore::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSystemSemaphore::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSystemSemaphore::slot_map->bigin();
	if ((itr = DummyQSystemSemaphore::slot_map->find(str)) == DummyQSystemSemaphore::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQSystemSemaphore::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQSystemSemaphore::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQSystemSemaphore::connection(QObject *o)
{
	QSystemSemaphore *p = dynamic_cast<QSystemSemaphore*>(o);
	if (p != NULL) {
	}
}

KQSystemSemaphore::KQSystemSemaphore(const QString key, int initialValue, QSystemSemaphore::AccessMode mode) : QSystemSemaphore(key, initialValue, mode)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQSystemSemaphore();
}

KQSystemSemaphore::~KQSystemSemaphore()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QSystemSemaphore_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSystemSemaphore *qp = RawPtr_to(KQSystemSemaphore *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSystemSemaphore]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSystemSemaphore]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSystemSemaphore_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSystemSemaphore *qp = RawPtr_to(KQSystemSemaphore *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSystemSemaphore]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSystemSemaphore]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSystemSemaphore_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQSystemSemaphore *qp = (KQSystemSemaphore *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QSystemSemaphore*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QSystemSemaphore_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQSystemSemaphore *qp = (KQSystemSemaphore *)p->rawptr;
		KQSystemSemaphore *qp = static_cast<KQSystemSemaphore*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSystemSemaphore_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSystemSemaphore::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QSystemSemaphoreConstInt[] = {
	{"Open", QSystemSemaphore::Open},
	{"Create", QSystemSemaphore::Create},
	{"NoError", QSystemSemaphore::NoError},
	{"PermissionDenied", QSystemSemaphore::PermissionDenied},
	{"KeyError", QSystemSemaphore::KeyError},
	{"AlreadyExists", QSystemSemaphore::AlreadyExists},
	{"NotFound", QSystemSemaphore::NotFound},
	{"OutOfResources", QSystemSemaphore::OutOfResources},
	{"UnknownError", QSystemSemaphore::UnknownError},
	{NULL, 0}
};

DEFAPI(void) constQSystemSemaphore(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QSystemSemaphoreConstInt);
}


DEFAPI(void) defQSystemSemaphore(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSystemSemaphore";
	cdef->free = QSystemSemaphore_free;
	cdef->reftrace = QSystemSemaphore_reftrace;
	cdef->compareTo = QSystemSemaphore_compareTo;
}


