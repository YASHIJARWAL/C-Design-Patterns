#include<iostream>
#include <memory>
#include <unordered_map>
using namespace std;
class flyweight{
    public: 
    virtual void operation(string extrinsicState)=0;
    virtual ~flyweight()=default;
};
class ConcreteFlyweight: public flyweight{
    protected: 
    string intrinsicState;
    public:
    ConcreteFlyweight(string state): intrinsicState(move(state)){}
    void operation(string extrinsicState) override{
        cout<<"intrinsic state: "<<intrinsicState<<endl;
        cout<<"extrinsic state: "<<extrinsicState<<endl;
    }
};
class flyweightFactory{
    unordered_map<string,shared_ptr<flyweight>>mpp;
    public:
    shared_ptr<flyweight>getFlyweight(string key){
        if(mpp.find(key)==mpp.end()){
            mpp[key]=make_shared<ConcreteFlyweight>(key);
        }
        return mpp[key];
    }
};
int main(){
    flyweightFactory factory;
    auto flyweight1 = factory.getFlyweight("A");
    auto flyweight2 = factory.getFlyweight("B");
    auto flyweight3 = factory.getFlyweight("A");
    flyweight1->operation("pos1");
    flyweight2->operation("pos2");
    flyweight3->operation("pos3");
    cout<<(flyweight1==flyweight2)<<endl;
    cout<<(flyweight1==flyweight3)<<endl;
}