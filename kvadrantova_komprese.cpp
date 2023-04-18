#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string header;
    int n, m;
    cin >> header;
    cin >> n >> m;
    
    // Default, full 0, full 1
    vector<vector<vector<int>>> picture(n, vector<vector<int>>(n, vector<int>(3))); 

    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            picture[i][j][0] = 0;
            if (x == 0) {picture[i][j][1] = 0; picture[i][j][2] = 1;} 
            if (x == 1) {picture[i][j][1] = 1; picture[i][j][2] = 0;} 
        }
    }

    while (n > 1) {
        for (int i = 0; i < n; i += 2)
        {
            for (int j = 0; j < n; j += 2)
            {
                vector<int> a, b, c, d;
                a = picture[i][j];
                b = picture[i][j + 1];
                c = picture[i + 1][j];
                d = picture[i + 1][j + 1];

                int full_black = a[1] + b[1] + c[1] + d[1];
                int full_white = a[2] + b[2] + c[2] + d[2];

                int colored = 4194304;
                colored = min(colored, a[1] + b[2] + c[0] + d[0]);
                colored = min(colored, a[2] + b[1] + c[0] + d[0]);

                colored = min(colored, a[1] + b[0] + c[2] + d[0]);
                colored = min(colored, a[2] + b[0] + c[1] + d[0]);

                colored = min(colored, a[1] + b[0] + c[0] + d[2]);
                colored = min(colored, a[2] + b[0] + c[0] + d[1]);

                colored = min(colored, a[0] + b[1] + c[2] + d[0]);
                colored = min(colored, a[0] + b[2] + c[1] + d[0]);

                colored = min(colored, a[0] + b[1] + c[0] + d[2]);
                colored = min(colored, a[0] + b[2] + c[0] + d[1]);

                colored = min(colored, a[0] + b[0] + c[1] + d[2]);
                colored = min(colored, a[0] + b[0] + c[2] + d[1]);

                picture[i / 2][j / 2] = {colored, full_black, full_white};
            }
        }
        n /= 2;
    }

    cout << picture[0][0][0];

    return 0;
}