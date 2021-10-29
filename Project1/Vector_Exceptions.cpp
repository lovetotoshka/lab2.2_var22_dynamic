#include "Vector_Exceptions.h"

Vector_Exception::Vector_Exception() : message("Some exception."), fatal(false) {}

Vector_Exception::Vector_Exception(std::string msg) : message(msg), fatal(false) {}

Vector_Exception::Vector_Exception(std::string msg, bool x) : message(msg), fatal(x) {}

Vector_Exception::Vector_Exception(bool x, std::string msg) : message(msg), fatal(x) {}

std::string Vector_Exception::What() const
{
	return message;
}

bool Vector_Exception::Fatal() const
{
	return fatal;
}

std::ostream& operator << (std::ostream& out, const Vector_Exception& exception)
{
	out << "\tException: \"" << exception.message << "\";\n\t";
	if (!exception.Fatal())
	{
		out << "not ";
	}
	out << "fatal exception.\n";
	return out;
}

