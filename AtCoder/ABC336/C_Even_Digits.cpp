#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
vector<int> a = {0, 2, 4, 6, 8};
void solve()
{
    ll n;
    cin >> n;
    n--;
    if (n == 0)
    {
        cout << 0;
        return;
    }
    vector<int> ans;
    while (n != 0)
    {
        ans.push_back(n % 5);
        n /= 5;
    }
    reverse(all(ans));
    for (auto v : ans)
        cout << a[v];
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
