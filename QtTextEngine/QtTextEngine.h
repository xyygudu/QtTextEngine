#pragma once

#include <QtWidgets/QMainWindow>
#include <QPaintEvent>
#include "ui_QtTextEngine.h"
#include "TextEditingPanel.h"
#include "DisplayWidget.h"

class QtTextEngine : public QMainWindow
{
    Q_OBJECT

public:
    QtTextEngine(QWidget *parent = nullptr);
    ~QtTextEngine();
private:
    void initUi();
private:
    Ui::QtTextEngineClass ui;

    TextEditingPanel* textEditPanel_;
    DisplayWidget* displayWidget_;
};
