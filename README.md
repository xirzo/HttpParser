# 🚀 HTTP Parser

## 🚧 Project Status

> **Currently Under Development** - Core functionality is being implemented

HTTP Parser is a C library made to parse HTTP requests. It was originally created to support [C-Website](https://github.com/xirzo/C-Website), a web server implementation written in C programming language. For recreational purposes only :).

## ✨ Current Features

- 🔹 HTTP request status line parsing
- 🔹 Support for standard HTTP methods (GET, POST, PUT, DELETE, etc.)
- 🔹 HTTP version detection (HTTP/0.9 through HTTP/3)

## 🔮 Roadmap

Enhancements planned for this library:

- 📋 Complete HTTP header parsing
- 📦 HTTP request body handling

## 📥 Installation Guide

To build and install the HTTP Parser library, follow these steps:

### Prerequisites

- **CMake** (version 3.31.4 or higher)
- **C Compiler** (e.g., `gcc`, `clang`)
- **Make**

### Step 1: Clone the Repository

Clone the repository to your local machine:

```bash
git clone https://github.com/your-username/http-parser.git
cd http-parser
```

### Step 2: Configure the Project with CMake

Create a build directory and configure the project:

```bash
mkdir build
cd build
cmake ..
```

This will generate the necessary build files.

### Step 3: Build the Project

Compile the project using `make`:

```bash
make
```

This will build the library and any associated binaries or tests.

### Step 4: Install the Library (Optional)

To install the library system-wide, run:

```bash
sudo make install
```

---

## 🔧 Usage

```c
#include "http_parser.h"

void example() {
    char request[] = "GET /index.html HTTP/1.1\r\n"; 
    HttpRequest *req;
    init_http_request(&req);
    
    parse_request_line(req, request);
    
    // Future versions will support full request parsing
    // req = parse_http_request(request);
    
    free_http_request(req);
}
```

## 🔗 Related Projects

- [C-Website](https://github.com/xirzo/C-Website) - A web server written entirely in C
