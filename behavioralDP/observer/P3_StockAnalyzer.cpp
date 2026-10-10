#include <algorithm>
#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Customer{
    public:
    virtual void update(string stock , double price)=0;
    virtual ~Customer()=default;
};
class BSETower{
    private:
    vector<Customer*>customers;
    public:
    void subscribe(Customer* customer){
        customers.push_back(customer);
    }
    void unsubscribe(Customer * customer){
        customers.erase(remove(customers.begin(), customers.end(), customer),customers.end());
    }
    void notify(string stock , double price){
        for(Customer*c : customers){
          c->update(stock,price);  
        };
    }
    void setPrice(string stock , double price){
        notify(stock,price);
    }
};
class Investor:public Customer{
    private:
    string Name;
    public:
    void setName(string name){
        this->Name = name;
    }
    void update(string stock, double price) override{
        cout<<"Hi "<<Name<<" stock : "<<stock<<" is updated to price: "<<price<<endl;
    }
};
int main(){
    Investor Yash;
    Investor Shaurya;
    BSETower mumOffice;
    Yash.setName("Yash");
    Shaurya.setName("Shaurya");
    mumOffice.subscribe(&Yash);
    mumOffice.subscribe(&Shaurya);
    mumOffice.setPrice("AdaniPorts", 66.44);
    mumOffice.unsubscribe(&Shaurya);
    mumOffice.setPrice("LTI", 34.21);
}