#include "DocumentReader.h"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std ;

DocumentReader::DocumentReader(){

}

bool DocumentReader::fileExists(const string& file){
    ifstream fin(file) ;
    return fin.is_open() ;
}

vector<string> DocumentReader::readDocument(const string& filename){
    ifstream fin(filename) ;
    vector<string> lines ;
    if(not DocumentReader::fileExists(filename)){
        std::cout<<"Error to open the file "<< endl ;
        return lines ;
    }
    string line ;
    while(getline(fin,line)){
        lines.push_back(line) ;
    }
    fin.close() ;
    return lines ;

}

vector<vector<string>> DocumentReader::readDocuments(const vector<string>& filenames){
    vector<vector<string> > result ;
    for(auto& file : filenames){
        vector<string> files = DocumentReader::readDocument(file) ;
        result.push_back(files) ;
    }
    return result ;
}