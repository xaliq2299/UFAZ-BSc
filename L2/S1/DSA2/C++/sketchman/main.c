#include <stdio.h>
#define PI 3.1415

typedef struct Position{
	int x,y;
}SPos;

typedef struct Color{
	int r,g,b;
}SColor;

typedef struct Rectangle{
	SPos pos;
	int nColor;
	float fWidth, fLength;
}SRectangle;

typedef struct Circle{
	SPos pos;
	int nColor;
	float fRadius;
}SCirlce;

typedef struct Triangle{
	SPos pos;
	int nColor;
	float fSide;
}STriangle;

typedef struct SketchMan{
	SRectangle arm[2], leg[2], torso;
	SCircle head;
	STriangle hat;
}SSketchman;

float areaRectangle(SRectangle r){
	return r.fWidth*r.fLength;
}

float areaCircle(SCircle c){
	return PI*c.fRadius*c.fRadius;
}

float areaTriangle(STriangle t){
	return t.fSide*t.fSide*sqrt(3)/4;
}

float area(SSketchMan sketchman){
	return areaRectangle(sketchman.arm)*2+
		   areaRectangle(sketchman.leg)*2+
		   areaRectangle(sketchman.torso)+
		   areaCircle(sketchman.head)+
		   areaTriangle(sketchman.hat);
}

int main(){
	SSketchman Ibrahim;
}