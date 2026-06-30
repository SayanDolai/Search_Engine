#ifndef DOCUMENTREADER_H
#define DOCUMENTREADER_H
#include<iostream>
#include<string>
#include<vector>

using namespace std ;

class DocumentReader {
public:
    DocumentReader();

    // Read an entire document line by line
    vector<string> readDocument(const string& filename);

    // Read multiple documents
    vector<vector<string>> readDocuments(const vector<string>& filenames);

    // Check if a file exists
    bool fileExists(const string& filename);
};
#endif