//  Employee.h
//  CS201
//
//  Created by brad waier on 6/29/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#ifndef CS201_Employee_h
#define CS201_Employee_h

#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    void Setup (const string& first, const string& last, float pay, bool isActive);
    void Setup (float pay); // overloaded function
    string GetName();
    bool GetIsActive();
    void LayOff();
    void Output();

    
private:
    string m_firstName;
    string m_lastName;
    float m_payPerHour;
    bool m_activeEmployee;
    
};


#endif
