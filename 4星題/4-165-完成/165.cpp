#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int h, k, ans, l;
string s;
void dfs(string str)
{
    int arr[75] = {0};
    for(int i = 1; i < 75; i++)
    {
        arr[i] = 10;
        for(int j = 0; j < v.size(); j++)
        {
            if(i >= v[j])
            {
                arr[i] = min(arr[i], arr[i-v[j]] + 1);
            }
        }
        if(arr[i] > h)
            return;
        if(i > ans)
        {
            ans = i;
            s = str;
        }
    }
}
void f(int n, int t, string str)
{
    if(t == k)
    {
        dfs(str);
        return;
    }
    for(int i = n+1; i < 33; i++)
    {
        v.push_back(i);
        f(i, t+1, str + to_string(i) + ",");
        v.pop_back();
    }
}
int main()
{
    v.push_back(1);
    while(cin >> h >> k)
    {
        if(!h * !k)
            break;
        ans = 0;
        l = 0;
        f(1, 1, "1,");
        for(char c : s)
        {
            if(c == ',')
            {
                cout << setw(3) << l;
                l = 0;
            }
            else
            {
                l *= 10;
                l += c - '0';
            }
        }
        cout << " ->" << setw(3) << ans << endl;
    }
    return 0;
}
