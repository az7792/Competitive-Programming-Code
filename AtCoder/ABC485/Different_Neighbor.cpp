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
        int n, l, r;
    };

    void solve()
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        map<int, int> mp;
        vector<Node> arr;
        for (int i = 1; i <= n; ++i)
        {
            if (arr.empty())
            {
                arr.push_back({a[i], i, i});
            }
            else if (arr.back().n == a[i])
            {
                arr.back().r++;
            }
            else
            {
                arr.push_back({a[i], i, i});
            }

            mp[i] = arr.size() - 1;
        }

        for (int i = 1; i <= n; ++i)
        {
            int p = mp[i];
            int prev = p - 1;
            int next = p + 1;

            int ans = 1e9;
            if (prev >= 0)
            {
                ans = min(ans, i - arr[prev].r);
            }
            if (next < arr.size())
            {
                ans = min(ans, arr[next].l - i);
            }
            cout << ans << " ";
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