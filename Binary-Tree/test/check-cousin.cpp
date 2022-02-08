#include <iostream>
#include "../BinaryTreeNode.h"
#include <queue>
using namespace std;

BTN<int> *takeInput()
{
    int rootdata;
    cin >> rootdata;
    if (rootdata == -1)
        return NULL;
    BTN<int> *root = new BTN<int>(rootdata);
    queue<BTN<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BTN<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            BTN<int> *left = new BTN<int>(leftData);
            front->left = left;
            pendingNodes.push(left);
        }
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            BTN<int> *right = new BTN<int>(rightData);
            front->right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}

void print(BTN<int> *root)
{
    queue<BTN<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (!pendingNodes.empty())
    {
        BTN<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (!front)
        {
            cout << endl;
            if (pendingNodes.empty())
            {
                return;
            }
            else
                pendingNodes.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
                pendingNodes.push(front->left);
            if (front->right)
                pendingNodes.push(front->right);
        }
    }
}


int depth(BTN<int> *root, int node)
{
    if (root == NULL)
        return -1;
    if (node == root->data)
        return 0;
    int left = depth(root->left, node);
    if (left != -1)
        return left + 1;
    else
    {
        int right = depth(root->right, node);
        if (right != -1)
            return right + 1;
        else
            return -1;
    }
}

bool isSibling(BTN<int> *root, int p, int q)
{
    if (!root)
        return false;
    if (root->left && root->right)
    {
        if ((root->left->data == p && root->right->data == q) || (root->left->data == q && root->right->data == p))
            return true;
    }
    bool leftAns = false, rightAns = false;
    if (root->left)
        leftAns = isSibling(root->left, p, q);
    if (root->right)
        rightAns = isSibling(root->right, p, q);

    return leftAns || rightAns;
}

bool isCousin(BTN<int> *root, int p, int q)
{
    if (!root)
        return false;
    int pDepth = depth(root, p);
    int qDepth = depth(root, q);
    if (pDepth == qDepth && !isSibling(root, p, q))
        return true;
}

//   1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    BTN<int> *root = takeInput();
    print(root);
    int n1, n2;
    cin >> n1 >> n2;
    string ans = isCousin(root, n1, n2) ? "true" : "false";
    cout << ans;

    delete root;
}
