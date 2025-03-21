/*
 * CommonStructures.h
 *
 *  Created on: 19 march 2025
 *      Author: Richa Bhatia
 */

#ifndef COMMONSTRUCTURES_H_
#define COMMONSTRUCTURES_H_

#include "ConfigReader.h"
#include "json.hpp"

enum RequestPayloadFormat
{
	callType=1,
	resendSeq=2
};

class Packet
{
	public:
		string symbol;
		char buy_sell_indicator;
	    int32_t quantity;
	    int32_t price;
	    int32_t packet_seq;

		Packet(const char* data)
		{
			symbol = string(reinterpret_cast<const char*>(data), 4);
			buy_sell_indicator = data[4];
			quantity = ntohl(*reinterpret_cast<const int32_t*>(&data[5]));
			price = ntohl(*reinterpret_cast<const int32_t*>(&data[9]));
			packet_seq = ntohl(*reinterpret_cast<const int32_t*>(&data[13]));
		}

		void Print()
		{
			string side = (buy_sell_indicator == 'B') ? "Buy" : (buy_sell_indicator == 'S') ? "Sell" : "Unknown";
			cout << "Packet: Symbol = " << symbol << ", Side = " << side
				 << ", Quantity = " << quantity << ", Price = " << price
				 << ", Sequence = " << packet_seq << endl;
		}
};

class Request
{
	public:
		uint8_t call_type;
		uint8_t resend_seq;

		Request(uint8_t call_type_, uint8_t resend_seq = 0) : call_type(call_type_), resend_seq(resend_seq)
		{
//			cout << "InConstructor " << call_type << "," << call_type_ << endl;
		}

		//Convert the request into a binary payload
		void to_payload(uint8_t* payload)
		{
			payload[0] = call_type;
			payload[1] = resend_seq;
		}
};

#endif /* COMMONSTRUCTURES_H_ */
