#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
vector<pii> a, g;
vector<int> ans;
int n, m, Rank = 1000;
void dfs(int p)
{
    if (p == m)
    {
        vector<pii> tmpa = a;
        for (int i = 0; i < m; ++i)
        {
            int op = ans[i];
            if (op == 0)
            {
                tmpa[g[i].first].first++;
                tmpa[g[i].second].first++;
            }
            else if (op == 1) // win l
                tmpa[g[i].first].first += 3;
            else
                tmpa[g[i].second].first += 3;
        }
        sort(tmpa.begin() + 1, tmpa.end(), [](pii aa, pii bb)
             { return aa.first > bb.first; });
        int nowr = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (tmpa[i].first != tmpa[i - 1].first)
                nowr = i;
            if (tmpa[i].second == 1)
                break;
        }
        Rank = min(Rank, nowr);
        return;
    }
    ans.push_back(0);
    dfs(p + 1);
    ans.pop_back();

    ans.push_back(1);
    dfs(p + 1);
    ans.pop_back();

    ans.push_back(2);
    dfs(p + 1);
    ans.pop_back();
}
void solve()
{
    cin >> n >> m;
    ans.clear();
    Rank = 1000;
    a.resize(n + 1, {0, 0});
    a[0].first = -1;
    g.resize(m, {0, 0});
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> g[i].first >> g[i].second;
    }
    dfs(0);
    cout << Rank << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
