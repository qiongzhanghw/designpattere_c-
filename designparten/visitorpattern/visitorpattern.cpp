#include <sstream>
#include "vistorpattern.h"

AbstractEmployee::AbstractEmployee(string name, unsigned int idvalue, unsigned int agevalue)
{
    this->employname = name;
    this->id = idvalue;
    this->age = agevalue;
}

string AbstractEmployee::getemployeename()
{
    return this->employname;
}

unsigned int AbstractEmployee::getemployeeid()
{
    return this->id;
}
unsigned int AbstractEmployee::getemployeesalary()
{
    return this->salary;
}
unsigned int AbstractEmployee::getemployeerank()
{
    return this->ranklevel;
}

unsigned int AbstractEmployee::getemployage()
{
    return this->age;
}
void AbstractEmployee::setemployeesalary(unsigned int salaryvalue)
{
    this->salary = salaryvalue;
}
void AbstractEmployee::setemployeerank(unsigned int rankvalue)
{
    this->ranklevel = rankvalue;
}

void AbstractEmployee::addemployeeage()
{
    this->age++;
}

/*void AbstractEmployee::accept(IVisitInterface* vistor)
{
    cout<<"执行了父类方法" <<endl;
}*/

CommonEmployee::CommonEmployee(string name, unsigned int idvalue, unsigned int agevalue):AbstractEmployee(name, idvalue, agevalue)
{

}

void CommonEmployee::setemployeejob(string jobvalue)
{
    this->jobinfo = jobvalue;
}

string CommonEmployee::getemployeejob()
{
    return this->jobinfo;
}

void CommonEmployee::accept(IVisitInterface* vistor)
{
    vistor->visit(this);
}

MidManager::MidManager(string name, unsigned int idvalue, unsigned int agevalue):AbstractEmployee(name, idvalue, agevalue)
{

}

string MidManager::getmanagerposition()
{
    return this->manageposition;
}

void MidManager::setmanagerposition(string positioninfo)
{
    this->manageposition = positioninfo;
}

string MidManager::getdepartreport()
{
    return this->departmentreport;
}

void MidManager::setdepartreport(string report)
{
    this->departmentreport = report;
}
void MidManager::accept(IVisitInterface* vistor)
{
    vistor->visit(this);
}

void CommonVisit::getCommonInfo(AbstractEmployee* employeeinst)
{
    stringstream employinfo;
    employinfo << "员工名称：" << employeeinst->getemployeename() <<"\t" \
               << "员工工号："<< employeeinst->getemployeeid() << "\t" \
               << "员工年龄："<< employeeinst->getemployage() << "\t";
    this->commoninfo += employinfo.str();

}
void CommonVisit::getEmployeeSpecialInfo(CommonEmployee* employeeinst)
{
    this->commoninfo += ("职位："  + employeeinst->getemployeejob() + "\n");
}
void CommonVisit::getManageSpecialInfo(MidManager* employeeinst)
{
    stringstream employinfo;

    employinfo << "管理岗位：" << employeeinst->getmanagerposition()<< "\t"
               << "部门目标" << employeeinst->getdepartreport()<<"\n";
    this->commoninfo += employinfo.str();
}

void CommonVisit::visit(CommonEmployee* comemployee)
{
    this->getCommonInfo(comemployee);
    this->getEmployeeSpecialInfo(comemployee);
}
void CommonVisit::visit(MidManager* comanager)
{
    this->getCommonInfo(comanager);
    this->getManageSpecialInfo(comanager);
}
string CommonVisit::getemployeeinfo()
{
    return this->commoninfo;
}

void CommonVisit::resetvistinfo()
{
    this->commoninfo = "";
}

void PaymentVisit::visit(CommonEmployee *comemployee)
{
    this->totalemployeesalary += (comemployee->getemployeesalary()*12 + comemployee->getemployeesalary()*1.5);
}
void PaymentVisit::visit(MidManager *comanager)
{
    this->totalmanagersalary += (comanager->getemployeesalary()*12 + comanager->getemployeesalary()*5);
}
string PaymentVisit::getPaymentinfo()
{
    stringstream employinfo;

    employinfo << "普通员工薪酬总额：" <<this->totalemployeesalary << "\t"
               << "管理人员薪酬总额：" <<this->totalmanagersalary<<"\n";
    return employinfo.str();
}

void PaymentVisit::resetvistinfo()
{
    this->totalemployeesalary = 0;
    this->totalmanagersalary = 0;
}

SearLogic::SearLogic()
{

}

bool SearLogic::setcompareUPcondition(unsigned int value, COMPARE_UP_ENUM logic)
{
    if (logic >= COMPARE_UP_BUTT || logic < COMPARE_UP_LITTER)
    {
        cout<<"上限比较逻辑设置错误：" << logic <<endl;
        return false;
    }
    if (value <= this->compareDownvalue)
    {
        cout<<"上限比下限小，设置错误："<< this->compareDownvalue <<endl;
        return false;
    }

    this->compareUpvalue = value;
    this->compareUplogic = logic;
    return true;
}

