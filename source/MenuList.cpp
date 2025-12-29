#include "../include/common.hpp"
#include "../include/Bluetooth.hpp"
#include "../include/Wifi.hpp"
int Menu() {
  map<int, string> QMap;

  QMap[1] = "Wifi Control";

  QMap.insert({2, "Bluetooth Control"});

  QMap[3] = "Exit Program";

  cout << "Program Options :" << endl;

  for (auto &pair : QMap) {
    cout << pair.first << "-" << pair.second << endl;
  }
  cout << "Enter Choice : ";
  int Choice;
  cin >> Choice;
  cout << endl;
  return Choice;
}
void InOptions(int x) {
  switch (x) {
  case 1:
    cout << endl;
    FuncDoing(DisplayOptions());
    break;
  case 2:
    cout << endl;
    BlueOptions(BlueFunc());
    break;
  case 3:
    cout << "Closing Program" << endl;
    break;
  default:
    cout << "Unkown Result " << endl;
    cout << "-------------" << endl;
    break;
  }
}
void Options(int x) {
  if (x > 3 || x < 0) {
    for (int i = 3; i > 0; i--) {
      cout << "Undefined Input " << endl;
      cout << "-------------" << endl;
      if (i != 1) {
        cout << "You Have " << i << " Attempets Only" << endl;
        cout << "New Choice : ";
      } else {
        cout << "You Have " << i << " Attempet Only" << endl;
        cout << "Last Choice : ";
      }

      cin >> x;
      if (i == 1 && x > 3 && x < 0) {
        cout << "No Attempets Left" << endl;
      }
      if (x < 4 && x > 0) {
        InOptions(x);
        break;
      }
    }
  } else {
    InOptions(x);
  }
}