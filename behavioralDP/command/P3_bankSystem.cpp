#include<iostream>
#include <memory>
using namespace std;
class Command{
    public:
    virtual void execute()=0;
    virtual void undo()=0;
    virtual ~Command()=default;
};
class Reciever{
    public:
    virtual void perform()=0;
    virtual void undo()=0;
    virtual ~Reciever()=default;
};
class WithdrawReciever: public Reciever{
    public:
    void perform() override{
        cout<<"performing withdraw"<<endl;
    }
    void undo() override{
        cout<<"terminating the action"<<endl;
    }
};
class DepositReciever: public Reciever{
    void perform() override{
        cout<<"performing deposit"<<endl;
    }
    void undo() override{
        cout<<"terminating the action"<<endl;
    }
};
class RunCommand: public Command{
    unique_ptr<Reciever>reciever;
    public:
    RunCommand(unique_ptr<Reciever>reciever):reciever(move(reciever)){}
    void execute() override{
        reciever->perform();
    }
    void undo() override{
        reciever->undo();
    }
};
class Invoker{
    public:
    unique_ptr<Command>command;
    Invoker(unique_ptr<Command>command):command(move(command)){}
    void invoke(){
        command->execute();
    }
    void undo(){
        command->undo();
    }
};
int main(){
    auto Command = make_unique<RunCommand>(make_unique<WithdrawReciever>());
    Invoker invoke(move(Command));
    invoke.invoke();
    invoke.undo();
}