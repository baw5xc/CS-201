//  Employee.cpp
//  CS201
//
//  Created by brad waier on 6/29/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#include "Employee.h"
#include "Schedule.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void Employee::Setup(const string& first, const string& last, float pay, bool isActive)
{
    m_firstName = first;
    m_lastName = last;
    m_payPerHour = pay;
    m_activeEmployee = isActive;
}
void Employee::Setup(float pay)
{
    m_payPerHour = pay;
}

string Employee::GetName()
{
    return m_firstName + " " + m_lastName;
}

void Employee::LayOff()
{
    m_activeEmployee = false;
}
bool Employee::GetIsActive()
{
    return m_activeEmployee;
}
void Employee::Output()
{
    using std::cout;
    cout.precision(4);
    cout.setf(ios_base::showpoint); // used to display trailing zeros
    string status;
    if (m_activeEmployee == 1)
    {
        status = "Active";
    }
    else
    {
        status = "Inactive";
    }
    cout << "---------------------------" << endl;
    cout << "Name: " << m_lastName << ", " << m_firstName << endl;
    cout << "Hourly Wage: $ " << m_payPerHour << endl;
    cout << "Employment Status: " << status << endl;
    cout << "---------------------------" << endl;
}


