#include<vector>
using namespace std;

class PriorityQueues{
    vector<int> pq;

    public:
    PriorityQueues(){

    }

    // Return if out priority queue is empty or not
    bool isEmpty() {
        return pq.size() == 0;
    }

    // return the size of the Priority Queue
    int getSize() {
        return pq.size();
    }

    // GetMin of the priority queue
    int getMin(){
        if(pq.size() == 0) {
            return 0;   //if our queue is empty return 0
        }

        return pq[0];
    }

    // Insert Element in the proirity Queue
    void insert(int data){
        pq.push_back(data);
        int childIndex = pq.size() - 1;

        while(childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;
            if(pq[childIndex] < pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin(){
        if(isEmpty()) return 0;

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // Down heapify
        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;

        while(leftChildIndex < pq.size()){
            int minIndex = parentIndex;
            if(pq[leftChildIndex] < pq[minIndex]){
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex]){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex) {
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }
};