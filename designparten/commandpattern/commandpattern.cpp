#include "commandpattern.h"

AbsReceiver::AbsReceiver(string workname)
{
    this->receivername = workname;
}

string AbsReceiver::GetReceiverName()
{
   return this->receivername;
}

//开发

DevelpReceiver::DevelpReceiver(string workname):AbsReceiver(workname)
{

}
void DevelpReceiver::DoJobWork()
{
    cout<<this->GetReceiverName()<<": develop the requirement" <<endl;
}
//测试
TestReceiver::TestReceiver(string workname):AbsReceiver(workname)
{

}
void TestReceiver::DoJobWork()
{
    cout<<this->GetReceiverName()<<": test the requirement" <<endl;
}

//SE
SysDesinReceiver::SysDesinReceiver(string workname):AbsReceiver(workname)
{

}
void SysDesinReceiver::DoJobWork()
{
    cout<<this->GetReceiverName()<<": analysis the requirement" <<endl;
}
//MDE
ModuleDesinReceiver::ModuleDesinReceiver(string workname):AbsReceiver(workname)
{

}
void ModuleDesinReceiver::DoJobWork()
{
    cout<<this->GetReceiverName()<<": analysis the module" <<endl;
}

//维护
OperateorReceiver::OperateorReceiver(string workname):AbsReceiver(workname)
{

}
void OperateorReceiver::DoJobWork()
{
    cout<<this->GetReceiverName()<<": operate the requirement" <<endl;
}

void AbsCommand::SEAnalysisRequirement()
{
    multimap<RECEIVE_ENUM, AbsReceiver*>::iterator pmapit;
    pair<multimap<RECEIVE_ENUM, AbsReceiver*>::iterator,multimap<RECEIVE_ENUM, AbsReceiver*>::iterator> findret;

    findret = Receiverlist.equal_range(SYSDESIGN_ROLE);

    for(pmapit = findret.first; pmapit != findret.second; ++pmapit)
    {
        pmapit->second->DoJobWork();
    }
}
void AbsCommand::SWEDevelopRequirement()
{
    multimap<RECEIVE_ENUM, AbsReceiver*>::iterator pmapit;
    pair<multimap<RECEIVE_ENUM, AbsReceiver*>::iterator,multimap<RECEIVE_ENUM, AbsReceiver*>::iterator> findret;

    findret = Receiverlist.equal_range(DEVELOPER_ROLE);

    for(pmapit = findret.first; pmapit != findret.second; ++pmapit)
    {
        pmapit->second->DoJobWork();
    }
}
void AbsCommand::MDEAnalysisRequirement()
{
    multimap<RECEIVE_ENUM, AbsReceiver*>::iterator pmapit;
    pair<multimap<RECEIVE_ENUM, AbsReceiver*>::iterator,multimap<RECEIVE_ENUM, AbsReceiver*>::iterator> findret;

    findret = Receiverlist.equal_range(MODULDESIGN_ROLE);

    for(pmapit = findret.first; pmapit != findret.second; ++pmapit)
    {
        pmapit->second->DoJobWork();
    }
}
void AbsCommand::TSETestRequirement()
{
    multimap<RECEIVE_ENUM, AbsReceiver*>::iterator pmapit;
    pair<multimap<RECEIVE_ENUM, AbsReceiver*>::iterator,multimap<RECEIVE_ENUM, AbsReceiver*>::iterator> findret;

    findret = Receiverlist.equal_range(TEST_ROLE);

    for(pmapit = findret.first; pmapit != findret.second; ++pmapit)
    {
        pmapit->second->DoJobWork();
    }
}
void AbsCommand::OPEOperateRequirement()
{
    multimap<RECEIVE_ENUM, AbsReceiver*>::iterator pmapit;
    pair<multimap<RECEIVE_ENUM, AbsReceiver*>::iterator,multimap<RECEIVE_ENUM, AbsReceiver*>::iterator> findret;

    findret = Receiverlist.equal_range(OPERATOR_ROLE);

    for(pmapit = findret.first; pmapit != findret.second; ++pmapit)
    {
        pmapit->second->DoJobWork();
    }

}

DevlopRequest::DevlopRequest()
{
    this->commandname = "Develop the requirement command";
}

//开发需求
void DevlopRequest::Execute()
{
    cout<<this->commandname<<"......"<<endl;
    /* analysis requirement */
    this->SEAnalysisRequirement();

    /* analysis module  */
    this->MDEAnalysisRequirement();
    /* develop requirement */
    this->SWEDevelopRequirement();
    /* test requirement */
    this->TSETestRequirement();
}

FetrueBetaRequest::FetrueBetaRequest()
{
    this->commandname = "Test the Feature in network command";
}
//特性beta
void FetrueBetaRequest::Execute()
{
    cout<<this->commandname<<"......"<<endl;
    /* operate requirement */
    this->OPEOperateRequirement();
    /* test requirement */
    this->TSETestRequirement();
}

ProblemRequest::ProblemRequest()
{
    this->commandname = "process the network problem command";
}
//处理网上问题
void ProblemRequest::Execute()
{
    cout<<this->commandname<<"......"<<endl;
    /* operate requirement */
    this->OPEOperateRequirement();
    /* analysis requirement */
    this->SEAnalysisRequirement();
    /* develop requirement */
    this->SWEDevelopRequirement();
    /* test requirement */
    this->TSETestRequirement();
    /* operate requirement */
    this->OPEOperateRequirement();
}

void AbsCommand::AddCommandReceiver(AbsReceiver* addreceiver)
{
    RECEIVE_ENUM receivertype;

    if (typeid(*addreceiver).name() == typeid(SysDesinReceiver).name())
    {
        receivertype = SYSDESIGN_ROLE;
    }
    else if (typeid(*addreceiver).name() == typeid(TestReceiver).name())
    {
        receivertype = TEST_ROLE;
    }
    else if (typeid(*addreceiver).name() == typeid(DevelpReceiver).name())
    {
        receivertype = DEVELOPER_ROLE;
    }
    else if (typeid(*addreceiver).name() == typeid(ModuleDesinReceiver).name())
    {
        receivertype = MODULDESIGN_ROLE;
    }
    else if (typeid(*addreceiver).name() == typeid(OperateorReceiver).name())
    {
        receivertype = OPERATOR_ROLE;
    }
    else
    {
        cout<<"SetCommandReceiver: " << typeid(addreceiver).name() << "is invalid class"<<endl;
        return;
    }
    this->Receiverlist.insert(pair<RECEIVE_ENUM, AbsReceiver*>(receivertype,addreceiver));
}


ProjectManager::ProjectManager(string name)
{
    this->ownername = name;
}
void ProjectManager::ReceiveCommand(AbsCommand* rececommand)
{
    this->DoCommand = rececommand;
}
void ProjectManager::ExecuteCommand()
{
    this->DoCommand->Execute();
}
