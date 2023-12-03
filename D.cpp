// D. Анаграмма?

// Задано две строки, нужно проверить, является ли одна анаграммой другой. 
// Анаграммой называется строка, полученная из другой перестановкой букв.

#include <iostream>
#include <string>
#include <unordered_map>

int main() 
{
	  std::string a, b;
  	std::cin >> a;
  	std::cin >> b;

  	std::unordered_map<char, int> count;

  	for (int i = 0; i < a.size(); i++) 
    {
    	  count[a[i]]++;
    	  count[b[i]]--;
  	}

  	for (auto i : count) 
    {
    	  if (i.second != 0) 
        {
      		  std::cout << "NO";
      		  return 0;
    	  }
  	}
    
    std::cout << "YES";
    return 0;
}