#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string path = "input.txt";

ifstream fin;

vector <string> getSets(string path) {
	fin.open(path);

	if (!fin.is_open())
		cout << "Open file (" + path + ") error!" << endl;

	vector <string> sets;
	int line = 0;
	while (!fin.eof()) {

		line++;
		string buff;
		getline(fin, buff);
		cout << buff << endl;
		if ((buff[2] == '{') && (buff[1] == '=') && (buff[buff.length() - 1] == '}')) {

			int opens = 0;
			int closes = 0;

			for (int i = 0; i < buff.length(); i++) {
				if (buff[i] == '{' || buff[i] == '<')
					opens++;
				if (buff[i] == '}' || buff[i] == '>')
					closes++;
			}

			if (opens != closes) {
				cout << "Check input for correctness! Line: " + to_string(line) + ", File: " + path << endl;
				cout << "Number of '<' or '{' is not equal to number of '>' or '}'" << endl;
				exit(0);
			}

			sets.push_back(buff);
		}

		else {

			cout << "Check input for correctness! Line: " + to_string(line) + ", File: " + path << endl;
			exit(0);
			break;
		}
	}
	return sets;
}


vector <vector<string>> splitSets(vector <string> sets, char delimiter) {
	int numSets = sets.size();
	vector <vector<string>> elements(numSets);

	for (int i = 0; i < numSets; i++) {

		string buff;
		buff = sets[i].substr(3, sets[i].length() - 4);
		stringstream ss(buff);
		string token;
		string element = "";
		int setOpened = 0;
		int tupleOpened = 0;

		while (getline(ss, token, delimiter)) {

			if (token[0] == '{') {

				element += token + ',';
				setOpened++;

				for (int i = 1; i < token.length(); i++) {

					if (token[i] == '{' || token[i] == '<') {

						if (token[i] == '{')
							setOpened++;
						if (token[i] == '<')
							tupleOpened++;
					}
					else break;
				}
				continue;
			}

			if (token[0] == '<') {

				element += token + ',';
				tupleOpened++;

				for (int i = 1; i < token.length(); i++) {

					if (token[i] == '{' || token[i] == '<') {
						if (token[i] == '{')
							setOpened++;
						if (token[i] == '<')
							tupleOpened++;
					}
					else break;
				}
				continue;
			}

			if (token[token.length() - 1] == '}') {

				setOpened--;
				element += token + ',';

				if (setOpened == 0 && tupleOpened == 0) {

					if (element[element.length() - 1] == ',')
						element.pop_back();

					elements[i].push_back(element);
					element = "";
				}
				continue;
			}

			if (token[token.length() - 1] == '>') {

				tupleOpened--;
				element += token + ',';

				if (setOpened == 0 && tupleOpened == 0) {

					if (element[element.length() - 1] == ',')
						element.pop_back();

					elements[i].push_back(element);
					element = "";
				}
				continue;
			}

			if (setOpened != 0 || tupleOpened != 0) {
				element += token + ',';
				continue;
			}

			if (setOpened == 0 && tupleOpened == 0) {
				elements[i].push_back(token);
			}
		}
	}
	return elements;
}


vector <string> cartesianProduct(vector <string> set1, vector <string> set2) {
	int size1 = set1.size();
	int size2 = set2.size();
	vector <string> result;

	for (int i = 0; i < set1.size(); i++) {

		for (int j = 0; j < set2.size(); j++) {
			result.push_back(set1[i] + ',' + set2[j]);
		}
	}
	return result;
}


vector <string> Result(vector <vector<string>> elements) {

	int numSets = elements.size();

	if (numSets == 1)
		return elements[0];

	vector <string> result = elements[0];

	for (int i = 1; i < numSets; i++) 
		result = cartesianProduct(result, elements[i]);
	
	return result;
}


string Print(vector <string> set) {
	string result = "";
	result += '{';

	for (int i = 0; i < set.size(); i++) {
		result += '<';
		result += set[i];
		result += '>';
		result += ',';
	}

	result[result.length() - 1] = '}';
	return result;
}


int main() {

	vector <string> sets;
	sets = getSets(path);

	vector <vector<string>> elements;
	elements = splitSets(sets, ',');

	vector <string> decart = Result(elements);
	
	cout << "\nCartesian product:  ";
	cout << Print(decart) << endl;

	return 0;
}