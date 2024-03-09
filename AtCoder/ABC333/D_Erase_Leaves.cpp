#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 3e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<int> G[MAX];
vector<bool> vis(MAX, 0);
vector<int> num(MAX, 0);
vector<int> e(MAX, 0);
void solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        e[u]++;
        e[v]++;
    }
    if (e[1] == 1)
    {
        cout << 1;
        return;
    }
    queue<int> Q;
    for (int i = 1; i <= n; ++i)
    {
        if (e[i] == 1)
        {
            vis[i] = 1;
            Q.push(i);
        }
    }
    while (!Q.empty())
    {
        int Node = Q.front();
        Q.pop();
        for (auto v : G[Node])
        {
            if (!vis[v])
            {
                num[v] += num[Node] + 1;
                e[v]--;
                if (e[v] == 1 && v != 1)
                {
                    vis[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
    vector<int> ans;
    for (auto v : G[1])
    {
        ans.push_back(num[v]);
    }
    sort(all(ans));
    int sum = 0;
    for (int i = 0; i < ans.size() - 1; ++i)
    {
        sum += ans[i] + 1;
    }
    cout << sum + 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
