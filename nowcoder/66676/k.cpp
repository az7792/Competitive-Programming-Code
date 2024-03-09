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
    string str;
    cin >> str;
    bool f = false;
    for (auto v : str)
    {
        if (v == ',')
        {
            if (f)
                cout << '.';
            else
                cout << v;
        }
        else
        {
            if (v == '(')
                f = true;
            if (v == ')')
                f = false;
            cout << v;
        }
    }
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