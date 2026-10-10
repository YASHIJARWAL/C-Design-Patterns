#include<iostream>
#include <memory>
using namespace std;
class FileProcessor{
    protected:
    string name;
    public:
        virtual void process()=0;
        virtual ~FileProcessor()=default;
        virtual void setName(string name){
            this->name = name;
        }
};
class ProcessFile:public FileProcessor{
    public:
        void process() override{
            cout<<"processing the file"<<this->name<<endl;
        }
};
class MoreOperations: public FileProcessor{
    protected:
    unique_ptr<FileProcessor>processedFile;
    public:
        MoreOperations(unique_ptr<FileProcessor>processor):processedFile(move(processor)){}
        void setName(string name) override{
            this->name = name;
            processedFile->setName(name);
        }
        virtual~MoreOperations()=default;
};
class EncryptFile: public MoreOperations{
    public:
        EncryptFile(unique_ptr<FileProcessor>processor):MoreOperations(move(processor)){}
        void process()override{
            cout<<"encrypting the file"<<this->name<<endl;
            processedFile->process();

        }
};
class CompressFile: public MoreOperations{
    public:
        CompressFile(unique_ptr<FileProcessor>processor):MoreOperations(move(processor)){}
        void process()override{
            cout<<"compressing the file"<<this->name<<endl;
            processedFile->process();
        }
};
int main(){
    unique_ptr<FileProcessor>processing = make_unique<ProcessFile>();
    processing = make_unique<EncryptFile>(move(processing));
    processing = make_unique<CompressFile>(move(processing));
    processing->setName("File1.txt");
    processing->process();
}