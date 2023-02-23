#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
/***********************************************************
  Group#  : 10
  Member  : Fatima Shibli, and Manoj Gurung
  Synopsis: read from city.name and flight.txt
			store the graph in an adjacency matrix
***********************************************************/

using namespace std;
#define INF INT_MAX
using namespace std;

class Graph
{
public:
	Graph() {};
	~Graph() {};
	void print()
	{
		for (int i = 0; i < cities.size(); i++)
		{
			cout << cities[i] << " -> ";
			for (int j = 0; j < cities.size(); j++)
			{
				if (adjMat[i][j])
				{
					cout << cities[j] << " ";
				}
			}
			cout << endl;
		}
	}
	void addCity(string name)
	{
		if (!(find(cities.begin(), cities.end(), name) != cities.end()))
		{
			cities.push_back(name);
			for (int i = 0; i < adjMat.size(); i++)
			{
				adjMat[i].push_back(INF);
				distanceFloyd[i].push_back(0);
			}
			vector<int> v(cities.size(),INF);
			adjMat.push_back(v);
			vector<int> v1(cities.size(), 0);
			distanceFloyd.push_back(v1);
			for (size_t i = 0; i < cities.size(); i++)
			{
				adjMat[i][i] = 0;
			}
		}
	}
	void addConnection(string c1, string c2)
	{
		int i1, i2;
		auto it1 = find(cities.begin(), cities.end(), c1);
		if (!(it1 != cities.end()))
			addCity(c1);

		auto it2 = find(cities.begin(), cities.end(), c2);
		if (!(it2 != cities.end()))
			addCity(c2);

		it1 = find(cities.begin(), cities.end(), c1);
		i1 = distance(cities.begin(), it1);
		

		it2 = find(cities.begin(), cities.end(), c2);
		i2 = distance(cities.begin(), it2);
		i2 = it2 - cities.begin();

		
		addEdge(i1, i2);
	}

	void addEdge(int node1, int node2)
	{

		adjMat[node1][node2] = 1;
		
	}

	int n;
	vector<vector<int>> adjMat = {};
	vector<vector<int>> distanceFloyd = {};
	vector<string> cities = {};

};

Graph graph;

int getCityIndex(string s)
{
	int i;
	for (i = 0; i < graph.cities.size(); i++)
	{
		if (s.compare(graph.cities[i]) == 0) {
			return i;
			break;
		}
	}
	cout << "error in finding city: '" << s << "'  Aborting! " << endl;
	return -1;
}

void DFS(int i, int j, int x, vector<int> route, vector<int>& minroute, vector<bool>& visited)
{
	if (i == j)
	{
		if (minroute.size() == 0 || minroute.size() > route.size())
		{
			minroute.assign(route.begin(), route.end());
		}
		return;
	}
	if (route.size() == x + 1)
	{
		return;
	}
	for (int k = 0; k < graph.cities.size(); k++)
	{
		if (k != i && graph.adjMat[i][k] == 1 && visited[k] == false)
		{
			visited[k] = true;
			route.push_back(k);
			DFS(k, j, x, route, minroute, visited);
			visited[k] = false;
			route.pop_back();
		}
	}
}

bool contains(vector<int> route, int k, int l)
{
	return (find(route.begin(), route.end(), k) != route.end()) && (find(route.begin(), route.end(), l) != route.end());
}

void DFS2(int i, int j, int m, int n, vector<int> route, vector<int>& minroute, vector<bool>& visited)
{
	if (i == j && contains(route, m, n))
	{
		if (minroute.size() == 0 || minroute.size() > route.size())
		{
			minroute.assign(route.begin(), route.end());
		}
		return;
	}
	for (int k = 0; k < graph.cities.size(); k++)
	{
		if (k != i && graph.adjMat[i][k] == 1 && visited[k] == false)
		{
			visited[k] = true;
			route.push_back(k);
			DFS2(k, j, m, n, route, minroute, visited);
			visited[k] = false;
			route.pop_back();
		}
	}
}



void validConnect(int A, int B, int x)
{
	if (A == graph.cities.size() || B == graph.cities.size())
	{
		cout << "Atleast one of the city names is wrong!!" << endl;
		return;
	}
	vector<bool> visited(graph.cities.size());
	vector<int> route;
	vector<int> minroute;
	for (int i = 0; i < graph.cities.size(); i++)
	{
		visited[i] = false;
	}
	visited[A] = true;
	route.push_back(A);
	DFS(A, B, x, route, minroute, visited);
	route.pop_back();
	visited[A] = false;
	int minpath = minroute.size();
	if (minpath != 0)
	{
		for (int i = 0; i < minpath - 1; i++)
		{
			cout << graph.cities[minroute[i]] << " -> ";
		}
		cout << graph.cities[minroute[minpath - 1]];
	}
}

