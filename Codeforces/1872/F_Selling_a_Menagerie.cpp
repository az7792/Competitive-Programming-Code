#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<bool> vis;
vector<int> ans;
vector<int> tmp;
vector<ll> a, c;
void dfs(int p)
{
    if (vis[p])
    {
        // int p = min_element(all(tmp)) - tmp.begin();

        int N = tmp.size();
        int Max = 1e9 + 10;
        for (int i = 0; i < N; ++i)
        {
            if (c[tmp[i]] < Max)
            {
                Max = c[tmp[i]];
                p = i;
            }
        }
        int i = (p + 1) % N;
        do
        {
            ans.push_back(tmp[i]);
            i = (i + 1) % N;
        } while (i != p);
        ans.push_back(tmp[p]);
        return;
    }
    vis[p] = true;
    tmp.push_back(p);
    dfs(a[p]);
}
void solve()
{
    ans.clear();
    a.clear();
    c.clear();
    int n;
    cin >> n;
    a.resize(n + 1);
    c.resize(n + 1);
    vector<ll> d(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        d[a[i]]++;
    }
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    queue<int> Q;
    for (int i = 1; i <= n; ++i)
        if (d[i] == 0)
            Q.push(i);
    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        ans.push_back(p);
        d[a[p]]--;
        if (d[a[p]] == 0)
            Q.push(a[p]);
    }
    vis.clear();
    vis.resize(n + 1, false);
    for (int i = 1; i <= n; ++i)
    {
        if (d[i] > 0 && vis[i] == false)
        {
            tmp.clear();
            dfs(i);
        }
    }
    for (auto v : ans)
        cout << v << " ";
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}