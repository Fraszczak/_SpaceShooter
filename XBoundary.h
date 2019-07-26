#pragma once
#include <iostream>
class XBoundary
{
public:
	 XBoundary(std::string ex) { this->ex = ex; std::cout << ex << std::endl; };
	~XBoundary() {};

public:
	std::string getException() { return  "Error message: " + ex; }

private:
    std::string ex;
};

