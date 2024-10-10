#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    while(cin >> n)
    {
        if(!n)
            break;
        cin >> m;
        int Max = -1;
        vector<int> ans;
        for(int t = 0; t < m; t++)
        {
            cin >> k;
            int arr[k], index = 0;
            vector<int> v;
            v.push_back(0);
            for(int i = 0; i < k; i++)
            {
                cin >> arr[i];
            }
            while(++index)
            {
                int temp = n+1;
                for(int i = 0; i < k; i++)
                    if(index >= arr[i])
                    {
                        temp = min(temp, v[index - arr[i]] + 1);
                    }
                if(temp > n)
                    break;
                v.push_back(temp);
            }
            if(index-1 > Max)
            {
                Max = index-1;
                ans.assign(arr, arr+k);
            }
            else if(index-1 == Max)
            {
                if(ans.size() > k)
                    ans.assign(arr, arr+k);
                else if(ans.size() == k)
                {
                    for(int i = ans.size() - 1; i >= 0; i--)
                    {
                        if(ans[i] > arr[i])
                        {
                            ans.assign(arr, arr+k);
                            break;
                        }
                        else if(arr[i] > ans[i])
                            break;
                    }
                }
            }
        }
        cout << "max coverage =" << setw(4) << Max << " :";
        for(int i : ans)
            cout << setw(3) << i;
        cout << endl;
    }
    return 0;
}
