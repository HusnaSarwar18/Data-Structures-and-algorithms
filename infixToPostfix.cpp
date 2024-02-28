#include <iostream>
#include <iostream>
#include <stack>
using namespace std;
bool isOperator(char ch)
{
    if (ch == '/' || ch == '*' || ch == '+' || ch == '-')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '/' || ch == '*')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string intfixToPostFix(stack<char> s, string str)
{
    string postfix;
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            postfix += str[i];
        }
        else if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (isOperator(str[i]))
        {
            if (!s.empty() && (precedence(str[i]) < precedence(s.top()) || (precedence(s.top()) == precedence(str[i]) && str[i] != '^')))

            {
                postfix += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    if (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
int main()
{
    stack<char> s;
    string infix, post;
    cout << "\nEnter an infix expression: ";
    cin >> infix;
    cout << "\nThe postfix expression of entered infix is: ";
    post = intfixToPostFix(s, infix);
    cout << post;
    return 0;
}