#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    unordered_map<ll, int> points_map;
    vector<ll> points(n);
    ll a;
    ll b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        points_map[(a << 32) | b] = i;
        points[i] = (a << 32) | b;
    }


    int p_x, p_y, q_x, q_y;
    ll a_x, a_y, b_x, b_y;
    ll final_1, final_2;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++)
        {
            p_x = points[i] >> 32;
            p_y = points[i];
            q_x = points[j] >> 32;
            q_y = points[j];

            if ((p_x + p_y + q_x + q_y) % 2 == 0)
            {
                a_x  = (p_x + q_x + p_y - q_y) / 2;
                a_y  = (- p_x + q_x + p_y + q_y) / 2;
                b_x  = (p_x + q_x - p_y + q_y) / 2;
                b_y  = (p_x - q_x + p_y + q_y) / 2;

                final_1 = (a_x << 32) | a_y;
                final_2 = (b_x << 32) | b_y;

                if (points_map.find(final_1) != points_map.end() && points_map.find(final_2) != points_map.end())
                {
                    cout << i << " " << points_map[final_1] << " " << j << " " << points_map[final_2] << "\n";
                    return 0;
                }
            }
        }
    }

    return 0;
}