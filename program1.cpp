/**********************
Author: Liam Rivers
Course section: 1310 - 001
Due Date: 9/18/2023
***********************/

#include "videogamelibrary.h"

using namespace std;

int main(){

    int choice; //user's menu choice
    char fileName[60]; //file name for user
    int maxGames = 0; //maximum number of games library can hold

    cout << "How many games can your library hold: ";
    cin >> maxGames;
    VideoGameLibrary * library = new VideoGameLibrary(maxGames); //prompts user for the maxGames, uses that to make a videogame library
    do{
        cout << endl;
        cout << "What would you like to do?" << endl;
        //menu options
        cout << "\t1. Load video games from a file." << endl;
        cout << "\t2. Save video games to a file." << endl;
        cout << "\t3. Add a video game." << endl;
        cout << "\t4. Remove a video game." << endl;
        cout << "\t5. Display all video games." << endl;
        cout << "\t6. Remove ALL video games from this Library and end program." << endl;
        cout << "CHOOSE 1-6: ";
        cin >> choice;
        cout << endl;
        while(choice > 6 || choice < 1){ //input validation
            cout << "Invalid input, please enter a number between 1-6: ";
            cin >> choice;
        }
        switch(choice){ //switch case for options, function calls inside each
            case 1:
                cout << endl;
                cin.ignore();
                cout << "What is the name of the file? (example.txt): ";
                cin.getline(fileName, 60); //gets file user wants to load from
                library->loadVideoGamesFromFile(fileName); //loads games from file
                break;
            case 2:
                cout << endl;
                cout << "What is the name of the file? (example.txt): ";
                cin.ignore();
                cin.getline(fileName, 60); //gets file user wants to save to
                library->saveToFile(fileName); //saves games to file
                break;
            case 3:
                library->addVideoGameToArray(); //adds a singular game to the library
                break;
            case 4:
                library->removeVideoGameFromArray(); //removes a singular game from library
                break;
            case 5:
                library->displayVideoGames(); //displays all videogames
                break;
            case 6:
                delete library;
                cout << "Videogame library deleted." << endl;
                cout << endl;
                cout << "Goodbye!";
                break;
        }

    }while(choice !=6); 
    
    //while loop to validate switch case until user wants to exit

    return 0;
}

//TO FIX
//CRASHES WHEN DEALLOCATING LIBRARY
//VGL.CPP - DESTRUCTOR- NEVER CONFIRMS DEALLOCATION TO USER
//VGL.CPP - RESIZEVIDEOGAMEARRAY - NEVER INFORMS USER THAT ARRAY IS BEING RESIZED
//VGL.CPP - DISPLAYVIDEOGAMES - NEVER CHECKS IF ARRAY IS EMPTY
// VGL.CPP - REMOVEVIDEOGAMEFROMARRAY - SHOULD CHECL IF THERE IS ONLY ONE ELEMENT AS WELL AS ZERO
//... NEVER CHECKS USER INPUT