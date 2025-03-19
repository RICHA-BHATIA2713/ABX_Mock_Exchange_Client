//============================================================================
// Name        : ABX_Mock_Exchange_Client.cpp
// Author      : Richa Bhatia
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "GlobalMembers.h"

int main() {

	InitializeGlobalMembers();

    if (!GetABXClient()->create_connection())
    {
        return EXIT_FAILURE;
    }

	return EXIT_SUCCESS;
}
