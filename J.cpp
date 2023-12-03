// J. Групповой проект

// Всего студентов по направлению «Мировая культура» — n человек. Преподаватель 
// дал задание — групповой проект. Для выполнения этого задания студенты должны 
// разбиться на группы численностью от a до b человек. Скажите, можно ли 
// разбить всех студентов на группы для выполнения проекта или преподаватель 
// что-то перепутал.

#include <iostream>

int main()
{
    int t, n, a, b;
    bool flag;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        flag = false;
        std::cin >> n >> a >> b;
        int kmin = n / b, kmax = n / a;

        for (int k = kmin; k <= kmax; k++)
            if ((n >= a * k && n <= b * k))
            {
                std::cout << "YES" << std::endl;
                flag = true;
                break;
            }

        if (flag == false) std::cout << "NO" << std::endl;
    }

    return 0;
}