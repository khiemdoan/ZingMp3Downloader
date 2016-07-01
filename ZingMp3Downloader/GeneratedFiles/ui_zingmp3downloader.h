/********************************************************************************
** Form generated from reading UI file 'zingmp3downloader.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZINGMP3DOWNLOADER_H
#define UI_ZINGMP3DOWNLOADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZingMp3DownloaderClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditUrl;
    QPushButton *btnGetData;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPlay;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnDownload128;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnDownload320;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnDownloadLossless;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QMainWindow *ZingMp3DownloaderClass)
    {
        if (ZingMp3DownloaderClass->objectName().isEmpty())
            ZingMp3DownloaderClass->setObjectName(QStringLiteral("ZingMp3DownloaderClass"));
        ZingMp3DownloaderClass->resize(505, 140);
        centralWidget = new QWidget(ZingMp3DownloaderClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 491, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEditUrl = new QLineEdit(verticalLayoutWidget);
        lineEditUrl->setObjectName(QStringLiteral("lineEditUrl"));

        horizontalLayout->addWidget(lineEditUrl);

        btnGetData = new QPushButton(verticalLayoutWidget);
        btnGetData->setObjectName(QStringLiteral("btnGetData"));

        horizontalLayout->addWidget(btnGetData);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnPlay = new QPushButton(verticalLayoutWidget);
        btnPlay->setObjectName(QStringLiteral("btnPlay"));
        btnPlay->setEnabled(false);

        horizontalLayout_2->addWidget(btnPlay);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        btnDownload128 = new QPushButton(verticalLayoutWidget);
        btnDownload128->setObjectName(QStringLiteral("btnDownload128"));
        btnDownload128->setEnabled(false);

        horizontalLayout_2->addWidget(btnDownload128);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnDownload320 = new QPushButton(verticalLayoutWidget);
        btnDownload320->setObjectName(QStringLiteral("btnDownload320"));
        btnDownload320->setEnabled(false);

        horizontalLayout_2->addWidget(btnDownload320);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnDownloadLossless = new QPushButton(verticalLayoutWidget);
        btnDownloadLossless->setObjectName(QStringLiteral("btnDownloadLossless"));
        btnDownloadLossless->setEnabled(false);

        horizontalLayout_2->addWidget(btnDownloadLossless);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        ZingMp3DownloaderClass->setCentralWidget(centralWidget);

        retranslateUi(ZingMp3DownloaderClass);

        QMetaObject::connectSlotsByName(ZingMp3DownloaderClass);
    } // setupUi

    void retranslateUi(QMainWindow *ZingMp3DownloaderClass)
    {
        ZingMp3DownloaderClass->setWindowTitle(QApplication::translate("ZingMp3DownloaderClass", "ZingMp3Downloader - KhiemDH", 0));
        btnGetData->setText(QApplication::translate("ZingMp3DownloaderClass", "Get Data", 0));
        btnPlay->setText(QApplication::translate("ZingMp3DownloaderClass", "Play", 0));
        btnDownload128->setText(QApplication::translate("ZingMp3DownloaderClass", "128", 0));
        btnDownload320->setText(QApplication::translate("ZingMp3DownloaderClass", "320", 0));
        btnDownloadLossless->setText(QApplication::translate("ZingMp3DownloaderClass", "Lossless", 0));
    } // retranslateUi

};

namespace Ui {
    class ZingMp3DownloaderClass: public Ui_ZingMp3DownloaderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZINGMP3DOWNLOADER_H
