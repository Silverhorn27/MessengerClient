#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class QTcpSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_sendButton_clicked();

    void on_bindButton_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *_socket;
};

#endif // WIDGET_H
