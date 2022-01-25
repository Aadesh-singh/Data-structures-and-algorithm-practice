#include<iostream>
#include"../BinaryTreeNode.h"
#include<queue>
using namespace std;


void print(BTN<int>* root){
    queue<BTN<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";
        if(front->left){
            cout<<"L->"<<front->left->data<<",";
            pendingNodes.push(front->left);
        }
        if(front->right){
            cout<<"L->"<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

void preOrder(BTN<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

BTN<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
	if (inS > inE) {
		return NULL;
	}

	int rootData = pre[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}

	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	int rInS = rootIndex + 1;
	int rInE = inE;
	BTN<int>*  root = new BTN<int>(rootData);
	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}

BTN<int>* buildTree(int* in, int* pre, int size) {
	return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}
//   1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    int size;
    cin>>size;
    int* in = new int[size];
    int* pre = new int[size];
    for(int i=0; i<size; i++)  cin>>pre[i];
    for(int j=0; j<size; j++)  cin>>in[j];
    
    BTN<int>* root = buildTree(in,pre,size);
    print(root);
    cout<<endl;
    preOrder(root);

    delete root;
    delete [] in;
    delete [] pre;
}
