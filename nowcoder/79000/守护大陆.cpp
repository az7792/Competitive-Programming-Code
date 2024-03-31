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
struct midnum
{
    // 默认*L.rbegin()为中位数
    multiset<int> L, R;
    void insert(int num)
    {
        if (L.size() == R.size())
        {
            if (L.size() == 0 || num <= *R.begin())
                L.insert(num);
            else
            {
                L.insert(*R.begin());
                R.erase(R.begin());
                R.insert(num);
            }
        }
        else
        {
            if (*L.rbegin() <= num)
                R.insert(num);
            else
            {
                R.insert(*L.rbegin());
                L.erase(prev(L.end()));
                L.insert(num);
            }
        }
    }

    void erase(int num)
    {
        if (L.size() == R.size())
        {
            if (num >= *R.begin())
                R.erase(R.find(num));
            else
            {
                L.erase(L.find(num));
                L.insert(*R.begin());
                R.erase(R.begin());
            }
        }
        else
        {
            if (num <= *L.rbegin())
            {
                L.erase(L.find(num));
            }
            else
            {
                R.erase(R.find(num));
                R.insert(*L.rbegin());
                L.erase(prev(L.end()));
            }
        }
    }

    int getnum()
    {
        if (L.empty())
            return 0;
        return *L.rbegin();
    }

    bool empty()
    {
        return L.empty();
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    midnum a, b;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }

    for (int i = 0; i < m; ++i)
    {
        int tmp;
        cin >> tmp;
        b.insert(tmp);
    }
    ll A = a.getnum() * (ll)n;
    ll B = b.getnum() * (ll)m;
    if(A>B)
        cout << "Yes";
    else if(A<B)
        cout << "No";
    else
        cout << "NY";
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
