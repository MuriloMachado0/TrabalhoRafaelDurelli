#ifndef CONVERSOES_H
#define CONVERSOES_H

#include <string>

using namespace std;

int charToVal(char c);
char valToChar(int val);
double potencia(double base, int exp);
long long stringToLongLong(const string& s);
string longLongToString(long long v);
string fracionarioParaString(double f, int limit);

// F5: Validacao
bool validarEntrada(const string& num, int base);

// F1 e F2: Conversoes envolvendo Decimal
string decParaBase(long long n, int base_destino, bool trace);
long long baseParaDec(const string& num, int base_origem, bool trace);
string decFracParaBase(double frac, int base_destino, bool trace);
double baseFracParaDec(const string& frac_str, int base_origem, bool trace);

// F3 e F4: Utilitarios de Agrupamento
string agruparBin(string bin, int bits, bool isFrac, bool trace);
string expandirParaBin(const string& val, int bitsPorDigito, bool isFrac, bool trace);

string converterParteInt(const string& parteInt, int bO, int bD, bool trace);
string converterParteFrac(const string& parteFrac, int bO, int bD, bool trace);
string converterTudo(const string& val, int bO, int bD);

// F10: Calculadora de Maximos
void calcularMaximos(int k);

#endif