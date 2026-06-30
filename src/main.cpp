#include "../include/SearchEngine.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    SearchEngine search;

    // Add documents
    search.addDocument("data/doc1.txt");
    search.addDocument("data/doc2.txt");
    search.addDocument("data/doc3.txt");
    search.addDocument("data/doc4.txt");

    // Build Trie + Inverted Index
    search.buildIndex();

    cout << "\n=====================================\n";
    cout << "      SEARCH ENGINE IS READY\n";
    cout << "=====================================\n";

    while (true){
        cout << "1. Search Word\n";
        cout << "2. Auto Complete\n";
        cout << "3. Phrase Search\n";
        cout << "4. TF-IDF Ranking\n";
        cout << "5. Exit\n";

        cout << "\nEnter Choice : ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            string word;

            cout << "Enter Word : ";
            getline(cin, word);

            search.searchQuery(word);
        }
        else if (choice == 2)
        {
            string prefix;

            cout << "Enter Prefix : ";
            getline(cin, prefix);

            vector<string> suggestions =
                search.autoComplete(prefix);

            cout << "\nSuggestions\n";
            cout << "----------------------\n";

            if (suggestions.empty())
            {
                cout << "No Suggestions Found\n";
            }
            else
            {
                for (const string& word : suggestions)
                    cout << word << endl;
            }
        }
       else if(choice == 3){
            string phrase;
            cout << "Enter Phrase : ";
            getline(cin, phrase);
            search.phraseQuery(phrase);
        }
        else if(choice == 4){
            string word;
            cout << "Enter Word : ";
            getline(cin, word);
            search.rankedSearch(word);
        }
        else if (choice == 5)
        {
            cout << "\nThank You!\n";
            break;
        }
        else
        {
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}