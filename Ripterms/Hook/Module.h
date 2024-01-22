#pragma once
#include <Windows.h>
#include <cstdint>
#include <vector>
#include <Psapi.h>

namespace Ripterms
{
	class Module
	{
	public:
		Module(const char* module_name);
		Module(HMODULE a_module);

		uint8_t* pattern_scan(uint8_t pattern[], int size, int access = PAGE_EXECUTE_READ) const;
		std::vector<uint8_t*> pattern_scan_all(uint8_t pattern[], int size, int access = PAGE_EXECUTE_READ) const;
		void* getProcAddress(const char* name);

		operator bool() const;

		static uint8_t* allocate_nearby_memory(uint8_t* nearby_addr, int size, int access = PAGE_EXECUTE_READWRITE);
	private:
		MODULEINFO moduleInfo{};
		HMODULE module = nullptr;
	};
}