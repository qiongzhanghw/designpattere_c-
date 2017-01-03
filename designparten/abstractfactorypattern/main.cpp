#include <iostream>
#include "abstractfactory.h"

using namespace std;

int main()
{
    AbstractFactoryInterface* shanghaiFac = new ShanghaiFactory();
    AbstractFactoryInterface* xianFac = new XianFactory();

    AbstractEat* eat1 = shanghaiFac->CreatEatProduct();
    eat1->OutPutEatDetailProductInfo();
    AbstractEat* eat2 = shanghaiFac->CreatEatProduct();
    eat2->OutPutEatDetailProductInfo();


    AbstractDrink* drink1 = shanghaiFac->CreatDrinkProduct();
    drink1->OutPutDrinkDetailProductInfo();
    AbstractDrink* drink2 = shanghaiFac->CreatDrinkProduct();
    drink2->OutPutDrinkDetailProductInfo();

    AbstractEat* eat3 = xianFac->CreatEatProduct();
    eat3->OutPutEatDetailProductInfo();
    AbstractEat* eat4 = xianFac->CreatEatProduct();
    eat4->OutPutEatDetailProductInfo();

    AbstractDrink* drink3 = xianFac->CreatDrinkProduct();
    drink3->OutPutDrinkDetailProductInfo();
    AbstractDrink* drink4 = xianFac->CreatDrinkProduct();
    drink4->OutPutDrinkDetailProductInfo();

    return 0;
}
