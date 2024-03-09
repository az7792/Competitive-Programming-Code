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
    ll n, A;
    cin >> n;
    cin >> A;
    if (n == 1)
    {
        cout << 0;
        return;
    }
    vector<ll> G;
    for (int i = 2; i <= n; ++i)
    {
        ll tmp;
        cin >> tmp;
        G.eb(tmp);
    }
    ll Max = *max_element(all(G));
    if (A > Max)
        cout << 0;
    else if (A == Max)
        cout << 1;
    else
        cout << Max - A + 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}