#include<iostream>
#include <memory>
#include <utility>
using namespace std;
class PaymentStrategy{
    public:
        virtual void pay(double amt)=0;
        virtual~PaymentStrategy()=default;
};
class CashStrategy:public PaymentStrategy{
    private: 
        void trackOrder(){
            cout<<"opening the tracker in a new window"<<endl;
        }
    public: 
        void pay(double amt) override{
            cout<<"payment will be done using cash"<<endl;
            trackOrder();
        }
        
};
class UPIStrategy: public PaymentStrategy{
    private:
        void loginUPI(){
            cout<<"redirecting you to UPI app"<<endl;
        }
    public:
        void pay(double amt) override{
            cout<<"payment will be done using UPI"<<endl;
            loginUPI();
        }    
};
class PaymentProcessor{
    private:
    unique_ptr<PaymentStrategy>paymentStrategy;
    public:
    PaymentProcessor(unique_ptr<PaymentStrategy>strategy):paymentStrategy(move(strategy)){}
    void checkout(double amt){
        paymentStrategy->pay(amt);
        bill(amt);
    }
    void bill(double amt){
        cout<<"your bill is : "<<amt<<endl;
    }
    void setPaymentStrategy(unique_ptr<PaymentStrategy>strategy){
        paymentStrategy = move(strategy);
    }
};
int main(){
    PaymentProcessor processor(make_unique<CashStrategy>());
    processor.checkout(547.66);
    processor.setPaymentStrategy(make_unique<UPIStrategy>());
    processor.checkout(44.33);
}