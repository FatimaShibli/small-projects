#include<iostream>
#include<string>
#include"Ent_item.h"
using namespace std;


class Movie:public  Ent_item
{

//private variables
private:

int MovieID;
string Title;
string Releasedate;
string Duration;
double Rentalcost;
double Replacecost;
char moviestatus;
string Rating;


//public variables
public:

//constructors
Movie();
Movie(int movieid, string title, string releasedate, string rating, string duration, double rentalcost, double replacecost, char Status);

//sitters and print fucntion
void setMovieID(int MovieiD);
void setTitle(string movietitle);
void setReleasedate(string reldate);
void setDuration(string movietime);
void setRentalcost(double rentcost);
void setReplacecost(double repcost);
void setRating(string rate);
void setmoviestatus(char STatus);

void printAllMovies();

//getter functions

int getMovieID();
string getTitle();
string getReleasedate();
string getRating();
string getDuration();
double getRentalcost();
double getReplacecost();
char getmoviestatus();

};
