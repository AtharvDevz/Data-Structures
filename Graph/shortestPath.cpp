#include<iostream>
#include<vector>
using namespace std;

class Graph
{
	vector<vector<int>> edgelist;
	vector<vector<int>> distance;
	int V;

public:
	Graph(int V)
	{
		this->V = V;
		distance.resize(V, vector<int>(V, INT_MAX));

		for (int i = 0; i < V; i++)
		{
			distance[i][i] = 0;
		}
	}

	void addEdge(int x, int y, int w)
	{
		edgelist.push_back({w, x, y});
		distance[x][y] = w;
		distance[y][x] = w;
	}

	void display(){
		for (int i = 0; i < distance.size(); i++)
		{
			for(int j=0;j<distance.size();j++){
				cout<<i<<" - "<<j<<distance[i][j]<<endl;
			}
		}
		
	}

	vector<vector<int>> floydWarshallShortestPath()
	{
		for (int i= 0; i< V;i++)
		{
			for (int j = 0; j < V; j++)
			{
				for (int k = 0; k < V; k++)
				{
					if(distance[i][k] != INT_MAX && distance[k][j] != INT_MAX)
					distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
				}
			}
		}
		return distance;
	}
};

// Driver code
int main()
{
	cout<<"Atharv";
	Graph g(5);
	g.addEdge(0, 1, 2);
	g.addEdge(0, 3, 6);
	g.addEdge(1, 3, 8);
	g.addEdge(1, 2, 3);
	g.addEdge(1, 4, 5);
	g.addEdge(2, 4, 7);

	vector<vector<int>> dist = g.floydWarshallShortestPath();
	for (int i = 0; i < dist.size(); i++)
	{
		for (int  j = 0; j < dist.size(); j++)
		{
			if(dist[i][j] != INT_MAX){
				cout<<i<<" -> "<<j<<" = "<<dist[i][j]<<endl;
			}
		}
		
	}
	
	return 0;
}