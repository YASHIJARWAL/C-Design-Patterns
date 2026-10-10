#include <algorithm>
#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Observer{
    public:
    virtual void update(string msg)=0;
    virtual ~Observer() = default;
};
class EmailNotify: public Observer{
    void update(string msg) override{
        cout<<"Email notification: "<<msg<<endl;
    }
};
class SMSNotify: public Observer{
    void update(string msg) override{
        cout<<"SMS notification: "<<msg<<endl;
    }
};
class NotificationService{
    private:
    vector<Observer*>observers;
    public:
    void subscribe(Observer* observer){
        observers.push_back(observer);
    }
    void unsubscribe(Observer*observer){
        observers.erase(remove(observers.begin(), observers.end(), observer),observers.end());
    }
    void notify(string msg){
        for(Observer*obs: observers){
            obs->update(msg);
        }
    }
    void sendNotification(string msg){
        cout<<"send msg"<<endl;
        notify(msg);
    }
};
int main(){
    NotificationService service;
    EmailNotify email;
    SMSNotify sms;
    service.subscribe(&email);
    service.subscribe(&sms);
    service.notify("hello all");
    service.unsubscribe(&email);
    service.notify("email unsubscribed");
}