#ifndef __PARA_HASH_UTILS_HPP__
#define __PARA_HASH_UTILS_HPP__

#pragma once

#include <string>

namespace Para
{
	class HashUtils
	{
	public:
		static size_t hash(const std::string& string);
	};
}


#endif //__PARA_HASH_UTILS_HPP__
