#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll n, fi, si;
string s, t;
vector<vector<ll>> a;
void find(int ch, ll mid)
{
    // if (si != 0)
    //     mid += a[ch][si - 1];
    // si = 0;
    // if (a[ch].back() == 0)
    // {
    //     fi = 1e18;
    //     return;
    // }

    // ll num = (mid - 1) / a[ch].back();
    // fi += num;
    // mid -= num * a[ch].back();
    // si = lower_bound(all(a[ch]), mid) - a[ch].begin();
    // if (si + 1 == s.size())
    //     fi++, si = 0;
    // else
    //     si++;

    ll now = a[ch].back();
    if (si != 0)
        now -= a[ch][si - 1];
    if (now < mid)
    {
        fi++;
        mid -= now;
        if (a[ch].back() == 0)
        {
            fi = 1e18;
            return;
        }
        if (mid % a[ch].back() != 0)
        {
            fi += mid / a[ch].back();
            mid = mid % a[ch].back();
        }
        else
        {
            fi += (mid / a[ch].back()) - 1;
            mid = a[ch].back();
        }
        si = lower_bound(all(a[ch]), mid) - a[ch].begin();
        if (si + 1 == s.size())
            fi++, si = 0;
        else
            si++;
    }
    else
    {
        si = lower_bound(a[ch].begin() + si, a[ch].end(), mid + (si - 1 < 0 ? 0 : a[ch][si - 1])) - a[ch].begin();
        if (si + 1 == s.size())
            fi++, si = 0;
        else
            si++;
    }
}
bool ok(ll mid)
{
    fi = 0, si = 0;
    for (auto v : t)
    {
        find(v - 'a', mid);
        if (fi + (si + s.size() - 1) / s.size() > n)
            return false;
    }
    return true;
}
void solve()
{
    cin >> n >> s >> t;
    a.resize(26, vector<ll>(s.size(), 0));
    // g(t,k) f(s,n)
    for (int i = 0; i < s.size(); ++i)
    {
        if (i != 0)
            for (int j = 0; j < 26; ++j)
                a[j][i] = a[j][i - 1];
        a[s[i] - 'a'][i]++;
    }
    ll l = 0, r = 1e18, mid;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        if (ok(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
