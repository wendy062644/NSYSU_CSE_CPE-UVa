#include<bits/stdc++.h>
using namespace std;
int main()
{
    char temp;
    long long int a, b, number[30005] = {1}, arr[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
    number[0] = 1;
    for(int i = 10; i >= 0; i--)
    {
        for(int j = arr[i]; j <= 30000; j+=5)
        {
            number[j] += number[j-arr[i]];
        }
    }
    while(cin >> a >> temp >> b)
    {
        if(!a && !b)
            break;
        printf("%3d.%02d %16lld\n", a, b, number[int(a*100+b)]);
    }
    return 0;
}
