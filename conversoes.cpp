#include "conversoes.h"
#include <iostream>

using namespace std;

int charToVal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1;
}

char valToChar(int val) {
    if (val >= 0 && val <= 9) return (char)(val + '0');
    if (val >= 10 && val <= 35) return (char)(val - 10 + 'A');
    return '?';
}

double potencia(double base, int exp) {
    if (exp == 0) return 1.0;
    double res = 1.0;
    for (int i = 0; i < (exp > 0 ? exp : -exp); i++) res *= base;
    return exp > 0 ? res : 1.0 / res;
}

long long stringToLongLong(const string& s) {
    long long res = 0;
    for (char c : s) {
        if (c >= '0' && c <= '9') res = res * 10 + (c - '0');
    }
    return res;
}

string longLongToString(long long v) {
    if (v == 0) return "0";
    string res = "";
    while (v > 0) {
        res = (char)((v % 10) + '0') + res;
        v /= 10;
    }
    return res;
}

string fracionarioParaString(double f, int limit) {
    if (f == 0.0) return "0";
    string res = "";
    while (f > 0 && limit > 0) {
        f *= 10;
        int i = (int)f;
        res += (char)(i + '0');
        f -= i;
        limit--;
    }
    return res;
}

bool validarEntrada(const string& num, int base) {
    for (char c : num) {
        if (c == '.' || c == ',') continue;
        int val = charToVal(c);
        if (val < 0 || val >= base) return false;
    }
    return true;
}

long long baseParaDec(const string& num, int base_origem, bool trace) {
    long long res = 0;
    int len = num.length();
    if (trace) cout << endl << "  [Origem -> Decimal] Regra F2: Somatorio Posicional:" << endl;
    for (int i = 0; i < len; i++) {
        int val = charToVal(num[i]);
        int exp = len - 1 - i;
        long long termo = val * (long long)potencia(base_origem, exp);
        res += termo;
        if (trace) cout << "    Posicao " << exp << ": Digito '" << num[i] << "' (Valor " << val << ") * " << base_origem << "^" << exp << " = " << termo << endl;
    }
    if (trace) cout << "  => Valor Decimal Calculado: " << res << endl;
    return res;
}

string decParaBase(long long n, int base_destino, bool trace) {
    if (n == 0) return "0";
    string res = "";
    if (trace) cout << endl << "  [Decimal -> Destino] Regra F1: Divisoes Sucessivas:" << endl;
    while (n > 0) {
        int resto = n % base_destino;
        char digito = valToChar(resto);
        if (trace) cout << "    " << n << " / " << base_destino << " = " << (n / base_destino) << "  (Resto: " << resto << " -> Digito '" << digito << "')" << endl;
        res = digito + res;
        n /= base_destino;
    }
    if (trace) cout << "  => Lendo restos de baixo para cima: " << res << endl;
    return res;
}

double baseFracParaDec(const string& frac_str, int base_origem, bool trace) {
    double res = 0.0;
    if (trace) cout << endl << "  [Fracionario -> Decimal] Regra F2: Somatorio Posicional Negativo:" << endl;
    for (size_t i = 0; i < frac_str.length(); i++) {
        int val = charToVal(frac_str[i]);
        if (val < 0) continue; 
        double termo = val * (1.0 / potencia(base_origem, i + 1));
        res += termo;
        if (trace) cout << "    Posicao -" << (i+1) << ": Digito '" << frac_str[i] << "' (Valor " << val << ") * " << base_origem << "^-" << (i+1) << " = " << termo << endl;
    }
    if (trace) cout << "  => Fracao Decimal Calculada: " << res << endl;
    return res;
}

string decFracParaBase(double frac, int base_destino, bool trace) {
    string res = "";
    int limit = 16; // F6
    if (trace) cout << endl << "  [Decimal -> Destino Fracionario] Regra F1: Multiplicacoes Sucessivas:" << endl;
    while (frac > 0 && limit > 0) {
        double frac_old = frac;
        frac *= base_destino;
        int inteiro = (int)frac;
        char digito = valToChar(inteiro);
        if (trace) cout << "    " << frac_old << " * " << base_destino << " = " << frac << "  (Inteiro: " << inteiro << " -> Digito '" << digito << "')" << endl;
        res += digito;
        frac -= inteiro;
        limit--;
    }
    if (trace) cout << "  => Lendo inteiros de cima para baixo: ." << res << endl;
    return res;
}

