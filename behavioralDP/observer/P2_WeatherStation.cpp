#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Observer{
    public:
    virtual void update(double temp)=0;
    virtual ~Observer()=default;
};
class User:public Observer{
    private:
    string name;
    public:
    void Name(string name){
        this->name = name;
    }
    void update(double temp) override{
        cout<<"Hi "<<this->name<<" the temp has changed to: "<<temp<<endl;
    }
};
class WeatherStation{
    vector<Observer*>observers;
    double temp;
    public:
    void subscribe(Observer*observer){
        observers.push_back(observer);
    }
    void unsubscribe(Observer*observer){
        observers.erase(remove(observers.begin()    , observers.end(), observer), observers.end());
    }
    void setTemp(double temp){
        this->temp = temp;
        notify();
    }
    void notify(){
        for(Observer * obs : observers){
            obs->update(temp);
        }
    }
};
int main(){
    User Yash;
    User Shaurya;
    Yash.Name("Yash");
    Shaurya.Name("Shaurya");
    WeatherStation station;
    station.subscribe(&Yash);
    station.subscribe(&Shaurya);
    station.setTemp(28.44);
    station.unsubscribe(&Shaurya);
    station.setTemp(23.22);
    station.setTemp(33.44);

}