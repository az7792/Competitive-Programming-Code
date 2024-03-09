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
    int n;
    cin >> n;
    vector<int> p(n+1,0);
    vector<int> ans(n+1,0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
        ans[p[i]] = i;
    }
    int ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        if(ans[i]<ans[i-1])
        {
            ct++;
        }
    }
    cout << ct << endl;
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