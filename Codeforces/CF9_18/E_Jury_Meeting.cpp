#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll jc[MAX];
ll POW(ll a, ll b)
{
    ll result = 1;
    a %= MOD;

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }

    return result;
}
void solve()
{
    ll n;
    cin >> n;
    map<ll, ll> mp;
    set<ll> S;
    for (int i = 1; i <= n; ++i)
    {
        ll tmp;
        cin >> tmp;
        S.insert(tmp);
        mp[tmp]++;
    }
    if (mp[*S.rbegin()] >= 2)
    {
        cout << jc[n] << endl;
    }
    else
    {
        set<ll>::iterator it = S.end();
        it--;
        ll Max = *(it);
        it--;
        ll SMax = *(it);
        if (Max - SMax > 1)
        {
            cout << 0 << endl;
        }
        else
        {
            ll ans = 0;
            ll ct = mp[SMax];
            cout << ((jc[n] - (jc[n] * POW(ct + 1, MOD - 2))) % MOD + MOD) % MOD << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    jc[0] = 1;
    for (int i = 1; i <= 1e6; ++i)
    {
        jc[i] = (jc[i - 1] * i) % MOD;
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}