#include "quiz.h"
#include "conversoes.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void iniciarQuiz() {
    srand((unsigned)time(0));
    int pontuacao = 0;
    int bases[] = {2, 8, 10, 16};

    cout << endl << "=== MODO QUIZ INICIADO ===" << endl;
    for (int nivel = 1; nivel <= 5; nivel++) {
        long long valor = rand() % (10 * nivel * nivel) + 1; 
        int baseO = bases[rand() % 4];
        int baseD = bases[rand() % 4];
        while (baseO == baseD) baseD = bases[rand() % 4];

        string val_str = decParaBase(valor, baseO, false);
        string resposta_correta = converterTudo(val_str, baseO, baseD);

        cout << "Nivel " << nivel << ": Converta " << val_str << " (Base " << baseO << ") para a Base " << baseD << ": ";
        string palpite;
        cin >> palpite;

        // Converte a resposta inteira para letras MAIUSCULAS usando a Tabela ASCII
        for (size_t i = 0; i < palpite.length(); i++) {
            if (palpite[i] >= 'a' && palpite[i] <= 'z') {
                palpite[i] = palpite[i] - 32; 
            }
        }

        if (palpite == resposta_correta) {
            cout << "Correto!" << endl;
            pontuacao += 10 * nivel;
        } else {
            cout << "Incorreto! A resposta era " << resposta_correta << endl;
        }
    }
    cout << "Quiz encerrado! Pontuacao final: " << pontuacao << endl;
}