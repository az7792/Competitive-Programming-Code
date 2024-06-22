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
    int n;
    cin >> n;
    vector<int> a(n, 0);
    int ct = 0;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        if (tmp < 0)
            ct++;
        a[i] = abs(tmp);
    }
    for (int i = 0; i < ct;++i)
        a[i] = -a[i];
    vector<int> b = a;
    sort(all(a));
    if(a==b)
        cout << "YES\n";
    else
        cout << "NO\n";
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