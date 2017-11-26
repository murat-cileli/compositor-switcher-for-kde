#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QDir>
#include <QStandardPaths>
#include <QStringListModel>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);

    QDir configDir(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/compositor-switcher");
    if (!configDir.exists()) {
        configDir.mkpath(".");
    }

    QTimer *checkTimer = new QTimer(this);
    connect(checkTimer, SIGNAL(timeout()), this, SLOT(check()));
    checkTimer->start(3000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAdd_clicked()
{
    QString processName = ui->processName->text().trimmed();

    if (processName.isEmpty()) {
        return;
    }

    ui->processList->addItem(ui->processName->text());
    ui->processName->clear();
}

void MainWindow::check() {
    int i;
    bool found = false;

    QString processes = MainWindow::getRunningProcesses();

    for (i = 0; i < ui->processList->count(); i++) {
        QListWidgetItem* item = ui->processList->item(i);
        if (processes.contains(item->text())) {
            found = true;
            break;
        }
    }

    if (found) {
        MainWindow::setCompositorState("suspend");
    } else {
        MainWindow::setCompositorState("resume");
    }

}

bool MainWindow::isCompositorActive() {
    QProcess *cmd = new QProcess();
    cmd->start("/bin/bash", QStringList() << "-c" << "qdbus org.kde.KWin /KWin supportInformation | grep -i \"compositing is\"");
    cmd->waitForFinished();
    QString output(cmd->readAllStandardOutput());
    delete cmd;

    if (output.contains("not active")) {
        ui->lblState->setText("Disabled");
        return false;
    } else {
        ui->lblState->setText("Enabled");
        return true;
    }
}


void MainWindow::on_btnRemove_clicked()
{
    qDeleteAll(ui->processList->selectedItems());
}


void MainWindow::on_btnHome_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://www.muratcileli.com/compositor-switcher-for-kde")));
}

void MainWindow::on_btnGithub_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://github.com/murat-cileli/compositor-switcher-for-kde")));
}
