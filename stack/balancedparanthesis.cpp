#include <iostream>
#include <stack>
using namespace std;
bool match(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
}

bool check(string a)
{
    stack<char> s;

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '(' || a[i] == '{' || a[i] == '[')
        {
            s.push(a[i]);
        }
        else
        {
            if (s.empty())
                return false;
            else if (!match(s.top(), a[i]))
                return false;
            else
                s.pop();
        }
    }
    return s.empty();
}
int main()
{
    string a = "((({}[])))";
    cout << check(a);
    return 0;
}