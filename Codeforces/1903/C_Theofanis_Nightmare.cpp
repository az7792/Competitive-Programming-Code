#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 2, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    ll sum = 0;
    set<ll> now;
    vector<ll> ans;
    for (int i = n; i >= 1; --i)
    {
        if (i == 1)
        {
            ans.push_back(a[i]);
            continue;
        }
        if (a[i] >= 0)
        {
            ans.push_back(a[i]);
            sum += a[i];
        }
        else
        {
            if (sum + a[i] >= 0)
            {
                ans.push_back(a[i]);
                sum += a[i];
            }
            else
                a[i - 1] += a[i];
        }
    }
    ll ANS = 0;
    reverse(all(ans));
    for (int i = 1; i <= ans.size(); ++i)
    {
        ANS += ans[i - 1] * i;
    }
    cout << ANS << endl;
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
