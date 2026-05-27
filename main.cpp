#include <iostream>
#include <string>
#include "conversoes.h"
#include "saida.h"
#include "quiz.h"
#include "batch.h"

using namespace std;

void exibirMenu() {
    cout << endl << "============================================" << endl;
    cout << "   Conversor Universal de Bases Numericas" << endl;
    cout << "============================================" << endl;
    cout << "1. Conversao manual (com ou sem trace)" << endl;
    cout << "2. Modo Batch (CSV)" << endl;
    cout << "3. Modo Quiz" << endl;
    cout << "4. Calculadora de Maximos (k bits)" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    int opcao;
    do {
        exibirMenu();
        cin >> opcao;

        if (opcao == 1) {
            string num;
            int baseO, baseD;
            char passo;
            cout << "Digite o numero a ser convertido: "; cin >> num;
            cout << "Base de origem (2, 8, 10, 16): "; cin >> baseO;
            cout << "Base de destino (2, 8, 10, 16): "; cin >> baseD;
            
            if ((baseO == 2 || baseO == 8 || baseO == 10 || baseO == 16) && 
                (baseD == 2 || baseD == 8 || baseD == 10 || baseD == 16)) {
                
                cout << "Deseja ver o passo a passo? (S/N): "; cin >> passo;
                exibirResultado(num, baseO, baseD, (passo == 'S' || passo == 's'));
            } else {
                cout << "Erro: Base invalida escolhida! O sistema suporta apenas as bases 2, 8, 10 e 16." << endl;
            }
        } 
        else if (opcao == 2) {
            string in_file, out_file;
            cout << "Arquivo de entrada (ex: entrada.csv): "; cin >> in_file;
            cout << "Arquivo de saida (ex: saida.csv): "; cin >> out_file;
            processarBatch(in_file, out_file);
        }
        else if (opcao == 3) {
            iniciarQuiz();
        }
        else if (opcao == 4) {
            int k;
            cout << "Digite a quantidade de bits (k): "; cin >> k;
            calcularMaximos(k);
        } 
        else if (opcao == 0) {
            cout << "Saindo do programa... Ate logo!" << endl;
        }
        else {
            cout << "Tente novamente, opcao errada ao escolher o modo." << endl;
        }
        
    } while (opcao != 0);

    return 0;
}