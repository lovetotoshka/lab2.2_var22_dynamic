//#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream> 

namespace lab3 {

	class Vector {
	private:

		int size = 0; // размер массива
		//int i; // реальный размер массива
		int* Array; // наш вектор
	public:
		int Get_size();
		int Get_arr_i(int i);

		Vector() : size(0), Array(new int[1]) { Array[0] = 0; }; //пустой конструктор для инициализации экземпляров и массивов экземпляров класса по умолчанию;
		Vector(int E) : size(1), Array(new int[1]) { Array[0] = E; }; //создание экземпляров класса с инициализацией единственным элементом вектора;
		Vector(int i, int* E); //создание экземпляров класса с инициализацией размером и массивом значений элементов вектора;

		Vector(const Vector&);//копирующий конструктор
		Vector(Vector&&); //Перемещающий конструктор
		~Vector() { delete[] Array;  std::cout << "\n\tdelete\n"; };// деструктор

		Vector& operator = (const Vector&);//перегруженный оператор присваивания
		Vector& operator = (Vector&&);// перемещающий оператор присванивания

		void Print(); //вывод значений в выходной поток;
		friend std::ostream& operator << (std::ostream& out, Vector& vector);

		void Enter(); //ввод экземпляров класса из входного потока
		friend std::istream& operator >> (std::istream&, Vector& vector);

		const Vector Add(const Vector& A); //выполнение операции сложения двух векторов (реализуется как покомпонентное сложение двух векторов);
		const Vector operator +(const Vector& A) const;

		int operator [ ] (int k) const;
		int& operator [ ] (int k);

		const Vector Vector_slice(int item_number, int number_of_elements); //выделение части вектора указанной длины, начиная с элемента, заданного его порядковым номером в векторе;
		void AddNewElement(const int E); //выполнение операции включения в вектор нового элемента;
		void Sort(); //упорядочение вектора по возрастанию;
		int FindMax(); //нахождение максимального элемента в векторе.
	};
}
#endif