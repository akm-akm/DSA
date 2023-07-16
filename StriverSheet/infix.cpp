#include <iostream>
using namespace std;
// a + b * c / d
// a + bc* / d
// a + bc*d/
// abc*d/+

#include <stack>
string infixToPostfix(string exp)
{
    stack<char> s;
    int i = 0;
    while (exp[i] == '(')
    {
        s.push(exp[0]);
        i++;
    }

    string r(1, exp[i]);
    i++;
    for (i; i < exp.length(); i++)
    {
        if (s.empty() &&
            (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*' || exp[i] == '^' || exp[i] == '(' || exp[i] == ')'))
            s.push(exp[i]);

        else if (exp[i] == '+' || exp[i] == '-')
        {
            if (s.top() == '/' || s.top() == '*' || s.top() == '^')
            {
                while (!s.empty() && s.top() != '(')
                {
                    r += s.top();
                    s.pop();
                }
                s.push(exp[i]);
            }
            else if (s.top() == '+' || s.top() == '-')
            {
                r += s.top();
                s.pop();
                s.push(exp[i]);
            }
            else
                s.push(exp[i]);
        }
        else if (exp[i] == '*' || exp[i] == '/')
        {
            if (s.top() == '^')
            {
                while (!s.empty() && s.top() != '(')
                {
                    r += s.top();
                    s.pop();
                }
                s.push(exp[i]);
            }
            else if (s.top() == '/' || s.top() == '*')
            {
                r += s.top();
                s.pop();
                s.push(exp[i]);
            }
            else
                s.push(exp[i]);
        }
        else if (exp[i] == '^')
        {
            if (s.top() == '^')
            {
                r += s.top();
                s.pop();
            }
            s.push('^');
        }
        else if (exp[i] == '(')
        {
            s.push('(');
        }
        else if (exp[i] == ')')
        {
            while (s.top() != '(')
            {
                r += s.top();
                s.pop();
            }
            s.pop();
        }
        else
            r += exp[i];
    }
    while (!s.empty())
    {
        r += s.top();
        s.pop();
    }
    return r;
}

int main()
{
    string d = "12 3 5 / 6 + *";
    string a = "a+b/(c*d)"; // ok
    string c = "a+(b/c)*d";
    string b = "(3-2+l/8)-(4+6/3*(5^8))";
    cout
        << infixToPostfix(b);
    //  infixPrefix(b);
    // cout << postfixOutput(d);
}