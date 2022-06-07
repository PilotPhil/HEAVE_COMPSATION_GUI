#ifndef TITLEPROP_H
#define TITLEPROP_H

#include <QObject>
#include <QString>
#include <QFont>

struct TitleProp
{
    QString text;

    QFont font;

    TitleProp();

    TitleProp(const QString& _text,QFont _font);
};

#endif // TITLEPROP_H
