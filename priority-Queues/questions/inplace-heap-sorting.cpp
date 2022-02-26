#include<iostream>
#include<vector>
using namespace std;

void inplaceHeapSort(vector<int>* v){
    if(v->size() == 0) return;
    int size = v->size();
    int size1 = v->size();
    int nextIndex = size - 1;
    for(int i=0; i< size1; i++){
        int parentIndex = 0;
        int leftChildIndex = 2* parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        int ans = v->at(0);
        v->at(0) = v->at(size -1);
        // v->pop_back();
        size--;
        v->at(nextIndex) = ans;
        nextIndex--;
        while(leftChildIndex < size){
            int minIndex = parentIndex;
            if(v->at(minIndex) > v->at(leftChildIndex)){
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < size && v->at(rightChildIndex) < v->at(minIndex)){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex) break;
            int temp = v->at(minIndex);
            v->at(minIndex) = v->at(parentIndex);
            v->at(parentIndex) = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}

void inplaceSorting(int* arr, int size){
    int nextIndex = size - 1;
    int size1 = size;
    for(int i=0; i<size1; i++){
        int parentIndex = 0;
        int leftChildIndex = 2* parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        int ans = arr[0];
        arr[0] = arr[size-1];
        size--;
        arr[nextIndex] = ans;
        nextIndex--;
        while(leftChildIndex < size){
            int minIndex = parentIndex;
            if(arr[minIndex] > arr[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < size && arr[rightChildIndex] < arr[minIndex]){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex) break;
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
    for(int i = 0; i< size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int size;
    cin>>size;
    int* arr = new int[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }


    inplaceSorting(arr, size);

    for(int i = 0; i< size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    cout<<endl;

    vector<int> v;
    v.push_back(2);
    v.push_back(6);
    v.push_back(8);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);

    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;
    inplaceHeapSort(&v);
    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;
}