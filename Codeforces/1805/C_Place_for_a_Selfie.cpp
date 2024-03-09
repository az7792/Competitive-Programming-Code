#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> k(n);
    vector<ll> a(m);
    vector<ll> b(m);
    vector<ll> c(m);
    for (int i = 0; i < n; ++i)
        cin >> k[i];
    sort(all(k));
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
        // b^2 - 2kb + k^2 < 4ac
        ll tmp = 4 * a[i] * c[i] - b[i] * b[i];
        // k^2 - 2kb < tmp
        ll Z = b[i];
        if (Z < k[0])
        {
            ll T = k[0] * k[0] - 2 * k[0] * b[i];
            if (T < tmp)
            {
                cout << "YES\n";
                cout << k[0] << endl;
            }
            else
                cout << "NO\n";
        }
        else if (Z > k.back())
        {
            ll T = k.back() * k.back() - 2 * k.back() * b[i];
            if (T < tmp)
            {
                cout << "YES\n";
                cout << k.back() << endl;
            }
            else
                cout << "NO\n";
        }
        else
        {
            int p = lower_bound(all(k), Z) - k.begin();
            if (k[p] == Z)
            {
                ll T = k[p] * k[p] - 2 * k[p] * b[i];
                if (T < tmp)
                {
                    cout << "YES\n";
                    cout << k[p] << endl;
                }
                else
                    cout << "NO\n";
            }
            else
            {
                ll T = k[p] * k[p] - 2 * k[p] * b[i];
                ll t = k[p - 1] * k[p - 1] - 2 * k[p - 1] * b[i];
                if (T < tmp)
                {
                    cout << "YES\n";
                    cout << k[p] << endl;
                }
                else if (t < tmp)
                {
                    cout << "YES\n";
                    cout << k[p - 1] << endl;
                }
                else
                    cout << "NO\n";
            }
        }
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1
1 2
1
1 -1 2
1 -1 3


*/