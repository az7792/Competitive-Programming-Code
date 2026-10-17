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
    ll n, k, t;
    cin >> n >> k >> t;
    vector<int> a(n);
    cin >> a;
    sort(all(a));
    vector<pair<ll, ll>> arr;
    for (auto v : a)
    {
        if (arr.empty())
        {
            arr.push_back({v, v + k});
        }
        else
        {
            if (v <= arr.back().second)
            {
                arr.back().second = v + k;
            }
            else
            {
                arr.push_back({v, v + k});
            }
        }
    }

    ll ans = 0;
    if (arr.front().first > 0)
    {
        ll num = min(t, arr.front().first);
        ans += (num + k - 1) / k;
        arr.front().second = max(arr.front().second, ans * k);
    }

    if (arr.front().second >= t)
    {
        cout << ans;
        return;
    }

    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i - 1].second >= arr[i].first)
        {
            arr[i].second = max(arr[i].second, arr[i - 1].second);
        }
        else
        {
            ll num = min(arr[i].first, t);
            ll ct = (num - arr[i - 1].second + k - 1) / k;
            ans += ct;
            arr[i].second = max(arr[i].second, arr[i - 1].second + k * ct);
        }

        if (arr[i].second >= t)
        {
            cout << ans;
            return;
        }
    }

    if (arr.back().second < t)
    {
        ans += (t - arr.back().second + k - 1) / k;
    }

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