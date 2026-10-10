#include<iostream>
#include <memory>
using namespace std;
class NotificationService{
    protected:
    string name;
    public:
    virtual void send()=0;
    virtual void setName(string name){
        this->name = name;
    }
    virtual ~NotificationService()=default;
};
class EmailNotification: public NotificationService{
    public:
    void send() override{
        cout<<"sending notification to email:"<<this->name<<endl;
    }
};
class MoreNotification: public NotificationService{
    protected:
    unique_ptr<NotificationService>notifications;
    public:
    MoreNotification(unique_ptr<NotificationService>notification):notifications(move(notification)){}
    void setName(string name){
        this->name = name;
        notifications->setName(name);
    }
    virtual ~MoreNotification()=default;
};
class SMSNotification: public MoreNotification{
    public:
    SMSNotification(unique_ptr<NotificationService>notification):MoreNotification(move(notification)){}
    void send() override{
        notifications ->send();
        cout<<"sending notification via sms:"<<this->name<<endl;
    }
};
class SlackNotification : public MoreNotification{
    public:
    SlackNotification(unique_ptr<NotificationService>notification):MoreNotification(move(notification)){}
    void send() override{
        notifications->send();
        cout<<"sending notification via slack:"<<this->name<<endl;
    }
};

int main(){
    unique_ptr<NotificationService> notifyMe = make_unique<EmailNotification>();
    notifyMe = make_unique<SMSNotification>(move(notifyMe));
    notifyMe =  make_unique<SlackNotification>(move(notifyMe));
    notifyMe->setName("Yash");
    notifyMe->send();

}