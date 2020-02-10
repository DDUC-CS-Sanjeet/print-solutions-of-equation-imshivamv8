#include <iostream>
using namespace std;

void printSolutions(int , int );

int main()
{
    int n = 0, c = 0;
    try
    {
        cout << "Enter the value of n and C for the Equation: X1 + X2 + ... + Xn = C : " << endl;
        cin >> n >> c;
        if(n < 1)
            throw "Can't find solutions for n < 1 !!!";
        else
        {
            cout << "The Solution Sets are..." << endl;
            printSolutions(n, c);
        }
    }
    catch(const char *exceptions)
    {
        cout << exceptions << endl;
    }
    return 0;
}

void printSolutions(int n, int c)
{
    int *solutions = new int[n];
    for(int index = 0; index < n; ++index)
        solutions[index] = 0;
    bool iterate = true;
    while(iterate == true)
    {
        bool flag = true;
        int sum = 0;
        for(int index = 0; index < n; ++index)
        {
            if(solutions[index] == c + 1)
            {
                solutions[index] = 0;
                if(index == n - 1)
                {
                    flag = false;
                    break;
                }
                solutions[index + 1]++;
            }
            sum += solutions[index];
        }
        if(flag == false)
            break;
        if(sum == c)
        {
            for(int index = n - 1; index >= 0; --index)
                cout << solutions[index] << " ";
            cout << endl;
        }
        solutions[0] ++;
    }
    delete[] solutions;
}