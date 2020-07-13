#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void Print(vector<int>* graph, int vertex)
{
	for (int i = 0; i < vertex; i++)
	{
		for (size_t j = 0; j < graph[i].size(); j++)
		{
			cout << graph[i][j] << " ";
		}

		cout << endl;
	}
}


inline char invert(int c)
{
	if (c == 1)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

int dfs(vector<int> *graph, char *color, int v, char c)
{
	color[v] = c;

	int t = 1;

	for (int u : graph[v])
	{
		if (color[u] == 0) 
		{   
			dfs(graph, color, u, invert(c));
		}
		else if (color[u] == c)
		{
			//cout << "Graph is not bipartite." << endl;
			t = -1;
			break;
		}
	}
	return t;
}

void scan(string file, vector<int> *graph)
{
	int i = 0;

	string str;

	int link;

	ifstream fin(file);

	while (!fin.eof())
	{
		getline(fin, str);

		stringstream ss;

		ss << str;

		while (ss >> link)
		{
			graph[i].push_back(link);
		}

		i++;
	}

	fin.close();
	
}


void Planar(string path, int number)
{
	ifstream fin1;

	fin1.open(path);

	int vertex = 0;

	int edge = 0;

	vector<int> graph[100];

	scan(path, graph);

	string str;

	while (!fin1.eof())
	{
		getline(fin1, str); 

		vertex++;
	}

	if (vertex <= 4)
	{
		cout << "\nGraph (" << number << "): is planar\n\n";
	}

	for (int i = 0; i < vertex; i++)
	{
		edge = edge + graph[i].size(); 
	}

	/*cout << "verticies (" << number << "):" << vertex << endl;

	cout << "Edges (" << number << "):" << edge << endl;

	cout << "Adjacency List (" << number<< "):" << endl;

	Print(graph, vertex); */

	char color[100];

	for (int i = 0; i < 100; i++)
	{
		color[i] = 0;
	}

	int checker = 0;

	for (int i = 0; i < vertex; i++)
	{
		if (color[i] == 0)
		{
			checker = dfs(graph, color, i, 1);
		}
	}

	if (checker == 1)
	{
		if (2 * vertex >= 4 + edge)
		{
			cout << "\nGraph (" << number << "): is planar\n\n";
		}
		else
		{
			cout << "\nGraph (" << number << "): is NOT planar\n\n";
		}
	}
	else if (edge <= 3 * vertex - 6 && vertex >= 3)
	{
		cout << "\nGraph (" << number << "): is planar\n\n";
	}
	else
	{
		cout << "\nGraph (" << number << "): is NOT planar\n\n";
	}
	
	fin1.close();

}

int main()	// 3 * Вершины - 6 >= Ребра		https://www.youtube.com/watch?v=v9lbaqTdaKQ
{
	Planar("OrGraph1.txt", 1);

	Planar("OrGraph2.txt", 2);
	
	Planar("OrGraph3.txt", 3);

	Planar("OrGraph4.txt", 4);

	Planar("OrGraph5.txt", 5); 

	return 0;
}

/*
Лекции Емеличев глава 6
Книга Diestel с.92
Книга Харари с.139
*/