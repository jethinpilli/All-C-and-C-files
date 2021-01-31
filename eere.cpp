#include<iostream>
using namespace std;


int max_sum(int *vector, int len)
{
    int best = 0, current = 0;
    int i = 0;
    for(i = 0; i < len; ++i)
    {
        current += *(vector + i);
        if(current < 0)
        {
            current = 0;
        }
        best = best > current ? best : current;
    }
    return best;
}

