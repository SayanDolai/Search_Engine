#include "InvertedIndex.h"
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set> 

using namespace std ;

void InvertedIndex::addWord(const string& word,int docID,int position, int line){
    vector<Posting>& postings = index[word];
    // Check whether this document already has a posting
    for (Posting& posting : postings){
        if (posting.docID == docID){
            posting.frequency++;
            posting.positions.push_back(position);
            posting.linenumber.push_back(line) ;
            return;
        }
    }
     // First occurrence in this document
    Posting newPosting;
    newPosting.docID = docID;
    newPosting.frequency = 1;
    newPosting.positions.push_back(position);
    newPosting.linenumber.push_back(line) ;
    postings.push_back(newPosting);
}

bool InvertedIndex::contains(const string& word){
    return InvertedIndex::index.contains(word) ;
}

vector<Posting> InvertedIndex::search(const string& word){
    // I have to return all the details stored at inverted index
    auto result = InvertedIndex::index.find(word) ;
    if(result == InvertedIndex::index.end()) return {} ;
    return result->second ;
}

void InvertedIndex::clear(){
    InvertedIndex::index.clear() ;
}

int InvertedIndex::size(){
    return InvertedIndex::index.size() ;
}

void InvertedIndex::printIndex(){
    return ;
}