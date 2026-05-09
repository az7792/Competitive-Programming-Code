#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll MOD = 1e9 + 7;
// ll MOD = 998244353;

template <typename T>
std::istream &operator>>(std::istream &_in, std::vector<T> &_a)
{
    for (auto &v : _a)
        _in >> v;
    return _in;
}

template <typename T>
std::ostream &operator<<(std::ostream &_out, std::vector<T> &_a)
{
    if (!_a.empty())
        _out << _a[0];
    for (size_t i = 1; i < _a.size(); ++i)
        _out << " " << _a[i];
    return _out;
}
struct Node
{
    int s, t, p;
};

struct ANS
{
    int l = 0, r = 0, num = 0;
};
vector<ANS> ans;
bool l2r(map<int, map<int, int>> &mpL, map<int, map<int, int>> &mpR, int s, int t, int queryNum)
{
    auto it = mpL[s].upper_bound(t);
    if (it == mpL[s].begin())
    {
        return false;
    }
    it--;
    int maxR = it->first;
    if (maxR == t)
    {
        if (ans[queryNum].num >= 2)
        {
            return true;
        }
        if (ans[queryNum].num == 1 && (ans[queryNum].l != s || ans[queryNum].r != t))
        {
            return true;
        }
        return false;
    }

    // s<= xx <=maxR+1
    it = mpR[t].upper_bound(maxR + 1);
    if (it == mpR[t].begin())
    {
        return false;
    }
    it--;
    return it->first >= s;
}

bool r2l(map<int, map<int, int>> &mpL, map<int, map<int, int>> &mpR, int s, int t, int queryNum)
{
    auto it = mpR[t].lower_bound(s);
    if (it == mpR[t].end())
    {
        return false;
    }
    int minL = it->first;
    if (minL == s)
    {
        if (ans[queryNum].num >= 2)
        {
            return true;
        }
        if (ans[queryNum].num == 1 && (ans[queryNum].l != s || ans[queryNum].r != t))
        {
            return true;
        }
        return false;
    }
    // midL-1<= xx <=t
    it = mpL[s].lower_bound(minL - 1);
    if (it == mpL[s].end())
    {
        return false;
    }
    return it->first <= t;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pii> Q;
    multiset<pii> S;
    map<int, map<int, int>> mpL;
    map<int, map<int, int>> mpR;
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        mpL[l][r]++;
        mpR[r][l]++;
        Q.push_back({l, r});
        S.insert({r, l});
    }
    sort(all(Q), std::greater<pii>());

    int q;
    cin >> q;
    vector<Node> query(q);
    ans.resize(q);
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].s >> query[i].t;
        query[i].p = i;
    }
    sort(all(query), [](Node a, Node b)
         { return a.s < b.s; });

    for (int i = 0; i < q; i++)
    {
        while (!Q.empty())
        {
            if (Q.back().first < query[i].s)
            {
                pii cur = Q.back();
                Q.pop_back();
                S.erase(S.find({cur.second, cur.first}));
            }
            else
            {
                break;
            }
        }

        int ct = 0;
        for (auto &v : S)
        {
            if (v.first <= query[i].t)
            {
                ans[query[i].p].num++;
                ans[query[i].p].l = v.second;
                ans[query[i].p].r = v.first;
            }
            ct++;
            if (ct >= 2)
                break;
        }
    }

    sort(all(query), [](Node a, Node b)
         { return a.p < b.p; });
    for (int i = 0; i < q; i++)
    {
        int s = query[i].s, t = query[i].t;
        if (mpL.find(s) == mpL.end() || mpR.find(t) == mpR.end())
        {
            cout << "No" << endl;
            continue;
        }

        // l->r
        if (l2r(mpL, mpR, s, t, i))
        {
            cout << "Yes" << endl;
            continue;
        }
        // r->l
        if (r2l(mpL, mpR, s, t, i))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
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