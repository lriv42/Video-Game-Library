#include "videogamelibrary.h"

VideoGameLibrary::VideoGameLibrary(int maxGames){ // constructor

    //dynamically allocate array of pointers using maximum size

    this->maxGames = maxGames; //assigning the variable passed in to the maxGames variable stored in the class

    this->videoGamesArray = new Videogame * [maxGames];  //makes the array storing videogames using the maxGames class member
    this->numGames = 0; //sets current number of games held to 0 as the library is being constructed, so no games are held at the moment

}

VideoGameLibrary::~VideoGameLibrary(){ // destructor

    //destroying VideoGame object and array storing the videogames
    for(int i = 0; i < this->numGames; i++){ //for loop needed to delete each object at the array element
        delete videoGamesArray[i];
    }
    delete [] videoGamesArray; //deletes the actual array itself

}


void VideoGameLibrary::resizeVideoGameArray(){

    //called by addVideoGameToArray
    //if videoGamesArray not big enough to hold a new game, doubles size of array
    //then moves all video game pointers to new array

    this->maxGames *= 2; //doubles the maximum amount of games that can be held

    Videogame** newVideoGameLibrary = new Videogame* [this->maxGames]; //creates a new array the size of the new doubled maxGames variable
    for(int i = 0; i <this->numGames; i++){
        newVideoGameLibrary[i] = videoGamesArray[i]; //copies over all information from previous library to the new library 
    }
    delete [] videoGamesArray; //deletes the old library

    videoGamesArray = newVideoGameLibrary; //assigns the pointer of the old library to point to the new array we just made
}

void VideoGameLibrary::addVideoGameToArray(){

    //called when adding SINGLE video game to library
    //asks for title, developer, and publisher (dynamically created text objects) and year
    
    //then checks if numgames is == maxgames. if true calls resizevideogamearray
    //then increments numgames by 1

    char tempCstring [100]; //used to take in user input
    int year = 0; //year doesn't need to be a cstring

    cin.ignore();
    cout << "What is the Title: ";
    cin.getline(tempCstring, 100);
    Text* textTitle = new Text(tempCstring); //gets the title from user, makes a new text object using input
    cout << endl;

    cout << "What is the Developer: ";
    cin.getline(tempCstring, 100);
    Text* textDev = new Text(tempCstring); //gets the developer and makes a new text object
    cout << endl;

    cout << "What is the Publisher: ";
    cin.getline(tempCstring, 100);
    Text* textPub = new Text(tempCstring); //gets the publisher and makes a new text object
    cout << endl;

    cout << "What is the year: ";
    cin >> year; //gets the year, an integer variable

    if(numGames==maxGames){
        resizeVideoGameArray(); //checks if we have hit the maximum number of games in the library, if so we resize it to double the size
    }
    videoGamesArray[this->numGames] = new Videogame(textTitle, textPub, textDev, year); //adds the new video game to the library
    numGames++; //after adding the videogame we increase the number of games are currently stored in the library

}

void VideoGameLibrary::displayVideoGames(){

    //loops through videogamesarray and calls the printvideogamedetails function
    //prints all video games in library to screen
    for(int i = 0; i < this->numGames; i++){
        cout << "\t--VIDEOGAME--" << i+1 << endl;
        videoGamesArray[i]->printVideoGameDetails();
        cout << endl;
    }
}

void VideoGameLibrary::displayVideoGameTitles(){

    //called to only print video game title
    //used when user wants to remove a video game from library
    //loops through videogamesarray and prints title by calling getvideogametitle function
    //then prints the title by calling display text function

    for(int i = 0; i < this->numGames; i++){
        cout << "\t" << i+1 << ".";
        videoGamesArray[i]->getVideoGameTitle()->displayText();
        cout << endl;
    }

}

void VideoGameLibrary::loadVideoGamesFromFile(char * userFile){

    int i = 0; //used to count the number of games we add
    ifstream infile; 
    char fileData[10000];
    Text* tempTitle; //temporary text objects
    Text* tempDev;
    Text* tempPub;
    int year = 0;

    infile.open(userFile); //opening the users file

    if(!infile.is_open()){
        cout << userFile << " could not be opened. ";
    } //checks if the file is open or not. if not then no gmaes are loaded
    else{

        while(!infile.eof()){ //gets data line by line until we reach end of the file
            infile.getline(fileData, 10000, '\n');
            tempTitle = new Text(fileData); //gets the temporary title to create a text object for title
            infile.getline(fileData,10000, '\n');
            tempDev = new Text(fileData); //repeats through for each necessary parameter until we make a videogame object
            infile.getline(fileData, 10000, '\n');
            tempPub = new Text(fileData);
            infile >> year;
            infile.ignore();
            
                
            Videogame * newVideo = new Videogame(tempTitle, tempDev, tempPub, year); //creates a new videogame object using data we got from file (above)
    
            if(numGames == maxGames){
                resizeVideoGameArray(); //resizes the array if library is at maximum capacity
            }

            i++; //counter for added games
            videoGamesArray[numGames] = newVideo;//adds video game to array here
    
            //print title of game and number of games that were added
            newVideo->getVideoGameTitle()->displayText();
            cout << " was added." << endl;
            numGames ++;
                
        }
    }
    cout << i << " games were added." << endl; //prints total number of games added

}

void VideoGameLibrary::removeVideoGameFromArray(){

    int del = 0; //used to store selection
    if(numGames == 0){ //checks so function only runs so long as we have at least one game to delete in the library
        cout << "You must have at least one game to delete from your library!" << endl;;
    }
    else{

        //once game is identified, print that title is successfully deleted
        cout << "Which game would you like to delete?" << endl;
        cout << endl;
        displayVideoGameTitles(); //game must be identified (print videogame title) by user
        cin >> del;

        videoGamesArray[del-1]->getVideoGameTitle()->displayText();
        cout << " was successfully deleted." << endl;  //once game is identified, print that title is successfully deleted

        delete videoGamesArray[del-1]; //deletes the videogame
        //for loop to copy game data one array element up the previous element
        for(int i = (del-1); i < numGames; i++){
            videoGamesArray[i] = videoGamesArray[i+1]; //this fills in the void left at the deletion number
        }

        videoGamesArray[numGames] = NULL; //because we have a duplicate at the end of the array, set last element to null
        numGames--; //decrease games currently held in library
    }

}

void VideoGameLibrary::saveToFile(char * userFile){

    //saves all data to user file
    //prints data in order, one piece of data per line
    //open file with name sent to function
    //use loop to go through array and call printvideogamedetailstofile
    //send file stream object to function ^
    //close file and print confirmation message that videogames were printed
    //makes me wanna switch to business major

    ofstream outfile;
    outfile.open(userFile); //opens file user wants to save to

    for(int i = 0; i < numGames; i++){
        videoGamesArray[i]->printVideoGameDetailsToFile(outfile); //prints all videogames in library to file
    }

    cout << "ALL video games have been saved to " << userFile << endl; //tells user all games have been saved
    outfile.close(); //closes user file
}