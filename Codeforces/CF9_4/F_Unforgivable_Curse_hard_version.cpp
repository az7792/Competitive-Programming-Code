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
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    vector<int> str(26, 0);
    for (int i = 0; i < n; ++i)
    {
        if (i >= n - k && i <= k - 1)
        {
            if (s[i] != t[i])
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            str[s[i] - 'a']++;
            str[t[i] - 'a']--;
        }
    }
    if (str == vector<int>(26, 0))
        cout << "YES\n";
    else
        cout << "NO\n";
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