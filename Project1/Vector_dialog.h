#ifndef VECTOR_DIALOG_H
#define VECTOR_DIALOG_H

#include "../StaticLib_vector/framework.h"
//#include "vector.h" 
using namespace lab3;

int Dialog_Main();
void Dialog_Create_vector(Vector& vector);
void Dialog_Print_Vector(Vector& vector);
void Dialog_Add_Vectors(Vector& vector);
void Dialog_Vector_slice(Vector& A);
void Dialog_Add_New_element_to_vector(Vector& A);
void Dialog_Vector_Sort(Vector& A);
void Dialog_Vector_Find_Max(Vector& A);
typedef void (*Dialog_t)(Vector&); //объ€вление типа "указатель на функцию"
const Dialog_t Dialogs[] = { Dialog_Create_vector, Dialog_Print_Vector , Dialog_Add_Vectors,
							 Dialog_Vector_slice,  Dialog_Add_New_element_to_vector,
							 Dialog_Vector_Sort,   Dialog_Vector_Find_Max };

#endif VECTOR_DIALOG_H#pragma once
