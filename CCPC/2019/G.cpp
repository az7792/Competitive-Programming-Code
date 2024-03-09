#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl '\n'
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
struct Node
{
    vector<vector<char>> A;
    void COUT()
    {
        for (auto v : A)
        {
            for (auto V : v)
                cout << V;
            cout << endl;
        }
    }
} node[11];
void init(int p)
{
    node[p].A.resize(1 << p, vector<char>(1 << p, 0));
    int n = 1 << (p - 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            node[p].A[i][j] = node[p - 1].A[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            node[p].A[i][j + n] = node[p - 1].A[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            node[p].A[i + n][j + n] = node[p - 1].A[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            node[p].A[i + n][j] = node[p - 1].A[i][j] == 'C' ? 'P' : 'C';
}
void solve()
{
    int k;
    cin >> k;
    node[k].COUT();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    node[1].A.resize(2, vector<char>(2, 0));
    node[1].A[0][0] = 'C';
    node[1].A[0][1] = 'C';
    node[1].A[1][0] = 'P';
    node[1].A[1][1] = 'C';
    for (int i = 2; i <= 10; ++i)
        init(i);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}