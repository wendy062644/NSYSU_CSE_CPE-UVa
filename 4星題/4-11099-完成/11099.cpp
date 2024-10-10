#include<bits/stdc++.h>
#define int long long int
using namespace std;
vector<int> prime, v;
bool not_prime[2000000] = {0};
int ans, n;
void f(int sum, int index)
{
    if(index-1 >= 0)
        f(sum, index-1);
    for(int i = 0; i < 20 && sum * v[index] < ans; i++)
    {
        sum *= v[index];
        if(sum > n)
        {
            ans = sum;
            break;
        }
        else if(index-1 >= 0)
            f(sum, index-1);
    }
}

signed main()
{
    for(int i = 2; i < 2000000; i++)
    {
        if(!not_prime[i])
        {
            prime.push_back(i);
            for(int j = i+i; j < 2000000; j+=i)
                not_prime[j] = 1;
        }
    }
    while(cin >> n)
    {
        int sum = 1, m = n;
        for(int i = 0; i < prime.size() && m >= prime[i]; i++)
        {
            if(n%prime[i] == 0)
            {
                sum *= prime[i];
                while(m%prime[i] == 0)
                    m /= prime[i];
                v.push_back(prime[i]);
            }
        }
        ans = 2000000;
        if(v.size() > 0)
            f(sum, v.size()-1);
        if(ans < 2000000)
            cout << ans << endl;
        else
            cout << "Not Exist!\n";
        v.clear();
    }
    return 0;
}
