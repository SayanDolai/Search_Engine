#include "../include/SearchEngine.h"
#include<iostream>
#include<vector>
#include<string>


using namespace std;

SearchEngine::SearchEngine() : phrase(&index){
    ranking = nullptr ;
}

void SearchEngine::addDocument(const string& filename){
    // it only ordered the Document Reader to read
    if(not reader.fileExists(filename)){
        cout << "Cannot find file from search engine: " << filename << endl;
        return;
    }
    //else store the path of the file in to the documents
    documents.push_back(filename) ;
    cout<<"Succefully added from addDocument"<<endl ;
}

void SearchEngine::buildIndex(){ // build the index tree and trie
    for(int docId = 0; docId<documents.size(); docId++){
        vector<string> lines = reader.readDocument(documents[docId]) ;
        int position = 0 ;
        int lineNo = 0 ;
        for(string& line : lines){
            string l = line ;
            l = tokenizer.removePunctuation(l) ;
            l = tokenizer.toLowerCase(l) ;
            vector<string> words = tokenizer.tokenize(l) ;
            for(string word : words){
                SearchEngine::documentLength[docId+1] ++ ;
                trie.insert(word) ;
                index.addWord(word,docId+1,position,lineNo) ;
                position ++ ;
            }
            lineNo++ ;
        }
    }
    if (ranking != nullptr)
    delete ranking;

    ranking = new Ranking(
    &index,
    &documentLength,
    documents.size()
);
    cout<<"Index built successfully from builindes search engine"<<endl ;
}

void SearchEngine::searchQuery(const string& query)
{
    // Preprocess the query
    string word = tokenizer.toLowerCase(query);
    word = tokenizer.removePunctuation(word);
    word = tokenizer.stemWord(word);

    // Check whether the word exists
    if (!trie.search(word)){
        cout << "\nWord not found.\n";
        return;
    }

    // Search the inverted index
    vector<Posting> result = index.search(word);

    cout << "\nSearch Results\n";
    cout << "-------------------------\n";

    for (const Posting& posting : result)
{
    cout << "Document : "
         << documents[posting.docID - 1]
         << endl;

    cout << "Frequency : "
         << posting.frequency
         << endl;

    for (int i = 0; i < posting.positions.size(); i++)
    {
        cout << "Position : "
             << posting.positions[i]
             << endl;

        cout << "Line No : "
             << posting.linenumber[i] + 1   // +1 if you want line numbers starting from 1
             << endl;
    }

    cout << endl;
}
}

vector<string> SearchEngine::autoComplete(const string& prefix){
    string word = prefix ;
    word = tokenizer.toLowerCase(prefix);
    word = tokenizer.removePunctuation(word);
    word = tokenizer.stemWord(word); 
    return trie.getSuggestions(word) ;
}


void SearchEngine::phraseQuery(const string& p){
    vector<int> docs = phrase.searchPhrase(p);
    if (docs.empty()){
        cout << "Phrase not found.\n";
        return;
    }
    cout << "\nPhrase Found In:\n\n";
    for (int docID : docs){
        cout << documents[docID - 1] << endl;
    }
}


void SearchEngine::rankedSearch(const string& word){
    vector<pair<int,double>> result =
        ranking->rankDocuments(word);

    if(result.empty()){
        cout << "Word not found.\n";
        return;
    }

    cout << "\nRanked Results\n";
    cout << "-------------------------\n";

    for(const auto& x : result){
        cout << "Document : "
             << documents[x.first - 1]
             << endl;

        cout << "TF-IDF Score : "
             << x.second
             << endl << endl;
    }
}