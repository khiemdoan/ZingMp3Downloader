#include "zingmp3downloader.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ZingMp3Downloader w;
	w.show();
	return a.exec();
}
