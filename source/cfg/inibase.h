#ifndef INIBASE_H
#define INIBASE_H

#include <QObject>

#include <QSettings>

class IniBase : public QObject
{
    Q_OBJECT
public:
    static IniBase* m_Instance;
    static IniBase* GetInstance();

    QString getValue(const QString& key);

    void setValue(const QString& key,const QString& value);

private:
    explicit IniBase(QObject *parent = nullptr);

    ~IniBase();

    QString iniPath;

    QSettings* qsetting;

signals:

};

#endif // INIBASE_H
