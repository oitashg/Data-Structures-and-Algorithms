#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

vector<string> split_sentence(string& s){
    //Create a stringstream object
    stringstream ss(s);

    //variable to hold each word of sentence
    string word;

    //vector of strings to hold each word of the sentence s
    vector<string> v;

    //extract words using getline with space as delimiter
    while(getline(ss, word, ' ')) v.push_back(word);

    //--------------------or-----------------------------

    // Extract words from the sentence
    while (ss >> word) {
        
        // Add the word to the vector
        v.push_back(word);
    }

    return v;
}

int main(){
    string s = "My name is Oitash Ghosh";
    vector<string> words;

    words = split_sentence(s);

    cout<<"The words are -> "<<endl;

    for(auto word: words) cout<<word<<", ";
    return 0;
}