
#include "ScalarConverter.hpp"

#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <cctype>
#include <cfloat>
#include <cstdlib>
#include <climits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void)&copy;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    (void)&copy;
    return *this;
}

static bool isChar(std::string literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return true;
    return false;
}

static bool isInt(std::string literal)
{
    for (unsigned long i = 0; i < literal.length(); i++)
    {
		if (i == 0 && literal[i] == '-')
			continue;
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

static bool isFloat(std::string literal)
{
    int dot = 0;
    int f = 0;
    for (unsigned int i = 0; i < literal.length(); i++)
    {
        if (literal[i] == '-')
            continue;
        if (literal[i] == '.')
            dot++;
        else if (literal[i] == 'f')
            f++;
        else if (!std::isdigit(literal[i]))
            return false;
    }
    if (dot == 1 && f == 1 && literal[literal.length() - 1] == 'f')
        return true;
    return false;
}

static bool isDouble(std::string literal)
{
    int dot = 0;
    for (unsigned int i = 0; i < literal.length(); i++)
    {
        if (literal[i] == '-')
            continue;
        if (literal[i] == '.')
            dot++;
        else if (!std::isdigit(literal[i]))
            return false;
    }
    if (dot == 1)
        return true;
    return false;
}

static char getType(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf")
		return 'n';
	if (literal == "-inf" || literal == "-inff")
		return '-';
	if (literal == "+inf" || literal == "+inff")
		return '+';
	if (isChar(literal))
		return 'c';
	if (isInt(literal))
		return 'i';
	if (isFloat(literal))
		return 'f';
	if (isDouble(literal))
		return 'd';
	else
		return '0';
}

static void convertChar(const std::string &literal)
{
    std::cout << "The input is a char" << std::endl;
    char c = literal[0];
    if (isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout <<"int: " << static_cast<int>(c) << std::endl;
    std::cout <<"float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout <<"double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void convertInt(const std::string &literal)
{
    std::cout << "The input is a int" << std::endl;
    try
    {
        long n = std::atol(literal.c_str());
        std::cout << "char: ";
        if (n >= 0 && n <= 127)
        {
            if (isprint(n))
                std::cout << static_cast<char>(n) << std::endl;
            else
                std::cout << "Non displayable" << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
        std::cout << "int: ";
        if (static_cast<long>(n) < INT_MIN || static_cast<long>(n) > INT_MAX)
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<int>(n) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
        std::cout <<"double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Invalid input" << std::endl;
        exit(1);
    }
}

static void convertFloat(const std::string &literal)
{
    std::cout << "The input is a float" << std::endl;
    try
    {
        float n = std::atof(literal.c_str());
        std::cout << "char: ";
        if (n >= 0 && n <= 127)
        {
            if (isprint(n))
                std::cout << static_cast<char>(n) << std::endl;
            else
                std::cout << "Non displayable" << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
        std::cout << "int: ";
        if (static_cast<long>(n) >= INT_MIN && static_cast<long>(n) <= INT_MAX)
            std::cout << static_cast<int>(n) << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "float: ";
        if (n >= -FLT_MAX && n <=FLT_MAX)
            std::cout << std::fixed << std::setprecision(1) << n << "f" << std::endl;
        else
         std::cout << "impossible" << std::endl;
        std::cout <<"double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Invalid input" << std::endl;
        exit(1);
    }
}

static void convertDouble(const std::string &literal)
{
    std::cout << "The input is a double" << std::endl;
    try
    {
        double n = std::atof(literal.c_str());
        std::cout << "char: ";
        if (n >= 0 && n <= 127)
        {
            if (isprint(n))
                std::cout << static_cast<char>(n) << std::endl;
            else
                std::cout << "Non displayable" << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
        std::cout << "int: ";
        if (n >= INT_MIN && n <= INT_MAX)
            std::cout << static_cast<int>(n) << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "float: ";
        if (n >= -FLT_MAX && n <=FLT_MAX)
            std::cout << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
        else
            std::cout << "impossible" << std::endl;

        std::cout <<"double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Invalid input" << std::endl;
        exit(1);
    }
}

static void convertNan()
{
    std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static void convertNegInf() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

static void convertInf() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    char type = getType(literal);
    switch (type)
    {
        case 'c':
            convertChar(literal);
            break;
        case 'i':
            convertInt(literal);
            break;
        case 'f':
            convertFloat(literal);
            break;
        case 'd':
            convertDouble(literal);
            break;
        case 'n':
            convertNan();
            break;
        case '+':
            convertInf();
            break;
        case '-':
            convertNegInf();
            break;
        default:
            std::cout << "Error: Invalid input" << std::endl;
            break;
    }
}
