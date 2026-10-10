#include<iostream>
#include <memory>
#include <string>
using namespace std;

class MessagingStrategy{
    public:
    virtual void send()=0;
    virtual ~MessagingStrategy()=default;
};
class SMTPStrategy:public MessagingStrategy{
    private:
    void Sent(){
        cout<<"msg sent from mailbox of sender"<<endl;
    }
    void ack(){
        unique_ptr<MessagingStrategy> strategy;
        cout<<"msg recieved at reciever mailbox"<<endl;
    }
    public:
    void send() override{
        cout<<"SMTP protocol in use"<<endl;
        Sent();
        ack();
    }
};
class SMSStrategy:public MessagingStrategy{
    private:
    void balance(){
        cout<<"deducted amount from your balance has been sent to you in the mail attached to this number"<<endl;
    }
    public:
    void send() override{
        cout<<"SMS protocol in use"<<endl;
        balance();
    }
};
class MessageProcessor{
    private:
    unique_ptr<MessagingStrategy>messagingStrategy;
    public:
    MessageProcessor(unique_ptr<MessagingStrategy>strategy):messagingStrategy(move(strategy)){}
    void sendingMsg(){
        messagingStrategy->send();
    }
    void setStrategy(unique_ptr<MessagingStrategy>strategy){
        messagingStrategy = move(strategy);
    }
};
int main(){
    MessageProcessor processor(make_unique<SMTPStrategy>());
    processor.sendingMsg();
    processor.setStrategy(make_unique<SMSStrategy>());
    processor.sendingMsg();
}