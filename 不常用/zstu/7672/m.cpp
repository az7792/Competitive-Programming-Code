#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, a;
    ll M = 100000;
    cin >> n;
    for (ll i = 0; i <= M; ++i)
        if (i * (M - i) >= n)
        {
            a = i;
            break;
        }
    ll sum = (a * (M - a)) - n;
    ll ct = sum / (M - a);
    ll yu = sum % (M - a);
    cout << M << endl;
    if (yu == 0)
    {
        for (int i = 1; i <= a - ct; ++i)
            cout << 0;
        for (int i = 1; i <= M - a; ++i)
            cout << 1;
        for (int i = 1; i <= ct; ++i)
            cout << 0;
    }
    else
    {
        for (int i = 1; i <= a - ct - 1; ++i)
            cout << 0;
        for (int i = 1; i <= yu; ++i)
            cout << 1;
        cout << 0;
        for (int i = 1; i <= M - a - yu; ++i)
            cout << 1;
        for (int i = 1; i <= ct; ++i)
            cout << 0;
    }
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
