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

void postOrder(BTN<int>* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

BTN<int>* buildTreePostHelper(int* in, int* post, int inS, int inE, int postS, int postE) {
	if (inS > inE) {
		return NULL;
	}

	int rootData = post[postE];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}

	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPostS = postS;
	int lPostE = lInE - lInS + lPostS;
	int rPostS = lPostE + 1;
	int rPostE = postE - 1;
	int rInS = rootIndex + 1;
	int rInE = inE;
	
    BTN<int>*  root = new BTN<int>(rootData);
    
    root->left = buildTreePostHelper(in, post, lInS, lInE, lPostS, lPostE);
    root->right = buildTreePostHelper(in, post, rInS, rInE, rPostS, rPostE);
	
	return root;
}

BTN<int>* buildTreePost(int* in, int* post, int size) {
	return buildTreePostHelper(in, post, 0, size - 1, 0, size - 1);
}
//   1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    int size;
    cin>>size;
    int* in = new int[size];
    int* post = new int[size];
    for(int i=0; i<size; i++)  cin>>post[i];
    for(int j=0; j<size; j++)  cin>>in[j];
    
    BTN<int>* root = buildTreePost(in,post,size);
    print(root);
    cout<<endl;
    postOrder(root);

    delete root;
    delete [] in;
    delete [] post;
}
