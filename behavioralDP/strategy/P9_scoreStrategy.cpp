#include<iostream>
#include <memory>
using namespace std;
class Strategy{
    protected:
    public:
    virtual int score()=0;
    virtual ~Strategy()=default;
};
class FourStrategy: public Strategy{
    public:
    int score() override{
        cout<<"four runs added to the score"<<endl;
        return 4;
    }
};
class SixStrategy: public Strategy{
    public:
    int score() override{
        cout<<"six runs added to the score"<<endl;
        return 6;
    }
};
class Processor{
    protected:
    unique_ptr<Strategy>strategyProcessor;
    int Score=0;
    public:
    Processor(unique_ptr<Strategy>strategy):strategyProcessor(move(strategy)){}
    void changeStrategy(unique_ptr<Strategy>strategy){
        strategyProcessor=move(strategy);
    }
    void generateScorecard(){
        Score+=strategyProcessor->score();
        cout<<"total score: \t";
        cout<<Score<<endl;
    }
};
int main(){
    Processor scoreProcessor = Processor(make_unique<SixStrategy>());
    scoreProcessor.generateScorecard();
    scoreProcessor.changeStrategy(make_unique<FourStrategy>());
    scoreProcessor.generateScorecard();
}