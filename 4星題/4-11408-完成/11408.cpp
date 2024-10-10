#include<bits/stdc++.h>
using namespace std;
bool prime[5000001] = {0};
long long int arr[5000001] = {0};
vector<int> v;
int main()
{
    int a, b;
    for(int i = 2; i <= 5000000; i++)
    {
        if(!prime[i])
        {
            for(int j = i+i; j <= 5000000; j += i)
            {
                prime[j] = 1;
                arr[j] += i;
            }
            arr[i] = i;
        }
        arr[i] = arr[i-1] + !prime[arr[i]];
    }
    while(cin >> a >> b && a*b)
    {
        cout << arr[b] - arr[a-1] << endl;
    }
    return 0;
}
