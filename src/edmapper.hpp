#pragma once
#include <iostream>
#include <stdint.h>
#include <filesystem>
#include <memory>
#include "memory/memory_handlers.hpp"
#include "pe/portable_executable.hpp"
#include "hook/iat_hook.hpp"
#include "hook/shellcode.hpp"




namespace Edmapper {

	class dll_map
	{
		// private by default
		std::uint32_t process_id = 0;
		std::uint8_t* rawDll_data = nullptr;
		std::size_t rawDll_dataSize = 0;
		PIMAGE_NT_HEADERS pnt_headers = nullptr;
		PVOID m_image = nullptr;
		PVOID l_image = nullptr;
		PVOID pShellCode = nullptr;
	public:
		dll_map() = default;
		~dll_map();
		bool map_dll(const std::string_view proccess_name, const std::string_view dll_path,const std::string_view iat_functionName_to_hijack);
	};
}

