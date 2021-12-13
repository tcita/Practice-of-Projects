#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QButtonGroup * buttonGroup = new QButtonGroup(this);
    buttonGroup -> addButton(ui->ACheckBox);
    buttonGroup -> addButton(ui->BCheckBox);
    buttonGroup -> addButton(ui->CCheckBox);
    buttonGroup -> addButton(ui->DCheckBox);

    buttonGroup->setExclusive(true);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_ACheckBox_toggled(bool checked)
{
    if(checked)
    {
        qDebug()<< "ACheckbox is checked" ;
    }
    else
    {
        qDebug()<<"ACheckedbox is unchecked";
    }
}


void Widget::on_BCheckBox_toggled(bool checked)
{
    if(checked)
    {
        qDebug()<< "BCheckbox is checked" ;
    }
    else
    {
        qDebug()<<"BCheckedbox is unchecked";
    }
}


void Widget::on_CCheckBox_toggled(bool checked)
{
    if(checked)
    {
        qDebug()<< "CCheckbox is checked";
    }
    else
    {
        qDebug()<<"CCheckedbox is unchecked";
    }
}


void Widget::on_DCheckBox_toggled(bool checked)
{
    if(checked)
    {
        qDebug()<< "DCheckbox is checked";
    }
    else
    {
        qDebug()<<"DCheckedbox is unchecked";
    }
}


void Widget::on_UploadButton_clicked()
{
    if(ui->ACheckBox->isChecked())
    {
       qDebug()<< "ACheckbox is checked";
    }else
    {
       qDebug()<<"ACheckbox is unchecked";
    }
}




