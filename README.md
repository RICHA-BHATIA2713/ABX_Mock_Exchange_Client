# ABX Mock Exchange Client

This project simulates a client interacting with an ABX mock exchange server. It requests and handles packets from the order book and simulates stock exchange data.

### Dependencies

- **C++17** support in your compiler (e.g., GCC)
- **Eclipse** IDE is used. The exe is in `ABX_Mock_Exchange_Client/Debug`
- **Compilation Tools**: `g++` C++ compiler or `Eclipse IDE`

### Setup and Building the Project

Follow these steps to manually compile and run the project:

#### 1. Instructions to execute ABX Application Client

Clone this repository to your local machine using `git`:

```bash
git clone https://github.com/RICHA-BHATIA2713/ABX_Mock_Exchange_Client.git
cd ABX_Mock_Exchange_Client/Deubg
make clean
make -k all
./Start_ABX_Client.sh
```

#### Key Points:
1. **Configuration File**:
   - Describes the **ABX Client Application configuration file** and the various fields that can be customized.
   - A sample configuration file (`Debug/ABX_Client_Config.cfg`) is included.
    Sample Configuration File details:
```bash
      SERVER_IP=127.0.0.1  //server IP where ABX server running
      SERVER_PORT=3000  //server port where ABX server running
      JSON_FILENAME=packet.json //JSON output of packets
```

2. **Output File**:
   - Explains what the program will output, specifically the **JSON output file** (`packet.json`).
   - Exe normal output present in `out` and `err` file.
