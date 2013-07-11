//  EmployeeHandler.h
//  CS201
//
//  Created by brad waier on 6/29/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#ifndef CS201_EmployeeHandler_h
#define CS201_EmployeeHandler_h

#include <iostream>
#include <string>
#include "Employee.h"

class EmployeeHandler
{
public:
    EmployeeHandler();
    void AddEmployee();
    void EditEmployee();
    void LayoffEmployee();
    void DisplayEmployeeList();
    int EmployeeSelection();
    Employee& GetEmployee(int index);
    int GetEmployeeCount();
    
private:
    Employee m_lstEmployee[50];
    int m_employeeCount;
};

#endif



