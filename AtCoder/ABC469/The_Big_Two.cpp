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

void solve()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> h_c;
    unordered_map<int, unordered_set<int>> c_h;
    map<pii, int> mp;
    vector<unordered_set<int>> hpk(n + 1);
    vector<pii> pk(m + 1);

    for (int i = 0; i < m; ++i)
    {
        cin >> pk[i].first >> pk[i].second;
        mp[pk[i]]++;
        hpk[pk[i].first].insert(pk[i].second);
        hpk[pk[i].second].insert(pk[i].first);

        h_c[pk[i].first]++;
        h_c[pk[i].second]++;
    }

    for (auto &v : h_c)
    {
        c_h[v.second].insert(v.first);
    }

    set<pii> ans;
    for (int i = 0; i < pk.size(); ++i)
    {
        int h1 = pk[i].first, h2 = pk[i].second;
        auto it = mp.find(pk[i]);
        if (h_c[h1] + h_c[h2] - (*it).second == m)
        {
            ans.insert(pk[i]);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        int num = m - h_c[i];
        auto &vec = c_h[num];

        for (auto &v : vec)
        {
            if (hpk[i].find(v) == hpk[i].end() && i != v)
            {
                if (i < v)
                    ans.insert({i, v});
                else
                    ans.insert({v, i});
            }
        }
    }

    cout << ans.size();
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