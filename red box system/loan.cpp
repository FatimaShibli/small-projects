#include<iostream>
#include<string>
#include"loan.h"
#include<ctime>
using namespace std;

Loan::Loan(){

loanID=0;
MovieID={};
CustomerID=0;
due_date_time=0;
currentstatus=0;

}

Loan::Loan(int loanid, vector<int> movieid, int customerid, int date_time,char status)
{


loanID=loanid;
MovieID=movieid;
CustomerID=customerid;
due_date_time=date_time;
currentstatus=status;


}

void Loan::setLoanID( int loanId)
{
loanID=loanId;
}
void Loan::setMovieID(vector<int> Mid)
{
MovieID=Mid;
}
void Loan::setCustomerID(int idcustomer)
{
CustomerID=idcustomer;
}
void Loan::setDueTime(int duedate)
{
due_date_time=duedate;
}
void Loan::setcurrentstatus( char stat)
{
currentstatus=stat;
}
void Loan::setNmovies(int nmovies)
{
NumOfMovies=nmovies;
}
void Loan::setName(string cusname)
{
person_name=cusname;
}
void Loan::setcurrentTime(int currtime)
{
currenttime=currtime;
}

//-----------------------------------------------

int Loan::getLoanID()
{
return loanID;
}
vector<int> Loan::getMovieID()
{
return MovieID;
}
int Loan::getCustomerID()
{
return CustomerID;
}
int Loan::getDueTime()
{
return due_date_time;
}
char Loan::getcurrentStatus()
{
return currentstatus;
}
int Loan::getNmovies()
{
return NumOfMovies;
}
string Loan::getcusname()
{
return person_name;
}
int Loan::getcurrentTime()
{
return currenttime;
}

