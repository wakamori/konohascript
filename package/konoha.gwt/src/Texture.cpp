#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void KTexture::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_press_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p1 = new_RawPtrFromClass(Texture, this);
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p1));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_press_func, lsfp, 2/*argc*/);
	}
}

void KTexture::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_move_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p1 = new_RawPtrFromClass(Texture, this);
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p1));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_move_func, lsfp, 2/*argc*/);
	}
}

void KTexture::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_release_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p1 = new_RawPtrFromClass(Texture, this);
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p1));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_release_func, lsfp, 2/*argc*/);
	}
}

void KTexture::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
	(void)event;
}

#ifdef K_USING_OPENCV
#include <legacy/legacy.hpp>
typedef struct parameter Parameter;
struct parameter {
	float alpha;
	float beta;
	float gamma;
};
void KTexture::setTrackData(const char *filepath)
{
	Parameter snake_param = {0.45, 0.35, 0.2};
	IplImage *src = cvLoadImage(filepath, CV_LOAD_IMAGE_GRAYSCALE);
	IplImage *dst = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 3);
	//cvInitFont(&font, CV_FONT_HERSHEY_DUPLEX, 0.7, 0.7);
	CvPoint center;
	center.x = src->width / 2;
	center.y = src->height / 2;
	int length = 50;
	CvPoint *contour = (CvPoint *)cvAlloc(sizeof(CvPoint) * length);
	for (int i = 0; i < length; i++) {
		contour[i].x = (int)(center.x * cos(2 * CV_PI * i / length) + center.x);
		contour[i].y = (int)(center.y * sin(2 * CV_PI * i / length) + center.y);
	}
	cvCvtColor(src, dst, CV_GRAY2RGB);
	for (int i = 0; i < length - 1; i++) {
		cvLine(dst, contour[i], contour[i + 1], CV_RGB(255, 0, 0), 2, 8, 0);
	}
	for (int i = 0; i < 50; i++) {
		cvSnakeImage(src, contour, length, &snake_param.alpha, &snake_param.beta, &snake_param.gamma,
					 CV_VALUE, cvSize(15, 15), cvTermCriteria (CV_TERMCRIT_ITER, 1, 0.0), 1);
		cvCvtColor(src, dst, CV_GRAY2RGB);
		for (int j = 0; j < length - 1; j++) {
			cvLine(dst, contour[j], contour[j + 1], CV_RGB(255, 0, 0), 2);
		}
		cvLine(dst, contour[length - 1], contour[0], CV_RGB(255, 0, 0), 2);
		//cvPutText (dst_img, iter, cvPoint (15, 30), &font, CV_RGB (0, 0, 255));
	}
	for (int i = 0; i < length; i++) {
		fprintf(stderr, "(x, y) = (%d, %d)\n", contour[i].x, contour[i].y);
	}
	//cvNamedWindow ("Snakes", CV_WINDOW_AUTOSIZE);
	//cvShowImage("Snakes", dst);
	//int c = cvWaitKey (0);
}
#endif

KTexture::KTexture(const char *filepath_)
{
	QString filepath(filepath_);
	p = new QPixmap(filepath);
	setPixmap(*p);
	isDrag = false;
	setObjectName("KTexture");
	ce = new QGraphicsColorizeEffect();
	setConnect();
	mouse_press_func = NULL;
	mouse_release_func = NULL;
	mouse_move_func = NULL;
#ifdef K_USING_BOX2D
	isStatic = true;
#endif
#ifdef K_USING_OPENCV
	//setTrackData(filepath_);
#endif
}

void KTexture::setConnect(void)
{

}

KTexture::KTexture(QImage *image)
{
	p = new QPixmap();
	QPixmap pixmap = p->fromImage(*image);
	setPixmap(pixmap);
	isDrag = false;
	setObjectName("KTexture");
	ce = new QGraphicsColorizeEffect();
	setConnect();
	mouse_press_func = NULL;
	mouse_release_func = NULL;
	mouse_move_func = NULL;
#ifdef K_USING_BOX2D
	isStatic = true;
#endif
#ifdef K_USING_OPENCV
	//setTrackData();
#endif
}

