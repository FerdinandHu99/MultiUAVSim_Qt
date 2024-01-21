#ifndef MULTIUAVSIMQMLGLOBAL_H
#define MULTIUAVSIMQMLGLOBAL_H

#include <QObject>
#include "settingsmanage.h"

class MultiUAVSimQmlGlobal : public QObject
{
    Q_OBJECT
public:
    explicit MultiUAVSimQmlGlobal(QObject *parent = nullptr);
    Q_PROPERTY(SettingsManage* settingsManage READ settingsManage CONSTANT)

    SettingsManage* settingsManage() const {return _settingsManage;}
signals:

private:
    SettingsManage* _settingsManage = nullptr;
};

#endif // MULTIUAVSIMQMLGLOBAL_H
