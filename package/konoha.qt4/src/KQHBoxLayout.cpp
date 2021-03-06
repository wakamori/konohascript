//QHBoxLayout QHBoxLayout.new();
KMETHOD QHBoxLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHBoxLayout *ret_v = new KQHBoxLayout();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QHBoxLayout QHBoxLayout.new(QWidget parent);
KMETHOD QHBoxLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQHBoxLayout *ret_v = new KQHBoxLayout(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQHBoxLayout::DummyQHBoxLayout()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQHBoxLayout::~DummyQHBoxLayout()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQHBoxLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQHBoxLayout::self = ptr;
	DummyQBoxLayout::setSelf(ptr);
}

bool DummyQHBoxLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQBoxLayout::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQHBoxLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHBoxLayout::event_map->bigin();
	if ((itr = DummyQHBoxLayout::event_map->find(str)) == DummyQHBoxLayout::event_map->end()) {
		bool ret = false;
		ret = DummyQBoxLayout::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQHBoxLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHBoxLayout::slot_map->bigin();
	if ((itr = DummyQHBoxLayout::slot_map->find(str)) == DummyQHBoxLayout::slot_map->end()) {
		bool ret = false;
		ret = DummyQBoxLayout::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQHBoxLayout::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQHBoxLayout::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQBoxLayout::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQHBoxLayout::connection(QObject *o)
{
	QHBoxLayout *p = dynamic_cast<QHBoxLayout*>(o);
	if (p != NULL) {
	}
	DummyQBoxLayout::connection(o);
}

KQHBoxLayout::KQHBoxLayout() : QHBoxLayout()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQHBoxLayout();
	dummy->connection((QObject*)this);
}

KQHBoxLayout::~KQHBoxLayout()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QHBoxLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHBoxLayout *qp = RawPtr_to(KQHBoxLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QHBoxLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHBoxLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QHBoxLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHBoxLayout *qp = RawPtr_to(KQHBoxLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QHBoxLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHBoxLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QHBoxLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQHBoxLayout *qp = (KQHBoxLayout *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QHBoxLayout*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QHBoxLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQHBoxLayout *qp = (KQHBoxLayout *)p->rawptr;
		KQHBoxLayout *qp = static_cast<KQHBoxLayout*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QHBoxLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQHBoxLayout::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQHBoxLayout::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QHBoxLayout::event(event);
		return false;
	}
//	QHBoxLayout::event(event);
	return true;
}



DEFAPI(void) defQHBoxLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QHBoxLayout";
	cdef->free = QHBoxLayout_free;
	cdef->reftrace = QHBoxLayout_reftrace;
	cdef->compareTo = QHBoxLayout_compareTo;
}


