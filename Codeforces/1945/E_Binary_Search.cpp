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
int T = 1;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    vector<bool> vis(n + 1, 0);
    int l = 1, r = n, mid;
    mid = (l + r + 1) / 2;
    int pos;
    for (int i = 1; i <= n; ++i)
        if (p[i] == x)
        {
            pos = i;
            break;
        }
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        if (p[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    if (p[l] == x)
    {
        cout << 0 << endl;
        return;
    }
    l = 1, r = n, mid = 0;
    vector<pii> ans;
    if (mid == pos)
    {
        int a = -1, b = -1;
        for (int i = l; i <= mid - 1; ++i)
        {
            if (p[i] < x)
            {
                a = i;
                break;
            }
        }
        for (int i = mid + 1; i <= r; ++i)
        {
            if (p[i] > x)
            {
                b = i;
                break;
            }
        }
        int ppp;
        if (a == -1 && b == -1)
        {
            ppp = 1;
            swap(p[1], p[mid]);
            ans.push_back({1, mid});
        }
        else if (a != -1)
        {
            ppp = a;
            swap(p[mid], p[a]);
            ans.push_back({mid, a});
        }
        else
        {
            ppp = b;
            swap(p[mid], p[a]);
            ans.push_back({mid, a});
        }
        while (l < r)
        {
            mid = (l + r + 1) / 2;
            if (p[mid] <= x)
                l = mid;
            else
                r = mid - 1;
        }
        ans.push_back({l, ppp});
        swap(p[l], p[ppp]);
    }
    else
    {
        int ppp = pos;
        if (p[mid] <= x)
        {
            if (pos >= mid)
            {
                swap(p[1], p[pos]);
                ans.push_back({1, pos});
                ppp = 1;
            }
        }
        else
        {
            if (pos <= mid)
            {
                swap(p[n], p[pos]);
                ans.push_back({n, pos});
                ppp = n;
            }
        }
        while (l < r)
        {
            mid = (l + r + 1) / 2;
            if (p[mid] <= x)
                l = mid;
            else
                r = mid - 1;
        }
        ans.push_back({l, ppp});
        swap(p[l], p[ppp]);
    }

    // l = 1, r = n, mid = 0;
    // while (l < r)
    // {
    //     mid = (l + r + 1) / 2;
    //     if (p[mid] <= x)
    //         l = mid;
    //     else
    //         r = mid - 1;
    // }
    // if (p[l] == x)
    //     cout << "Ok" << T << endl;
    // T++;
    cout << ans.size() << endl;
    for (auto v : ans)
        cout << v.first << " " << v.second << endl;
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
