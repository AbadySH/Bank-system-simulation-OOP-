# 🏦 Bank system simulation (OOP) -  macOS Edition

<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?size=28&color=007ACC&width=1000&lines=macOS-Compatible+Bank+Simulation;Object-Oriented+Programming+in+C%2B%2B;Secure+Console+Application;Built+for+Learning;ProgrammingAdvices+Adaptation" alt="Typing Animation" />
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-Solutions-blue?style=for-the-badge&logo=c%2B%2B" alt="C++">
  <img src="https://img.shields.io/badge/Object--Oriented-Programming-green?style=for-the-badge" alt="OOP">
  <img src="https://img.shields.io/badge/Security-5--Layer%20Encryption-red?style=for-the-badge" alt="Security">
  <img src="https://img.shields.io/badge/Platform-macOS-orange?style=for-the-badge&logo=apple" alt="macOS">
  <img src="https://img.shields.io/badge/Compiler-Apple%20Clang-brightgreen?style=for-the-badge&logo=apple" alt="Apple Clang">
  <img src="https://img.shields.io/badge/GCC-Compatible-lightgrey?style=for-the-badge&logo=gnu" alt="GCC">
  <img src="https://img.shields.io/badge/Purpose-Educational%20Only-yellow?style=for-the-badge" alt="Educational">
</p>

---

## 📝 Introduction

<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?size=22&color=FF6600&width=800&lines=High-performance+Console-based+Bank+Management;Secure+and+Visual+OOP+System;Manage+Banking+Operations+Effortlessly;macOS-Compatible+Version;Simulation+for+Learning+Purposes" alt="Typing Animation" />
</p>

A high-performance **Console-based Bank system simulation ** built with **C++**. This project focuses on **Object-Oriented Programming (OOP)** principles, providing a secure and visually intuitive way to manage banking operations, currency exchange, and user activities.

> ⚠️ **Important Notice:** This project is a **simulation ** built **strictly for educational purposes** . It is not intended for real-world banking, financial transactions, or production environments.

---

## 🍏 Why This macOS Version Exists

This is a **macOS-compatible version** of the original project from **ProgrammingAdvices**.

### Why this version exists
The original library relies on Microsoft's proprietary feature:

