#ifndef TOKENIZER_H 
#define TOKENIZER_H

#include <string>
#include <vector>
#include <unordered_set>

using namespace std ;

class Tokenizer {
private:
    unordered_set<string> stopWords;

public:
    Tokenizer();
    // Convert text to lowercase
    string toLowerCase(const string& text);
    // Remove punctuation
    string removePunctuation(const string& text);
    // Split text into words and remove stop words
    vector<string> tokenize(const string& text);
    // Check if a word is a stop word
    bool isStopWord(const std::string& word);
    // stemming the word to convrt to its root form 
    string stemWord(const string& word);
};

#endif 