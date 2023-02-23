#include<iostream>
#include<string>
#include<vector>
#include"customer.h"
using namespace std;




// class for Customer

class Customers
{

// privare class
private:

public:

// Vector for class customers
vector<Customer>customers;
Customers();


        void addCustomer(Customer addcust);
        void editCustomer(Customer editcust, int newcustId, int Sindex);// edit a customer based on if the Customer id matches 
        void deleteCustomer(int deletecust);// delete a customer based on the id number, first search in the vector, if a match found delete the customer
        int searchCustomer(int searchcust);
        void updateFines(int custID, double numDays);
        void updatemovies_customer(int customerstatusid, int p_nmbermovies);
        void printAllInfo();
        void print_allinfo_Customer(int NforCustomer);
        void storeCustomer();
        void loadCustomer();
        double calcFines(int numdays_over);
   
    


};




