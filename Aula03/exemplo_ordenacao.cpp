#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    sort(v.begin(), v.end());
    auto it = lower_bound(v.begin(), v.end(), 5);
    if (it != v.end() && *it == 5)
    {
        cout << "O elemento 5 está no vetor" << endl;
    }
}