#include<iostream>
#include<string>
using namespace std;

// class customer 

class Customer
{
private:
	string name;
	int Cardval;
	int Activemovies;
	double finebalance;
	int CustomerID;
	long int creditcardnumb;
	string Cardexp;


// public class

public:
Customer();

Customer(string customername, int customerid, long int cardnumber, string experation, int validation, int activemovies, double fines);


// declare sets

void SetName(string CustoName);
void SetActive(int moviesactive);
void SetCreditcardnumb(long int CardNumb);
void SetId(int idnum);
void SetExp(string expera);
void SetVal(int cardvalu);
void SetFine(double customerfine);


void printCustomer();

// declare gets

string GetName();
int GetId();
long int GetCreditcardnumb();
int GetActive();
double GetFine();
string GetExp();
int GetVal();



};

