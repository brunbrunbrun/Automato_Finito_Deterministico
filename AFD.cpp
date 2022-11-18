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
    string recebimento_estados_finais;

    cout << "Numero N de estados do automato" << endl;
    cin >> numero_estados;

    cout << "Estado Inicial" << endl;
    cin >> estado_inicial;

    cout <<"Estados Finais" << endl;
    getline(cin, recebimento_estados_finais);

/*    stringstream ss(recebimento_estados_finais);
    vector<string> result;

    while(ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
    }
*/
    //string str = "1, 2, 3, 4, 5, 6";
    vector<int> vect;

    stringstream ss(recebimento_estados_finais);

    for (int i; ss >> i;) {
        vect.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }

    for (size_t i = 0; i < vect.size(); i++)
        cout << vect[i] << endl;



    return 0;
}
