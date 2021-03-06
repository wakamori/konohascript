//QTextFragment QTextFragment.new();
KMETHOD QTextFragment_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextFragment *ret_v = new KQTextFragment();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextFragment QTextFragment.new(QTextFragment other);
KMETHOD QTextFragment_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextFragment  other = *RawPtr_to(const QTextFragment *, sfp[1]);
	KQTextFragment *ret_v = new KQTextFragment(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QTextCharFormat QTextFragment.charFormat();
KMETHOD QTextFragment_charFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFragment *  qp = RawPtr_to(QTextFragment *, sfp[0]);
	if (qp) {
		QTextCharFormat ret_v = qp->charFormat();
		QTextCharFormat *ret_v_ = new QTextCharFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextFragment.charFormatIndex();
KMETHOD QTextFragment_charFormatIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFragment *  qp = RawPtr_to(QTextFragment *, sfp[0]);
	if (qp) {
		int ret_v = qp->charFormatIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTextFragment.contains(int position);
KMETHOD QTextFragment_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFragment *  qp = RawPtr_to(QTextFragment *, sfp[0]);
	if (qp) {
		int position = Int_to(int, sfp[1]);
		bool ret_v = qp->contains(position);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTextFragment.length();
KMETHOD QTextFragment_length(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFragment *  qp = RawPtr_to(QTextFragment *, sfp[0]);
	if (qp) {
		int ret_v = qp->length();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextFragment.position();
KMETHOD QTextFragment_position(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFragment *  qp = RawPtr_to(QTextFragment *, sfp[0]);
	if (qp) {
		int ret_v = qp->position();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QTextFragment.text();
KMETHOD QTextFragment_text(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFragment *  qp = RawPtr_to(QTextFragment *, sfp[0]);
	if (qp) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QTextFragment.parents();
KMETHOD QTextFragment_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFragment *qp = RawPtr_to(QTextFragment*, sfp[0]);
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

DummyQTextFragment::DummyQTextFragment()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTextFragment::~DummyQTextFragment()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQTextFragment::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextFragment::self = ptr;
}

bool DummyQTextFragment::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextFragment::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextFragment::event_map->bigin();
	if ((itr = DummyQTextFragment::event_map->find(str)) == DummyQTextFragment::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextFragment::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextFragment::slot_map->bigin();
	if ((itr = DummyQTextFragment::slot_map->find(str)) == DummyQTextFragment::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTextFragment::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextFragment::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQTextFragment::connection(QObject *o)
{
	QTextFragment *p = dynamic_cast<QTextFragment*>(o);
	if (p != NULL) {
	}
}

KQTextFragment::KQTextFragment() : QTextFragment()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTextFragment();
}

KQTextFragment::~KQTextFragment()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QTextFragment_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextFragment *qp = RawPtr_to(KQTextFragment *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextFragment]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextFragment]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextFragment_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextFragment *qp = RawPtr_to(KQTextFragment *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextFragment]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextFragment]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextFragment_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTextFragment *qp = (KQTextFragment *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTextFragment*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTextFragment_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTextFragment *qp = (KQTextFragment *)p->rawptr;
		KQTextFragment *qp = static_cast<KQTextFragment*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextFragment_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QTextFragment*>(p1->rawptr) == *static_cast<QTextFragment*>(p2->rawptr) ? 0 : 1);
}

void KQTextFragment::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQTextFragment(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextFragment";
	cdef->free = QTextFragment_free;
	cdef->reftrace = QTextFragment_reftrace;
	cdef->compareTo = QTextFragment_compareTo;
}


