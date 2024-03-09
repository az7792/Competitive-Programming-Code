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
map<ll, ll> mp;
vector<int> G(MAX, 0);
void solve()
{
    ll b,c,h;
    cin >> b >> c >> h;
    c += h;
    if(c>=b-1)
    {
        cout << b - 1 + b << endl;
    }
    else
    {
        cout << c + c + 1 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
     cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/