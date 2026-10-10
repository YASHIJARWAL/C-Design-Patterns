#include <iostream>
#include <memory>
using namespace std;
class Database{
    public:
    virtual void useDB()=0;
    virtual ~Database()=default;
};
class MongoDB: public Database{
    public:
    void useDB() override{
        cout<<"using MongoDB"<<endl;
    }
};
class SQL: public Database{
    public:
    void useDB() override{
        cout<<"using sql"<<endl;
    }
};
class PostGres: public Database{
    public:
    void useDB() override{
        cout<<"PostGres SQL in use"<<endl;
    }
};
class DatabaseCreator{
    public:
    virtual unique_ptr<Database>ListDb()=0;
    virtual ~DatabaseCreator()=default;
    void execute(){
        auto db =ListDb();
        db->useDB();
    }
};
class SQLCreator: public DatabaseCreator{
    public:
    unique_ptr<Database> ListDb() override{
        return make_unique<SQL>();
    }
};
class PostGresCreator: public DatabaseCreator{
    public:
    unique_ptr<Database> ListDb() override{
        return make_unique<PostGres>();
    }
};
int main(){
    unique_ptr<DatabaseCreator>pg = make_unique<PostGresCreator>();
    unique_ptr<DatabaseCreator>sql = make_unique<SQLCreator>();
    pg->execute();
    sql->execute();

}