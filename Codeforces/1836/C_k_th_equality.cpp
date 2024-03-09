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
ll Min[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
ll Max[] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999};
vector<ll> G(MAX, 0);
vector<pll> LR(MAX, {0, 0});
void solve()
{
    ll a, b, c, k, sum = 0;

    cin >> a >> b >> c >> k;

    for (ll i = Min[a]; i <= Max[a]; ++i)
    {
        if (i + Max[b] < Min[c] || i + Min[b] > Max[c])
            G[i] = 0, LR[i] = {0, 0};
        else
        {
            ll L, R;
            if (i + Min[b] < Min[c])
                L = Min[c] - i;
            else
                L = Min[b];
            if (i + Max[b] > Max[c])
                R = Max[c] - i;
            else
                R = Max[b];
            G[i] = R - L + 1;
            LR[i] = {L, R};
        }
        sum += G[i];
        if (sum >= k)
            break;
    }
    for (ll i = Min[a]; i <= Max[a]; ++i)
    {
        if (k - G[i] >= 1)
        {
            k -= G[i];
        }
        else
        {
            cout << i << " + " << LR[i].first + k - 1 << " = " << (i + LR[i].first + k - 1) << endl;
            return;
        }
    }
    cout << -1 << endl;
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