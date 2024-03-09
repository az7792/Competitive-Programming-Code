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
unsigned long long n, k, ans;
vector<unsigned long long> G;
vector<unsigned long long> a;
void dfs(int p)
{
    if (G.size() == n)
    {
        unsigned long long tmp = 0xffffffffffffffff;
        for (int i = 0; i < n; ++i)
        {
            if (G[i] == 1)
                tmp &= a[i];
        }
        bitset<64> T(tmp);
        if (T.count() == k)
            ans++;
        return;
    }
    G.push_back(1);
    dfs(p + 1);
    G.pop_back();

    G.push_back(0);
    dfs(p + 1);
    G.pop_back();
}
void solve()
{
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ans = 0;
    dfs(0);
    cout << ans << endl;
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