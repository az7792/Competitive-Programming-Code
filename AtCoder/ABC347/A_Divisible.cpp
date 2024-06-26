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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] % k == 0)
            ans.push_back(a[i] / k);
    }
    for (auto v : ans)
        cout << v << " ";
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
