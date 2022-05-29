#include "Engine/Core/Utility.hpp"
#include <stdarg.h>

bool FileReadToString(std::string& outString, std::string const& fileName)
{
	std::ifstream is(fileName.c_str(), std::ios::in | std::ios::binary);

	if (!is)
	{
		return false;
	}

	outString = std::string((std::istreambuf_iterator<char>(is)), std::istreambuf_iterator<char>());
	is.close();
	return true;
}


constexpr int STRING_STACK_LOCAL_LENGTH = 2048;

std::string const Stringf(char const* format, ...)
{
	char textLiteral[STRING_STACK_LOCAL_LENGTH];

	va_list variableArgumentList;
	va_start(variableArgumentList, format);
	vsnprintf_s(textLiteral, STRING_STACK_LOCAL_LENGTH, _TRUNCATE, format, variableArgumentList);
	va_end(variableArgumentList);
	textLiteral[STRING_STACK_LOCAL_LENGTH - 1] = '\0'; // In case vsnprintf overran (doesn't auto-terminate)

	return std::string(textLiteral);
}

std::wstring const WStringf(wchar_t const* format, ...)
{
	wchar_t textLiteral[STRING_STACK_LOCAL_LENGTH];

	va_list variableArgumentList;
	va_start(variableArgumentList, format);
	_vsnwprintf_s(textLiteral, STRING_STACK_LOCAL_LENGTH, _TRUNCATE, format, variableArgumentList);
	va_end(variableArgumentList);
	textLiteral[STRING_STACK_LOCAL_LENGTH - 1] = '\0'; // In case vsnprintf overran (doesn't auto-terminate)

	return std::wstring(textLiteral);
}
