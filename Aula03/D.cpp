#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ehEstritamenteCrescente(const vector<int>& array) {
    if (array.size() <= 1) {
        return true;
    }
    for (size_t i = 0; i < array.size() - 1; ++i) {
        if (array[i] >= array[i + 1]) {
            return false;
        }
    }
    return true;
}

bool podeSerEstritamenteCrescente(const vector<int>& array, int prucurado) {
    int n = array.size();
    if (n <= 1) {
        return true;
    }

    vector<int> b = array; // Tentativa 1: manter os valores iniciais

    for (int i = 0; i < (1 << n); ++i) { // Iterar por todas as 2^n combinações
        vector<int> tentativa;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) { // Se o j-ésimo bit estiver setado, subtrai
                tentativa.push_back(prucurado - array[j]);
            } else { // Caso contrário, mantém o valor original
                tentativa.push_back(array[j]);
            }
        }
        if (ehEstritamenteCrescente(tentativa)) {
            return true;
        }
    }

    return false;
}

int main() {
    int num_casos;
    cin >> num_casos;
    while (num_casos--) {
        int n, m;
        cin >> n >> m; // Ler n (tamanho do vetor array) e m (tamanho do vetor prucurado, que assumimos ser 1)
        vector<int> array(n);
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
        }
        vector<int> prucurado(m);
        cin >> prucurado[0]; // Ler o valor de prucurado

        if (podeSerEstritamenteCrescente(array, prucurado[0])) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}