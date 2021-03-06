//QDateTime QDateTime.new();
KMETHOD QDateTime_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDateTime *ret_v = new KQDateTime();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QDateTime QDateTime.new(QDate date);
KMETHOD QDateTime_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QDate  date = *RawPtr_to(const QDate *, sfp[1]);
	KQDateTime *ret_v = new KQDateTime(date);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QDateTime QDateTime.new(QDate date, QTime time, int spec);
KMETHOD QDateTime_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QDate  date = *RawPtr_to(const QDate *, sfp[1]);
	const QTime  time = *RawPtr_to(const QTime *, sfp[2]);
	Qt::TimeSpec spec = Int_to(Qt::TimeSpec, sfp[3]);
	KQDateTime *ret_v = new KQDateTime(date, time, spec);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QDateTime QDateTime.new(QDateTime other);
KMETHOD QDateTime_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QDateTime  other = *RawPtr_to(const QDateTime *, sfp[1]);
	KQDateTime *ret_v = new KQDateTime(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QDateTime QDateTime.addDays(int ndays);
KMETHOD QDateTime_addDays(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		int ndays = Int_to(int, sfp[1]);
		QDateTime ret_v = qp->addDays(ndays);
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QDateTime.addMSecs(int msecs);
KMETHOD QDateTime_addMSecs(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		qint64 msecs = Int_to(qint64, sfp[1]);
		QDateTime ret_v = qp->addMSecs(msecs);
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QDateTime.addMonths(int nmonths);
KMETHOD QDateTime_addMonths(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		int nmonths = Int_to(int, sfp[1]);
		QDateTime ret_v = qp->addMonths(nmonths);
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QDateTime.addSecs(int s);
KMETHOD QDateTime_addSecs(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		int s = Int_to(int, sfp[1]);
		QDateTime ret_v = qp->addSecs(s);
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QDateTime.addYears(int nyears);
KMETHOD QDateTime_addYears(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		int nyears = Int_to(int, sfp[1]);
		QDateTime ret_v = qp->addYears(nyears);
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDate QDateTime.getDate();
KMETHOD QDateTime_getDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		QDate ret_v = qp->date();
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDateTime.daysTo(QDateTime other);
KMETHOD QDateTime_daysTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		const QDateTime  other = *RawPtr_to(const QDateTime *, sfp[1]);
		int ret_v = qp->daysTo(other);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDateTime.msecsTo(QDateTime other);
KMETHOD QDateTime_msecsTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		const QDateTime  other = *RawPtr_to(const QDateTime *, sfp[1]);
		qint64 ret_v = qp->msecsTo(other);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDateTime.secsTo(QDateTime other);
KMETHOD QDateTime_secsTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		const QDateTime  other = *RawPtr_to(const QDateTime *, sfp[1]);
		int ret_v = qp->secsTo(other);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QDateTime.setDate(QDate date);
KMETHOD QDateTime_setDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		const QDate  date = *RawPtr_to(const QDate *, sfp[1]);
		qp->setDate(date);
	}
	RETURNvoid_();
}

//void QDateTime.setMSecsSinceEpoch(int msecs);
KMETHOD QDateTime_setMSecsSinceEpoch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		qint64 msecs = Int_to(qint64, sfp[1]);
		qp->setMSecsSinceEpoch(msecs);
	}
	RETURNvoid_();
}

//void QDateTime.setTime(QTime time);
KMETHOD QDateTime_setTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		const QTime  time = *RawPtr_to(const QTime *, sfp[1]);
		qp->setTime(time);
	}
	RETURNvoid_();
}

//void QDateTime.setTimeSpec(int spec);
KMETHOD QDateTime_setTimeSpec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		Qt::TimeSpec spec = Int_to(Qt::TimeSpec, sfp[1]);
		qp->setTimeSpec(spec);
	}
	RETURNvoid_();
}

//void QDateTime.setTime_t(int seconds);
KMETHOD QDateTime_setTime_t(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		uint  seconds = *RawPtr_to(uint *, sfp[1]);
		qp->setTime_t(seconds);
	}
	RETURNvoid_();
}

//QTime QDateTime.getTime();
KMETHOD QDateTime_getTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		QTime ret_v = qp->time();
		QTime *ret_v_ = new QTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDateTime.getTimeSpec();
