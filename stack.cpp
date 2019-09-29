#include "stack.h"

Stack::Stack(const uint32_t length){
	if(length<1) return;
	Buffer=(uint8_t*) malloc(length);
	BufferLength=length;
	flushBuffer();
	Initialized=true;
}

Stack::~Stack(void){
	flushBuffer();
	BufferLength=0;
	free(Buffer);
	Buffer=NULL;	//for avoid dangling pointer
}

void Stack::flushBuffer(void){
	if(Buffer==NULL || BufferLength<1) return;
	for(uint32_t i=0;i<BufferLength;i++){
		Buffer[i]=0;		
	}
	Top=0;
	isFullFlag=false;
	isEmptyFlag=true;
	Initialized=false;
}

bool Stack::write(const uint8_t data){
	if(isFullFlag || !Initialized) return false;
	Buffer[Top++]=data;
	if(Top==BufferLength) isFullFlag=true;
	isEmptyFlag=false;
	return true;
}

bool Stack::write(const uint8_t* data, const uint32_t length){
	if(getAvailableSpace()<length) return false;
	for(uint32_t i=0;i<length;i++){
		if(!write(data[i])){
			return false;
		}
	}
	return true;
}

const uint8_t Stack::read(void){
	if(isEmptyFlag)	return 0;
	Top--;
	if(Top==0) isEmptyFlag=true;
	return Buffer[Top];
}

const uint32_t Stack::getAvailableSpace(void){
	return (BufferLength-Top);
}

bool Stack::remove(uint32_t length){
	if(length>BufferLength) return false;
	for(uint32_t i=0;i<length;i++){
		read();
	}
	return true;
}

