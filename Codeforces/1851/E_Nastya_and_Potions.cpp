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
vector<ll> C(MAX, 0), P(MAX, 0), tmpC(MAX, 0);
vector<ll> G[MAX];
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        G[i].clear(), P[i] = 0, tmpC[i] = 0;

    for (int i = 1; i <= n; ++i)
        cin >> C[i];

    for (int i = 1, tmp; i <= k; ++i)
    {
        cin >> tmp;
        C[tmp] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        int m;
        cin >> m;
        for (int j = 1, tmp; j <= m; ++j)
        {
            cin >> tmp;
            G[tmp].eb(i);
            P[i]++;
        }
    }
    queue<int> Q;
    for (int i = 1; i <= n; ++i)
        if (P[i] == 0)
            Q.push(i);
    while (!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        for (auto v : G[node])
        {
            P[v]--;
            tmpC[v] += C[node];
            if (P[v] == 0)
            {
                C[v] = min(C[v], tmpC[v]);
                Q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << C[i] << " \n"[i == n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/