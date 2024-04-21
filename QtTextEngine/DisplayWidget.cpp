#include "DisplayWidget.h"
#include <QPixmap>
#include <QImage>
#include <QPainter>
#include <QDebug>

DisplayWidget::DisplayWidget(QWidget *parent)
	: QWidget(parent)
	, isMousePress(false)
{
	textElement_ = new TextElement();
	setMouseTracking(true); 
}

DisplayWidget::~DisplayWidget()
{}

void DisplayWidget::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	textElement_->setText(u"份14\r56发解放大卡dkj啊😂😒🤣");
	textElement_->horizontalLayout(250);
	textElement_->drawFace();
	SkBitmap bitmap = textElement_->getBitmap();
	int w = bitmap.width();
	int h = bitmap.height();
	const void* pixels = bitmap.getPixels();
	int bytesPerLine = bitmap.rowBytes();
	QImage::Format format = QImage::Format_ARGB32; // 根据SkBitmap的格式进行调整

	QImage image = QImage(static_cast<const uchar*>(pixels), w, h, bytesPerLine, format);

	// Use QPainter to draw QImage on the widget
	painter.drawImage(0, 0, image);
	/*painter.fillRect(0, 0, this->width(), this->height(), QColor(255, 255, 255)); 
	QPixmap pixmap("C:/Users/acer/Pictures/xyy.bmp");
	QPixmap img = pixmap.scaled(width(), height(), Qt::KeepAspectRatio);
	painter.drawPixmap((width() - img.width()) / 2, (height() - img.height()) / 2, img);*/
}

void DisplayWidget::mousePressEvent(QMouseEvent* event)
{
	isMousePress = true;
	qDebug() << "press: " << event->pos();
	//textElement_->setCenterPoint(event->pos().x(), event->pos().y());
	QWidget::mousePressEvent(event);
	
}

void DisplayWidget::mouseReleaseEvent(QMouseEvent* event)
{
	isMousePress = false;
}

void DisplayWidget::mouseMoveEvent(QMouseEvent* event)
{
	qDebug() << "move: " << event->pos();
	if (isMousePress)
	{
		textElement_->setCenterPoint(event->pos().x(), event->pos().y());
		update();
	}
	QWidget::mouseMoveEvent(event);
}
