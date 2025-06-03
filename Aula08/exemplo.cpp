#include <iostream>

using namespace std;

int dp(int precos, int mem, int dinheiro, int loja, int orcamento)
{
    if (dinheiro < 0)
        return -10000;
    if (loja == qtd_lojas)
        return orcamento - dinheiro;
    if (mem[dinheiro][loja] != -1)
        return mem[dinheiro][loja];
    int ans = -1;
    for (int i = 0; i < itens; ++i)
    {
        ans = max(ans, dp(precos, mem, dinheiro - precos[loja][i], loja + 1));
    }
    mem[dinheiro][loja] = ans;
    return ans;
}

int main()
{
    int orcamento = 10, qtd_lojas = 3, itens = 3;

    int precos[3][3] = {
        {2, 3, 5},
        {3, 4, 6},
        {2, 5, 7},
    }

    return 0;
}