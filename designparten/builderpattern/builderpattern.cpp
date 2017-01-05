#include "builderpattern.h"


Wheel::Wheel(unsigned int wheelsize, unsigned int qualityperd, string productinfo)
{
    this->wheelsizeinfo = wheelsize;
    this->qualityyear = qualityperd;
    this->productfactory = productinfo;
}
void Wheel::GetWheelInfo()
{
    cout<<"  "<<"轮胎信息："<<endl;
    cout<<"\t"<<"生产厂家："<<this->productfactory<<"\t"
        <<"轮胎尺寸："<<this->wheelsizeinfo<<"寸"<<"\t"
        <<"保质期: "<<this->qualityyear<<"年"<<endl;
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
    cout<<"  "<<"发动机信息："<<endl;
    cout<<"\t"<<"生产厂家："<<this->productfactory<<"\t"
        <<"发动机制式："<<this->enginestandard<<"\t"
        <<"发动机型号："<<this->enginemodel<<"\t"
        <<"保质期："<<this->qualityyear<<"年"<<endl;
}



Chassis::Chassis(string hang, string standard, string productinfo)
{
    this->hangstandard = hang;
    this->Chassisstandard = standard;
    this->productfactory = productinfo;
}
void Chassis::GetChassisInfo()
{
    cout<<"  "<<"底盘信息："<<endl;
    cout<<"\t"<<"生产厂家："<<this->productfactory<<"\t"
        <<"底盘制式："<<this->Chassisstandard<<"\t"
        <<"悬挂制式："<<this->hangstandard<<endl;
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
    cout<<"  "<<"车身信息："<<endl;
    cout<<"\t"<<"车身高："<<this->highinfo<<"cm"<<"\t"
        <<"车身长："<<this->longinfo<<"cm"<<"\t"
        <<"轴距："<<this->wheelbase<<"cm"<<"\t"
        <<"车门数："<<this->doornum<<"个"<<endl;
}

MultiMedia::MultiMedia(string touch, string sound)
{
    this->touchscreen = touch;
    this->soundinfo = sound;
}

void MultiMedia::GetMultiMediaInfo()
{
    cout<<"  "<<"多媒体信息："<<endl;
    cout<<"\t"<<"触摸屏信息："<<this->touchscreen<<"\t"
        <<"音响信息："<<this->soundinfo<<endl;

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
    this->buildCar->SetCarEngine(new Engine("EA8888","涡轮增压",10,"奥迪"));
}
void SuvBuilder::BuildWheel()
{
    this->buildCar->SetCarWheel(new Wheel(24,5,"普利司通"));
}
void SuvBuilder::BuildChassis()
{
    this->buildCar->SetCarChassis(new Chassis("独立悬挂","非承载式","奥迪"));
}
void SuvBuilder::BuildFrame()
{
    this->buildCar->SetCarFrame(new Frame(170,240,220,2));
}

void SuvBuilder::BuildMulti()
{
    this->buildCar->SetMultiMedia(new MultiMedia("7寸触摸屏", "杜比环绕"));
}

ProductCar* SuvBuilder::getProduct()
{
    return this->buildCar;
}

void SuvCarDirect::Construct1(AbstractCarBuilder* conBuilder)
{
    cout<<"建造豪华SUV："<<endl;
    conBuilder->BuildWheel();
    conBuilder->BuildEngine();
    conBuilder->BuildFrame();
    conBuilder->BuildChassis();
    conBuilder->BuildMulti();
}

void SuvCarDirect::Construct2(AbstractCarBuilder* conBuilder)
{
    cout<<"建造标配SUV："<<endl;
    conBuilder->BuildWheel();
    conBuilder->BuildEngine();
    conBuilder->BuildFrame();
    conBuilder->BuildChassis();
}

void MpvBuilder::BuildEngine()
{
    this->buildCar->SetCarEngine(new Engine("ED3888","涡轮增压",10,"大众"));
}
void MpvBuilder::BuildWheel()
{
    this->buildCar->SetCarWheel(new Wheel(17,3,"锦湖"));
}
void MpvBuilder::BuildChassis()
{
    this->buildCar->SetCarChassis(new Chassis("独立悬挂","承载式","大众"));
}
void MpvBuilder::BuildFrame()
{
    this->buildCar->SetCarFrame(new Frame(170,240,220,4));
}

void MpvBuilder::BuildMulti()
{
    this->buildCar->SetMultiMedia(new MultiMedia("6寸触摸屏", "普通音响"));
}

ProductCar* MpvBuilder::getProduct()
{
    return this->buildCar;
}


void MpvCarDirect::Construct1(AbstractCarBuilder* conBuilder)
{
    cout<<"建造豪华MPV："<<endl;
    conBuilder->BuildWheel();
    conBuilder->BuildEngine();
    conBuilder->BuildFrame();
    conBuilder->BuildChassis();
    conBuilder->BuildMulti();
}

void MpvCarDirect::Construct2(AbstractCarBuilder* conBuilder)
{
    cout<<"建造标配MPV："<<endl;
    conBuilder->BuildWheel();
    conBuilder->BuildEngine();
    conBuilder->BuildFrame();
    conBuilder->BuildChassis();
}


