#include <iostream>
#include <ctype.h>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <fstream>

using namespace std;

int bs(int a[], int n, int x)
{
    int high = n - 1, low = 0, mid;
    while (low <= high)
    {
        mid = low / 2 + high / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int recbs(int a[], int high, int x, int low = 0)
{
    int mid = low / 2 + high / 2;

    if (low > high)
        return -1;
    else if (a[mid] == x)
        return mid;
    else if (a[mid] > x)
        return recbs(a, mid - 1, x, low);
    else
        return recbs(a, high, x, mid + 1);
}
bool palin(string a, int end, int start = 0)
{
    if (start >= end)
        return true;
    if (a[start] != a[end])
        return false;
    return palin(a, end - 1, start + 1);
}
void searchpattern(string &txt, string &ptr)
{
    int a = 0, f = 0, p = ptr.length();
    for (int i = 0; i < txt.length(); i++)
    {

        if (ptr[a] == txt[i])
        {
            a++;
            f = 1;
        }
        else
        {
            a = 0;
        }
        if (a == p)
        {
            cout << i - a;
        }
    }
}

int singer()
{
    // ifstream myfile("/home/akm/Downloads/output.txt");
    ifstream myfile("./a.txt");
    int n = 200000, maxi = 0, numFavorites = 0, temp;
    unordered_map<string, int> m;
    //  cin >> n;
    string myline;
    if (myfile.is_open())
    {
        while (myfile)
        {
            getline(myfile, myline);
            m[myline]++;
            max(maxi, m[myline]);
            cout << myline << ": " << myfile.tellg() << '\n';
        }
    }

    for (int i = 0; i < n; i++)
    {
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second == maxi)
        {
            numFavorites++;
        }
    }
    return numFavorites;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 33, 54, 55, 76, 88};
    // char b[] = 'hello how are you?';
    //  cout << recbs(a, 14, 9);
    //  cout << palin(b, b.length() - 1);
    // rev(b, 17);
    cout << singer();
}