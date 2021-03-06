#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
private:
	static const auto max_vertex = 50;
	string file;
	int vertex;
	int cycle_st;
	int cycle_end;
	vector <int> graph[max_vertex];
	vector <int> color;
	vector <int> ancestor;
	vector <int> cycle;
	bool dfs(int v, int anc, int cnt)
	{
		color[v] = 1;
		for (size_t i = 0; i < graph[v].size(); i++)
		{
			int to = graph[v][i];
			if (color[to] == 0 && to != anc)
			{
				ancestor[cnt] = v;
				if (dfs(to, v, cnt + 1))
				{
					return true;
				}
			}
			else if (color[to] == 1 && to != anc)
			{
				cycle_end = v;
				cycle_st = to;
				color.assign(vertex, 0);
				return true;
			}
		}
		ancestor.assign(vertex, -1);
		color.assign(vertex, 0);
		return false;
	}
	void find_cycle()
	{
		ancestor.assign(vertex, -1);
		color.assign(vertex, 0);
		cycle.clear();
		cycle_st = -1;
		for (int i = 0; i < vertex; ++i)
		{
			if (dfs(i, i, 0))
			{
				break;
			}
		}
		if (cycle_st != -1)
		{
			size_t cnt = 0;
			while (ancestor[cnt] != cycle_st && cnt != ancestor.size() - 1)
			{
				cnt++;
			}
			for (size_t i = cnt; i < ancestor.size(); i++)
			{
				if (ancestor[i] != -1)
				{
					cycle.push_back(ancestor[i]);
				}
			}
			cycle.push_back(cycle_end);
		}
	}
	void delete_v(int v)
	{
		for (int i = 0; i < vertex; i++)
		{
			for (size_t j = 0; j < graph[i].size(); j++)
			{
				if (graph[i][j] == v)
				{
					graph[i].erase(graph[i].begin() + j);
				}
			}
		}
		graph[v].clear();
	}
	bool hinge(int v)
	{
		find_cycle();
		for (size_t i = 0; i < graph[v].size(); i++)
		{
			int com_flag = 0;
			for (size_t j = 0; j < cycle.size(); j++)
			{
				int flag;
				if (graph[v][i] == cycle[j])
				{
					flag = 1;
				}
				else
				{
					flag = 0;
				}
				com_flag += flag;
			}
			if (com_flag == 0)
			{
				return true;
			}
		}
		return false;
	}
public:
	Graph(string fl) : file(fl) {};
	void scan()
	{
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
				graph[vertex].push_back(link);
			}
			vertex++; 
		}
		fin.close();
	}
	void print()
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
	void tree()
	{
		find_cycle();
		struct lnks
		{
			int v;
			int cnt;
		};
		vector <lnks> links;
		vector <int> min_tree_vertex;
		for (int i = 0; i < vertex; i++)
		{
			lnks temp;
			temp.v = i;
			temp.cnt = graph[i].size();
			links.push_back(temp);
		}
		for (int i = 1; i < vertex; i++)
		{
			for (size_t j = 0; j < vertex - i; j++)
			{
				if (links[j].cnt < links[j + 1].cnt)
				{
					lnks temp = links[j];
					links[j] = links[j + 1];
					links[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < links.size(); i++)
		{
			if (!hinge((links[i].v)))
			{
				delete_v(links[i].v);
				min_tree_vertex.push_back(links[i].v);
			}
		}
		for (size_t i = 0; i < min_tree_vertex.size(); i++)
		{
			cout << min_tree_vertex[i] << " ";
		}
	}
};

int main()
{
	Graph one("graph_1.txt");
	one.scan();
	one.print();
	cout << endl;
	one.tree();
	cout << endl;
	system("pause");
	system("cls");
	Graph two("graph_2.txt");
	two.scan();
	two.print();
	cout << endl;
	two.tree();
	cout << endl;
	system("pause");
	system("cls");
	Graph three("graph_3.txt");
	three.scan();
	three.print();
	cout << endl;
	three.tree();
	cout << endl;
	system("pause");
	system("cls");
	Graph four("graph_4.txt");
	four.scan();
	four.print();
	cout << endl;
	four.tree();
	cout << endl;
	system("pause");
	system("cls");
	Graph five("graph_5.txt");
	five.scan();
	five.print();
	cout << endl;
	five.tree();
	cout << endl;
	system("pause");
	system("cls");
    return 0;
}