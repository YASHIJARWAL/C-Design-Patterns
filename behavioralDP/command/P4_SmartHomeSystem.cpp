#include <algorithm>
#include<iostream>
#include <memory>
using namespace std;
class Reciever;
class Command{
    public:
    virtual void execute()=0;
    virtual void undo()=0;
    virtual ~Command()=default;
};
class Reciever{
    public:
    virtual void on()=0;
    virtual void off()=0;
    virtual ~Reciever()=default;
};
class FanReciever: public Reciever{
    public:
    void on() override{
        cout<<"turned on fan"<<endl;
    }
    void off() override{
        cout<<"turned off fan"<<endl;
    }
};
class LightReciever: public Reciever{
    void on() override{
        cout<<"turned on light"<<endl;
    }
    void off() override{
        cout<<"turned off light"<<endl;
    }
};
class TVReciever: public Reciever{
    void on() override{
        cout<<"turn on TV"<<endl;
    }
    void off() override{
        cout<<"turn off TV"<<endl;
    }
};
class PerformCommand:public Command{
    unique_ptr<Reciever>reciever;
    public:
    PerformCommand(unique_ptr<Reciever>recieverAppliance):reciever(move(recieverAppliance)){}
    void execute() override{
        reciever->on();
    }
    void undo() override{
        reciever->off();
    }
    
};
class Invoker{
    unique_ptr<Command>performCommand;
    public:
    Invoker(unique_ptr<Command>perform):performCommand(move(perform)){}
    void execute(){
        performCommand->execute();
    }
    void undo(){
        performCommand->undo();
    }
    
};
int main(){
    auto tvcommand = make_unique<PerformCommand>(make_unique<FanReciever>());
    Invoker invoke(move(tvcommand));
    invoke.execute();
    invoke.undo();
    auto fanCommand= make_unique<PerformCommand>(make_unique<TVReciever>());
    Invoker invoke2(move(fanCommand));
    invoke2.execute();
    invoke2.undo();
}