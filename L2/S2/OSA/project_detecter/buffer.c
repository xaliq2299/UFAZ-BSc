#include "buffer.h"

Buffer get_buffer(){
	Buffer buf;
	buf.data=malloc(sizeof(1));
	buf.size=1;
	return buf;
}

int compare(Buffer *b1, Buffer *b2){
	if(b1->size != b2->size) return 1;
	else{
		for(int i=0;i<b1->size;i++){
			if(b1->data[i] != b2->data[i])
				return 1;
		}
	}
	return 0;
}

Buffer copy(Buffer *des, Buffer *src){
	des->data=NULL;
	des->data=malloc(sizeof(char)*src->size);
	for(int i=0;i<src->size;i++)
		des->data[i]=src->data[i];
	des->size=src->size;
	return *des;
}

void destruct_buffer(Buffer *buf){
	buf->data=NULL; buf->size=0;
}