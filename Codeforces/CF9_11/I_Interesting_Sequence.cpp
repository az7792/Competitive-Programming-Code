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
    unsigned long long n, x, ans = 0;
    cin >> n >> x;
    if (n == x)
    {
        cout << n << endl;
        return;
    }
    if (x > n)
    {
        cout << -1 << endl;
        return;
    }
    bitset<64> N(n), X(x);
    int a = 64, b = -1;
    for (int i = 63; i >= 0; --i)
    {
        if ((x >> i & 1) == 1)
        {
            if ((n >> i & 1) == 1)
                a = min(a, i);
            else
            {
                cout << -1 << endl;
                return;
            }
        }
        else if ((n >> i & 1) == 1)
            b = max(b, i);
    }
    if (b + 1 >= a)
        cout << -1 << endl;
    else
    {
        N[b + 1] = 1;
        for (int i = 0; i <= b; ++i)
            N[i] = 0;
        for (int i = 0; i < 64; ++i)
            ans += (N[i] == 1 ? (1ull << i) : 0);
        cout << ans << endl;
    }
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