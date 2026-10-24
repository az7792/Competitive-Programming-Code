#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        ll a;
        cin >> a;

        int ans = 0;
        while (a > 1)
        {
            a /= 2;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
