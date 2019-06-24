#ifndef MESSENGERCONNECTIONDIALOG_H
#define MESSENGERCONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class MessengerConnectionDialog;
}

class MessengerConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MessengerConnectionDialog(QWidget *parent = nullptr);
    ~MessengerConnectionDialog();

    QString hostname() const;
    quint16 port() const;

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::MessengerConnectionDialog *ui;
    QString _hostname;
    quint16 _port;
};

#endif // MESSENGERCONNECTIONDIALOG_H
