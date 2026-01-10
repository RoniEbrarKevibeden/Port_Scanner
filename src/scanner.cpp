#pragma once
#include <string>

enum class PortStatus { Open, Closed, Error };

PortStatus check_port(const std::string& ip, int port, int timeout_ms);

