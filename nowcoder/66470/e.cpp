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
vector<int> SG(10010, -1);
int a, b;
int getsg(int n)
{
    if (SG[n] != -1)
        return SG[n];
    if (n < a)
        SG[n] = 0;
    set<int> s;
    for (int i = a; i <= b; ++i)
    {
        if (n - i < 0)
            break;
        s.insert(getsg(n - i));
    }
    int ct = 0;
    while (1)
    {
        if (s.find(ct) == s.end())
        {
            SG[n] = ct;
            return SG[n];
        }
        ct++;
    }
}
void solve()
{
    int n, res = 0, tmp;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        res ^= getsg(tmp);
    }
    cout << "CY"[res == 0];
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