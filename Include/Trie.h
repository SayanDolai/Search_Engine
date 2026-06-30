// 1. Autocomplettion for the users 
// 2 . Prefix Search 
//3. check for existance of a word faster 
#ifndef TRIE_H 
#define TRIE_H 

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode {
public:
    char data ;
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode(char ch);
};

class Trie {
private:
    TrieNode* root;

    // Helper function for autocomplete
    void dfs(TrieNode* node,string currentWord,vector<string>& suggestions);

public:
    Trie();

    // Insert a word into the Trie
    void insert(const string& word);

    // Check if a complete word exists
    bool search(const string& word);

    // Check if a prefix exists
    bool startsWith(const string& prefix);

    // Return all words starting with a prefix
    vector<string> getSuggestions(const string& prefix);
};

#endif