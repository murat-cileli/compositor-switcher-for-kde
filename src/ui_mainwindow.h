/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *processName;
    QLabel *label;
    QPushButton *btnAdd;
    QListWidget *processList;
    QPushButton *btnRemove;
    QFrame *frame;
    QLabel *label_2;
    QLabel *lblState;
    QFrame *frame_2;
    QSpinBox *spinBox_2;
    QLabel *lblState_2;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *frame_3;
    QLabel *label_3;
    QPushButton *btnHome;
    QPushButton *btnGithub;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(462, 280);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        processName = new QLineEdit(centralWidget);
        processName->setObjectName(QStringLiteral("processName"));
        processName->setGeometry(QRect(20, 30, 131, 30));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 121, 16));
        btnAdd = new QPushButton(centralWidget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setGeometry(QRect(160, 30, 61, 30));
        processList = new QListWidget(centralWidget);
        new QListWidgetItem(processList);
        processList->setObjectName(QStringLiteral("processList"));
        processList->setGeometry(QRect(20, 70, 201, 151));
        processList->setSelectionMode(QAbstractItemView::MultiSelection);
        btnRemove = new QPushButton(centralWidget);
        btnRemove->setObjectName(QStringLiteral("btnRemove"));
        btnRemove->setGeometry(QRect(20, 230, 201, 32));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(240, 30, 201, 41));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(14, 13, 101, 16));
        lblState = new QLabel(frame);
        lblState->setObjectName(QStringLiteral("lblState"));
        lblState->setGeometry(QRect(114, 13, 71, 16));
        lblState->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(240, 80, 201, 91));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        spinBox_2 = new QSpinBox(frame_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(15, 41, 49, 30));
        spinBox_2->setMinimum(3);
        spinBox_2->setMaximum(300);
        lblState_2 = new QLabel(frame_2);
        lblState_2->setObjectName(QStringLiteral("lblState_2"));
        lblState_2->setGeometry(QRect(115, 15, 71, 16));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(15, 17, 101, 16));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(76, 49, 101, 16));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(240, 181, 201, 81));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(14, 10, 171, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        btnHome = new QPushButton(frame_3);
        btnHome->setObjectName(QStringLiteral("btnHome"));
        btnHome->setGeometry(QRect(31, 33, 71, 32));
        btnHome->setCursor(QCursor(Qt::PointingHandCursor));
        btnGithub = new QPushButton(frame_3);
        btnGithub->setObjectName(QStringLiteral("btnGithub"));
        btnGithub->setGeometry(QRect(107, 33, 61, 32));
        btnGithub->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Compositor Switcher for KDE", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Process Name", Q_NULLPTR));
        btnAdd->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));

        const bool __sortingEnabled = processList->isSortingEnabled();
        processList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = processList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "notepadqq", Q_NULLPTR));
        processList->setSortingEnabled(__sortingEnabled);

        btnRemove->setText(QApplication::translate("MainWindow", "Remove Selected", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Compositor State:", Q_NULLPTR));
        lblState->setText(QString());
        lblState_2->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Check every", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "seconds (default: 3)", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Programmed by Murat \303\207ileli", Q_NULLPTR));
        btnHome->setText(QApplication::translate("MainWindow", "Home", Q_NULLPTR));
        btnGithub->setText(QApplication::translate("MainWindow", "GitHub", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
