#include <iostream>

int main()
{
  int arr[10], beg = 0, end = 10, num, pos;

  for (size_t i = 0; (pos = i++) < 10; arr[pos] = num)
    for (std::cin >> num; pos > 0 && num < arr[pos - 1]; --pos)
      arr[pos] = arr[pos - 1];
  std::cin >> num;

  while (beg < end)
  {
    pos = beg + end >> 1;
    if (num == arr[pos])
    {
      std::cout << pos;
      return 0;
    }
    else if (num < arr[pos])
      end = pos;
    else
      beg = pos + 1;
  }

  std::cout << -1;

  return 0;
}