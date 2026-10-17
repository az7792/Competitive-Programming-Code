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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    vector<ll> suma(n + 1);
    vector<ll> sumnum(n + 1);
    vector<ll> num(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        suma[i] = suma[i - 1] + a[i];
        sumnum[i] = sumnum[i - 1] + suma[i];
        num[i] = num[i - 1] + i;
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        int pl = lower_bound(num.begin() + 1, num.end(), l) - num.begin();
        int pr = lower_bound(num.begin() + 1, num.end(), r) - num.begin();
        ll ans = 0;
        if (pr - pl >= 1)
        {
            ans = sumnum[pr - 1] - sumnum[pl];
        }
        if (pl == pr)
        {
            ans += suma[r - num[pr - 1]] - suma[l - num[pl - 1] - 1];
        }
        else
        {
            // num[pl]
            // l - num[pl - 1]
            ans += suma[pl] - suma[l - num[pl - 1] - 1];
            // num[pr]
            ans += suma[r - num[pr - 1]];
        }
        cout << ans << endl;
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