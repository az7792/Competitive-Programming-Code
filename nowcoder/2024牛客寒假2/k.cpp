#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
int n;
vector<int> num;
vector<char> ch;
vector<int> chnum;
vector<vector<int>> ep;
set<int> s;
string str;
int ans, y;
void dfs(int p)
{
    if (p == ch.size() - 1)
    {
        for (int i = 0; i < ch.size(); ++i)
        {
            for (auto v : ep[ch[i] - 'a'])
            {
                num[v] = chnum[i];
            }
        }
        if ((num.size() > 1 && num[0] == 0) || num.back() % 2 == 1)
            return;
        int tmpnum = 0;
        int ppp = 1;
        for (int i = num.size() - 1; i >= 0; --i)
        {
            tmpnum += num[i] * ppp;
            ppp *= 10;
        }
        if (tmpnum % 8 == 0 && tmpnum <= y)
            ans++;
        return;
    }
    for (int i = 0; i <= 9; ++i)
    {
        if (s.find(i) != s.end())
            continue;
        s.insert(i);
        chnum[p + 1] = i;
        dfs(p + 1);
        s.erase(i);
    }
}
void solve()
{
    // 0 2 4 6 8
    ans = 0;
    num.clear(), ch.clear(), ep.clear(), s.clear(), chnum.clear();
    cin >> n;
    num.resize(n, 0);
    ep.resize(26);
    cin >> str;
    cin >> y;
    int p = -1;
    for (int i = 0; i < str.size(); ++i)
    {
        char v = str[i];
        if ('a' <= v && v <= 'z')
        {
            ch.push_back(v);
            ep[v - 'a'].push_back(i);
        }
        else if (v == '_')
            p = i;
        else
            num[i] = v - '0';
    }
    sort(all(ch));
    ch.erase(unique(all(ch)), ch.end());
    chnum.resize(ch.size());
    if (p != -1)
    {
        for (int i = 0; i <= 9; ++i)
        {
            num[p] = i;
            dfs(-1);
        }
    }
    else
    {
        dfs(-1);
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
