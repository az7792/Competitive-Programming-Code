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
    string s, f;
    cin >> s >> f;
    int ctf = count(all(f), '1');
    int cts = count(all(s), '1');
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1' && f[i] == '1')
            ctf--, cts--;
    }
    cout << max(ctf, cts) << endl;
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
