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
vector<int> G(MAX, 0);
void solve()
{
    int n, Min;
    cin >> n;
    cin >> Min;
    G[1] = Min;
    for (int i = 2; i <= n; ++i)
    {
        cin >> G[i];
        Min &= G[i];
    }
    if (Min != 0)
    {
        cout << 1 << endl;
        return;
    }
    int ct = 0;
    Min = G[1];
    for (int i = 2; i <= n; ++i)
    {
        if (Min == 0)
        {
            ct++;
            Min = G[i];
        }
        else
        {
            Min &= G[i];
        }
    }
    if (Min == 0)
        ct++;
    cout << ct << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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