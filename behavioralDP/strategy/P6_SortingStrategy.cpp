#include<iostream>
#include <memory>
#include <vector>
using namespace std;
class SortStrategy{
    public:
    virtual void sort(vector<int>v)=0;
    virtual ~SortStrategy() = default;
};
class QuickSort :public SortStrategy{
    public: 
    void sort(vector<int>v) override{
        for(int i:v){
            cout<<i<<"\t";
        }
        cout<<"sorting in quicksort"<<endl;
        quickSort(v,0,v.size()-1);
        for(int i:v){
            cout<<i<<"\t";
        }
        cout<<"\n";
    }
    int partition(vector<int>& v, int low, int high) {

        int pivot = v[high];

        int i = low - 1;

        for (int j = low; j < high; j++) {

            if (v[j] < pivot) {
                i++;
                swap(v[i], v[j]);
            }
        }

        swap(v[i + 1], v[high]);

        return i + 1;
    }

    void quickSort(vector<int>& v, int low, int high) {

        if (low >= high)
            return;

        int pivotIndex = partition(v, low, high);

        quickSort(v, low, pivotIndex - 1);
        quickSort(v, pivotIndex + 1, high);
    }
};
class MergeSort : public SortStrategy{
    public:
    void sort(vector<int> v) override{
        for(int i:v){
            cout<<i<<"\t";
        }
        cout<<"sorting in mergesort"<<endl;
        mergeSort(v, 0,v.size()-1);
        for(int i:v){
            cout<<i<<"\t";
        }
        cout<<"\n";
    }
    void merge(vector<int>& v, int left, int mid, int right) {
        vector<int> temp;

        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (v[i] <= v[j]) {
                temp.push_back(v[i]);
                i++;
            } else {
                temp.push_back(v[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(v[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(v[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            v[left + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& v, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);

        merge(v, left, mid, right);
    }
};
class SortProcessor{
    private:
    unique_ptr<SortStrategy>sortStrategy;
    public:
    SortProcessor(unique_ptr<SortStrategy>strategy):sortStrategy(move(strategy)){}
    void perform(vector<int>v){
        sortStrategy->sort(v);
    }
    void setStrategy(unique_ptr<SortStrategy>strategy){
        sortStrategy=move(strategy);
    }
};
int main(){
    SortProcessor processor(make_unique<QuickSort>());
    vector<int>v = {6,8,3,4,5};
    processor.perform(v);
    processor.setStrategy(make_unique<MergeSort>());
    processor.perform(v);
}