KTexture::KTexture(QPixmap *image)
{
	p = NULL;
	setPixmap(*image);
	isDrag = false;
	setObjectName("KTexture");
	ce = new QGraphicsColorizeEffect();
	setConnect();
	mouse_press_func = NULL;
	mouse_release_func = NULL;
	mouse_move_func = NULL;
#ifdef K_USING_BOX2D
	isStatic = true;
#endif
#ifdef K_USING_OPENCV
	//setTrackData();
#endif
}

KTexture::~KTexture(void)
{
	//delete p;
	//delete gp;
	//delete ce;
}

QList<KTexture*> *KTexture::split(CTX ctx, int row, int col)
{
	QList<KTexture*> *list = new QList<KTexture*>();
	QPixmap p = pixmap();
	int width = p.width();
	int height = p.height();
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			QPixmap pixmap = p.copy(width / row * i, height / col * j, width / row, height / col);
			KTexture *t = new KTexture(&pixmap);
			list->append(t);
		}
	}
	return list;
}

void KTexture::setRectShape(KRect *r)
{
	x = r->x;
	y = r->y;
	width = r->width;
	height = r->height;
	QPixmap p_;
	if (p == NULL) {
		QPixmap p = pixmap();
		p_ = p.scaled(width, height);
	} else {
		p_ = p->scaled(width, height);
	}
	setPixmap(p_);
	setPos(x, y);
}

#ifdef K_USING_BOX2D
void KTexture::addToWorld(KWorld *w)
{
	b2World *world = w->world;
	b2BodyDef bodyDef;
	if (!isStatic) {
		bodyDef.type = b2_dynamicBody;
	}
	bodyDef.position.Set(x, -y);
	bodyDef.angle = -(rotation() * (2 * M_PI)) / 360.0;
	body = world->CreateBody(&bodyDef);

	b2FixtureDef shapeDef;
	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2, b2Vec2(width / 2, -height / 2), 0.0);
	shapeDef.shape = &shape;
	shapeDef.density = density;
	shapeDef.friction = friction;
	shapeDef.restitution = restitution;
	body->CreateFixture(&shapeDef);

	QGraphicsItem *i = dynamic_cast<QGraphicsItem *>(this);
	knh_GraphicsUserData_t *data = (knh_GraphicsUserData_t *)malloc(sizeof(knh_GraphicsUserData_t));
	memset(data, 0, sizeof(knh_GraphicsUserData_t));
	CTX lctx = knh_getCurrentContext();
	data->ct = getClassTBL(Texture);
	data->o = i;
	data->self = this;
	body->SetUserData(data);
}
#endif

void KTexture::setColor(QColor *c)
{
	ce->setColor(*c);
	setGraphicsEffect(ce);
}

KMETHOD Texture_new(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	const char *filepath = String_to(const char *, sfp[1]);
	KTexture *t = new KTexture(filepath);
	t->setTag(GTexture);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, t, NULL);
	RETURN_(p);
}

KMETHOD Texture_setRect(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	KRect *r = RawPtr_to(KRect *, sfp[1]);
	t->setRectShape(r);
	RETURNvoid_();
}

KMETHOD Texture_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	QColor *c = RawPtr_to(QColor *, sfp[1]);
	t->setColor(c);
	RETURNvoid_();
}

KMETHOD Texture_split(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	int row = Int_to(int, sfp[1]);
	int col = Int_to(int, sfp[2]);
	QList<KTexture*> *panels = t->split(ctx, row, col);
	int size = row * col;
	knh_Array_t *a = new_Array0(ctx, size);
	for (int i = 0; i < size; i++) {
		knh_Array_add(ctx, a, (Object *)new_ReturnCppObject(ctx, sfp, panels->at(i), NULL));
	}
	RETURN_(a);
}

