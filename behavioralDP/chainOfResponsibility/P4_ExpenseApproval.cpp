#include<iostream>
using namespace std;
class ExpenseHandler{
    protected:
    ExpenseHandler *nextHandler;
    public:
    ExpenseHandler():nextHandler(nullptr){}
    virtual void setNext(ExpenseHandler*newHandler)=0;
    virtual void handleExpense(double amount)=0;
    ~ExpenseHandler()=default;
};
class Employee:public ExpenseHandler{
    public:
    void setNext(ExpenseHandler *newHandler) override{
        nextHandler = newHandler;
    }
    void handleExpense(double amount) override{
        if(amount<=5000){
            cout<<"handled by Employee"<<endl;
        }
        else if (nextHandler!=nullptr) {
            cout<<"handled by next heirarchy"<<endl;
            nextHandler->handleExpense(amount);
        }
    }
};
class Manager:public ExpenseHandler{
    public:
    void setNext(ExpenseHandler *newHandler) override{
        nextHandler=newHandler;
    }
    void handleExpense(double amount) override{
        if(amount<=15000 and amount>5000){
            cout<<"handled by manager"<<endl;
        }
        else if (nextHandler!=nullptr) {
            cout<<"handled by next heirarchy"<<endl;
            nextHandler->handleExpense(amount);
        }
    }
};
class Director :public ExpenseHandler{
    public:
    void setNext(ExpenseHandler *newHandler) override{
        nextHandler=newHandler;
    }
    void handleExpense(double amount) override{
        if(amount>15000){
            cout<<"handled by director"<<endl;
        }
    }
};
int main(){
    Employee employee;
    Manager manager;
    Director director;
    employee.setNext(&manager);
    manager.setNext(&director);
    director.setNext(nullptr);
    employee.handleExpense(2000);
    employee.handleExpense(6000);
    employee.handleExpense(100000);
}
