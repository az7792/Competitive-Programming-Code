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
struct Node
{
    int l, r;
    bool operator<(const Node &other) const
    {
        return l < other.l;
    }
};

void solve()
{
    int n, q, x, y;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> b(n);
    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mp[a[i]]++;
        b[i - 1] = a[i];
    }
    set<Node> S;
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    S.insert({(int)(b.back() + 1), (int)1e9 + 1});
    if (b[0] != 0)
    {
        S.insert({0, b[0] - 1});
    }
    for (int i = 1; i < b.size(); ++i)
    {
        if (b[i] != b[i - 1] + 1)
        {
            S.insert({b[i - 1] + 1, b[i] - 1});
        }
    }

    while (q--)
    {
        cin >> x >> y;
        if (mp[a[x]] > 1)
        {
            mp[a[x]]--;
            a[x] = y;
            if (mp[y] >= 1)
            {
                cout << (*S.begin()).l << endl;
            }
            else
            {
                auto v = S.upper_bound({y, 0});
                v--;
                int l = (*v).l;
                int r = (*v).r;
                S.erase(v);
                if (y - 1 >= l)
                    S.insert({l, y - 1});
                if (y + 1 <= r)
                    S.insert({y + 1, r});
                cout << (*S.begin()).l << endl;
            }
            mp[y]++;
        }
        else //<=1
        {
            int l, r;
            auto v = S.upper_bound({a[x], 0});
            l = (*v).l;
            auto tmp = v;
            if (v == S.begin())
                r = -100;
            else
            {
                tmp--;
                r = (*tmp).r;
            }
            if (a[x] + 1 == l && a[x] - 1 == r)
            {
                l = (*tmp).l;
                r = (*v).r;
                S.erase(v);
                S.erase(tmp);
                S.insert({l, r});
            }
            else if (a[x] + 1 == l)
            {
                l = a[x];
                r = (*v).r;
                S.erase(v);
                S.insert({l, r});
            }
            else if (a[x] - 1 == r)
            {
                l = (*tmp).l;
                r = a[x];
                S.erase(tmp);
                S.insert({l, r});
            }
            else
            {
                S.insert({a[x], a[x]});
            }
            mp[a[x]]--;
            a[x] = y;
            if (mp[y] >= 1)
            {
                cout << (*S.begin()).l << endl;
            }
            else
            {
                auto v = S.upper_bound({y, 0});
                v--;
                int l = (*v).l;
                int r = (*v).r;
                S.erase(v);
                if (y - 1 >= l)
                    S.insert({l, y - 1});
                if (y + 1 <= r)
                    S.insert({y + 1, r});
                cout << (*S.begin()).l << endl;
            }
            mp[y]++;
        }
    }
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
