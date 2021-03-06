//QStateMachine QAbstractState.machine();
KMETHOD QAbstractState_machine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractState *  qp = RawPtr_to(QAbstractState *, sfp[0]);
	if (qp) {
		QStateMachine* ret_v = qp->machine();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStateMachine*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QState QAbstractState.parentState();
KMETHOD QAbstractState_parentState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractState *  qp = RawPtr_to(QAbstractState *, sfp[0]);
	if (qp) {
		QState* ret_v = qp->parentState();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QState*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQAbstractState::DummyQAbstractState()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	entered_func = NULL;
	exited_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("entered", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("exited", NULL));
}
DummyQAbstractState::~DummyQAbstractState()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQAbstractState::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractState::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQAbstractState::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractState::enteredSlot()
{
	if (entered_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, entered_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractState::exitedSlot()
{
	if (exited_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, exited_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractState::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractState::event_map->bigin();
	if ((itr = DummyQAbstractState::event_map->find(str)) == DummyQAbstractState::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractState::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractState::slot_map->bigin();
	if ((itr = DummyQAbstractState::slot_map->find(str)) == DummyQAbstractState::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		entered_func = (*slot_map)["entered"];
		exited_func = (*slot_map)["exited"];
		return true;
	}
}

knh_Object_t** DummyQAbstractState::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAbstractState::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 3;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, entered_func);
	KNH_ADDNNREF(ctx, exited_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQAbstractState::connection(QObject *o)
{
	QAbstractState *p = dynamic_cast<QAbstractState*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(entered()), this, SLOT(enteredSlot()));
		connect(p, SIGNAL(exited()), this, SLOT(exitedSlot()));
	}
	DummyQObject::connection(o);
}

KQAbstractState::~KQAbstractState()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QAbstractState_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractState *qp = RawPtr_to(KQAbstractState *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractState]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractState]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractState_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractState *qp = RawPtr_to(KQAbstractState *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractState]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractState]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractState_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQAbstractState *qp = (KQAbstractState *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QAbstractState*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QAbstractState_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQAbstractState *qp = (KQAbstractState *)p->rawptr;
		KQAbstractState *qp = static_cast<KQAbstractState*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractState_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractState::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractState::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractState::event(event);
		return false;
	}
//	QAbstractState::event(event);
	return true;
}



DEFAPI(void) defQAbstractState(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractState";
	cdef->free = QAbstractState_free;
	cdef->reftrace = QAbstractState_reftrace;
	cdef->compareTo = QAbstractState_compareTo;
}