KMETHOD QDateTime_getTimeSpec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		Qt::TimeSpec ret_v = qp->timeSpec();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QDateTime QDateTime.toLocalTime();
KMETHOD QDateTime_toLocalTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		QDateTime ret_v = qp->toLocalTime();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDateTime.toMSecsSinceEpoch();
KMETHOD QDateTime_toMSecsSinceEpoch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->toMSecsSinceEpoch();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDateTime.toString(String fmt);
KMETHOD QDateTime_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		const QString format = String_to(const QString, sfp[1]);
		QString ret_v = qp->toString(format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QDateTime.toString(int fmt);
KMETHOD QDateTime_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		Qt::DateFormat format = Int_to(Qt::DateFormat, sfp[1]);
		QString ret_v = qp->toString(format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QDateTime QDateTime.toTimeSpec(int specification);
KMETHOD QDateTime_toTimeSpec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		Qt::TimeSpec specification = Int_to(Qt::TimeSpec, sfp[1]);
		QDateTime ret_v = qp->toTimeSpec(specification);
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDateTime.toTime_t();
KMETHOD QDateTime_toTime_t(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		uint ret_v = qp->toTime_t();
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QDateTime.toUTC();
KMETHOD QDateTime_toUTC(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *  qp = RawPtr_to(QDateTime *, sfp[0]);
	if (qp) {
		QDateTime ret_v = qp->toUTC();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QDateTime.currentDateTime();
KMETHOD QDateTime_currentDateTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QDateTime ret_v = QDateTime::currentDateTime();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QDateTime.currentDateTimeUtc();
KMETHOD QDateTime_currentDateTimeUtc(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QDateTime ret_v = QDateTime::currentDateTimeUtc();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDateTime.currentMSecsSinceEpoch();
KMETHOD QDateTime_currentMSecsSinceEpoch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qint64 ret_v = QDateTime::currentMSecsSinceEpoch();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QDateTime.fromMSecsSinceEpoch(int msecs);
KMETHOD QDateTime_fromMSecsSinceEpoch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qint64 msecs = Int_to(qint64, sfp[1]);
		QDateTime ret_v = QDateTime::fromMSecsSinceEpoch(msecs);
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QDateTime.fromString(String str, int fmt);
KMETHOD QDateTime_fromString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString string = String_to(const QString, sfp[1]);
		Qt::DateFormat format = Int_to(Qt::DateFormat, sfp[2]);
		QDateTime ret_v = QDateTime::fromString(string, format);
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QDateTime QDateTime.fromString(String str, String fmt);
KMETHOD QDateTime_fromString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString string = String_to(const QString, sfp[1]);
		const QString format = String_to(const QString, sfp[2]);
		QDateTime ret_v = QDateTime::fromString(string, format);
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QDateTime QDateTime.fromTime_t(int seconds);
KMETHOD QDateTime_fromTime_t(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		uint  seconds = *RawPtr_to(uint *, sfp[1]);
		QDateTime ret_v = QDateTime::fromTime_t(seconds);
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QDateTime.parents();
KMETHOD QDateTime_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTime *qp = RawPtr_to(QDateTime*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQDateTime::DummyQDateTime()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQDateTime::~DummyQDateTime()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQDateTime::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDateTime::self = ptr;
}

bool DummyQDateTime::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQDateTime::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDateTime::event_map->bigin();
	if ((itr = DummyQDateTime::event_map->find(str)) == DummyQDateTime::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDateTime::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDateTime::slot_map->bigin();
	if ((itr = DummyQDateTime::slot_map->find(str)) == DummyQDateTime::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQDateTime::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQDateTime::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQDateTime::connection(QObject *o)
{
	QDateTime *p = dynamic_cast<QDateTime*>(o);
	if (p != NULL) {
	}
}

KQDateTime::KQDateTime() : QDateTime()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQDateTime();
}

KQDateTime::~KQDateTime()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QDateTime_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDateTime *qp = RawPtr_to(KQDateTime *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDateTime]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDateTime]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDateTime_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDateTime *qp = RawPtr_to(KQDateTime *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDateTime]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDateTime]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDateTime_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQDateTime *qp = (KQDateTime *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QDateTime*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QDateTime_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQDateTime *qp = (KQDateTime *)p->rawptr;
		KQDateTime *qp = static_cast<KQDateTime*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QDateTime_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QDateTime*>(p1->rawptr) == *static_cast<QDateTime*>(p2->rawptr) ? 0 : 1);
}

void KQDateTime::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQDateTime(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDateTime";
	cdef->free = QDateTime_free;
	cdef->reftrace = QDateTime_reftrace;
	cdef->compareTo = QDateTime_compareTo;
}