void getroute(string c1, string c2, string c3, string c4)
{
	int A = getCityIndex(c1);
	int B = getCityIndex(c2);
	int C = getCityIndex(c3);
	int D = getCityIndex(c4);
	if (A == graph.cities.size() || B == graph.cities.size() || C == graph.cities.size() || D == graph.cities.size())
	{
		cout << "Atleast one of the city names is wrong!!" << endl;
		return;
	}
	vector<bool> visited(graph.cities.size());
	vector<int> route;
	vector<int> minroute;
	for (int i = 0; i < graph.cities.size(); i++)
	{
		visited[i] = false;
	}
	visited[A] = true;
	route.push_back(A);
	DFS2(A, B, C, D, route, minroute, visited);
	route.pop_back();
	visited[A] = false;
	int minpath = minroute.size();
	if (minpath != 0)
	{
		cout << "Yes! You can do so via route: ";
		for (int i = 0; i < minpath - 1; i++)
		{
			cout << graph.cities[minroute[i]] << " -> ";
		}
		cout << graph.cities[minroute[minpath - 1]] << endl;
	}
	else
	{
		cout << "No! You can't fly as no such route exists." << endl;
	}
}
void floydWarshall()
{
	int i, j, k;
	for (i = 0; i < graph.cities.size(); i++)
		for (j = 0; j < graph.cities.size(); j++)
		{

			int a = graph.adjMat[i][j];
			graph.distanceFloyd[i][j] = a;
		}
	for (k = 0; k < graph.cities.size(); k++)
	{
		// Pick all cities as source one by one
		for (i = 0; i < graph.cities.size(); i++)
		{
			// Pick all cities as destination for the above picked source
			for (j = 0; j < graph.cities.size(); j++)
			{ // updating closure matrix
				if (graph.distanceFloyd[i][j] > (graph.distanceFloyd[i][k] + graph.distanceFloyd[k][j]) && (graph.distanceFloyd[k][j] != INF && graph.distanceFloyd[i][k] != INF))
					graph.distanceFloyd[i][j] = graph.distanceFloyd[i][k] + graph.distanceFloyd[k][j];
			}
		}
	}
}
int shortest(int a, int b, int c)
{

	vector<int> d1(graph.cities.size()), d2(graph.cities.size()), d3(graph.cities.size());
	for (size_t i = 0; i < graph.cities.size(); i++)
	{
		// init 3 arrays for holding distance from 3 cities to all cities
		d1[i] = graph.distanceFloyd[a][i];
		d2[i] = graph.distanceFloyd[b][i];
		d3[i] = graph.distanceFloyd[c][i];
	}

	int sum = INF;
	int select = -1;
	// find lowest sum of distance fomr each city to a single city
	for (int i = 0; i < graph.cities.size(); i++)
	{
		if (d1[i] >= INF || d2[i] >= INF || d3[i] >= INF)
			continue;
		if (d1[i] + d2[i] + d3[i] < sum)
		{
			sum = d1[i] + d2[i] + d3[i];
			select = i;
		}
	}
	cout << "shortest would be to meet at " << graph.cities[select] << endl;
	cout << "Route for first person:   ";
	validConnect(a, select, graph.cities.size());
	cout << " ( " << d1[select] << " connections)" << endl;
	cout << "Route for second person:  ";
	validConnect(b, select, graph.cities.size());
	cout << " ( " << d2[select] << " connections)" << endl;
	cout << "Route for third person:  ";
	validConnect(c, select, graph.cities.size());
	cout << " ( " << d3[select] << " connections)" << endl;

	return select;
}
vector<int> path;

int shorts (int a, int b, int c, int d)
{

	vector<int> D1(graph.cities.size()), D2(graph.cities.size()), D3(graph.cities.size()), D4(graph.cities.size());
	for (size_t i = 0; i < graph.cities.size(); i++)
	{
		// init 4  arrays for holding distance from 3 cities to all cities
		D1[i] = graph.distanceFloyd[a][i];
		D2[i] = graph.distanceFloyd[b][i];
		D3[i] = graph.distanceFloyd[c][i];
		D4[i] = graph.distanceFloyd[d][i];
	}

	int sum = INF;
	int select = -1;
	// find lowest sum of distance fomr each city to a single city
	for (int i = 0; i < graph.cities.size(); i++)
	{
		if (D1[i] >= INF || D2[i] >= INF || D3[i] >= INF || D4[i] >= INF)
			continue;
		if (D1[i] + D2[i] + D3[i] + D4[i] < sum)
		{
			sum = D1[i] + D2[i] + D3[i] + D4[i];
			select = i;
		}
	}
	cout << "shortest path would be: " << graph.cities[select] << endl;
	validConnect(a, select, graph.cities.size());
	cout << " ( " << D1[select] << " connections)" << endl;
	validConnect(b, select, graph.cities.size());
	cout << " ( " << D2[select] << " connections)" << endl;
	validConnect(c, select, graph.cities.size());
	cout << " ( " << D3[select] << " connections)" << endl;
	validConnect(d, select, graph.cities.size());
	cout << " ( " << D4[select] << " connections)" << endl;

	return select;
}

