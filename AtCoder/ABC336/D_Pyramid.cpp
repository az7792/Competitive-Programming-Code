#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
vector<int> a;
int n;
bool ok(int mid)
{
    int len = 0, need;
    set<int> l, r;
    for (int i = 1; i <= n; ++i)
    {
        if (len == mid)
            need = len;
        else
            need = len + 1;

        if (a[i] >= need)
        {
            if (len == mid)
                l.insert(i);
            else
            {
                len++;
                if (len == mid)
                    l.insert(i);
            }
        }
        else
        {
            len = a[i];
        }
    }
    len = 0;
    for (int i = n; i >= 1; --i)
    {
        if (len == mid)
            need = len;
        else
            need = len + 1;

        if (a[i] >= need)
        {
            if (len == mid)
                r.insert(i);
            else
            {
                len++;
                if (len == mid)
                    r.insert(i);
            }
        }
        else
        {
            len = a[i];
        }
    }
    if (l.size() == 0 || r.size() == 0)
        return false;
    if (l.size() < r.size())
    {
        for (auto v : l)
        {
            if (r.find(v) != r.end())
                return true;
        }
    }
    else
    {
        for (auto v : r)
        {
            if (l.find(v) != l.end())
                return true;
        }
    }
    return false;
}
void solve()
{
    cin >> n;
    a.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int l = 1, r = (n + 1) / 2, mid;
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
