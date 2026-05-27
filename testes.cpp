#include "conversoes.h"
#include <iostream>
#include <string>

using namespace std;

int totalTestes = 0;
int testesPassaram = 0;

void runTest(const string& nome_teste, const string& input, int baseO, int baseD, const string& esperado) {
    totalTestes++;
    // Usa o nosso despachante principal para realizar a conversao sem trace
    string resultado = converterTudo(input, baseO, baseD);
    
    if (resultado == esperado) {
        cout << "[PASS] " << nome_teste << " | " << input << "(" << baseO << ") -> " << resultado << "(" << baseD << ")" << endl;
        testesPassaram++;
    } else {
        cout << "[FAIL] " << nome_teste << endl;
        cout << "       Entrada: " << input << " (Base " << baseO << ")" << endl;
        cout << "       Esperado: " << esperado << " | Obtido: " << resultado << endl;
    }
}

int main() {
    cout << "===========================================" << endl;
    cout << "      INICIANDO SUITE DE TESTES (30+)      " << endl;
    cout << "===========================================" << endl;

    // F1 e F2: Base 10 <-> Outras (Inteiros)
    runTest("T01: Dec -> Bin", "25", 10, 2, "11001");
    runTest("T02: Dec -> Oct", "25", 10, 8, "31");
    runTest("T03: Dec -> Hex", "255", 10, 16, "FF");
    runTest("T04: Bin -> Dec", "11001", 2, 10, "25");
    runTest("T05: Oct -> Dec", "31", 8, 10, "25");
    runTest("T06: Hex -> Dec", "FF", 16, 10, "255");
    runTest("T07: Dec -> Dec (Mesma base)", "100", 10, 10, "100");

    // F3: Binario <-> Octal / Hexadecimal (Agrupamento Direto)
    runTest("T08: Bin -> Oct", "101101", 2, 8, "55");
    runTest("T09: Oct -> Bin", "55", 8, 2, "101101");
    runTest("T10: Bin -> Hex", "11110000", 2, 16, "F0");
    runTest("T11: Hex -> Bin", "F0", 16, 2, "11110000");
    runTest("T12: Bin -> Oct (Zeros a esquerda)", "11", 2, 8, "3");
    runTest("T13: Bin -> Hex (Zeros a esquerda)", "101", 2, 16, "5");

    // F4: Octal <-> Hexadecimal (Intermediario Binario)
    runTest("T14: Oct -> Hex", "377", 8, 16, "FF");
    runTest("T15: Hex -> Oct", "FF", 16, 8, "377");
    runTest("T16: Oct -> Hex (Maior)", "1000", 8, 16, "200");
    runTest("T17: Hex -> Oct (Maior)", "200", 16, 8, "1000");

    // F6: Fracionarios (Limite de 16 casas e matematica)
    runTest("T18: Dec Frac -> Bin", "10.625", 10, 2, "1010.101");
    runTest("T19: Dec Frac -> Oct", "10.625", 10, 8, "12.5");
    runTest("T20: Dec Frac -> Hex", "10.625", 10, 16, "A.A");
    runTest("T21: Bin Frac -> Dec", "1010.101", 2, 10, "10.625");
    runTest("T22: Oct Frac -> Dec", "12.5", 8, 10, "10.625");
    runTest("T23: Hex Frac -> Dec", "A.A", 16, 10, "10.625");
    
    // F3 Fracionario: Agrupamento fracionario (Zeros a direita)
    runTest("T24: Bin Frac -> Oct", "0.1011", 2, 8, "0.54");
    runTest("T25: Oct Frac -> Bin", "0.54", 8, 2, "0.101100");
    runTest("T26: Bin Frac -> Hex", "0.101101", 2, 16, "0.B4");
    
    // F4 Fracionario: Octal <-> Hexa fracionario
    runTest("T27: Oct Frac -> Hex", "0.4", 8, 16, "0.8");
    runTest("T28: Hex Frac -> Oct", "0.8", 16, 8, "0.40"); // Corrigido de 0.400 para 0.40

    // Testes de Bordas / Zeros
    runTest("T29: Zero Dec -> Bin", "0", 10, 2, "0");
    runTest("T30: Zero Hex -> Oct", "0", 16, 8, "0");

    cout << "===========================================" << endl;
    cout << "Testes Executados: " << totalTestes << endl;
    cout << "Testes Aprovados:  " << testesPassaram << endl;
    if (totalTestes == testesPassaram) {
        cout << "STATUS: SUCESSO TOTAL! Todos os testes passaram." << endl;
    } else {
        cout << "STATUS: FALHA. Verifique os erros acima." << endl;
    }
    cout << "===========================================" << endl;

    return 0;
}