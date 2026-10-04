#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll MOD = 1e9 + 7;
// ll MOD = 998244353;

template <typename T>
std::istream &operator>>(std::istream &_in, std::vector<T> &_a)
{
    for (auto &v : _a)
        _in >> v;
    return _in;
}

template <typename T>
std::ostream &operator<<(std::ostream &_out, std::vector<T> &_a)
{
    if (!_a.empty())
        _out << _a[0];
    for (size_t i = 1; i < _a.size(); ++i)
        _out << " " << _a[i];
    return _out;
}

struct Node
{
    int ch, type;
    bool operator<(const Node &o) const
    {
        if (ch == o.ch)
            return type < o.type;
        return ch < o.ch;
    }
};
int SCCCT = 0;
vector<bool> vis;
vector<int> st;
vector<int> SCC;
vector<vector<Node>> gp;
vector<vector<Node>> gn;
vector<set<Node>> g;
vector<int> ans;
void dfsP(int i)
{
    // cout << i << " ";
    if (vis[i])
        return;

    vis[i] = 1;

    for (auto &v : gp[i])
    {
        dfsP(v.ch);
    }

    st.push_back(i);
}

int dfsN(int i)
{
    if (SCC[i] != -1)
        return 0;
    SCC[i] = SCCCT;
    for (auto &v : gn[i])
    {
        dfsN(v.ch);
    }
    return 1;
}

void dfs(int p)
{
    if (vis[p] == 1)
        return;

    vis[p] = 1;
    if (g[p].empty())
    {
        ans[p] = 1;
        return;
    }

    int Max = 1;
    for (auto &v : g[p])
    {
        dfs(v.ch);
        if (v.type == 0)
        {
            Max = max(Max, ans[v.ch]);
        }
        else
        {
            Max = max(Max, ans[v.ch] + 1);
        }
    }
    ans[p] = Max;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    gp.resize(n + 1);
    gn.resize(n + 1);
    vis.resize(n + 1, 0);
    SCC.resize(n + 1, -1);
    vector<int> fanum(n + 1, 0);

    for (int i = 1; i <= q; ++i)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if (u == v)
        {
            if (t == 0)
            {
                continue;
            }
            else
            {
                cout << "No";
                return;
            }
        }
        gp[v].push_back({u, t});
        fanum[u]++;
        gn[u].push_back({v, t});
    }

    for (int i = 1; i <= n; ++i)
    {
        dfsP(i);
    }

    // if (st.empty())
    // {
    //     dfsP(1);
    // }
    // cout << endl;

    // cout << st;

    for (auto it = st.rbegin(); it != st.rend(); it++)
    {
        // cout << *it << " ";
        SCCCT += dfsN(*it);
    }
    // cout << endl;

    //cout << SCC << endl;

    g.resize(SCCCT);
    fanum.assign(SCCCT, 0);
    vis.assign(SCCCT, 0);
    ans.assign(SCCCT, 1);
    for (int i = 1; i <= n; ++i)
    {
        for (auto &v : gp[i])
        {
            if (SCC[i] == SCC[v.ch] && v.type == 1)
            {
                cout << "No";
                return;
            }
            else if (SCC[i] != SCC[v.ch])
            {
                g[SCC[i]].insert({SCC[v.ch], v.type});
            }
        }
    }

    // for (int i = 0; i < SCCCT; ++i)
    // {
    //     cout << i << ":";
    //     for (auto v : g[i])
    //     {
    //         cout << v.ch << "," << v.type << " ";
    //         fanum[v.ch]++;
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for (int i = 0; i < SCCCT; ++i)
    {
        if (fanum[i] == 0)
        {
            dfs(i);
        }
    }

    //cout << ans;
    cout << "Yes\n";
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[SCC[i]] << " ";
    }
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