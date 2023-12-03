// A. Не минимум на отрезке

// Задана последовательность целых чисел a1, a2, …, an. 
// Задаются запросы: сказать любой элемент последовательности на отрезке 
// от L до R включительно, не равный минимуму на этом отрезке.

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> A;
    int n, m, l, r;
    
    std::cin >> n >> m;
    A.resize(n);

    for (int i = 0; i < n; i++)
        std::cin >> A[i];

    for (int i = 0; i < m; i++)
    {
        std::cin >> l >> r;

        for (int j = l+1; j <= r; j++)
        {
            if (A[j] > A[l])
            {
                std::cout << A[j] << std::endl;
                break;
            }
            else if (A[j] < A[l])
            {
                std::cout << A[l] << std::endl;
                break;
            }

            if (j == r) std::cout << "NOT FOUND" << std::endl;
        }
    }

    return 0;
}