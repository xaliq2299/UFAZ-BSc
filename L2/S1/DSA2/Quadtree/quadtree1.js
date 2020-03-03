class Point {
	constructor(x,y){
		this.x = x;
		this.y = y;
		this.divided = false;
	}
}

class Rectangle {
	constructor(x,y,w,h){
		this.x = x;
		this.y = y;
		this.w = w;
		this.h = h;
	}
}

class Quadtree{
	constructor(boundary, ){
		this.boundary = boundary;
		this.points = [];
		this.capacity = n;
	}

	insert() {
		if(this.points.length < this.capacity) this.points.push();
		else {if(!this.divided) this.divided = true;}
	}

	subdivide(){
		let nw,ne,sw,se = new Rectangle;
		this.x = x;
		this.y = y;

		this.northwest, northcast, southwest, southeast = 
		new Quadtree();
		this.divided = true;
	}

	insert(point){

	}
}