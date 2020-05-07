// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <random>
#include <iterator> 


#define N 100

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(1, N);
uniform_real_distribution<> distR(1, N);

void CreateSet(set<int> *_set, int size)
{
	int a;

	for (int i = 0; i < size; i++)
	{
		 a = dist(gen);
		_set->insert(a);
	}
};


void CreateMap(map<int, double> *_map, int size)
{
	int a;
	double b;

	for (int i = 0; i < size; i++)
	{
		a = dist(gen);
		b = distR(gen);
		_map->insert(pair<int, double>(b, a));
	}
};

int main()
{
	ostream_iterator<int> ositer(cout, ", ");

	set<int> dSet;
	map <int, double> strMap;

	CreateSet(&dSet, 10);

	copy(dSet.begin(), dSet.end(), ositer);

	cout << endl << "Value of element to remove: ";
	int num;
	cin >> num;
	if (dSet.find(num) != dSet.end())
	{
		dSet.erase(num);
	}
	else
		cout << endl << "There is no it in set";
	copy(dSet.begin(), dSet.end(), ositer);
	cout << endl<< endl;

	CreateMap(&strMap, 10);
	map <int, double> ::iterator it = strMap.begin();
	for (int i = 0; it != strMap.end(); it++, i++)
		cout << it->first << " : " << it->second << endl;

	cout << endl << "Key of element to remove: ";
	cin >> num;
	it = strMap.find(num);
	if (it != strMap.end())
	{
		strMap.erase(it);
		it = strMap.begin();
		for (int i = 0 ; it != strMap.end(); it++, i++)
			cout << it->first << " : " << it->second << endl;
	}
	else
		cout << endl << "There is no it in map";
}

