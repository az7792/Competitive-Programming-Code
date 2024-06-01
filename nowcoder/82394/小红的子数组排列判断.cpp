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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    map<int, int> mp;
    for (int i = 1; i <= k; ++i)
        mp[a[i]]++;
    int ans = 0;
    if (mp.size() == k && (*mp.rbegin()).first == k)
        ans++;
    for (int i = k + 1; i <= n; ++i)
    {
        mp[a[i]]++;
        mp[a[i - k]]--;
        if (mp[a[i - k]] == 0)
            mp.erase(a[i - k]);
        if (mp.size() == k && (*mp.rbegin()).first == k)
            ans++;
    }
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
