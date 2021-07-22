#include <QtWidgets>
#include "download.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Futures futuresView;
    futuresView.show();

    return app.exec();
}
