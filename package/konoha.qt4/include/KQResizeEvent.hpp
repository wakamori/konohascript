#ifndef QRESIZEEVENT
#define QRESIZEEVENT
class DummyQResizeEvent : public DummyQEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQResizeEvent();
	virtual ~DummyQResizeEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQResizeEvent : public QResizeEvent {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQResizeEvent *dummy;
	KQResizeEvent(const QSize size, const QSize oldSize);
	~KQResizeEvent();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QRESIZEEVENT


