// B. Сложить две дроби

// Даны две рациональные дроби: a/b и c/d. Сложите их и результат 
// представьте в виде несократимой дроби m/n.

#include <iostream>

int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) 
{
    short int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int res1 = a * d + c * b, res2 = b * d;

    std::cout << res1 / gcd(res1, res2) << " " << res2 / gcd(res1, res2);

    return 0;
}