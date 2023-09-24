#pragma once
#include <vector>
#define VERYBIGINT 1000000000
#include <iostream>
#include <string>

#ifndef __GRAPH__
#define __GRAPH__
#define SIZE 10



class Human {
public:
	Human();
	// добавление участника
	void add_name(std::string name);
	// добавление рукопожатия
	void add_hand(int n1, int n2);
	// вывод сети в консоль
	void show();
	// поиск путей
	

private:

	// проверка существования вершины
	bool edgeExists(int v1, int v2);
	// проверка существования ребра
	bool vertexExists(std::string n);


	int _matrix[SIZE][SIZE]; // матрица смежности
	std::string _names[SIZE]; // хранилище вершин
	int _vertexCount; // количество добавленных вершин

};
#endif