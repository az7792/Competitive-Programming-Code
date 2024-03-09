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
    int q;
    cin >> q;
    map<int, int> S;
    while (q--)
    {
        int op, x, c;
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            S[x]++;
        }
        else if (op == 2)
        {
            cin >> x >> c;
            if (c >= S[x])
                S.erase(x);
            else
                S[x] -= c;
        }
        else
        {
            cout << (*S.rbegin()).first - (*S.begin()).first << endl;
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