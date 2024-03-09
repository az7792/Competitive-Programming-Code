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
vector<int> a(10);
void solve()
{
    ll n;
    cin >> n;
    n--;
    vector<int> ans;
    if (n == 0)
        ans.push_back(0);
    while (n != 0)
    {
        ans.push_back(n % 7);
        n /= 7;
    }
    for (int i = ans.size() - 1; i >= 0; --i)
        cout << a[ans[i]];
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    a[0] = 0;
    a[1] = 2;
    a[2] = 3;
    a[3] = 6;
    a[4] = 7;
    a[5] = 8;
    a[6] = 9;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
