#pragma once
#include<iostream>
#include<vector>
using namespace std;
//#include<string>
class Ent_item
{
    protected:
        double ItemCost;
        char ItemStatus;
        int loan_period;
        int Itemid;
        char ItemType;


    public:
       Ent_item();
       Ent_item(double costsitem, char itemstats, int lperi, int item_ID, char type);

        void setLoanperiod(int loanPeriod);
        void setItemId(int Id_Item );
        void setItemCost(double costofitem);
        void setItemStatus(char Status_item);
        void setItemtype(char ttyp);
        
        int getLoanperiod();
        int getItemId();
        double getItemCost();
        char getItemStatus();
        char getItemtype();
        virtual void printItem();
        //friend istream& operator>>(istream& st, Ent_item& it);//overloading insertion operator

};

