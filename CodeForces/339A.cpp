//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
// 8 directions
const ll rows[] = {1, -1, 0, 0, 1, -1, 1, -1};
const ll cols[] = {0, 0, 1, -1, 1, -1, -1, 1};

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    T = 1;
    while (T--)
    {
        string s;
        cin >> s;

        if (s.find('+') == string::npos)
            cout << s;
        else
        {
            multiset<ll> MS;
            for (int i = 0; i < s.size(); i++)
                if (s[i] != '+')
                    MS.insert((s[i] - '0'));

            string ans = "";
            for (multiset<ll>::iterator it = MS.begin(); it != MS.end(); it++)
            {
                ll val = *it;
                ans += (char)((char)val + '0');
                ans += '+';
            }
            cout << ans.substr(0, ans.size() - 1);
        }
    }
    return 0;
}
// END OF SOURCE CODE