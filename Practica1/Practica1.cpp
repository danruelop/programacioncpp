// Practica1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>


#define MASK_INVULNERABLE 0x00000001
#define MASK_BALASINFINITAS 0x00000002
#define MASK_ESCUDO 0x00000003
#define MASK_BERSERKER 0x00000004
#define MASK_BALAS 0x000000FF
#define MASK_RESETBULLETS 0xFF00FFFF

//obtener número de balas
unsigned int GetNumBullets(unsigned int _uValue)
{
	unsigned int uTemp = _uValue >> 16;
	return uTemp & MASK_BALAS;
}

// return nuevo _uValue con las balas añadidas
unsigned int AddBullets(unsigned int _uValue, unsigned int _uBullets)
{
	unsigned int uNumOfBullets = GetNumBullets(_uValue);
	unsigned int uNewBullets = uNumOfBullets + _uBullets;
	unsigned int uTemp = _uValue & MASK_RESETBULLETS;
	unsigned int uNewBulletsDesplazadas = uNewBullets << 16;
	// Para sumar a nivel de bits hay que hacerlo con un OR
	return uTemp | uNewBulletsDesplazadas;
	// @TODO: Hay que comprobar que uNumBullets no valga más de 255 o problemas
}

bool IsInfiniteBulletsActivated(unsigned int _uValue) 
{
	bool bIsActivated = (_uValue & MASK_BALASINFINITAS) >> 1 != 0;
	return bIsActivated;
}
unsigned int ActivateInfiniteBullets(unsigned int _uValue)
{
	return _uValue | MASK_BALASINFINITAS;
}

  //  @TODO: Ponerlo más bonito

int main()
{
	unsigned int uValor(0x8F252001);
	printf(" Número de balas: %d\n",GetNumBullets(uValor));

	unsigned int uValorConNuevasBalas = AddBullets(uValor, 30);
	printf(" Nuevo número de balas: %d\n", GetNumBullets(uValorConNuevasBalas));

	printf(" Está activado el modo balas infinitas ? %d\n", IsInfiniteBulletsActivated(uValor));

	printf("Y ahora ? %d\n", IsInfiniteBulletsActivated(ActivateInfiniteBullets(uValorConNuevasBalas)));


	

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
