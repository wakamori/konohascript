#ifndef QPROXYSTYLE
#define QPROXYSTYLE
class DummyQProxyStyle : public DummyQCommonStyle {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQProxyStyle();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQProxyStyle : public QProxyStyle {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQProxyStyle *dummy;
	KQProxyStyle(QStyle* style);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QPROXYSTYLE

