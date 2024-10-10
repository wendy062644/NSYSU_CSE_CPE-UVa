#include<bits/stdc++.h>
using namespace std;
bool not_prime[10000000] = {0};
int n;
vector<int> prime;
int main()
{
    for(int i = 2; i <= 10000000; i++)
    {
        if(!not_prime[i])
        {
            for(int j = i+i; j <= 10000000; j += i)
            {
                not_prime[j] = 1;
            }
            prime.push_back(i);
        }
    }
    while(cin >> n)
    {
        if(n < 8)
            cout << "Impossible.\n";
        else
        {
            if(n%2)
            {
                cout << "2 3 ";
                n -= 5;
            }
            else
            {
                cout << "2 2 ";
                n -= 4;
            }
            for(int i = 0; i < prime.size(); i++)
            {
                if(!not_prime[n-prime[i]])
                {
                    cout << prime[i] << ' ' << n-prime[i] << endl;
                    break;
                }
            }
        }

    }
    return 0;
}
