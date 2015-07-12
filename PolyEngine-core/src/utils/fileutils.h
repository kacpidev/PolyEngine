#ifndef __FILE_UTILS_H__
#define __FILE_UTILS_H__
#include <fstream>

namespace PE
{
	namespace FileUtils
	{
		inline std::string readFile(const char* filePath)
		{
			auto file = fopen(filePath, "rt");
			fseek(file, 0, SEEK_END);
			auto length = ftell(file);

			auto data = new char[length + 1];
			memset(data, 0, length + 1);
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);

			std::string result(data);
			delete[] data;
			return result;
		}

	}
}


#endif