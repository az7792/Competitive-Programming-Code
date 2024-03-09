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
    ll n;
    cin >> n;
    ll L = 0, R = 1e9, mid, sum;
    while (L < R)
    {
        mid = (L + R) / 2;
        sum = (mid + 1) * (mid + 1);
        if (sum < n)
            L = mid + 1;
        else
            R = mid;
    }
    cout << L << endl;
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