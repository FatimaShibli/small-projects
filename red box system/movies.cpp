
#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;
#include"movies.h"
unsigned int i=0;
int indeX=0;
int count=0;

Movies::Movies(){};

void Movies::addMovie(Movie movietoadd){
    mymovies.push_back(movietoadd);

}

void Movies:: editMovie(Movie editmovie,int MVid){

    indeX=this->searchInfo(editmovie.getMovieID());
    if(indeX != -1){
            mymovies.at(indeX).setMovieID(editmovie.getMovieID());
            mymovies.at(indeX).setTitle(editmovie.getTitle());
            mymovies.at(indeX).setReleasedate(editmovie.getReleasedate());
            mymovies.at(indeX).setRating(editmovie.getRating());
            mymovies.at(indeX).setRentalcost(editmovie.getRentalcost());
            mymovies.at(indeX).setReplacecost(editmovie.getReplacecost());
        }

}

void Movies::updateStatus(int moviestatusid, char status){
    indeX=this->searchInfo(moviestatusid);
    if (indeX != -1)
    {
        cout<<"Movie was found";
        mymovies.at(indeX).setmoviestatus(status);
    }
    else
    {
        cout<<"Movie was not found, nothing deleted";
    }

}
void Movies::deleteMovie(int deletemovies){

    indeX=this->searchInfo(deletemovies);

    if(indeX!=-1)
    {
        mymovies.erase(mymovies.begin()+indeX);
    }
    else
    {
        cout<<"movie was not found";
    }

}
int Movies::searchInfo(int searchmovie){
  for (i = 0; i < mymovies.size(); i++)
    {
        if(mymovies.at(i).getMovieID()==searchmovie){

            cout<<"movie was found\n";
            return i;
        }
    }
    return -1;
}

void Movies::printAllInfo()
{
    for(i=0;i<mymovies.size(); i++)
    {
        mymovies.at(i).printAllMovies();
    }
}
void Movies::printSpecificMovie(string NforMovie){
    for (i = 0; i < mymovies.size(); i++)
    {
        if(mymovies.at(i).getTitle()==NforMovie){
            cout<<" Movie found";
            cout<<"for this movie: \n";
            cout<<"movie Name:"<<mymovies.at(i).getTitle();
            cout<<"\nMovie ID is:  "<<mymovies.at(i).getMovieID()<<endl;
            cout<<" Movie release date:  "<<mymovies.at(i).getReleasedate()<<endl;
            cout<<" Movie rating is:  "<<mymovies.at(i).getRating()<<endl;
            cout<<" Movie duration:  "<<mymovies.at(i).getDuration()<<endl;
            cout<<" Movie rental price is:  "<<mymovies.at(i).getRentalcost()<<endl;
            cout<<" Movie replacement cost: "<<mymovies.at(i).getReplacecost()<<endl;
            if(mymovies.at(i).getmoviestatus()=='o'){
            cout<<"Movie Status is: out"<<endl;
            }
            else if(mymovies.at(i).getmoviestatus()=='i'){
                cout<<"Movie Status is: in"<<endl;
            }
            else if(mymovies.at(i).getmoviestatus()=='r'){
                cout<<"Movie Status is: overdue"<<endl;
            }
            else if(mymovies.at(i).getmoviestatus()=='l'){
                cout<<"Movie Status is: lost"<<endl;
            }

        }
       else
       {
            cout<<"Movie was not found, enter another movie name\n";
       }


    }

}
vector<Movie> Movies::Getmovievec(){
    return mymovies;
}