bool SearLogic::setcompareDOWNcondition(unsigned int value, COMPARE_DOWN_ENUM logic)
{
   if (logic >= COMPARE_DOWN_BUTT || logic < COMPARE_DOWN_LARGEER)
    {
        cout<<"下限比较逻辑设置错误：" << logic <<endl;
        return false;
    }
    if (value >= this->compareUpvalue)
    {
        cout<<"下限比上限大，设置错误："<< this->compareUpvalue <<endl;
        return false;
    }

    this->compareDownvalue = value;
    this->compareDownlogic = logic;
    return true;
}


bool SearLogic::compareresult(unsigned int inputvalue)
{
    switch(this->compareDownlogic)
    {
        case COMPARE_DOWN_LARGEER:
            if (inputvalue<= this->compareDownvalue)
            {
                return false;
            }
            break;
        case COMPARE_DOWN_EQUAL_AND_LARGERR:
            if (inputvalue< this->compareDownvalue)
            {
                return false;
            }
            break;
        default:
            return false;
    }

    switch(this->compareUplogic)
    {
        case COMPARE_UP_LITTER:
            if (inputvalue >= this->compareUpvalue)
            {
                return false;
            }
            break;
        case COMPARE_UP_EQUAL_AND_LITTER:
            if (inputvalue > this->compareUpvalue)
            {
                return false;
            }
            break;
        default:
            return false;
    }

    return true;
}

void SearLogic::resetcodition()
{
    this->compareUpvalue = 0xffffffff;
    this->compareDownvalue = 0;
    this->compareUplogic = COMPARE_UP_LITTER;
    this->compareDownlogic = COMPARE_DOWN_LARGEER;
}

bool SearchInfoVisit::SetLogicCompareCondition(SearLogic &logicinst, unsigned int uplimit, unsigned int downlimit, COMPARE_UP_ENUM uplogic, COMPARE_DOWN_ENUM dnlogic)
{
    if (false == logicinst.setcompareUPcondition(uplimit, uplogic))
    {
        return false;
    }

    return logicinst.setcompareDOWNcondition(downlimit, dnlogic);
}

bool SearchInfoVisit::SetRankCondition(unsigned int uplimit, unsigned int downlimit, COMPARE_UP_ENUM uplogic, COMPARE_DOWN_ENUM dnlogic)
{
    return this->SetLogicCompareCondition(this->searchrank, uplimit, downlimit, uplogic, dnlogic);
}
bool SearchInfoVisit::SetSalaryCondition(unsigned int uplimit, unsigned int downlimit, COMPARE_UP_ENUM uplogic, COMPARE_DOWN_ENUM dnlogic)
{
    return this->SetLogicCompareCondition(this->searsalary, uplimit, downlimit, uplogic, dnlogic);
}
bool SearchInfoVisit::SetAgeCondition(unsigned int uplimit, unsigned int downlimit, COMPARE_UP_ENUM uplogic, COMPARE_DOWN_ENUM dnlogic)
{
    return this->SetLogicCompareCondition(this->searchage, uplimit, downlimit, uplogic, dnlogic);
}

bool SearchInfoVisit::GetCompareResult(SearLogic &logicinst, unsigned int inputvalue)
{
    return logicinst.compareresult(inputvalue);
}

void SearchInfoVisit::ResetComparecondition(SearLogic &logicinst)
{
    logicinst.resetcodition();
}

void SearchInfoVisit::ResetRankCondition()
{
    this->ResetComparecondition(this->searchrank);
}
void SearchInfoVisit::ResetSalaryCondition()
{
    this->ResetComparecondition(this->searsalary);
}
void SearchInfoVisit::ResetAgeCondition()
{
    this->ResetComparecondition(this->searchage);
}
void SearchInfoVisit::ResetAllCondition()
{
    this->ResetComparecondition(this->searchrank);
    this->ResetComparecondition(this->searsalary);
    this->ResetComparecondition(this->searchage);
}

bool SearchInfoVisit::VisitFilter(AbstractEmployee* abstracinst)
{
    if (false == this->GetCompareResult(this->searchrank, abstracinst->getemployeerank()))
    {
        return false;
    }
    if (false == this->GetCompareResult(this->searsalary, abstracinst->getemployeesalary()))
    {
        return false;
    }
    if (false == this->GetCompareResult(this->searchage, abstracinst->getemployage()))
    {
        return false;
    }
    return true;
}

void SearchInfoVisit::GetRankSalaryinfo(AbstractEmployee* employeeinst)
{
   stringstream employinfo;

    employinfo << "职级：" << employeeinst->getemployeerank() << "\t"
               << "工资：" << employeeinst->getemployeesalary() <<"\t";
    this->commoninfo += employinfo.str();
}
void SearchInfoVisit::visit(CommonEmployee *comemployee)
{
    if (false == this->VisitFilter(comemployee))
    {
        return;
    }
    //CommonVisit::visit(comemployee);
    this->getCommonInfo(comemployee);
    this->GetRankSalaryinfo(comemployee);
    this->getEmployeeSpecialInfo(comemployee);
}
void SearchInfoVisit::visit(MidManager *comanager)
{
    if (false == this->VisitFilter(comanager))
    {
        return;
    }
    //CommonVisit::visit(comanager);
    this->getCommonInfo(comanager);
    this->GetRankSalaryinfo(comanager);
    this->getManageSpecialInfo(comanager);
}


