#include "widget.h"
#include "ui_widget.h"
#include "MessengerConnectionDialog.h"
#include <QTcpSocket>
#include <QTextStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->bindButton->setDefault(true);
    setWindowTitle("Client");
    _socket = new QTcpSocket(this);

    connect(_socket, &QTcpSocket::readyRead, [&]() {
        QTextStream out(_socket);
        auto text = out.readAll();
        ui->textEdit->append(text);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_sendButton_clicked()
{
    QTextStream stream(_socket);
    stream << ui->niknameLine->text() << ": " << ui->messageLine->text();
    _socket->flush();
    ui->messageLine->clear();
}

void Widget::on_bindButton_clicked()
{
    MessengerConnectionDialog dialog(this);

    if (dialog.exec() == QDialog::Rejected) {
        return;
    }
    _socket->connectToHost(dialog.hostname(), dialog.port());
}
