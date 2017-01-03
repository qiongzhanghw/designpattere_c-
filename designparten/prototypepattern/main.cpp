#include <iostream>

using namespace std;
class AbstractProduct
{
public:

    virtual AbstractProduct* clone()=0;
    virtual void ShowProductInfo()=0;
    virtual void SetProdeuctInfo(string setinfo)=0;
};
class AbstractCompany
{
public:

    virtual void SetCompanyInfo(string setinfo)=0;
    virtual string GetCompanyInfo()=0;
};

class CompanyImplt:public AbstractCompany
{
private:
    string companyinfo;
public:

    CompanyImplt()
    {
        string defaultinfo = "Huawei Company";
        this->companyinfo = defaultinfo;
    }

    ~CompanyImplt()
    {

    }

    void SetCompanyInfo(string setinfo)
    {
        this->companyinfo = setinfo;
    }
    string GetCompanyInfo()
    {
        return this->companyinfo;
    }
};
class Product:public AbstractProduct
{
private:
    string conmanyinfo;
    string prodctinfo;
public:

    Product(AbstractCompany* companyIns)
    {
        cout<<"Construct1 is call"<<endl;
        this->conmanyinfo = companyIns->GetCompanyInfo();
    }

    ~Product()
    {
        cout<<"DeConstruct is call"<<endl;
    }

    Product()
    {
        cout<<"Construct2 is call"<<endl;
    }
    Product* clone()
    {
        Product* newproduct = new Product();

        newproduct->conmanyinfo = this->conmanyinfo;
        newproduct->prodctinfo = this->prodctinfo;
        return newproduct;
    }
    void SetProdeuctInfo(string setinfo)
    {
        this->prodctinfo = setinfo;
    }

    void ShowProductInfo()
    {
        cout<<"companyinof: " << this->conmanyinfo << endl;
        cout<<"productinfo: " << this->prodctinfo << endl;
    }
};

int main()
{
    AbstractCompany* publiccompany = new CompanyImplt();

    AbstractProduct* prodectA = new Product(publiccompany);
    prodectA->SetProdeuctInfo("productA");
    prodectA->ShowProductInfo();

    AbstractProduct* prodectB = prodectA->clone();
    prodectB->SetProdeuctInfo("productB");
    prodectB->ShowProductInfo();

    publiccompany->SetCompanyInfo("huawei honnor");

    AbstractProduct* prodectC= new Product(publiccompany);
    prodectC->SetProdeuctInfo("productC");
    prodectC->ShowProductInfo();

    AbstractProduct* prodectD = prodectC->clone();
    prodectD->SetProdeuctInfo("productD");
    prodectD->ShowProductInfo();

    return 0;
}
