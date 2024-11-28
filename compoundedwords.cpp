#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        isTerminal = false;
        for(int i = 0; i < 26; i++)
        children[i] = NULL;
    }
};
class Trie{
    public:
    TrieNode*root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insert(string &word){
        TrieNode*node=root;
        for(char c:word){
            int j=c-'a';
            if(node->children[j]==NULL)
            node->children[j]= new TrieNode(c); 
            node=node->children[j];
        }
        node->isTerminal=true;
    }
    bool help(string word,int index,int count){
        TrieNode*node=root;
        for(int i = index;i<word.size();i++){
            char ch = word[i];
            int j = ch-'a';
            if(node->children[j]==NULL)
            return false;
            node = node->children[j];
            if(node->isTerminal){
                if(i == word.size()-1)
                return count>1;
                if(help(word,i+1,count+1))
                return true;
            }
        }
        return false;
    }
};
void solve(string &inputFile1) {
    auto start = chrono::high_resolution_clock::now();
    ifstream inputFile(inputFile1);
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << inputFile1 << endl;
    }
    vector<string>v;
    string word;
    Trie trie;
    while (inputFile >> word) {
        v.push_back(word);
        trie.insert(word);
    }
    inputFile.close();
    string maxlengthword="",maxlengthword2="";
    for(const auto& word:v){
        bool helpresult = trie.help(word,0,0);
        if(!helpresult) continue;
        int sizeofword = word.size();
        if(sizeofword>maxlengthword.size() && helpresult){
        maxlengthword2=maxlengthword;
        maxlengthword = word;
        }
        else if(sizeofword>maxlengthword2.size() && word!=maxlengthword2 && helpresult)
        maxlengthword2 = word;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

   cout<<"Longest Compound Word" << " " <<maxlengthword<<endl;
   cout<<"Second Longest Compound Word" << " " <<maxlengthword2<<endl;
   cout<<"Time taken to process file "<<inputFile1<<" " <<duration<<" milliseconds"; 
}

int main(){
    string inputFile1 = "Input_01.txt";
    string inputFile2 = "Input_02.txt";
    cout<<"Printing for "<<inputFile1<<endl;
    cout<<endl;
    solve(inputFile1);
    cout<<endl;
    cout<<"Printing for "<<inputFile2<<endl;
    cout<<endl;
    solve(inputFile2);
}
