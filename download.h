#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QtWidgets>
#include <QtConcurrent>
#include <QNetworkAccessManager>

class Futures : public QWidget {
Q_OBJECT
public:
    explicit Futures(QWidget *parent = nullptr);

    QFuture<QByteArray> download();

public slots:

    void processNonBlocking();

    void processResult();

    void processTakeResult();

private:
    QPushButton *nonBlockingButton;
    QPushButton *resultButton;
    QPushButton *takeResultButton;
    QVBoxLayout *mainLayout;

    QNetworkAccessManager qnam;
    QFuture<QByteArray> downloadFuture;
};

#endif // DOWNLOAD_H
