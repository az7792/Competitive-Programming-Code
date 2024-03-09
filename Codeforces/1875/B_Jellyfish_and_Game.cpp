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
    ll n, m, k;
    cin >> n >> m >> k;
    multiset<ll> a, b;
    if (k % 2 == 0)
        k = 2;
    else
        k = 1;
    for (int i = 1; i <= n; ++i)
    {
        ll tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    for (int i = 1; i <= m; ++i)
    {
        ll tmp;
        cin >> tmp;
        b.insert(tmp);
    }
    for (int i = 1; i <= k; ++i)
    {
        if (i % 2 == 1)
        {
            ll A = *a.begin();
            ll B = *b.rbegin();
            if (A < B)
            {
                a.erase(a.begin());
                a.insert(B);
                b.erase(--b.end());
                b.insert(A);
            }
        }
        else
        {
            ll A = *b.begin();
            ll B = *a.rbegin();
            if (A < B)
            {
                b.erase(b.begin());
                b.insert(B);
                a.erase(--a.end());
                a.insert(A);
            }
        }
        // ll ans = 0;
        // for (auto v : a)
        // {
        //     ans += v;
        // }
        // cout << ans << endl;
    }
    ll ans = 0;
    for (auto v : a)
    {
        ans += v;
    }
    cout << ans << endl;
    //cout << endl;
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