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
vector<int> dp;
int mex(set<int> &st)
{
    for (int i = 0;; ++i)
        if (st.find(i) == st.end())
            return i;
}
int sg(int n)
{
    if (dp[n] != -1)
        return dp[n];
    set<int> st;
    for (int i = 1; i <= n; i *= 2)
        st.emplace(sg(n - i));
    return dp[n] = mex(st);
}
void solve(int n)
{
    cout << (sg(n) > 0 ? "Kiki" : "Cici") << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    dp.resize(1010, -1);
    while (cin >> t)
    {
        solve(t);
    }
    return 0;
}