void displayCycle() {
	cout << " Following is the (hamiltotian) cycle of connections: "<<endl;

	for (int i = 0; i < graph.cities.size(); i++)
		cout<< " " << graph.cities[path[i]] << " -> ";
	cout << graph.cities[path[0]] << endl;      //print the first vertex again
}

bool isValid(int v, int k) {
	if (graph.adjMat[path[k - 1]][v] == 0 || graph.adjMat[path[k - 1]][v] == INF)   //if there is no edge
		return false;

	for (int i = 0; i < k; i++)   //if vertex is already taken, skip that
		if (path[i] == v)
			return false;
	return true;
}

bool cycleFound(int k) {
	if (k == graph.cities.size()) {             //when all vertices are in the path
		if (graph.adjMat[path[k - 1]][path[0]] == 1)
			return true;
		else
			return false;
	}

	for (int v = 1; v < graph.cities.size(); v++) {       //for all vertices except starting point
		if (isValid(v, k)) {                //if possible to add v in the path
			path[k] = v;
			if (cycleFound(k + 1) == true)
				return true;
			path[k] = -1;               //when k vertex will not in the solution
		}
	}
	return false;
}

bool hamiltonianCycle(int V) {
	for (int i = 0; i < graph.cities.size(); i++)
		path.push_back(-1);
	path[0] = V; //first vertex as given city

	if (cycleFound(1) == false) {
		cout << "No path possible without travelling to same city twice" << endl;
		return false;
	}

	displayCycle();
	return true;
}

int main()
{
	int i, j, node1, node2;
	string c1, c2;
	string line;
	 //n = 140;

	char lineChar[256];



	ifstream flightFile;
	flightFile.open("flight.txt", ios::in);

	while (!flightFile.eof())
	{
		getline(flightFile, line);
		/* if line constains From: */
		if (line.find("From:", 0) == 0)
		{
			line.erase(0, 7);

			int index = line.find(",");
			if (index < 0)
				continue;
			line.erase(index, line.size());
			c1 = line;
		}
		else
		{

			line.erase(0, 7);
			int index = line.find(",");
			if (index < 0)
				continue;
			line.erase(index, line.size());
			c2 = line;


			graph.addConnection(c1, c2);
		}
	}
	flightFile.close();

	/* print the graph */
	cout << endl
		<< "Available cities are" << endl;
	for (size_t i = 0; i < graph.cities.size(); i++)
	{
		cout << graph.cities[i] << endl;
	}

	

	// solution part
	cout << "Which type of query do you want an answer for?" << endl;
	cout << "1. Give me the route with the smallest number of connections or tell me there is no such a route." << endl;
	cout << "2. Give me the route with the smallest number of connections from city A to city D through city B and C." << endl;
	cout << "3. Find route to start from city A, visit all the cities that can be reached and then come back to A." << endl;
	cout << "4. Find city D such that if I am in city A, my two friends are in different city B and C, then travelling to D will have minimim no of overall connections required.  " << endl;
	cout << "5. Quit" << endl;
	int ch;
	while (1)
	{
		cout << "\nEnter your choice: ";
		cin >> ch;
		if (ch == 1)
		{
			string c1, c2;
			cout << "City A: ";
			cin.ignore();
			std::getline(cin, c1);
			cout << "City B: ";
			std::getline(cin, c2);
			cout << "Number of connections: ";
			int x;
			cin >> x;
			int A = getCityIndex(c1);
			int B = getCityIndex(c2);
			validConnect(A, B, x);
		}
		else if (ch == 2)
		{
			floydWarshall(); // calc distance from each city to each other city and store in Weighted Adjacency Matrix
			string A, B, C, D;
			cin.ignore();
			cout << "First City (A): ";
			getline(cin, A);
			cout << "Last City (D): ";
			getline(cin, D);
			cout << " Cities in between (B): ";
			getline(cin, B);
			cout << " Cities in between (C): ";
			getline(cin, C);
			int a = getCityIndex(A);
			int b = getCityIndex(B);
			int c = getCityIndex(C);
			int d = getCityIndex(D);
			if (a == -1 || b == -1 || c == -1 || d == -1)
			{
				break;
			}
			int select = shorts(a, b, c, d);
		}
		else if (ch == 3)
		{
			cin.ignore();
			string A;
			cout << "City to start: ";
			getline(cin, A);
			int a = getCityIndex(A);
			hamiltonianCycle(a);
		}
		else if (ch == 4)
		{
			floydWarshall(); // calc distance from each city to each other city and store in Weighted Adjacency Matrix
			string A, B, C, D;
			cin.ignore();
			cout << "First City (A): ";
			getline(cin, A);
			cout << "Second City (B): ";
			getline(cin, B);
			cout << "Third (C): ";
			getline(cin, C);
			int a = getCityIndex(A);
			int b = getCityIndex(B);
			int c = getCityIndex(C);
			if (a == -1 || b == -1 || c == -1)
			{
				break;
			}
			int select = shortest(a, b, c);
		}
		else if (ch == 5)
		{
			 graph.print();
			break;
		}else{
            cout<< "invalid option, please try again!!"<<endl;
			break;
            
        }

	}
	return 0;
}//End of Program
