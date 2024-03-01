#include "Chave.h"

using namespace std;

int main() {
	int* chAle = new int[6];
	int* chUs = new int[6];
	Chave::gerarChaveAleatoria(chAle);
	Chave::lerChave(chUs);
	Chave::imprimirChaveUser(chUs);
	Chave::imprimirChave(chAle);
	Chave::showPrize(chAle,chUs);
}
