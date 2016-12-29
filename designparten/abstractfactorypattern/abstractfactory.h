#include <iostream>
#include <time.h>
using namespace std;

class AbstractProduct
{
protected:
    unsigned int ProductSeriesNumber;
    string ProduceCity;
    time_t ProductTime;
public:
    AbstractProduct(unsigned int seriesinfo, string city);
    string GetFactroyInfo();
    unsigned int GetProductInfo();
};

class AbstractEat:public AbstractProduct
{
protected:
    unsigned int ProductWeight;
    string ProductUnit;
public:
    AbstractEat(unsigned int seriesinfo, string city, unsigned int weight);
    unsigned int GetProductWeight();
    string GetProductUint();
    virtual string GetProductName() = 0;
    virtual unsigned int GetProductQualityPeriod() = 0;
    void OutPutEatDetailProductInfo();
};

class Noddles:public AbstractEat
{
private:
    string ProductName;
    unsigned int qualityTime;
public:
    Noddles(unsigned int seriesinfo, string city, unsigned int weight);
    string GetProductName();
    unsigned int GetProductQualityPeriod();
};

class Cookies:public AbstractEat
{
private:
    string ProductName;
    unsigned int qualityTime;
public:
    Cookies(unsigned int seriesinfo, string city, unsigned int weight);
    string GetProductName();
    unsigned int GetProductQualityPeriod();
};

class AbstractDrink:public AbstractProduct
{
protected:
    unsigned int ProductVolume;
    string ProductUnit;
public:
    AbstractDrink(unsigned int seriesinfo, string city, unsigned int capcity);
    unsigned int GetVolume();
    string GetProductUint();
    virtual string GetProductName() = 0;
    virtual unsigned int GetProductQualityPeriod() = 0;
    void OutPutDrinkDetailProductInfo();

};

class Water:public AbstractDrink
{
private:
    string ProductName;
    unsigned int qualityTime;
public:
    Water(unsigned int seriesinfo, string city, unsigned int capcity);
    string GetProductName();
    unsigned int GetProductQualityPeriod();
};

class Tea:public AbstractDrink
{
private:
    string ProductName;
    unsigned int qualityTime;
public:
    Tea(unsigned int seriesinfo, string city, unsigned int capcity);
    string GetProductName();
    unsigned int GetProductQualityPeriod();
};

class AbstractFactoryInterface
{
public:
    virtual AbstractDrink* CreatDrinkProduct() = 0;
    virtual AbstractEat* CreatEatProduct() = 0;
};

class ShanghaiFactory:public AbstractFactoryInterface
{
private:
    static unsigned int NoddlesSeriesNumber;
    static unsigned int WaterSeriesNumber;
public:
    AbstractDrink* CreatDrinkProduct();
    AbstractEat* CreatEatProduct();
};

class XianFactory:public AbstractFactoryInterface
{
private:
    static unsigned int CookiesSeriesNumber;
    static unsigned int TeaSeriesNumber;
public:
    AbstractDrink* CreatDrinkProduct();
    AbstractEat* CreatEatProduct();
};



