#ifndef __PARA_FILE_READER_HPP__
#define __PARA_FILE_READER_HPP__
#pragma once

#include <string>

class FileReader
{
public:
	std::string read(const std::string& path);
	static void read(const std::string& path, std::string& buffer);
	FileReader();
	~FileReader();

	
};

#endif //__PARA_FILE_READER_HPP__