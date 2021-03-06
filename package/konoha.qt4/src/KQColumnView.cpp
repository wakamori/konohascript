//@Virtual @Override QModelIndex QColumnView.indexAt(QPoint point);
KMETHOD QColumnView_indexAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		QModelIndex ret_v = qp->indexAt(point);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QColumnView.scrollTo(QModelIndex index, int hint);
KMETHOD QColumnView_scrollTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QColumnView::ScrollHint hint = Int_to(QColumnView::ScrollHint, sfp[2]);
		qp->scrollTo(index, hint);
	}
	RETURNvoid_();
}

//@Virtual @Override void QColumnView.selectAll();
KMETHOD QColumnView_selectAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		qp->selectAll();
	}
	RETURNvoid_();
}

//@Virtual @Override void QColumnView.setModel(QAbstractItemModel model);
KMETHOD QColumnView_setModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[1]);
		qp->setModel(model);
	}
	RETURNvoid_();
}

//@Virtual @Override void QColumnView.setRootIndex(QModelIndex index);
KMETHOD QColumnView_setRootIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->setRootIndex(index);
	}
	RETURNvoid_();
}

//@Virtual @Override void QColumnView.setSelectionModel(QItemSelectionModel new_SelectionModel);
KMETHOD QColumnView_setSelectionModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		QItemSelectionModel*  new_SelectionModel = RawPtr_to(QItemSelectionModel*, sfp[1]);
		qp->setSelectionModel(new_SelectionModel);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QColumnView.sizeHint();
KMETHOD QColumnView_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QRect QColumnView.visualRect(QModelIndex index);
KMETHOD QColumnView_visualRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QRect ret_v = qp->visualRect(index);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColumnView QColumnView.new(QWidget parent);
KMETHOD QColumnView_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQColumnView *ret_v = new KQColumnView(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//Array<int> QColumnView.getColumnWidths();
KMETHOD QColumnView_getColumnWidths(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		QList<int> ret_v = qp->columnWidths();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("int"));
		for (int n = 0; n < list_size; n++) {
			int *ret_v_ = new int(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QWidget QColumnView.getPreviewWidget();
KMETHOD QColumnView_getPreviewWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->previewWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QColumnView.getResizeGripsVisible();
KMETHOD QColumnView_getResizeGripsVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->resizeGripsVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QColumnView.setColumnWidths(Array<int> list);
KMETHOD QColumnView_setColumnWidths(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<int> list;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			list.append(*(int*)p->rawptr);
		}
		qp->setColumnWidths(list);
	}
	RETURNvoid_();
}

//void QColumnView.setPreviewWidget(QWidget widget);
KMETHOD QColumnView_setPreviewWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setPreviewWidget(widget);
	}
	RETURNvoid_();
}

//void QColumnView.setResizeGripsVisible(boolean visible);
KMETHOD QColumnView_setResizeGripsVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setResizeGripsVisible(visible);
	}
	RETURNvoid_();
}


DummyQColumnView::DummyQColumnView()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	update_preview_widget_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("update-preview-widget", NULL));
}
DummyQColumnView::~DummyQColumnView()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQColumnView::setSelf(knh_RawPtr_t *ptr)
{
	DummyQColumnView::self = ptr;
	DummyQAbstractItemView::setSelf(ptr);
}

bool DummyQColumnView::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractItemView::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQColumnView::updatePreviewWidgetSlot(const QModelIndex index)
{
	if (update_preview_widget_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, index);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, update_preview_widget_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQColumnView::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQColumnView::event_map->bigin();
	if ((itr = DummyQColumnView::event_map->find(str)) == DummyQColumnView::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemView::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQColumnView::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQColumnView::slot_map->bigin();
	if ((itr = DummyQColumnView::slot_map->find(str)) == DummyQColumnView::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemView::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		update_preview_widget_func = (*slot_map)["update-preview-widget"];
		return true;
	}
}

knh_Object_t** DummyQColumnView::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQColumnView::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, update_preview_widget_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQAbstractItemView::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQColumnView::connection(QObject *o)
{
	QColumnView *p = dynamic_cast<QColumnView*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(updatePreviewWidget(const QModelIndex)), this, SLOT(updatePreviewWidgetSlot(const QModelIndex)));
	}
	DummyQAbstractItemView::connection(o);
}

KQColumnView::KQColumnView(QWidget* parent) : QColumnView(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQColumnView();
	dummy->connection((QObject*)this);
}

KQColumnView::~KQColumnView()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QColumnView_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQColumnView *qp = RawPtr_to(KQColumnView *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QColumnView]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QColumnView]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QColumnView_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQColumnView *qp = RawPtr_to(KQColumnView *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QColumnView]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QColumnView]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QColumnView_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQColumnView *qp = (KQColumnView *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QColumnView*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QColumnView_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQColumnView *qp = (KQColumnView *)p->rawptr;
		KQColumnView *qp = static_cast<KQColumnView*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QColumnView_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQColumnView::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQColumnView::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QColumnView::event(event);
		return false;
	}
//	QColumnView::event(event);
	return true;
}



DEFAPI(void) defQColumnView(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QColumnView";
	cdef->free = QColumnView_free;
	cdef->reftrace = QColumnView_reftrace;
	cdef->compareTo = QColumnView_compareTo;
}


