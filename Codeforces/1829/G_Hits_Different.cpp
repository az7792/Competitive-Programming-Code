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
// 1+...+1450=1051975
vector<ll> G(1051975 + 10);
void init()
{
    ll p = 1;
    G[1] = 1;
    for (int i = 2; i <= 1450; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            p++;
            G[p] = p * p;
            if (j == 1 || j == i)
                G[p] += j == 1 ? G[p - i + 1] : G[p - i];
            else
            {
                G[p] += G[p - i + 1] + G[p - i];
                G[p] -= G[(p - i) - (i - 1) + 1];
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    cout << G[n] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}