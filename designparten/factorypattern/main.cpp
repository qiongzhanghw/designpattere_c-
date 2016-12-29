#include <iostream>

using namespace std;


class AabstractProduct
{
public:
   AabstractProduct()
   {
   }
   ~AabstractProduct()
   {
   }
   virtual void douse()=0;
};

class ProductA:public AabstractProduct
{
public:
    ProductA()
    {

    }
    ~ProductA()
    {

    }
    void douse()
    {
        cout<<"use ProductA\n";
    }
};

class ProductB:public AabstractProduct
{
public:
    ProductB()
    {

    }
    ~ProductB()
    {

    }
    void douse()
    {
        cout<<"use ProductB\n";
    }
};
class CompanyFactory{
public:
    CompanyFactory()
    {

    }
    ~CompanyFactory()
    {

    }

    virtual AabstractProduct* BuildProduct(string Paramete)=0;
};

class CompanyA:public CompanyFactory
{
public:
    CompanyA()
    {

    }
    ~CompanyA()
    {

    }

    AabstractProduct* BuildProduct(string Paramete)
    {
        if (Paramete == "A")
        {
            return new ProductA();
        }
        else
        {
            return new ProductB();
        }
    }

};



int main()
{
    CompanyFactory* realfactory = new CompanyA();
    AabstractProduct* realproduct = realfactory->BuildProduct("A");
    realproduct->douse();

    realproduct = realfactory->BuildProduct("B");
    realproduct->douse();

    return 0;
}
