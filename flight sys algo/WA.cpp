/***********************************************************
  Group#  : 1， 2， 3........ 
  Member  : Student 1 and Student 2
  Synopsis: read from city.name and flight.txt
            store the graph in a adjacency matrix
***********************************************************/

#include <iostream>
#include <vector>
#include <ctime> 
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>

using namespace std;

class Graph{
     public:
          Graph(int d);
          ~Graph(){};

          void print();
          void addEdge(int node1, int node2){ adj[node1][node2] = 1; };
     private: 
          int n;
          int adj[140][140]; // You may want to use adjacent list implementation for sparse graph instead
};

Graph::Graph(int d){
    for (int i=0; i < d; i++){
        for (int j=0; j < d; j++){
            adj[i][j] = 0;
        }
    }
    n = d;
};

void Graph::print(){
    for (int i=0; i < n; i++){
        cout << i << " -> ";
        for (int j=0; j < n; j++){
            if (adj[i][j]){
                cout << j << " ";
            }
        }
        cout << endl;
    }

};


struct strCmp {
    bool operator()( const string s1, const string s2 ) const {
      return s1 <s2;
    }
  };


/*to map a city name with an unique integer */
//map<const string, int, strCmp> city;
map<const string, int> city;

int main(int argc, char *argv[]){
   int i,j, node1, node2,n;
   string line;


   cout << "Please enter the number of cities in your graph: " << endl;
   cout << "---------------------------------------------------" << endl;
   cin >> n;
   //n = 140;
   Graph graph(n);
 
   char lineChar[256];

   ifstream cityFile;
   cityFile.open("city.name", ios::in);

   for (i = 0; i < n; i++){
      //cityFile.getline(lineChar,256);
      std::getline(cityFile, line);
      line.erase(std::prev(line.end()));
      // printf("The city %s\n", line.c_str());
      //fflush(stdout);
      // line = lineChar;
      city[line] = i;
      //city.insert({line, i});
      // printf(" is numbered as %d\n", i);
      // printf(" is numbered as %d\n", city[line]);
      //fflush(stdout);
      //cout << line << " is numbered as city " << city[line]<< endl;
   }

   cityFile.close();
   //cityFile.open("city.name", ios::in);
   // for (i = 0; i < n; i++){
      //cityFile.getline(lineChar,256);
      // std::getline(cityFile, line);
          //if(city.find(line) != city.end()){
	  //	cout << "!!!locate!" << line << line.length() << endl;
	  //}
	  //else{
	  //	cout << "!!!NO!" << line <<  line.length() << endl;
	 // }
   //}
   // cityFile.close();
  /* initialize adjacent matrix*/
   // map<const string, int>::iterator it;
   // for(it = city.begin(); it != city.end(); it++){
        //cout << endl;
	//cout << it->first << " " << it->second << endl;	
        //cout << endl;
	/**
	if (city.find(it->first) != city.end()) {
	    cout << "Yes! locate " << it->first << endl;
	} else {
	    cout << "No!!!!! " << it->first << endl;
	}
	/**/
        // printf("%s\n %d\n",it->first.c_str(), it->second);
        //fflush(stdout);
   // }

   ifstream flightFile;
   flightFile.open("flight.txt", ios::in);

   while (flightFile.getline(lineChar, 256)){
      /* if line constains From: */
      line = lineChar;

      if (line.find("From:", 0) == 0 ){
          line.erase(0,7);
	  printf("%s\n", line.c_str());
          if(city.find(line) != city.end()){
	  	cout << "locate!" << line <<  line.length() << endl;
	  }
	  else{
	  	cout << "NO!" << line <<  line.length() << endl;
	  }
	  //cout << line << " " << city[line] << endl;
          node1 = city[line];
      } else {
          line.erase(0,7);
          node2 = city[line];
          graph.addEdge(node1,node2);
      }
   }
   flightFile.close();

   /* print the graph */
   cout << endl << "The graph generated can be represented by the following adjacent matrix : " << endl;
   cout << "-----------------------------------------------------------------------------------" << endl;
   graph.print();
}
