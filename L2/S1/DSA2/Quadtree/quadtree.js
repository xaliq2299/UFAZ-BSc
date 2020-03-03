class Point{
	constructor(x,y){
		this.x=x;
		this.y=y;
	}
}

class Rectangle(){
	constructor(x,y,w,h){
		this.x=x;
		this.y=y;
		this.w=w;
		this.h=h;
	}
	show(){
		stroke(0);
		strokeHeight(1);
		noFill();
		rectMode(CENTER);
		rect(this.x,this.y,this.w*2.this.h*2);
	}
}

class Quadtree(){
	constructor(bound,n){
		this.boundary=bound;
		this.capacity=n;
		this.points=[];
	}
	divide(){
		x=this.boundary.x;
		y=this.boundary.y;
		w=this.boundary.w;
		h=this.boundary.h;
		nw = new Rectangle(x,y,w/2,h/2);
		ne = new Rectangle(x+w2, y,w/2,h/2);
		sw = new Rectangle(x, y+h/2, w/2, h/2);
		ne = new Rectangle(x+w/2, y+h/2,w/2,h/2);
		this.northeast(new Quadtree);
	}
}