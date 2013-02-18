#include <iostream>

using namespace std;
int main()
{
    cout << "How much are tickects?\n";
    int amount = 0;
    cin >> amount; //количество всех билетов
    int count = 0;
    for (int i = 0;i < amount;++i)
    {
      long tick = 0;
      cin >> tick;
      int lSumm = 0;
      int rSumm = 0;
      lSumm = tick / 100000 + (tick / 10000) % 10 + (tick / 1000) % 10;
      rSumm = (tick % 1000) / 100 + (tick % 100) / 10 + tick % 10;
      if (lSumm == rSumm)
      {
        ++count;
      }
    }
    cout << count;
    return 0;
}
