#ifndef RANKING_H
#define RANKING_H
#include<iostream>
#include "InvertedIndex.h"

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Ranking{
private:
    // Existing inverted index
    InvertedIndex* index;
    // Number of words in every document
    unordered_map<int, int>* documentLength;
    // Total number of indexed documents
    int totalDocuments;
    // Helper functions
    double calculateTF(const Posting& posting);

    double calculateIDF(const string& word);

public:
    // Constructor
    Ranking(InvertedIndex* idx, unordered_map<int, int>* docLength,int totalDocs);

    // Return documents sorted by TF-IDF score
    vector<pair<int, double>> rankDocuments(const string& word);
};
#endif