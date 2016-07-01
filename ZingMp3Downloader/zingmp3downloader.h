#ifndef ZINGMP3DOWNLOADER_H
#define ZINGMP3DOWNLOADER_H

#include <QtWidgets/QMainWindow>
#include "ui_zingmp3downloader.h"
#include <QMessageBox.h>
#include <QFileDialog.h>
#include <QMediaPlayer.h>

#include "song.h"
#include "dkstd_string.h"

class ZingMp3Downloader : public QMainWindow
{
	Q_OBJECT

public:
	ZingMp3Downloader(QWidget *parent = 0);
	~ZingMp3Downloader();

private:
	Ui::ZingMp3DownloaderClass ui;
	void displayWarning();
	void displayInfo(std::string content);

	Song m_song;
	bool bPlaying = false;

	QMediaPlayer *player = nullptr;

private slots:
	void on_btnGetData_clicked();
	void on_btnPlay_clicked();
	void on_btnDownload128_clicked();
	void on_btnDownload320_clicked();
	void on_btnDownloadLossless_clicked();
};

#endif // ZINGMP3DOWNLOADER_H
