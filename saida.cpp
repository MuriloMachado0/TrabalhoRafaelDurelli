#include "saida.h"
#include "conversoes.h"
#include <iostream>

using namespace std;

void exibirResultado(const string& entrada, int base_origem, int base_destino, bool passo_a_passo) {
    if (!validarEntrada(entrada, base_origem)) {
        cout << "[Erro] Entrada invalida ou digitos incompativeis para a base " << base_origem << endl;
        return;
    }

    string parteInt = entrada, parteFrac = "";
    size_t pos = entrada.find('.');
    if (pos == string::npos) pos = entrada.find(','); 
    
    if (pos != string::npos) {
        parteInt = entrada.substr(0, pos);
        parteFrac = entrada.substr(pos + 1);
    }

    if (passo_a_passo) {
        cout << endl << "======================================================" << endl;
        cout << "                INICIANDO PASSO A PASSO               " << endl;
        cout << "======================================================" << endl;
        cout << endl << ">>> ETAPA 1: Processando a Parte Inteira (" << parteInt << ") <<<" << endl;
    }

    string resInt = converterParteInt(parteInt, base_origem, base_destino, passo_a_passo);
    if (resInt.empty()) resInt = "0";
    
    string resultadoFinal = resInt;

    if (!parteFrac.empty()) {
        if (passo_a_passo) {
            cout << endl << ">>> ETAPA 2: Processando a Parte Fracionaria (." << parteFrac << ") <<<" << endl;
        }
        string resFrac = converterParteFrac(parteFrac, base_origem, base_destino, passo_a_passo);
        
        // F6: Limite de 16 casas decimais
        if (resFrac.length() > 16) {
            resFrac = resFrac.substr(0, 16);
            if(passo_a_passo) cout << endl << "    [Aviso F6] Fracao truncada para 16 casas decimais." << endl;
        }
        resultadoFinal += "." + resFrac;
    }

    if (passo_a_passo) {
        cout << endl << "======================================================" << endl;
        cout << "                    FIM DO TRACE                      " << endl;
        cout << "======================================================" << endl;
    }

    cout << endl << "[RESULTADO FINAL]" << endl;
    cout << "Valor Original: " << entrada << " (Base " << base_origem << ")" << endl;
    cout << "Convertido para: " << resultadoFinal << " (Base " << base_destino << ")" << endl << endl;
}