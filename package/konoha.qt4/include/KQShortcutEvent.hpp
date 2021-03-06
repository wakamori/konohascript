#ifndef QSHORTCUTEVENT
#define QSHORTCUTEVENT
class DummyQShortcutEvent : public DummyQEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQShortcutEvent();
	virtual ~DummyQShortcutEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQShortcutEvent : public QShortcutEvent {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQShortcutEvent *dummy;
	KQShortcutEvent(const QKeySequence key, int id, bool ambiguous);
	~KQShortcutEvent();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSHORTCUTEVENT


