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
    ll n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return;
    }
    ll N = log2(n) + 1;
    bitset<40> t(n);
    int p;
    for (int i = 39; i >= 0; --i)
    {
        if (t[i] == 1)
        {
            p = i;
            break;
        }
    }
    for (int i = p - 1; i >= 0; --i)
    {
        if (t[i] == 1)
        {
            for (int j = 0; j < i; ++j)
            {
                if (t[j] == 0)
                {
                    t[i] = 0;
                    t[j] = 1;
                    break;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 40;++i)
    {
        if(t[i]==1)
        {
            ans += (1ll << i);
        }
    }
    cout << n - ans;
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