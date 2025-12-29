# Linux Network & Bluetooth Manager 📡

A robust **C++ CLI (Command Line Interface)** tool designed to manage wireless connectivity on Linux systems. This project interacts directly with the Linux kernel's networking stack using system calls (`nmcli` and `rfkill`) to control Wifi and Bluetooth interfaces programmatically.

## 🚀 Features

### 📶 Wifi Control
- **Status Monitoring:** Real-time check of Wifi adapter status.
- **Power Management:** Toggle Wifi radio ON/OFF.
- **Connection Manager:** Scan and connect to available networks securely.
- **Network Administration:** - Delete saved networks.
  - Modify SSID and Passwords for existing connections.
  - Search for nearby networks with signal strength.

### 🔵 Bluetooth Control
- **Power Management:** Enable/Disable Bluetooth adapter via `rfkill`.
- **Status Check:** Monitor Bluetooth visibility and status.

### 🛠️ Technical Highlights
- **Modular Architecture:** Source code separated into `header` and `source` files for better maintainability.
- **System Integration:** Uses `popen()` and `system()` to interface with Linux network daemons.
- **Security:** Requires `sudo` privileges for hardware control operations.

---

## ⚙️ Requirements
- **OS:** Linux (Ubuntu/Debian based distributions recommended).
- **Compiler:** `g++` (GCC).
- **Dependencies:** `network-manager` package (pre-installed on most distros).

---

## 🔨 How to Build & Run

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/mohamedelbagoury701/Linux-Network-Manager.git](https://github.com/mohamedelbagoury701/Linux-Network-Manager.git)
   cd Linux-Network-Manager
