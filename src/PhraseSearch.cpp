
#include "../include/PhraseSearch.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std ;

PhraseSearch::PhraseSearch(InvertedIndex* idx){
    index = idx;
}


bool PhraseSearch::matchPhrase(const vector<vector<Posting>>& postingLists,
                               int docID)
{
    vector<vector<int>> positions;

    // Collect the positions of every word in this document
    for (const auto& postingList : postingLists)
    {
        bool found = false;

        for (const Posting& posting : postingList)
        {
            if (posting.docID == docID)
            {
                positions.push_back(posting.positions);
                found = true;
                break;
            }
        }

        // One of the words is not present in this document
        if (!found)
            return false;
    }

    // Try every occurrence of the first word
    for (int firstPos : positions[0])
    {
        bool phraseFound = true;

        // Check the remaining words
        for (int i = 1; i < positions.size(); i++)
        {
            bool nextWordFound = false;

            for (int pos : positions[i])
            {
                if (pos == firstPos + i)
                {
                    nextWordFound = true;
                    break;
                }
            }

            if (!nextWordFound)
            {
                phraseFound = false;
                break;
            }
        }

        if (phraseFound)
            return true;
    }

    return false;
}



vector<int> PhraseSearch::searchPhrase(const string& phrase)
{
    string query = tokenizer.toLowerCase(phrase);
    query = tokenizer.removePunctuation(query);

    vector<string> words = tokenizer.tokenize(query);

    if (words.empty())
        return {};

    vector<vector<Posting>> postingLists;

    for (const string& word : words)
    {
        vector<Posting> postings = index->search(word);

        if (postings.empty())
            return {};

        postingLists.push_back(postings);
    }

    vector<int> result;

    for (const Posting& posting : postingLists[0])
    {
        if (matchPhrase(postingLists, posting.docID))
            result.push_back(posting.docID);
    }

    return result;
}