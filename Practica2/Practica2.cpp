// Practica2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>



int main()
{
	//breakpoint de memoria!!

	// EJERCICIO 1

	int iEj1 = 9;
	int* p = &iEj1;
	char* pChar = reinterpret_cast<char*>(p);
	for (int i = 0; i < sizeof(int); i++)
	{

		printf("byte : %02hhX\n", *(pChar + i));

	}

	// EJERCICIO 2

	int tabla[] = { 1,2,3,4,5,3,0xFFFFFFFF,2 };
	unsigned int size_tabla = sizeof(tabla) / sizeof(int);
	int numMayor = 0;
	int* pTabla = tabla;

	for (unsigned int i = 0; i < size_tabla; i++)
	{
		int actual = *(pTabla + i);
		if (actual > numMayor) {
			numMayor = actual;
		}
	}
	printf("%d", numMayor);

	// EJERCICIO 3
	// Hay que castear a char
	
	int byteMayor = 0;
	int* pTabla = tabla;

	for (unsigned int i = 0; i < size_tabla; i++)
	{

		int actual = *(pTabla + i);
		if (actual > numMayor) {
			numMayor = actual;
		}
	}
	printf("%d", numMayor);
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
