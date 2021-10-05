#ifndef CLIENT_MEM_MEM
#define CLIENT_MEM_MEM

#include <Windows.h>
#include <Psapi.h>
#include <vector>
#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>

#define INRANGE(x,a,b)   (x >= a && x <= b)
#define GET_BYTE( x )    (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))
#define GET_BITS( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))

class Mem {
public:
    static uintptr_t findSig(const char*);
    static uintptr_t findMultiLvlPtr(uintptr_t, std::vector<unsigned int>);
    static void DebugPrint(const char*);
};

#endif /* CLIENT_MEM_MEM */