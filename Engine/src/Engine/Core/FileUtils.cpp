#include "Engine/Core/FileUtils.hpp"

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