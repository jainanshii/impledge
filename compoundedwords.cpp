// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool help(const string& word,const unordered_set<string>&s,unordered_map<string ,bool>&dp){
    if(dp.find(word)!=dp.end()) return dp[word];
    for(size_t i=1;i<word.size();i++){
        string p1=word.substr(0,i);
        string s1=word.substr(i);
        if(s.count(p1)>0 && (s.count(s1)>0||help(s1,s,dp))){
            return dp[word]=true;
        } 
    }
    return dp[word]=false;
}
void solve(string &inputFile1) {
    auto start = chrono::high_resolution_clock::now();
    ifstream inputFile(inputFile1);
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << inputFile1 << endl;
    }
    vector<string>v;
    unordered_set<string>s;
    unordered_map<string ,bool>dp;
    string word;
    while (inputFile >> word) {
        v.push_back(word);
        s.insert(word);
    }
    inputFile.close();
    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
    });
    string maxlengthword="",maxlengthword2="";
    for(const auto& word:v){
    s.erase(word);
    if(help(word,s,dp)){
        if(maxlengthword==""){
            maxlengthword=word; 
        }
        else if (maxlengthword2=="") {
            maxlengthword2=word; 
            break;
            }}
            s.insert(word);
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
    return 0;
}


