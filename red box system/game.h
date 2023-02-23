//game.h

#include<string>
#include"Ent_item.h"
using namespace std;

class game :public Ent_item 
{
    private:
    string game_rating;
    double game_Genre;
    string game_title;
    string game_Realesedate;
    string Studio;
    string rentalcost;
    float Replacement_Cost;


    public:
    game();
    
    game(string grating, double ggenre, string gtitle, string grealeasedate, string gstudio, string grentalcost,float gReplacement_Cost);

    void setgamerating(string gamerating);
    void setgamegenre(double gamegenre);
    void setgametitle(string gametitle);
    void setgame_Realesedate(string gRealesedate);
    void setgameStudio(string gameStudio);
    void setgamerentalcost(string gamerentalcost);
    void setgameReplacement_Cost(float gameReplacement_Cost);

    /**/
    string getgamerating();
    double getgamegenre();
    string getgametitle();
    string getgame_Realesedate();
    string getgameStudio();
    string getgamerentalcost();
    float getgameReplacement_Cost();
    void printItem();
  //  ~game();
};
