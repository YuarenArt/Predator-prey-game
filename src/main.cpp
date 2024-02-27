#include <QtWidgets/QApplication>
#include <QApplication>
#include <QFile>
#include <QPixmapCache>

#include "PredatorPreyGame.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    //FieldSprite w;
    QPixmapCache::setCacheLimit(20480);
    FieldSpriteVector w;


    QFile styleFile("./resources/styles/styles.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        app.setStyleSheet(style);
    }
    else {
        qDebug() << "Failed to open stylesheet file!";
    }

    w.show();
    return app.exec();
}