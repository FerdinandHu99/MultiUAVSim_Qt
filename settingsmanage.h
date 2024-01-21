#ifndef SETTINGSMANAGE_H
#define SETTINGSMANAGE_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

class SettingsManage : public QObject
{
    Q_OBJECT
public:
    explicit SettingsManage(QObject *parent = nullptr);
    virtual ~SettingsManage();

    Q_PROPERTY(QString settingsFilePath READ settingsFilePath WRITE setSettingsFilePath NOTIFY settingsFilePathChanged)

    QString settingsFilePath() const {return _settingsFilePath;}

    Q_INVOKABLE void setSettingsFilePath(const QString &filePath);
    Q_INVOKABLE QVariant readKeyValue(const QString &key);
    Q_INVOKABLE void writeKeyValue(const QString &key, const QString &value);

    Q_INVOKABLE void addNewUAV(const QString &uavName, const QJsonObject &uavData);
signals:
    void settingsFilePathChanged();

private:
    QString _settingsFilePath;
    QJsonObject _jsonObject;
    void readSettingsFile();
    void writeSettingsFile();
};

#endif // SETTINGSMANAGE_H
