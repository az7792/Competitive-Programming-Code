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
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    vector<int> sum(n, 0);
    int ct = 0;
    for (int i = n - 2; i >= 0; --i)
    {
        if (str[i] == str[i + 1])
            ct++;
        sum[i] = ct;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << sum[l] - sum[r] << endl;
    }
    
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