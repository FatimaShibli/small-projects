#include"game.h"
#include<iostream>
using namespace std;

game::game(){
    game_rating="none";
    game_Genre = 0;
    game_title = "none";
    game_Realesedate="none";
    rentalcost=0.0;
    Studio="none";
    Replacement_Cost = 0.0;
}
game::game(string grating, double ggenre, string gtitle, string grealeasedate, string gstudio, string grentalcost,float gReplacement_Cost){
    game_rating=grating;
    game_Genre = ggenre;
    game_title=gtitle;
    game_Realesedate=grealeasedate;
    rentalcost=grentalcost;
    Studio=gstudio;
    Replacement_Cost = gReplacement_Cost;
}

/************************************************************************************************/
void game::setgamerating(string gamerating){
    game_rating=gamerating;
}
void game::setgamegenre(double gamegenre){
    game_Genre=gamegenre;
}
void game::setgametitle(string gametitle){
    game_title=gametitle;
}
void game::setgameStudio(string gameStudio){
    Studio=gameStudio;
}
void game::setgame_Realesedate(string gRealesedate){
    game_Realesedate=gRealesedate;
}

void game::setgamerentalcost(string gamerentalcost){
    rentalcost=gamerentalcost;
}

void game::setgameReplacement_Cost(float gameReplacement_Cost){
    Replacement_Cost=gameReplacement_Cost;
}






string game:: getgamerating(){
    return game_rating;
}
double game:: getgamegenre(){
    return game_Genre;
}
string game:: getgame_Realesedate(){
    return game_Realesedate;
}
string game:: getgameStudio(){
    return Studio;
}
string game:: getgamerentalcost(){
    return rentalcost;
}

float game:: getgameReplacement_Cost(){
    return Replacement_Cost;
}

string game:: getgametitle(){
    return game_title;
}




void game::printItem(){

    cout<<"\ngame Title is: "<<game_title;
    cout<<"\n\n item is game\n";
    cout<<"\ngame Rating is:"<<game_rating;
    cout<<"\nItem  Genre: "<<game_Genre;
    cout<<"\ngame Release date: "<<game_Realesedate;
    cout<<"\ngame studio: "<< Studio;
    cout<<"\ngame rental cost "<<rentalcost;
    cout<<"\ngame replacement cost "<<Replacement_Cost;
    
    
     if(ItemStatus=='o'){
        cout<<"\n game satatus is : Not avaliable\n";
    }
    else if(ItemStatus=='a'){
        cout<<"\n game satatus is :  Avaliable\n";
    }
    else if(ItemStatus=='l'){
        cout<<"\n game satatus is : Lost\n";
    }


}
