#include"customer.h"
using namespace std;



Customer::Customer(){

name="none";
CustomerID=0;
Cardexp="none";
Cardval=0;
Activemovies=0;
finebalance=0.0;
creditcardnumb=0;
}

Customer::Customer(string customername, int customerid, long int cardnumber, string experation, int validation, int activemovies, double fines)
{

Cardval=validation;
Activemovies=activemovies;
finebalance=fines;
name=customername;
CustomerID=customerid;
creditcardnumb=cardnumber;
Cardexp=experation;name=customername;
CustomerID=customerid;
creditcardnumb=cardnumber;
Cardexp=experation;

}

void Customer::SetName(string CustoName)
{
name=CustoName;
}
void Customer::SetId(int idnum)
{
CustomerID=idnum;
}
void Customer::SetCreditcardnumb(long int CardNumb)
{
creditcardnumb=CardNumb;
}
void Customer::SetExp(string expera)
{
Cardexp=expera;
}
void Customer::SetVal(int cardvalu)
{
Cardval=cardvalu;
}
void Customer::SetActive(int moviesactive)
{
Activemovies=moviesactive;
}
void Customer:: SetFine(double customerfine)
{
finebalance=customerfine;
}



string Customer::GetName()
{
return name;
}

int Customer::GetId()
{
return CustomerID;
}

long int Customer::GetCreditcardnumb()
{
return creditcardnumb;
}

string Customer::GetExp()
{
return Cardexp;
}

int Customer::GetVal()
{
return Cardval;
}

int Customer::GetActive()
{
return Activemovies;
}
double Customer::GetFine()
{
return finebalance;
}


void Customer::printCustomer()
{

        cout<<"Customer name is: "<< name <<endl;
        cout<<"Customer Id number is: "<< CustomerID <<endl;
        cout<<"Customer Credit card number is: "<< creditcardnumb<<endl;
        cout<<"Customer Card validation key is: "<<Cardval<<endl;
	    cout<<"Customer Card expires in:"<<Cardexp<<endl;
        cout<<"Customer Number of Active movies are: "<<Activemovies<<" Movies"<<endl;
    	cout<<"customer balance is: "<<finebalance<<endl;

}



