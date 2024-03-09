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
    unsigned int n;
    cin >> n;
    bitset<8> a[4];
    for (int i = 0; i < 4; ++i)
    {
        a[i] = bitset<8>(n);
        n = (n >> 8);
    }
    vector<int> g = {0, 1, 2, 3};
    unsigned int ans = 0;
    do
    {
        unsigned int tmp = 0;
        for (int i = 0; i < 32; ++i)
        {
            int p = i / 8;
            int pp = i - 8 * p;
            if (a[g[p]][pp] == 1)
                tmp += (1u << i);
        }
        ans = max(ans, tmp);
    } while (next_permutation(all(g)));
    cout << ans;
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