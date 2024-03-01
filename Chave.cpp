#include "Chave.h"
#include <algorithm>

bool Chave::validaCinco(int num, int* chUS) { // valida os limites dos numeros que o user pode escolher 
	if (num > 0 && num < 50)
		return true;
	return false;
}

bool Chave::validaSuplementar(int num) { // valida os limites do numero suplementar que o user pode escolher 
	if (num > 0 && num < 14)
		return true;
	return false;
}

void Chave::gerarChaveAleatoria(int* chAle){ // gera uma chave aleatoria sorteada 
	int num;
	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		num = 1 + (rand() % 49);
		if (num == chAle[i])
		{
			num = 1 + (rand() % 49);
		}
		chAle[i] = num;

	}
	for (int i = 0; i < 1; i++)
	{
		num = 1 + (rand() % 13);
		chAle[5] = num;
	}
	Chave::ordenaChave(chAle);
}

void Chave::imprimirChave(int* chAle) { // imprime a chave
	Chave::ordenaChave(chAle);
	cout << "\nChave Premiada: ";
	for (int i = 0; i < 6; i++)
	{
		cout << chAle[i] << " ";
	}
	cout << "Suplementar: " << chAle[5];
	cout << endl;
}

void Chave::imprimirChaveUser(int* chUs) { // imprime a chave
	Chave::ordenaChave(chUs);
	cout << "Chave: ";
	for (int i = 0; i < 6; i++)
	{
		if (i == 5)
		{
			cout << "Suplementar: ";
		}
		cout << chUs[i] << " ";
	}
	cout << endl;
}

bool Chave::validaRepetidos(int num, int* chUS) { // valida se o numero não é repetido, caso seja, volta a dar erro e a pedir novo input
	for (int i = 0; i < 5; i++)
	{
		if (num == chUS[i])
		{
			return false;
		}
		return true;
	}
}

void Chave::lerChave(int* chUs) { // recebe a chave que o user aposta
	int num;
	for (int i = 0; i < 5; i++)
	{
		cout << "\nIntroduza o " << i + 1 << "o que quer apostar: ";
		cin >> num;

		if (Chave::validaCinco(num, chUs) && Chave::validaRepetidos(num, chUs))
		{
			chUs[i] = num;
		}
		else
		{
			cout << "ERRO: Tem de ser entre 1 e 49, nao repeitdo";
			i--;
		}
	}
	cout << "\nIntroduza o Suplementar que quer apostar: ";
	cin >> num;
	if (Chave::validaSuplementar(num))
	{
		chUs[5] = num;
	}
	else
	{
		while (!Chave::validaSuplementar(num))
		{
			cout << "\nIntroduza o Suplementar que quer apostar: ";
			cin >> num;
		}
		chUs[5] = num;
	}
	Chave::ordenaChave(chUs);
}

void Chave::ordenaChave(int* ch) { // ordena a chave aleatoria em uma chave ordenada
	for (int i = 0; i < 5; i++)
	{
		int vec[] = {ch[0],ch[1], ch[2], ch[3] ,ch[4]};
		int n = sizeof(vec) / sizeof(vec[5]);
		sort(vec, vec + n);
	}
}

int Chave::verifPremio(int* ch1, int* ch2) {
	int cont = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (ch1[i] == ch2[j])
			{
				cont++;
			}
		}
	}
	if (ch1[5] == ch2[5])
	{
		cont = cont + 10;
	}
	return cont;
}

void Chave::showPrize(int* ch1, int* ch2) {
	int premio = Chave::verifPremio(ch1, ch2);
	switch (premio)
	{
	case 16: cout << "\t\t\t****************\n\t\t\t\tJACKPOT\n\t\t\t****************\n!!acertou os 5 números mais o suplementar!!"; break;
	case 5: cout << "acertou 5 números e errou o suplementar"; break;
	case 14: cout << "acertou 4 números mais o suplementar"; break;
	case 4: cout << "acertou 4 números e errou o suplementar"; break;
	case 0: cout << "Nao acertou qualquer numero"; break;
	default: cout << "Nao obteve qualquer premio";
		break;
	}
}