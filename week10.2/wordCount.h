/***********************************************************************
* Header:
*    WORD COUNT
* Summary:
*    This will contain just the prototype for the wordCount()
*    function
* Author
*    <your names here>
************************************************************************/

#ifndef WORD_COUNT_H
#define WORD_COUNT_H
#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

#include "map.h"       // for MAP

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using std::ifstream;

using namespace custom;



/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount()
{
  
    string userInput;
    int numberOfWords = 0;
    
    cout << "What is the filename to be counted? ";
    cin >> userInput;
    
    ifstream fin;
    fin.open(userInput.c_str());
    
    if (fin.fail()) {
        cout << "Error: Unable to open file" << endl;
        return;
    }

    
    map<string, int> myMap;
    string word;
    
    while (fin >> word) {
        
        
        string noPunWord = "";
        
        for (int i = 0; i < word.length(); i++) {
            if (!ispunct(word[i]) || word[i] == '-')
                noPunWord += word[i];
        }
        
        transform(noPunWord.begin(), noPunWord.end(), noPunWord.begin(), ::tolower);
        
        myMap[noPunWord]++;
        numberOfWords++;
    }

    
    fin.close();
    
     cout << "What word whose frequency is to be found. Type ! when done\n";
     cin.ignore();
     cin >> userInput;
    string flag = "!";
    
    while(userInput != flag)
    {
       map<string,int>::iterator it = myMap.find(userInput);
       map<string,int>::iterator itty = myMap.end();
       if(it != itty)
       cout  << "\t" <<it.it.getNode()->data.getFirst() << " : " <<  it.it.getNode()->data.getSecond() << endl;
       else
       cout << "\t" << userInput << " :  0\n"; 
       cin >> userInput;
    }

    cout << "this is a  list of words only used once in the book of mormon" << endl;
    

    std::vector<string> vEctor;
    for(map<string,int>::iterator newit = myMap.begin(); newit != myMap.end(); ++newit)
    {
       if(newit.it.getNode()->data.getSecond() == 1) 
       vEctor.push_back(newit.it.getNode()->data.getFirst());  
    }
    
    for(int i = 0; i < vEctor.size() ; i++)
    {
      cout << vEctor[i] << endl;
    }

   
}


#endif // WORD_COUNT_H

