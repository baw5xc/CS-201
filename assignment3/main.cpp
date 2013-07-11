//  main.cpp
//  CS201
//
//  Created by brad waier on 6/29/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#include <iostream>
#include <string>
#include "Employee.h"
#include "EmployeeHandler.h"
#include "Schedule.h"
#include "ScheduleHandler.h"
#include <iomanip>

using namespace std;

enum MenuOptions {QUIT, ADD_EMPLOYEE, EDIT_EMPLOYEE, LAYOFF_EMPLOYEE, VIEW_EMPLOYEE_LIST, UPDATE_SCHEDULE, CANCEL_SCHEDULE, VIEW_SCHEDULE, EXPORT_SCHEDULE_CSV, EXPORT_SCHEDULE_HTML };
//----------------------------------------------------------------------------------------------------
void DisplayMainMenu()
{
cout << endl << endl;
cout <<  setw(40) << "BUSINESS MANAGEMENT system!" << endl;
cout << "------------------------------------------------------\n" << endl;
cout << "EMPLOYEE OPTIONS:" << setw(30) << "SCHEDULING OPTIONS: " << endl;
cout << endl;
cout << ADD_EMPLOYEE << ". Add Employee" << setw(12) << UPDATE_SCHEDULE << ". Update Schedule" << endl;
cout << EDIT_EMPLOYEE << ". Edit Employee" << setw(11) << CANCEL_SCHEDULE << ". Cancel Schedule" << endl;
cout << LAYOFF_EMPLOYEE << ". Layoff Employee" << setw(9) << VIEW_SCHEDULE << ". View Schedule" << endl;
cout << VIEW_EMPLOYEE_LIST << ". View Employee List" << setw(6) << EXPORT_SCHEDULE_CSV << ". Export Schedule to CSV" << endl;
    
cout << setw(27) << EXPORT_SCHEDULE_HTML << ". Export Schedule to HTML" << endl;
    cout << endl;
    cout << QUIT << ". Quit\n" << endl;
    
    cout << "User input: ";
}
//----------------------------------------------MAIN---------------------------------------------------

int main(int argc, const char * argv[])
{
    
    bool done = false;
    
    ScheduleHandler scheduleHandler;
    EmployeeHandler employeeHandler;
    while (done == false)
    {
        DisplayMainMenu();
        int choice;
        cin >> choice;
        switch (choice)
        {
            case QUIT:
                done = true;
            break;
                
            case ADD_EMPLOYEE:
                employeeHandler.AddEmployee();
            break;
                
            case EDIT_EMPLOYEE:
                employeeHandler.EditEmployee();
            break;
            
            case LAYOFF_EMPLOYEE:
                employeeHandler.LayoffEmployee();
            break;
                
            case VIEW_EMPLOYEE_LIST:
                employeeHandler.DisplayEmployeeList();
            break;
            
            case UPDATE_SCHEDULE:
                scheduleHandler.AddSchedule(employeeHandler);
            break;
                
            case CANCEL_SCHEDULE:
                scheduleHandler.CancelSchedule();
            break;
                
            case VIEW_SCHEDULE:
                scheduleHandler.DisplaySchedule();
            break;
                
            case EXPORT_SCHEDULE_CSV:
                scheduleHandler.ExportScheduleCSV();
            break;
                
            case EXPORT_SCHEDULE_HTML:
                scheduleHandler.ExportScheduleHTML();
        }
        
    }
    
    
    cout << "Logging off BUSINESS MANAGEMENT system" << endl;
    cout << "Goodbye";
    return 0;
}

