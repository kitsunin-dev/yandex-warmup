// F. Лифт

// Тридцатого декабря все сотрудники известной IT-компании отправляются 
// праздновать Новый год! На парковке офиса сотрудников уже ожидают автобусы, 
// чтобы отвезти их в ресторан. Известно, что на i-м этаже работает a_i
// сотрудников, а парковка расположена на нулевом этаже. Изначально лифт 
// расположен на этаже с парковкой. Какое минимальное количество времени лифт 
// будет перевозить всех людей на парковку? Известно, что лифт движется со 
// скоростью один этаж в секунду, а посадка и высадка происходит мгновенно.

#include <iostream>
#include <vector>

int main() 
{
    unsigned long long int k, n;
    std::vector<unsigned long long int> A;

    std::cin >> k >> n;
    A.resize(n);

    for (int i = 0; i < n; i++)
        std::cin >> A[i];

    unsigned long long int res = 0, reserve = 0;

    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] != 0)
        {
            if (A[i] <= reserve)
            {
                reserve -= A[i];
                A[i] = 0;
            }
            else
            {
                A[i] -= reserve;
                reserve = 0;
            }
        }

        if (A[i] % k == 0)
            res += (i+1)*2*(A[i]/k);
        else
        {
            reserve = k - A[i] % k;
            res += (i+1)*2*(A[i]/k+1);
        }
    }

    std::cout << res;
    return 0;
}