#include "MessengerConnectionDialog.h"
#include "ui_MessengerConnectionDialog.h"

MessengerConnectionDialog::MessengerConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessengerConnectionDialog)
{
    ui->setupUi(this);
}

MessengerConnectionDialog::~MessengerConnectionDialog()
{
    delete ui;
}

QString MessengerConnectionDialog::hostname() const
{
    return _hostname;
}

quint16 MessengerConnectionDialog::port() const
{
    return _port;
}

void MessengerConnectionDialog::on_okButton_clicked()
{
    _hostname = ui->hostnameLine->text();
    _port = static_cast<quint16>(ui->portSpinBox->value());
    accept();
}

void MessengerConnectionDialog::on_cancelButton_clicked()
{
    reject();
}
