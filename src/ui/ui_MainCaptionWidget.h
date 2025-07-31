/********************************************************************************
** Form generated from reading UI file 'MainCaptionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCAPTIONWIDGET_H
#define UI_MAINCAPTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainCaptionWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *enabledCheckbox;
    QToolButton *settingsToolButton;
    QLabel *label_2;
    QPlainTextEdit *captionHistoryPlainTextEdit;
    QLabel *label;
    QPlainTextEdit *captionLinesPlainTextEdit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *statusTextLabel;

    void setupUi(QWidget *MainCaptionWidget)
    {
        if (MainCaptionWidget->objectName().isEmpty())
            MainCaptionWidget->setObjectName(QString::fromUtf8("MainCaptionWidget"));
        MainCaptionWidget->resize(464, 457);
        verticalLayout = new QVBoxLayout(MainCaptionWidget);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 2, -1, 2);
        widget = new QWidget(MainCaptionWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        enabledCheckbox = new QCheckBox(widget);
        enabledCheckbox->setObjectName(QString::fromUtf8("enabledCheckbox"));

        horizontalLayout->addWidget(enabledCheckbox);

        settingsToolButton = new QToolButton(widget);
        settingsToolButton->setObjectName(QString::fromUtf8("settingsToolButton"));

        horizontalLayout->addWidget(settingsToolButton);


        verticalLayout->addWidget(widget);

        label_2 = new QLabel(MainCaptionWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        captionHistoryPlainTextEdit = new QPlainTextEdit(MainCaptionWidget);
        captionHistoryPlainTextEdit->setObjectName(QString::fromUtf8("captionHistoryPlainTextEdit"));
        QFont font;
        font.setPointSize(13);
        captionHistoryPlainTextEdit->setFont(font);
        captionHistoryPlainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(captionHistoryPlainTextEdit);

        label = new QLabel(MainCaptionWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        captionLinesPlainTextEdit = new QPlainTextEdit(MainCaptionWidget);
        captionLinesPlainTextEdit->setObjectName(QString::fromUtf8("captionLinesPlainTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(captionLinesPlainTextEdit->sizePolicy().hasHeightForWidth());
        captionLinesPlainTextEdit->setSizePolicy(sizePolicy);
        captionLinesPlainTextEdit->setMinimumSize(QSize(0, 120));
        captionLinesPlainTextEdit->setMaximumSize(QSize(16777215, 120));
        QFont font1;
        font1.setPointSize(15);
        captionLinesPlainTextEdit->setFont(font1);
        captionLinesPlainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(captionLinesPlainTextEdit);

        widget_2 = new QWidget(MainCaptionWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 4, 0, 4);
        statusTextLabel = new QLabel(widget_2);
        statusTextLabel->setObjectName(QString::fromUtf8("statusTextLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(statusTextLabel->sizePolicy().hasHeightForWidth());
        statusTextLabel->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(statusTextLabel, 0, Qt::AlignLeft);


        verticalLayout->addWidget(widget_2);


        retranslateUi(MainCaptionWidget);

        QMetaObject::connectSlotsByName(MainCaptionWidget);
    } // setupUi

    void retranslateUi(QWidget *MainCaptionWidget)
    {
        MainCaptionWidget->setWindowTitle(QCoreApplication::translate("MainCaptionWidget", "Caption Preview", nullptr));
        enabledCheckbox->setText(QCoreApplication::translate("MainCaptionWidget", "Captioning Enabled", nullptr));
        settingsToolButton->setText(QCoreApplication::translate("MainCaptionWidget", "Settings", nullptr));
        label_2->setText(QCoreApplication::translate("MainCaptionWidget", "Recent:", nullptr));
        captionHistoryPlainTextEdit->setPlainText(QCoreApplication::translate("MainCaptionWidget", "Preview\n"
"                            asdfa sdf 123 asdf Preview\n"
"                            asdfa sdf 123 asdf Preview\n"
"                            asdfa sdf 123 asdf ", nullptr));
        label->setText(QCoreApplication::translate("MainCaptionWidget", "Stream Output Preview:", nullptr));
        captionLinesPlainTextEdit->setPlainText(QCoreApplication::translate("MainCaptionWidget", "line1\n"
"                            line2\n"
"                            line3\n"
"                            line4", nullptr));
        statusTextLabel->setText(QCoreApplication::translate("MainCaptionWidget", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainCaptionWidget: public Ui_MainCaptionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCAPTIONWIDGET_H
