#include "builderpattern.h"


Wheel::Wheel(unsigned int wheelsize, unsigned int qualityperd, string productinfo)
{
    this->wheelsizeinfo = wheelsize;
    this->qualityyear = qualityperd;
    this->productfactory = productinfo;
}
void Wheel::GetWheelInfo()
{
    cout<<"  "<<"��̥��Ϣ��"<<endl;
    cout<<"\t"<<"�������ң�"<<this->productfactory<<"\t"
        <<"��̥�ߴ磺"<<this->wheelsizeinfo<<"��"<<"\t"
        <<"������: "<<this->qualityyear<<"��"<<endl;
}

Engine::Engine(string model, string standard, unsigned int qualityperd, string productinfo)
{
    this->enginemodel = model;
    this->enginestandard = standard;
    this->qualityyear = qualityperd;
    this->productfactory = productinfo;
}

void Engine::GetEngineInfo()
{
    cout<<"  "<<"��������Ϣ��"<<endl;
    cout<<"\t"<<"�������ң�"<<this->productfactory<<"\t"
        <<"��������ʽ��"<<this->enginestandard<<"\t"
        <<"�������ͺţ�"<<this->enginemodel<<"\t"
        <<"�����ڣ�"<<this->qualityyear<<"��"<<endl;
}



Chassis::Chassis(string hang, string standard, string productinfo)
{
    this->hangstandard = hang;
    this->Chassisstandard = standard;
    this->productfactory = productinfo;
}
void Chassis::GetChassisInfo()
{
    cout<<"  "<<"������Ϣ��"<<endl;
    cout<<"\t"<<"�������ң�"<<this->productfactory<<"\t"
        <<"������ʽ��"<<this->Chassisstandard<<"\t"
        <<"������ʽ��"<<this->hangstandard<<endl;
}


Frame::Frame(unsigned int highsize, unsigned int longsie, unsigned int wheelsize, unsigned int doorn)
{
    this->highinfo = highsize;
    this->longinfo = longsie;
    this->wheelbase = wheelsize;
    this->doornum = doorn;
}
void Frame::GetFrameInfo()
{
    cout<<"  "<<"������Ϣ��"<<endl;
    cout<<"\t"<<"����ߣ�"<<this->highinfo<<"cm"<<"\t"
        <<"������"<<this->longinfo<<"cm"<<"\t"
        <<"��ࣺ"<<this->wheelbase<<"cm"<<"\t"
        <<"��������"<<this->doornum<<"��"<<endl;
}

MultiMedia::MultiMedia(string touch, string sound)
{
    this->touchscreen = touch;
    this->soundinfo = sound;
}

void MultiMedia::GetMultiMediaInfo()
{
    cout<<"  "<<"��ý����Ϣ��"<<endl;
    cout<<"\t"<<"��������Ϣ��"<<this->touchscreen<<"\t"
        <<"������Ϣ��"<<this->soundinfo<<endl;

}

void ProductCar::SetCarEngine(Engine* engineobj)
{
    this->enginepart = engineobj;
}
void ProductCar::SetCarWheel(Wheel* wheelobj)
{
    this->wheelpart = wheelobj;
}
void ProductCar::SetCarChassis(Chassis* chassisobj)
{
    this->chassispart = chassisobj;
}
void ProductCar::SetCarFrame(Frame* frameobj)
{
    this->framepart = frameobj;
}

void ProductCar::SetMultiMedia(MultiMedia* multiobj)
{
    this->multimediapart = multiobj;
}

void ProductCar::ShowCarConfigure()
{
    if (this->enginepart != nullptr)
    {
        this->enginepart->GetEngineInfo();
    }
    if (this->chassispart != nullptr)
    {
        this->chassispart->GetChassisInfo();
    }
    if (this->framepart != nullptr)
    {
        this->framepart->GetFrameInfo();
    }
    if (this->wheelpart != nullptr)
    {
        this->wheelpart->GetWheelInfo();
    }
    if (this->multimediapart != nullptr)
    {
        this->multimediapart->GetMultiMediaInfo();
    }
}

void SuvBuilder::BuildEngine()
{
    this->buildCar->SetCarEngine(new Engine("EA8888","������ѹ",10,"�µ�"));
}
void SuvBuilder::BuildWheel()
{
    this->buildCar->SetCarWheel(new Wheel(24,5,"����˾ͨ"));
}
void SuvBuilder::BuildChassis()
{
    this->buildCar->SetCarChassis(new Chassis("��������","�ǳ���ʽ","�µ�"));
}
void SuvBuilder::BuildFrame()
{
    this->buildCar->SetCarFrame(new Frame(170,240,220,2));
}

void SuvBuilder::BuildMulti()
{
    this->buildCar->SetMultiMedia(new MultiMedia("7�紥����", "�űȻ���"));
}

ProductCar* SuvBuilder::getProduct()
{
    return this->buildCar;
}

void SuvCarDirect::Construct1(AbstractCarBuilder* conBuilder)
{
    cout<<"�������SUV��"<<endl;
    conBuilder->BuildWheel();
    conBuilder->BuildEngine();
    conBuilder->BuildFrame();
    conBuilder->BuildChassis();
    conBuilder->BuildMulti();
}

void SuvCarDirect::Construct2(AbstractCarBuilder* conBuilder)
{
    cout<<"�������SUV��"<<endl;
    conBuilder->BuildWheel();
    conBuilder->BuildEngine();
    conBuilder->BuildFrame();
    conBuilder->BuildChassis();
}

void MpvBuilder::BuildEngine()
{
    this->buildCar->SetCarEngine(new Engine("ED3888","������ѹ",10,"����"));
}
void MpvBuilder::BuildWheel()
{
    this->buildCar->SetCarWheel(new Wheel(17,3,"����"));
}
void MpvBuilder::BuildChassis()
{
    this->buildCar->SetCarChassis(new Chassis("��������","����ʽ","����"));
}
void MpvBuilder::BuildFrame()
{
    this->buildCar->SetCarFrame(new Frame(170,240,220,4));
}

void MpvBuilder::BuildMulti()
{
    this->buildCar->SetMultiMedia(new MultiMedia("6�紥����", "��ͨ����"));
}

ProductCar* MpvBuilder::getProduct()
{
    return this->buildCar;
}


void MpvCarDirect::Construct1(AbstractCarBuilder* conBuilder)
{
    cout<<"�������MPV��"<<endl;
    conBuilder->BuildWheel();
    conBuilder->BuildEngine();
    conBuilder->BuildFrame();
    conBuilder->BuildChassis();
    conBuilder->BuildMulti();
}

void MpvCarDirect::Construct2(AbstractCarBuilder* conBuilder)
{
    cout<<"�������MPV��"<<endl;
    conBuilder->BuildWheel();
    conBuilder->BuildEngine();
    conBuilder->BuildFrame();
    conBuilder->BuildChassis();
}


