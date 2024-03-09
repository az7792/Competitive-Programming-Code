#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, p, ans = 0;
    cin >> n >> p;
    vector<pll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].first;
    for (int i = 0; i < n; ++i)
        cin >> a[i].second;
    sort(all(a), [](pll x, pll y)
         { if(x.second==y.second)
            return x.first > y.first;
        return x.second < y.second; });
    ans = p;
    int nowp = 0, nowe = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[nowp].second < p)
        {
            ans += a[nowp].second;
            a[nowp].first--;
            if (a[nowp].first == 0)
                nowp++;
        }
        else
        {
            ans += p;
        }
        nowe++;
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