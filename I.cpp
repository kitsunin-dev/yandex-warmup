// I. Правильная скобочная последовательность

// Рассмотрим последовательность, состоящую из круглых, квадратных и фигурных 
// скобок. Программа должна определить, является ли данная скобочная 
// последовательность правильной. Пустая последовательность является правильной. 
// Если A — правильная, то последовательности (A), [A], {A} — правильные. 
// Если A и B — правильные последовательности, то последовательность AB — 
// правильная.

#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::stack<char> st;
    std::string input;
    std::cin >> input;
    bool flag = true;
    for (int i = 0; i < input.size(); i++)
    {
        switch (input[i])
        {
        case '(':
        case '[':
        case '{':
            st.push(input[i]);
            break;

        case ')':
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                flag = false;

            break;

        case ']':
            if (!st.empty() && st.top() == '[')
                st.pop();
            else
                flag = false;

            break;

        case '}':
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
                flag = false;

            break;
        
        default:
            break;
        }

        if (!flag)
        {
            std::cout << "no";
            return 0;
        }
        flag = true;
    }

    if (st.empty())
        std::cout << "yes";
    else
        std::cout << "no";
        
    return 0;
}