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
multiset<int> L, R;
void solve()
{
    char op;
    int l, r;
    cin >> op >> l >> r;
    if (op == '+')
    {
        L.insert(l);
        R.insert(r);
        if (*R.begin() < *L.rbegin())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
    {
        L.erase(L.find(l));
        R.erase(R.find(r));
        if (!L.empty() && *R.begin() < *L.rbegin())
            cout << "YES\n";
        else
            cout << "NO\n";
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