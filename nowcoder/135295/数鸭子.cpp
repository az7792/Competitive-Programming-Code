#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll MOD = 20260601;
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

ll POW(ll a, ll b)
{
    a %= MOD;
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return POW((a * a) % MOD, b / 2) % MOD;
    else
        return (POW((a * a) % MOD, b / 2) % MOD * a) % MOD;
}

set<int> st = {2, 4, 6, 7, 8};
int get(int num)
{
    int ans = 0;
    for (auto v : st)
        if (num > v)
            ans++;
    return ans;
}
void solve()
{
    // 24678

    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        ans = ans + POW(5, i);
        ans %= MOD;
    }
    bool ok = true;
    for (int i = 0; i < n; ++i)
    {
        ans = ans + (POW(5, (n - i - 1))) * get(s[i] - '0');
        ans = ans % MOD;
        if (st.find(s[i] - '0') == st.end())
        {
            ok = false;
            break;
        }
    }
    if (st.find(s[n - 1] - '0') != st.end() && ok)
        ans++;
    ans %= MOD;
    cout << ans;
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