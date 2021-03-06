#ifndef QGRAPHICSBLUREFFECT
#define QGRAPHICSBLUREFFECT
class DummyQGraphicsBlurEffect : public DummyQGraphicsEffect {
	Q_OBJECT;
public:
	typedef QGraphicsBlurEffect::BlurHints BlurHints;
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *blur_hints_changed_func;
	knh_Func_t *blur_radius_changed_func;
	DummyQGraphicsBlurEffect();
	virtual ~DummyQGraphicsBlurEffect();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool blurHintsChangedSlot(BlurHints hints);
	bool blurRadiusChangedSlot(qreal radius);
};

class KQGraphicsBlurEffect : public QGraphicsBlurEffect {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQGraphicsBlurEffect *dummy;
	KQGraphicsBlurEffect(QObject* parent);
	~KQGraphicsBlurEffect();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QGRAPHICSBLUREFFECT


