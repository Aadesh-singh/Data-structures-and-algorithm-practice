#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node* next;
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

template<typename T>
class Stack{
    Node<T> *head;
    int size;
    public:
    Stack(){
        head = NULL;
        size = 0;
    }
    int Size(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void push(T data){
        Node<T> *newNode = new Node<T>(data);
        if(head == NULL){
            head = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
        return;
    }
    T pop(){
        if(size == 0){
            cout<<"Stack UnderFlow"<<endl;
            return 0;
        }
        int ans = head->data;
        head = head->next;
        size--;
        return ans;
    }
    T top() {
        if(size == 0){
            cout<<"Stack UnderFlow"<<endl;
            return 0;
        }
        return head->data;
    }
};

bool validate(char *arr){
    Stack<char> s;
    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] == '{' || arr[i] == '[' || arr[i] == '('){
            s.push(arr[i]);
        }
        else if(arr[i] == '}'){
            if(s.top() != '{'){
                return false;
            }
            s.pop();
        }
        else if(arr[i] == ']'){
            if(s.top() != '['){
                return false;
            }
            s.pop();
        }
        else if(arr[i] == ')'){
            if(s.top() != '('){
                return false;
            }
            s.pop();
        }
    }
    if(s.isEmpty()){
        return true;
    }
    else return false;
}

int main() {

    char arr[] = "{a+b*(c+d)}";
    bool ans = validate(arr);
    if(ans == 0){
        cout<<"No! parenthesis are not balanced"<<endl;
    }
    else cout<<"Yeah! Parenthesis are Balanced"<<endl;



    // Stack<char> s;
    // s.push(100);
    // s.push(102);
    // s.push(103);
    // cout<<s.top()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.Size()<<endl;
    // cout<<s.isEmpty()<<endl;


}