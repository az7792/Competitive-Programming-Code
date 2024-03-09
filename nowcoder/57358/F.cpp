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
void solve()
{
    ll n;
    cin >> n;
    vector<pll> G(n, {0,0});
    for (int i = 0; i < n; ++i)
        cin >> G[i].first, G[i].second = i;
    sort(all(G), [](pll a, pll b)
         { return a.first < b.first; });
    ll L = 0, R = n - 1, l = 0, r = n - 1, mid;
    for (int i = 1; i < n; ++i)
    {
        l = L, r = R;
        while (l < r)
        {
            if(l+1==r)
                break;
            mid = (l + r) >> 1;
            ll lv = G[mid].first - G[L].first;
            ll rv = G[R].first - G[mid].first;
            if (lv == rv)
            {
                l = mid;
            }
            else if (lv < rv)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }            
        }
        if((l-L+1)==(R-l))
        {
            R--;
        }
        else if((l-L+1)>(R-l)){
            R--;
        }   
        else{
            L++;
        }
    }
    cout << G[L].second+1 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/