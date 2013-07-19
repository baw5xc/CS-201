//  Phonebook.cpp
//  Assignment4
//
//  Created by brad waier on 7/13/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#include "Phonebook.h"
#include "PhoneNumber.h"



#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void Phonebook::ReadFile(const string& filename)
{
    ifstream inFile;
    inFile.open(filename);
    string first, last, phone, country;
    while (inFile >> first >> last >> phone >> country)
    {
        PhoneNumber tempPhone (first, last, phone, country);
        m_listPhoneNumbers.AddItem( tempPhone );
        m_listCountries.AddItem( country );
    }
    inFile.close();
}

void Phonebook::OutputAllCountries()
{
    m_listCountries.OutputAll();
}

void Phonebook::OutputAllPhoneNumbers()
{
    m_listPhoneNumbers.OutputAll();
}

void Phonebook::OutputPhonenumbersFilter(const string& country)  //overloaded function
{
    
    for (int i = 0; i < m_listPhoneNumbers.GetSize(); i++)
    {
        int count = 0;
        PhoneNumber item = m_listPhoneNumbers.GetItem(i);
        if (item.m_country == country)
        {
            cout << item << endl; // using overloaded '<<' operator
            count += 1;
            
        }
    }
    
}

void Phonebook::OutputPhonenumbersFilter(char letter)
{
    int count = 0;
    for (int i = 0; i < m_listPhoneNumbers.GetSize(); i++)
    {
        
        PhoneNumber item = m_listPhoneNumbers.GetItem(i);
        if (item.m_lastName[0] == letter)
        {
            cout << item << endl; // using overloaded '<<' operator
            count += 1;
        }
        if (i == (m_listPhoneNumbers.GetSize()-1) && count == 0)
        {
            cout << "NONE" << endl << endl;
        }
    }
    
}

