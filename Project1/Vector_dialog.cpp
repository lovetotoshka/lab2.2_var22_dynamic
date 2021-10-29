#include "Vector_dialog.h" //+ vector.h
//#include "Vector_Exceptions.h" //ничего не вызывает
#include "Get_Templates.h" //!!!!!!!! вызывает Vector_Exceptions.h, namespace lab3

using namespace lab3;

int Dialog_Main()
{
	int choice;
	while (1)
	{
		const char* msgs[] = {
			"\n\t===========================================",
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
		for (int i = 0; i < 10; i++)
			std::cout << msgs[i] << std::endl;
		getNum(choice, 0, 7);
		if (choice <= 7 && choice >= 0)
			return choice;
	}

}

void Dialog_Create_vector(Vector& vector) {

	std::cout << "\tКак вы хотите задать вектор?" << std::endl;
	std::cout << "\t1 - Создать пустой вектор" << std::endl;
	std::cout << "\t2 - Создать вектор с одним элементом" << std::endl;
	std::cout << "\t3 - Создать вектор с массивом значений" << std::endl;
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
		std::cout << "\tСколько значений будет в массиве? " << std::endl;
		int size;
		getNum(size, 0, 30);
		int arr[30];
		std::cout << "\tВведите все значения массива: " << std::endl;
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
	std::cout << "\tВведите номер элемента, с которого хотите получить срез" << std::endl;
	getNum(item_number, 1, 29);
	std::cout << "\tВведите количество элементов" << std::endl;
	getNum(number_of_elements, 0, 30);
	A.Vector_slice(item_number, number_of_elements);
}

void Dialog_Add_New_element_to_vector(Vector& A) {
	std::cout << "\tКакой элемент вы хотите включить?\n\t1 - Одно значение массива \n\t2 - Массив значений" << std::endl;
	int what_to_add;
	getNum(what_to_add, 1, 2);
	if (what_to_add == 1) {
		GetVector1(A);
		std::cout << A << std::endl;
	}
	if (what_to_add == 2) {
		std::cout << "\tСколько значений будет в массиве?" << std::endl;
		int size;
		getNum(size, 0, 100);
		std::cout << "\tВведите все значения массива: " << std::endl;
		for (int i = 0; i < size; i++)
			GetVector1(A);
	}
}

void Dialog_Vector_Sort(Vector& A) {
	A.Sort();
	std::cout << "\t" << A;
}

void Dialog_Vector_Find_Max(Vector& A) {
	std::cout << "\tМаксимальный элемент: " << A.FindMax() << std::endl;
}
