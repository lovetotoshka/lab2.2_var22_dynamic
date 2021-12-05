#ifndef GET_TEMPLATES_H // ��������� #ifndef ���������, ���������� �� ��� GET_TEMPLATES_H, ���� ���, 
#define GET_TEMPLATES_H // �� ���������� ��������� ��������� #define � ������������ ��������� ������. 
//���� �� ��� GET_TEMPLATES_H ��� ����������, ���������� ��������� ��������� #endif. 
//����� �������, ����������� ����������� ������������� ����������� ������ GET_TEMPLATES_H.

#include <iostream> 
#include "Vector_Exceptions.h" 
using namespace lab3;

inline int getNum(int& a, int b, int c)
{
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		std::cout << "\t������� ����� ��������: ";
		std::cin >> a;
		if (std::cin.bad()) {
			throw Vector_Exception("Fatal Error", 1); // 
		}
		if (std::cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			std::cin.clear(); // �� ���������� cin � '�������' ����� ������
			std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			std::cout << "\tERROR!!!" << std::endl;
		}
		else {// ���� �� ������, �� �������� ������� �� �������
			if ((a < b) || (a > c)) {
				std::cin.clear(); // ���������� cin � '�������' ����� ������
				std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
				std::cout << "\tERROR!" << std::endl;
			}
			else { //�� ������
				std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
				return a;
			}
		}
	}
}
inline Vector GetVector1(Vector& vector) {
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		std::cout << "\t������� ����� ��������: ";
		std::cin >> vector;
		if (std::cin.bad()) {
			throw Vector_Exception("Fatal error during input", 1);
		}
		else if (std::cin.eof()) {
			throw Vector_Exception("EOF occured", 1);
		}
		else if (std::cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			std::cin.clear(); // �� ���������� cin � '�������' ����� ������
			std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			std::cout << "\tWrong input! Enter again" << std::endl;
		}
		else { //�� ������
			std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			break;
		}
	}
	return vector;
}

#endif
