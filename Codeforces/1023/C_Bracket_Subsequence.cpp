#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
#define fi first
#define se second
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    vector<int> ans;
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int L = 0, R = 0;
    for (int i = 0; i < n; ++i)
        if (str[i] == '(')
        {
            L = R = i;
            break;
        }
    while (k != 0 && L < n && R < n)
    {
        if (str[L] == ')')
        {
            L++;
            if (R <= L)
                R = L+1;
        }
        else if (str[R] == ')')
        {
            k -= 2;
            ans.eb(L);
            ans.eb(R);
            L++, R++;
        }
        else
            R++;
    }
    sort(all(ans));
    for(auto v:ans)
        cout<<str[v];
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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