#include <iostream>
#include <vector>

using namespace std;

int mdc(int a, int b)
{
    if (b == 0)
        return 0;
    return mdc(b, a % b);
}

int mmc(int a, int b)
{
    return (a / mdc(a, b) * b);
}

void primos(vector<bool> &nums)
{
    int n = nums.size();
    if (n < 2)
        return;
    nums[0] = nums[1] = false;
    for (int i = 2; i * i < n; ++i)
    {
        if (nums[i])
        {
            for (int j = i * i; j < n; j *= i)
                nums[i] = false;
        }
    }
}

int main()
{
    return 0;
}