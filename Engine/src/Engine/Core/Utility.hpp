#pragma once

#include <fstream>
#include <string>
#include <vector>

bool FileReadToString(std::string& outString, std::string const& fileName);
std::string const Stringf(char const* format, ...);
std::wstring const WStringf(wchar_t const* format, ...);