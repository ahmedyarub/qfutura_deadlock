#include "download.h"
#include <QNetworkReply>
#include <qmath.h>

Futures::Futures(QWidget *parent) : QWidget(parent) {
    setWindowTitle(tr("QFuture Deadlock Test"));
    resize(400, 300);

    nonBlockingButton = new QPushButton(tr("Nonblocking"));
    connect(nonBlockingButton, &QPushButton::clicked, this, &Futures::processNonBlocking);

    resultButton = new QPushButton(tr("result()"));
    connect(resultButton, &QPushButton::clicked, this, &Futures::processResult);

    takeResultButton = new QPushButton(tr("takeResult()"));
    connect(takeResultButton, &QPushButton::clicked, this, &Futures::processTakeResult);


    auto *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(nonBlockingButton);
    buttonLayout->addWidget(resultButton);
    buttonLayout->addWidget(takeResultButton);
    buttonLayout->addStretch();

    mainLayout = new QVBoxLayout();
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
}

void Futures::processNonBlocking() {
    downloadFuture = download();
    downloadFuture.then([](const QFuture<QByteArray> &result) { qDebug() << result.result().length(); }
    );
}

void Futures::processResult() {
    downloadFuture = download();
    qDebug() << downloadFuture.result().length();
}

void Futures::processTakeResult() {
    downloadFuture = download();
    qDebug() << downloadFuture.takeResult().length();
}

QFuture<QByteArray> Futures::download() {
    QSharedPointer<QNetworkReply> reply(qnam.get(QNetworkRequest(QUrl("https://www.google.com"))));
    return QtFuture::connect(reply.get(), &QNetworkReply::finished).then([=] {
        return reply->readAll();
    });
}