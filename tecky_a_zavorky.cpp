#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <stdio.h>
#include <bits/stdc++.h>
#include <fstream>
typedef long long ll;
using namespace std;

const string precalculated[32] = { ".", "()", "(())", "(.())", "((()))", "(..())", "(()())", "(...())", "((.()))", "(.(()))", "(().())", "(....())", "((())())", "(.....())", "(()..())", "(.()())", "(((())))", "(......())", "(()(()))", "(.......())", "((()).())", "(.().())", "(()...())", "(........())", "((.())())", "(..(()))", "(()....())", "(.(.()))", "((())..())", "(.........())", "(()()())", "(..........())" };


void simpleSieve(int limit, vector<int> &prime)
{
    vector<bool> mark(limit + 1, true);
 
    for (int p=2; p*p<limit; p++)
    {
        if (mark[p] == true)
        {
            for (int i=p*p; i<limit; i+=p)
                mark[i] = false;
        }
    }

    for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
        }
    }
}


string segmentedSieve(int n)
{
    string ans = "(";
    int real_n = n;
    n = min(n, 6000000) + 1;
    int limit = floor(sqrt(n))+1;
    vector<int> prime;
    prime.reserve(limit);
    simpleSieve(limit, prime);
 
    int cnt = 0;
    for(int i = 0; i < prime.size() && real_n > 1; i++)
    {
        cnt = 0;
        while (real_n % prime[i] == 0) {
            cnt++;
            real_n /= prime[i];
        }
        ans += precalculated[cnt];
    }

    if (real_n > 1)
    {
        int low = limit;
        int high = 2*limit;
    
        while (low < n && real_n > 1)
        {
            if (high >= n)
            high = n;

            bool mark[limit+1];
            memset(mark, true, sizeof(mark));
    
            for (int i = 0; i < prime.size(); i++)
            {
                int loLim = floor(low/prime[i]) * prime[i];
                if (loLim < low)
                    loLim += prime[i];
    
                for (int j=loLim; j<high; j+=prime[i])
                    mark[j-low] = false;
            }
    
            for (int i = low; i<high; i++)
            {
                if (mark[i - low] == true)  
                {
                    if (real_n % i == 0)
                    {
                        cnt = 0;
                        while (real_n % i == 0) {
                            cnt++;
                            real_n /= i;
                        }
                        ans += precalculated[cnt];
                    }
                    else if (real_n > 1)
                    {
                        ans += ".";
                    }
                }
            }
    
            low = low + limit;
            high = high + limit;
        }
    }

    ans += ")";
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream infile;
    infile.open("cisla.in");

    ofstream output_file("cisla.out");

    if (infile.is_open())
    {
        int num; 
        while(infile >> num)
        {
            string ans;
            if (num < 32) 
            {
                ans = precalculated[num];
            } 
            else
            {
                ans = segmentedSieve(num);
            }
            output_file << ans << "\n";
        }
    }

    output_file.close();

    return 0;
}   