#include<iostream>
using namespace std;
class Manager;
class Associate;
class Director;
class Visitor{
    public:
    virtual void manVisit(Manager &mananger)=0;
    virtual void asoVisit(Associate &associate)=0;
    virtual void dirVisit(Director &director)=0;
};
class SalaryVisitor:public Visitor{
    int salary;
    public:
    int getSal(){
        return this->salary;
    }
    void setSal(){
        int sal;
        cin>>sal;
        this->salary = sal;
    }
    void manVisit(Manager &mananger) override{
        cout<<"enter salary for manager:"<<"\t";
        this->setSal();
        cout<<"the salary for manager is: "<<this->getSal()<<endl;
    }
    void asoVisit(Associate &associate) override{
        cout<<"enter salary for associate:"<<"\t";
        this->setSal();
        cout<<"the salary for associate is: "<<this->getSal()<<endl;
    }
    void dirVisit(Director &director) override{
        cout<<"enter salary for director:"<<"\t";
        this->setSal();
        cout<<"the salary for director is: "<<this->getSal()<<endl;
    }
};
class ReportVisitor:public Visitor{
    public:
    void manVisit(Manager &mananger) override{
        cout<<"manager gives report of him and associate"<<endl;
    }
    void dirVisit(Director &director) override{
        cout<<"director gives report for everyone in project"<<endl;
    }
    void asoVisit(Associate &associate) override{
        cout<<"associate gives his reports"<<endl;
    }
};
class Employee{
    public:
    virtual void accept(Visitor &Vis)=0;
};
class Manager: public Employee{
    public:
    void accept(Visitor &Vis) override{
        Vis.manVisit(*this);
    }
};
class Director:public Employee{
    public:
    void accept(Visitor &Vis) override{
        Vis.dirVisit(*this);
    }
};
class Associate: public Employee{
    public:
    void accept(Visitor &Vis) override{
        Vis.asoVisit(*this);
    }
};
int main(){
    Director director;
    Manager manager;
    Associate associate;
    SalaryVisitor salVis;
    ReportVisitor repVis;
    manager.accept(repVis);
    manager.accept(salVis);
    director.accept(repVis);
    director.accept(salVis);
    associate.accept(repVis);
    associate.accept(salVis);
}