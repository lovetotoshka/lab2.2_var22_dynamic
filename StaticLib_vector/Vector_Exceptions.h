#ifndef VECTOR_EXCEPTIONS_HEADER
#define VECTOR_EXCEPTIONS_HEADER
#include <iostream> 

class Vector_Exception
{
private:
	std::string message;
	bool fatal;
public:
	Vector_Exception();
	Vector_Exception(std::string);
	Vector_Exception(std::string, bool);
	Vector_Exception(bool, std::string);
	std::string What() const;
	bool Fatal() const;
	friend std::ostream& operator << (std::ostream&, const Vector_Exception&);
};
#endif