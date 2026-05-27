#include "batch.h"
#include "conversoes.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void processarBatch(const string& arquivo_entrada, const string& arquivo_saida) {
    ifstream in(arquivo_entrada);
    ofstream out(arquivo_saida);

    if (!in.is_open()) {
        cout << "Erro ao abrir o arquivo " << arquivo_entrada << endl;
        return;
    }

    out << "valor;base_origem;resultado;base_destino" << endl;
    string linha;
    
    while (getline(in, linha)) {
        string valor = "";
        int base_origem = 0, base_destino = 0;
        int estado = 0;
        for(char c : linha) {
            if(c == ';') { estado++; continue; }
            if(estado == 0) valor += c;
            else if(estado == 1) base_origem = base_origem * 10 + charToVal(c);
            else if(estado == 2) base_destino = base_destino * 10 + charToVal(c);
        }

        if(valor != "valor" && base_origem > 0 && base_destino > 0) {
            string res = converterTudo(valor, base_origem, base_destino);
            out << valor << ";" << base_origem << ";" << res << ";" << base_destino << endl;
        }
    }
    cout << "Processamento batch concluido! Arquivo gerado: " << arquivo_saida << endl;
}