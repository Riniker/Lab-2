// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <set>
#include <map>
#include <random>
#include <iterator> 
#include <algorithm>

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

void IncreaseByFirst(set<int> *_set)
{
	set<int>::iterator iter = _set->begin();
	set<int> set;
	int fEl = *iter;
	set.insert(*iter);
	iter++;
	for (int i = 1; i < _set->size(); i++, iter++)
	{
		set.insert(*iter + fEl);
	}
	_set->clear();
	_set->swap(set);
}

void ReplaceByFirst(map<int, double> *_map)
{
	map<int, double>::iterator iter = _map->begin();
	map<int, double>::iterator iter2 = _map->begin();
	int first = iter->second;
	iter++;
	for (int i = 1; i < _map->size(); i++, iter++)
	{
		if (iter2->second < iter->second)
		{
			 iter2 = iter;
		}
	}
	cout << "Biggest: " << iter2->first << " : " << iter2->second << endl;
	iter2->second = first;
}

bool compare(int a, int b)
{
	return (a < b);
}

int main()
{
	ostream_iterator<int> ositer(cout, ", ");

	set<int> dSet;
	map <int, double> strMap;

	CreateSet(&dSet, 10);

	set<int>::iterator iter = dSet.begin();


	copy(dSet.begin(), dSet.end(), ositer);

	cout << endl << "Value of element to remove: ";
	int num;
	cin >> num;
	if (dSet.find(num) != dSet.end())
	{
		dSet.erase(num);
	}
	else
		cout << endl << "There is no it in set" << endl;
	copy(dSet.begin(), dSet.end(), ositer);
	iter = dSet.begin();
	cout << endl << "Number of element to remove: ";
	cin >> num;
	if (dSet.size() + 1 > num)
	{
		for (int i = 0; i < num - 1; i++)
			iter++;
		num = *iter;
		dSet.erase(num);
		copy(dSet.begin(), dSet.end(), ositer);
	}
	else cout << "Your number is too big";

	IncreaseByFirst(&dSet);
	cout << endl << "Increased" << endl;
	copy(dSet.begin(), dSet.end(), ositer);
	cout << endl << endl;

	CreateMap(&strMap, 10);
	map <int, double> ::iterator it = strMap.begin();
	for (int i = 0; it != strMap.end(); it++, i++)
		cout << it->first << " : " << it->second << endl;

	ReplaceByFirst(&strMap);

	cout << "Replaced" << endl;
	it = strMap.begin();
	for (int i = 0; it != strMap.end(); it++, i++)
		cout << it->first << " : " << it->second << endl;

}

