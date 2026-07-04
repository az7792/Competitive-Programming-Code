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
    ll x, y, k;
    cin >> x >> y >> k;
    // A: x // k
    // B: [kx, kx + k - 1] // 33, 33 + 2
    // B->A: no
    // A->B: x - x % k
    // n * A -> m * B
    // kx <= y && y <= kx + k - 1

    // [(y + 1 - k + k - 1) / k, y / k]
    unordered_map<ll, int> mp;
    int ct = 0;
    while (x != 0)
    {
        mp[x] = ct;
        x /= k;
        ct++;
    }
    mp[0] = ct;

    int ans = 1e9;

    ct = 0;
    while (y != 0)
    {
        auto it = mp.find(y);
        if (it != mp.end())
        {
            ans = min(ans, ct + it->second);
        }
        y /= k;
        ct++;
    }

    auto it = mp.find(y);
    if (it != mp.end())
    {
        ans = min(ans, ct + it->second);
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