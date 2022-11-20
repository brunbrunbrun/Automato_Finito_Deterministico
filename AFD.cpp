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
#include <stdio.h>
#include <algorithm>

using namespace std;

bool aceitas(int estado_atual, vector<int> estados_finais)
{
    if(find(estados_finais.begin(), estados_finais.end(), estado_atual) != estados_finais.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int numero_estados, estado_inicial;
    string string_leitura;
    string string_leitura2;
    string string_leitura3;

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


    //transições
    cout << "Numero M de transicoes" << endl;
    int quantidade_transicao;
    cin >> quantidade_transicao;


    //matriz com as transicoes
    int quantos_simbolos = simbolos.size();
    int transition[numero_estados][quantos_simbolos];



    cout << "Transicoes (estado atual, simbolo) -> estado destino" << endl;

    //loop para ler M transicoes

/*
    for(int i=0; i<(quantidade_transicao + 1); i++)
    {
        getline(cin, string_leitura3);
        int estado_atual, estado_destino;
        char simbolo_atual;

        //problema aq?
        sscanf(string_leitura3.c_str(),"(%d, %c) -> %d", &estado_atual, &simbolo_atual, &estado_destino);

        //estado_atual = string_leitura3[1];
        //simbolo_atual = string_leitura3[4];
        //estado_destino = string_leitura3[10];


        cout << estado_atual <<" "<< simbolo_atual <<" "<< estado_destino << endl;
    }
*/

    cin.ignore();

    for(int i=0; i<numero_estados;i++)
    {
        for(int j = 0; j < quantos_simbolos; j++)
        {
            getline(cin, string_leitura3);
            int estado_atual, estado_destino;
            char simbolo_atual;
            sscanf(string_leitura3.c_str(),"(%d, %c) -> %d", &estado_atual, &simbolo_atual, &estado_destino);

            transition[i][j] = int(estado_destino);
            cout << estado_atual <<" "<< simbolo_atual <<" "<< estado_destino << endl;

        }
    }

    cout << "matriz com os destinos" << endl;
    for(int i = 0; i < numero_estados; i++)
    {
        for(int j=0; j< quantos_simbolos; j++)
        {
            cout << transition[i][j] << " ";
        }
        cout << endl;
    }

    string string_leitura4;
    cout << "Cadeia de entrada" << endl;
    getline(cin, string_leitura4);

    vector<char> entrada;

    stringstream ss_entrada(string_leitura4);

    char palavra2;
    for (int i = 0; ss_entrada >> palavra2;i++)
    {
        entrada.push_back(palavra2);
    //    if (ss_simbolos.peek() == ',')
    //        ss_simbolos.ignore();
    }

        //apenas pra mostrar que foi adicionado corretamente no vetor
        for (size_t i = 0; i < entrada.size(); i++)
        {
            cout << entrada[i] << endl;
        }

//AUTOMATO EM ACAO
    int index_simbolo;
    int estado_atual = estado_inicial;

    //checkar se n existe simbolos nao pertencentes
    for(size_t i = 0; i < entrada.size(); i++)
    {
        if(find(simbolos.begin(), simbolos.end(), entrada[i]) != simbolos.end())
        {
            continue;
        }
        else
        {
            cout << "Simbolo inserido nao contido no alfabeto" << endl;
            cout << "Entrada foi NEGADA" << endl;
            exit(1);
        }
    }

    for(size_t i = 0; i < entrada.size(); i++)
    {
        for(int j = 0; j < quantos_simbolos; j++)
        {
            if (entrada[i] == simbolos[j])
            {
                index_simbolo = j;
            }
        }

        estado_atual = transition[estado_atual-1][index_simbolo];
        cout << estado_atual << endl;
    }

    cout <<"Estado final: "<< estado_atual << endl;

    bool aceitado = aceitas(estado_atual, estados_finais);

    if (aceitado == true)
    {
        cout << "A entrada e ACEITA pelo automato" << endl;
    }
    else
    {
        cout << "A entrada e REJEITADA pelo automato" << endl;
    }

    return 0;
}
