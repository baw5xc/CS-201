
//  Phonebook.h
//  Assignment4
//
//  Created by brad waier on 7/13/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#ifndef Assignment4_Phonebook_h
#define Assignment4_Phonebook_h

#include "List.h"
#include "PhoneNumber.h"
#include <iostream>
#include <string>

using namespace std;

class Phonebook
{
public:
    void ReadFile(const string& filename);
    void OutputAllCountries();
    void OutputAllPhoneNumbers();
    void OutputPhonenumbersFilter(char letter);
    void OutputPhonenumbersFilter(const string& country);
    
    
private:
    List<PhoneNumber> m_listPhoneNumbers;
    List<string> m_listCountries;
    
};

#endif
