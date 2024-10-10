#include<bits/stdc++.h>
using namespace std;
int r, n, t = 1, total = 0;
map<char, string> m;

struct node{
    char code = 0;
    int frq = 0;
    bool root = 0;
    node *leaf[10] = {nullptr};
};

bool upper(const node* a, const node* b)
{
    if(a -> frq == b -> frq)
        return a -> code < b -> code;
    return a -> frq < b -> frq;
}

bool cmp(node *a, node *b)
{
    if(a -> frq == b -> frq)
        return a -> code < b -> code;
    return a -> frq < b -> frq;
}

void dfs(node* root, string str)
{
    if(root -> root)
    {
        m[root -> code] = str;
        total += str.size() * root -> frq;
    }
    for(int i = 0; i < r; i++)
    {
        if(root -> leaf[i] != nullptr)
        {
            dfs(root -> leaf[i], str + char('0' + i));
        }
    }
    delete root;
}

int main()
{
    while(cin >> r)
    {
        if(!r)
            break;
        cin >> n;
        int arr[n], frq = 0;
        total = 0;
        vector<node*> v;

        for(int i = 0; i < n; i++)
        {
            node* temp = new node();
            cin >> temp -> frq;
            frq += temp -> frq;
            temp -> code = 'A'+i;
            temp -> root = 1;
            v.push_back(temp);
        }
        while((n-r)%(r-1) != 0)
        {
            node* temp = new node();
            temp -> code = -1;
            v.push_back(temp);
            n++;
        }
        sort(v.begin(), v.end(), cmp);
        while(v.size() >= r)
        {
            node *temp = new node();
            temp -> code = 'Z';
            for(int i = 0; i < r; i++)
            {
                temp -> frq += v[i] -> frq;
                temp -> leaf[i] = v[i];
                if(v[i] -> code >= 'A')
                    temp -> code = min(temp -> code, v[i] -> code);
            }
            v.erase(v.begin(), v.begin() + r);
            auto i = upper_bound(v.begin(), v.end(), temp, upper);
            v.insert(i, temp);
        }
        for(int i = 0; i < v.size(); i++)
        {
            dfs(v[i], "");
        }
        cout << "Set " << t++ << "; average length " << fixed << setprecision(2) << double(total)/frq << endl;
        for(auto i : m)
            cout << "    " << i.first << ": " << i.second << endl;
        cout << endl;
        m.clear();
    }
    return 0;
}
