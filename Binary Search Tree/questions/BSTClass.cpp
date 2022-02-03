#include<iostream>
#include"../BinarySearchTreeNode.h"
#include<climits>
using namespace std;

class BinarySearchTree{
    private:
    BST<int>* root;

    bool hasData(BST<int>* root, int data){
        if(!root) return false;
        if(root->data == data) return true;
        else if(root->data < data) return hasData(root->right, data);
        else if(root->data > data) return hasData(root->left, data);
    }

    BST<int>* insertData(BST<int>* node, int data){
        if(!node){
            BST<int>* newNode = new BST<int>(data);
            return newNode;
        }
        if(data < node->data){
            node->left = insertData(node->left, data);
        }
        else{
            node->right = insertData(node->right, data);
        }
        return node;
    }

    void print(BST<int>* root){
        if(!root) return;
        cout<<root->data<<": ";
        if(root->left){
            cout<<"L: "<<root->left->data<<" ";
        }
        if(root->right){
            cout<<"R: "<<root->right->data<<" ";
        }
        cout<<endl;
        print(root->left);
        print(root->right);
    }

    int minimum(BST<int>* root){
        if(!root) return INT_MAX;
        return min(root->data, min(minimum(root->left), minimum(root->right)));
    }

    BST<int>* deleteData(BST<int>* node, int data){
        if(!node) return NULL;

        if(data > node->data){
            node->right = deleteData(node->right, data);
        }
        else if(data < node->data){
            node->left = deleteData(root->left, data);
        }
        else{
            if(!node->left && !node->right){
                delete node;
                return NULL;
            }
            else if(!node->left){
                BST<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if(!node->right){
                BST<int>* temp = node->left;
                node->left = NULL;
                delete node;  
                return temp;
            }
            else {
                BST<int>* minNode = node->right;
                while(minNode->left != NULL) minNode = minNode->left;

                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(node->right, rightMin);
                return node;
            }
        }
    }

    public: 
    BinarySearchTree(){
        root = NULL;
    }
    ~BinarySearchTree(){
        delete root;
    }

    void deleteData(int data){
        root = deleteData(root, data);
    }
    void print(){
        print(root);
        return;
    }
    void insertData(int data){
        this->root = insertData(root, data);
        return;
    }
    bool hasData(int data){
       return hasData(root, data);
    }
};

int main(){
    BinarySearchTree b;
    b.insertData(4);
    b.insertData(5);
    b.insertData(6);
    b.print();
    cout<<b.hasData(5)<<endl;
    b.deleteData(5);
    b.print();

}