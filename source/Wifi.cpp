#include "../include/Wifi.hpp"
#include "../include/MenuList.hpp"
#include "../include/common.hpp"

void CheckStatusWIFI() { // check wifi status
  string Command = "nmcli -t -f ACTIVE,SSID dev wifi | grep yes";
  FILE *pipe = popen(Command.c_str(), "r");
  if (!pipe) {
    cerr << "Failed to Check Status" << endl;
    FuncDoing(DisplayOptions());
  }
  char buffer[64];
  while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
    cout << "Wifi status : " << buffer;
    cout << endl;
  }
  pclose(pipe);
}

void ModifyAll() { // change ssid and password
  cout << "Listing Saved Networks That Can Be Modified..." << endl;
  system("nmcli connection show");
  string WifiName;
  string NewSSID;
  string NewPassword;
  cout << "Enter The Wifi Name U Want To Modify : " << endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, WifiName);
  cout << "Enter The New SSID U Want : " << endl;
  getline(cin, NewSSID);
  cout << "Enter The New PassWord U Want : " << endl;
  cin >> NewPassword;
  string command1 = "nmcli connection modify \"" + WifiName +
                    "\" 802-11-wireless.ssid \"" + NewSSID + "\"";
  string command2 = "nmcli connection modify \"" + WifiName +
                    "\" wifi-sec.psk " + NewPassword;
  int result1 = system(command1.c_str());
  int result2 = system(command2.c_str());
  if (result1 == 0 && result2 == 0) {
    system("sudo systemctl restart wpa_supplicant");
    cout << "WiFi settings changed successfully." << endl;
  } else {
    cout << "Failed to change WiFi settings." << endl;
  }
}

void ModifySSID() { // change wifi ssid
  cout << "Listing Saved Networks That Can Be Modified..." << endl;
  system("nmcli connection show");
  string WifiName;
  string NewSSID;
  cout << "Enter The Wifi Name U Want To Modify : " << endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, WifiName);
  cout << "Enter The New SSID U Want : " << endl;
  getline(cin, NewSSID);
  string command = "nmcli connection modify \"" + WifiName +
                   "\" 802-11-wireless.ssid \"" + NewSSID + "\"";
  int result1 = system(command.c_str());
  if (result1 == 0) {
    system("sudo systemctl restart wpa_supplicant");
    cout << "WiFi SSID changed successfully." << endl;
  } else {
    cout << "Failed to change WiFi SSID." << endl;
  }
}

void ModifyPassWord() { // change wifi password
  cout << "Listing Saved Networks That Can Be Modified..." << endl;
  system("nmcli connection show");
  string WifiName;
  string NewPassword;
  cout << "Enter The Wifi Name U Want To Modify : " << endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, WifiName);
  cout << "Enter The New PassWord U Want : " << endl;
  cin >> NewPassword;
  string command = "nmcli connection modify \"" + WifiName +
                   "\" wifi-sec.psk " + NewPassword;
  int result = system(command.c_str());
  if (result == 0) {
    system("sudo systemctl restart wpa_supplicant");
    cout << "WiFi PassWord changed successfully." << endl;
  } else {
    cout << "Failed to change WiFi PassWord." << endl;
  }
}

void SearchWifi() { // search for available wifi
  cout << "Checking Available Networks Near" << endl;
  string command = "nmcli device wifi list";
  char buffer[256];
  FILE *pipe = popen(command.c_str(), "r");
  if (pipe) {
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
      cout << buffer;
    }
    cout << endl << "This are The available Networks Near" << endl;
    cout << "You Have 5 Seconds Then u Will be Back For Wifi Program" << endl;
    this_thread::sleep_for(chrono::seconds(5));
  } else {
    cerr << "Error Occured Make Sure That Wifi Is Opened" << endl;
    cout << "You Have 5 Seconds Then u Will be Back For Wifi Program" << endl;
    this_thread::sleep_for(chrono::seconds(5));
  }
}

void ConnectWifi() { // connect to wifi
  cout << "Checking Available Networks Near" << endl;
  string command = "nmcli device wifi list";
  FILE *pipe = popen(command.c_str(), "r");
  char buffer[256];
  if (!pipe) {
    cerr << "Error Scanning Available Networks" << endl;
  } else {
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
      cout << buffer;
    }
    fclose(pipe);
    string WifiName;
    string Pass;
    cout << "Enter Wifi Name : " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, WifiName);
    cout << "WARNING!! If Wifi Without Password Press AnyLetter." << endl;
    cout << "Enter Wifi Password : " << endl;
    getline(cin, Pass);
    cout << "Please wait a Second" << endl;
    string Command = "nmcli device wifi connect \"" + WifiName +
                     "\" password " + Pass + " > /dev/null 2>&1";
    int result = system(Command.c_str());
    if (result != 0) {
      cout << "Check Name And PassWord" << endl << endl;
      cerr << "Failed To Connect Wifi" << endl << endl;
    } else {
      system(Command.c_str());
      cout << "Connected To " << WifiName << " Succesfully" << endl << endl;
    }
  }
}

