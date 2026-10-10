#include<iostream>
using namespace std;
class File;
class Directory;
class SymbolicLink;
class Visitor{
    public:
    virtual void visFile(File *file)=0;
    virtual void visDir(Directory *directory)=0;
    virtual void visSL(SymbolicLink *sl)=0;
    virtual ~Visitor()=default;
};
class Structure{
    public:
    virtual void accept(Visitor *vis)=0;
    virtual ~Structure()=default;
};
class PermissionVisitor:public Visitor{
    public:
    void visDir(Directory *directory) override{
        cout<<"permission to enter directory"<<endl;
    }
    void visFile(File *file) override{
        cout<<"permission to enter file"<<endl;
    }
    void visSL(SymbolicLink *sl) override{
        cout<<"permission to enter symbolic link"<<endl;
    }
};
class StoreVisitor: public Visitor{
    public:
    void visDir(Directory *directory) override{
        cout<<"storing in directory"<<endl;
    }
    void visSL(SymbolicLink *sl) override{
        cout<<"storing in symbolic link"<<endl;
    }
    void visFile(File *file) override{
        cout<<"Storing in file"<<endl;
    }
};
class File:public Structure{
    public:
    void accept(Visitor *vis) override{
        vis->visFile(this);
    }
};
class Directory: public Structure{
    public:
    void accept(Visitor *vis) override{
        vis->visDir(this);
    }
};
class SymbolicLink: public Structure{
    public:
    void accept(Visitor *vis) override{
        vis->visSL(this);
    }
};
int main(){
    StoreVisitor store;
    PermissionVisitor permission;
    SymbolicLink sl;
    Directory dir;
    File file;
    file.accept(&store);
    dir.accept(&store);
    sl.accept(&store);
    file.accept(&permission);
    dir.accept(&permission);

}