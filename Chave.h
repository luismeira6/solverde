#pragma once

#include<iostream>
#include<string>

using namespace std;

class Chave {
private: 
	static bool validaCinco(int num, int* chUS);
	static bool validaSuplementar(int num);
	static bool validaRepetidos(int num, int* chUS);
	static void ordenaChave(int* chAle);
	static int verifPremio(int* ch1, int* ch2);
public:
	static void gerarChaveAleatoria(int* ch);
	static void lerChave(int* ch);
	static void imprimirChave(int* chAle);
	static void imprimirChaveUser(int* chUs);
	static void showPrize(int* ch1, int* ch2);
};
