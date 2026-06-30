#ifndef INVERTEDINDEX_H 
#define INVERTEDINDEX_H 

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct Posting {
    int docID;
    int frequency;
    vector<int> positions;
    vector<int> linenumber ;
};

class InvertedIndex {
private:
    unordered_map<string, vector<Posting>> index;
public:
    void addWord(const string& word, int docID, int position,int line);

    vector<Posting> search(const string& word);

    bool contains(const string& word);

    void printIndex();

    void clear();

    int size();
};

#endif 