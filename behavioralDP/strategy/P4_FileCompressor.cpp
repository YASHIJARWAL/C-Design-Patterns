#include<iostream>
#include <memory>
#include <string>
using namespace std;
class Compressor{
    public:
    virtual void compress(string filename)=0;
};
class ZipCompress: public Compressor{
    public:
    void compress(string filename) override{
        cout<<"compressing the file using zip"<<endl;
    }
};
class RarCompress: public Compressor{
    public:
    void compress(string filename) override{
        cout<<"compressing using RAR"<<endl;
    }
};
class TarCompress: public Compressor{
    public:
    void compress(string filename) override{
        cout<<"compressing using TAR"<<endl;
    }
};
class CompressProcessor{
    private:
    unique_ptr<Compressor>compressProcessor;
    public:
    CompressProcessor(unique_ptr<Compressor> strategy):compressProcessor(move(strategy)){}
    void CompressingFile(string filename){
        compressProcessor->compress(filename);
    }
    void setStrategy(unique_ptr<Compressor>strategy){
        compressProcessor= move(strategy);
    }
};
int main(){
    CompressProcessor processor(make_unique<TarCompress>());
    processor.CompressingFile("file1.txt");
    processor.setStrategy(make_unique<ZipCompress>());
    processor.CompressingFile("file2.docs");
}