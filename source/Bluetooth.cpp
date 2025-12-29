#include "../include/common.hpp"
#include "../include/Bluetooth.hpp"
#include "../include/MenuList.hpp"
void ONOFFBlueTooth(int &&on_off) {
  string command;
  int result;
  if (on_off == 1) {
    command = "sudo rfkill unblock bluetooth";
    result = system(command.c_str());
    if (result == 0) {
      cout << "BlueTooth Turned ON Succesfully" << endl << endl;
    } else {
      cerr << "Can't Turn BlueTooth ON , Check BlueTooth Adapter" << endl;
    }
  }
  if (on_off == 0) {
    command = "sudo rfkill block bluetooth";
    result = system(command.c_str());
    if (result == 0) {
      cout << "BlueTooth Turned OFF Succesfully" << endl << endl;
    } else {
      cerr << "Can't Turn BlueTooth OFF , Check BlueTooth Adapter" << endl;
    }
  }
}

int BlueFunc() {
  cout << "BlueTooth Control Program" << endl;
  cout << "---------------------------" << endl;
  cout << "1- Display BlueTooth Status" << endl;
  cout << "2- Turn BlueTooth ON" << endl;
  cout << "3- Turn BlueTooth OFF" << endl;
  cout << "4- Search And Connect To BlueTooth Device" << endl;
  cout << "5- Back To Main Menu" << endl;
  cout << "Choice : ";
  int choice;
  cin >> choice;
  return choice;
}
void BlueOptions(int var) {
  if (var > 5 || var < 0) {
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
      cin >> var;
      cout << endl;
      if (i == 1 && (var > 5 || var < 0)) {
        cout << "No Attempets Left" << endl;
      }
      if (var < 6 && var > 0) {
        InBlueOptions(var);
        break;
      }
    }
  } else {
    InBlueOptions(var);
  }
}
void InBlueOptions(int var) {
  switch (var) {
  case 1:
    cout << "Option 1 Checking BlueTooth Status" << endl << endl;
    BlueOptions(BlueFunc());
    break;
  case 2:
    cout << "Option 2 Turning ON BlueTooth" << endl << endl;
    ONOFFBlueTooth(1);
    BlueOptions(BlueFunc());
    break;
  case 3:
    cout << "Option 3 Turning OFF BlueTooth" << endl << endl;
    ONOFFBlueTooth(0);
    BlueOptions(BlueFunc());
    break;
  case 4:
    cout << "Option 4 Search or Connect To A BlueTooth Device" << endl << endl;
    BlueOptions(BlueFunc());
    break;
  case 5:
    cout << "Option 5 Back To Main Menu" << endl << endl;
    Options(Menu());
    break;
  default:
    cerr << "Unkown Failure Happened" << endl << endl;
    break;
  }
}
