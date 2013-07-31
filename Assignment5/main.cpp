//  main.cpp
//  Assignment5
//
//  Created by brad waier on 7/20/13.
//  Copyright (c) 2013 brad waier. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int DisplayMenu()
{
	cout << "Recipes" << endl;
    cout << "--------" << endl;
    cout << "1: Add New Recipe" << endl;
    cout << "2: Export Recipes" << endl;
    cout << "3: Quit" << endl;
    cout << endl;
    cout << "What do you want to do? " << endl;
    int choice;
    cin >> choice;
	cin.ignore(1, '\n');
    return choice;
}

void AddRecipe(map <string, vector<string> >& recipes)
{
	
    string name;
    string enterMore = "y";

    while (enterMore == "y")
    {

		cout << "Enter the recipe name: " << endl;
		cin >> name;
		bool done = false;
		cin.clear();
		cin.ignore(1, '\n');
		while (done == false)
		{
			cout << "Enter ingredient and its amount " << endl;
			cout << "or type 'done' when finished. ";
			string ingredient;
			getline(cin, ingredient, '\n');
			if (ingredient == "done")
			{
				done = true;
			}
			else
			{
				recipes[name].push_back(ingredient);
				cout << "Added: " << ingredient << endl << endl;
			}
		}
		cout << "Enter more recipes? (y/n): ";
		cin >> enterMore;
    }
   
}

void ExportRecipes(map< string, vector<string> >& recipes)
{
	ofstream outFile;
    outFile.open("Recipes.txt");
    
    for ( map<string, vector<string> >::iterator recipe = recipes.begin(); recipe != recipes.end();recipe++)
        
    {
        outFile << endl << endl << recipe->first << endl;
        
        for (vector< string >::iterator ingredient = recipe->second.begin(); ingredient != recipe->second.end(); ingredient++ )
        {
            outFile << "\t" << *ingredient << endl;
        }
    
    }
    outFile.close();

}

int main(int argc, const char * argv[])
{

    map< string, vector<string> > recipes; //must be white-space between two end arrows
    
    bool done = false;
    while (done == false)
    {
        int choice = DisplayMenu();
        if (choice == 1)
        {
            AddRecipe(recipes);
        }
        else if (choice == 2)
        {
            
            ExportRecipes(recipes);
        }
        else if (choice == 3)
        {
			cout << endl << "Goodbye" << endl;
            done = true;
        }
    }
    
    system("PAUSE");
    return 0;
}



