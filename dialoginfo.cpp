#include "dialoginfo.h"
#include "ui_dialoginfo.h"

DialogInfo::DialogInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInfo)
{
    ui->setupUi(this);
    ui->label->setText("         Made by \n Ömer Buğra Selvi");
}

DialogInfo::~DialogInfo()
{
    delete ui;
}
