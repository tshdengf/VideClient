#pragma once
#include <qthread.h>
#include <qobjectdefs.h>
#include <atomic>

class FileProgressThread :
	public QThread
{
	Q_OBJECT
public:

	FileProgressThread(QString filePath);

	FileProgressThread(QObject *parent = 0);

	void run() override;
	QString file;

	QString GetCacheFile();

	void RecordFileCache(QString file, QString md5, long pos);

	long GetCacheSeek(QString md5);

signals:
	void updateProgress(const int num);
	void progressMsg(bool error, QString msg);

public slots:
	void StopOrStart();
	void Resume();
	void Pause();

private:
	std::atomic<bool> stopFlag;
	std::atomic<bool> startFlg;
};

