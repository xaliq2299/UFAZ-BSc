#include <iostream>

using namespace std;

class C2DRectangle{
	CPos pos;
	int nColor;
	float fWidth, fHeight;
	public:
	C2DRectangle(float w, float h, int c, CPos p){
		fWidth=w; fHeight=h; nColor=c; pos=p;
	}	
}

int main()
{
	std::cout << "Hello World" << std::endl;
	return 0;
}
