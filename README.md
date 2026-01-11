# C++ Port Scanner (Windows)

This is a small C++ command-line project I built to better understand how basic TCP networking
and port scanning work at a low level on Windows systems.

The tool attempts to connect to a list of ports on a given IP address and reports whether each
port is open or closed.

## Why I built this
As a computer science student interested in cybersecurity, I wanted a simple project to practice:
- socket programming
- TCP connections
- how port scanning tools work internally

Instead of using existing tools, I implemented a minimal scanner myself to focus on learning the core concepts.

## How it works
- Uses the Windows Winsock API
- Tries to establish a TCP connection to each specified port
- If the connection succeeds, the port is considered open
- If it fails or times out, the port is reported as closed

## Build (Windows – Visual Studio)
This project is intended to be built using Visual Studio on Windows.

Make sure the `ws2_32.lib` library is linked in the project settings.

## Run example
```bash
cpp-port-scanner.exe 127.0.0.1 22 80 443
```
## Example output:
```
Target: 127.0.0.1
22: closed
80: closed
443: closed
```
## What I learned

- Basic TCP socket programming using Winsock
- Handling command-line arguments in C++
- Understanding how port scanning works at a low level
- Linking system libraries in Visual Studio

## Limitations

- This scanner performs simple sequential TCP connection attempts
- No service detection or banner grabbing is implemented
- Designed for learning purposes, not as a full-featured scanner
