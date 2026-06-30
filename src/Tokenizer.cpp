// it break down the whole line into small words

#include "Tokenizer.h"
#include <iostream>
#include <vector>
#include <string>
#include<unordered_set>
#include<sstream>
#include<fstream>

using namespace std;

Tokenizer::Tokenizer(){
    stopWords = {"a", "an", "the", "is", "are", "was", "were", "in", "on", "at", "of", "to", "and", "or", "for", "with", "by"};
}

bool Tokenizer::isStopWord(const string& word){
    return stopWords.count(word) > 0;
}
string Tokenizer::toLowerCase(const string &text){
    string result = text;
    for (char &x : result) x = tolower(x);
    return result ;
}

string Tokenizer::removePunctuation(const string& text){
    // just to take alphanumeric and one space 
    string result = "" ;
    for(auto& x: text) if(isalnum(x) or x ==' ') result += x ;
    return result ;
}


string Tokenizer::stemWord(const string& word) {
    string stem = word;

    if (stem.size() > 4 && stem.substr(stem.size() - 3) == "ing")
        stem.erase(stem.size() - 3);

    else if (stem.size() > 3 && (stem.substr(stem.size() - 2) == "ed" or stem.substr(stem.size() - 2) == "es") )
        stem.erase(stem.size() - 2);

    else if (stem.size() > 2 && stem.back() == 's')
        stem.pop_back();

    return stem;
}

vector<string> Tokenizer::tokenize(const string& text){
    // this functions check for stop word 
    // and also split the text into words 
    stringstream ss(text) ;
    vector<string> result ;
    string word ;
    while(ss>>word){
        if(isStopWord(word)) continue ;
        word = stemWord(word) ;
        result.push_back(word) ;
    }
    return result ;
}
