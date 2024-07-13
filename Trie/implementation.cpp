#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26]; //26 alphabets so 26 children can be there for each node
        bool isTerminal; //checks if last alphabet of the word is terminal node or not in the trie 

        //constructor
        TrieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;

        //constructor
        Trie(){
            root = new TrieNode('\0'); //root started with null character
        }

        //recursive functions
        void insertUtil(TrieNode* root, string word){
            //base case
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }

            //assumption, word will be in CAPS
            int index = word[0] - 'A';
            TrieNode* child;

            //checks if alphabet is present or not in the trie
            if(root->children[index] != NULL){
                //alphabet present in the trie, so go ahead
                child = root->children[index];
            }
            else{
                //alphabet absent, so create a new node and go ahead
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            //recursion
            insertUtil(child, word.substr(1));
        }

        bool searchUtil(TrieNode* root, string word){
            //base case
            if(word.length() == 0){
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            //check if word presenr or not
            if(root->children[index] != NULL){
                //present,so go on
                child = root->children[index];
            }
            else{
                //absent
                return false;
            }

            //recursion
            return searchUtil(child, word.substr(1));
        }

        bool startsWithUtil(TrieNode* root, string prefix){
            //base case
            if(prefix.length() == 0){
                return true;
            }

            int index = prefix[0] - 'A';
            TrieNode* child;

            //present
            if(root->children[index] != NULL){
                child = root->children[index];
            }
            else{
                return false;
            }

            //recursion
            return startsWithUtil(child, prefix.substr(1));
        }
        
        void removeUtil(TrieNode* root, string word){
            //base case
            if(word.length() == 0){
                //if word found then make the isTerminal of last character false so that word gets removed from trie
                if(root->isTerminal){
                    root->isTerminal = false;
                    return;
                }
                else
                    //isTerminal already false..i.e..that word doesn't exist in trie
                    return;
            }

            //assumption, word will be in CAPS
            int index = word[0] - 'A';
            TrieNode* child;

            //checks if alphabet is present or not in the trie
            if(root->children[index] != NULL){
                //alphabet present in the trie, so go ahead
                child = root->children[index];
            }
            else
                //word doesn't exist in trie
                return;

            //recursion
            removeUtil(child, word.substr(1));
        }

        //insert word function
        void insertWord(string word){
            insertUtil(root, word);
        }

        //search word fucntion
        bool searchWord(string word){
            return searchUtil(root, word);
        }

        //starts with function
        bool startsWith(string prefix) {
            return startsWithUtil(root, prefix);
        }

        //remove word function
        void removeWord(string word){
            removeUtil(root, word);
        }
};

int main(){
    Trie *t = new Trie();

    t->insertWord("ABCD");
    t->insertWord("EFGH");
    t->insertWord("IJKL");
    cout<<"Present or not "<< t->searchWord("ABCD")<<endl;
    cout<<"Present or not "<< t->searchWord("EFGH")<<endl;
    cout<<"Present or not "<< t->startsWith("AT")<<endl;
    t->removeWord("ABCD");
    t->removeWord("EFGH");
    cout<<"Present or not "<< t->searchWord("ABCD")<<endl;
    cout<<"Present or not "<< t->searchWord("EFGH")<<endl;
    
    return 0;
}