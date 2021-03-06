//@Virtual @Override QRectF QGraphicsDropShadowEffect.boundingRectFor(QRectF rect);
KMETHOD QGraphicsDropShadowEffect_boundingRectFor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QRectF ret_v = qp->boundingRectFor(rect);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsDropShadowEffect QGraphicsDropShadowEffect.new(QObject parent);
KMETHOD QGraphicsDropShadowEffect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQGraphicsDropShadowEffect *ret_v = new KQGraphicsDropShadowEffect(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//float QGraphicsDropShadowEffect.getBlurRadius();
KMETHOD QGraphicsDropShadowEffect_getBlurRadius(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->blurRadius();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QColor QGraphicsDropShadowEffect.getColor();
KMETHOD QGraphicsDropShadowEffect_getColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp) {
		QColor ret_v = qp->color();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QGraphicsDropShadowEffect.offset();
KMETHOD QGraphicsDropShadowEffect_offset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->offset();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsDropShadowEffect.xOffset();
KMETHOD QGraphicsDropShadowEffect_xOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->xOffset();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsDropShadowEffect.yOffset();
KMETHOD QGraphicsDropShadowEffect_yOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->yOffset();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QGraphicsDropShadowEffect.setBlurRadius(float blurRadius);
KMETHOD QGraphicsDropShadowEffect_setBlurRadius(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp) {
		qreal blurRadius = Float_to(qreal, sfp[1]);
		qp->setBlurRadius(blurRadius);
	}
	RETURNvoid_();
}

//void QGraphicsDropShadowEffect.setColor(QColor color);
KMETHOD QGraphicsDropShadowEffect_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp) {
		const QColor  color = *RawPtr_to(const QColor *, sfp[1]);
		qp->setColor(color);
	}
	RETURNvoid_();
}

//void QGraphicsDropShadowEffect.setOffset(QPointF ofs);
KMETHOD QGraphicsDropShadowEffect_setOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp) {
		const QPointF  ofs = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setOffset(ofs);
	}
	RETURNvoid_();
}

/*
//void QGraphicsDropShadowEffect.setOffset(float dx, float dy);
KMETHOD QGraphicsDropShadowEffect_setOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		qp->setOffset(dx, dy);
	}
	RETURNvoid_();
}
*/
/*
//void QGraphicsDropShadowEffect.setOffset(float d);
KMETHOD QGraphicsDropShadowEffect_setOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp) {
		qreal d = Float_to(qreal, sfp[1]);
		qp->setOffset(d);
	}
	RETURNvoid_();
}
*/
//void QGraphicsDropShadowEffect.setXOffset(float dx);
KMETHOD QGraphicsDropShadowEffect_setXOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp) {
		qreal dx = Float_to(qreal, sfp[1]);
		qp->setXOffset(dx);
	}
	RETURNvoid_();
}

//void QGraphicsDropShadowEffect.setYOffset(float dy);
KMETHOD QGraphicsDropShadowEffect_setYOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp) {
		qreal dy = Float_to(qreal, sfp[1]);
		qp->setYOffset(dy);
	}
	RETURNvoid_();
}


DummyQGraphicsDropShadowEffect::DummyQGraphicsDropShadowEffect()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	blur_radius_changed_func = NULL;
	color_changed_func = NULL;
	offset_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("blur-radius-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("color-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("offset-changed", NULL));
}
DummyQGraphicsDropShadowEffect::~DummyQGraphicsDropShadowEffect()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGraphicsDropShadowEffect::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsDropShadowEffect::self = ptr;
	DummyQGraphicsEffect::setSelf(ptr);
}

bool DummyQGraphicsDropShadowEffect::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsEffect::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsDropShadowEffect::blurRadiusChangedSlot(qreal blurRadius)
{
	if (blur_radius_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].fvalue = blurRadius;
		knh_Func_invoke(lctx, blur_radius_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsDropShadowEffect::colorChangedSlot(const QColor color)
{
	if (color_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QColor, color);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, color_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsDropShadowEffect::offsetChangedSlot(const QPointF offset)
{
	if (offset_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QPointF, offset);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, offset_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsDropShadowEffect::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsDropShadowEffect::event_map->bigin();
	if ((itr = DummyQGraphicsDropShadowEffect::event_map->find(str)) == DummyQGraphicsDropShadowEffect::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsEffect::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsDropShadowEffect::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsDropShadowEffect::slot_map->bigin();
	if ((itr = DummyQGraphicsDropShadowEffect::slot_map->find(str)) == DummyQGraphicsDropShadowEffect::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsEffect::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		blur_radius_changed_func = (*slot_map)["blur-radius-changed"];
		color_changed_func = (*slot_map)["color-changed"];
		offset_changed_func = (*slot_map)["offset-changed"];
		return true;
	}
}

knh_Object_t** DummyQGraphicsDropShadowEffect::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsDropShadowEffect::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 4;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, blur_radius_changed_func);
	KNH_ADDNNREF(ctx, color_changed_func);
	KNH_ADDNNREF(ctx, offset_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQGraphicsEffect::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsDropShadowEffect::connection(QObject *o)
{
	QGraphicsDropShadowEffect *p = dynamic_cast<QGraphicsDropShadowEffect*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(blurRadiusChanged(qreal)), this, SLOT(blurRadiusChangedSlot(qreal)));
		connect(p, SIGNAL(colorChanged(const QColor)), this, SLOT(colorChangedSlot(const QColor)));
		connect(p, SIGNAL(offsetChanged(const QPointF)), this, SLOT(offsetChangedSlot(const QPointF)));
	}
	DummyQGraphicsEffect::connection(o);
}

KQGraphicsDropShadowEffect::KQGraphicsDropShadowEffect(QObject* parent) : QGraphicsDropShadowEffect(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQGraphicsDropShadowEffect();
	dummy->connection((QObject*)this);
}

KQGraphicsDropShadowEffect::~KQGraphicsDropShadowEffect()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGraphicsDropShadowEffect_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsDropShadowEffect *qp = RawPtr_to(KQGraphicsDropShadowEffect *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsDropShadowEffect]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsDropShadowEffect]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsDropShadowEffect_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsDropShadowEffect *qp = RawPtr_to(KQGraphicsDropShadowEffect *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsDropShadowEffect]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsDropShadowEffect]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsDropShadowEffect_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGraphicsDropShadowEffect *qp = (KQGraphicsDropShadowEffect *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGraphicsDropShadowEffect*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGraphicsDropShadowEffect_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGraphicsDropShadowEffect *qp = (KQGraphicsDropShadowEffect *)p->rawptr;
		KQGraphicsDropShadowEffect *qp = static_cast<KQGraphicsDropShadowEffect*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsDropShadowEffect_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsDropShadowEffect::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsDropShadowEffect::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsDropShadowEffect::event(event);
		return false;
	}
//	QGraphicsDropShadowEffect::event(event);
	return true;
}



DEFAPI(void) defQGraphicsDropShadowEffect(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsDropShadowEffect";
	cdef->free = QGraphicsDropShadowEffect_free;
	cdef->reftrace = QGraphicsDropShadowEffect_reftrace;
	cdef->compareTo = QGraphicsDropShadowEffect_compareTo;
}


