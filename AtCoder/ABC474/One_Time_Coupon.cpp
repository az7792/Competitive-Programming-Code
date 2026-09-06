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
    vector<ll> a(n), b(n), c(n);
    ll minA = 1e9 + 1;
    ll sumA = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
        c[i] = a[i] - b[i];
        sumA += a[i];
        minA = min(minA, (ll)a[i]);
    }

    sort(all(c), std::greater<ll>());
    for (int i = 1; i < c.size(); ++i)
        c[i] += c[i - 1];
    ll ans = 2e18;

    for (int i = 0; i <= n; ++i)
    {
        if (i == 0)
        {
            ans = min(ans, sumA);
        }
        else
        {
            ans = min(ans, sumA - c[i - 1] + max(0ll, 2ll * i - n) * minA);
        }
    }

    cout << ans << endl;
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