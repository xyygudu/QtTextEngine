#include "QtTextEngine.h"

QtTextEngine::QtTextEngine(QWidget *parent)
    : QMainWindow(parent)
{
    
    ui.setupUi(this);
    initUi();
}

QtTextEngine::~QtTextEngine()
{}

void QtTextEngine::initUi()
{
    textEditPanel_ = new TextEditingPanel(ui.attrWidget);
    ui.attrWidget->layout()->addWidget(textEditPanel_);
    displayWidget_ = new DisplayWidget(ui.displayWidget);
    ui.displayWidget->layout()->addWidget(displayWidget_);
}

