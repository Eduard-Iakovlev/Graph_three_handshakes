#include "human.h"

Human::Human()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			_matrix[i][j] = 0;
	_vertexCount = 0;
}

// ���������� ���������
void Human::add_name(std::string name)
{
	_names[_vertexCount] = name;
	_vertexCount++;
}

// ���������� �����������
void Human::add_hand(int n1, int n2)
{
	_matrix[n1-1][n2-1] = 1;
	_matrix[n2-1][n1-1] = 1;
}

// ����� ���� � �������
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
// ����� �����

// �������� ������������� �����
bool Human::edgeExists(int v1, int v2)
{
	return _matrix[v1][v2] != 0;
}
// �������� ������������� �������
bool Human::vertexExists(std::string n)
{
	for (int i = 0; i < _vertexCount; i++)
		if (_names[i] == n) return true;
	return false;
}
