// StaticLib_vector.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"

#include "Get_Templates.h"
#include "Vector_Exceptions.h"
#include <iostream> 


namespace lab3 {

	//Vector::Vector()  //пустой конструктор для инициализации экземпляров и массивов экземпляров класса по умолчанию;
	//	: i(0)
	//{
	//}


	Vector::Vector(int k, int* E) { //создание экземпляров класса с инициализацией размером и массивом значений элементов вектора;
		size = k;
		//delete[] Array;
		Array = new int[size];
		for (int l = 0; l < k; l++)
		{
			Array[l] = E[l];
		}
	}

	Vector::Vector(const Vector& v) : size(v.size) {//копирующий конструктор
		Array = new int[size];
		for (int i = 0; i < size; i++) {
			Array[i] = v.Array[i];
		}
		std::cout << "\nКопирующий конструктор\n";

	}

	Vector::Vector(Vector&& v) : size(v.size), Array(v.Array) { //Перемещающий конструктор
		v.Array = nullptr;
		std::cout << "\n Перемещающий конструктор\n";
	}

	Vector& Vector:: operator = (const Vector& v) {//перегруженный оператор присваивания
		if (this != &v) {
			size = v.size;
			//Array = v.Array;
			delete[] Array;
			Array = new int[size];
			for (int i = 0; i < size; i++) {
				Array[i] = v.Array[i];
			}
		}
		std::cout << "\nперегруженный оператор присваивания\n";
		return *this;
	}

	Vector& Vector:: operator = (Vector&& v) {// перемещающий оператор присванивания
		int tmp = size;
		size = v.size;
		v.size = tmp;
		int* ptr = Array;
		Array = v.Array;
		v.Array = ptr;
		std::cout << "\nперемещающий оператор присваивания\n";
		return *this;
	}

	void Vector::Print() { //вывод вектора в выходной поток;
		std::cout << "\t{";
		for (int l = 0; l < this->size; l++)
			if (l != this->size - 1) {
				std::cout << this->Array[l] << ",";
			}
			else { std::cout << this->Array[l]; }
		std::cout << "}" << std::endl;
	}

	std::ostream& operator << (std::ostream& out, Vector& vector)
	{
		out << "{";
		for (int l = 0; l < vector.Get_size(); l++) {
			if (l != vector.Get_size() - 1)
				out << vector.Get_arr_i(l) << ",";
			else
				out << vector.Get_arr_i(l);
		}
		out << "}";

		return out;
	}

	void Vector::Enter() { //ввод значения вектора из входного потока
		int a;
		getNum(a, -100000, 100000);
		AddNewElement(a);
		std::cout << "\tЭлемент " << a << " добавлен в вектор" << std::endl;
	}

	std::istream& operator>> (std::istream& in, Vector& vector) {
		int m;
		in >> m;
		if (std::cin.bad())
			in.setstate(std::ios::badbit);
		else if (std::cin.eof())
			in.setstate(std::ios::eofbit);
		else if (std::cin.fail())
			in.setstate(std::ios::failbit);
		else {
			vector.AddNewElement(m);
		}
		return in;
	}

	const Vector Vector::Add(const Vector& A) {
		if (this->size != A.size) {
			std::cout << " Векторы имеют разный размер" << std::endl;
			throw Vector_Exception("Векторы имеют разный размер");
		}
		Vector tmp;
		for (int i = 0; i < A.size; i++) {
			tmp.AddNewElement(this->Array[i] + A.Array[i]);
		}
		return tmp;
	}

	int Vector::operator [ ] (int k) const { //сделать вторую форму
		if (k < 0 || k >= size)
			throw Vector_Exception("Выходит за пределы массива");
		return Array[k];
	}

	int& Vector::operator[] (int k) {
		if (k < 0 || k >= size)
			throw Vector_Exception("Выходит за пределы массива");
		return Array[k];
	}

	const Vector Vector:: operator +(const Vector& A) const {
		if (this->size != A.size) {
			std::cout << " Векторы имеют разный размер";
			throw Vector_Exception("Векторы имеют разный размер");
		}
		int* tmp = new int[size];
		for (int i = 0; i < A.size; i++) {
			tmp[i] = (Array[i] + A.Array[i]);
		}
		Vector tmp_v(size, tmp);
		return tmp_v;
	}

	int Vector::Get_size() {
		return size;
	}

	int Vector::Get_arr_i(int i) {
		return Array[i];
	}

	void Vector::AddNewElement(const int E) {
		size++;
		int* newArr = new int[size];
		for (int k = 0; k < size - 1; k++) {
			newArr[k] = Array[k];
		}
		delete[] Array;
		newArr[size - 1] = E;
		Array = new int[size];
		for (int i = 0; i < size; i++) {
			Array[i] = newArr[i];
		}
	}

	const Vector Vector::Vector_slice(int item_number, int number_of_elements) {
		Vector tmp;
		if (this->size < number_of_elements + item_number - 1) {
			std::cout << "Значения выходят за пределы массива" << std::endl;
			throw Vector_Exception("Значения выходят за пределы массива");
		}
		else {
			int k = item_number - 1; // индекс элемента 1 2 3 4 5
			std::cout << "\t{";
			for (int j = 0; j < number_of_elements; j++) {
				if (j != number_of_elements - 1) {
					std::cout << this->Array[k] << ",";
					tmp.AddNewElement(Array[k]);
					k++;
				}
				else {
					std::cout << this->Array[k];
					tmp.AddNewElement(Array[k]);
				}
			}
			std::cout << "}" << std::endl << std::endl;

		}
		return tmp;
	}

	void Vector::Sort() {
		int temp;
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size - 1; j++) {
				if (this->Array[j] > this->Array[j + 1]) {
					temp = this->Array[j];
					this->Array[j] = this->Array[j + 1];
					this->Array[j + 1] = temp;
				}
			}
		}
	}

	int Vector::FindMax() {
		if (size == 0)
			throw Vector_Exception("Вектор пуст");
		else {
			int res = this->Array[0];
			int i;
			for (i = 0; i < this->size; ++i)
				if (this->Array[i] > res)
					res = this->Array[i];
			return res;
		}
	}


}