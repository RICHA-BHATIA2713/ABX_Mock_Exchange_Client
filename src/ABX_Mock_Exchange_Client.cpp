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

	PrintSeqVector();

	//Connection closed create connection again
    if (!GetABXClient()->create_connection())
    {
        return EXIT_FAILURE;
    }

    //2. Request Missing Sequence Packets.
    int seq_counter = 1, idx_counter = 0, last_counter = GetSeqVector().back();
    while(idx_counter < GetSeqVector().size() && seq_counter<last_counter)
    {
    	if(GetSeqVector()[idx_counter] == seq_counter) {
    		idx_counter++;
    		seq_counter++;
    	}
    	else if(GetSeqVector()[idx_counter] > seq_counter) {
    		Request resend_request((int)RequestPayloadFormat::resendSeq, seq_counter);
    		if (GetABXClient()->send_request(resend_request))
    		{
    			cout << "Send Request done: type " << (int)RequestPayloadFormat::resendSeq << endl;
    			GetABXClient()->handle_response(GetSeqVector());
    		}
    		else
    		{
    			cerr << "Send Request Not done: type " << (int)RequestPayloadFormat::resendSeq << endl;
    			return EXIT_FAILURE;
    		}
    		seq_counter++;
    	}
    }

    DestroyGlobalMembers();

	return EXIT_SUCCESS;
}
