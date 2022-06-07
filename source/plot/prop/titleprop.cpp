#include "titleprop.h"


TitleProp::TitleProp()
    :text(""),font(QFont("sans", 12, QFont::Bold))
{

}

TitleProp::TitleProp(const QString &_text, QFont _font)
    :text(_text),font(_font)
{

}
