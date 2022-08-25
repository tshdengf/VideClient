#include "JsonUtils.h"

//对象转换BA
QByteArray JsonUtils::ObjToByteArray(QJsonObject obj)
{
	QJsonDocument jsonDoc(obj);
	
	return jsonDoc.toJson();
}

//Json对象File
bool JsonUtils::JsonObjToFile(QJsonArray obj,QString filePath)
{
	QJsonDocument jsonDoc(obj);

	QByteArray ba = jsonDoc.toJson();

	QFile file(filePath);

	if (!file.open(QIODevice::WriteOnly))
	{
		return false;
	}

	file.write(ba);
	file.close();
}

QJsonArray JsonUtils::JsonFromFile(QString filePath)
{
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly))
	{
		return QJsonArray();
	}

	QByteArray ba = file.readAll();
	QJsonParseError e;
	QJsonDocument doc =  QJsonDocument::fromJson(ba, &e);
	return doc.array();
}
