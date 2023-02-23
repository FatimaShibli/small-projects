#include<iostream>
#include<string> 
#include<vector>
using namespace std;

class Loan
{

private:

    long int loanID;
    vector<int> MovieID;
    int CustomerID;
    int NumOfMovies;
    int due_date_time;
    int currenttime;
    char currentstatus;
    std::string person_name;
    


public:
Loan();
Loan(int loanid, vector<int> movieid, int customerid, int date_time,char status);

//----------------------------------------------

void setLoanID( int loanID);
void setMovieID(vector<int> Mid);
void setCustomerID(int idcustomer);
void setDueTime(int duedate);
void setcurrentstatus( char stat);
void setNmovies(int nmovies);
void setName(string cusname);
void setcurrentTime(int currtime);



int getLoanID();
vector<int> getMovieID();
int getCustomerID();
int getDueTime();
char getcurrentStatus();
int getNmovies();
string getcusname();
int getcurrentTime();


};
