#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class kingdom
{
private:
	string file_in_name;
	string file_out_name;
	vector <vector <int>> graph;
	int vertex;
	int link;
public:
	kingdom(string fl_in) : file_in_name(fl_in)
	{
		file_out_name = fl_in;
		file_out_name.erase(file_out_name.end() - 2, file_out_name.end());
		file_out_name = file_out_name + "out";
	};
	void read()
	{
		string buff;
		int adj_vert;
		ifstream fin("D://sec_ways//" + file_in_name);
		for (int i = 0; fin.eof(); i++)
		{
			getline(fin, buff);
			stringstream ss;
			ss << buff;
			while (ss >> adj_vert)
			{
				graph[i].push_back(adj_vert);
			}
		}
		fin.close();
	}
	void write()
	{
		ofstream fout("D://sec_ways//file_in_name//" + file_out_name);
		for (size_t i = 0; i < graph.size(); i++)
		{
			for (size_t j = 0; j < graph[i].size(); j++)
			{
				fout << graph[i][j] << ' ';
			}
			fout << endl;
		}
	}
};

int main()
{
	kingdom one("kek.in");
	one.read();
	one.write();
    return 0;
}