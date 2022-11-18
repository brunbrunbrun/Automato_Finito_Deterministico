/*
Trabalho da materia de TLFAC 2022/2 criando um simulador de
Automatos Finitos Deterministicos

Alunos:
Bruno Belo
Lucas Freitas
Lucca Souza
Matheus Parizotto
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    int numero_estados, estado_inicial;
    string string_leitura;

    cout << "Numero N de estados do automato" << endl;
    cin >> numero_estados;

    cout << "Estado Inicial" << endl;
    cin >> estado_inicial;

    //lendo estados finais e separando eles em um vetor
    cout <<"Estados Finais" << endl;
    cin.ignore();
    getline(cin, string_leitura);

    vector<int> vect;

    stringstream ss(string_leitura);

    for (int i; ss >> i;) {
        vect.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }

    for (size_t i = 0; i < vect.size(); i++)
        cout << vect[i] << endl;


    //lendo os simbolos do alfabeto
    cout <<"Simbolos (separados por virgula)"<<endl;
    cin.ignore();
    getline(cin, string_leitura);

    vector<char> simbolos;

    stringstream string_simbolos(string_leitura);

    return 0;
}
