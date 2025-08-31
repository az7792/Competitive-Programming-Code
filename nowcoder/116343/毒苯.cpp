#include <bits/stdc++.h>
using namespace std;
vector<int> make1(string strArr);
vector<vector<int>> make2(string strArr);
#define endl '\n'
// leetcode--------start
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

class Solution
{
public:
    int beautifulSplits(vector<int> &nums)
    {
        return 1;
    }
};
// leetcode--------end
struct Node
{
    int x, y, z;
};
int n, m, q;
pii o2t(int val)
{
    return {val / m, val % m};
}

int t2o(int va, int vb)
{
    return va * m + vb;
}

void solve()
{
    cin >> n >> m >> q;
    vector<pii> a(n * m);
    vector<int> fa(n * m);
    vector<int> ct(n * m);
    for (int i = 0; i < n * m; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    vector<pii> tmpa = a;

    vector<pii> FF(a.begin(), a.begin() + m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            fa[i * m + j] = i * m + j, ct[i * m + j] = 1;

    function<int(int)> Find = [&](int p) -> int
    {
        if (fa[p] != p)
            fa[p] = Find(fa[p]);
        return fa[p];
    };
    vector<Node> oldQ(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> oldQ[i].x;
        oldQ[i].y = i;
        oldQ[i].z = 0;
    }

    sort(all(oldQ), [](const Node &_, const Node &__) -> bool
         { return _.x < __.x; });

    sort(all(a), greater<pii>());
    sort(all(FF), greater<pii>());
    int line1FA = -1;
    for (int pos = 0; pos < q; ++pos)
    {
        while (!a.empty() && a.back().first <= oldQ[pos].x)
        {
            pii xy = o2t(a.back().second);
            for (int i = 0; i < 4; ++i)
            {
                pii nxy = {xy.first + tx[i], xy.second + ty[i]};
                if (nxy.first < 0 || nxy.second < 0 || nxy.first >= n || nxy.second >= m)
                    continue;
                if (tmpa[t2o(nxy.first, nxy.second)].first > oldQ[pos].x)
                    continue;
                int FA = Find(a.back().second);
                int FB = Find(t2o(nxy.first, nxy.second));
                if (FA == FB)
                    continue;
                fa[FA] = FB;
                ct[FB] += ct[FA];
            }
            a.pop_back();
        }

        vector<pii> tmppii;
        while (!FF.empty() && FF.back().first <= oldQ[pos].x)
        {
            tmppii.push_back(FF.back());
            FF.pop_back();
        }
        int FA = -1;
        if (!tmppii.empty())
        {
            FA = Find(tmppii.front().second);
        }
        for (int i = 1; i < tmppii.size(); ++i)
        {
            int FB = Find(tmppii[i].second);
            if (FA == FB)
                continue;
            fa[FB] = FA;
            ct[FA] += ct[FB];
        }

        if (FA == -1 && line1FA == -1)
            continue;

        if(FA == -1)
        {
            oldQ[pos].z = ct[Find(line1FA)];
            continue;
        }

        if (line1FA == -1)
        {
            line1FA = FA;
        }
        line1FA = Find(line1FA);
        if (FA != line1FA)
        {
            fa[FA] = line1FA;
            ct[line1FA] += ct[FA];
        }
        oldQ[pos].z = ct[line1FA];
    }

    sort(all(oldQ), [](const Node &_, const Node &__) -> bool
         { return _.y < __.y; });

    for (auto v : oldQ)
        cout << v.z << "\n";
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

vector<int> make1(string strArr)
{
    vector<int> result;
    if (strArr.empty())
        return result;
    string item;
    strArr = strArr.substr(1, strArr.size() - 2);
    stringstream stream(strArr);
    while (getline(stream, item, ','))
    {
        result.push_back(stoi(item));
    }
    return result;
}
vector<vector<int>> make2(string strArr)
{
    vector<vector<int>> result;
    if (strArr.empty())
        return result;
    string item;
    strArr = strArr.substr(2, strArr.size() - 4);
    stringstream stream(strArr);
    bool first = true;
    while (getline(stream, item, ']'))
    {
        if (!item.empty())
        {
            if (!first)
                item = item.substr(2);
            vector<int> innerResult = make1("[" + item + "]");
            result.push_back(innerResult);
            first = false;
        }
    }
    return result;
}