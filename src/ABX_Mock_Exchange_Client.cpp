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


    //1. Request All Feed Packets.
    Request all_packet_request((int)RequestPayloadFormat::callType);
	if (GetABXClient()->send_request(all_packet_request))
	{
		cout << "Send Request done: type " << (int)RequestPayloadFormat::callType << endl;
		int recv_bytes = INT_MAX;
		while(recv_bytes > 0)
		{
			recv_bytes = GetABXClient()->handle_response(GetSeqVector());
		}
	}
	else
	{
		cerr << "Send Request Not done: type " << (int)RequestPayloadFormat::callType << endl;
	}


    DestroyGlobalMembers();

	return EXIT_SUCCESS;
}
