// Simple interactive calculator
// g++ "01.project\calculator.cpp" -o "01.project\calculator.exe"
// Usage:
//  - Enter expressions like: 2 + 3
//  - Supported operators: +  -  *  /
//  - Enter `q` or `exit` to quit
// Compile (PowerShell):
//  g++ -std=c++17 -O2 -o calculator "01. project/calculator.cpp"

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

int main() {
	std::cout << "Simple Calculator (enter 'q' or 'exit' to quit)\n";
	std::string line;

	while (true) {
		std::cout << "calc> ";
		if (!std::getline(std::cin, line)) break; // EOF

		// Trim leading spaces
		size_t i = line.find_first_not_of(" \t\r\n");
		if (i == std::string::npos) continue; // empty line
		line = line.substr(i);

		if (line == "q" || line == "exit") break;

		std::istringstream ss(line);
		double a, b;
		char op;

		if (!(ss >> a)) {
			std::cout << "Invalid input. Example: 2 + 3\n";
			continue;
		}

		if (!(ss >> op)) {
			std::cout << "Missing operator. Use + - * /.\n";
			continue;
		}

		if (!(ss >> b)) {
			std::cout << "Missing second operand. Example: 4 * 5\n";
			continue;
		}

		double result;
		bool ok = true;

		switch (op) {
			case '+': result = a + b; break;
			case '-': result = a - b; break;
			case '*': result = a * b; break;
			case '/':
				if (b == 0.0) {
					std::cout << "Error: division by zero.\n";
					ok = false;
				} else {
					result = a / b;
				}
				break;
			default:
				std::cout << "Unsupported operator '" << op << "'. Use + - * /.\n";
				ok = false;
		}

		if (ok) {
			std::cout << a << " " << op << " " << b << " = " << result << "\n";
		}
	}

	std::cout << "Goodbye.\n";
	return 0;
}

