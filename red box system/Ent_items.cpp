#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include"Ent_items.h"
#include<fstream>
using namespace std;
unsigned int i=0;
int indeX=0;
int count=0;

Ent_items::Ent_items(){

}
void Ent_items::addItem(Ent_item* itemtoadd){
    myitems.push_back(itemtoadd);
    count++;

}

void Ent_items::editItem(Ent_item* itemedit, int newitemId, char edit_types){
    
    indeX=this->searchInfo(itemedit->getItemId());
    if(indeX != -1){
        
            myitems.at(indeX)=itemedit;    
        
    }
}

void Ent_items::updateStatus(int itemstatusid, char status){
    indeX=this->searchInfo(itemstatusid);
    if (indeX != -1)
    {
        cout<<"Item was found";
        myitems.at(indeX)->setItemStatus(status);
    }
    else
    {
        cout<<"Item was not found, nothing deleted";
    }
    
}
void Ent_items::deleteItem(int deleteitem){

    indeX=this->searchInfo(deleteitem);

    if(indeX!=-1)
    {
        myitems.erase(myitems.begin()+indeX);
        cout<<"\nItem deleted succesfully\n";
        count--;
    }
    else
    {
        cout<<"item was not found";
    }
    
}
int Ent_items::searchInfo(int searchbook){
  for (i = 0; i < myitems.size(); i++)
    {
        if(myitems.at(i)->getItemId()==searchbook){
        
            cout<<"\nItem was found was found\n";
            return i;
        }  
    }
    return -1;
}

void Ent_items::printAllInfo()
{
    for(i=0;i<myitems.size(); i++)
    {
        myitems.at(i)->printItem();
    }
}
void Ent_items::printSpecificInfo(int idforitems){

    for (i=0;i<myitems.size(); i++){

        if(myitems.at(i)->getItemId()==idforitems){
            cout<<"\nItem found\n";
            myitems.at(i)->printItem();
         
        }
       else
       {
            cout<<"item was not found, enter another item name\n";
       }
       

    }
}

void Ent_items::storeitmes(){

    Ent_item *temp;
    ofstream output;
    output.open("items.txt", ios::app);
    output<<"items number"<<count<<endl;
    
    for(i=0;i<myitems.size();i++)
    {
    
        myitems.at(i)->getItemtype();
        if(myitems.at(i)->getItemtype()=='g')
        {
            game *tempb=dynamic_cast<game*>(temp);
            output<<tempb->getgamerating <<endl;
            output<<tempb->getgamegenre()<<endl;
            output<<tempb->getgametitle<<endl;
            output<<tempb->getgamerentalcost<<endl;
            output<<tempb->getgame_Realesedate<<endl;
            output<<tempb->getgametitle()<<endl;
            output<<tempb->getgameStudio<<endl;
            
            output<<endl<<endl;

        }
        if(myitems.at(i)->getItemtype()=='m')
        {
            Movie *tempc=dynamic_cast<Movie*>(temp);
            output<< tempc->getTitle()<<endl;
            output<< tempc->getReleasedate()<<endl;
            output<< tempc->getRating()<<endl;
            output<< tempc->getDuration()<<endl;
            output<< tempc->getRentalcost()<<endl;
            output<< tempc->getReplacecost()<<endl;
            output<< tempc->getmoviestatus()<<endl;
            output<<endl<<endl;
        }
      
    }
        

    
}