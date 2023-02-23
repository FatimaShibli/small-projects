#pragma once
#include<string>
#include<vector>
#include"Ent_item.h"
#include"game.h"
#include"movie.h"


class Ent_items
{
private:


public:
 vector<Ent_item*> myitems;
 
 game games;
 Movie movie;
    Ent_items();
    
    void addItem(Ent_item* itemtoadd);// add a item by passing the item i want to add to the function
    void editItem(Ent_item* itemedit, int newitemId, char edit_types);// edit a book based on if the book name matches 
    void deleteItem(int deleteitem);// delete item based on the id number, first search in the vector, if a match found delete the book
    int searchInfo(int searchbook);// search int the item vector based on the bookisbn, then if found return the index 
    void updateStatus(int itemstatusid, char status);//update item status based on items id,
    void printAllInfo();// print all items in the vector
    void printSpecificInfo(int idforitems); // print info about a baak based on search function wich takes the book id
    void storeitmes();
    void loaditems();





};
