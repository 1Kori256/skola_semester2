#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
 

int main()
{
    
    ifstream infile;
    infile.open("papiry.in");

    int N, P, K;
    infile >> N >> P >> K;

    vector<int> moves(P);
    for (int i = 0; i < P; i++)
    {
        infile >> moves[i]; 
    }


    ofstream output_file;
    output_file.open("papiry.out");

    for (int i = 1; i <= N; i += K)
    {
        int current_pos = i;
        for (int j = P - 1; j >= 0; j--)
        {
            if (moves[j] >= current_pos) 
            {
                current_pos--;
                if (current_pos == 0)
                {
                    current_pos = moves[j];
                }
            }
        }
        if (i > 1) {output_file << " ";}
        output_file << current_pos;
    }

    output_file.close();


    return 0;
}