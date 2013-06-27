//  main.cpp
//  cs201
//
//  Created by brad waier on 6/23/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Character.h"
#include "Equipment.h"
#include <Windows.h>

using namespace std;

//----------------------------------------------------------------------------------------------------------


void DisplayTitleScreen()
{
	cout << "###    ##   ##### #####  #    ####  ##" << endl;
    cout << "#  #  #  #    #     #    #    #     ##" << endl;
    cout << "###   ####    #     #    #    ####  ##" << endl;
    cout << "#  #  #  #    #     #    #    #       " << endl;
    cout << "###   #  #    #     #    #### ####  ##" << endl;
	cout << endl;
    cout << "Welcome to BATTLE! In this game, you will be fighting in an arena.\n";
    cout << "You can improve your attack, defense, and agility by allocating \n";
    cout << "character points, and also by picking specialized equipment. ";
    cout << endl;
}

//----------------------------------------------------------------------------------------------------------


void DisplayRoundMenu( int combatRound, Character player, Character enemy)
{
    
    cout << endl;
    cout << "###########################################\n";
    cout << "-------------------------------------------\n";
    cout <<  "ROUND " << combatRound << endl;
    cout << player.name <<" STATS:\n";
    cout << player.name << " HP: " << player.HP << endl;
    cout << player.name << " ATK: " << player.atk << endl;
    cout << player.name << " DEF: " << player.def << endl;
    cout << player.name << " AGI: " << player.agi << endl;
    cout << endl;
	cout << enemy.name <<" STATS:\n";
    cout << enemy.name << " HP: " << enemy.HP << endl;
    cout << enemy.name << " ATK: " << enemy.atk << endl;
    cout << enemy.name << " DEF: " << enemy.def << endl;
    cout << enemy.name << " AGI: " << enemy.agi << endl;
    cout << endl;
    cout << "-------------------------------------------\n";
    cout << "1. Quick Attack\n";
    cout << "2. Standard Attack\n";
    cout << "3. Heavy Attack\n";
    cout << "What will you do? \n";
    
}

//----------------------------------------------------------------------------------------------------------
void showStats(Character x, Character y)
{
	cout << x.name <<" STATS:\n";
    cout << x.name << " HP: " << x.HP << endl;
    cout << x.name << " ATK: " << x.atk << endl;
    cout << x.name << " DEF: " << x.def << endl;
    cout << x.name << " AGI: " << x.agi << endl;
    cout << endl;
	cout << y.name <<" STATS:\n";
    cout << y.name << " HP: " << y.HP << endl;
    cout << y.name << " ATK: " << y.atk << endl;
    cout << y.name << " DEF: " << y.def << endl;
    cout << y.name << " AGI: " << y.agi << endl;
    cout << endl;
	cout << endl;
}
//----------------------------------------------------------------------------------------------------------

Character AdjustStats(Character character, int attackChoice)
{

	character.adjustedAgi = character.agi;
	character.adjustedAtk = character.atk;

    if (attackChoice == 1) 
	{
        character.adjustedAgi = character.agi + 2;
        character.adjustedAtk = character.atk - 1;
    }
    else if (attackChoice == 3)
	{
        character.adjustedAtk = character.atk + 2;
        character.adjustedAgi = character.agi - 1;
    }
    return character;
}


//----------------------------------------------------------------------------------------------------------

Character AllocateStats(Character player)
{
    cout << endl;
    cout << "You must allocate five additional character points\n";
	cout <<	"to your character's attack, defense,or agility. \n";
    cout << "Or you may put it toward your character's Hit Points, where 1 pt. = 4 HP.\n\n";
    cout << "1. Hit Points\n";
    cout << "2. Attack\n";
    cout << "3. Defense\n";
    cout << "4. Agility\n\n";
    int characterPoints = 5;
    while (characterPoints != 0)
	{
        cout << "HP: " << player.HP << endl;
        cout << "ATK: " << player.atk << endl;
        cout << "DEF: " << player.def << endl;
        cout << "AGI: " << player.agi << endl << endl;
        cout << "Choose an option: " << endl;
		cout << endl;
        int option;
        cin >> option;
        if (option == 1)
		{
            player.HP += 4;
        }
        else if (option == 2)
		{
            player.atk += 1;
        }
        else if (option == 3)
		{
            player.def += 1;
        }
        else if (option == 4)
		{
            player.agi += 1;
        }
        characterPoints--;
        cout << "You have " << characterPoints << " remaining character points.\n" << endl;
        
    }
	return player;
}
//----------------------------------------------------------------------------------------------------------
Character allocateEnemyStats(Character enemy)
{
	
	int enemyStats[] = {enemy.atk, enemy.def, enemy.agi, enemy.HP};
    int enemyNum;
    int i = 0;
    while(i < 5)
	{
        enemyNum = rand() % 4;
		if (enemyStats[enemyNum] ==  enemy.HP)
		{
            enemy.HP += 4;
        }
        else if(enemyStats[enemyNum] ==  enemy.atk)
		{
			enemy.atk += 1;
        }
		else if(enemyStats[enemyNum] ==  enemy.def)
		{
			enemy.def += 1;
        }
		else if(enemyStats[enemyNum] ==  enemy.agi)
		{
			enemy.agi += 1;
        }

        i++;
    }
	return enemy;
}
//----------------------------------------------------------------------------------------------------------


