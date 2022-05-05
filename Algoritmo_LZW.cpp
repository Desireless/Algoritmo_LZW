// Algoritmo_LZW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#define MAX 100

using namespace std;

// diccionario MAX : 100;
// n : cantidad real del diccionario
// frase : palabras a comprimir

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
    string comprimido = "";
    cout << "FRASE COMPRIMIDA: ";

    for (string tut : tutson) {
        for (int i = 0; i < n; i++)
        {
            if (tut == diccionario[i]) {
                comprimido += i;
                cout << i;
            }
        }
    }

    //cout << comprimido;
}

void lzw(string frase, string diccionario[MAX], int n) {

    cout << "ALGORITMO LZW" << endl;
    cout << "FRASE: " + frase << endl;

    string c = string(1,frase.at(0));
    string k = "";
    string ck = "";
    vector<string> res; // vector resultado a convertir

    for (int i = 0; i < ( frase.length() - 1 ); i++)
    {
        res.push_back(c);
        

        // Algoritmo
        k = string(1, frase.at(i + 1) );
        ck += c;
        ck += k;
        if ( existe(ck, diccionario, n) ) {
            c = ck;
        }
        else {
            diccionario[n] = ck;
            n++;
            c = k;
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

