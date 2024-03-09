#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, sum = 0;
    cin >> n;
    vector<ll> a(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll Min = *min_element(all(a));
    ll Max = *max_element(all(a));
    if (Min==Max)
        cout << 1 << endl;
    else
        cout << Max << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
