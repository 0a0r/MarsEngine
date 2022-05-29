#include "Engine/Core/StringUtils.hpp"
#include <stdarg.h>

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
