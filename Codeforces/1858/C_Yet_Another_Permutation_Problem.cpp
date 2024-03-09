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
    int n, i;
    cin >> n;
    set<int> st;
    for (i = 1; i <= n; ++i)
        st.emplace(i);
    i = 1;
    while (!st.empty())
    {
        i = *st.begin();
        for (; i <= n; i *= 2)
        {
            cout << i << ' ';
            st.erase(i);
        }
    }
    cout << endl;
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