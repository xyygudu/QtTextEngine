#include "TextEditingPanel.h"


TextEditingPanel::TextEditingPanel(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::TextEditingPanelClass())
{
	ui->setupUi(this);
}

TextEditingPanel::~TextEditingPanel()
{
	delete ui;
}


