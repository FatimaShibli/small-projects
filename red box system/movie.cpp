#include"movie.h"
using namespace std;

// initialize  

Movie::Movie(){

MovieID=0;
Title="none";
Releasedate=" ";
Rating="none";
Duration=" ";
Rentalcost=0.0;
Replacecost=0.0;
moviestatus='0';

}


Movie::Movie(int movieid, string title, string releasedate, string rating, string duration, double rentalcost, double replacecost, char Status){

    MovieID=movieid;
    Title=title;
    Releasedate=releasedate;
    Rating=rating;
    Duration=duration;
    Rentalcost=rentalcost;
    Replacecost=replacecost;
    moviestatus=Status;

}

// void function

void Movie::setMovieID(int Movieid)
{
MovieID=Movieid;
}
void Movie::setTitle(string movietitle)
{
Title=movietitle;
}
void Movie::setReleasedate(string reldate)
{
Releasedate=reldate;
}
void Movie::setRating(string rate)
{
Rating=rate;
}
void Movie::setDuration(string movietime)
{
Duration=movietime;
}
void Movie::setRentalcost(double rentcost)
{
Rentalcost=rentcost;
}
void Movie::setReplacecost(double repcost)
{
Replacecost=repcost;
}

void Movie::setmoviestatus(char Status)
{
moviestatus=Status;
}

//print function

void Movie::printAllMovies()
{
cout<<"Movie: "<<Title<<"\nID: "<<MovieID<<"\nRated: "<<Rating<<endl;
cout<<"Movie release date is: "<<Releasedate<<"\nMovie duration:"<<Duration<<endl;
cout<<"Movie rent cost: "<<Rentalcost<<"\nReplacement cost if lost: "<<Replacecost<<endl;

        if(moviestatus=='i'){
            cout<<"Movie status is: Avaliable";
        }
        else if(moviestatus=='o')
        {
            cout<<"Movie Status is: Out/not avaliable"<<endl;
        }
        else if(moviestatus=='r'){
            cout<<"Movie Status is: Overdue"<<endl;
        }
        else if(moviestatus=='l')
        {
            cout<<"Movie Status is: Lost"<<endl;
        }

}

int Movie::getMovieID()
{
    return MovieID;
}
string Movie::getTitle()
{
    return Title;
}

string Movie::getDuration()
{
    return Duration;
}
double Movie::getRentalcost()
{
    return Rentalcost;
}
double Movie::getReplacecost()
{
    return Replacecost;
}
char Movie::getmoviestatus()
{
    return moviestatus;
}

string Movie::getReleasedate()
{
    return Releasedate;
}
string Movie::getRating()
{
    return Rating;
}










