#include<iostream>
using namespace std;
class TicketHandler{
    protected:
    TicketHandler *nextHandler;
    public:
    TicketHandler():nextHandler(nullptr){}
    virtual void setNext(TicketHandler*nextHandler)=0;
    virtual void handleTicket(int priority)=0;
    virtual ~TicketHandler()=default;
};
class BotHandler:public TicketHandler{
    public:
    void setNext(TicketHandler *nextHandler) override{
        this->nextHandler=nextHandler;
    }
    void handleTicket(int priority) override{
        if(priority == 0){
            cout<<"The bot is handling your ticket"<<endl;
        }
        else if(nextHandler!=nullptr){
            cout<<"Transferring to next in line"<<endl;
            nextHandler->handleTicket(priority);
        }
    }
};
class AgentHandler : public TicketHandler{
    public:
    void setNext(TicketHandler *nextHandler) override{
        this->nextHandler = nextHandler;
    }
    void handleTicket(int priority) override{
        if(priority == 1){
            cout<<"the agent is handling your ticket"<<endl;
        }
        else if (nextHandler !=nullptr){
            cout<<"sending to next in line"<<endl;
            nextHandler->handleTicket(priority);
        }
    }
};
class SeniorAgentHandler: public TicketHandler{
    public:
    void setNext(TicketHandler *nextHandler) override{
        this->nextHandler=nextHandler;
    }
    void handleTicket(int priority) override{
        if(priority ==2){
            cout<<"Senior agent is handling your ticket"<<endl;
        }
        else if (nextHandler==nullptr) {
            cout<<"Invalid priority set for the ticket"<<endl;
        }
    }
};
int main(){
    AgentHandler agent;
    BotHandler bot;
    SeniorAgentHandler senior;
    bot.setNext(&agent);
    agent.setNext(&senior);
    senior.setNext(nullptr);
    bot.handleTicket(0);
    bot.handleTicket(1);
    bot.handleTicket(2);
    bot.handleTicket(3);
}