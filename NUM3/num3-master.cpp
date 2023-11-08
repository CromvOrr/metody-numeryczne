#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

void setUp(int size, vector<vector<double>> &array, vector<double> &x, vector<double> &y)
{
    array.resize(4, vector<double>(size, 0.0));

    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            array[0][i] = 0;
        }
        else
        {
            array[0][i] = 0.2;
        }

        array[1][i] = 1.2;
        array[2][i] = 0.1 / (i + 1);
    }

    for (int i = 0; i < size - 1; i++)
    {
        array[3][i] = 0.15 / ((i + 1) * (i + 1));
    }

    for (int i = 0; i < size; i++)
    {
        x[i] = i + 1;
        y[i] = 0.0;
    }
}

void operations(int size, vector<vector<double>> &array, vector<double> &x, vector<double> &y)
{
    for (int i = 1; i < (size - 2); i++)
    {
        array[0][i] = array[0][i] / array[1][i - 1];
        array[1][i] = array[1][i] - array[0][i] * array[2][i - 1];
        array[2][i] = array[2][i] - array[0][i] * array[3][i - 1];
    }

    array[0][size - 2] = array[0][size - 2] / array[1][size - 3];
    array[1][size - 2] = array[1][size - 2] - array[0][size - 2] * array[2][size - 3];
    array[2][size - 2] = array[2][size - 2] - array[0][size - 2] * array[3][size - 3];
    array[0][size - 1] = array[0][size - 1] / array[1][size - 2];
    array[1][size - 1] = array[1][size - 1] - array[0][size - 1] * array[2][size - 2];

    for (int i = 1; i < size; i++)
    {
        x[i] = x[i] - array[0][i] * x[i - 1];
    }

    y[size - 1] = x[size - 1] / array[1][size - 1];
    y[size - 2] = (x[size - 2] - array[2][size - 2] * x[size - 1]) / array[1][size - 2];

    for (int i = size - 3; i >= 0; i--)
    {
        y[i] = (x[i] - array[2][i] * x[i + 1] - array[3][i] * x[i + 2]) / array[1][i];
    }
}

double calcuateDet(int size, vector<vector<double>> &array, double det = 1)
{
    for (int i = 0; i < size; i++)
    {
        det *= array[1][i];
    }

    return det;
}

int main()
{
    const int N = 124;
    vector<double> x(N), y(N);
    vector<vector<double>> A;

    auto start = chrono::high_resolution_clock::now();
    setUp(N, A, x, y);
    operations(N, A, x, y);
    auto end = chrono::high_resolution_clock::now();
    auto timePassed = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

    cout << "|A| =\t\t\t" << calcuateDet(N, A) << "\n";
    cout << "Runtime for N = 124:\t" << timePassed << "ms\n\n";

    cout << "y =    [" << y[0] << "\n";
    for (int i = 1; i < N - 1; i++)
    {
        cout << "\t" << y[i] << "\n";
    }
    cout << "\t" << y[N - 1] << "]\n";

    //* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    int step = 100, maxN = 10000;
    ofstream data("data.dat");

    data << 0 << "\t" << 0 << endl;
    for (int i = step; i <= maxN; i += step)
    {
        start = chrono::high_resolution_clock::now();

        vector<double> xx(i), yy(i);
        vector<vector<double>> testing;

        setUp(i, testing, xx, yy);
        operations(i, testing, xx, yy);

        end = chrono::high_resolution_clock::now();
        timePassed = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

        data << i << "\t" << timePassed << endl;
    }

    data.close();

    return 0;
}