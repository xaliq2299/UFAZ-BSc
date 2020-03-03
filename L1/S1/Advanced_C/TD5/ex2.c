1)
struct floatList{
	float val;
	struct floatList* next;
};

2)
struct charList{
	char val;
	struct charList* next;
};

3)
struct int5ArrayList{
	int array[5];
	struct int5ArrayList* next;
};

4)
struct intArrayList{
	int *array;
	struct intArrayList* next;
};

5)
struct color{
	unsigned char red, green, blue;
};

struct colorList{
	struct color c;
	struct colorList* next;
};
