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
    ll a, s;
    cin >> a >> s;
    s = s - 2 * a;
    if (s < 0)
        cout << "No\n";
    else
    {
        bitset<60> A(a);
        bitset<60> S(s);
        for (int i = 0; i < 60; ++i)
        {
            if (A[i] == 1 && S[i] == 0)
            {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
    }
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