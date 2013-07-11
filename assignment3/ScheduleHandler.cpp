//  ScheduleHandler.cpp
//  CS201
//
//  Created by brad waier on 6/30/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#include "ScheduleHandler.h"
#include "Schedule.h"
#include "Employee.h"
#include "EmployeeHandler.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;



ScheduleHandler::ScheduleHandler()
{
    
    for (int i = 0; i < 24; i++)
    {   
        m_lstSchedule[i].Setup(i);
        
    }
}

void ScheduleHandler::DisplaySchedule()
{
    cout << "     Employee Schedule: " << endl;
    cout << "    -------------------" << endl;
    for (int k = 0; k < 24; k++)
    {
        if (k < 10)
        {
            cout << setw(2) << "[" << k << "]" << ":  " << k << ":00 -- ";
            m_lstSchedule[k].Output();
        }
        else
        {
            cout << "[" << k << "]" << ": " << k << ":00 -- ";
            m_lstSchedule[k].Output();
        }

    }
}

int ScheduleHandler::ScheduleSelection()
{
    DisplaySchedule();
    cout << endl;
    cout << "What hour do you want to update: ";
    int hour;
    cin >> hour;
    
    return hour;
}

void ScheduleHandler::AddSchedule(EmployeeHandler& employeeHandler)
{
    int hourIndex;
    hourIndex = ScheduleSelection();
    cout << endl;
    int employeeIndex;
    
    employeeIndex = employeeHandler.EmployeeSelection();
    Employee &refEmployee = employeeHandler.GetEmployee(employeeIndex);
    if (refEmployee.GetIsActive())
    {
        m_lstSchedule[hourIndex].AssignEmployee(&refEmployee);
        cout << m_lstSchedule[hourIndex].GetEmployeeName() << " is now added to the " << hourIndex << ":00 slot" << endl;
    }
    else
    {
        
        cout << "Cannot schedule.";
    
    }

}
void ScheduleHandler::CancelSchedule()
{
    cout << "Canceling Schedule:" << endl;
    cout << "------------------" << endl;
    int hourIndex;
    hourIndex = ScheduleSelection();
    string tempName = m_lstSchedule[hourIndex].GetEmployeeName();
    m_lstSchedule[hourIndex].Reset();
    cout << tempName << " is now removed from the " << hourIndex << ":00 slot." << endl;
    
}
void ScheduleHandler::ExportScheduleCSV()
{
    ofstream outFile;
    outFile.open("Schedule.csv");
    outFile << "Hour, Employee" << endl;
    for (int i = 0; i < 24; i++)
    {
        outFile << i << ":00, " << m_lstSchedule[i].GetEmployeeName() << endl;
    }
    outFile.close();
}
void ScheduleHandler::ExportScheduleHTML()
{
    ofstream outFile;
    outFile << "<head><title>Schedule</title>" << endl;
    outFile << "<style type='text/css'>" << endl;
    outFile << "table tr td { border: solid 1px #000000; width: 200px;";
    outFile << "background: #cccccc; }" << endl;
    outFile << "</style></head>" << endl;
    outFile << "<body><table>" << endl;
    outFile << "<tr><td>HOUR</td><td>EMPLOYEE</td></tr>" << endl;
    for (int i = 0; i < 24; i++)
    {
        outFile << "<tr>" << endl;
        outFile << "<td>" << i << ":00</td>" << endl;
        outFile << m_lstSchedule[i].GetEmployeeName();
        outFile << "</td>" << endl;
        outFile << "</tr>" << endl;
    }
    outFile << "</table><body>" << endl;
    outFile.close();
}
