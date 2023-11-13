#ifndef VIDEOGAMELIBRARY_H //include guards
#define VIDEOGAMELIBRARY_H

#include "videogame.h" //includes videogame class, by association includes text class

using namespace std; //declaring the namespace

//declaring the VideoGameLibrary class
class VideoGameLibrary
{
    //private members
    private:
    Videogame ** videoGamesArray; //the array of videogames
    int maxGames; //max number of games the library can hold
    int numGames; //current number of games the library has

    //public members
    public:
    VideoGameLibrary(int maxGames); //constructor
    ~VideoGameLibrary(); //destructor

    //function prototypes
    void resizeVideoGameArray();
    void addVideoGameToArray();
    void displayVideoGames();
    void displayVideoGameTitles();
    void loadVideoGamesFromFile(char *);
    void removeVideoGameFromArray();
    void saveToFile(char *);

};

#endif