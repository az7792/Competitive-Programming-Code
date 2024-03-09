#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
vector<vector<int>> g;
vector<int> fa;
vector<int> ans;
vector<int> sum;
string str;
int n;
void dfs(int p)
{
    for (auto v : g[p])
    {
        dfs(v);
        sum[p] += sum[v];
    }
    if (str[p] == 'W')
    {
        ans[p] = 1;
        sum[p] += 1;
    }
    else
    {
        if (sum[p] % 3 == 1)
        {
            ans[p] = 2;
        }
        else if (sum[p] % 3 == 2)
        {
            ans[p] = 1;
        }
        else
        {
            bool f = 0;
            for (auto v : g[p])
            {
                if (str[v] == 'W')
                {
                    ans[v] = 2;
                    ans[p] = 2;
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                cout << -1;
                exit(0);
            }
        }
        sum[p] = 0;
    }
}
void solve()
{
    cin >> n;
    g.resize(n + 1);
    fa.resize(n + 1, 0);
    ans.resize(n + 1, 0);
    sum.resize(n + 1, 0);
    cin >> str;
    str = "*" + str;
    for (int i = 2; i <= n; ++i)
    {
        cin >> fa[i];
        g[fa[i]].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
        cout << ans[i];
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
