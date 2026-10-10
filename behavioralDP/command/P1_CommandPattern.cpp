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
    void action(){
        cout<<"performing action"<<endl;
    }
    void undoAction(){
        cout<<"undo the performed action"<<endl;
    }
};
class concreteCommand: public Command{
    private:
    Reciever * reciever;
    public:
    concreteCommand(Reciever* reciever):reciever(reciever){}
    void execute() override{
        reciever->action();
    }
    void undo() override{
        reciever->undoAction();
    }
};
class Invoker{
    private:
    unique_ptr<Command>command;
    public:
    void setCommand(unique_ptr<Command>command){
        this->command= std::move(command);
    }
    void executeCommand(){
        if(command){
            command->execute();
        }
    }
    void undoCommand(){
        if(command){
            command->undo();
        }
    }
};
int main(){
    Reciever reciever;
    auto command = make_unique<concreteCommand>(&reciever);
    Invoker invoker;
    invoker.setCommand(std::move(command));
    invoker.executeCommand();
    invoker.undoCommand();
}