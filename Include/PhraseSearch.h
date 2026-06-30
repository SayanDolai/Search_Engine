#ifndef PHRASESEARCH_H
#define PHRASESEARCH_H

#include "InvertedIndex.h"
#include "Tokenizer.h"
#include<iostream>
#include <vector>
#include <string>

using namespace std;

class PhraseSearch{
private:
    InvertedIndex* index;
    Tokenizer tokenizer;
    bool matchPhrase(const vector<vector<Posting>>& postings,int docID);
public:
    // Constructor
    PhraseSearch(InvertedIndex* idx);
    // Search an exact phrase
    vector<int> searchPhrase(const string& phrase);
};

#endif 