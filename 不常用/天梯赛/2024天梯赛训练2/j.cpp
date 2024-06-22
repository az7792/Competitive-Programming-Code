#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
struct Node
{
    string a, b;
    int f, tm, p;
};
bool ok(string &str)
{
    if (str.size() != 18)
        return false;
    for (int i = 0; i < 18; ++i)
        if (str[i] > '9' || str[i] < '0')
            return false;
    return true;
}
void solve()
{
    int D, P, ct = 0;
    cin >> D >> P;
    map<string, int> mp;
    vector<Node> ans1;
    for (int i = 1; i <= D; ++i)
    {
        int T, S;
        cin >> T >> S;
        vector<Node> tt(T);
        int hh, mm;
        for (int j = 1; j <= T; ++j)
        {
            cin >> tt[j - 1].a >> tt[j - 1].b >> tt[j - 1].f;
            scanf("%d:%d", &hh, &mm);
            tt[j - 1].tm = hh * 60 + mm;
            tt[j - 1].p = ct++;
        }
        sort(
            all(tt), [](Node a, Node b)
            { 
                        if(a.tm == b.tm)
                            return a.p < b.p;
                        return a.tm < b.tm; });

        for (auto v : tt)
        {
            if (!ok(v.b))
                continue;
            if (S >= 1)
            {
                if (mp.find(v.b) == mp.end() || i >= mp[v.b] + P + 1)
                {
                    cout << v.a << " ";
                    cout << v.b << endl;
                    mp[v.b] = i;
                    S--;
                }
            }
            else
                break;
        }

        for (auto v : tt)
        {
            if (v.f == 1 && ok(v.b))
                ans1.push_back(v);
        }
    }
    map<string, bool> mmp;
    sort(
        all(ans1), [](Node a, Node b)
        { return a.p < b.p; });
    for (auto v : ans1)
    {
        if (mmp.find(v.b) == mmp.end())
        {
            cout << v.a << " " << v.b << endl;
            mmp[v.b] = 1;
        }
    }
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
