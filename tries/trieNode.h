#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++) children[i] = NULL;
        isTerminal = false;
    }
};

class Trie{
    TrieNode* root;

    public:
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode* root, string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL){
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(child, word.substr(1));
    }

    bool search(TrieNode *root,string word) {
        // Write your code here

        if(root->children[word[0]-'a']==NULL)
            return false;

        if(word.size()==1)
        {
            return root->children[word[0]-'a']->isTerminal;
        }

        return search(root->children[word[0]-'a'],word.substr(1)); 
    }
    bool search(string word)
    {  return search(root,word);}

    void removeWord(TrieNode* root, string word){
        if(word.size() == 0){
            root -> isTerminal = false;
            return;
        }

        TrieNode* child;
        int index = word[0] - 'a';
        if(root -> children[index] != NULL){
            child = root -> children[index];
        } else {
            return;
        }

        removeWord(child, word.substr(1));

        if(child -> isTerminal == false){
            for(int i=0; i<26; i++){
                if(child -> children[i] != NULL){
                    return;
                }
            }
            delete child;
            root -> children[index] = NULL;
        }
    }

    void insertWord(string word){
        insertWord(root, word);
    }

    void removeWord(string word){
        removeWord(root, word);
    }
};