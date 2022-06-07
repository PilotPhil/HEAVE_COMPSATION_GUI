#include "printprop.h"

PrintProp::PrintProp():
    savePath(R"(C:\Users\Public\Pictures)"),
    saveName("pic"),
    format(PrintFormat::JPG),
    scale(5),
    quality(100),
    resolution(650),
    isOpenOutputFolder(true)
{

}
