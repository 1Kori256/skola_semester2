#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <map>
typedef unsigned long long ll;
using namespace std;

struct point
{
    ll a;
    ll b;
    ll c;
};


bool custom_compare1(point const &a, point const &b)
{
    if (a.a < b.a) {return true;}
    if (a.a == b.a && a.b < b.b) {return true;}
    return false;
}

bool custom_compare2(point const &a, point const &b)
{
    if (a.b < b.b) {return true;}
    if (a.b == b.b && a.a < b.a) {return true;}
    return false;
}

bool custom_compare3(point const &a, point const &b)
{
    return (a.c < b.c);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    cin >> N;

    struct point points[N];
    ll x_partners[N];
    ll y_partners[N];

    for (ll i = 0; i < N; i++)
    {
        cin >> points[i].a;
        cin >> points[i].b;
        points[i].c = i;
    }

    std::sort(points, points + N, &custom_compare1);

    for (ll i = 0; i < N; i+=2)
    {
        x_partners[points[i].c] = points[i + 1].c;
        x_partners[points[i + 1].c] = points[i].c;
    }

    std::sort(points, points + N, &custom_compare2);

    for (ll i = 0; i < N; i+=2)
    {
        y_partners[points[i].c] = points[i + 1].c;
        y_partners[points[i + 1].c] = points[i].c;    
    }

    std::sort(points, points + N, &custom_compare3);

    int current_point = 0;
    int current_axis = 0;
    for (ll i = 0; i < N; i++)
    {
        cout << points[current_point].a << " " << points[current_point].b << "\n";
        if (current_axis == 0)
        {
            current_point = x_partners[current_point];
            current_axis = 1;
        } else
        {
            current_point = y_partners[current_point];
            current_axis = 0;
        }
    }

    return 0;
}