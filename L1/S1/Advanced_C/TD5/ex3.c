#include <stdio.h>
#include <stdlib.h>

struct floatList{
	float val;
	struct floatList *next;
};

struct floatList* FL_new1(float x){
	struct floatList* f = (struct floatList*)malloc(sizeof(struct floatList));
	if(f == NULL)
		printf("Malloc failed.\n");
	else{
		f->val = x;
		f->next = NULL;
	}
	return f;
}

void FL_show1(struct floatList *f, char *label){
	printf("%s: %p %f %p\n", label, f, f->val, f->next);
}

void FL_show(struct floatList *list, char *label){
	printf("--------- Show floatList : %s ---------\n", label);
	//while version
	struct floatList *f = list;
	while(f != NULL){
		printf("%p%8.3f%10p\n", f, f->val, f->next);
		f = f->next;
	}
	//for version
	//for(struct floatList *f=list;f != NULL;f=f->next)
		//printf("%p%8.3f%10p\n", f, f->val, f->next);
}

int main(){
	struct floatList *f1, *f2, *f3;
	f1 = FL_new1(5);
	f2 = FL_new1(10);
	f3 = FL_new1(3);
	
	f1->next = f2;
	f2->next = f3;
	
	FL_show1(f1,"first");
	FL_show1(f2,"second");
	FL_show1(f3,"third");
	
	FL_show(f1, "first list");

	return 0;
}