string hexCharToBin(char c) {
    if(c=='0') return "0000"; if(c=='1') return "0001"; if(c=='2') return "0010"; if(c=='3') return "0011";
    if(c=='4') return "0100"; if(c=='5') return "0101"; if(c=='6') return "0110"; if(c=='7') return "0111";
    if(c=='8') return "1000"; if(c=='9') return "1001"; if(c=='A'||c=='a') return "1010"; if(c=='B'||c=='b') return "1011";
    if(c=='C'||c=='c') return "1100"; if(c=='D'||c=='d') return "1101"; if(c=='E'||c=='e') return "1110"; if(c=='F'||c=='f') return "1111";
    return "";
}

string octCharToBin(char c) {
    if(c=='0') return "000"; if(c=='1') return "001"; if(c=='2') return "010"; if(c=='3') return "011";
    if(c=='4') return "100"; if(c=='5') return "101"; if(c=='6') return "110"; if(c=='7') return "111";
    return "";
}

char binToHexChar(string b) {
    if(b=="0000") return '0'; if(b=="0001") return '1'; if(b=="0010") return '2'; if(b=="0011") return '3';
    if(b=="0100") return '4'; if(b=="0101") return '5'; if(b=="0110") return '6'; if(b=="0111") return '7';
    if(b=="1000") return '8'; if(b=="1001") return '9'; if(b=="1010") return 'A'; if(b=="1011") return 'B';
    if(b=="1100") return 'C'; if(b=="1101") return 'D'; if(b=="1110") return 'E'; if(b=="1111") return 'F';
    return '?';
}

char binToOctChar(string b) {
    if(b=="000") return '0'; if(b=="001") return '1'; if(b=="010") return '2'; if(b=="011") return '3';
    if(b=="100") return '4'; if(b=="101") return '5'; if(b=="110") return '6'; if(b=="111") return '7';
    return '?';
}

string expandirParaBin(const string& val, int bitsPorDigito, bool isFrac, bool trace) {
    if(trace) cout << endl << "  [Expansao Direta -> Binario] Transformando cada digito em " << bitsPorDigito << " bits:" << endl;
    string res = "";
    for(char c : val) {
        string bin = (bitsPorDigito == 3) ? octCharToBin(c) : hexCharToBin(c);
        res += bin;
        if(trace) cout << "    Digito '" << c << "' -> " << bin << endl;
    }
    if (!isFrac) {
        int start = 0;
        while(start < res.length() - 1 && res[start] == '0') start++;
        return res.substr(start);
    }
    return res;
}

string agruparBin(string bin, int bits, bool isFrac, bool trace) {
    if(trace) cout << endl << "  [Agrupamento Binario -> Base " << (bits==3?8:16) << "] Agrupando de " << bits << " em " << bits << " bits:" << endl;
    int rem = bin.length() % bits;
    if (rem != 0) {
        int pad = bits - rem;
        if (isFrac) {
            if(trace) cout << "    Padronizando fracao: adicionando " << pad << " zero(s) a direita." << endl;
            for(int i=0; i<pad; i++) bin += '0';
        } else {
            if(trace) cout << "    Padronizando inteiro: adicionando " << pad << " zero(s) a esquerda." << endl;
            string zeros = "";
            for(int i=0; i<pad; i++) zeros += '0';
            bin = zeros + bin;
        }
    }
    string res = "";
    for (size_t i = 0; i < bin.length(); i += bits) {
        string chunk = bin.substr(i, bits);
        char c = (bits == 3) ? binToOctChar(chunk) : binToHexChar(chunk);
        res += c;
        if(trace) cout << "    Grupo " << chunk << " -> " << c << endl;
    }
    if (!isFrac) {
        int start = 0;
        while(start < res.length() - 1 && res[start] == '0') start++;
        res = res.substr(start);
    }
    return res;
}

