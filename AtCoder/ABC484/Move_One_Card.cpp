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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;

    int s, e;
    for (s = 0; s < n; ++s)
    {
        if (a[s] != b[s])
            break;
    }
    for (e = n - 1; e >= 0; --e)
    {
        if (a[e] != b[e])
            break;
    }

    if (s == n)
    {
        cout << "Yes";
        return;
    }

    // s - e
    vector<int> ts(a.begin() + s + 1, a.begin() + e + 1);
    ts.push_back(a[s]);
    vector<int> te(b.begin() + s, b.begin() + e + 1);

    if (ts == te)
    {
        cout << "Yes";
        return;
    }

    ts.assign(a.begin() + s, a.begin() + e + 1);
    te.assign(b.begin() + s + 1, b.begin() + e + 1);
    te.push_back(b[s]);

    if (ts == te)
    {
        cout << "Yes";
        return;
    }

    cout << "No";
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