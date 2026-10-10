#include<iostream>
#include <memory>
using namespace std;

//|----------------------|
//|      Strategy        |
//|----------------------|


class PaymentStrategy{
    public:
    virtual void pay(double amount)=0;
    virtual ~PaymentStrategy()=default;
};

//|----------------------|
//| Concrete Strategy-I  |
//|----------------------|

class CashStrategy: public PaymentStrategy{
    public:
    void pay(double amount) override{
        cout<<"payment will be done using cash. Kindly pay: "<<amount<<endl;
    }
};

//|----------------------|
//| Concrete Strategy-II |
//|----------------------|
class UPIStrategy: public PaymentStrategy{
    public:
    void pay(double amount) override{
        cout<<"transferring to UPI please pay: "<<amount<<endl;
    }
};

//|----------------------|
//| Concrete Strategy-III|
//|----------------------|
class CardStrategy : public PaymentStrategy{
    public:
    void pay(double amount) override{
        cout<<"swipe the card in the machine and enter your pin to pay: "<<amount<<endl;
    }
};

//|----------------------|
//|      Processor       |
//|----------------------|

class PaymentProcessor{
    private:
    unique_ptr<PaymentStrategy> paymentStrategy ;
    public:
    PaymentProcessor(unique_ptr<PaymentStrategy>strategy):paymentStrategy(move(strategy)){}
    void checkout(double amt){
        paymentStrategy->pay(amt);
        genBill(amt);
        greet();
        
    }
    void genBill(double amt){
        cout<<"The bill has been paid for the order. Final amount:"<<amt<<endl;
    }
    void greet(){
        cout<<"THANK YOU"<<endl;
    }
    void setPaymentStrategy(unique_ptr<PaymentStrategy>strategy){
        paymentStrategy=move(strategy);
    }
};


//|----------------------|
//|        client        |
//|----------------------|

int main(){
    PaymentProcessor processor(make_unique<UPIStrategy>());
    processor.checkout(5000.98);
    PaymentProcessor Cashprocessor(make_unique<CashStrategy>());
    Cashprocessor.checkout(340.44);
    PaymentProcessor Cardprocessor(make_unique<CardStrategy>());
    Cardprocessor.checkout(860.32);
    processor.setPaymentStrategy(make_unique<CardStrategy>());
    processor.checkout(670.85);
}
