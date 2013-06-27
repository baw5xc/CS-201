//  Equipment.h
//  cs201
//
//  Created by brad waier on 6/23/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#ifndef cs201_Equipment_h
#define cs201_Equipment_h

#include <iostream>
#include <string>

using namespace std;

struct Equipment {
    void PrintInfo();
    void Setup( string equipname, int attack, int defense, int agility);
    
    string name;
    int atk;
    int def;
    int agi;
    
};

#endif
