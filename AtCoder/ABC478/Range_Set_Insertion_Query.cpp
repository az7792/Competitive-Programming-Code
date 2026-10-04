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
    int l, r;
    bool operator<(const Node &o) const
    {
        return l < o.l;
    }
};

void merge(vector<Node> &a)
{
    vector<Node> ans;
    sort(all(a));

    ans.push_back(*a.begin());

    for (int i = 1; i < a.size(); ++i)
    {
        if (ans.back().r >= a[i].l)
        {
            ans.back().r = max(ans.back().r, a[i].r);
        }
        else
        {
            ans.push_back(a[i]);
        }
    }

    a = ans;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    map<int, vector<Node>> mp;
    for (int i = 0; i < q; ++i)
    {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        mp[a3].push_back({a1, a2});
    }
    for (auto &v : mp)
    {
        merge(v.second);
    }
    vector<ll> ans(n + 2, 0);
    for (auto &v : mp)
    {
        for (auto &vv : v.second)
        {
            ans[vv.l]++;
            ans[vv.r + 1]--;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        ans[i] += ans[i - 1];
        cout << ans[i] << " ";
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