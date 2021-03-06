//@Virtual String QAccessibleInterface.actionText(int action, int t, int child);
KMETHOD QAccessibleInterface_actionText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		int action = Int_to(int, sfp[1]);
		QAccessibleInterface::Text t = Int_to(QAccessibleInterface::Text, sfp[2]);
		int child = Int_to(int, sfp[3]);
		QString ret_v = qp->actionText(action, t, child);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QAccessibleInterface.childAt(int x, int y);
KMETHOD QAccessibleInterface_childAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int ret_v = qp->childAt(x, y);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual int QAccessibleInterface.childCount();
KMETHOD QAccessibleInterface_childCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		int ret_v = qp->childCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual boolean QAccessibleInterface.doAction(int action, int child, QVariantList params);
KMETHOD QAccessibleInterface_doAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		int action = Int_to(int, sfp[1]);
		int child = Int_to(int, sfp[2]);
		const QVariantList  params = *RawPtr_to(const QVariantList *, sfp[3]);
		bool ret_v = qp->doAction(action, child, params);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual int QAccessibleInterface.indexOfChild(QAccessibleInterface child);
KMETHOD QAccessibleInterface_indexOfChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		const QAccessibleInterface*  child = RawPtr_to(const QAccessibleInterface*, sfp[1]);
		int ret_v = qp->indexOfChild(child);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QVariant QAccessibleInterface.invokeMethod(int method, int child, QVariantList params);
KMETHOD QAccessibleInterface_invokeMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		QAccessibleInterface::Method method = Int_to(QAccessibleInterface::Method, sfp[1]);
		int child = Int_to(int, sfp[2]);
		const QVariantList  params = *RawPtr_to(const QVariantList *, sfp[3]);
		QVariant ret_v = qp->invokeMethod(method, child, params);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QAccessibleInterface.navigate(int relation, int entry, QAccessibleInterface target);
KMETHOD QAccessibleInterface_navigate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		QAccessibleInterface::RelationFlag relation = Int_to(QAccessibleInterface::RelationFlag, sfp[1]);
		int entry = Int_to(int, sfp[2]);
		QAccessibleInterface**  target = RawPtr_to(QAccessibleInterface**, sfp[3]);
		int ret_v = qp->navigate(relation, entry, target);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QObject QAccessibleInterface.object();
KMETHOD QAccessibleInterface_object(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		QObject* ret_v = qp->object();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QRect QAccessibleInterface.rect(int child);
KMETHOD QAccessibleInterface_rect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		int child = Int_to(int, sfp[1]);
		QRect ret_v = qp->rect(child);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QAccessibleRelation QAccessibleInterface.relationTo(int child, QAccessibleInterface other, int otherChild);
KMETHOD QAccessibleInterface_relationTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		int child = Int_to(int, sfp[1]);
		const QAccessibleInterface*  other = RawPtr_to(const QAccessibleInterface*, sfp[2]);
		int otherChild = Int_to(int, sfp[3]);
		QAccessible::Relation ret_v = qp->relationTo(child, other, otherChild);
		QAccessible::Relation *ret_v_ = new QAccessible::Relation(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QAccessibleInterface.role(int child);
KMETHOD QAccessibleInterface_role(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		int child = Int_to(int, sfp[1]);
		QAccessibleInterface::Role ret_v = qp->role(child);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual void QAccessibleInterface.setText(int t, int child, String text);
KMETHOD QAccessibleInterface_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		QAccessibleInterface::Text t = Int_to(QAccessibleInterface::Text, sfp[1]);
		int child = Int_to(int, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		qp->setText(t, child, text);
	}
	RETURNvoid_();
}

//@Virtual QAccessibleState QAccessibleInterface.state(int child);
KMETHOD QAccessibleInterface_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		int child = Int_to(int, sfp[1]);
		QAccessible::State ret_v = qp->state(child);
		QAccessible::State *ret_v_ = new QAccessible::State(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual String QAccessibleInterface.getText(int t, int child);
KMETHOD QAccessibleInterface_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		QAccessibleInterface::Text t = Int_to(QAccessibleInterface::Text, sfp[1]);
		int child = Int_to(int, sfp[2]);
		QString ret_v = qp->text(t, child);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QAccessibleInterface.userActionCount(int child);
KMETHOD QAccessibleInterface_userActionCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleInterface *  qp = RawPtr_to(QAccessibleInterface *, sfp[0]);
	if (qp) {
		int child = Int_to(int, sfp[1]);
		int ret_v = qp->userActionCount(child);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQAccessibleInterface::DummyQAccessibleInterface()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQAccessibleInterface::~DummyQAccessibleInterface()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQAccessibleInterface::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAccessibleInterface::self = ptr;
	DummyQAccessible::setSelf(ptr);
}

bool DummyQAccessibleInterface::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAccessible::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAccessibleInterface::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAccessibleInterface::event_map->bigin();
	if ((itr = DummyQAccessibleInterface::event_map->find(str)) == DummyQAccessibleInterface::event_map->end()) {
		bool ret = false;
		ret = DummyQAccessible::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAccessibleInterface::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAccessibleInterface::slot_map->bigin();
	if ((itr = DummyQAccessibleInterface::slot_map->find(str)) == DummyQAccessibleInterface::slot_map->end()) {
		bool ret = false;
		ret = DummyQAccessible::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQAccessibleInterface::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAccessibleInterface::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAccessible::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQAccessibleInterface::connection(QObject *o)
{
	QAccessibleInterface *p = dynamic_cast<QAccessibleInterface*>(o);
	if (p != NULL) {
	}
	DummyQAccessible::connection(o);
}

KQAccessibleInterface::~KQAccessibleInterface()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QAccessibleInterface_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAccessibleInterface *qp = RawPtr_to(KQAccessibleInterface *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAccessibleInterface]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAccessibleInterface]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAccessibleInterface_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAccessibleInterface *qp = RawPtr_to(KQAccessibleInterface *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAccessibleInterface]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAccessibleInterface]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAccessibleInterface_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQAccessibleInterface *qp = (KQAccessibleInterface *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QAccessibleInterface*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QAccessibleInterface_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQAccessibleInterface *qp = (KQAccessibleInterface *)p->rawptr;
		KQAccessibleInterface *qp = static_cast<KQAccessibleInterface*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAccessibleInterface_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAccessibleInterface::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQAccessibleInterface(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAccessibleInterface";
	cdef->free = QAccessibleInterface_free;
	cdef->reftrace = QAccessibleInterface_reftrace;
	cdef->compareTo = QAccessibleInterface_compareTo;
}


