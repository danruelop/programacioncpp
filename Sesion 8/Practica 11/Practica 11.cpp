// Practica 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Jpg.h"
#include "Png.h"

void PrintImageInfo(const CImagen &oImagen);

int main()
{
  // Práctica Imagen
  CPng oPng;
  CJpg oJpg;

  oPng.SetPngFile("Fichero.png");
  oJpg.SetJpgFile("Fichero.jpg");



  PrintImageInfo(oPng);
  PrintImageInfo(oJpg);

  getchar();

  return 0;
}

// ***************************************************
//
// ***************************************************
void PrintImageInfo(const CImagen &oImagen)
{
  printf("NumPixes: %d \nSize: %d\n", oImagen.GetNumPixels(), oImagen.GetUncompressedSize());
}

