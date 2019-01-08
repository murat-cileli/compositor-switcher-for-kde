#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QSystemTrayIcon>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changeEvent(QEvent *event);
    void closeEvent (QCloseEvent *event);
    QString getRunningProcesses();
    void setCompositorState(QString state);
    bool isCompositorActive();
    void saveProcessList();
    void loadProcessList();
    QString configPath;

private slots:
    void on_btnAdd_clicked();
    void check();
    void on_btnRemove_clicked();
    void on_btnHome_clicked();
    void on_btnGithub_clicked();
    void showWindow(QSystemTrayIcon::ActivationReason r);

private:
    Ui::MainWindow *ui;

};


#endif // MAINWINDOW_H
