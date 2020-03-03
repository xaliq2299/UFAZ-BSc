#include "bit.h"

void bb_init(BIT_BUFFER *buff, FILE *fp){
	buff->f = fp;
	buff->pos=0;
	buff->bits=0;
}

void bb_print(BIT_BUFFER *buff){
	//IF WE HAVE number of bits < 8
//	while(buff->pos < 8){
//		buff->bits &= ~(1 << 8-buff->pos-1);
//		(buff->pos)++;
//	}
	//WHEN ALL BITS are filled with 8 bits
	fwrite(&(buff->bits),sizeof(char),1,buff->f);
	buff->pos = 0;
	buff->bits = 0;
}

void bb_fill(BIT_BUFFER *buff, int s, int *bitsTab){
	int i,shift_pos;
	for(i=0;i<s;i++){
		if(buff->pos == 8)	bb_print(buff);
		shift_pos=8-buff->pos-1;
		if(bitsTab[i] == 1)		buff->bits = buff->bits | (1 << shift_pos);
		else					buff->bits = buff->bits & ~(1 << shift_pos);
		buff->pos++;
	}
}
