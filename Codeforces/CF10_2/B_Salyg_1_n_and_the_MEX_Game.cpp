#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    set<int> S;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        S.insert(tmp);
    }
    int p;
    for (int i = 0; true; ++i)
    {
        if (S.find(i) == S.end())
        {
            p = i;
            break;
        }
    }
    cout << p << endl;
    int x;
    while (1)
    {
        cin >> x;
        if (x == -1)
            break;
        cout << x << endl;
    }
    
}
int main()
{
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