/*
KMETHOD Texture_setPosition(Ctx *ctx, knh_sfp_t *sfp, long rix)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	qreal x = Float_to(qreal, sfp[1]);
	qreal y = Float_to(qreal, sfp[2]);
	image->setPosition(x, y);
	RETURNvoid_();
}
*/

#ifdef K_USING_BOX2D
KMETHOD Texture_setDensity(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	qreal density = Float_to(qreal, sfp[1]);
	t->setDensity(density);
	RETURNvoid_();
}

KMETHOD Texture_setFriction(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	qreal friction = Float_to(qreal, sfp[1]);
	t->setFriction(friction);
	RETURNvoid_();
}

KMETHOD Texture_setRotation(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	qreal rotation = Float_to(qreal, sfp[1]);
	t->setRotation(rotation);
	RETURNvoid_();
}

KMETHOD Texture_setRestitution(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	qreal restitution = Float_to(qreal, sfp[1]);
	t->setRestitution(restitution);
	RETURNvoid_();
}
#endif

#ifdef K_USING_OPENCV
static ObjPointList *getDetectObjectPointList(IplImage *src, IplImage *background)
{
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* find_contour = NULL;
	const int w = src->width;
    const int h = src->height;
	IplImage *imgResult = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 1);
	IplImage *hsvImage = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 3);
	IplImage *hueImage = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 1);
	IplImage *saturationImage = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 1);
	IplImage *valueImage = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 1);
	IplImage *thresholdImage1 = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 1);
	IplImage *thresholdImage2 = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 1);
	IplImage *thresholdImage3 = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 1);
	IplImage *grayImage = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U,1);
	IplImage *differenceImage = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U,1);
    IplImage *backgroundImage = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U,1);
	//IplImage *prevImage = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U,1);
	//cvCvtColor(src, prevImage,CV_BGR2GRAY);
	cvCvtColor(background, backgroundImage, CV_BGR2GRAY);
	cvCvtColor(src, grayImage, CV_BGR2GRAY);
	//cvAbsDiff(grayImage, prevImage, differenceImage);
	cvAbsDiff(grayImage, backgroundImage, differenceImage);
	cvCvtColor(src, hsvImage, CV_BGR2HSV);
	cvSplit(hsvImage, hueImage, saturationImage, valueImage, NULL);
	cvThreshold(hueImage, thresholdImage1, 0, 255, CV_THRESH_BINARY);
	cvThreshold(hueImage, thresholdImage2, 96, 255, CV_THRESH_BINARY_INV);
	cvAnd(thresholdImage1, thresholdImage2, thresholdImage3, NULL);
	cvAnd(differenceImage, thresholdImage3, imgResult, NULL);
	cvErode(imgResult, imgResult, NULL, 1);
	cvDilate(imgResult, imgResult, NULL, 1);
	//=====================================================================//
	//IplImage *dst = cvCloneImage(imgResult);
	IplImage *tmp_img = cvCreateImage(cvGetSize(imgResult), IPL_DEPTH_8U, 1);
	cvThreshold(imgResult, tmp_img, 40, 255, CV_THRESH_BINARY);
	cvDilate(tmp_img, tmp_img, NULL, 20);
	cvFindContours(tmp_img, storage, &find_contour, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
	//fprintf(stderr, "num = [%d]\n", num);
    cvDrawContours(src, find_contour, CV_RGB(255, 0, 0), CV_RGB(255, 0, 0), 1, 2, CV_AA, cvPoint(0, 0));
    //cvShowImage("hoge", src);
	//=====================================================================//
	ObjPointList *objs = new ObjPointList();
	while (1) {
		if (find_contour == NULL) break;
		//fprintf(stderr, "=============START=============\n");
		QList<KPoint *> *obj = new QList<KPoint *>();
		for (int i = 0; i < find_contour->total; i++) {
			CvPoint *point = CV_GET_SEQ_ELEM(CvPoint, find_contour, i);
			KPoint *p = new KPoint(point->x, point->y);
			obj->append(p);
			//fprintf(stderr, "lib:(x, y) = (%d, %d)\n", point->x, point->y);
		}
		//fprintf(stderr, "=============END=============\n");
		objs->append(obj);
		if (find_contour->h_next == NULL) break;
		find_contour = find_contour->h_next;
	}
	cvReleaseImage(&imgResult);
	cvReleaseImage(&hsvImage);
	cvReleaseImage(&hueImage);
	cvReleaseImage(&saturationImage);
	cvReleaseImage(&valueImage);
	cvReleaseImage(&thresholdImage1);
	cvReleaseImage(&thresholdImage2);
	cvReleaseImage(&thresholdImage3);
	cvReleaseImage(&grayImage);
	cvReleaseImage(&differenceImage);
    cvReleaseImage(&backgroundImage);
	cvReleaseImage(&tmp_img);
	cvReleaseMemStorage(&storage);
	return objs;
	//cvShowImage(winNameCapture, img);
	//cvShowImage(winNameResult, dst);
	//cvShowImage(winNameResult, imgResult);
}