void DeleteFromList() { // delete saved wifi
  cout << "Saved Networks : " << endl;
  system("nmcli connection show");
  string DeleteNetwork;
  cout << "Which Network Want to Delete : " << endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, DeleteNetwork);
  cout << endl;
  string command = "nmcli connection delete \"" + DeleteNetwork + "\"";
  int result = system(command.c_str());
  if (result == 0) {
    std::cout << "Successfully deleted network: " << DeleteNetwork << std::endl;
  } else {
    std::cerr << "Failed to delete network: " << DeleteNetwork << std::endl;
  }
}

void ONOFFwifi(int &&x) { // turn on or off wifi
  int resultON = system("nmcli radio wifi on");
  int resultOFF = system("nmcli radio wifi off");
  if (x == 1) {
    if (resultON != 0) {
      cerr << "Failed to turn wifi on" << endl;
      cout << endl;
    } else {
      system("nmcli radio wifi on");
      cout << "Wifi turned on succesfully" << endl;
      cout << endl;
    }
  } else {
    if (resultOFF != 0) {
      cerr << "Failed to turn wifi off" << endl;
      cout << endl;
    } else {
      cout << "Wifi turned off succesfully" << endl;
      cout << endl;
    }
  }
}

int DisplayOptions() { // menu of wifi
  cout << "Wifi Control Program \n-----------------------" << endl;
  cout << "1- Display Wifi Status" << endl;
  cout << "2- Turn Wifi On" << endl;
  cout << "3- Turn Wifi Off" << endl;
  cout << "4- Connect to Wifi" << endl;
  cout << "5- Remove a Saved Network" << endl;
  cout << "6- Modify SSID Only" << endl;
  cout << "7- Modify Password Only" << endl;
  cout << "8- Search for a Network" << endl;
  cout << "9- Modify SSID and Password" << endl;
  cout << "10- Back To Main Menu" << endl;
  cout << "Choice: ";
  int Choice;
  cin >> Choice;
  cout << endl;
  return Choice;
}

void InFuncDoing(int x) { // after choice the functions
  switch (x) {
  case 1:
    cout << "Option 1 Checking wifi status" << endl;
    CheckStatusWIFI();
    FuncDoing(DisplayOptions());
    break;
  case 2:
    cout << "Option 2 Turning wifi on" << endl;
    ONOFFwifi(1);
    FuncDoing(DisplayOptions());
    break;
  case 3:
    cout << "Option 3 Turning wifi off" << endl;
    ONOFFwifi(0);
    FuncDoing(DisplayOptions());
    break;
  case 4:
    cout << "Option 4 Connecting to available Networks" << endl;
    ConnectWifi();
    FuncDoing(DisplayOptions());
    break;
  case 5:
    cout << "Option 5 Delete Saved Network" << endl << endl;
    DeleteFromList();
    FuncDoing(DisplayOptions());
    break;
  case 6:
    cout << "Option 6 Modify SSID only" << endl;
    ModifySSID();
    FuncDoing(DisplayOptions());
    break;
  case 7:
    cout << "Option 7 Modify PassWord only" << endl;
    ModifyPassWord();
    FuncDoing(DisplayOptions());
    break;
  case 8:
    cout << "Option 8 Searching For Near Wifi" << endl;
    SearchWifi();
    FuncDoing(DisplayOptions());
    break;
  case 9:
    cout << "Option 9 Modify SSID and PassWord" << endl << endl;
    ModifyAll();
    FuncDoing(DisplayOptions());
    break;
  case 10:
    cout << "Option 10 Back To Main Menu" << endl << endl;
    Options(Menu());
    break;
  default:
    cerr << "Unkown Failure Happened" << endl;
    break;
  }
}

void FuncDoing(int x) { // for wrong choices
  if (x > 10 || x < 0) {
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
      cout << endl;
      if (i == 1 && (x > 10 || x < 0)) {
        cout << "No Attempets Left" << endl;
      }
      if (x < 11 && x > 0) {
        InFuncDoing(x);
        break;
      }
    }
  } else {
    InFuncDoing(x);
  }
}
