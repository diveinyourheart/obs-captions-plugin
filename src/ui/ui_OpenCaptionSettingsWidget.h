/********************************************************************************
** Form generated from reading UI file 'OpenCaptionSettingsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENCAPTIONSETTINGSWIDGET_H
#define UI_OPENCAPTIONSETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenCaptionSettingsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *enabledCheckBox;
    QWidget *textSourceWidget;
    QFormLayout *formLayout_5;
    QLabel *label_14;
    QComboBox *outputComboBox;
    QLabel *label_15;
    QSpinBox *lineLengthSpinBox;
    QLabel *label_17;
    QSpinBox *lineCountSpinBox;
    QLabel *label_18;
    QComboBox *capitalizationComboBox;
    QLabel *label_24;
    QCheckBox *punctuationCheckBox;
    QToolButton *deleteToolButton;

    void setupUi(QWidget *OpenCaptionSettingsWidget)
    {
        if (OpenCaptionSettingsWidget->objectName().isEmpty())
            OpenCaptionSettingsWidget->setObjectName(QString::fromUtf8("OpenCaptionSettingsWidget"));
        OpenCaptionSettingsWidget->resize(383, 197);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OpenCaptionSettingsWidget->sizePolicy().hasHeightForWidth());
        OpenCaptionSettingsWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(OpenCaptionSettingsWidget);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 12, 0, 12);
        enabledCheckBox = new QCheckBox(OpenCaptionSettingsWidget);
        enabledCheckBox->setObjectName(QString::fromUtf8("enabledCheckBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(enabledCheckBox->sizePolicy().hasHeightForWidth());
        enabledCheckBox->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(enabledCheckBox);

        textSourceWidget = new QWidget(OpenCaptionSettingsWidget);
        textSourceWidget->setObjectName(QString::fromUtf8("textSourceWidget"));
        sizePolicy.setHeightForWidth(textSourceWidget->sizePolicy().hasHeightForWidth());
        textSourceWidget->setSizePolicy(sizePolicy);
        formLayout_5 = new QFormLayout(textSourceWidget);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_5->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout_5->setVerticalSpacing(4);
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(textSourceWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(120, 0));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_14);

        outputComboBox = new QComboBox(textSourceWidget);
        outputComboBox->setObjectName(QString::fromUtf8("outputComboBox"));
        outputComboBox->setMinimumSize(QSize(250, 0));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, outputComboBox);

        label_15 = new QLabel(textSourceWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_15);

        lineLengthSpinBox = new QSpinBox(textSourceWidget);
        lineLengthSpinBox->setObjectName(QString::fromUtf8("lineLengthSpinBox"));
        lineLengthSpinBox->setMinimum(1);
        lineLengthSpinBox->setMaximum(999999999);

        formLayout_5->setWidget(2, QFormLayout::FieldRole, lineLengthSpinBox);

        label_17 = new QLabel(textSourceWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label_17);

        lineCountSpinBox = new QSpinBox(textSourceWidget);
        lineCountSpinBox->setObjectName(QString::fromUtf8("lineCountSpinBox"));
        lineCountSpinBox->setMinimum(1);

        formLayout_5->setWidget(3, QFormLayout::FieldRole, lineCountSpinBox);

        label_18 = new QLabel(textSourceWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout_5->setWidget(5, QFormLayout::LabelRole, label_18);

        capitalizationComboBox = new QComboBox(textSourceWidget);
        capitalizationComboBox->setObjectName(QString::fromUtf8("capitalizationComboBox"));

        formLayout_5->setWidget(5, QFormLayout::FieldRole, capitalizationComboBox);

        label_24 = new QLabel(textSourceWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        formLayout_5->setWidget(4, QFormLayout::LabelRole, label_24);

        punctuationCheckBox = new QCheckBox(textSourceWidget);
        punctuationCheckBox->setObjectName(QString::fromUtf8("punctuationCheckBox"));

        formLayout_5->setWidget(4, QFormLayout::FieldRole, punctuationCheckBox);


        verticalLayout->addWidget(textSourceWidget);

        deleteToolButton = new QToolButton(OpenCaptionSettingsWidget);
        deleteToolButton->setObjectName(QString::fromUtf8("deleteToolButton"));

        verticalLayout->addWidget(deleteToolButton);


        retranslateUi(OpenCaptionSettingsWidget);

        QMetaObject::connectSlotsByName(OpenCaptionSettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *OpenCaptionSettingsWidget)
    {
        OpenCaptionSettingsWidget->setWindowTitle(QCoreApplication::translate("OpenCaptionSettingsWidget", "Form", nullptr));
        enabledCheckBox->setText(QCoreApplication::translate("OpenCaptionSettingsWidget", "Enabled", nullptr));
        label_14->setText(QCoreApplication::translate("OpenCaptionSettingsWidget", "Text Source", nullptr));
        label_15->setText(QCoreApplication::translate("OpenCaptionSettingsWidget", "Line Length", nullptr));
        label_17->setText(QCoreApplication::translate("OpenCaptionSettingsWidget", "Lines", nullptr));
        label_18->setText(QCoreApplication::translate("OpenCaptionSettingsWidget", "Capitalization", nullptr));
        label_24->setText(QCoreApplication::translate("OpenCaptionSettingsWidget", "Add Punctuation", nullptr));
        punctuationCheckBox->setText(QString());
        deleteToolButton->setText(QCoreApplication::translate("OpenCaptionSettingsWidget", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenCaptionSettingsWidget: public Ui_OpenCaptionSettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENCAPTIONSETTINGSWIDGET_H
