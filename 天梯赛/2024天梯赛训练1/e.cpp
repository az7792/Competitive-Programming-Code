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
    vector<int> a(24);
    for (int i = 0; i < 24; ++i)
        cin >> a[i];
    int tmp;
    while (1)
    {
        cin >> tmp;
        if (tmp > 23 || tmp < 0)
            return;
        if(a[tmp]>50)
            cout << a[tmp] << " Yes\n";
        else
            cout << a[tmp] << " No\n";
    }
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
