#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e1 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n;
    cin >> n;
    vector<pll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        a[i].second += a[i].first;
    }
    sort(all(a), [](pll a, pll b)
         { return a.first < b.first; });
    ll ans = 0;
    priority_queue<ll, vector<ll>, std::greater<ll>> Q;
    ll nowt = a[0].first;
    for (int i = 0; i < n; ++i)
    {
        if (a[i].first == nowt)
            Q.push(a[i].second);
        else
        {
            while (nowt < a[i].first && !Q.empty())
            {
                while (!Q.empty() && Q.top() < nowt)
                    Q.pop();
                if (Q.empty())
                    break;
                ans++;
                Q.pop();
                nowt++;
            }
            if (Q.empty())
                nowt = a[i].first;
            Q.push(a[i].second);
        }
    }
    while (!Q.empty())
    {
        while (!Q.empty())
        {
            while (!Q.empty() && Q.top() < nowt)
                Q.pop();
            if (Q.empty())
                break;
            ans++;
            Q.pop();
            nowt++;
        }
    }
    cout << ans << endl;
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