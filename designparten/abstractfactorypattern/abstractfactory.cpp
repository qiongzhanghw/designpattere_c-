

#include "abstractfactory.h"


AbstractProduct::AbstractProduct(unsigned int seriesinfo, string city)
{
    this->ProductTime = time(nullptr);
    this->ProductSeriesNumber = seriesinfo;
    this->ProduceCity = city;
}

unsigned int AbstractProduct::GetProductInfo()
{
    return this->ProductSeriesNumber;
}

string AbstractProduct::GetFactroyInfo()
{
    return this->ProduceCity;
}

AbstractEat::AbstractEat(unsigned int seriesinfo, string city, unsigned int weight):AbstractProduct(seriesinfo, city)
{
    this->ProductWeight = weight;
    this->ProductUnit = "克";
}
unsigned int AbstractEat::GetProductWeight()
{
    return this->ProductWeight;
}
string AbstractEat::GetProductUint()
{
    return this->ProductUnit;
}

void AbstractEat::OutPutEatDetailProductInfo()
{
    time_t calctime;
    unsigned int qualityperiod;

    cout<<"产品名称："<<this->GetProductName()<<endl;
    cout<<"生产厂地："<<this->GetFactroyInfo()<<endl;
    cout<<"生产日期："<<ctime(&this->ProductTime);
    cout<<"产品编号："<<this->GetProductInfo()<<endl;
    cout<<"产品规格："<<this->GetProductWeight()<<this->GetProductUint()<<endl;

    qualityperiod = this->GetProductQualityPeriod();
    calctime = this->ProductTime + qualityperiod*60*60*24;
    cout<<"最好在 " << ctime(&calctime) <<" 之前享用"<<endl;
}

Noddles::Noddles(unsigned int seriesinfo, string city, unsigned int weight):AbstractEat(seriesinfo, city, weight)
{
    this->ProductName = "方便面";
    this->qualityTime = 180;
}
string Noddles::GetProductName()
{
    return this->ProductName;
}

unsigned int Noddles::GetProductQualityPeriod()
{
    return this->qualityTime;
}
Cookies::Cookies(unsigned int seriesinfo, string city, unsigned int weight):AbstractEat(seriesinfo, city, weight)
{
    this->ProductName = "饼干";
    this->qualityTime = 120;
}
string Cookies::GetProductName()
{
    return this->ProductName;
}

unsigned int Cookies::GetProductQualityPeriod()
{
    return this->qualityTime;
}

AbstractDrink::AbstractDrink(unsigned int seriesinfo, string city, unsigned int capcity):AbstractProduct(seriesinfo, city)
{

    this->ProductVolume = capcity;
    this->ProductUnit = "毫升";
}

unsigned int AbstractDrink::GetVolume()
{
    return this->ProductVolume;
}
string AbstractDrink::GetProductUint()
{
    return this->ProductUnit;
}

void AbstractDrink::OutPutDrinkDetailProductInfo()
{
    time_t calctime;
    unsigned int qualityperiod;

    cout<<"产品名称："<<this->GetProductName()<<endl;
    cout<<"生产厂地："<<this->GetFactroyInfo()<<endl;
    cout<<"生产日期："<<ctime(&this->ProductTime);
    cout<<"产品编号："<<this->GetProductInfo()<<endl;
    cout<<"产品规格："<<this->GetVolume()<<this->GetProductUint()<<endl;

    qualityperiod = this->GetProductQualityPeriod();
    calctime = this->ProductTime + qualityperiod*60*60*24;
    cout<<"最好在 " << ctime(&calctime) <<" 之前享用" <<endl;
}
Water::Water(unsigned int seriesinfo, string city, unsigned int capcity):AbstractDrink(seriesinfo, city, capcity)
{
    this->ProductName= "矿泉水";
    this->qualityTime = 90;
}
string Water::GetProductName()
{
    return this->ProductName;
}
unsigned int Water::GetProductQualityPeriod()
{
    return this->qualityTime;
}

Tea::Tea(unsigned int seriesinfo, string city, unsigned int capcity):AbstractDrink(seriesinfo, city, capcity)
{
    this->ProductName= "绿茶";
    this->qualityTime = 60;
}
string Tea::GetProductName()
{
    return this->ProductName;
}
unsigned int Tea::GetProductQualityPeriod()
{
    return this->qualityTime;
}

unsigned int ShanghaiFactory::NoddlesSeriesNumber = 0;
unsigned int ShanghaiFactory::WaterSeriesNumber = 0;

AbstractEat* ShanghaiFactory::CreatEatProduct()
{
    AbstractEat* noddleproct = new Noddles(NoddlesSeriesNumber++, "SHANGHAI", 100);
    return noddleproct;
}
AbstractDrink* ShanghaiFactory::CreatDrinkProduct()
{
    AbstractDrink* waterproct = new Water(WaterSeriesNumber++, "SHANGHAI", 500);
    return waterproct;
}

unsigned int XianFactory::CookiesSeriesNumber = 0;
unsigned int XianFactory::TeaSeriesNumber = 0;

AbstractEat* XianFactory::CreatEatProduct()
{
    AbstractEat* cooliesproct = new Cookies(CookiesSeriesNumber++, "XIAN", 150);
    return cooliesproct;
}
AbstractDrink* XianFactory::CreatDrinkProduct()
{
    AbstractDrink* teaproct = new Tea(TeaSeriesNumber++, "XIAN", 600);
    return teaproct;
}





