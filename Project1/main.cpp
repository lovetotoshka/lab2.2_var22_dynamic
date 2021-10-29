#include "Vector_dialog.h" 
#include "Vector_Exceptions.h" 
using namespace lab3;

int main() {
	setlocale(LC_ALL, "Russian");

	Vector vector;
	int choice = 0;
	int first_create = 1;
	while (1)
	{
		try
		{
			if (first_create == 1) {
				Dialogs[0](vector);
				first_create = 0;
			}

			choice = Dialog_Main();
			if (choice == 0)
			{
				break;
			}
			Dialogs[choice - 1](vector);
		}
		catch (Vector_Exception& ex)
		{
			std::cout << ex << std::endl;
			if (ex.Fatal())
			{
				vector.~Vector();
				return -1;
			}
		}
		catch (std::bad_alloc& ex)
		{
			std::cout << ex.what() << std::endl;
			vector.~Vector();
			return -1;
		}
	}
	return 0;
}
/*
#include "vector.h"
#include <iostream>
using namespace lab3;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	try
	{
		const char* msgs[] = {
				"\t===========================================",
				"\t0 - Выход",
				"\t1 - Создать вектор ",
				"\t2 - Вывести вектор ",
				"\t3 - Сложить два вектора",
				"\t4 - Получить срез вектора",
				"\t5 - Включить в вектор новый элемент ",
				"\t6 - Отсортировать вектор по возрастанию",
				"\t7 - Найти максимальный элемент в векторе",
				"\t=========================================="
		};
		Vector A = how_to_create_Vector(); // создаём вектор, с которым будем работать
		int start = 1; // start = 1, пока рользователь не решил выйти из программы
		while (start != 0) {
			for (int i = 0; i < 10; i++)
				std::cout << msgs[i] << std::endl;
			int choice;
			getNum(choice, 0, 8);
			if (choice == 0) {
				start = 0;
			}
			if (choice == 1) {
				A = how_to_create_Vector();
			}
			if (choice == 2) {
				//A.Print();
				std::cout << A;
			}
			if (choice == 3) {
				Vector B = how_to_create_Vector();
				//Vector C = A.Add(B);
				Vector C = A + B;
				if (C.Get_i() != 0)
					std::cout << C;
					//C.Print();
			}
			if (choice == 4) {
				int item_number, number_of_elements;
				std::cout << "\tВведите номер элемента, с которого хотите получить срез" << std::endl;
				getNum(item_number, 0, 30);
				std::cout << "\tВведите количество элементов" << std::endl;
				getNum(number_of_elements, 0, 30);
				A.Vector_slice(item_number, number_of_elements);
			}
			if (choice == 5) {
				std::cout << "\tКакой элемент вы хотите включить?\n\t1 - Одно значение массива \n\t2 - Новый массив значений" << std::endl;
				int what_to_add;
				getNum(what_to_add, 1, 2);
				if (what_to_add == 1) {
					//A.Enter();
					std::cin >> A;
					std::cin.ignore(32767, '\n');
				}
				if (what_to_add == 2) {
					std::cout << "\tСколько значений будет в массиве? " << std::endl;
					int size;
					getNum(size, 0, 30 - A.Get_i());
					std::cout << "\tВведите все значения массива: " << std::endl;
					for (int i = 0; i < size; i++) {
						//getNum(arr[i], -100000, 100000);
						std::cin >> A;
						std::cin.ignore(32767, '\n');
						//A.AddNewElement(arr[i]);
					}
				}
			}
			if (choice == 6) {
				A.Sort();
				//A.Print();
				std::cout << A;
			}
			if (choice == 7) {
				std::cout << "\tМаксимальный элемент: " << A.FindMax() << std::endl;
			}
		}

	}
	catch (std::exception ex)
	{
		std::cout << "\n\tОшибка 1: " << ex.what() << std::endl;
	}
	return 0;
}

*/

