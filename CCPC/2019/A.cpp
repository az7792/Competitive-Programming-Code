#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define pii pair<int, int>

void solve();

int t;
ll n, m, k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

void solve()
{
    cin >> n >> m;
    vi a, b;
    while (n > 0ll || m > 0ll)
    {
        a.push_back(n % 2ll);
        n /= 2ll;
        b.push_back(m % 2ll);
        m /= 2ll;
    }
    ll len = (ll)a.size();
    ll res = 1ll;
    ll ans = 0ll;
    for (ll i = 0ll; i < len; i++)
    {
        if (a[i] == 1ll && b[i] == 1ll)
        {
            ans += res;
        }
        res *= 2ll;
    }
    cout << max(1ll, ans) << endl;
    a.clear();
    b.clear();
    return;
}