void BeginPrompt()
{
    
    cout << "You ready for this? (yes/no) ";
    string choice;
    cin >> choice;
    
    while( choice != "yes")
	{
        cout << "Well, what are you waiting for? My show comes on at 6, bro. \n";
        cout << "Ready, now?! (yes/no) ";
        cin >> choice;
	}
	
}
//----------------------------------------------------------------------------------------------------------


void DisplayGameOver(Character player, Character enemy)
{
    cout << endl;
    cout << "    #####################################   " << endl;
    cout << " ####                                   ####" << endl;
    cout << "#           G A M E     O V E R             #" << endl;
    cout << "# ######################################### #" << endl;
    cout << "##                                         ##" << endl;
    cout << endl;
    
    if ( player.HP <= 0 )
	{
        cout << "Too bad, your city shall now burn!\n";
    }
    else if (enemy.HP <= 0)
	{
        cout << "Congratulations, you shall be honored with harlems full of women!\n";
    
	}
}
    
//---------------------------------------MAIN---------------------------------------------------------------


int main()
{
    
    DisplayTitleScreen();
    bool done = false;
    int combatRound = 0;
    srand(time(NULL)); // seed pseudo-random #'s
    
    //creates structure objects player and enemy based on the structure "character".
    
    Character player = {"PLAYER", 40};
    
    Character enemy =  {"ENEMY", 40};

	Equipment equipment[3];
    equipment[0].Setup("Knight's Pack", 8, 4, 3);
    equipment[1].Setup("Tank's Pack", 4, 8, 3);
    equipment[2].Setup("Rogue's Pack", 4, 3, 8);
    
	cout << endl;
	cout << "Please pick the following equipment by selecting 1, 2, or 3.  \n";
	cout << endl;

    for (int i = 0; i < 3; i ++)
	{
        equipment[i].PrintInfo();
    }
    
    int equipChoice;
    cin >> equipChoice;
    
    player.atk = equipment[equipChoice -1].atk;
    player.def = equipment[equipChoice -1].def;
    player.agi = equipment[equipChoice -1].agi;
    
    int enemyEquipChoice = rand() % 3;
    enemy.atk = equipment[enemyEquipChoice].atk;
    enemy.def = equipment[enemyEquipChoice].def;
    enemy.agi = equipment[enemyEquipChoice].agi;
    
    player = AllocateStats(player);
	enemy = allocateEnemyStats(enemy);              // randomly allocates five additional character points to enemy's stats

    int delayLength = 500;
    
    cout << endl;
    cout << "_____________\n";
    cout << "FIGHTER STATS\n";
    cout << "_____________\n";
    cout << endl;
    
	showStats(player, enemy);
    BeginPrompt();
    
	

while ( done == false )
{
    combatRound += 1;
    
    DisplayRoundMenu(combatRound, player, enemy);
    
    int playerChoice;
    cin >> playerChoice;
    
    while ( playerChoice < 1 || playerChoice > 3 )
	{
        cout << "Invalid choice, choose between 1 and 3: ";
        cin >> playerChoice;
        
    }
    int enemyChoice = rand() % 3 + 1;
    cout << "Enemy chooses option " << enemyChoice << endl;
    cout << "-------------------------------------------\n";
    
    player.adjustedAtk = player.atk;
    player.adjustedAgi = player.agi;
    
    enemy.adjustedAtk = enemy.atk;
    enemy.adjustedAgi = enemy.agi;
    
    // Adjust player and enemy stats based on the type of attack they're doing
    player = AdjustStats(player, playerChoice);
    enemy = AdjustStats(enemy, enemyChoice);
    
    // Begin battle
    cout << "PLAYER attacks ENEMY!\n";
    Sleep( delayLength );
    
    int randDiff = rand() % player.adjustedAgi;
    Sleep( delayLength );
    if ( randDiff >= 1 )
	{
        // calculate damage
        int damage = player.adjustedAtk - (enemy.def / 2);
        cout << "PLAYER hits ENEMY for " << damage << " damage!\n";
        enemy.HP -= damage;
    }
    else 
	{
        cout << "PLAYER misses!\n";
    }
    Sleep( delayLength );
    randDiff = rand() % enemy.adjustedAgi;
    Sleep( delayLength );
    
    if ( randDiff >= 1 )
	{
        //Calculate damage
        int damage = enemy.adjustedAtk - (player.def / 2);
        cout << "ENEMY hits PLAYER for " << damage << " damage!\n";
        player.HP -= damage;
    }
    else 
	{
        cout << "ENEMY misses!\n";
        
    }
    Sleep( delayLength );
    
    //Check to see if either player is knocked out
    if ( player.HP <= 0 )
	{
        cout << "PLAYER has fallen!\n";
        done = true;
    }
    else if (enemy.HP <= 0)
	{
        cout << "ENEMY has fallen!\n";
        done = true;
    }
    
    }// Game main (while) loop
    // At this point, either the player or the enemy has fallen.
    
    DisplayGameOver(player, enemy);
    
    system("PAUSE");
    return 0;
    
}//end main------------------------------------------------------------------------------------------------
    
