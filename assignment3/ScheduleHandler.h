//  ScheduleHandler.h
//  CS201
//
//  Created by brad waier on 6/29/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#ifndef CS201_ScheduleHandler_h
#define CS201_ScheduleHandler_h

#include <iostream>
#include <string>
#include "Schedule.h"
#include "EmployeeHandler.h"

class ScheduleHandler
{
public:
    ScheduleHandler();
    void AddSchedule(EmployeeHandler& employeeHandler);
    void EditSchedule(EmployeeHandler& employeeHandler);
    void CancelSchedule();
    void DisplaySchedule();
    void ExportScheduleCSV();
    void ExportScheduleHTML();
    int ScheduleSelection();

private:
    Schedule  m_lstSchedule[24];
    int m_beginHour;
};


#endif
