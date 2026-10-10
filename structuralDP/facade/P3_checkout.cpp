#include <iostream>
using namespace std;
class Cart{
    public:
    void addToCart(){
        cout<<"added to cart"<<endl;
    }
};
class Inventory{
    public:
    void checkedInventory(){
        cout<<"checked with inventory"<<endl;
    }
};
class Payment{
    public:
    void pay(){
        cout<<"paying for the order"<<endl;
    }
};
class Notification{
    public: 
    void send(){
        cout<<"notification sent"<<endl;
    }
};
class Checkout{
    Cart &cart;
    Inventory &inventory;
    Payment &payment;
    Notification &notify;
    public:
    Checkout(Cart &cart , Inventory &inventory , Payment &payment , Notification &notification):cart(cart),inventory(inventory),payment(payment),notify(notification){}
    void checkingOut(){
        cart.addToCart();
        inventory.checkedInventory();
        payment.pay();
        notify.send();
    }

};
int main(){
    Cart c;
    Inventory i ;
    Payment p;
    Notification n;
    Checkout checkingout(c,i,p,n);
    checkingout.checkingOut();
}