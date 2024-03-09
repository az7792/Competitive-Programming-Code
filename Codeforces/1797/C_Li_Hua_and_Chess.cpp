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
ll n, m;
ll ask(ll x, ll y)
{
    cout << "? " << x << ' ' << y << endl;
    cout.flush();
    ll res;
    cin >> res;
    return res;
}
void solve()
{
    cin >> n >> m;
    ll len1 = ask(1, 1), len2;
    len1++;
    if (len1 > n || len1 > m)
    {
        if (len1 > n)
        {
            len2 = ask(n, len1);
            cout << "! " << n - len2 << ' ' << len1 << endl;
        }
        else
        {
            len2 = ask(len1, m);
            cout << "! " << len1 << ' ' << m - len2 << endl;
        }
        cout.flush();
        return;
    }
    len2 = ask(len1, len1);
    if (ask(len1, len1 - len2) == 0)
        cout << "! " << len1 << ' ' << len1 - len2 << endl;

    else
        cout << "! " << len1 - len2 << ' ' << len1 << endl;
    cout.flush();
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/