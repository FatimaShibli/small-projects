#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<fstream>
#include"customers.h"
using namespace std;

unsigned int k=0;
int location=0;
string str;
int custcount=0;
double totalfine=0.0;

Customers::Customers(){

}
int  Customers::searchCustomer(int searchcustomer){
    for(k=0; k<customers.size(); k++){
        if(customers.at(k).GetId()==searchcustomer){
            return k;
        }

    }
    return -1;
}

void Customers::addCustomer(Customer addcust){
    customers.push_back(addcust);
    custcount++;
     this->storeCustomer();
}
void Customers::deleteCustomer(int deletecust){
    location= this->searchCustomer(deletecust);
    if(location!=-1){
        customers.erase(customers.begin()+location);
        this->storeCustomer();
        cout<<"customer deleted\n";
    }
    else
    {
        cout<<"customer not found, nothing deleted";
    }

}
void Customers::editCustomer(Customer editcust, int newcustId, int Sindex){


    customers.at(Sindex).SetName(editcust.GetName());//fuck uuu
    customers.at(Sindex).SetId(newcustId);
    customers.at(Sindex).SetCreditcardnumb(editcust.GetCreditcardnumb());
    customers.at(Sindex).SetExp(editcust.GetExp());
    customers.at(Sindex).SetVal(editcust.GetVal());
    customers.at(Sindex).SetFine(editcust.GetFine());
    customers.at(Sindex).SetActive(editcust.GetActive());

}


double Customers::calcFines(int numdays_over){
    return 0.25*numdays_over;
}

void Customers::updateFines(int custID, double numDays){
    location= this->searchCustomer(custID);
    if(location!=-1){
        cout<<"Customer found\n";

        customers.at(location).SetFine(numDays);
        cout<<"fines updated\n";
    }
    else
    {
        cout<<"\nCustomer not found, no fines updated\n";
    }
}

void Customers::storeCustomer(){
    ofstream output;
    output.open("customers.txt", ios::app);
    output<<"customer number"<<custcount<<endl;
    for(k=0;k<customers.size();k++){
        output<<"ID is: "<<customers.at(k).GetId()<<endl;
        output<<"Name is: "<<customers.at(k).GetName()<<endl;
        output<<"Card Number is: "<<customers.at(k).GetCreditcardnumb()<<endl;
	output<<"Experation date: "<<customers.at(k).GetExp()<<endl;
        output<<"Number of movies is: "<<customers.at(k).GetActive()<<endl;
        output<<endl<<endl;
    }

	output.close();
}


void Customers::updatemovies_customer(int customerstatusid, int p_nmbermovies){
    location=0;
    location=this->searchCustomer(customerstatusid);
    if(location!=-1){
        cout<<"Customer found\n";
        customers.at(location).SetActive(p_nmbermovies);
    }
    else
    {
        cout<<"customer not found, nothing updated\n";
    }
    
}





void Customers::loadCustomer(){
    ifstream input;
    input.open("customers.txt",ios::app);
    string temp_custnm="";
    string temp_retday="";
    int temp_id=0;
    double temp_fines=0.0;
    int temp_numb=0;
    int temp_drent=0;
    for(k=0;k<customers.size();k++)
    {
        temp_custnm=customers.at(k).GetName();
        temp_id=customers.at(k).GetId();

        temp_fines=customers.at(k).GetFine();
        temp_numb=customers.at(k).GetActive();

        cin >> temp_custnm;
        cin >>temp_id;
        
        cin>>temp_fines;
        cin>>temp_numb;
        


    }



}
    
    









void Customers::printAllInfo(){
    for(k=0; k<customers.size(); k++){
        customers.at(k).printCustomer();
    }
}

void Customers::print_allinfo_Customer(int NforCustomer){
    location=0;
    location=this->searchCustomer(NforCustomer);
    if(location!=-1)
    {
        cout<<"Customer found\n";
        cout<<"Printing all info for Customer\n";
        cout<<"name is:"<<customers.at(location).GetName()<<endl;
        cout<<"ID is :"<<customers.at(location).GetId()<<endl;
        cout<<"card number is: "<<customers.at(location).GetCreditcardnumb()<<endl;
        cout<<"Experation date is: "<<customers.at(location).GetExp()<<endl;
        cout<<"Validation key is:"<<customers.at(location).GetVal()<<"\n";
        cout<<"Active movies : "<<customers.at(location).GetActive();
    }
    else
    {
        cout<<"Customer not found, no info is printed\n";
    }

}

