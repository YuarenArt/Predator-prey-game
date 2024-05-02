#include <QtWidgets/QApplication>
#include <QApplication>
#include <QFile>
#include <QPixmapCache>

#include "game/PredatorPreyGame.h"
#include "widgets/settings_widget/SettingsWidget.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QPixmapCache::setCacheLimit(20480);

    QFile styleFile("./resources/styles/styles.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        app.setStyleSheet(style);
    }
    else {
        qDebug() << "Failed to open stylesheet file!";
    }

    PredatorPreyGame game;
    game.show();

    return app.exec();
}
