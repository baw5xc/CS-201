//  main.cpp
//  Assignment6
//
//  Created by brad waier on 7/20/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#include <iostream>
#include "CardStack.h"
#include <string>
#include <fstream>
#include <time.h>
#include <Windows.h>
#include <cstdlib>
#include <list>


using namespace std;

int main(int argc, const char * argv[])
{

    ofstream outFile;
    outFile.open("Output.txt");
    
    
    bool done = false;
    int game = 1;
    
    while (done != true)
    {
        
        cout << "Game " << game;
        cout << endl << endl;
        Stack cards;
        int players[5];
        for (int i = 0; i < 5; i++)
        {
            players[i] = 0;
        }
        
        srand(time(NULL));
        
        for (int i = 0; i < 100; i++)
        {
            cards.Push( (rand() % 5));
            
        }
        
        
        while(cards.GetSize() != 0)
        {
            for (int i = 0; i < 5; i++)
            {
                players[i] += cards.Top();
                cards.Pop();
            }
        }
        
        
        int max = players[0];
        int maxPlayer;
        for (int i = 0; i < 4; i++)
        {
            if (max < players[i+1])
            {
                max = players[i+1];
                maxPlayer = i+1;
            }
        }
        
        
        cout << "Game " << game << " Score: " << endl;
        cout << "-------------" << endl;
        cout << "Player 1: " << players[0] << endl;
        cout << "Player 2: " << players[1] << endl;
        cout << "Player 3: " << players[2] << endl;
        cout << "Player 4: " << players[3] << endl;
        cout << "Player 5: " << players[4] << endl;
        cout << "And the winner is Player " << (maxPlayer+1) << " with a score of " << max << ".";
        cout << endl;
        
        outFile << " Game " << game << " Score: " << endl;
        outFile << "------------------" << endl;
        outFile << "Player 1: " << players[0] << endl;
        outFile << "Player 2: " << players[1] << endl;
        outFile << "Player 3: " << players[2] << endl;
        outFile << "Player 4: " << players[3] << endl;
        outFile << "Player 5: " << players[4] << endl;
        outFile << "And the winner is Player " << (maxPlayer+1) << " with a score of " << max << ".";
        outFile << endl << endl;
        
        cout << endl;
        cout << "Keep playing? (y/n): ";
        string answer;
        cin >> answer;
        if (answer == "n")
        {
            done = true;
        }
        else
        {
            game += 1;
        }
        

    }
    outFile.close();
    system("PAUSE");
    return 0;
}

//-----------
