#include <iostream>
using namespace std;

//------------------------------------------------------------------------------------------

class Node{
public:
    Node *links[26];
    bool flag = false;
};

class Trie{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    //-------------------------Insert a word in Trie-------------------------------------
    //-----------------------T.C - O(length of word)-------------------------------------

    void insert(string word)
    {
        int n = word.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            char ch = word[i];

            // if the character is not present in the node
            if (node->links[ch - 'a'] == NULL)
            {
                node->links[ch - 'a'] = new Node();
            }

            // move to the new or existing reference node
            node = node->links[ch - 'a'];
        }

        node->flag = true;
    }

    //----------------------Search a word in Trie-------------------------------------------
    //-----------------------T.C - O(length of word)----------------------------------------

    bool search(string word)
    {
        int n = word.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            char ch = word[i];

            if (node->links[ch - 'a'] == NULL)
                return false;

            node = node->links[ch - 'a'];
        }

        return (node->flag);
    }

    //--------------------Search a word in trie that starts with "prefix"------------------------------
    //-----------------------T.C - O(length of prefix)-------------------------------------------------

    bool startsWith(string prefix)
    {
        int n = prefix.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            char ch = prefix[i];

            if (node->links[ch - 'a'] == NULL)
                return false;

            node = node->links[ch - 'a'];
        }

        return true;
    }

    //-----------------------------------------------------------------
};

//---------------------------------------------------------------------------------------