//  main.cpp
//  Assignment4
//
//  Created by brad waier on 7/13/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#include "List.h"
#include "PhoneNumber.h"
#include "Phonebook.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


enum MenuOptions {QUIT, VIEW_ALL_ENTRIES, FILTER_BY_COUNTRY, FILTER_BY_LETTER};

int main(int argc, const char * argv[])
{
    Phonebook phonebook;
    phonebook.ReadFile("numbers.txt");
    
    bool done = false;
    
    while (done == false)
    {
        cout << " International Directory (Ninjas): " << endl;
        cout << "----------------------------------" << endl;
        cout << VIEW_ALL_ENTRIES << ". View all entries. " << endl;
        cout << FILTER_BY_COUNTRY << ". Filter by country. " << endl;
        cout << FILTER_BY_LETTER << ". Filter by letter. " << endl << endl;
        cout << QUIT << ". Quit. " << endl << endl;
        cout << "Input: ";
        
        int choice;
        cin >> choice;
        if (choice == VIEW_ALL_ENTRIES)
        {
            phonebook.OutputAllPhoneNumbers();
        }
        if (choice == FILTER_BY_COUNTRY)
        {

            phonebook.OutputAllCountries();
            cout << endl;
            string country;
            cout << "Enter the name of the country. ";
            cin >> country;
            string buffer;
            for (int i = 1; i < country.length(); i++)
            {
                buffer += tolower(country[i]);
            }
            country = toupper(country[0]);
            country += buffer;
            cout << "RESULTS: " << endl;
            cout << "-------" << endl;
            phonebook.OutputPhonenumbersFilter(country);
            cout << endl;
            
        }
        if (choice == FILTER_BY_LETTER)
        {
            char letter;
            cout << "Enter a letter. ";
            cin >> letter;
            letter = toupper(letter);
            cout << "Searching by the letter: " << letter << endl;
            cout << "RESULTS: " << endl;
            cout << "-------" << endl;
            phonebook.OutputPhonenumbersFilter(letter);
        }
        if (choice == QUIT)
        {
            done = true;
        }
        
        
    }
    cout << "Goodbye" << endl << endl;
    system("PAUSE");
    return 0;
}
