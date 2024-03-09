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
string str[] = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
void solve()
{
    string st;
    cin >> st;
    for (int i = 0; i < 7;++i)
        if(st==str[i])
            {
                cout << "Yes\n";
                return;
            }
    cout << "No";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}