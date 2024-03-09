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
    ll i = 0, j = 0, k = 0, n;
    cin >> n;
    for (i = 0; i <= n; i++)
    {
        if (i + j + k > n)
            continue;
        for (j = 0; j <= n; ++j)
        {
            if (i + j + k > n)
                continue;
            for (k = 0; k <= n; ++k)
            {
                if (i + j + k > n)
                    continue;
                cout << i << ' ' << j << " " << k << endl;
            }
            k = 0;
        }
        j = 0;
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
