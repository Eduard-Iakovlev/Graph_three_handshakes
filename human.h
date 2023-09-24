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
	// ���������� ���������
	void add_name(std::string name);
	// ���������� �����������
	void add_hand(int n1, int n2);
	// ����� ���� � �������
	void show();
	// ����� �����
	

private:

	// �������� ������������� �������
	bool edgeExists(int v1, int v2);
	// �������� ������������� �����
	bool vertexExists(std::string n);


	int _matrix[SIZE][SIZE]; // ������� ���������
	std::string _names[SIZE]; // ��������� ������
	int _vertexCount; // ���������� ����������� ������

};
#endif