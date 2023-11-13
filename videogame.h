#ifndef VIDEOGAME_H //include guards
#define VIDEOGAME_H

#include<fstream> //necessary includes
#include "text.h" //include text class

using namespace std;

//declaring the videogame class
class Videogame
{
    //private members
    private:

    Text * title; //pointer to Text object
    Text * developer; // title, developer, and publisher are text objects for videogame
    Text * publisher;
    int year;

    //public members
    public:

    //function prototypes
    Videogame(Text *, Text *, Text *, int); //constructor
    ~Videogame(); //destructor
    void printVideoGameDetails();
    void printVideoGameDetailsToFile(ofstream &);
    Text * getVideoGameTitle();

};



#endif