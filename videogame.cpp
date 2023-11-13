#include "videogame.h"


Videogame::Videogame(Text * neoTitle, Text * neoDev, Text * neoPub, int neoYear){ //just using neo as a prefix to differentiate variables

//makes the videogame object
//initializes all attributes to arguments sent to this function

title = neoTitle;
developer = neoDev;
publisher = neoPub;
year = neoYear;

};

Videogame::~Videogame(){

//release dynamically allocated text arrays in video game

    delete title;
    delete developer;
    delete publisher;

    cout << "Videogame objects deleted" << endl;

};

void Videogame::printVideoGameDetails(){ // this function displays the information of a videogame

//this will allow the printing of text objects which would be title, developer, and publisher

    cout << "Game title: ";
    title->displayText();
    cout << endl;

    cout << "Game developer: ";
    developer->displayText();
    cout << endl;

    cout << "Game publisher:";
    publisher->displayText();
    cout << endl;

    cout << "Year: ";
    cout << this->year << endl; //prints the year

};

void Videogame::printVideoGameDetailsToFile(ofstream &outfile){ //this function will print the details of a videogame to a file

    outfile << title->getText() << endl; //outfile used as the ofstream object
    outfile << developer->getText() << endl;
    outfile << publisher->getText() << endl;
    outfile << year << endl;
};

Text * Videogame::getVideoGameTitle(){ //allows the title of a game to be returned for printing, used when removing a videogame
    return this-> title;
};
