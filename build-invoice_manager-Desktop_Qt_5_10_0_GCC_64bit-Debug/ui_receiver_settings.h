/********************************************************************************
** Form generated from reading UI file 'receiver_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVER_SETTINGS_H
#define UI_RECEIVER_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Receiver_settings
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *name_line_edit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *surname_line_edit;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *address_line_edit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *civic_number_line_edit;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *cap_line_edit;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *province_line_edit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *piva_line_edit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *fiscal_code_line_edit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLineEdit *mail_line_edit;
    QHBoxLayout *_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *add_new;
    QPushButton *pushButton;
    QPushButton *submit_button;
    QSpacerItem *horizontalSpacer_4;
    QTableView *tableView;

    void setupUi(QDialog *Receiver_settings)
    {
        if (Receiver_settings->objectName().isEmpty())
            Receiver_settings->setObjectName(QStringLiteral("Receiver_settings"));
        Receiver_settings->resize(900, 478);
        verticalLayout_3 = new QVBoxLayout(Receiver_settings);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(Receiver_settings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label_2);

        name_line_edit = new QLineEdit(groupBox);
        name_line_edit->setObjectName(QStringLiteral("name_line_edit"));

        horizontalLayout_3->addWidget(name_line_edit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(label);

        surname_line_edit = new QLineEdit(groupBox);
        surname_line_edit->setObjectName(QStringLiteral("surname_line_edit"));

        horizontalLayout_2->addWidget(surname_line_edit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        address_line_edit = new QLineEdit(groupBox);
        address_line_edit->setObjectName(QStringLiteral("address_line_edit"));

        horizontalLayout->addWidget(address_line_edit);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        civic_number_line_edit = new QLineEdit(groupBox);
        civic_number_line_edit->setObjectName(QStringLiteral("civic_number_line_edit"));

        horizontalLayout_4->addWidget(civic_number_line_edit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(label_7);

        cap_line_edit = new QLineEdit(groupBox);
        cap_line_edit->setObjectName(QStringLiteral("cap_line_edit"));

        horizontalLayout_8->addWidget(cap_line_edit);


        horizontalLayout_5->addLayout(horizontalLayout_8);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(label_9);

        province_line_edit = new QLineEdit(groupBox);
        province_line_edit->setObjectName(QStringLiteral("province_line_edit"));

        horizontalLayout_10->addWidget(province_line_edit);


        horizontalLayout_5->addLayout(horizontalLayout_10);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(label_5);

        piva_line_edit = new QLineEdit(groupBox);
        piva_line_edit->setObjectName(QStringLiteral("piva_line_edit"));

        horizontalLayout_6->addWidget(piva_line_edit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(label_6);

        fiscal_code_line_edit = new QLineEdit(groupBox);
        fiscal_code_line_edit->setObjectName(QStringLiteral("fiscal_code_line_edit"));

        horizontalLayout_7->addWidget(fiscal_code_line_edit);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);

        horizontalLayout_11->addWidget(label_10);

        mail_line_edit = new QLineEdit(groupBox);
        mail_line_edit->setObjectName(QStringLiteral("mail_line_edit"));

        horizontalLayout_11->addWidget(mail_line_edit);


        verticalLayout_2->addLayout(horizontalLayout_11);


        verticalLayout_4->addWidget(groupBox);

        _2 = new QHBoxLayout();
        _2->setObjectName(QStringLiteral("_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(horizontalSpacer_2);

        add_new = new QPushButton(Receiver_settings);
        add_new->setObjectName(QStringLiteral("add_new"));

        _2->addWidget(add_new);

        pushButton = new QPushButton(Receiver_settings);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        _2->addWidget(pushButton);

        submit_button = new QPushButton(Receiver_settings);
        submit_button->setObjectName(QStringLiteral("submit_button"));

        _2->addWidget(submit_button);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(_2);


        verticalLayout_3->addLayout(verticalLayout_4);

        tableView = new QTableView(Receiver_settings);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(tableView);


        retranslateUi(Receiver_settings);

        QMetaObject::connectSlotsByName(Receiver_settings);
    } // setupUi

    void retranslateUi(QDialog *Receiver_settings)
    {
        Receiver_settings->setWindowTitle(QApplication::translate("Receiver_settings", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("Receiver_settings", "aggiungi destinatario", nullptr));
        label_2->setText(QApplication::translate("Receiver_settings", "nome", nullptr));
        label->setText(QApplication::translate("Receiver_settings", "cognome", nullptr));
        label_3->setText(QApplication::translate("Receiver_settings", "indirizzo", nullptr));
        label_4->setText(QApplication::translate("Receiver_settings", "numero indirizzo", nullptr));
        label_7->setText(QApplication::translate("Receiver_settings", "cap", nullptr));
        label_9->setText(QApplication::translate("Receiver_settings", "provincia", nullptr));
        label_5->setText(QApplication::translate("Receiver_settings", "partita iva", nullptr));
        label_6->setText(QApplication::translate("Receiver_settings", "codice fiscale", nullptr));
        label_10->setText(QApplication::translate("Receiver_settings", "email", nullptr));
        add_new->setText(QApplication::translate("Receiver_settings", "add", nullptr));
        pushButton->setText(QApplication::translate("Receiver_settings", "delete", nullptr));
        submit_button->setText(QApplication::translate("Receiver_settings", "submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Receiver_settings: public Ui_Receiver_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVER_SETTINGS_H
