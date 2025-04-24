#include <iostream>
using namespace std;
int main(void)
{
    int num_concursos, qtd_incriveis = 0, pontuacao_atual, pontuacao_maxima, pontuacao_minima;
    cin >> num_concursos;
    cin >> pontuacao_atual;
    pontuacao_maxima = pontuacao_atual;
    pontuacao_minima = pontuacao_atual;
    for (int i = 1; i < num_concursos; i++)
    {
        cin >> pontuacao_atual;
        if (pontuacao_atual > pontuacao_maxima)
        {
            pontuacao_maxima = pontuacao_atual;
            qtd_incriveis++;
        }
        if (pontuacao_atual < pontuacao_minima)
        {
            pontuacao_minima = pontuacao_atual;
            qtd_incriveis++;
        }
    }
    cout << qtd_incriveis << endl;

    return 0;
}