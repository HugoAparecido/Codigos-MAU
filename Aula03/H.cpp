#include <iostream>
using namespace std;
int main(void)
{
    int qtd_amigos, qtd_garrafas, litros_garrafa, qtd_limoes, qtd_fatias, qtd_sal, bebida_amigo, grama_sal, qtd_por_amigo;
    cin >> qtd_amigos >> qtd_garrafas >> litros_garrafa >> qtd_limoes >> qtd_fatias >> qtd_sal;
    cin >> bebida_amigo >> grama_sal;
    qtd_por_amigo = (qtd_garrafas * litros_garrafa) / (bebida_amigo * qtd_amigos);
    if (qtd_por_amigo > (qtd_limoes * qtd_fatias) / qtd_amigos)
    {
        qtd_por_amigo = (qtd_limoes * qtd_fatias) / qtd_amigos;
    }
    if (qtd_por_amigo > qtd_sal / (grama_sal * qtd_amigos))
    {
        qtd_por_amigo = qtd_sal / (grama_sal * qtd_amigos);
    }
    cout << qtd_por_amigo << endl;

    return 0;
}