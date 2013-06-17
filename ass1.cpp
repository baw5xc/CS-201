
#include <iostream>
#include <string>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
using namespace std;

int main(){
    
    cout << "BATTLE GAME" << endl;
    bool done = false;
    int combatRound = 0;
    srand(time(NULL)); // seed pseudo-random #'s
    int playerHP = 20;
    int playerAtk = rand() % 6 + 3;
    int playerDef = rand() % 6 + 3;
    int playerAgi = rand() % 6 + 3;
    
    int enemyHP = 20;
    int enemyAtk = rand() % 6 + 2;
    int enemyDef = rand() % 6 + 2;
    int enemyAgi = rand() % 6 + 2; 
    
    int delayLength = 500;
    
    cout << endl;
    cout << "_____________\n";
    cout << "FIGHTER STATS\n";
    cout << "_____________\n";
    
    cout << endl;
    cout << "PLAYER STATS:\n";
    cout << "HP " << playerHP << endl;
    cout << "ATK " << playerAtk << endl;
    cout << "DEF " << playerDef << endl;
    cout << "AGI " << playerAgi << endl;
    
    cout << endl;
    cout << "ENEMY STATS:\n";
    cout << "HP " << enemyHP << endl;
    cout << "ATK " << enemyAtk << endl;
    cout << "DEF " << enemyDef << endl;
    cout << "AGI " << enemyAgi << endl;
    
    cout << endl;
    cout << "Ready to begin? (yes/no) ";
    string choice;
    cin >> choice;
    
    while( choice != "yes"){
        cout << "Well, what are you waiting for? \n";
        cout << "Ready to begin? (yes/no) ";
        cin >> choice;
        
    }
    
    while ( done == false ){
        combatRound += 1;
        cout << endl;
        cout << "###########################################\n";
        cout << "-------------------------------------------\n";
        cout <<  "ROUND " << combatRound << endl;
        cout <<  "PLAYER:\t HP " << playerHP << " ATK " << playerAtk
        << " DEF " << playerDef << " AGI " << playerAgi << endl;
        cout <<  "ENEMY:\t HP " << enemyHP << " ATK " << enemyAtk
        << " DEF " << enemyDef << " AGI " << enemyAgi << endl;
        cout << "-------------------------------------------\n";
        cout << "1. Quick Attack\n";
        cout << "2. Standard Attack\n";
        cout << "3. Heavy Attack\n";
        cout << "What will you do? \n";
        int playerChoice;
        cin >> playerChoice;
        
        while ( playerChoice < 1 || playerChoice > 3 ){
            cout << "Invalid choice, choose between 1 and 3: ";
            cin >> playerChoice;
            
        }
        int enemyChoice = rand() % 3 + 1;
        cout << "Enemy chooses option " << enemyChoice << endl;
        cout << "-------------------------------------------\n";
        
        // Adjust player and enemy stats based on the type of attack they're doing

        
        int adjustedPlayerAtk = playerAtk;
        int adjustedPlayerAgi = playerAgi;
        
        int adjustedEnemyAtk = enemyAtk;
        int adjustedEnemyAgi = enemyAgi;
        
        if ( playerChoice == 1 ){
            adjustedPlayerAgi += 2;
            adjustedPlayerAtk -= 1;
        }
        else if ( playerChoice == 3 ){
            adjustedPlayerAgi -= 1;
            adjustedPlayerAtk += 2;
        }
        if ( enemyChoice == 1 ){
            adjustedEnemyAgi += 2;
            adjustedEnemyAtk -= 1;
        }
        else if ( enemyChoice == 3 ){
            adjustedEnemyAgi -= 1;
            adjustedEnemyAtk += 2;
        }
        
        // Begin battle
        cout << "PLAYER attacks ENEMY!\n";
        Sleep( delayLength );
        
        int randDiff = rand() % adjustedPlayerAgi;
        Sleep( delayLength );
        if ( randDiff >= 1 ){
            // calculate damage
            int damage = adjustedPlayerAtk - enemyDef / 2;
            cout << "PLAYER hits ENEMY for " << damage << " damage!\n";
            enemyHP -= damage;
        }
        else {
            cout << "PLAYER misses!\n";
        }
        Sleep( delayLength );
        randDiff = rand() % adjustedEnemyAgi;
        Sleep( delayLength );
        
        if ( randDiff >= 1 ){
            //Calculate damage
            int damage = adjustedEnemyAtk - playerDef / 2;
            cout << "ENEMY hits PLAYER for " << damage << " damage!\n";
            playerHP -= damage;
        }
        else {
            cout << "ENEMY misses!\n";
            
        }
        Sleep( delayLength );
        
        //Check to see if either player is knocked out
        if ( playerHP <= 0 ){
            cout << "PLAYER has fallen!\n";
            done = true;
        }
        else if (enemyHP <= 0){
            cout << "ENEMY has fallen!\n";
            done = true;
        }
                
    }// Game main (while) loop
    // At this point, either the player or the enemy has fallen.
    cout << endl;
    cout << "    #####################################   " << endl;
    cout << " ####                                   ####" << endl;
    cout << "#           G A M E     O V E R             #" << endl;
    cout << "# ######################################### #" << endl;
    cout << "##                                         ##" << endl;
    cout << endl;
    
    if ( playerHP <= 0 ){
        cout << "Too bad, you lose!\n";
    }
    else if (enemyHP <= 0){
        cout << "Congratulations, you won!\n";
    }
    system("PAUSE");
    return 0;
    
}//end main

