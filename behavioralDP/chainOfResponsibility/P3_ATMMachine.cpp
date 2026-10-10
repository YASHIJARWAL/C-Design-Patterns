#include <iostream>
using  namespace std;

class ATMHandler{
    protected:
    ATMHandler *nextHandler;
    public:
    ATMHandler():nextHandler(nullptr){}
    virtual void setNext(ATMHandler *nextHandler)=0;
    virtual void handleNotes(double amount)=0;
    virtual ~ATMHandler()=default;
};
class ATMHandler500 : public ATMHandler{
    private:
    int notes;
    public:
    void setNotes(int notes){
        this->notes = notes;
    }
    void setNext(ATMHandler *nextHandler) override{
        this->nextHandler=nextHandler;
    }
    void handleNotes(double amount) override{
        cout<<"amount:"<<amount<<" to be seen by 500 handler"<<endl;
        if(amount-notes*500<=0 && amount>=500){
            cout<<"handled by 500 rupees"<<endl;
            notes-=min((int)(amount / 500), notes);
        }
        else if(nextHandler!=nullptr && amount>=100){
            cout<<"giving 500 rs: "<<notes<<endl;
            nextHandler->handleNotes(amount-(min((int)(amount / 500), notes))*500);
            notes-=min((int)(amount / 500), notes);
        }
    }
};
class ATMHandler200: public ATMHandler{
    private:
    int notes;
    public:
    void setNotes(int notes){
        this->notes = notes;
    }
    void setNext(ATMHandler *nextHandler) override{
        this->nextHandler=nextHandler;
    }
    void handleNotes(double amount) override{
        cout<<"amount:"<<amount<<" to be seen by 200 handler"<<endl;
        if(amount-notes*200<=0 && amount>=200){
            cout<<"handled by 200 rupees"<<endl;
            notes-=min((int)(amount / 200), notes);
        }
        else if(nextHandler!=nullptr  && amount>=100){
            cout<<"giving 200 rs: "<<notes<<endl;
            nextHandler->handleNotes(amount-(min((int)(amount / 200), notes))*200);
            notes-=min((int)(amount / 200), notes);
        }
    }
};
class ATMHandler100: public ATMHandler{
    private:
    int notes;
    public:
    void setNotes(int notes){
        this->notes = notes;
    }
    void setNext(ATMHandler *nextHandler) override{
        this->nextHandler=nextHandler;
    }
    void handleNotes(double amount) override{
        cout<<"amount:"<<amount<<" to be seen by 100 handler"<<endl;
        if(amount-notes*100<=0 && amount>=100){
            cout<<"handled by 100 rupees"<<endl;
        }
        else if(nextHandler==nullptr){
            cout<<"kindly go to the counter and register "<<amount<<endl;
        }
    }
};
int main(){
    ATMHandler500 fiveHundred;
    ATMHandler200 twoHundred;
    ATMHandler100 oneHundred;
    fiveHundred.setNotes(5);
    fiveHundred.setNext(&twoHundred);
    twoHundred.setNotes(2);
    twoHundred.setNext(&oneHundred);
    oneHundred.setNotes(1);
    oneHundred.setNext(nullptr);
    fiveHundred.handleNotes(2500);
    fiveHundred.setNotes(5);
    twoHundred.setNotes(1);
    fiveHundred.handleNotes(2700);
    fiveHundred.setNotes(5);
    twoHundred.setNotes(2);
    oneHundred.setNotes(1);
    fiveHundred.handleNotes(3000);
    fiveHundred.handleNotes(67);

}