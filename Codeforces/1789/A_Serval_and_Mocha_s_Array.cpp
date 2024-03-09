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
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> G[i];
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (gcd(G[i], G[j]) <= 2)
            {
                cout << "YES\n";
                return;
            }
    cout << "NO\n";
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