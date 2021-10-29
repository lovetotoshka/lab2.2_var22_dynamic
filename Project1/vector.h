#ifndef VECTOR_H
#define VECTOR_H
#include <iostream> 

namespace lab3 {

	class Vector {
	private:

		int size = 0; // ������ �������
		//int i; // �������� ������ �������
		int *Array; // ��� ������
	public:
		int Get_size();
		int Get_arr_i(int i);

		Vector(): size(0), Array(new int[1]) { Array[0] = 0; }; //������ ����������� ��� ������������� ����������� � �������� ����������� ������ �� ���������;
		Vector(int E) : size(1), Array(new int[1]) { Array[0] = E; }; //�������� ����������� ������ � �������������� ������������ ��������� �������;
		Vector(int i, int* E); //�������� ����������� ������ � �������������� �������� � �������� �������� ��������� �������;

		Vector(const Vector&);//���������� �����������
		Vector(Vector&&); //������������ �����������
		~Vector() { delete[] Array;  std::cout <<"\n\tdelete\n"; };// ����������
		
		Vector& operator = (const Vector&);//������������� �������� ������������
		Vector& operator = (Vector&&);// ������������ �������� �������������

		void Print(); //����� �������� � �������� �����;
		friend std::ostream& operator << (std::ostream& out, Vector& vector);

		void Enter(); //���� ����������� ������ �� �������� ������
		friend std::istream& operator >> (std::istream&, Vector& vector);

		const Vector Add(const Vector& A); //���������� �������� �������� ���� �������� (����������� ��� �������������� �������� ���� ��������);
		const Vector operator +(const Vector& A) const;

		int operator [ ] (int k) const;
		int& operator [ ] (int k);

		const Vector Vector_slice(int item_number, int number_of_elements); //��������� ����� ������� ��������� �����, ������� � ��������, ��������� ��� ���������� ������� � �������;
		void AddNewElement(const int E); //���������� �������� ��������� � ������ ������ ��������;
		void Sort(); //������������ ������� �� �����������;
		int FindMax(); //���������� ������������� �������� � �������.
	};
}
#endif