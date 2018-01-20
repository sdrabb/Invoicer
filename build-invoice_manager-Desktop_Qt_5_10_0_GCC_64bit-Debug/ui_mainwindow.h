/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_new_invoice;
    QAction *action_settings_receiver;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableView *invoices;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *receiver_choiches;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menudestinatario;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1114, 653);
        action_new_invoice = new QAction(MainWindow);
        action_new_invoice->setObjectName(QStringLiteral("action_new_invoice"));
        action_settings_receiver = new QAction(MainWindow);
        action_settings_receiver->setObjectName(QStringLiteral("action_settings_receiver"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        invoices = new QTableView(centralWidget);
        invoices->setObjectName(QStringLiteral("invoices"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(invoices->sizePolicy().hasHeightForWidth());
        invoices->setSizePolicy(sizePolicy);
        invoices->horizontalHeader()->setStretchLastSection(true);
        invoices->verticalHeader()->setVisible(true);

        verticalLayout_2->addWidget(invoices);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        receiver_choiches = new QTableView(centralWidget);
        receiver_choiches->setObjectName(QStringLiteral("receiver_choiches"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(receiver_choiches->sizePolicy().hasHeightForWidth());
        receiver_choiches->setSizePolicy(sizePolicy1);
        receiver_choiches->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(receiver_choiches);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1114, 22));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QStringLiteral("menufile"));
        menudestinatario = new QMenu(menuBar);
        menudestinatario->setObjectName(QStringLiteral("menudestinatario"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addAction(action_new_invoice);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_settings_receiver);
        menuBar->addAction(menufile->menuAction());
        menuBar->addAction(menudestinatario->menuAction());
        menufile->addAction(action_new_invoice);
        menudestinatario->addAction(action_settings_receiver);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_new_invoice->setText(QApplication::translate("MainWindow", "aggiungi fattura", nullptr));
        action_settings_receiver->setText(QApplication::translate("MainWindow", "aggiungi/rimuovi destinatario", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Fatture", nullptr));
        label->setText(QApplication::translate("MainWindow", "Intestatari", nullptr));
        menufile->setTitle(QApplication::translate("MainWindow", "fattura", nullptr));
        menudestinatario->setTitle(QApplication::translate("MainWindow", "destinatario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
