// G. Кролик учит геометрию

// Кролики очень любопытны. Они любят изучать геометрию, бегая по грядкам. 
// Наш кролик как раз такой. Сегодня он решил изучить новую фигуру — квадрат.
// Кролик бегает по грядке — клеточному полю N × M клеток. В некоторых из них 
// посеяны морковки, в некоторых нет. Помогите кролику найти сторону квадрата 
// наибольшей площади, заполненного морковками полностью.

#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    int n, m;
    std::vector<std::vector<int>> A;

    std::cin >> n >> m;
    A.resize(n);
    for (int i = 0; i < n; i++)
        A[i].resize(m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> A[i][j];

    int side = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i * j == 0)
                continue;

            if (A[i][j] == 1)
                A[i][j] = std::min({A[i][j-1], A[i-1][j], A[i-1][j-1]}) + 1;
            
            if (A[i][j] > side)
                side = A[i][j];
        }

    std::cout << side;
    return 0;
}