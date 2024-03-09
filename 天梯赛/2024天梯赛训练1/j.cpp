#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
vector<int> a[10010];
vector<int> ans;
int len = 0;
void Dfs(int p, int st)
{
    if (a[p].size() == 0)
    {
        len = max(len, st);
        return;
    }
    for (auto v : a[p])
    {
        Dfs(v, st + 1);
    }
}
void dfs(int p, int st)
{
    if (st == len)
    {
        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i];
            if (i != ans.size() - 1)
                cout << " ";
        }
        exit(0);
    }
    for (auto v : a[p])
    {
        ans.push_back(v);
        dfs(v, st + 1);
        ans.pop_back();
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; ++i)
    {
        int k, tmp;
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> tmp;
            vis[tmp] = 1;
            a[i].push_back(tmp);
        }
        sort(all(a[i]));
    }
    int p;
    for (p = 0; p < n; ++p)
        if (vis[p] == 0)
            break;
    Dfs(p, 1);
    cout << len << endl;
    ans.push_back(p);
    dfs(p, 1);
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
