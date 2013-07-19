//  PhoneNumber.cpp
//  Assignment4
//
//  Created by brad waier on 7/13/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#include "PhoneNumber.h"
#include "List.h"
#include "Phonebook.h"


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

PhoneNumber::PhoneNumber()
{
    m_firstName = "F_Name";
    m_lastName = "L_Name";
    m_phoneNumber = "***-***-****";
    m_country = "Country";
}
PhoneNumber::PhoneNumber(const string& first, const string& last, const string& phone, const string& country)
{
    Setup(first, last, phone, country);
    
}
void PhoneNumber::Setup(const string& first, const string& last, const string& phone, const string& country)
{
    m_firstName = first;
    m_lastName = last;
    m_phoneNumber = phone;
    m_country = country;
}

bool operator== (const PhoneNumber& item1, const PhoneNumber& item2)
{
    int trueCount = 0;
    if (item1.m_firstName == item2.m_firstName)
    {
        trueCount += 1;
    }
    if (item1.m_lastName == item2.m_lastName)
    {
        trueCount += 1;
    }
    if (item1.m_phoneNumber == item2.m_phoneNumber)
    {
        trueCount += 1;
    }
    if (item1.m_country == item2.m_country)
    {
        trueCount += 1;
    }
    if (trueCount == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

ostream& operator<< (ostream& out, const PhoneNumber& item)
{
    out << item.m_lastName << endl;
    out << item.m_firstName << endl;
    out << item.m_country << endl;
    out << item.m_phoneNumber << endl;
    return out;
}

//----------------

