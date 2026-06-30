#include "Trie.h" 
#include<iostream>
#include<vector>
#include<string>

using namespace std ;
TrieNode::TrieNode(char ch){
    this->data = ch ;
    this->isEndOfWord = false ;
}
Trie::Trie(){
    Trie::root = new TrieNode('\0') ;
}
void Trie::insert(const string& word){
    TrieNode* curr = Trie::root ;
    for(char ch : word){

        // if not exist and if exist then skip it 
        if(not curr->children.contains(ch)){
            curr->children[ch] = new TrieNode(ch) ;
        }
        // go to the children 
        curr = curr->children[ch] ;
    }
    // after the loop done last letter contains is endofword  = true
    curr->isEndOfWord = true ;
}

bool Trie::search(const string& word){
    TrieNode* curr = Trie::root ;
    for(char ch : word){
        if(not curr->children.contains(ch)) return false ;
        curr = curr->children[ch] ;
    }
    //check the exact word exist or not
    return curr->isEndOfWord ;
}

bool Trie::startsWith(const string& prefix){
    TrieNode* curr = Trie::root ;
    for(char ch : prefix){
        if(not curr->children.contains(ch)) return false ;
        curr = curr->children[ch] ;
    }
    return true ;
}

void Trie::dfs(TrieNode* node,string currentWord,vector<string>& suggestions){
    if(node->isEndOfWord){
        suggestions.push_back(currentWord) ;
    }
    for(auto& child : node->children){
        dfs(child.second,currentWord+child.first,suggestions) ;
    }
}

vector<string> Trie::getSuggestions(const string& prefix){
    if(not startsWith(prefix)) return {} ;
    vector<string> result ;
     TrieNode* curr = Trie::root ;
    string word = "" ;
    for(char ch : prefix){
        curr = curr->children[ch] ;
        word += ch ;
    }
    Trie::dfs(curr,word,result) ;
    return result ;
}