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
double len(pair<double, double> a, pair<double, double> b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
double K(pair<double, double> a, pair<double, double> b)
{
    if (a.first == b.first)
        return 1e18;
    return (a.second - b.second) / (a.first - b.first);
}
void solve()
{
    int n;
    cin >> n;
    vector<pii> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i].first >> a[i].second;
    map<pii, vector<pair<pii, pii>>> mp;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[i].first - a[j].first > 0)
            {
                mp[{a[i].first - a[j].first, a[i].second - a[j].second}].push_back({a[i], a[j]});
            }
            else if (a[i].first - a[j].first < 0)
            {
                mp[{a[j].first - a[i].first, a[j].second - a[i].second}].push_back({a[i], a[j]});
            }
            else
            {
                if (a[i].second - a[j].second > 0)
                    mp[{a[i].first - a[j].first, a[i].second - a[j].second}].push_back({a[i], a[j]});
                else
                    mp[{a[i].first - a[j].first, a[j].second - a[i].second}].push_back({a[i], a[j]});
            }
        }
    double ans = -1;
    for (auto [v1, v2] : mp)
    {
        if (v2.size() <= 1)
            continue;
        if (v1.second >= 0)
        {
            double x0 = -1e9, y0 = 1e9;
            sort(all(v2), [&](pair<pii, pii> A, pair<pii, pii> B)
                 {
                    double AA,BB,CC,len1,len2;
                    if(A.first.first == A.second.first)
                        len1 = 1e9 - A.first.second;
                    else{
                      BB = 1, AA = -(A.first.second - A.second.second) / (A.first.first - A.second.first);
                      CC = -AA * A.second.first - A.second.second;
                     len1 = (fabs(AA * x0 + BB * y0 + CC) / sqrt(AA * AA + BB * BB));
                     }


                     if(B.first.first == B.second.first)
                        len2 = 1e9 - B.first.second;
                    else{
                      BB = 1, AA = -(B.first.second - B.second.second) / (B.first.first - B.second.first);
                      CC = -AA * B.second.first - B.second.second;
                     len2 = (fabs(AA * x0 + BB * y0 + CC) / sqrt(AA * AA + BB * BB));
                     }

                     return len1 < len2; });
            double area1, area2;
            double X1 = v2[0].first.first, Y1 = v2[0].first.second;
            double X2 = v2[0].second.first, Y2 = v2[0].second.second;
            double X3 = v2.back().first.first, Y3 = v2.back().first.second;
            area1 = area1 = 0.5 * abs(X1 * (Y2 - Y3) + X2 * (Y3 - Y1) + X3 * (Y1 - Y2));
            X3 = v2.back().second.first, Y3 = v2.back().second.second;
            area2 = area1 = 0.5 * abs(X1 * (Y2 - Y3) + X2 * (Y3 - Y1) + X3 * (Y1 - Y2));
            if (area1 + area2 >= 1e-6)
            {
                ans = max(ans, area1 + area2);
            }
        }
        else
        {
            double x0 = 1e9, y0 = 1e9;
            sort(all(v2), [&](pair<pii, pii> A, pair<pii, pii> B)
                 {
                    double AA,BB,CC,len1,len2;
                    if(A.first.first == A.second.first)
                        len1 = 1e9 - A.first.second;
                    else{
                      BB = 1, AA = -(A.first.second - A.second.second) / (A.first.first - A.second.first);
                      CC = -AA * A.second.first - A.second.second;
                     len1 = (fabs(AA * x0 + BB * y0 + CC) / sqrt(AA * AA + BB * BB));
                     }


                     if(B.first.first == B.second.first)
                        len2 = 1e9 - B.first.second;
                    else{
                      BB = 1, AA = -(B.first.second - B.second.second) / (B.first.first - B.second.first);
                      CC = -AA * B.second.first - B.second.second;
                     len2 = (fabs(AA * x0 + BB * y0 + CC) / sqrt(AA * AA + BB * BB));
                     }

                     return len1 < len2; });
            double area1, area2;
            double X1 = v2[0].first.first, Y1 = v2[0].first.second;
            double X2 = v2[0].second.first, Y2 = v2[0].second.second;
            double X3 = v2.back().first.first, Y3 = v2.back().first.second;
            area1 = area1 = 0.5 * abs(X1 * (Y2 - Y3) + X2 * (Y3 - Y1) + X3 * (Y1 - Y2));
            X3 = v2.back().second.first, Y3 = v2.back().second.second;
            area2 = area1 = 0.5 * abs(X1 * (Y2 - Y3) + X2 * (Y3 - Y1) + X3 * (Y1 - Y2));
            if (area1 + area2 >= 1e-6)
            {
                ans = max(ans, area1 + area2);
            }
        }
    }

    if (ans == -1)
        cout << -1;
    else
        printf("%.1lf", ans);
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
