#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<stack>

using namespace std;

class TPostfix
{
    string infix;
    string postfix;
    map <char, int> priority = { {'(',0}, {'+',1}, {'-',1}, {'*',2}, {'/',2}, {'^',3} };

public:
    void space_removing();
    void fill_postfix(stack<char> st);
    string get_str_number(size_t *i, string s);
    double math(double s1, double s2, char op);
    TPostfix(const string infx = "")
    {
        infix = infx;
        to_postfix();
    }
    string GetInfix() { return infix; }
    string GetPostfix() { return postfix; }
    string to_postfix();
    double calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
