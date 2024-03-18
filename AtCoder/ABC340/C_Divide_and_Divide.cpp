#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
map<ll, ll> mp;
void dfs(ll n)
{
    if (n < 2)
        return;
    if (mp.find(n) != mp.end())
        return;
    ll a = n / 2;
    ll b = (n + 1) / 2;
    dfs(a);
    dfs(b);
    mp[n] = mp[a] + mp[b] + n;
}
void solve()
{
    ll n;
    cin >> n;
    dfs(n);
    cout << mp[n];
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
