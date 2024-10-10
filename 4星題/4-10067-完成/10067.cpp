#include<bits/stdc++.h>
using namespace std;
struct node{
    int n = 0, t = 0;
};
int main()
{
    int t, n, m, goal = 0;
    cin >> t;
    while(t--)
    {
        node temp;
        queue<node> q;
        bool had_pass[10000] = {0}, ok = 0;
        for(int i = 0; i < 4; i++)
        {
            cin >> m;
            temp.n *= 10;
            temp.n += m;
        }
        q.push(temp);
        goal = 0;
        for(int i = 0; i < 4; i++)
        {
            cin >> m;
            goal *= 10;
            goal += m;
        }
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(int j = 0; j < 4; j++)
            {
                cin >> m;
                sum *= 10;
                sum += m;
            }
            //if(sum != q.front().n)
            had_pass[sum] = 1;
        }
        if(q.front().n == goal)
        {
            cout << 0 << endl;
        }
        else
        {
            while(!q.empty())
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 2; j++)
                    {
                        int next = q.front().n + j * pow(10, 3-i) - !j * pow(10, 3-i);
                        m = q.front().n % int(pow(10, 4-i)) / int(pow(10, 3-i));
                        if(m == 9 && j)
                            next = q.front().n - 9*pow(10, 3-i);
                        else if(m == 0 && !j)
                            next = q.front().n + 9*pow(10, 3-i);
                        if(next == goal)
                        {
                            ok = 1;
                            cout << q.front().t + 1 << endl;
                            break;
                        }
                        if(had_pass[next])
                            continue;
                        else
                        {
                            had_pass[next] = 1;
                            node temp;
                            temp.n = next;
                            temp.t = q.front().t+1;
                            q.push(temp);
                        }
                    }
                }
                q.pop();
                if(ok)
                    break;
            }
            if(!ok)
                cout << -1 << endl;
        }
        while(!q.empty())
            q.pop();
    }
    return 0;
}
