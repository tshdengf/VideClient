#pragma once
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qfile.h>
#include <qjsonarray.h>
class JsonUtils
{
public:
	static QByteArray ObjToByteArray(QJsonObject obj);

	static bool JsonObjToFile(QJsonArray obj, QString filePath);

	static QJsonArray JsonFromFile(QString filePath);
};

