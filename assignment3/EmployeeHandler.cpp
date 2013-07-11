
//  EmployeeHandler.cpp
//  CS201
//
//  Created by brad waier on 6/29/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#include "EmployeeHandler.h"
#include "Employee.h"
#include <iostream>
#include <string>


using namespace std;

string firstName;
string lastName;
float payRate;


EmployeeHandler::EmployeeHandler()
{
    m_employeeCount = 0;
}
void EmployeeHandler::DisplayEmployeeList()
{
    int eCount = GetEmployeeCount();
    if (eCount == 0)
    {
        cout << "No employees at this time. " << endl;
    }
    else
    {
        for (int i = 0; i < eCount; i++)
        {
            cout << "Employee " << i << endl;
            m_lstEmployee[i].Output();
        }
    }
}
int EmployeeHandler::EmployeeSelection()
{
    DisplayEmployeeList();
    cout << endl;
    cout << "Please enter the employee number whose information you would like to modify: \n\n";
    int index;
    cin >> index;
    return index;
}
void EmployeeHandler::AddEmployee()
{
    
    cout << "Adding Employees: " << endl;
    cout << "--------------------" << endl;
    cout << "How many employees would you like to add? ";
    int nums;
    cin >> nums;
    int count = 0;
    while (count < nums)
        
    {
        cout << "Employee: " << m_employeeCount << endl;
        cout << "Enter first name: ";
        cin >> firstName;
        cout << endl << "Enter last name: ";
        cin >> lastName;
        cout << endl << "Enter pay-rate: ";
        cin >> payRate;
        cout << endl;
        m_lstEmployee[m_employeeCount].Setup(firstName, lastName, payRate, true);
        m_employeeCount += 1;
        count += 1;
        
        
        
    }
    cout << nums << " employees added.";
    
    
}
void EmployeeHandler::EditEmployee()
{
    int index;
    index = EmployeeSelection();
    if (m_lstEmployee[index].GetIsActive())
    {
        string name = m_lstEmployee[index].GetName();
        cout << "Editing " << name << "'s pay information " << endl;
        cout << "--------------------------------" << endl;
        cout << endl << "Enter pay-rate: ";
        cin >> payRate;
        cout << endl;
        m_lstEmployee[index].Setup(payRate);
        cout << "Pay-rate changed.";
    }
    else
    {
        cout << "Not active employee";
    }
   
}


void EmployeeHandler::LayoffEmployee()
{
    int index;
    index = EmployeeSelection();
    cout << "Are you sure you want to lay off this employee? (yes/no) ";
    string answer;
    cin >> answer;
    if (answer == "yes")
    {
        
        m_lstEmployee[index].LayOff();
        
        string name = m_lstEmployee[index].GetName();
        cout << name << " is now inactive. Please remove " << name << " from the schedule." << endl;
        
        m_employeeCount -= m_employeeCount;
        
    }
    
}

Employee& EmployeeHandler::GetEmployee(int index)
{
    return m_lstEmployee[index];
}

int EmployeeHandler::GetEmployeeCount()
{
    return m_employeeCount;
}

