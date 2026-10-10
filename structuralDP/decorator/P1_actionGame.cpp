#include<iostream>
#include <memory>
using namespace std;
class Action{
    protected:
    string name;
    int total;
    public:
    int getTotal(){
        return total;
    }
    virtual void operation()=0;
    virtual void setName(string name){
        this->name = name;
    }
    virtual int points()=0;
    virtual ~Action()=default;
};
class WalkAction: public Action{
    public:
    void operation() override{
        points();
        cout<<this->name<<" performs walk action"<<endl;
    }
    int points() override{
        return 1;
    }
};
class PerformAction: public Action{
    protected:
    unique_ptr<Action>action;
    public:
    void setName(string name) override{
        this->name = name;
        action->setName(name);
    }
    PerformAction(unique_ptr<Action>action): action(move(action)){}
    virtual ~PerformAction()= default;
};
class JumpAction: public PerformAction{
    public:
    JumpAction(unique_ptr<Action>action): PerformAction(move(action)){}
    void operation() override{
        action->operation();
        points();
        cout<<this->name<<" is performing jump operation"<<endl;
    }
    int points() override{
        total= action->points()+2;
        return total;
    }
};
class ScoreAction : public PerformAction{
    public:
    ScoreAction(unique_ptr<Action>action):PerformAction(move(action)){}
    void operation() override{
        action->operation();
        points();
        cout<<this->name<<" performing point scorer"<<endl;
    }
    int points() override{
        total = action->points()+5;
        return total;
    }
};
int main(){
    unique_ptr<Action>act = make_unique<WalkAction>();
    act = make_unique<JumpAction>(move(act));
    act = make_unique<ScoreAction>(move(act));
    act = make_unique<JumpAction>(move(act));
    act = make_unique<ScoreAction>(move(act));
    act->setName("player 1");
    act->operation();
    cout<< "total score: "<<act->getTotal()<<endl;
}