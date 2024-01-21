#include "multiuavsimqmlglobal.h"

MultiUAVSimQmlGlobal::MultiUAVSimQmlGlobal(QObject *parent)
    : QObject{parent}
{
    _settingsManage = new SettingsManage(this);
}
