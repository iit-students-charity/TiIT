#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>

using namespace std;

void Transfers(vector<string>* graph, string* transstr)
{
	graph[5].push_back(transstr[1]);
	graph[6].push_back(transstr[1]);
	graph[6].push_back("ФРУНЗЕНСКАЯ");
	graph[6].push_back(transstr[6]);
	graph[6].push_back(transstr[7]);
	graph[25].push_back(transstr[0]);
	graph[26].push_back(transstr[0]);
	graph[7].push_back(transstr[1]);
	graph[7].push_back(transstr[3]);
	graph[8].push_back(transstr[5]);
	graph[8].push_back(transstr[10]);
	graph[8].push_back(transstr[11]);
	graph[8].push_back(transstr[6]);
	graph[8].push_back(transstr[7]);
	graph[8].push_back(transstr[3]);
	graph[51].push_back(transstr[2]);
	graph[9].push_back(transstr[5]);
	graph[9].push_back(transstr[10]);
	graph[9].push_back(transstr[11]);
	graph[9].push_back(transstr[3]);
	graph[10].push_back(transstr[5]);
	graph[9].push_back(transstr[8]);
	graph[9].push_back(transstr[9]);
	graph[42].push_back(transstr[4]);
	graph[52].push_back(transstr[6]);
	graph[27].push_back(transstr[7]);
	graph[28].push_back(transstr[9]);
	graph[29].push_back(transstr[9]);
	graph[43].push_back(transstr[8]);
	graph[41].push_back(transstr[11]);
	graph[50].push_back(transstr[10]);
	graph[26].push_back("ПУШКИНСКАЯ");
	graph[26].push_back("БАЛТИЙСКАЯ");
	graph[26].push_back(transstr[7]);
	graph[27].push_back(transstr[0]);
	graph[27].push_back(transstr[2]);
	graph[27].push_back(transstr[3]);
	graph[27].push_back(transstr[9]);
	graph[27].push_back("СПОРТИВНАЯ");
	graph[28].push_back(transstr[7]);
	graph[28].push_back(transstr[4]);
	graph[28].push_back(transstr[5]);
	graph[28].push_back("ВАСИЛЕОСТРОВСКАЯ");
	graph[40].push_back(transstr[11]);
	graph[41].push_back("НОВОЧЕРКАССКАЯ");
	graph[41].push_back(transstr[2]);
	graph[41].push_back(transstr[3]);
	graph[41].push_back(transstr[4]);
	graph[42].push_back(transstr[11]);
	graph[42].push_back(transstr[8]);
	graph[42].push_back(transstr[2]);
	graph[42].push_back(transstr[3]);
	graph[42].push_back("ЧЕРНЫШЕВСКАЯ");
	graph[43].push_back(transstr[7]);
	graph[43].push_back(transstr[6]);
	graph[43].push_back("ГОРЬКОВСКАЯ");
	graph[43].push_back(transstr[4]);
	graph[44].push_back(transstr[8]);
	graph[49].push_back(transstr[10]);
	graph[50].push_back(transstr[4]);
	graph[50].push_back(transstr[3]);
	graph[50].push_back(transstr[2]);
	graph[50].push_back("ЕЛИЗАРОВСКАЯ");
	graph[51].push_back(transstr[10]);
	graph[51].push_back(transstr[6]);
	graph[51].push_back(transstr[5]);
	graph[51].push_back(transstr[4]);
	graph[51].push_back("ПУШКИНСКАЯ");
	graph[52].push_back(transstr[8]);
	graph[52].push_back(transstr[9]);
	graph[52].push_back(transstr[0]);
	graph[52].push_back(transstr[1]);
	graph[52].push_back(transstr[2]);
	graph[53].push_back(transstr[6]);
}
const int SIZE = 56;
void Print(vector<string>* graph, int vertex)
{
	for (int i = 0; i < vertex; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			cout << graph[i][j] << "   ";
		}

		cout << endl;
	}
}


void GetNames(string path, string* names, int* counter)
{
	ifstream fin;

	fin.open(path);

	int numLines;

	string str;

	fin >> numLines;

	getline(fin, str);

	for (int i = 0; i < numLines; i++)
	{
		getline(fin, str);
		names[*counter] = str;
		(*counter)++;
	}

	fin.close();
}


void Scan(string path, vector<string>* graph, string* names, int* counter)
{
	ifstream fin;

	fin.open(path);

	int numLines;

	fin >> numLines;

	graph[*counter].push_back(names[(*counter) + 1]);


	for (int i = (*counter) + 1; i < (*counter) + numLines - 1; i++)
	{
		graph[i].push_back(names[i - 1]);
		graph[i].push_back(names[i + 1]);
	}

	graph[(*counter) + numLines - 1].push_back(names[(*counter) + numLines - 2]);

	(*counter) += numLines;

	fin.close();

}

int IntIndex(string* names, string station, int SIZE = 56)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (names[i] == station)
		{
			return i;
		}
	}
}


void SpbMetro(string pathIn,string pathOut, string *names, vector<string>* graph)
{
	ifstream input;

	string firStat, v, secStat;

	input.open(pathIn);

	getline(input, firStat);

	getline(input, secStat);

	input.close();

	bool used[SIZE];

	int dist[SIZE];

	for (int i = 0; i < SIZE; i++)
		used[i] = false;

	//for (int i = 0; i < SIZE; i++)
		//dist[i] = -1;                   

	queue<string> q;

	q.push(firStat);

	used[IntIndex(names, firStat)] = true;

	dist[IntIndex(names, firStat)] = 0;

	while (!q.empty()) {

		firStat = q.front();

		q.pop();

		for (int i = 0; i < graph[IntIndex(names, firStat)].size(); i++) {

			string v = graph[IntIndex(names, firStat)][i];

			if (!used[IntIndex(names, v)]) {

				used[IntIndex(names, v)] = true;

				dist[IntIndex(names, v)] = dist[IntIndex(names, firStat)] + 1;

				q.push(v);
			}
		}
	}

	int answer;

	ifstream finswer;

	finswer.open(pathOut);

	finswer >> answer;

	if (answer == dist[IntIndex(names, secStat)])
		cout << "Right answer!" << endl;
	else
		cout << "Wrong Answer" << endl;

}

int main()
{
	setlocale(LC_ALL, "Russian");

	string lines[4] = { "line1", "line2", "line3", "line4" };

	vector<string> graph[SIZE];

	string names[SIZE];

	int counter = 0;

	for (int i = 0; i < 4; i++)
		GetNames(lines[i], names, &counter);

	counter = 0;

	for (int i = 0; i < 4; i++)
		Scan(lines[i], graph, names, &counter);

	ifstream trans;

	trans.open("transfers");

	string transstr[12];

	counter = 0;

	GetNames("transfers", transstr, &counter);

	Transfers(graph, transstr);

	string testIn[97] = { "1", "18", "10", "96", "25" };

	string testOut[97] = { "1.a", "18.a", "10.a", "96.a", "25.a" };

	for (int i = 0; i < 5; i++)
	{
		SpbMetro(testIn[i], testOut[i], names, graph);
	}

	/*
	for (int i = 0; i < 97; i++)
	{
		stringstream ss;
		ss << i;
		testIn[i] = ss.str();
	}

	string a = ".a";

	string testOut[97];

	for (int i = 0; i < 97; i++)
	{
		stringstream ss;
		ss << i;
		testOut[i] = ss.str() + a;
	}

	*/
	return 0;
}