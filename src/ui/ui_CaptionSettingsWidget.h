/********************************************************************************
** Form generated from reading UI file 'CaptionSettingsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTIONSETTINGSWIDGET_H
#define UI_CAPTIONSETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CaptionSettingsWidget
{
public:
    QVBoxLayout *verticalLayoutMainOuter;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayoutMainScrollContainer;
    QCheckBox *enabledCheckBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayoutTabGeneral;
    QFrame *generalSceneCollectionWidget;
    QFormLayout *formLayout_2;
    QLabel *sceneCollectionNameLabel_GeneralLeft;
    QLabel *sceneCollectionNameLabel_GeneralRight;
    QWidget *widget_2;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *sourcesComboBox;
    QLabel *captionWhenLabel;
    QComboBox *captionWhenComboBox;
    QLabel *muteSourceLabel;
    QComboBox *muteSourceComboBox;
    QLabel *label_6;
    QComboBox *languageComboBox;
    QLabel *languageWarningLabel;
    QLabel *profanitFilterLabel;
    QComboBox *profanityFilterComboBox;
    QLabel *apiKeyLabel;
    QWidget *apiKeyWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *apiKeyLineEdit;
    QPushButton *apiKeyShowPushButton;
    QLabel *label_5;
    QFrame *frame;
    QFormLayout *formLayout_5;
    QLabel *nativeOutputToLabel;
    QComboBox *outputTargetComboBox;
    QLabel *nativeLineCountLabel;
    QSpinBox *lineCountSpinBox;
    QLabel *nativeForceLinebreaksLabel;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *insertLinebreaksCheckBox;
    QLabel *nativeLinebreaksNotRecommendendLabel;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *captionTimeoutEnabledCheckBox;
    QDoubleSpinBox *captionTimeoutDoubleSpinBox;
    QLabel *label_22;
    QCheckBox *addPunctuationCheckBox;
    QLabel *label_15;
    QComboBox *capitalizationComboBox;
    QSpacerItem *verticalSpacer;
    QTextBrowser *bottomTextBrowser;
    QWidget *tab_2;
    QVBoxLayout *verticalLayoutTabTranscripts;
    QCheckBox *saveTranscriptsCheckBox;
    QWidget *transcripWidget1;
    QFormLayout *formLayout_3;
    QLabel *label_9;
    QLabel *label_17;
    QComboBox *transcriptFormatComboBox;
    QLabel *label_10;
    QCheckBox *transcriptsEnabledStreamCheckBox;
    QCheckBox *transcriptsEnabledRecordingCheckBox;
    QCheckBox *transcriptsEnabledVirtualcamCheckBox;
    QWidget *transcripWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *transcriptFolderPathLineEdit;
    QPushButton *transcriptFolderPickerPushButton;
    QFrame *transcripWidget3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_7;
    QComboBox *streamingTranscriptFilenameComboBox;
    QWidget *streamingTranscriptCustomNameWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QComboBox *streamingTranscriptCustomNameExistsCombobox;
    QLineEdit *streamingTranscriptCustomNameOverwriteLineEdit;
    QFrame *transcripWidget4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QComboBox *recordingTranscriptFilenameComboBox;
    QWidget *recordingTranscriptCustomNameWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QComboBox *recordingTranscriptCustomNameExistsCombobox;
    QLineEdit *recordingTranscriptCustomNameOverwriteLineEdit;
    QFrame *transcripWidget5;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_14;
    QComboBox *virtualcamTranscriptFilenameComboBox;
    QWidget *virtualcamTranscriptCustomNameWidget;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_21;
    QComboBox *virtualcamTranscriptCustomNameExistsCombobox;
    QLineEdit *virtualcamTranscriptCustomNameOverwriteLineEdit;
    QWidget *transcriptSrtSettingsWidget;
    QFormLayout *formLayout_4;
    QLabel *label_18;
    QLabel *label_19;
    QSpinBox *srtDurationSpinBox;
    QLabel *label_20;
    QSpinBox *srtLineLengthSpinBox;
    QLabel *label_11;
    QComboBox *srtCapitalizationComboBox;
    QCheckBox *srtSplitSentencesCheckBox;
    QLabel *label_12;
    QCheckBox *srtAddPunctuationCheckBox;
    QWidget *tab_3;
    QVBoxLayout *verticalLayoutTabOpenCaptions;
    QScrollArea *textOutputsListScrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *filterTab;
    QVBoxLayout *verticalLayoutTabTextFiltering;
    QLabel *label_4;
    QTableWidget *wordReplacementTableWidget;
    QPushButton *replacementWordsAddWordPushButton;
    QWidget *footer_save_widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *previewPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelPushButton;
    QPushButton *savePushButton;

    void setupUi(QWidget *CaptionSettingsWidget)
    {
        if (CaptionSettingsWidget->objectName().isEmpty())
            CaptionSettingsWidget->setObjectName(QString::fromUtf8("CaptionSettingsWidget"));
        CaptionSettingsWidget->resize(425, 885);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CaptionSettingsWidget->sizePolicy().hasHeightForWidth());
        CaptionSettingsWidget->setSizePolicy(sizePolicy);
        verticalLayoutMainOuter = new QVBoxLayout(CaptionSettingsWidget);
        verticalLayoutMainOuter->setSpacing(0);
        verticalLayoutMainOuter->setObjectName(QString::fromUtf8("verticalLayoutMainOuter"));
        verticalLayoutMainOuter->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(CaptionSettingsWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(0);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 425, 841));
        verticalLayoutMainScrollContainer = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayoutMainScrollContainer->setSpacing(12);
        verticalLayoutMainScrollContainer->setObjectName(QString::fromUtf8("verticalLayoutMainScrollContainer"));
        verticalLayoutMainScrollContainer->setContentsMargins(12, 12, 12, 12);
        enabledCheckBox = new QCheckBox(scrollAreaWidgetContents_2);
        enabledCheckBox->setObjectName(QString::fromUtf8("enabledCheckBox"));

        verticalLayoutMainScrollContainer->addWidget(enabledCheckBox);

        tabWidget = new QTabWidget(scrollAreaWidgetContents_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayoutTabGeneral = new QVBoxLayout(tab);
        verticalLayoutTabGeneral->setSpacing(6);
        verticalLayoutTabGeneral->setObjectName(QString::fromUtf8("verticalLayoutTabGeneral"));
        verticalLayoutTabGeneral->setContentsMargins(4, 12, 4, 12);
        generalSceneCollectionWidget = new QFrame(tab);
        generalSceneCollectionWidget->setObjectName(QString::fromUtf8("generalSceneCollectionWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(generalSceneCollectionWidget->sizePolicy().hasHeightForWidth());
        generalSceneCollectionWidget->setSizePolicy(sizePolicy2);
        generalSceneCollectionWidget->setFrameShape(QFrame::NoFrame);
        generalSceneCollectionWidget->setFrameShadow(QFrame::Plain);
        generalSceneCollectionWidget->setLineWidth(0);
        formLayout_2 = new QFormLayout(generalSceneCollectionWidget);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_2->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout_2->setVerticalSpacing(0);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        sceneCollectionNameLabel_GeneralLeft = new QLabel(generalSceneCollectionWidget);
        sceneCollectionNameLabel_GeneralLeft->setObjectName(QString::fromUtf8("sceneCollectionNameLabel_GeneralLeft"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        sceneCollectionNameLabel_GeneralLeft->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, sceneCollectionNameLabel_GeneralLeft);

        sceneCollectionNameLabel_GeneralRight = new QLabel(generalSceneCollectionWidget);
        sceneCollectionNameLabel_GeneralRight->setObjectName(QString::fromUtf8("sceneCollectionNameLabel_GeneralRight"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, sceneCollectionNameLabel_GeneralRight);


        verticalLayoutTabGeneral->addWidget(generalSceneCollectionWidget);

        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy2.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy2);
        formLayout = new QFormLayout(widget_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetNoConstraint);
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout->setVerticalSpacing(6);
        formLayout->setContentsMargins(4, 0, 4, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        sourcesComboBox = new QComboBox(widget_2);
        sourcesComboBox->setObjectName(QString::fromUtf8("sourcesComboBox"));
        sizePolicy2.setHeightForWidth(sourcesComboBox->sizePolicy().hasHeightForWidth());
        sourcesComboBox->setSizePolicy(sizePolicy2);
        sourcesComboBox->setMinimumSize(QSize(250, 0));

        formLayout->setWidget(0, QFormLayout::FieldRole, sourcesComboBox);

        captionWhenLabel = new QLabel(widget_2);
        captionWhenLabel->setObjectName(QString::fromUtf8("captionWhenLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, captionWhenLabel);

        captionWhenComboBox = new QComboBox(widget_2);
        captionWhenComboBox->setObjectName(QString::fromUtf8("captionWhenComboBox"));
        sizePolicy2.setHeightForWidth(captionWhenComboBox->sizePolicy().hasHeightForWidth());
        captionWhenComboBox->setSizePolicy(sizePolicy2);
        captionWhenComboBox->setMinimumSize(QSize(250, 0));

        formLayout->setWidget(1, QFormLayout::FieldRole, captionWhenComboBox);

        muteSourceLabel = new QLabel(widget_2);
        muteSourceLabel->setObjectName(QString::fromUtf8("muteSourceLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, muteSourceLabel);

        muteSourceComboBox = new QComboBox(widget_2);
        muteSourceComboBox->setObjectName(QString::fromUtf8("muteSourceComboBox"));
        sizePolicy2.setHeightForWidth(muteSourceComboBox->sizePolicy().hasHeightForWidth());
        muteSourceComboBox->setSizePolicy(sizePolicy2);
        muteSourceComboBox->setMinimumSize(QSize(250, 0));

        formLayout->setWidget(2, QFormLayout::FieldRole, muteSourceComboBox);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(120, 0));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        languageComboBox = new QComboBox(widget_2);
        languageComboBox->setObjectName(QString::fromUtf8("languageComboBox"));
        sizePolicy2.setHeightForWidth(languageComboBox->sizePolicy().hasHeightForWidth());
        languageComboBox->setSizePolicy(sizePolicy2);
        languageComboBox->setMinimumSize(QSize(250, 0));

        formLayout->setWidget(3, QFormLayout::FieldRole, languageComboBox);

        languageWarningLabel = new QLabel(widget_2);
        languageWarningLabel->setObjectName(QString::fromUtf8("languageWarningLabel"));
        languageWarningLabel->setMinimumSize(QSize(242, 70));
        languageWarningLabel->setStyleSheet(QString::fromUtf8("border: 1px solid red;"));
        languageWarningLabel->setWordWrap(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, languageWarningLabel);

        profanitFilterLabel = new QLabel(widget_2);
        profanitFilterLabel->setObjectName(QString::fromUtf8("profanitFilterLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, profanitFilterLabel);

        profanityFilterComboBox = new QComboBox(widget_2);
        profanityFilterComboBox->setObjectName(QString::fromUtf8("profanityFilterComboBox"));
        sizePolicy2.setHeightForWidth(profanityFilterComboBox->sizePolicy().hasHeightForWidth());
        profanityFilterComboBox->setSizePolicy(sizePolicy2);
        profanityFilterComboBox->setMinimumSize(QSize(250, 0));

        formLayout->setWidget(5, QFormLayout::FieldRole, profanityFilterComboBox);

        apiKeyLabel = new QLabel(widget_2);
        apiKeyLabel->setObjectName(QString::fromUtf8("apiKeyLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, apiKeyLabel);

        apiKeyWidget = new QWidget(widget_2);
        apiKeyWidget->setObjectName(QString::fromUtf8("apiKeyWidget"));
        apiKeyWidget->setMinimumSize(QSize(250, 0));
        horizontalLayout_2 = new QHBoxLayout(apiKeyWidget);
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        apiKeyLineEdit = new QLineEdit(apiKeyWidget);
        apiKeyLineEdit->setObjectName(QString::fromUtf8("apiKeyLineEdit"));
        apiKeyLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(apiKeyLineEdit);

        apiKeyShowPushButton = new QPushButton(apiKeyWidget);
        apiKeyShowPushButton->setObjectName(QString::fromUtf8("apiKeyShowPushButton"));

        horizontalLayout_2->addWidget(apiKeyShowPushButton);


        formLayout->setWidget(6, QFormLayout::FieldRole, apiKeyWidget);


        verticalLayoutTabGeneral->addWidget(widget_2);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setFont(font);

        verticalLayoutTabGeneral->addWidget(label_5);

        frame = new QFrame(tab);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        formLayout_5 = new QFormLayout(frame);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_5->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout_5->setContentsMargins(4, 0, 4, 4);
        nativeOutputToLabel = new QLabel(frame);
        nativeOutputToLabel->setObjectName(QString::fromUtf8("nativeOutputToLabel"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, nativeOutputToLabel);

        outputTargetComboBox = new QComboBox(frame);
        outputTargetComboBox->setObjectName(QString::fromUtf8("outputTargetComboBox"));
        sizePolicy2.setHeightForWidth(outputTargetComboBox->sizePolicy().hasHeightForWidth());
        outputTargetComboBox->setSizePolicy(sizePolicy2);
        outputTargetComboBox->setMinimumSize(QSize(250, 0));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, outputTargetComboBox);

        nativeLineCountLabel = new QLabel(frame);
        nativeLineCountLabel->setObjectName(QString::fromUtf8("nativeLineCountLabel"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, nativeLineCountLabel);

        lineCountSpinBox = new QSpinBox(frame);
        lineCountSpinBox->setObjectName(QString::fromUtf8("lineCountSpinBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineCountSpinBox->sizePolicy().hasHeightForWidth());
        lineCountSpinBox->setSizePolicy(sizePolicy4);
        lineCountSpinBox->setMinimum(1);
        lineCountSpinBox->setMaximum(4);
        lineCountSpinBox->setValue(3);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, lineCountSpinBox);

        nativeForceLinebreaksLabel = new QLabel(frame);
        nativeForceLinebreaksLabel->setObjectName(QString::fromUtf8("nativeForceLinebreaksLabel"));

        formLayout_5->setWidget(4, QFormLayout::LabelRole, nativeForceLinebreaksLabel);

        widget_7 = new QWidget(frame);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setSpacing(14);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        insertLinebreaksCheckBox = new QCheckBox(widget_7);
        insertLinebreaksCheckBox->setObjectName(QString::fromUtf8("insertLinebreaksCheckBox"));

        horizontalLayout_5->addWidget(insertLinebreaksCheckBox);

        nativeLinebreaksNotRecommendendLabel = new QLabel(widget_7);
        nativeLinebreaksNotRecommendendLabel->setObjectName(QString::fromUtf8("nativeLinebreaksNotRecommendendLabel"));

        horizontalLayout_5->addWidget(nativeLinebreaksNotRecommendendLabel);

        horizontalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        formLayout_5->setWidget(4, QFormLayout::FieldRole, widget_7);

        captionTimeoutEnabledCheckBox = new QCheckBox(frame);
        captionTimeoutEnabledCheckBox->setObjectName(QString::fromUtf8("captionTimeoutEnabledCheckBox"));

        formLayout_5->setWidget(5, QFormLayout::LabelRole, captionTimeoutEnabledCheckBox);

        captionTimeoutDoubleSpinBox = new QDoubleSpinBox(frame);
        captionTimeoutDoubleSpinBox->setObjectName(QString::fromUtf8("captionTimeoutDoubleSpinBox"));
        captionTimeoutDoubleSpinBox->setDecimals(1);

        formLayout_5->setWidget(5, QFormLayout::FieldRole, captionTimeoutDoubleSpinBox);

        label_22 = new QLabel(frame);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_22);

        addPunctuationCheckBox = new QCheckBox(frame);
        addPunctuationCheckBox->setObjectName(QString::fromUtf8("addPunctuationCheckBox"));

        formLayout_5->setWidget(2, QFormLayout::FieldRole, addPunctuationCheckBox);

        label_15 = new QLabel(frame);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label_15);

        capitalizationComboBox = new QComboBox(frame);
        capitalizationComboBox->setObjectName(QString::fromUtf8("capitalizationComboBox"));
        sizePolicy2.setHeightForWidth(capitalizationComboBox->sizePolicy().hasHeightForWidth());
        capitalizationComboBox->setSizePolicy(sizePolicy2);
        capitalizationComboBox->setMinimumSize(QSize(250, 0));

        formLayout_5->setWidget(3, QFormLayout::FieldRole, capitalizationComboBox);


        verticalLayoutTabGeneral->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutTabGeneral->addItem(verticalSpacer);

        bottomTextBrowser = new QTextBrowser(tab);
        bottomTextBrowser->setObjectName(QString::fromUtf8("bottomTextBrowser"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(bottomTextBrowser->sizePolicy().hasHeightForWidth());
        bottomTextBrowser->setSizePolicy(sizePolicy5);
        bottomTextBrowser->setMaximumSize(QSize(16777215, 95));
        QFont font1;
        font1.setFamily(QString::fromUtf8(".SF NS"));
        font1.setPointSize(11);
        bottomTextBrowser->setFont(font1);

        verticalLayoutTabGeneral->addWidget(bottomTextBrowser);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayoutTabTranscripts = new QVBoxLayout(tab_2);
        verticalLayoutTabTranscripts->setObjectName(QString::fromUtf8("verticalLayoutTabTranscripts"));
        verticalLayoutTabTranscripts->setContentsMargins(4, 12, 12, 4);
        saveTranscriptsCheckBox = new QCheckBox(tab_2);
        saveTranscriptsCheckBox->setObjectName(QString::fromUtf8("saveTranscriptsCheckBox"));

        verticalLayoutTabTranscripts->addWidget(saveTranscriptsCheckBox);

        transcripWidget1 = new QWidget(tab_2);
        transcripWidget1->setObjectName(QString::fromUtf8("transcripWidget1"));
        sizePolicy2.setHeightForWidth(transcripWidget1->sizePolicy().hasHeightForWidth());
        transcripWidget1->setSizePolicy(sizePolicy2);
        formLayout_3 = new QFormLayout(transcripWidget1);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_3->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout_3->setVerticalSpacing(4);
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(transcripWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_9);

        label_17 = new QLabel(transcripWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_17);

        transcriptFormatComboBox = new QComboBox(transcripWidget1);
        transcriptFormatComboBox->setObjectName(QString::fromUtf8("transcriptFormatComboBox"));
        transcriptFormatComboBox->setMinimumSize(QSize(250, 0));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, transcriptFormatComboBox);

        label_10 = new QLabel(transcripWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_10);

        transcriptsEnabledStreamCheckBox = new QCheckBox(transcripWidget1);
        transcriptsEnabledStreamCheckBox->setObjectName(QString::fromUtf8("transcriptsEnabledStreamCheckBox"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, transcriptsEnabledStreamCheckBox);

        transcriptsEnabledRecordingCheckBox = new QCheckBox(transcripWidget1);
        transcriptsEnabledRecordingCheckBox->setObjectName(QString::fromUtf8("transcriptsEnabledRecordingCheckBox"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, transcriptsEnabledRecordingCheckBox);

        transcriptsEnabledVirtualcamCheckBox = new QCheckBox(transcripWidget1);
        transcriptsEnabledVirtualcamCheckBox->setObjectName(QString::fromUtf8("transcriptsEnabledVirtualcamCheckBox"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, transcriptsEnabledVirtualcamCheckBox);


        verticalLayoutTabTranscripts->addWidget(transcripWidget1);

        transcripWidget2 = new QWidget(tab_2);
        transcripWidget2->setObjectName(QString::fromUtf8("transcripWidget2"));
        horizontalLayout_3 = new QHBoxLayout(transcripWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        transcriptFolderPathLineEdit = new QLineEdit(transcripWidget2);
        transcriptFolderPathLineEdit->setObjectName(QString::fromUtf8("transcriptFolderPathLineEdit"));

        horizontalLayout_3->addWidget(transcriptFolderPathLineEdit);

        transcriptFolderPickerPushButton = new QPushButton(transcripWidget2);
        transcriptFolderPickerPushButton->setObjectName(QString::fromUtf8("transcriptFolderPickerPushButton"));

        horizontalLayout_3->addWidget(transcriptFolderPickerPushButton);


        verticalLayoutTabTranscripts->addWidget(transcripWidget2);

        transcripWidget3 = new QFrame(tab_2);
        transcripWidget3->setObjectName(QString::fromUtf8("transcripWidget3"));
        sizePolicy2.setHeightForWidth(transcripWidget3->sizePolicy().hasHeightForWidth());
        transcripWidget3->setSizePolicy(sizePolicy2);
        transcripWidget3->setFrameShape(QFrame::StyledPanel);
        verticalLayout_6 = new QVBoxLayout(transcripWidget3);
        verticalLayout_6->setSpacing(4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(4, 4, 4, 4);
        label_7 = new QLabel(transcripWidget3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_6->addWidget(label_7);

        streamingTranscriptFilenameComboBox = new QComboBox(transcripWidget3);
        streamingTranscriptFilenameComboBox->setObjectName(QString::fromUtf8("streamingTranscriptFilenameComboBox"));
        streamingTranscriptFilenameComboBox->setMinimumSize(QSize(250, 0));

        verticalLayout_6->addWidget(streamingTranscriptFilenameComboBox);

        streamingTranscriptCustomNameWidget = new QWidget(transcripWidget3);
        streamingTranscriptCustomNameWidget->setObjectName(QString::fromUtf8("streamingTranscriptCustomNameWidget"));
        horizontalLayout_7 = new QHBoxLayout(streamingTranscriptCustomNameWidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(streamingTranscriptCustomNameWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy3.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy3);

        horizontalLayout_7->addWidget(label_8);

        streamingTranscriptCustomNameExistsCombobox = new QComboBox(streamingTranscriptCustomNameWidget);
        streamingTranscriptCustomNameExistsCombobox->setObjectName(QString::fromUtf8("streamingTranscriptCustomNameExistsCombobox"));

        horizontalLayout_7->addWidget(streamingTranscriptCustomNameExistsCombobox);


        verticalLayout_6->addWidget(streamingTranscriptCustomNameWidget);

        streamingTranscriptCustomNameOverwriteLineEdit = new QLineEdit(transcripWidget3);
        streamingTranscriptCustomNameOverwriteLineEdit->setObjectName(QString::fromUtf8("streamingTranscriptCustomNameOverwriteLineEdit"));

        verticalLayout_6->addWidget(streamingTranscriptCustomNameOverwriteLineEdit);


        verticalLayoutTabTranscripts->addWidget(transcripWidget3);

        transcripWidget4 = new QFrame(tab_2);
        transcripWidget4->setObjectName(QString::fromUtf8("transcripWidget4"));
        sizePolicy2.setHeightForWidth(transcripWidget4->sizePolicy().hasHeightForWidth());
        transcripWidget4->setSizePolicy(sizePolicy2);
        transcripWidget4->setFrameShape(QFrame::StyledPanel);
        verticalLayout_5 = new QVBoxLayout(transcripWidget4);
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(4, 4, 4, 4);
        label_3 = new QLabel(transcripWidget4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        recordingTranscriptFilenameComboBox = new QComboBox(transcripWidget4);
        recordingTranscriptFilenameComboBox->setObjectName(QString::fromUtf8("recordingTranscriptFilenameComboBox"));
        recordingTranscriptFilenameComboBox->setMinimumSize(QSize(250, 0));

        verticalLayout_5->addWidget(recordingTranscriptFilenameComboBox);

        recordingTranscriptCustomNameWidget = new QWidget(transcripWidget4);
        recordingTranscriptCustomNameWidget->setObjectName(QString::fromUtf8("recordingTranscriptCustomNameWidget"));
        horizontalLayout_6 = new QHBoxLayout(recordingTranscriptCustomNameWidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(recordingTranscriptCustomNameWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(label_2);

        recordingTranscriptCustomNameExistsCombobox = new QComboBox(recordingTranscriptCustomNameWidget);
        recordingTranscriptCustomNameExistsCombobox->setObjectName(QString::fromUtf8("recordingTranscriptCustomNameExistsCombobox"));

        horizontalLayout_6->addWidget(recordingTranscriptCustomNameExistsCombobox);


        verticalLayout_5->addWidget(recordingTranscriptCustomNameWidget);

        recordingTranscriptCustomNameOverwriteLineEdit = new QLineEdit(transcripWidget4);
        recordingTranscriptCustomNameOverwriteLineEdit->setObjectName(QString::fromUtf8("recordingTranscriptCustomNameOverwriteLineEdit"));

        verticalLayout_5->addWidget(recordingTranscriptCustomNameOverwriteLineEdit);


        verticalLayoutTabTranscripts->addWidget(transcripWidget4);

        transcripWidget5 = new QFrame(tab_2);
        transcripWidget5->setObjectName(QString::fromUtf8("transcripWidget5"));
        sizePolicy2.setHeightForWidth(transcripWidget5->sizePolicy().hasHeightForWidth());
        transcripWidget5->setSizePolicy(sizePolicy2);
        transcripWidget5->setFrameShape(QFrame::StyledPanel);
        verticalLayout_8 = new QVBoxLayout(transcripWidget5);
        verticalLayout_8->setSpacing(4);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(4, 4, 4, 4);
        label_14 = new QLabel(transcripWidget5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_8->addWidget(label_14);

        virtualcamTranscriptFilenameComboBox = new QComboBox(transcripWidget5);
        virtualcamTranscriptFilenameComboBox->setObjectName(QString::fromUtf8("virtualcamTranscriptFilenameComboBox"));
        virtualcamTranscriptFilenameComboBox->setMinimumSize(QSize(250, 0));

        verticalLayout_8->addWidget(virtualcamTranscriptFilenameComboBox);

        virtualcamTranscriptCustomNameWidget = new QWidget(transcripWidget5);
        virtualcamTranscriptCustomNameWidget->setObjectName(QString::fromUtf8("virtualcamTranscriptCustomNameWidget"));
        horizontalLayout_8 = new QHBoxLayout(virtualcamTranscriptCustomNameWidget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(virtualcamTranscriptCustomNameWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy3.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy3);

        horizontalLayout_8->addWidget(label_21);

        virtualcamTranscriptCustomNameExistsCombobox = new QComboBox(virtualcamTranscriptCustomNameWidget);
        virtualcamTranscriptCustomNameExistsCombobox->setObjectName(QString::fromUtf8("virtualcamTranscriptCustomNameExistsCombobox"));

        horizontalLayout_8->addWidget(virtualcamTranscriptCustomNameExistsCombobox);


        verticalLayout_8->addWidget(virtualcamTranscriptCustomNameWidget);

        virtualcamTranscriptCustomNameOverwriteLineEdit = new QLineEdit(transcripWidget5);
        virtualcamTranscriptCustomNameOverwriteLineEdit->setObjectName(QString::fromUtf8("virtualcamTranscriptCustomNameOverwriteLineEdit"));

        verticalLayout_8->addWidget(virtualcamTranscriptCustomNameOverwriteLineEdit);


        verticalLayoutTabTranscripts->addWidget(transcripWidget5);

        transcriptSrtSettingsWidget = new QWidget(tab_2);
        transcriptSrtSettingsWidget->setObjectName(QString::fromUtf8("transcriptSrtSettingsWidget"));
        formLayout_4 = new QFormLayout(transcriptSrtSettingsWidget);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_4->setVerticalSpacing(4);
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(transcriptSrtSettingsWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_18);

        label_19 = new QLabel(transcriptSrtSettingsWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_19);

        srtDurationSpinBox = new QSpinBox(transcriptSrtSettingsWidget);
        srtDurationSpinBox->setObjectName(QString::fromUtf8("srtDurationSpinBox"));
        srtDurationSpinBox->setMinimum(1);
        srtDurationSpinBox->setMaximum(999);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, srtDurationSpinBox);

        label_20 = new QLabel(transcriptSrtSettingsWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_20);

        srtLineLengthSpinBox = new QSpinBox(transcriptSrtSettingsWidget);
        srtLineLengthSpinBox->setObjectName(QString::fromUtf8("srtLineLengthSpinBox"));
        srtLineLengthSpinBox->setMinimum(10);
        srtLineLengthSpinBox->setMaximum(9999999);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, srtLineLengthSpinBox);

        label_11 = new QLabel(transcriptSrtSettingsWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_11);

        srtCapitalizationComboBox = new QComboBox(transcriptSrtSettingsWidget);
        srtCapitalizationComboBox->setObjectName(QString::fromUtf8("srtCapitalizationComboBox"));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, srtCapitalizationComboBox);

        srtSplitSentencesCheckBox = new QCheckBox(transcriptSrtSettingsWidget);
        srtSplitSentencesCheckBox->setObjectName(QString::fromUtf8("srtSplitSentencesCheckBox"));

        formLayout_4->setWidget(5, QFormLayout::SpanningRole, srtSplitSentencesCheckBox);

        label_12 = new QLabel(transcriptSrtSettingsWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_4->setWidget(6, QFormLayout::LabelRole, label_12);

        srtAddPunctuationCheckBox = new QCheckBox(transcriptSrtSettingsWidget);
        srtAddPunctuationCheckBox->setObjectName(QString::fromUtf8("srtAddPunctuationCheckBox"));

        formLayout_4->setWidget(4, QFormLayout::SpanningRole, srtAddPunctuationCheckBox);


        verticalLayoutTabTranscripts->addWidget(transcriptSrtSettingsWidget);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayoutTabOpenCaptions = new QVBoxLayout(tab_3);
        verticalLayoutTabOpenCaptions->setObjectName(QString::fromUtf8("verticalLayoutTabOpenCaptions"));
        verticalLayoutTabOpenCaptions->setContentsMargins(4, -1, -1, -1);
        textOutputsListScrollArea = new QScrollArea(tab_3);
        textOutputsListScrollArea->setObjectName(QString::fromUtf8("textOutputsListScrollArea"));
        textOutputsListScrollArea->setFrameShape(QFrame::NoFrame);
        textOutputsListScrollArea->setFrameShadow(QFrame::Plain);
        textOutputsListScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textOutputsListScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 379, 745));
        textOutputsListScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayoutTabOpenCaptions->addWidget(textOutputsListScrollArea);

        tabWidget->addTab(tab_3, QString());
        filterTab = new QWidget();
        filterTab->setObjectName(QString::fromUtf8("filterTab"));
        verticalLayoutTabTextFiltering = new QVBoxLayout(filterTab);
        verticalLayoutTabTextFiltering->setObjectName(QString::fromUtf8("verticalLayoutTabTextFiltering"));
        verticalLayoutTabTextFiltering->setContentsMargins(4, -1, 4, -1);
        label_4 = new QLabel(filterTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayoutTabTextFiltering->addWidget(label_4);

        wordReplacementTableWidget = new QTableWidget(filterTab);
        if (wordReplacementTableWidget->columnCount() < 4)
            wordReplacementTableWidget->setColumnCount(4);
        wordReplacementTableWidget->setObjectName(QString::fromUtf8("wordReplacementTableWidget"));
        wordReplacementTableWidget->setRowCount(0);
        wordReplacementTableWidget->setColumnCount(4);
        wordReplacementTableWidget->horizontalHeader()->setDefaultSectionSize(50);
        wordReplacementTableWidget->verticalHeader()->setCascadingSectionResizes(true);

        verticalLayoutTabTextFiltering->addWidget(wordReplacementTableWidget);

        replacementWordsAddWordPushButton = new QPushButton(filterTab);
        replacementWordsAddWordPushButton->setObjectName(QString::fromUtf8("replacementWordsAddWordPushButton"));
        sizePolicy4.setHeightForWidth(replacementWordsAddWordPushButton->sizePolicy().hasHeightForWidth());
        replacementWordsAddWordPushButton->setSizePolicy(sizePolicy4);

        verticalLayoutTabTextFiltering->addWidget(replacementWordsAddWordPushButton);

        tabWidget->addTab(filterTab, QString());

        verticalLayoutMainScrollContainer->addWidget(tabWidget);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayoutMainOuter->addWidget(scrollArea);

        footer_save_widget = new QWidget(CaptionSettingsWidget);
        footer_save_widget->setObjectName(QString::fromUtf8("footer_save_widget"));
        sizePolicy2.setHeightForWidth(footer_save_widget->sizePolicy().hasHeightForWidth());
        footer_save_widget->setSizePolicy(sizePolicy2);
        horizontalLayout = new QHBoxLayout(footer_save_widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        previewPushButton = new QPushButton(footer_save_widget);
        previewPushButton->setObjectName(QString::fromUtf8("previewPushButton"));

        horizontalLayout->addWidget(previewPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelPushButton = new QPushButton(footer_save_widget);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));

        horizontalLayout->addWidget(cancelPushButton);

        savePushButton = new QPushButton(footer_save_widget);
        savePushButton->setObjectName(QString::fromUtf8("savePushButton"));

        horizontalLayout->addWidget(savePushButton);


        verticalLayoutMainOuter->addWidget(footer_save_widget);


        retranslateUi(CaptionSettingsWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CaptionSettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *CaptionSettingsWidget)
    {
        CaptionSettingsWidget->setWindowTitle(QCoreApplication::translate("CaptionSettingsWidget", "Caption Settings", nullptr));
        enabledCheckBox->setText(QCoreApplication::translate("CaptionSettingsWidget", "Captioning Enabled", nullptr));
        sceneCollectionNameLabel_GeneralLeft->setText(QCoreApplication::translate("CaptionSettingsWidget", "Scene Collection", nullptr));
        sceneCollectionNameLabel_GeneralRight->setText(QCoreApplication::translate("CaptionSettingsWidget", "Name", nullptr));
        label->setText(QCoreApplication::translate("CaptionSettingsWidget", "Caption Source", nullptr));
        captionWhenLabel->setText(QCoreApplication::translate("CaptionSettingsWidget", "Caption When", nullptr));
        muteSourceLabel->setText(QCoreApplication::translate("CaptionSettingsWidget", "Mute Source", nullptr));
        label_6->setText(QCoreApplication::translate("CaptionSettingsWidget", "Language ", nullptr));
        languageWarningLabel->setText(QCoreApplication::translate("CaptionSettingsWidget", "Note: This language does not support native caption output to streams and recordings. Only Open Captions and Transcripts will work correctly.", nullptr));
        profanitFilterLabel->setText(QCoreApplication::translate("CaptionSettingsWidget", "Profanity Filter", nullptr));
        apiKeyLabel->setText(QCoreApplication::translate("CaptionSettingsWidget", "API Key", nullptr));
        apiKeyShowPushButton->setText(QCoreApplication::translate("CaptionSettingsWidget", "Show", nullptr));
        label_5->setText(QCoreApplication::translate("CaptionSettingsWidget", "Native Captions (608, Twitch)", nullptr));
        nativeOutputToLabel->setText(QCoreApplication::translate("CaptionSettingsWidget", "Output To", nullptr));
        nativeLineCountLabel->setText(QCoreApplication::translate("CaptionSettingsWidget", "Lines", nullptr));
        nativeForceLinebreaksLabel->setText(QCoreApplication::translate("CaptionSettingsWidget", "Force Linebreaks", nullptr));
        insertLinebreaksCheckBox->setText(QString());
        nativeLinebreaksNotRecommendendLabel->setText(QCoreApplication::translate("CaptionSettingsWidget", "(Not Recommended For Twitch)", nullptr));
        captionTimeoutEnabledCheckBox->setText(QCoreApplication::translate("CaptionSettingsWidget", "Caption Timeout", nullptr));
        label_22->setText(QCoreApplication::translate("CaptionSettingsWidget", "Add Punctuation ", nullptr));
        addPunctuationCheckBox->setText(QString());
        label_15->setText(QCoreApplication::translate("CaptionSettingsWidget", "Capitalization", nullptr));
        bottomTextBrowser->setHtml(QCoreApplication::translate("CaptionSettingsWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"                                                            <html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"                                                            p, li { white-space: pre-wrap; }\n"
"                                                            </style></head><body style=\" font-family:'.SF NS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"                                                            <p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:10pt;\">Closed Captioning plugin using Google Speech-To-Text Cloud API. Audio data sent to Google for captioning!</span></p>\n"
"                                                            <p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; "
                        "margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'.SF NS Text'; font-size:10pt;\"><br /></p>\n"
"                                                            <p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:10pt;\">Experimental Version ${VERSION_STRING} by RatWithAShotgun.</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CaptionSettingsWidget", "General", nullptr));
        saveTranscriptsCheckBox->setText(QCoreApplication::translate("CaptionSettingsWidget", "Save Transcripts", nullptr));
        label_9->setText(QCoreApplication::translate("CaptionSettingsWidget", "Save For", nullptr));
        label_17->setText(QCoreApplication::translate("CaptionSettingsWidget", "Format", nullptr));
        label_10->setText(QCoreApplication::translate("CaptionSettingsWidget", "Transcript Folder:", nullptr));
        transcriptsEnabledStreamCheckBox->setText(QCoreApplication::translate("CaptionSettingsWidget", "Streams", nullptr));
        transcriptsEnabledRecordingCheckBox->setText(QCoreApplication::translate("CaptionSettingsWidget", "Recordings", nullptr));
        transcriptsEnabledVirtualcamCheckBox->setText(QCoreApplication::translate("CaptionSettingsWidget", "Virtual Cam", nullptr));
        transcriptFolderPathLineEdit->setPlaceholderText(QCoreApplication::translate("CaptionSettingsWidget", "Transcript Folder", nullptr));
        transcriptFolderPickerPushButton->setText(QCoreApplication::translate("CaptionSettingsWidget", "Choose", nullptr));
        label_7->setText(QCoreApplication::translate("CaptionSettingsWidget", "Transcript Filenames (Streams)", nullptr));
        label_8->setText(QCoreApplication::translate("CaptionSettingsWidget", "If File Exists", nullptr));
        streamingTranscriptCustomNameOverwriteLineEdit->setPlaceholderText(QCoreApplication::translate("CaptionSettingsWidget", "custom file name (must include extension yourself)", nullptr));
        label_3->setText(QCoreApplication::translate("CaptionSettingsWidget", "Transcript Filenames (Recordings)", nullptr));
        label_2->setText(QCoreApplication::translate("CaptionSettingsWidget", "If File Exists", nullptr));
        recordingTranscriptCustomNameOverwriteLineEdit->setPlaceholderText(QCoreApplication::translate("CaptionSettingsWidget", "custom file name (must include extension yourself)", nullptr));
        label_14->setText(QCoreApplication::translate("CaptionSettingsWidget", "Transcript Filenames (Virtualcam)", nullptr));
        label_21->setText(QCoreApplication::translate("CaptionSettingsWidget", "If File Exists", nullptr));
        virtualcamTranscriptCustomNameOverwriteLineEdit->setPlaceholderText(QCoreApplication::translate("CaptionSettingsWidget", "custom file name (must include extension yourself)", nullptr));
        label_18->setText(QCoreApplication::translate("CaptionSettingsWidget", "SRT Settings", nullptr));
        label_19->setText(QCoreApplication::translate("CaptionSettingsWidget", "Preferred Caption Duration", nullptr));
        srtDurationSpinBox->setSpecialValueText(QString());
        srtDurationSpinBox->setSuffix(QCoreApplication::translate("CaptionSettingsWidget", " secs", nullptr));
        label_20->setText(QCoreApplication::translate("CaptionSettingsWidget", "Max Line Length", nullptr));
        srtLineLengthSpinBox->setSuffix(QCoreApplication::translate("CaptionSettingsWidget", " characters", nullptr));
        label_11->setText(QCoreApplication::translate("CaptionSettingsWidget", "Capitalization", nullptr));
        srtSplitSentencesCheckBox->setText(QCoreApplication::translate("CaptionSettingsWidget", "Split Sentences Longer Than Preferred Duration", nullptr));
        label_12->setText(QString());
        srtAddPunctuationCheckBox->setText(QCoreApplication::translate("CaptionSettingsWidget", "Add Punctuation ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CaptionSettingsWidget", "Transcripts", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("CaptionSettingsWidget", "Open Captions", nullptr));
        label_4->setText(QCoreApplication::translate("CaptionSettingsWidget", "Text Replacements", nullptr));
        replacementWordsAddWordPushButton->setText(QCoreApplication::translate("CaptionSettingsWidget", "Add Text Replacement", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(filterTab), QCoreApplication::translate("CaptionSettingsWidget", "Text Filtering", nullptr));
        previewPushButton->setText(QCoreApplication::translate("CaptionSettingsWidget", "Show Preview", nullptr));
        cancelPushButton->setText(QCoreApplication::translate("CaptionSettingsWidget", "Cancel", nullptr));
        savePushButton->setText(QCoreApplication::translate("CaptionSettingsWidget", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CaptionSettingsWidget: public Ui_CaptionSettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTIONSETTINGSWIDGET_H
