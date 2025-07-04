#include <iostream>
#include <vector>
#include <numeric> // Para iota, se necessário para inicializar visitados

using namespace std;

// A função DFS fornecida
int dfs(vector<vector<int>> &grafo, vector<bool> &visitados, int atual, int valor_procurado) {
    int x = 1;
    visitados[atual] = true;
    for (int i = 0; i < grafo[atual].size(); i++) {
        if (!visitados[grafo[atual][i]] && grafo[atual][i] != valor_procurado) {
            x += dfs(grafo, visitados, grafo[atual][i], valor_procurado);
        }
    }
    return x; // É importante retornar 'x' aqui, caso contrário a função não faria sentido
}

int main() {
    int num_nos = 5; // Exemplo: 5 nós (0, 1, 2, 3, 4)

    // 1. Declarar e redimensionar o grafo
    vector<vector<int>> grafo;
    grafo.resize(num_nos);

    // 2. Função auxiliar para adicionar arestas (para um grafo não direcionado)
    auto adicionarAresta = [&](int u, int v) {
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    };

    // 3. Adicionar as arestas do seu grafo
    adicionarAresta(0, 1);
    adicionarAresta(0, 2);
    adicionarAresta(1, 3);
    adicionarAresta(2, 4);
    adicionarAresta(3, 4); // Adicionando mais uma aresta para um exemplo mais interessante

    // Inicializar o vetor de visitados
    vector<bool> visitados(num_nos, false);

    // Exemplo de uso da DFS:
    // Começar a DFS do nó 0, excluindo o valor 4
    int no_inicial_dfs = 0;
    int valor_a_excluir = 4;
    int tamanho_componente = dfs(grafo, visitados, no_inicial_dfs, valor_a_excluir);

    cout << "Tamanho do componente conectado a partir do no " << no_inicial_dfs
              << " (excluindo " << valor_a_excluir << "): " << tamanho_componente << endl;

    // Se você quiser encontrar outro componente, precisaria resetar o vetor 'visitados'
    fill(visitados.begin(), visitados.end(), false);
    int no_inicial_dfs2 = 1;
    int valor_a_excluir2 = 0;
    int tamanho_componente2 = dfs(grafo, visitados, no_inicial_dfs2, valor_a_excluir2);
    cout << "Tamanho do componente conectado a partir do no " << no_inicial_dfs2
              << " (excluindo " << valor_a_excluir2 << "): " << tamanho_componente2 << endl;

    return 0;
}