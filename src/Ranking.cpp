#include "../include/Ranking.h"

#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>

using namespace std ;

Ranking:: Ranking(InvertedIndex* idx, unordered_map<int, int>* docLength,int totalDocs){
    index = idx ;
    documentLength = docLength ;
    totalDocuments = totalDocs ;
}

double Ranking::calculateTF(const Posting& posting){
    // TF = (required word) /(total words)
    int freq = posting.frequency ;
    int total = (*documentLength)[posting.docID];
    if(total == 0) return 0.0 ;
    return (double)freq / total ;
}

double Ranking::calculateIDF(const string& word){
    vector<Posting> result = (*index).search(word);
    if(result.empty()) return 0.0 ;
    return log((double)(totalDocuments + 1) / (result.size() + 1)) + 1.0;
}

vector<pair<int, double>> Ranking::rankDocuments(const string& word){
    vector<pair<int, double>> result;

    // Get posting list of the word
    vector<Posting> postings = index->search(word);

    // Word not found
    if (postings.empty())
        return result;

    // Calculate IDF once
    double idf = calculateIDF(word);

    // Calculate TF-IDF score for every document
    for (const Posting& posting : postings){
        double tf = calculateTF(posting);
        double score = tf * idf;
        result.push_back({posting.docID, score});
    }

    // Sort by score in descending order
    sort(result.begin(), result.end(),[](const pair<int, double>& a,const pair<int, double>& b){
            return a.second > b.second;
        });

    return result;
}