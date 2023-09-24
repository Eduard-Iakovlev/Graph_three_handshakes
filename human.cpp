#include "human.h"

Human::Human()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			_matrix[i][j] = 0;
	_vertexCount = 0;
}

// добавление участника
void Human::add_name(std::string name)
{
	_names[_vertexCount] = name;
	_vertexCount++;
}

// добавление рукопожатия
void Human::add_hand(int n1, int n2)
{
	_matrix[n1-1][n2-1] = 1;
	_matrix[n2-1][n1-1] = 1;
}

// вывод сети в консоль
void Human::show()
{
	std::cout << "       ";
	for (int i = 0; i < SIZE; i++) std::cout << _names[i] << "   ";
	std::cout << "\n";
	for (int i = 0; i < SIZE; i++) {
		std::cout << _names[i] << "     ";
		for (int j = 0; j < SIZE; j++) {
			std::cout << _matrix[i][j] << "      ";
		}
		std::cout << "\n";
	}
}
// помск путей

// проверка существования ребра
bool Human::edgeExists(int v1, int v2)
{
	return _matrix[v1][v2] != 0;
}
// проверка существования вершины
bool Human::vertexExists(std::string n)
{
	for (int i = 0; i < _vertexCount; i++)
		if (_names[i] == n) return true;
	return false;
}
