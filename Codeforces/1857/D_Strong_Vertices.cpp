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
    vector<ll> A(n + 10, 0);
    vector<ll> B(n + 10, 0);
    vector<pll> C(n + 10, {0,0});
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    for (int i = 1; i <= n; ++i)
        cin >> B[i];
    for (int i = 1; i <= n; ++i)
        C[i].first = A[i] - B[i], C[i].second = i;
    sort(C.begin() + 1, C.begin() + n + 1, [](pll a, pll b)
         {
        if(a.first==b.first)
            return a.second < b.second;
        return a.first > b.first; });
    ll tmp = C[1].first;
    vector<ll> ans;
    for (int i = 1; i <= n; ++i)
    {
        if(C[i].first==tmp)
            ans.eb(C[i].second);
        else
            break;
    }
    cout << ans.size() << endl;
    for(auto v:ans)
        cout << v << ' ';
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