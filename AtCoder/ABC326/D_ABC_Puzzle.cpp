#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
struct Node
{
    int a, b, c;
};
vector<vector<char>> G;
vector<vector<Node>> mp(6);
string tt = "ABC";
int n;
string R, C;
bool ok()
{
    for (int i = 0; i < n; ++i) // hang
    {
        vector<int> a(3, 0);
        for (int j = 0; j < n; ++j)
            if (G[i][j] != '.')
                a[G[i][j] - 'A']++;
        if (a != vector<int>(3, 1))
            return false;
    }
    for (int i = 0; i < n; ++i) // lie
    {
        vector<int> a(3, 0);
        for (int j = 0; j < n; ++j)
            if (G[j][i] != '.')
                a[G[j][i] - 'A']++;
        if (a != vector<int>(3, 1))
            return false;
    }
    for (int i = 0; i < n; ++i)
    {
        bool ook = false;
        for (int j = 0; j < n; ++j)
        {
            if (G[j][i] == '.')
                continue;
            if (G[j][i] == C[i])
            {
                ook = true;
                break;
            }
            else
            {
                break;
            }
        }
        if (!ook)
            return false;
    }
    return true;
}
void pf()
{
    cout << "Yes\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << G[i][j];
        cout << endl;
    }
    exit(0);
}

void dfs4(int p)
{
    if (p == n)
    {
        if (ok())
        {
            pf();
        }
        return;
    }
    for (auto v : mp[n])
    {
        vector<bool> f(n, 0);
        f[v.a] = 1;
        f[v.b] = 1;
        f[v.c] = 1;
        G[p][v.a] = R[p];
        if (R[p] == 'A')
        {
            for (int i = 0; i < n; ++i)
                if (!f[i])
                    G[p][i] = '.';
            G[p][v.b] = 'B';
            G[p][v.c] = 'C';
            dfs4(p + 1);
            G[p][v.b] = 'C';
            G[p][v.c] = 'B';
            dfs4(p + 1);
        }
        else if (R[p] == 'B')
        {
            for (int i = 0; i < n; ++i)
                if (!f[i])
                    G[p][i] = '.';
            G[p][v.b] = 'A';
            G[p][v.c] = 'C';
            dfs4(p + 1);
            G[p][v.b] = 'C';
            G[p][v.c] = 'A';
            dfs4(p + 1);
        }
        else
        {
            for (int i = 0; i < n; ++i)
                if (!f[i])
                    G[p][i] = '.';
            G[p][v.b] = 'A';
            G[p][v.c] = 'B';
            dfs4(p + 1);
            G[p][v.b] = 'B';
            G[p][v.c] = 'A';
            dfs4(p + 1);
        }
    }
}
void solve()
{
    G.clear();
    cin >> n >> R >> C;
    G.resize(n, vector<char>(n));
    dfs4(0);
    cout << "No";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));

    mp[3].push_back({0, 1, 2});

    mp[4].push_back({0, 1, 2});
    mp[4].push_back({0, 1, 3});
    mp[4].push_back({0, 2, 3});
    mp[4].push_back({1, 2, 3});

    mp[5].push_back({0, 1, 2}); // 34
    mp[5].push_back({0, 1, 3}); // 24
    mp[5].push_back({0, 1, 4}); // 23
    mp[5].push_back({0, 2, 3}); // 14
    mp[5].push_back({0, 2, 4}); // 13
    mp[5].push_back({0, 3, 4}); // 12
    mp[5].push_back({1, 2, 3}); // 04
    mp[5].push_back({1, 2, 4}); // 03
    mp[5].push_back({1, 3, 4}); // 02
    mp[5].push_back({2, 3, 4}); // 01
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}