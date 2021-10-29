#ifndef GET_TEMPLATES_H // Директива #ifndef проверяет, определено ли имя GET_TEMPLATES_H, если нет, 
#define GET_TEMPLATES_H // то управление передаётся директиве #define и определяется интерфейс класса. 
//Если же имя GET_TEMPLATES_H уже определено, управление передаётся директиве #endif. 
//Таким образом, исключается возможность многократного определения класса GET_TEMPLATES_H.

#include <iostream> 
#include "Vector_Exceptions.h" 
using namespace lab3;

inline int getNum(int& a, int b, int c)
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		std::cout << "\tВведите целое значение: ";
		std::cin >> a;
		if (std::cin.bad()) {
			throw Vector_Exception("Fatal Error", 1); // 
		}
		if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			std::cout << "\tERROR!!!" << std::endl;
		}
		else {// если всё хорошо, но значение выходит за границы
			if ((a < b) || (a > c)) {
				std::cin.clear(); // возвращаем cin в 'обычный' режим работы
				std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
				std::cout << "\tERROR!" << std::endl;
			}
			else { //всё хорошо
				std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
				return a;
			}
		}
	}
}
inline Vector GetVector1(Vector& vector) {
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		std::cout << "\tВведите целое значение: ";
		std::cin >> vector;
		if (std::cin.bad()) {
			throw Vector_Exception("Fatal error during input", 1);
		}
		else if (std::cin.eof()) {
			throw Vector_Exception("EOF occured", 1);
		}
		else if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			std::cout << "\tWrong input! Enter again" << std::endl;
		}
		else { //всё хорошо
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			break;
		}
	}
	return vector;
}

#endif
