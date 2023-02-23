#include<string>
#include<iostream>
#include"movie.h"
using namespace std;

// class movies 

class Movies
{




public:
vector<Movie*> mymovies;
    Movies();

    void addMovie(Movie movietoadd);// add a movie by passing the movie
    void editMovie(Movie editmovie, int newMovieId);// edit a movie 
    void deleteMovie(int deletemovies);// delete a movie 
    int searchInfo(int searchmovie);// search int 
    void updateStatus(int moviestatusid, char status);
    void printAllInfo();// print all 
    void printSpecificMovie(string NforMovie); // print info 
    vector<Movie> Getmovievec();
    //void updateMovies() 




};