KMETHOD Texture_detectHuman(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	KTexture *background = RawPtr_to(KTexture *, sfp[1]);
	ObjPointList *objs = getDetectObjectPointList(t->ipl, background->ipl);
	int objs_size = objs->size();
//fprintf(stderr, "objs_size = [%d]\n", objs_size);
	knh_Array_t *a = new_Array0(ctx, objs_size);
	for (int i = 0; i < objs_size; i++) {
		QList<KPoint *> *obj = objs->at(i);
		int obj_size = obj->size();
		//fprintf(stderr, "obj_size = [%d]\n", obj_size);
		knh_Array_t *elem = new_Array0(ctx, obj_size);
		for (int j = 0; j < obj_size; j++) {
			KPoint *p = obj->at(j);
			//fprintf(stderr, "detectHuman: (x, y) = (%d, %d)\n", p->x, p->y);
			knh_Array_add(ctx, elem, (Object *)new_ReturnCppObject(ctx, sfp, new KPoint(p->x, p->y), NULL));
			delete p;
		}
		knh_Array_add(ctx, a, (Object *)elem);
        delete obj;
	}
    delete objs;
	RETURN_(a);
}

KMETHOD Texture_setMousePressEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	t->mouse_press_func = fo;
	RETURNvoid_();
}

KMETHOD Texture_setMouseReleaseEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	t->mouse_release_func = fo;
	RETURNvoid_();
}

KMETHOD Texture_setMouseMoveEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	t->mouse_move_func = fo;
	RETURNvoid_();
}

#endif

static void Texture_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL && O_cTBL(p)->total < 4) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Texture:free\n");
#endif
		KTexture *t = (KTexture *)p->rawptr;
		delete t;
	}
}

static void Texture_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx;
	(void)p;
	(void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Texture:reftrace\n");
#endif
		KTexture *t = (KTexture *)p->rawptr;
		KNH_ADDREF(ctx, t->mouse_press_func);
		KNH_ADDREF(ctx, t->mouse_move_func);
		KNH_ADDREF(ctx, t->mouse_release_func);
	}
}

DEFAPI(void) defTexture(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Texture";
	cdef->free = Texture_free;
	cdef->reftrace = Texture_reftrace;
}

DEFAPI(void) constTexture(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

/*
KMETHOD QPixmap_setSize(Ctx *ctx, knh_sfp_t *sfp, long rix)
{
	KPixmap *image = RawPtr_to(KPixmap *, sfp[0]);
	int width = Int_to(int, sfp[1]);
	int height = Int_to(int, sfp[2]);
	image->setSize(width, height);
	RETURNvoid_();
}
*/
#ifdef __cplusplus
}
#endif
