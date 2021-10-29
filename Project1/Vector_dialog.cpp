#include "Vector_dialog.h" //+ vector.h
//#include "Vector_Exceptions.h" //������ �� ��������
#include "Get_Templates.h" //!!!!!!!! �������� Vector_Exceptions.h, namespace lab3

using namespace lab3;

int Dialog_Main()
{
	int choice;
	while (1)
	{
		const char* msgs[] = {
			"\n\t===========================================",
			"\t0 - �����",
			"\t1 - ������� ������ ",
			"\t2 - ������� ������ ",
			"\t3 - ������� ��� �������",
			"\t4 - �������� ���� �������",
			"\t5 - �������� � ������ ����� ������� ",
			"\t6 - ������������� ������ �� �����������",
			"\t7 - ����� ������������ ������� � �������",
			"\t=========================================="
		};
		for (int i = 0; i < 10; i++)
			std::cout << msgs[i] << std::endl;
		getNum(choice, 0, 7);
		if (choice <= 7 && choice >= 0)
			return choice;
	}

}

void Dialog_Create_vector(Vector& vector) {

	std::cout << "\t��� �� ������ ������ ������?" << std::endl;
	std::cout << "\t1 - ������� ������ ������" << std::endl;
	std::cout << "\t2 - ������� ������ � ����� ���������" << std::endl;
	std::cout << "\t3 - ������� ������ � �������� ��������" << std::endl;
	int how_create;
	getNum(how_create, 1, 3);
	if (how_create == 1) {
		Vector A;
		vector = A;
	}
	if (how_create == 2) {
		int value;
		getNum(value, -100000, 100000);
		Vector A(value);
		vector = A;
	}
	if (how_create == 3)
	{
		std::cout << "\t������� �������� ����� � �������? " << std::endl;
		int size;
		getNum(size, 0, 30);
		int arr[30];
		std::cout << "\t������� ��� �������� �������: " << std::endl;
		for (int i = 0; i < size; i++) {
			getNum(arr[i], -100000, 100000);
		}
		Vector A(size, arr);
		vector = A;
		std::cout << "\n\tVector[2] = " << vector[2] << std::endl;
		vector[1] = 0;
		std::cout << "\n\tVector[1] = " << vector[1] << std::endl;


	}
}

void Dialog_Print_Vector(Vector& vector) {
	std::cout << "\t" << vector << std::endl;
}

void Dialog_Add_Vectors(Vector& vector) {
	Vector B;
	Dialogs[0](B);
	Vector C = vector + B;
	if (C.Get_size() != 0)
		std::cout << "\tVector " << vector << " + Vector " << B << " = " << C << std::endl;
}

void Dialog_Vector_slice(Vector& A) {
	int item_number, number_of_elements;
	std::cout << "\t������� ����� ��������, � �������� ������ �������� ����" << std::endl;
	getNum(item_number, 1, 29);
	std::cout << "\t������� ���������� ���������" << std::endl;
	getNum(number_of_elements, 0, 30);
	A.Vector_slice(item_number, number_of_elements);
}

void Dialog_Add_New_element_to_vector(Vector& A) {
	std::cout << "\t����� ������� �� ������ ��������?\n\t1 - ���� �������� ������� \n\t2 - ������ ��������" << std::endl;
	int what_to_add;
	getNum(what_to_add, 1, 2);
	if (what_to_add == 1) {
		GetVector1(A);
		std::cout << A << std::endl;
	}
	if (what_to_add == 2) {
		std::cout << "\t������� �������� ����� � �������?" << std::endl;
		int size;
		getNum(size, 0, 100);
		std::cout << "\t������� ��� �������� �������: " << std::endl;
		for (int i = 0; i < size; i++)
			GetVector1(A);
	}
}

void Dialog_Vector_Sort(Vector& A) {
	A.Sort();
	std::cout << "\t" << A;
}

void Dialog_Vector_Find_Max(Vector& A) {
	std::cout << "\t������������ �������: " << A.FindMax() << std::endl;
}
