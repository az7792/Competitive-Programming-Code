#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 20220911;
void solve()
{
    vector<ll> S; //-2 -1
    string str;
    while (1)
    {
        cin >> str;
        if (str == "fin")
        {
            if (S.empty())
                cout << 0;
            else
            {
                ll ans = 0;
                for(auto v:S)
                    ans = (ans + v) % MOD;
                cout << ans % MOD;
            }
            return;
        }
        else if (str == "repeat")
        {
            S.push_back(-1);
        }
        else if (str == "library")
        {
            if (S.empty())
                S.push_back(1);
            else if (S.back() != -1)
            {
                ll tmp = S.back();
                S.pop_back();
                S.push_back((tmp + 1) % MOD);
            }
            else
                S.push_back(1);
        }
        else if (str == "for")
        {
            ll t;
            cin >> t >> str;
            ll tmp = 0;
            while (1)
            {
                if (S.back() == -1)
                {
                    S.pop_back();
                    break;
                }
                tmp = (tmp + S.back()) % MOD;
                S.pop_back();
            }
            S.push_back((tmp * t) % MOD);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}