```cpp

__declspec(property)

which is supported by Microsoft Visual Studio but is not supported by Apple Clang or GCC. Because of this, the original code cannot be compiled on macOS without modifications.
Changes Made

    ✅ Removed all usages of __declspec(property).

    ✅ Replaced Visual Studio–specific constructs with Standard C++.

    ✅ Preserved the original function names and behavior as much as possible.

    ✅ Fixed several issues discovered during the migration process.

    ✅ Tested with Apple Clang on macOS.

    ✅ Adjusted file paths to work with macOS directory structures.

Compatibility
Compiler / Platform	Supported
Apple Clang (macOS)	✅ Fully Supported
GCC (Linux)	✅ Fully Supported
Clang	✅ Fully Supported
Microsoft Visual Studio	⚠️ Not Tested
📁 Data Files (File Handling)

The system uses external .txt files for persistent data storage. Make sure these files exist in the directory specified in the code (or update the paths):
File Name	Purpose
ClientFile.txt	Stores encrypted client account information (CRUD operations).
Users.txt	Stores encrypted system user credentials and permissions.
LoginRecord.text	Stores the login history of all users (Audit Trail).
TransferRecord.text	Stores detailed transfer logs (Source, Destination, Amount, etc.).

    ⚠️ Important: The code contains absolute file paths (e.g., /Users/.../Desktop/...). You must update these paths in clsBanckClient.h, clsUser.h, and clsCurrency.h to match your local directory structure before compiling and running.

🚀 Main Features
🔐 1. Authentication & Access
<p align="center"> <img src="https://readme-typing-svg.herokuapp.com?size=20&color=00BFFF&width=800&lines=Secure+Login+System;Dynamic+Permissions;Login+Tracking;Multi-Level+Security" alt="Typing Animation" /> </p>

    Secure Login System: The gateway to the system with credential verification.

    Dynamic Permissions: Each user has specific access rights (Admin/User). Permissions are bitwise (1, 2, 4, 8, etc.).

    Login Tracking: Every successful login attempt is recorded with timestamps and stored in LoginRecord.text.

👥 2. Client & User Management
<p align="center"> <img src="https://readme-typing-svg.herokuapp.com?size=20&color=00FF7F&width=800&lines=Full+CRUD+Operations;Encrypted+Storage;Permissions+Display;User+Management+Tools" alt="Typing Animation" /> </p>

    Client Operations: Full CRUD (Add, Delete, Update, Find) with encrypted storage.

    User Operations: Complete management of system users and their security levels.

    Permissions Display: A dedicated screen to view user access rights.

💰 3. Banking & Transactions
<p align="center"> <img src="https://readme-typing-svg.herokuapp.com?size=20&color=FFD700&width=800&lines=Balance+Management;Secure+Money+Transfer;Transfer+Logs;Audit+Trail+Included" alt="Typing Animation" /> </p>

    Balance Management: Deposit, Withdraw, and Total Balances.

    Transfer System: Secure money transfer between accounts with real-time validation and balance checks.

    Quick & Normal Withdraw: Supports both standard and quick withdrawal methods.

🌍 4. Currency Exchange System
<p align="center"> <img src="https://readme-typing-svg.herokuapp.com?size=20&color=FF4500&width=800&lines=Live-Style+Rates;Currency+Finder;Currency+Calculator;Real-Time+Conversions" alt="Typing Animation" /> </p>

    Live-Style Rates: View currency rates relative to the USD.

    Currency Finder: Search for any currency by code or country.

    Currency Calculator: Perform instant conversions between different global currencies.

🛡️ 5. Security & Logs (Audit Trail)
<p align="center"> <img src="https://readme-typing-svg.herokuapp.com?size=20&color=8A2BE2&width=800&lines=User+Move+Tracking;Logs+Viewer;Security+Refresh;Re-Encryption+Tool" alt="Typing Animation" /> </p>

    User Move Tracking: The system records every single action by the user (Login, Edits, Views).

    Logs Viewer: A clean, formatted table for admins to review all system activities (Login Logs & Transfer Logs).

🏗️ Organized Code Structure (Layered Architecture)
<p align="center"> <img src="https://readme-typing-svg.herokuapp.com?size=20&color=FFA500&width=800&lines=Layered+Architecture;Screen+Inheritance;Robust+Input+Validation" alt="Typing Animation" /> </p>

    Layered Architecture (Core, Screens, Libs): Clear separation of concerns for maintainability.

    Screen Inheritance for UI Consistency: All screens inherit from a base clsScreen class for uniform behavior.

    Robust Input Validation System: Prevents invalid data entry using the clsInputValidate class.

💰 Financial & Banking Operations

    Quick & Normal Withdraw Logic: Prevents overdrafts with clear error messages.

    Deposit System with Instant Balance Update: Immediately reflects deposited amounts.

    Professional Formatted Tables: All data is displayed in clean, colored, and well-structured tables.

🧾 Automatic Receipts System

    Automatic Receipts Generation: Every successful transaction generates a detailed receipt concept.

    External File Storage (File Handling): Uses .txt files for all persistent storage.

    Detailed Transaction Logging: Every financial move is logged with timestamps and amounts.

🎨 User Interface
<p align="center"> <img src="https://readme-typing-svg.herokuapp.com?size=20&color=00CED1&width=800&lines=Colorful+Terminal+UI;Smooth+Navigation;User-Friendly+Interaction" alt="Typing Animation" /> </p>

    Full Color Support: A professional color-coded terminal experience.

    Modular Menus: Intuitive navigation through nested, organized screens.

    Formatted Tables: Data is displayed in neat, structured, and colored tables.

🔐 Encryption Engine (5-Layers)

The system protects sensitive data using a custom-built cryptographic logic:

    XOR Cipher (Initial encryption)

    Random Padding (Noise injection)

    Case Inversion (Casing flip)

    Nested XOR (Double security)

    Hexadecimal (Final storage format)

📂 Project Structure
text

For Practsing/
├── core/                         # Core Business Logic
│   ├── clsBanckClient.h          # Bank Client CRUD & Transactions
│   ├── clsUser.h                 # User Authentication & Permissions
│   ├── clsCurrency.h             # Currency Exchange Logic
│   └── clsPerson.h               # Base Person Class (Inheritance)
│
├── Lib/                          # Utility Libraries
│   ├── clsDate.h                 # Date/Time manipulation
│   ├── clsString.h               # String utilities & formatting
│   ├── clsUtil.h                 # Encryption, Random, & Helpers
│   └── clsInputValidate.h        # Input validation
│
├── Screens/                      # UI Screens (Inheritance)
│   ├── Client/                   # Client management screens
│   ├── User/                     # User management & Login screens
│   └── Currenncies/              # Currency exchange screens
│
├── clsMainScreen.h               # Main Menu
├── clsScreen.h                   # Base Screen (Header, Permissions)
├── Global.h                      # Global Current User object
└── main.cpp                      # Entry point

🚀 Skills Applied  

    ✅ OOP Principles: (Inheritance, Encapsulation, Polymorphism, Abstraction)

    ✅ Software Design: (Modular Design, Layered Architecture & Clean Code)

    ✅ Data Persistence: (Advanced File Handling with external .txt storage)

    ✅ Security Implementation: (Custom 5-layer encryption)

    ✅ UI/UX Design: (Colored terminal outputs and formatted tables)

    (This journey taught me that programming isn't just about working code; programming is about building a correct, scalable system from the ground up.)

👨‍💻 Original Author & Credits

Original Library & Course Materials by:
Mohammed Abu-Hadhoud (ProgrammingAdvices)

This repository contains a portability adaptation for Standard C++ environments (specifically macOS and Linux). The core functionality and API of the original library have been kept intact whenever possible to allow students using macOS to follow the course materials without requiring Visual Studio or Windows-specific language extensions.
📌 How to Run

    Clone the repository.

    Update file paths: Open clsBanckClient.h, clsUser.h, and clsCurrency.h and change the static const string paths to your local directory.

    Compile using any C++17 compliant compiler (Apple Clang or GCC):
    bash

    g++ -std=c++17 main.cpp -o BankSystem

    Run the executable:
    bash

    ./BankSystem

    Default login credentials (if you haven't changed the files) are stored in Users.txt. You may need to create the first admin user manually in the file or through the system's initial setup.

📄 License

This project is for educational purposes only. All rights belong to the original author, Mohammed Abu-Hadhoud (ProgrammingAdvices).
