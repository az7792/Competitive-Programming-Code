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
    int n, a, q;
    int ct, Max;
    cin >> n >> a >> q;
    string str;
    cin >> str;
    if (a >= n)
    {
        cout << "YES\n";
        return;
    }
    ct = Max = a;
    for (auto v : str)
    {
        if (v == '+')
        {
            ct++;
            Max = max(Max, ct);
        }
        else
        {
            ct--;
        }
    }
    ct = a;
    int old = a;
    for (auto v : str)
    {
        if (v == '+')
        {
            ct++;
            old++;
        }
        else
        {
            if (old >= 1)
                old--;
            else
                ct--;
        }
    }
    if (Max >= n)
        cout << "YES\n";
    else if (ct < n)
        cout << "NO\n";
    else
        cout << "MAYBE\n";
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