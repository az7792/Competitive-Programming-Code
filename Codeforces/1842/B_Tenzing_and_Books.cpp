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
map<ll, ll> mp;
int G[4][MAX], n, x;
void solve()
{
    int S[4];
    cin >> n >> x;
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> G[i][j];
            G[i][j] |= G[i][j - 1];
        }
    }
    for (int i = 1; i <= 3; ++i)
        for (int j = 0; j <= n; ++j)
            if ((G[i][j] | x) == x)
                S[i] = G[i][j];
    if ((S[1] | S[2] | S[3]) == x)
        cout << "Yes\n";
    else
        cout << "No\n";
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




*/