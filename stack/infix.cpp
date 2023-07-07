#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// a + b / (c * d)
// a + b / cd*
// a + bcd*/
// abcd*/+

// a / b + c * d
// ab/ + c * d
// ab/ + cd*
// ab/cd*+

// a + (b / c) * d
// a + bc/ * d
// a + bc/d*
// abc/d*+

// (a + (b / c)) * d
// (a + bc/) * d
// abc/+ * d
// abc/d+*
//

// e + (a + (b - c)) * d
// e + (a + bc-) * d
// e + abc-+ * d
// e + abc-+d*
// eabc-+d*+

void infixPostfix(string &s)
{
    stack<char> p;
    cout << s[0];
    for (int i = 1; i < s.length(); i++)
    {
        if (p.empty())
            p.push(s[i]);
        else if (s[i] == '+' || s[i] == '-')
        {
            if (p.top() == '/' || p.top() == '*' || p.top() == '^')
            {
                while (!p.empty())
                {
                    cout << p.top();
                    p.pop();
                }
                p.push(s[i]);
            }
            else
                p.push(s[i]);
        }
        else if (s[i] == '/' || s[i] == '*')
        {
            if (p.top() == '^')
            {
                while (!p.empty())
                {
                    cout << p.top();
                    p.pop();
                }
                p.push(s[i]);
            }
            else
                p.push(s[i]);
        }
        else if (s[i] == '^')
        {
            p.push(s[i]);
        }
        else if (s[i] == '(')
        {
            p.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!p.empty())
            {
                if (p.top() == '(')
                {
                    p.pop();
                    break;
                }
                cout << p.top();
                p.pop();
            }
        }
        else
            cout << s[i];
    }
    while (!p.empty())
    {
        cout << p.top();
        p.pop();
    }
}

int calc(int temp, int temp2, char c)
{
    if (c == '/')
        return temp2 / temp;
    if (c == '*')
        return temp * temp2;
    if (c == '+')
        return temp + temp2;
    if (c == '-')
        return temp2 - temp;
    return pow(temp2, temp);
}

int postfixOutput(string s)
{
    cout << s;
    char c = s[0];
    stack<int> p;
    string str;
    str += c;

    int temp, temp2, val;
    for (int i = 1; i < s.length(); i++)
    {
        cout << str;
        if (s[i] != ' ' && s[i] != '*' && s[i] != '/' && s[i] != '+' && s[i] != '-' && s[i] != '^')
            str = str + s[i];
        else if (s[i] == ' ')
        {
            temp = stoi(str);
            str = "";
            p.push(temp);
        }
        else
        {
            temp = p.top();
            p.pop();
            temp2 = p.top();
            p.pop();
            val = calc(temp, temp2, s[i]);
            p.push(val);
        }
    }
    return p.top();
}

// a / b + c * d
// /ab + c * d
// /ab + *cd
// +/ab*cd

void infixPrefix(string &s)
{
    stack<char> p;
    int l = s.length();
    string r;
    r = s[l - 1];
    for (int i = l - 2; i >= 0; i++)
    {
        if (p.empty())
            p.push(s[i]);
        else if (s[i] == '+' || s[i] == '-')
        {
            if (p.top() == '/' || p.top() == '*' || p.top() == '^')
            {
                while (!p.empty())
                {
                    r += p.top();
                    p.pop();
                }
                p.push(s[i]);
            }
            else
                p.push(s[i]);
        }
        else if (s[i] == '/' || s[i] == '*')
        {
            if (p.top() == '^')
            {
                while (!p.empty())
                {
                    r += p.top();
                    p.pop();
                }
                p.push(s[i]);
            }
            else
                p.push(s[i]);
        }

        else if (s[i] == '^')
            p.push(s[i]);

        else if (s[i] == ')')
            p.push(s[i]);

        else if (s[i] == '(')
            while (!p.empty())
            {
                if (p.top() == ')')
                {
                    p.pop();
                    break;
                }
                r += p.top();
                p.pop();
            }

        else
            r += s[i];
    }
    while (!p.empty())
    {
        r += p.top();
        p.pop();
    }
    cout << r;
}

int main()
{
    string d = "12 3 5 / 6 + *";
    string a = "a+b/(c*d)"; // ok
    string c = "a+(b/c)*d";
    string b = "a+b";
  //  infixPostfix(b);
    infixPrefix(b);
    // cout << postfixOutput(d);
}