string converterParteInt(const string& parteInt, int bO, int bD, bool trace) {
    if (bO == bD) return parteInt;
    
    string parteIntMaiuscula = parteInt;
    for(size_t i = 0; i < parteIntMaiuscula.length(); i++) {
        if(parteIntMaiuscula[i] >= 'a' && parteIntMaiuscula[i] <= 'z') {
            parteIntMaiuscula[i] = parteIntMaiuscula[i] - 32;
        }
    }
    
    if (bO == 2 && (bD == 8 || bD == 16)) return agruparBin(parteIntMaiuscula, bD == 8 ? 3 : 4, false, trace);
    if ((bO == 8 || bO == 16) && bD == 2) return expandirParaBin(parteIntMaiuscula, bO == 8 ? 3 : 4, false, trace);
    if ((bO == 8 && bD == 16) || (bO == 16 && bD == 8)) {
        if(trace) cout << endl << "  [Regra F4] Usando Binario como intermediario..." << endl;
        string bin = expandirParaBin(parteIntMaiuscula, bO == 8 ? 3 : 4, false, trace);
        return agruparBin(bin, bD == 8 ? 3 : 4, false, trace);
    }
    
    if (bO == 10) return decParaBase(stringToLongLong(parteIntMaiuscula), bD, trace);
    if (bD == 10) return longLongToString(baseParaDec(parteIntMaiuscula, bO, trace));
    
    return decParaBase(baseParaDec(parteIntMaiuscula, bO, trace), bD, trace);
}

string converterParteFrac(const string& parteFrac, int bO, int bD, bool trace) {
    if (bO == bD) return parteFrac;
    
    string parteFracMaiuscula = parteFrac;
    for(size_t i = 0; i < parteFracMaiuscula.length(); i++) {
        if(parteFracMaiuscula[i] >= 'a' && parteFracMaiuscula[i] <= 'z') {
            parteFracMaiuscula[i] = parteFracMaiuscula[i] - 32;
        }
    }
    
    if (bO == 2 && (bD == 8 || bD == 16)) return agruparBin(parteFracMaiuscula, bD == 8 ? 3 : 4, true, trace);
    if ((bO == 8 || bO == 16) && bD == 2) return expandirParaBin(parteFracMaiuscula, bO == 8 ? 3 : 4, true, trace);
    if ((bO == 8 && bD == 16) || (bO == 16 && bD == 8)) {
        if(trace) cout << endl << "  [Regra F4 Fracionaria] Usando Binario como intermediario..." << endl;
        string bin = expandirParaBin(parteFracMaiuscula, bO == 8 ? 3 : 4, true, trace);
        return agruparBin(bin, bD == 8 ? 3 : 4, true, trace);
    }
    
    if (bO == 10) {
        double f = 0.0, div = 10.0;
        for(char c : parteFracMaiuscula) { f += (c - '0') / div; div *= 10.0; }
        return decFracParaBase(f, bD, trace);
    }
    if (bD == 10) return fracionarioParaString(baseFracParaDec(parteFracMaiuscula, bO, trace), 16);
    
    return decFracParaBase(baseFracParaDec(parteFracMaiuscula, bO, trace), bD, trace);
}

string converterTudo(const string& val, int bO, int bD) {
    string pI = val, pF = "";
    size_t p = val.find('.'); if(p == string::npos) p = val.find(',');
    if(p != string::npos) { pI = val.substr(0, p); pF = val.substr(p+1); }
    
    string res = converterParteInt(pI, bO, bD, false);
    if(res.empty()) res = "0";
    if(!pF.empty()) {
        string rF = converterParteFrac(pF, bO, bD, false);
        if(rF.length() > 16) rF = rF.substr(0, 16);
        res += "." + rF;
    }
    return res;
}

// F10: Calculadora de maximos
void calcularMaximos(int k) {
    long long maxVal = (long long)potencia(2, k) - 1;
    cout << "Maior valor representavel com " << k << " bits:" << endl;
    cout << "Decimal: " << maxVal << endl;
    cout << "Binario: " << decParaBase(maxVal, 2, false) << endl;
    cout << "Octal: " << decParaBase(maxVal, 8, false) << endl;
    cout << "Hexadecimal: " << decParaBase(maxVal, 16, false) << endl;
}