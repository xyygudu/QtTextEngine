#pragma once

#include <QWidget>

#include "ui_TextEditingPanel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditingPanelClass; };
QT_END_NAMESPACE

class TextEditingPanel : public QWidget
{
	Q_OBJECT

public:
	TextEditingPanel(QWidget *parent = nullptr);
	~TextEditingPanel();


private:
	Ui::TextEditingPanelClass *ui;
};
