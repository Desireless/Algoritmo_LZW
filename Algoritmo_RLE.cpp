
#include <iostream>
#include <vector>

using namespace std;

void rle(string letras)
{
	int tamano = letras.size();
	int contador;

	cout << "FRASE COMPRIMIDA: ";

	for (int i = 0; i < tamano; i++) {
		contador = 1;
		while (letras[i] == letras[i + 1] && i < tamano - 1 ) {
			contador++;
			i++;
		}
		cout << letras[i] << contador;
	}
}

int main()
{
	cout << "ALGORITMO RLE" <<endl;

	string frase = "AAAAAAABAAACABA";
	cout << "FRASE: " + frase << endl;

	rle(frase);

	return 0;
}
