#include<bits/stdc++.h>
using namespace std;
struct block{
    int x, y, z;
};
bool cmp(block a, block b)
{
    if(a.x == b.x && a.y == b.y)
        return a.z > b.z;
    if(a.x == b.x)
        return a.y > b.y;
    return a.x > b.x;
}
int main()
{
    int n, t = 1;
    while(cin >> n)
    {
        if(!n)
            break;
        vector<block> v;
        for(int i = 0; i < n; i++)
        {
            block temp;
            cin >> temp.x >> temp.y >> temp.z;
            v.push_back(temp); //123
            swap(temp.x, temp.y);
            v.push_back(temp); //213
            swap(temp.y, temp.z);
            v.push_back(temp); //231
            swap(temp.x, temp.y);
            v.push_back(temp); //321
            swap(temp.y, temp.z);
            v.push_back(temp); //312
            swap(temp.x, temp.y);
            v.push_back(temp); //132
        }
        sort(v.begin(), v.end(), cmp);
        int arr[v.size()] = {v[0].z}, ans = arr[0];
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(v[j].x > v[i].x && v[j].y > v[i].y)
                {
                    arr[i] = max(arr[i], arr[j] + v[i].z);
                    ans = max(ans, arr[i]);
                }
            }
            //cout << v[i].x << ' ' << v[i].y << ' ' << v[i].z << ' ' << arr[i] << endl;
            if(arr[i] == 0)
                arr[i] = v[i].z;
            ans = max(ans, arr[i]);
        }
        cout << "Case " << t++ << ": maximum height = " << ans << endl;
    }
    return 0;
}
