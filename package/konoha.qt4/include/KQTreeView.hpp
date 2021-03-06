#ifndef QTREEVIEW
#define QTREEVIEW
class DummyQTreeView : public DummyQAbstractItemView {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *collapsed_func;
	knh_Func_t *expanded_func;
	DummyQTreeView();
	virtual ~DummyQTreeView();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool collapsedSlot(const QModelIndex index);
	bool expandedSlot(const QModelIndex index);
};

class KQTreeView : public QTreeView {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQTreeView *dummy;
	KQTreeView(QWidget* parent);
	~KQTreeView();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QTREEVIEW


