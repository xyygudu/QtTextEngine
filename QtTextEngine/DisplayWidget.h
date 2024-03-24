#pragma once

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>

#include "Element.h"
#include "TextElement.h"

class DisplayWidget  : public QWidget
{
	Q_OBJECT

public:
	DisplayWidget(QWidget *parent);
	~DisplayWidget();

	void paintEvent(QPaintEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;

private:
	TextElement* textElement_;
	bool isMousePress;
};
