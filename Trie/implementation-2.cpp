#include <iostream>
using namespace std;

//--------------------------------------------------------------------------------------

class Node{
public:
    Node *links[26];
    int ct = 0, cp = 0;
};

class Trie{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    //-------------------------Insert a word in Trie-------------------------------------

    void insert(string &word)
    {
        int n = word.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            char ch = word[i];

            if (node->links[ch - 'a'] == NULL)
                node->links[ch - 'a'] = new Node();

            node = node->links[ch - 'a'];
            (node->cp)++;
        }

        (node->ct)++;
    }

    //------------------------Count words equal to "word" in Trie-------------------------------

    int countWordsEqualTo(string &word)
    {
        int n = word.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            char ch = word[i];

            if (node->links[ch - 'a'] == NULL)
                return 0;

            node = node->links[ch - 'a'];
        }

        return (node->ct);
    }

    //-------------------------Count words start with "word" in Trie-------------------------------------

    int countWordsStartingWith(string &word)
    {
        int n = word.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            char ch = word[i];

            if (node->links[ch - 'a'] == NULL)
                return 0;

            node = node->links[ch - 'a'];
        }

        return (node->cp);
    }

    //-------------------------Erase a word in Trie-------------------------------------

    void erase(string &word)
    {
        int n = word.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            char ch = word[i];

            node = node->links[ch - 'a'];
            (node->cp)--;
        }

        (node->ct)--;
    }

    //------------------------------------------------------------------------------------------
};
