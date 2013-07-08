//  Schedule.cpp
//  CS201
//
//  Created by brad waier on 6/30/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#include "Schedule.h"
#include "Employee.h"
#include "EmployeeHandler.h"
#include "ScheduleHandler.h"
#include <iostream>
#include <string>

using namespace std;

void Schedule::Setup(int hour)
{
    m_beginHour = hour;
    m_ptrEmployee = nullptr;
}

void Schedule::AssignEmployee(Employee * employee)
{
    m_ptrEmployee = employee;
}

void Schedule::Reset()
{
   m_ptrEmployee = nullptr;
}

bool Schedule::GetIsSet()
{
    bool isSet;
    if (m_ptrEmployee == nullptr)
    {
        isSet = false;
        return isSet;
    }
    else
    {
        isSet = true;
        return isSet;
    }
}

void Schedule::Output()
{
    cout << GetEmployeeName() << endl;
}
string Schedule::GetEmployeeName()
{
    string tempName;
    if (GetIsSet() == true)
    {
        tempName = m_ptrEmployee->GetName();
        return tempName;
    }
    else
    {
        return "UNALLOCATED";
    }
}
