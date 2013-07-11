//  Schedule.h
//  CS201
//
//  Created by brad waier on 6/29/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#ifndef CS201_Schedule_h
#define CS201_Schedule_h

#include <iostream>
#include <string>
#include "Employee.h"


class Schedule
{
public:
    void Setup (int hour);
    void AssignEmployee(Employee *employee);
    string GetEmployeeName();
    void Output();
    void Reset();
    bool GetIsSet();
    
private:
    Employee * m_ptrEmployee;
    int m_beginHour;
};

#endif

