// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;
// bool isoperator(char ch)
// {
//     if (ch == '/' || ch == '*' || ch == '+' || ch == '-')
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// string postToInfix(string str)
// {
//     stack<string> s;
//     for (int i = 0; i < str.length(); i++)
//     {
//         if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
//         {
//             s.push(string(1, str[i]));
//         }
//         else if (isoperator(str[i]))
//         {
//             string ch2 = s.top();
//             s.pop();
//             string ch1 = s.top();
//             s.pop();
//             string infix = "(" + ch1 + str[i] + ch2 + ")";
//             s.push(infix);
//         }
//     }
//     return s.top();
// }
// int main()
// {
//     string postFix;
//     cout << "\nEntera postFix expression: ";
//     cin >> postFix;
//     cout << "\nThe postFix expression after converting into infix is: " << endl;
//     string infix = postToInfix(postFix);
//     cout << infix;
//     return 0;
// }

//<........................Using character array.....................>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isValid(string str)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            x++;
        }
        else if (str[i] == ')')
        {
            y++;
        }
        if (y > x)
        {
            return false;
        }
    }

    return x == y;
}
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
string postToIn(string str)
{
    stack<string> s;
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            s.push(string(1, str[i]));
        }
        else if (isOperator(str[i]))
        {
            string ch2 = s.top();
            s.pop();
            string ch1 = s.top();
            s.pop();
            string infix = "(" + ch1 + str[i] + ch2 + ")";
            s.push(infix);
        }
    }
    return s.top();
}
int main()
{
    string infix, postFix;
    cout << "\nEnter a postFix expression: ";
    cin.ignore();
    getline(cin, postFix);
    if (isValid(postFix))
    {
        cout << "\nThe postFix expression after converting into infix will be: " << endl;
        infix = postToIn(postFix);
        cout << infix;
    }
    else
    {
        cout << "\nInvalid expression.";
    }
    return 0;
}

//<...............preToInfix.............................>
// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;
// bool isOperator(char ch)
// {
//     if (ch == '/' || ch == '*' || ch == '+' || ch == '-')
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// string preToIn(string str)
// {
//     stack<string> s;
//     for (int i = str.length() - 1; i >= 0; i--)
//     {
//         if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
//         {
//             s.push(string(1, str[i]));
//         }
//         else
//         {
//             if (isOperator(str[i]))
//             {
//                 string ch1 = s.top();
//                 s.pop();
//                 string ch2 = s.top();
//                 s.pop();
//                 string infix = "(" + ch1 + str[i] + ch2 + ")";
//                 s.push(infix);
//             }
//         }
//     }
//     return s.top();
// }
// int main()
// {
//     string prefix = "";
//     string infix = "";
//     cout << "\nEnter any prefix expression: ";
//     cin >> prefix;
//     infix = preToIn(prefix);
//     cout << "\nAfter conversion into infix, The prefix expression is: " << infix;
//     return 0;
// }

// KL+MN*-OP^W*U/V/T*+Q+
