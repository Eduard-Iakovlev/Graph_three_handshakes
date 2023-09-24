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
// помск путей в глубину
void Human::depth(int start)
{
	bool visited[SIZE]; // список посещенных вершин
	for (int i = start; i < SIZE; i++)
		visited[i] = false; // инициализируем как непосещенные
	depthInner(start, visited); // запуск алгоритма 

	std::cout << std::endl;
}
// поиск путей в ширину
void Human::width(int start, int h)
{
	int queue_to_visit[SIZE]; // очередь вершин для обхода
	int queueCount = 0;

	bool visited[SIZE]; // список посещенных вершин
	for (int i = 0; i < SIZE; i++)
		visited[i] = false;

	queue_to_visit[queueCount++] = start; // кладем в очередь начальную вершину
	int counter = h+1;
	while (counter > 0)
	{
		// взятие из очереди вершины
		int current = queue_to_visit[0];
		queueCount--;
		for (int i = 0; i < queueCount; i++)
		{
			queue_to_visit[i] = queue_to_visit[i + 1];
		}
		visited[current] = true;
		std::cout << _names[current] << " -> "; // вывод текущей
		// поиск смежных вершин и добавление их в очередь
		for (int i = 0; i < SIZE; i++)
		{
			bool alreadyAdded = false;
			for (int j = 0; j < queueCount; j++)
				if (queue_to_visit[j] == i)
				{
					alreadyAdded = true;
					break;
				}
			if (!alreadyAdded && edgeExists(current, i) && !visited[i])
				queue_to_visit[queueCount++] = i;
		}
		counter--;
	}
	std::cout << std::endl;
}

void Human::depthInner(int current, bool visited[])
{
	std::cout << _names[current];
	if (current < SIZE-1) std::cout << " -> "; // вывод текущей
	visited[current] = true; // помечаем как посещенную
	for (int i = 0; i < SIZE; i++)
	{
		if (edgeExists(current, i) && !visited[i])
			depthInner(i, visited); // если существует ребро и вершина не посещалась, то пройдем по нему в смежную вершину

	}
}

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
