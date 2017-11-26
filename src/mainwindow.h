#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString getRunningProcesses();
    void setCompositorState(QString state);
    bool isCompositorActive();
    QDir configDir;

private slots:
    void on_btnAdd_clicked();
    void check();
    void on_btnRemove_clicked();
    void on_btnHome_clicked();
    void on_btnGithub_clicked();

private:
    Ui::MainWindow *ui;

};


#endif // MAINWINDOW_H
