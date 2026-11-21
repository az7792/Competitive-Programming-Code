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

struct Nodebfs
{
    int now, prev, c, sum;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<pii>> g(n + 1);
    map<pii, bool> mp;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].insert({b, c});
    }

    queue<Nodebfs> Q;

    Q.push({1, 0, 0, 0});

    while (!Q.empty())
    {
        Nodebfs tmp = Q.front();
        Q.pop();

        if (tmp.now == n)
        {
            cout << tmp.sum;
            return;
        }

        set<pii> save;

        for (auto &v : g[tmp.now])
        {
            if (tmp.c == v.second)
            {
                save.insert(v);
                continue;
            }

            auto it = mp.find({v.first, v.second});
            if (it != mp.end())
                continue;

            mp[{v.first, v.second}] = true;
            Q.push({v.first, tmp.now, v.second, tmp.sum + 1});
        }

        swap(save, g[tmp.now]);
    }

    cout << -1;
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