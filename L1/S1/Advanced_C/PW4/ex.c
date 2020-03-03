#include <stdio.h>
#include <stdlib.h>

struct floatList{
	float val;
	struct floatList *next;
};

struct floatList* FL_new1(float x){
	struct floatList* f = malloc(sizeof(struct floatList));
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
	//for version
	int i=0;
	for(struct floatList *f=list;f != NULL;i++, f=f->next)
		printf("%d : %p%8.3f%10p\n", i, f, f->val, f->next);
	printf("%d elements in all\n", i);
	//while version
	/*struct floatList *f = list;
	while(f != NULL){
		printf("%p%8.3f%10p\n", f, f->val, f->next);
		f = f->next;
	}*/
}

struct floatList* FL_newEmpty(){
	struct floatList *f = NULL;
	return f;
}

int FL_isEmpty(struct floatList *list){
	if(list == NULL)
		return 1;
	else
		return 0;
}

struct floatList* FL_add(struct floatList *list, float val){
	struct floatList *new = malloc(sizeof(struct floatList));
	new->val = val;
	new->next = list;
	return new;
}

struct floatList* FL_firstInts(int n){
	struct floatList *intList = FL_newEmpty();
	for(int i=0;i<n;i++)
		intList = FL_add(intList, i);
	return intList;
}

struct floatList* FL_nth(struct floatList *list, int n){
	for(int i=0;i<n && list != NULL;i++)
		list = list->next;

	if(list == NULL)
		printf("There is no %dth number in the list.\n", n);

	return list;
}

struct floatList* FL_last(struct floatList *list){
	if(FL_isEmpty(list))
		printf("The list is empty.\n");
	else
		for(list;list->next != NULL;list=list->next);
	return list;
}

struct floatList* FL_removeFirst(struct floatList *list){
	if(FL_isEmpty(list))
		return list;
	return list->next;
}

struct floatList* FL_removeSecond(struct floatList *list){
	if(list == NULL || list->next == NULL)
		return list;
	list->next = list->next->next;	
	return list;
}

struct floatList* FL_insertAfterFirst(struct floatList *list, float val){
	if( FL_isEmpty(list) ){
		printf("The list is empty!!!\n");
		return list;
	}
	struct floatList *new = malloc(sizeof(struct floatList));
	new->next = list->next;
	list->next = new;
	new->val = val;
	return list;
}

struct floatList* FL_previous(struct floatList *list, struct floatList *el){
	if(list == el){
		printf("Given element is the first one in the list: "
			   "We don't have anything before it\n");
		return NULL;
	}
	for(list;list != NULL;list=list->next){
		if(list->next == el)
			return list;
	}
	printf("The given element is not in the list\n");
	return NULL;
}

struct floatList* FL_remove(struct floatList *list, struct floatList *el){
	if(el == list)	return list->next;
	
	struct floatList *cur;
	for(cur=list;cur->next != el;cur=cur->next);
	if(cur == NULL)		printf("Given element is not included in the list.\n");
	else 				cur->next = cur->next->next;

	return list;
}

struct floatList* FL_insertAfter(struct floatList *list, struct floatList *el, float val){
	struct floatList *cur;
	for(cur=list;cur != el;cur=cur->next);
	if(cur == NULL)
		printf("The given parameter doesn't belong to list.\n");
	else{
		struct floatList *new = malloc(sizeof(struct floatList));
		new->val = val;
		new->next = cur->next;
		cur->next = new;
	}
	return list;
}

struct floatList* FL_append(struct floatList *list, float val){
	struct floatList *cur;	
	struct floatList *new = malloc(sizeof(struct floatList));
	for(cur=list;cur->next != NULL;cur=cur->next);
	cur->next = new;
	new->next = NULL;
	new->val = val;
	return list;
}

struct floatList* FL_concat(struct floatList *l1, struct floatList *l2){
	struct floatList *last = FL_last(l1);
	last->next = l2;
	return l1;
}

int main(){
	//...		
	return 0;
}
