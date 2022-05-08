#include <iostream>
#include <vector>
#define MAX 100

using namespace std;

/*

Dada una frase y un diccionario, devuelve la frase codificada en codigos.

*/

bool existe(string ck, string diccionario[MAX], int n) {
    for (int i = 0; i < n; i++)
    {
        if (ck == diccionario[i]) {
            return 1;
        }
    }
    return 0;
}

void resultado(vector<string> tutson, string diccionario[MAX], int n) {
    cout << "FRASE COMPRIMIDA: ";
    for (string tut : tutson) {
        for (int i = 0; i < n; i++)
        {
            if (tut == diccionario[i]) {
                cout << i;
            }
        }
    }

}

void lzw(string frase, string diccionario[MAX], int n) {
    /*
        c : caracter actual
        k : caracter siguiente
        ck : caracter actual concatenado con el siguiente
        res : vector resultante de caracteres a comprimir
    */
    cout << "ALGORITMO LZW" << endl;
    cout << "FRASE: " + frase << endl;
    int siguiente = 1;
    string c = string(1,frase.at(0));
    string k = "";
    string ck = "";
    vector<string> res;


    for (int i = 0; i < frase.length(); i++)
    {
        // Si siguiente no supera el tamano de frase
        if (siguiente < frase.length()) {
            k = string(1, frase.at(siguiente)); // siguiente caracter
            ck += c;
            ck += k;

            if (existe(ck, diccionario, n)) { // Existe ck en Diccionario ?
                c = ck;
                siguiente++;
            }
            else {
                diccionario[n] = ck; // guarda ck en diccionario
                n++;
                res.push_back(c); // guarda en vector de caracteres
                c = k;
                siguiente++;
            }
        }
        else { // caso de ultimo caracter
            res.push_back(c);
        }

        ck = "";
    }

    resultado(res, diccionario, n);
}


int main()
{
    string frase = "ABACABA";
    string diccionario[MAX] = {"A","B","C"};
    int n = 3;

    lzw(frase, diccionario, n);

    return 0;
}

