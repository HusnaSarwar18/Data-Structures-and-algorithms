#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if ((ch == '*') || (ch == '/'))
    {
        return 2;
    }
    else if ((ch == '+') || (ch == '-'))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
bool isOperator(char ch)
{
    if ((ch == '^') || (ch == '/') || (ch == '*') || (ch == '+') || (ch == '-'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string infixToPrefix(string str)
{
    string prefix;
    int len = str.length();
    stack<char> s;

    for (int i = len - 1; i >= 0; i--)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            prefix += str[i];
        }
        else if (str[i] == ')')
        {
            s.push(str[i]);
        }
        else if (str[i] == '(')
        {
            while (!s.empty() && s.top() != ')')
            {
                prefix += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (isOperator(str[i]))
        {
            while (!s.empty() && s.top() != ')' && (precedence(s.top()) >= precedence(str[i])))
            {
                prefix += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }

    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}
// string infixToPrefix(stack<char> s, string str)
// {
//     string prefix;
//     int len = str.length();
//     for (int i = 0; i < len / 2; i++)
//     {
//         swap(str[i], str[len - i - 1]);
//     }

//     for (int i = 0; i < str.length(); i++)
//     {
//         if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
//         {
//             prefix += str[i];
//         }

//         else if (str[i] == '(')
//         {
//             while (!s.empty() && s.top() != ')')
//             {
//                 prefix += s.top();
//                 s.pop();
//             }
//             while (!s.empty() && s.top() == ')')
//             {
//                 s.pop();
//             }
//         }
//         else if (isOperator(str[i]))
//         {
//             while (!s.empty() && (precedence(s.top()) > precedence(str[i]) || (precedence(s.top()) == precedence(str[i]) && s.top() != '^')))
//             {
//                 prefix += s.top();
//                 s.pop();
//             }
//             s.push(str[i]);
//         }
//     }
// while (!s.empty())
// {
//     prefix += s.top();
//     s.pop();
// }
//     for (int i = 0; i < len / 2; i++)
//     {
//         swap(prefix[i], prefix[len - i - 1]);
//     }

//     return prefix;
// }
int main()
{
    string s, pre;
    cout << "\nEnter an infix expression: ";
    cin >> s;

    pre = infixToPrefix(s);
    cout << pre;
}