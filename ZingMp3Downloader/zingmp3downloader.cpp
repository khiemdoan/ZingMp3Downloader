#include "zingmp3downloader.h"

ZingMp3Downloader::ZingMp3Downloader(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.btnCheck, SIGNAL(release()), this, SLOT(on_btnCheck_clicked()));
	connect(ui.btnDownload128, SIGNAL(release()), this, SLOT(on_btnDownload128_clicked()));
	connect(ui.btnDownload320, SIGNAL(release()), this, SLOT(on_btnDownload320_clicked()));
	connect(ui.btnDownloadLossless, SIGNAL(release()), this, SLOT(on_btnDownloadLossless_clicked()));
	connect(ui.btnPlay, SIGNAL(release()), this, SLOT(on_btnPlay_clicked()));
}

ZingMp3Downloader::~ZingMp3Downloader()
{
	if (player != nullptr) {
		delete player;
		player = nullptr;
	}
}

void ZingMp3Downloader::displayWarning()
{
	QMessageBox msgBox;
	msgBox.setIcon(QMessageBox::Warning);
	msgBox.setText(QString::fromUtf8("Có gì đó sai sai!!!"));
	msgBox.setInformativeText(QString::fromUtf8("Hãy bơm tiền cho Khiêm để Khiêm có thể tiếp tục hoàn thiện sản phẩm này."));
	msgBox.exec();
}

void ZingMp3Downloader::displayInfo(std::string content)
{
	QMessageBox msgBox;
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setText(QString::fromStdString(content));
	msgBox.exec();
}

void ZingMp3Downloader::on_btnCheck_clicked()
{
	ui.btnPlay->setEnabled(false);
	ui.btnDownload128->setEnabled(false);
	ui.btnDownload320->setEnabled(false);
	ui.btnDownloadLossless->setEnabled(false);
	
	ui.btnPlay->setText("Play");
	bPlaying = false;

	QString qsUrl = ui.lineEditUrl->text();

	if (player != nullptr) {
		delete player;
		player = nullptr;
	}
	m_song = Song();

	if (m_song.verifyLink(qsUrl.toStdString()) == false) {
		displayWarning();
		return;
	}

	m_song.getLink(qsUrl.toStdString());

	if (m_song.isHas128()) {
		ui.btnPlay->setEnabled(true);

		QString sqUrl128 = QString::fromStdString(m_song.get128());

		player = new QMediaPlayer();
		player->setVolume(100);
		player->setMedia(QUrl(sqUrl128));
	}

	if (m_song.isHas128()) {
		ui.btnDownload128->setEnabled(true);
	}

	if (m_song.isHas320()) {
		ui.btnDownload320->setEnabled(true);
	}

	if (m_song.isHasLossless()) {
		ui.btnDownloadLossless->setEnabled(true);
	}
}

void ZingMp3Downloader::on_btnPlay_clicked()
{
	if (bPlaying == false) {
		if (player != nullptr) {
			player->play();
		}
		ui.btnPlay->setText("Pause");
	}
	else {
		if (player != nullptr) {
			player->pause();
		}
		ui.btnPlay->setText("Play");
	}
	bPlaying = !bPlaying;
}

void ZingMp3Downloader::on_btnDownload128_clicked()
{
	QString qsName = QString::fromStdString(m_song.getName() + " - " + m_song.getArtist());
	QString qsFile = QFileDialog::getSaveFileName(this, tr("Save File"), qsName, tr("Audio (*.mp3)"));
	if (qsFile.size() > 0) {
		m_song.download128(qsFile.toStdString());
		displayInfo("Tải xuống thành công");
	}
}

void ZingMp3Downloader::on_btnDownload320_clicked()
{
	QString qsName = QString::fromStdString(m_song.getName() + " - " + m_song.getArtist());
	QString qsFile = QFileDialog::getSaveFileName(this, tr("Save File"), qsName, tr("Audio (*.mp3)"));
	if (qsFile.size() > 0) {
		m_song.download320(qsFile.toStdString());
		displayInfo("Tải xuống thành công");
	}
}

void ZingMp3Downloader::on_btnDownloadLossless_clicked()
{
	QString qsName = QString::fromStdString(m_song.getName() + " - " + m_song.getArtist());
	QString qsFile = QFileDialog::getSaveFileName(this, tr("Save File"), qsName, tr("Audio (*.flac)"));
	if (qsFile.size() > 0) {
		m_song.downloadLossless(qsFile.toStdString());
		displayInfo("Tải xuống thành công");
	}
}
