#ifndef QWIZARD
#define QWIZARD
class DummyQWizard : public DummyQDialog {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *current_id_changed_func;
	knh_Func_t *custom_button_clicked_func;
	knh_Func_t *help_requested_func;
	knh_Func_t *page_added_func;
	knh_Func_t *page_removed_func;
	DummyQWizard();
	virtual ~DummyQWizard();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool currentIdChangedSlot(int id);
	bool customButtonClickedSlot(int which);
	bool helpRequestedSlot();
	bool pageAddedSlot(int id);
	bool pageRemovedSlot(int id);
};

class KQWizard : public QWizard {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQWizard *dummy;
	KQWizard(QWidget* parent, Qt::WindowFlags flags);
	~KQWizard();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QWIZARD


