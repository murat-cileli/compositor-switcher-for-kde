#include "mainwindow.h"
#include <QApplication>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

QString MainWindow::getRunningProcesses() {
    QProcess *cmd = new QProcess();
    cmd->start("/bin/bash", QStringList() << "-c" << "ps -e");
    cmd->waitForFinished();
    QString output(cmd->readAllStandardOutput());
    delete cmd;

    return output;
}

void MainWindow::setCompositorState(QString state) {
    if ((state == "suspend" && !MainWindow::isCompositorActive()) || (state == "resume" && MainWindow::isCompositorActive())) {
        return;
    }

    QProcess *cmd = new QProcess();
    cmd->start("/bin/bash", QStringList() << "-c" << "qdbus org.kde.KWin /Compositor " + state);
    cmd->waitForFinished();
    delete cmd;
}
