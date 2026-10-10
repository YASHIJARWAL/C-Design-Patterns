#include <cstdio>
#include<iostream>
using namespace std;
class GetRequest;
class PostRequest;
class DeleteRequest;
class Visitor{
    public:
    virtual void visit(GetRequest *getrequest)=0;
    virtual void visit(PostRequest *postrequest)=0;
    virtual void visit(DeleteRequest *delrequest)=0;
    virtual ~Visitor()=default;
};
class LoggingVisitor:public Visitor{
    public:        
     void visit(GetRequest *getrequest) override{
        cout<<"logging for get request"<<endl;
     }
     void visit(PostRequest *postrequest) override{
        cout<<"logging for post request"<<endl;
     }
     void visit(DeleteRequest *delrequest) override{
        cout<<"logging for del request"<<endl;
     }
};
class AuthVisitor: public Visitor{
    public:
    void visit(GetRequest *getrequest) override{
        cout<<"auth for get request"<<endl;
    }
    void visit(PostRequest *postrequest) override{
        cout<<"auth for post request"<<endl;
    }
    void visit(DeleteRequest *delrequest) override{
        cout<<"auth for del request"<<endl;
    }
};
class RoleVisitor: public Visitor{
    public:
    void visit(GetRequest *getrequest) override{
        cout<<"authorization for get request"<<endl;
    }
    void visit(PostRequest *postrequest) override{
        cout<<"authourization for post request"<<endl;
    }
    void visit(DeleteRequest *delrequest) override{
        cout<<"authorization for del request"<<endl;
    }
};
class RateVisitor:public Visitor{
    public:
    void visit(GetRequest *getrequest) override{
        cout<<"rate limiter for get request"<<endl;
    }
    void visit(PostRequest *postrequest) override{
        cout<<"rate limiter for post request"<<endl;
    }
    void visit(DeleteRequest *delrequest) override{
        cout<<"rate limiter for del request"<<endl;
    }
};
class Request{
    public: 
    virtual void accept(Visitor &visitor)=0;
    virtual ~Request()=default;
};
class GetRequest: public Request{
    public:
    void accept(Visitor &visitor) override{
        visitor.visit(this);
    }
};
class PostRequest : public Request{
    public:
    void accept(Visitor &visitor) override{
        visitor.visit(this);
    }
};
class DeleteRequest : public Request{
    public:
    void accept(Visitor &visitor) override{
        visitor.visit(this);
    }
};
int main(){
    DeleteRequest del;
    PostRequest post;
    LoggingVisitor logvis;
    RateVisitor ratevis;
    RoleVisitor rolevis;
    AuthVisitor authvis;
    del.accept(logvis);
    del.accept(authvis);
    del.accept(rolevis);
    del.accept(ratevis);
    post.accept(logvis);
    post.accept(authvis);
    post.accept(rolevis);
    post.accept(ratevis);
}