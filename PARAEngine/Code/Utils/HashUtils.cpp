#include "HashUtils.hpp"

using namespace Para;

size_t HashUtils::hash(const std::string& string)
{
	std::hash<std::string> hasher;
	return hasher(string);
}
