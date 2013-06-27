//  Equipment.cpp
//  cs201
//
//  Created by brad waier on 6/23/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#include "Equipment.h"
#include <iostream>
#include <string>

using namespace std;

void Equipment::Setup(string equipname, int attack, int defense, int agility){
    
    name = equipname;
    atk = attack;
    def = defense;
    agi = agility;
    
}
void Equipment::PrintInfo(){
    
    cout << "Name: " << name << " ATK: " << atk << " DEF: " << def << " AGI: " << agi << endl;
}

