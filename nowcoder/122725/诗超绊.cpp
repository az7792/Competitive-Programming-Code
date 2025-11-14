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
bool ok(const vector<ll> &a, int mid, int m)
{
    for (int i = 2; i < a.size(); ++i)
    {
        if (a[i] > a[i-1])
        {
            continue;
        }

        ll n = 1 + (a[i-1] - a[i]) / mid;
        m -= n;
        if (m < 0)
            return false;
    }
    return true;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    bool okk = true;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] <= a[i - 1])
        {
            okk = false;
            break;
        }
    }
    if (okk)
    {
        cout << "0\n";
        return;
    }

    ll l = 1, r = 1e9+10, mid;

    while (l < r)
    {
        mid = (l + r) / 2;
        if (ok(a, mid, m))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << (ok(a, l, m) ? l : -1) << endl;
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