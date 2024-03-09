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
    unsigned long long x;
    cin >> x;
    bitset<40> tmp(x);
    int p;
    for (int i = 39; i >= 0; --i)
    {
        if (tmp[i] == 1)
        {
            p = i;
            break;
        }
    }
    cout << (1ll << (p + 1));
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