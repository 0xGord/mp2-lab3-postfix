#include "postfix.h"

void TPostfix::space_removing()
{
	infix.erase(remove(infix.begin(), infix.end(), ' '), infix.end());
}

void TPostfix::fill_postfix(stack<char> st)
{
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
}

string TPostfix::get_str_number(size_t *i, string s)
{
    string str_number = "";
    for (size_t j = *i; j < s.length(); j++, (*i)++)
        if (isdigit(s[j]))
            str_number += s[j];
        else
            break;
    (*i)--;
    return str_number;
}
double TPostfix::math(double left, double right, char op)
{
    {
        switch (op)
        {
            case '+': return left + right;
            case '-': return left - right;
            case '*': return left * right;
            case '/': return left / right;
            case '^': return pow(left, right);
        }
    }
}

string TPostfix::to_postfix()
{
    space_removing();
    postfix = "";
    stack<char> st;
    int flag = 0;
    for (size_t i = 0; i < infix.length(); i++)
    {
        if (isdigit(infix[i]))
            postfix += get_str_number(&i, infix) + ' ';
        else
            if (infix[i] == '(')
            {
                st.push(infix[i]);
                flag++;
            }
            else
                if (infix[i] == ')')
                {
                    while (!st.empty() > 0 && st.top() != '(')
                    {
                        postfix += st.top();
                        st.pop();
                    }
                    st.pop();
                    flag--;
                }
                else
                    if ((priority.find(infix[i]) != priority.end()))
                    {

                        while (!st.empty() > 0 && priority[st.top()] >= priority[infix[i]])
                        {
                            postfix += st.top();
                            st.pop();
                        }
                        st.push(infix[i]);
                    }
    }
    fill_postfix(st);
    if (flag != 0)
        throw invalid_argument("");
    return postfix;
}

double TPostfix::calculate()
{
    double last;
    double first;
    stack<double> operands;
    for (size_t i = 0; i < postfix.length(); i++)
    {
        if (isdigit(postfix[i]))
            operands.push(stoi(get_str_number(&i, postfix)));
        else if (priority.find(postfix[i]) != priority.end())
        {
            last = operands.top();
            operands.pop();
            first = operands.top();
            operands.pop();
            operands.push(math(first, last, postfix[i]));
        }

    }
    double x = operands.top();
    operands.pop();
    return x;
}
