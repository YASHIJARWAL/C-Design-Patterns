#include<iostream>
#include <memory>
using namespace std;
class Permission{
    public:
    string input;
    Permission(string input):input(input){}
    bool hasPermission(string role){
        return input == role;
    }
};
class Level{
    public:
    virtual bool permission(Permission &context)=0;
    virtual ~Level()=default;
};
class Admin: public Level{
    public:
    bool permission(Permission &context) override{
        return context.hasPermission("Admin");
    }
};
class User: public Level{
    unique_ptr<Level>grant;
    public: 
    bool permission(Permission &context) override{
        return context.hasPermission("User");
    }
};

int main(){
    Permission("granting permission");
}