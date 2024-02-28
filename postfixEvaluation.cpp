#include <iostream>
#include <string>
#include <math.h>
#define size 10
using namespace std;
// defining stack
class Stack
{
private:
    int top;
    char *arr;

public:
    Stack()
    {
        arr = new char[size];
        top = -1;
    }
    char push(char data)
    {
        if (isFull())
        {
            cout << "Stack is full.";
            return '\0';
        }
        else
        {
            if (top == -1)
            {
                top++;
                arr[top] = data;
                return arr[top];
            }
            else
            {
                top++;
                arr[top] = data;
                return arr[top];
            }
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "\nNothing to pop, As stack is Empty.";
            return;
        }
        else
        {
            top--;
        }
    }
    char peek()
    {
        if (isEmpty())
        {
            cout << "\nNo element in the stack.";
            return '\0';
        }
        else
        {
            return arr[top];
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "\nNothing to display. ";
            return;
        }
        else
        {
            cout << "\nThe elements of stack are: " << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

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
    if ((ch == '^') || (ch == '/') || (ch == '*') || (ch == '+') || (ch == '-'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string infixToPostfix(string str)
{
    string postfix;
    Stack s;

    for (int i = 0; i < str.length(); i++)
    {
        if (!isValid(str))
        {
            cout << "\nInvalid expression.";
            return str;
        }
        else
        {
            if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
            {
                postfix += str[i];
            }
            else if (str[i] == '(')
            {
                s.push(str[i]);
            }
            else if (str[i] == ')')
            {
                while (!s.isEmpty() && s.peek() != '(')
                {
                    postfix += s.peek();
                    s.pop();
                }
                s.pop();
            }
            else if (isOperator(str[i]))
            {
                while (!s.isEmpty() && precedence(str[i]) <= precedence(s.peek()) && s.peek() != '^')
                {
                    postfix += s.peek();
                    s.pop();
                }
                s.push(str[i]);
            }
        }
    }

    while (!s.isEmpty())
    {
        postfix += s.peek();
        s.pop();
    }

    return postfix;
}

int postFixEvaluation(string str)
{
    Stack s;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
        {
            s.push(str[i] - '0'); // convert character to numeric digit
        }
        else
        {
            if (isOperator(str[i]))
            {
                int result = 0;
                int A = s.peek();
                s.pop();
                int B = s.peek();
                s.pop();
                if (str[i] == '+')
                {
                    result = B + A;
                }
                else if (str[i] == '-')
                {
                    result = B - A;
                }
                else if (str[i] == '*')
                {
                    result = B * A;
                }
                else if (str[i] == '/')
                {
                    result = B / A;
                }
                else if (str[i] == '^')
                {
                    result = pow(B, A);
                }
                s.push(result);
            }
        }
    }
    return s.peek();
}

int main()
{
    string infix;
    cout << "\nEnter an infix expression: ";
    getline(cin, infix);
    string postFix = infixToPostfix(infix);
    cout << "\nThe infix expression after converting into postfix expression is: " << postFix;
    cout << "\nAfter evaluation, The reault will be: ";
    int Answer = postFixEvaluation(postFix);
    cout << Answer;

    return 0;
}
