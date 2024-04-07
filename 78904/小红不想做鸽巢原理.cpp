#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<pair<ll, ll>> tmp;
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        ll v = a[i];
        if (v % k != 0)
        {
            tmp.push_back(pair<ll, ll>(v % k, i + 1));
            sum += v % k;
        }
    }
    sort(all(tmp), [](pair<ll, ll> a, pair<ll, ll> b)
         { return a.first > b.first; });
    ll tk = k;
    while (!tmp.empty())
    {
        if (tk == k && sum < k)
            break;
        if (tmp.back().first >= tk)
        {
            tmp.back().first -= tk;
            sum -= tk;
            tk = k;
            if (tmp.back().first == 0)
                tmp.pop_back();
        }
        else
        {
            tk -= tmp.back().first;
            sum -= tmp.back().first;
            tmp.pop_back();
        }
    }
    cout << tmp.size();
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
