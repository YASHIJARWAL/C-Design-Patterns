#include<iostream>
#include <memory>
using namespace std;
class Req{
    public:
    virtual void req()=0;
};
class Database: public Req{
    public:
    virtual void db()=0;
    void req() override{
        cout<<"database product"<<endl;
    }
};
class Query: public Req{
    public:
    virtual void query()=0;
    void req() override{
        cout<<"query product"<<endl;
    }
};
class MacDb: public Database{
    public:
    void db() override{
        cout<<"mac db"<<endl;
    }
};
class WinDb: public Database{
    public:
    void db() override{
        cout<<"windows db"<<endl;
    }
};
class MacQuery: public Query{
    public:
    void query() override{
        cout<<"mac query"<<endl;
    }
};
class WinQuery: public Query{
    public:
    void query() override{
        cout<<"windows query"<<endl;
    }
};
class Creator{
    public:
    virtual unique_ptr<Database>databaseCreator()=0;
    virtual unique_ptr<Query>queryCreator()=0;
    void execute(){
        databaseCreator()->db();
        queryCreator()->query();
        databaseCreator()->req();
        queryCreator()->req();
    }
};
class MacCreator: public Creator{
    public:
    unique_ptr<Database> databaseCreator() override{
        return make_unique<MacDb>();
    }
    unique_ptr<Query> queryCreator() override{
        return make_unique<MacQuery>();
    }
};
class WinCreator: public Creator{
    public:
    unique_ptr<Database> databaseCreator() override{
        return make_unique<WinDb>();
    }
    unique_ptr<Query> queryCreator() override{
        return make_unique<WinQuery>();
    }
};
int main(){
    unique_ptr<WinCreator>winCreator= make_unique<WinCreator>();
    unique_ptr<MacCreator>macCreator = make_unique<MacCreator>();
    winCreator->execute();
    macCreator->execute();
}