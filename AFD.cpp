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
    string string_leitura2;

    cout << "Numero N de estados do automato" << endl;
    cin >> numero_estados;

    cout << "Estado Inicial" << endl;
    cin >> estado_inicial;

    //lendo estados finais e separando eles em um vetor
    cout <<"Estados Finais" << endl;
    cin.ignore();
    getline(cin, string_leitura);

    vector<int> estados_finais;

    stringstream ss_estados_finais(string_leitura);

    for (int i; ss_estados_finais >> i;) {
        estados_finais.push_back(i);
        if (ss_estados_finais.peek() == ',')
            ss_estados_finais.ignore();
    }

    //apenas pra mostrar que foi adicionado corretamente no vetor
    for (size_t i = 0; i < estados_finais.size(); i++)
        cout << estados_finais[i] << endl;


    //lendo os simbolos do alfabeto
    cout <<"Simbolos (separados por virgula)"<<endl;
    getline(cin, string_leitura2);

    vector<char> simbolos;

    stringstream ss_simbolos(string_leitura2);

    char palavra;
    for (int i = 0; ss_simbolos >> palavra;i++)
    {
        simbolos.push_back(palavra);
        if (ss_simbolos.peek() == ',')
            ss_simbolos.ignore();
    }

    //apenas pra mostrar que foi adicionado corretamente no vetor
    for (size_t i = 0; i < simbolos.size(); i++)
        cout << simbolos[i] << endl;

    return 0;
}
