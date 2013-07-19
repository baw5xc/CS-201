//  Created by brad waier on 7/13/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#ifndef Assignment4_PhoneNumber_h
#define Assignment4_PhoneNumber_h

#include <iostream>
#include <string>



using namespace std;

class PhoneNumber
{
    
public:
    PhoneNumber();
    PhoneNumber(const string& first, const string& last, const string& phone, const string& country);
    void Setup(const string& first, const string& last, const string& phone, const string& country);
    friend bool operator== (const PhoneNumber& item1, const PhoneNumber& item2);
    friend ostream& operator<< (ostream& out, const PhoneNumber& item);
    friend class Phonebook;
    
private:
    string m_firstName;
    string m_lastName;
    string m_phoneNumber;
    string m_country;
    
};



#endif
