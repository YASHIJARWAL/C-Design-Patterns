#include<iostream>
using namespace std;
class Walkable{
    public:
    virtual void walk()=0;
};
class canWalk : public Walkable{
    void walk() override{
        cout<<"Can walk"<<endl;
    }
};
class NoWalk : public Walkable{
    void walk()override{
        cout<<"don't walk"<<endl;
    }
};
class Flyable{
    public:
    virtual void fly()=0;
};
class CanFly: public Flyable{
    void fly() override{
        cout<<"can fly"<<endl;
    }
};
class NoFly : public Flyable{
    void fly() override{
        cout<<"no fly"<<endl;
    }
};
class Talkable{
    public:
    virtual void talk()=0;
};
class CanTalk : public Talkable{
    void talk() override{
        cout<< "can talk"<<endl;
    }
};
class NoTalk : public Talkable{
    void talk() override{
        cout<<"cannot talk"<<endl;
    }
};
class Robot{
    protected: 
    Walkable* walk;
    Talkable* talk;
    Flyable* fly;
    public:
    Robot(Walkable*w , Talkable*t , Flyable*f){
        this->fly = f;
        this->walk = w;
        this->talk = t;
    }
    void flying(){
        fly->fly();
    }
    void walking(){
        walk->walk();
    }
    void talking(){
        talk->talk();
    }
    virtual void projection()=0;
};
class CompanionRobot : public Robot{
    public:
    CompanionRobot(Walkable*w , Talkable* t , Flyable*f): Robot(w, t, f){}
    void projection() override{
        cout<<"displaying companionship"<<endl;
    }
};
class WorkerRobot : public Robot{
    public:
    WorkerRobot(Walkable*w , Talkable* t , Flyable*f): Robot(w, t, f){}
    void projection() override{
        cout<<"displaying Worker Robots"<<endl;
    }
};
int main(){
    Robot*robot1 = new CompanionRobot(new canWalk(),new CanTalk(),new NoFly());
    robot1->walking();
    robot1->talking();
    robot1->flying();
    robot1->projection();
    Robot*robot2 = new WorkerRobot(new NoWalk(),new NoTalk(), new CanFly());
    robot2->walking();
    robot2->talking();
    robot2->flying();
    robot2->projection();
}