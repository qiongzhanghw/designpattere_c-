#include <iostream>

using namespace std;

class AbstractDataInterface
{
public:
    virtual void SendData()=0;
    virtual void RecvData()=0;
    virtual AbstractDataInterface* GetDataTansProxy()=0;
};

class ProxyTrans:public AbstractDataInterface
{
private:
    AbstractDataInterface* InnerDataTrans = nullptr;
    void sendbefor();
    void sendafter();
    void recebefor();
    void receafter();
public:
    ProxyTrans(string name);
    ProxyTrans(AbstractDataInterface* datatransIns);
    void SendData();
    void RecvData();
    ~ProxyTrans();
    AbstractDataInterface* GetDataTansProxy();
};

class DataTrans:public AbstractDataInterface
{
private:
    string username;
    AbstractDataInterface* proxyIns = nullptr;
public:
    DataTrans(string name);
    void SendData();
    void RecvData();
    ~DataTrans();

    AbstractDataInterface* GetDataTansProxy();

    bool IsUseForceProxy();
};

void ProxyTrans::sendbefor()
{
    cout<<"Proxy send befor action\n";
}
void ProxyTrans::sendafter()
{
    cout<<"Proxy send after action\n";
}
void ProxyTrans::recebefor()
{
    cout<<"Proxy rece befor action\n";
}
void ProxyTrans::receafter()
{
    cout<<"Proxy rece after action\n";
}

ProxyTrans::ProxyTrans(string name)
{
    this->InnerDataTrans = new DataTrans(name);
}

ProxyTrans::ProxyTrans(AbstractDataInterface* datatransIns)
{
    this->InnerDataTrans = datatransIns;
}
void ProxyTrans::SendData()
{
    sendbefor();
    this->InnerDataTrans->SendData();
    sendafter();
}
void ProxyTrans::RecvData()
{
    recebefor();
    this->InnerDataTrans->RecvData();
    receafter();
}
ProxyTrans::~ProxyTrans()
{
}
AbstractDataInterface* ProxyTrans::GetDataTansProxy()
{
    return this;
}


DataTrans::DataTrans(string name)
{
    this->username = name;
}
void DataTrans::SendData()
{
    if (!IsUseForceProxy())
    {
        cout<<this->username<<" senddata\n";
    }
    else
    {
        cout<<this->username<< " Use ForceProxy" << " senddata\n";
    }
}
void DataTrans::RecvData()
{
    if (!IsUseForceProxy())
    {
        cout<<this->username<<" recedata\n";
    }
    else
    {
        cout<<this->username<< " Use ForceProxy"<<" recedata\n";
    }
}
DataTrans::~DataTrans()
{
}

AbstractDataInterface* DataTrans::GetDataTansProxy()
{
    this->proxyIns = new ProxyTrans(this);
    return this->proxyIns;
}

bool DataTrans::IsUseForceProxy()
{
    if(this->proxyIns == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    AbstractDataInterface* DataTransInst = new ProxyTrans("datatransinst");

    DataTransInst->SendData();

    DataTransInst->RecvData();


    AbstractDataInterface* DataTransForceInst = new DataTrans("proxyddatatrans");

    AbstractDataInterface* DataTransProxyInst = DataTransForceInst->GetDataTansProxy();

    DataTransProxyInst->SendData();

    DataTransProxyInst->RecvData();

    return 0;
}
