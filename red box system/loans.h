#include<vector>
#include<string>
#include"movies.h"
#include"loan.h"
#include"customers.h"
#include"Ent_items.h"
using namespace std;

class Loans
{
private:

    vector<Loan> vloans;
    Ent_items items;
    Movies moviemanage;
    Customers managecustomer;
public:
    //Loans();

    int search_l(int id_loan);//search function
    void checkout(Loan nloan);//creates a loan
    void checkInmovie(int Checkloan, int moviesret);//delete loan
    void checkoverdue(int idforcust);//functions to check overdue before renting a movie for cutomers
    void listOverdues(int systemtime);//print all overdue loans based on the time
    void listmovies_customer(int cust_id);//list all the movies for a certain cutomer
    void reportLost(int Lost_personid, int lostMid);
    void storeloans();
    void editLoan(Loan editloan, int fplace);
    




    
};

