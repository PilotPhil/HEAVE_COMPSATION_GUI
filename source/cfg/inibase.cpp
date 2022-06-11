#include "inibase.h"

#include <QCoreApplication>

IniBase *IniBase::m_Instance = nullptr;

IniBase *IniBase::GetInstance() {
  if (m_Instance == nullptr) {
    m_Instance = new IniBase();
  }
  return m_Instance;
}

IniBase::IniBase(QObject *parent) : QObject(parent) {
  iniPath = QCoreApplication::applicationDirPath() + "/pid.ini";
  qsetting = new QSettings(iniPath, QSettings::IniFormat);
}

IniBase::~IniBase() { delete qsetting; }

QString IniBase::getValue(const QString &key) {
  auto res = qsetting->value(key);

  QString str;

  if (res.isNull() == false && res.isValid() == true) {
    str = res.toString();
  }

  return str;
}

void IniBase::setValue(const QString &key, const QString &value) {
  qsetting->setValue(key, value);
}
