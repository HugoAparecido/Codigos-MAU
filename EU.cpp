#include <iostream>
using namespace std;
int main(void)
{
    int num_problemas, petya, vasya, tonya, problemas_resolvidos = 0;
    cin >> num_problemas;
    for (int i = 0; i < num_problemas; i++)
    {
        cin >> petya >> vasya >> tonya;
        if (petya + vasya + tonya >= 2)
        {
            problemas_resolvidos++;
        }
    }
    cout << problemas_resolvidos << endl;
    return 0;
}