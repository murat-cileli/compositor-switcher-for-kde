#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>
#include <QDebug>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QDir>
#include <QStandardPaths>
#include <QStringListModel>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSystemTrayIcon* trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon::fromTheme("draw-square-inverted-corners"));
    trayIcon->show();

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(showWindow(QSystemTrayIcon::ActivationReason)));

    QDir configDir(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/compositor-switcher");

    if (!configDir.exists()) {
        configDir.mkpath(".");
    }

    configPath = configDir.path();

    loadProcessList();
    isCompositorActive();

    QTimer *checkTimer = new QTimer(this);
    connect(checkTimer, SIGNAL(timeout()), this, SLOT(check()));
    checkTimer->start(ui->sbInterval->value() * 1000);
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

    saveProcessList();
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

void MainWindow::saveProcessList()
{
    int i;

    QString fileName = configPath + QString("/process_list");
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }

    QTextStream out(&file);

    for (i = 0; i < ui->processList->count(); i++) {
        QListWidgetItem* item = ui->processList->item(i);
        out << item->text() << "\n";
    }

    file.close();
}

void MainWindow::loadProcessList()
{
    QString fileName = configPath + QString("/process_list");
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly)) {
       return;
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QListWidgetItem* item = new QListWidgetItem;
        item->setText(in.readLine().trimmed());
        ui->processList->addItem(item);
    }

    file.close();
}

void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::WindowStateChange && isMinimized()) {
            this->hide();
            event->ignore();
    }
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    event->accept();
    qApp->exit();
}

void MainWindow::showWindow(QSystemTrayIcon::ActivationReason r)
{
    if (r == QSystemTrayIcon::Trigger) {
        this->show();
        this->activateWindow();
    }
}

void MainWindow::on_btnRemove_clicked()
{
    qDeleteAll(ui->processList->selectedItems());
    saveProcessList();
}


void MainWindow::on_btnHome_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://www.muratcileli.com/compositor-switcher-for-kde")));
}

void MainWindow::on_btnGithub_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://github.com/murat-cileli/compositor-switcher-for-kde")));
}
