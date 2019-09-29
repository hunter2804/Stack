#ifndef __STACK_H__
#define __STACK_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define debug printf

#define Buffer 			packet.buffer
#define BufferLength 		packet.bufferLength
#define Top 				packet.top
#define isFullFlag			packet.isFull
#define isEmptyFlag		packet.isEmpty

class Stack{
	private:
		struct __attribute__((packed)) stack{
			uint8_t *buffer;
			uint32_t bufferLength;
			uint32_t top;
			bool isFull;
			bool isEmpty;
		}packet;
		
		bool Initialized;
		void flushBuffer(void);
	
	public:
		Stack(const uint32_t length);
		~Stack(void);
		
		bool write(const uint8_t data);
		bool write(const uint8_t* data, const uint32_t length);

		const uint8_t read(void);
		
		const uint32_t getAvailableSpace(void);
		bool remove(const uint32_t length=1);
};

#endif

