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
    vector<int> num(n);
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    sort(all(num));
    int top = -1;
    bool f = true;
    for (int i = num.back(); i >= 1; --i)
    {
        int p = lower_bound(all(num), i) - num.begin();
        int H = n - p;
        if (H != num[++top])
        {
            f = false;
            break;
        }
    }
    cout << (f ? "YES\n" : "NO\n");
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