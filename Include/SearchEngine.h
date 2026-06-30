#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H
#include "DocumentReader.h"
#include "Tokenizer.h"
#include "Trie.h"
#include "InvertedIndex.h"
#include "PhraseSearch.h"
#include "Ranking.h"

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class SearchEngine{
private:
    // Core Components
    DocumentReader reader;
    Tokenizer tokenizer;
    Trie trie;
    InvertedIndex index;
    PhraseSearch phrase ;
    Ranking* ranking ;
    
    // Stores all document names
    vector<string> documents;

    // stores the number of words present in each doc
    unordered_map<int,int> documentLength ;

public:
    // Constructor
    SearchEngine();

    // Add a document to the search engine
    void addDocument(const string& filename);

    // Build the Trie and Inverted Index
    void buildIndex();

    // Search a word
    void searchQuery(const string& word);

    // Autocomplete suggestions
    vector<string> autoComplete(const string& prefix);
    void phraseQuery(const string& phrase);
    void rankedSearch(const string& word);

    // Print the whole inverted index (for debugging)
    // void printIndex();

    // Print all loaded documents
    // void printDocuments();
};

#endif 