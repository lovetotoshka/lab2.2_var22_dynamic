#include "vector.h" //+
//#include "Vector_Exceptions.h" //+
#include "Get_Templates.h" //+
#include <iostream> //+


namespace lab3 {

	//Vector::Vector()  //������ ����������� ��� ������������� ����������� � �������� ����������� ������ �� ���������;
	//	: i(0)
	//{
	//}

/*
	Vector::Vector(int E) //�������� ����������� ������ � �������������� ������������ ��������� �������;
	{
		this->i = 1;
		this->Array[0] = E;
	}
	*/
	/*
	Vector::Vector() {
		
		if (size != 0) {
			delete[] Array;
			size = 0;
		}
		Array = new int[1];
		Array[0] = 0;
		};
		*/
	

	Vector::Vector(int k, int* E) { //�������� ����������� ������ � �������������� �������� � �������� �������� ��������� �������;
		size = k;
		delete[] Array;
		Array = new int[size];
		for (int l = 0; l < k; l++)
		{
			Array[l] = E[l];
		}
	}

	Vector::Vector(const Vector&v):  size(v.size){//���������� �����������
		Array = new int[size];
		for (int i = 0; i < size; i++) {
			Array[i] = v.Array[i];
		}
		std::cout << "\n���������� �����������\n";

	}

	Vector::Vector(Vector&&v): size(v.size), Array(v.Array) { //������������ �����������
		v.Array = nullptr;
		std::cout << "\n ������������ �����������\n";
	}

	Vector& Vector:: operator = (const Vector& v) {//������������� �������� ������������
		if (this != &v) {
			size = v.size;
			//Array = v.Array;
			delete[] Array;
			Array = new int[size];
			for (int i = 0; i < size; i++) {
				Array[i] = v.Array[i];
			}
		}
		std::cout << "\n������������� �������� ������������\n";
		return *this;
	}

	Vector& Vector:: operator = (Vector&&v) {// ������������ �������� �������������
		int tmp = size;
		size = v.size;
		v.size = tmp;
		int* ptr = Array;
		Array = v.Array;
		v.Array = ptr;
		std::cout << "\n������������ �������� ������������\n";
		return *this;
	}

	void Vector::Print() { //����� ������� � �������� �����;
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

	void Vector::Enter() { //���� �������� ������� �� �������� ������
		int a;
		getNum(a, -100000, 100000);
		AddNewElement(a);
		std::cout << "\t������� " << a << " �������� � ������" << std::endl;
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
			std::cout << " ������� ����� ������ ������" << std::endl;
			throw Vector_Exception("������� ����� ������ ������");
		}
		Vector tmp;
		for (int i = 0; i < A.size; i++) {
			tmp.AddNewElement(this->Array[i] + A.Array[i]);
		}
		return tmp;
	}

	int Vector::operator [ ] (int k) const { //������� ������ �����
		return Array[k];
	}

	int& Vector::operator[] (int k) { 
		return Array[k];
	}

	const Vector Vector:: operator +(const Vector& A) const {
		if (this->size != A.size) {
			std::cout << " ������� ����� ������ ������";
			throw Vector_Exception("������� ����� ������ ������");
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
		size ++;
		int* newArr = new int[size];
		for (int k = 0; k < size-1; k++) {
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
			std::cout << "�������� ������� �� ������� �������" << std::endl;
			throw Vector_Exception("�������� ������� �� ������� �������");
		}
		else {
			int k = item_number - 1; // ������ �������� 1 2 3 4 5
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
			throw Vector_Exception("������ ����");
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
/*Vector how_to_create_Vector()
   {
	   std::cout << "\t��� �� ������ ������ ������?" << std::endl;
	   std::cout << "\t1 - ������� ������ ������" << std::endl;
	   std::cout << "\t2 - ������� ������ � ����� ���������" << std::endl;
	   std::cout << "\t3 - ������� ������ � �������� ��������" << std::endl;
	   int how_create, test = 0;
	   getNum(how_create, 1, 3);
	   if (how_create == 1) {
		   Vector A;
		   return A;
	   }
	   if (how_create == 2) {
		   int value;
		   getNum(value, -100000, 100000);
		   Vector A(value);
		   return A;
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
		   return A;
	   }
   }*/