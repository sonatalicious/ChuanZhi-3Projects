#define INTEGER int
INTEGER Multiply(INTEGER a, int b)
{
	INTEGER result = a * b;
	return result;
#include "..\EndBrace.h"

void Increment(int* value)
{
	(*value)++;
}

void Increment2(int& value)
{
	value++;
}


