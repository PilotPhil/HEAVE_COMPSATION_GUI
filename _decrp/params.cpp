#include "params.h"

Params* Params::m_Instance=nullptr;

Params *Params::GetInstance()
{
    if(m_Instance==nullptr)
    {
        m_Instance=new Params();
    }
    return m_Instance;
}

Params::Params(QObject *parent) : QObject(parent)
{

}
