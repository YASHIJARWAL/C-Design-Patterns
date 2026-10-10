#include<iostream>
#include <memory>
using namespace std;
class Target{
    public:
    virtual void send()=0;
    virtual ~Target()=default;
};
class Adaptee{
    public:
    virtual void sendUsingLegacyApp()=0;
    virtual ~Adaptee()=default;  
};
class SendEmail :public Adaptee{
    public:
    void sendUsingLegacyApp() override{
        sendEmail();
    }
    void sendEmail(){
        cout<<"sending email via legacy app"<<endl;
    }
};
class SendSMS :public Adaptee{
    public:
    void sendUsingLegacyApp() override{
        sendSMS();
    }
    void sendSMS(){
        cout<<"sending sms via legacy app"<<endl;
    }
};
class Adapter:public Target{
    unique_ptr<Adaptee>adaptee;
    public:
    Adapter(unique_ptr<Adaptee>adaptee):adaptee(move(adaptee)){}
    void send() override{
        adaptee->sendUsingLegacyApp();
    }
};
class client{
    public:
    void execute(Target &target){
        target.send();
    }
};
int main(){
    auto sms = make_unique<SendSMS>();
    auto email = make_unique<SendEmail>();
    auto adapter1 = Adapter(move(sms));
    auto adapter2 = Adapter(move(email));
    client c;
    c.execute(adapter1);
    c.execute(adapter2);
}
