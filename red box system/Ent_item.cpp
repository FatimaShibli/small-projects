#include<iostream>
#include<vector>

#include "Ent_item.h"

Ent_item::Ent_item(){
    ItemCost=0;
    ItemStatus='0';
    loan_period=0;
    Itemid=0;
    ItemType='0';
}
Ent_item::Ent_item(double costsitem, char itemstats, int lperi, int item_ID, char type){
    ItemCost=costsitem;
    ItemStatus=itemstats;
    loan_period=lperi;
    Itemid=item_ID;
    ItemType=type;
}
void Ent_item::setItemCost(double costofitem){
    ItemCost=costofitem;
}
void Ent_item::setItemId( int Id_Item ){
   Itemid=Id_Item;
}
void Ent_item::setLoanperiod(int loanPeriod){
    loan_period=loanPeriod;
}
void Ent_item::setItemStatus(char Status_item){
    ItemStatus=Status_item;
}
void Ent_item::setItemtype(char ttyp){
    ItemType=ttyp;
}
/**/
double Ent_item::getItemCost(){
    return ItemCost;
}
int Ent_item::getItemId(){
    return Itemid;
}
int Ent_item::getLoanperiod(){
    return loan_period;
}
char Ent_item::getItemStatus(){
    return ItemStatus;
}
char Ent_item::getItemtype(){
    return ItemType;
}



void Ent_item::printItem()
{
    cout<<"\nItem cost is: "<< ItemCost;
    cout<<"\nLoan Period is: "<<loan_period;
    cout<<"\n Item ID is: "<<Itemid;
    cout<<"\n Item type is: "<<ItemType;

    if(ItemStatus=='a'){
        cout<<"\nItem Status is: Avaliable \n";
    }
    else if(ItemStatus=='o'){
        cout<<"\nItem Status is: Not Avaliable \n";
    }
    else if(ItemStatus=='l'){
        cout<<"\nItem Status is: Lost \n";
    }

}
istream& operator>>(istream& st, Ent_item& it)//definition
{
    it.printItem();
    return st;
}