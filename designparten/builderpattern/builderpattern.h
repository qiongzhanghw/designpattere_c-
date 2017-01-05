#ifndef BUILDERPATTERN_H_INCLUDED
#define BUILDERPATTERN_H_INCLUDED
#include <iostream>
#include <list>

using namespace std;

class Wheel
{
private:
    unsigned int wheelsizeinfo;
    unsigned int qualityyear;
    string productfactory;
public:
    Wheel(unsigned int wheelsize, unsigned int qualityperd, string productinfo);
    void GetWheelInfo();
};

class Engine
{
private:
    unsigned int qualityyear;
    string enginemodel;
    string enginestandard;
    string productfactory;
public:
    Engine(string model, string standard, unsigned int qualityperd, string productinfo);
    void GetEngineInfo();
};

class Chassis
{
private:
    string hangstandard;
    string Chassisstandard;
    string productfactory;
public:
    Chassis(string hang, string standard, string productinfo);
    void GetChassisInfo();
};

class Frame
{
private:
    unsigned int highinfo;
    unsigned int longinfo;
    unsigned int wheelbase;
    unsigned int doornum;
public:
    Frame(unsigned int highsize, unsigned int longsie, unsigned int wheelsize, unsigned int doorn);
    void GetFrameInfo();
};

class MultiMedia
{
private:
    string touchscreen;
    string soundinfo;
public:
    MultiMedia(string touch, string sound);
    void GetMultiMediaInfo();
};

class ProductCar
{
private:
    Engine* enginepart = nullptr;
    Wheel* wheelpart = nullptr;
    Chassis* chassispart = nullptr;
    Frame* framepart = nullptr;
    MultiMedia* multimediapart = nullptr;
public:
    void SetCarEngine(Engine* engineobj);
    void SetCarWheel(Wheel* wheelobj);
    void SetCarChassis(Chassis* chassisobj);
    void SetCarFrame(Frame* frameobj);
    void SetMultiMedia(MultiMedia* multiobj);
    void ShowCarConfigure();

};

class AbstractCarBuilder
{
public:
    virtual void BuildEngine() = 0;
    virtual void BuildWheel() = 0;
    virtual void BuildChassis() = 0;
    virtual void BuildFrame() = 0;
    virtual void BuildMulti() = 0;
    virtual ProductCar* getProduct() = 0;
};

class SuvBuilder:public AbstractCarBuilder
{
    ProductCar* buildCar = new ProductCar();
    void BuildEngine();
    void BuildWheel();
    void BuildChassis();
    void BuildFrame();
    void BuildMulti();
    ProductCar* getProduct();
};

class SuvCarDirect
{
public:
    void Construct1(AbstractCarBuilder* conBuilder);

    void Construct2(AbstractCarBuilder* conBuilder);
};

class MpvBuilder:public AbstractCarBuilder
{
    ProductCar* buildCar = new ProductCar();
    void BuildEngine();
    void BuildWheel();
    void BuildChassis();
    void BuildFrame();
    void BuildMulti();
    ProductCar* getProduct();
};

class MpvCarDirect
{
public:
    void Construct1(AbstractCarBuilder* conBuilder);

    void Construct2(AbstractCarBuilder* conBuilder);
};


#endif // BUILDERPATTERN_H_INCLUDED
