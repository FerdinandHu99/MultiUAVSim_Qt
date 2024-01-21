#include <QQmlEngine>
#include "settingsmanage.h"

SettingsManage::SettingsManage(QObject *parent)
    : QObject{parent}
{
}

SettingsManage::~SettingsManage()
{

}

void SettingsManage::setSettingsFilePath(const QString &filePath)
{
    _settingsFilePath = filePath;
    readSettingsFile();
}

QVariant SettingsManage::readKeyValue(const QString &key)
{
    return _jsonObject.value(key);
}

void SettingsManage::writeKeyValue(const QString &key, const QString &value)
{
    _jsonObject.insert(key, value);
    writeSettingsFile();
}

void SettingsManage::addNewUAV(const QString &uavName, const QJsonObject &uavData)
{
    QJsonObject vehiclesObject = _jsonObject.value("Vehicles").toObject();

    vehiclesObject.insert(uavName, uavData);

    _jsonObject["Vehicles"] = vehiclesObject;

    writeSettingsFile();
}

void SettingsManage::readSettingsFile()
{
    QFile file(_settingsFilePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray data = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);

        if (jsonDoc.isObject())
        {
            _jsonObject = jsonDoc.object();
        }
        else
        {
            qWarning() << "Invalid JSON format in the config file.";
        }

        file.close();
    }
    else
    {
        qWarning() << "Failed to open the settings file for reading.";
    }
}

void SettingsManage::writeSettingsFile()
{
    QFile file(_settingsFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QJsonDocument jsonDoc(_jsonObject);
        file.write(jsonDoc.toJson());
        file.close();
    }
    else
    {
        qWarning() << "Failed to open the settings file for writing.";
    }
}

