#include <iostream>
#include <stack>
using namespace std;

int precedence(char op){
    if(op == '^'){
        return 3;
    }
    else if(op == '*' || op == '/'){
        return 2;
    }
    else if(op == '+' || op =='-'){
        return 1;
    }
}

string infixToPostfix(string exp)
{
    stack<char> st;
    string postfixexp;

    for (char ch : exp)
    {
        if (isalnum(ch))
        {
            postfixexp += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfixexp += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                cout << "INVALID EXPRESSION" << endl;
                return "";
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(ch))
            {
                postfixexp += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        postfixexp += st.top();
        st.pop();
    }

    return postfixexp;
}

int evaluatepostfix(string exp)
{
    stack<int> st;

    for (char ch : exp)
    {
        if (isdigit(ch))
        {
            int operand = ch - '0';
            st.push(operand);
        }
        else
        {
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();

            int result;

            switch (ch)
            {

            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }

            st.push(result);
        }
    }
    return st.top();
}

int main()
{
    string infixExp = "1+4*2";
    string postfixExp = infixToPostfix(infixExp);
    cout<<"Postfix Exp : "<<postfixExp<<endl;

    int result = evaluatepostfix(postfixExp);
    cout<<"Result = "<<result;

    return 0;
}