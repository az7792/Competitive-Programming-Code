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
string str;
vector<int> a(26);
ll dfs(int p, vector<int> &c)
{
    ll ans = 0;
    if (p == str.size())
    {
        for (auto v : c)
            ans += v;
        return ans;
    }
    for (int i = str[p] - 'a' + 1; i < 26; ++i)
    {
        ans += c[i];
        c[i] = 0;
    }
    int num = c[str[p] - 'a'];
    if (num == 0)
        return ans;
    int len = 1;
    for (int i = p + 1; i < str.size(); ++i)
    {
        if (str[i] == str[p])
            len++;
        else
            break;
    }
    int l = 0, r = num / len, mid;
    vector<int> b = c;
    b[str[p] - 'a'] = 0;
    ll tans = dfs(p + len, b);
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        ll offset = (c[str[p] - 'a'] - mid * len);
        if (p + len < str.size() && str[p + len] > str[p])
            offset = 0;
        if (tans + offset >= mid)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans + l;
}
void solve()
{
    cin >> str;
    cin >> a;
    cout << dfs(0, a);
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
