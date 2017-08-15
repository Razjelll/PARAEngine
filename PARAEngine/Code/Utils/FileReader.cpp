#include "FileReader.hpp"
#include <fstream>

const std::string CARRIAGE_RETURN = "\r\n";

FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}

std::string FileReader::read(const std::string& path)
{
	std::ifstream fileStream;
	fileStream.open(path.c_str(), std::ios::in);
	if (fileStream)
	{
		std::string line;
		std::string buffer;
		while (std::getline(fileStream, line))
		{
			buffer.append(line);
			buffer.append(CARRIAGE_RETURN);
		}
		return buffer;
	}
	return NULL;
}

void FileReader::read(const std::string& path, std::string& buffer)
{
	std::ifstream fileStream;
	fileStream.open(path.c_str(), std::ios::in);
	if (fileStream)
	{
		std::string line;
		while (std::getline(fileStream, line))
		{
			buffer.append(line);
			buffer.append(CARRIAGE_RETURN);
		}
	}
}
