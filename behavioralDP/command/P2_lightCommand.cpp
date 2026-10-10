#include<iostream>
#include <memory>
using namespace std;

class Command{
    public:
    virtual void execute()=0;
    virtual void undo()=0;
    virtual ~Command()=default;
};
class TurnOn{
    public:
    void action(){
        cout<<"turning on the lights"<<endl;
    }
    void undoAct(){
        cout<<"undo the action on the lights"<<endl;
    }
};
class LightCommand:public Command{
    private:
    TurnOn * Switch;
    public:
    LightCommand(TurnOn *reciever):Switch(reciever){}
    void execute() override{
        Switch->action();
    }
    void undo() override{
        Switch->undoAct();
    }
};
class Invoker{
    private:
    unique_ptr<Command>command;
    public:
    void setCommand(unique_ptr<Command>command){
        this->command = std::move(command);
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
    TurnOn turnOn;
    Invoker invoke;
    auto command = make_unique<LightCommand>(&turnOn);
    invoke.setCommand(std::move(command));
    invoke.executeCommand();
    invoke.undoCommand();
}
