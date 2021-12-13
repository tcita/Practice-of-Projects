#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_ACheckBox_toggled(bool checked);

    void on_BCheckBox_toggled(bool checked);

    void on_CCheckBox_toggled(bool checked);

    void on_DCheckBox_toggled(bool checked);

    void on_UploadButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
