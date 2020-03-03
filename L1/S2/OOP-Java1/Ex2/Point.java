public class Point{
	private float x;
	private float y;

	public static class Segment{
	  	Point p1;
		Point p2;
		
		public Segment(Point p1, Point p2){
			this.p1 = p1;
			this.p2 = p2; 
		}
		//Getters
		public Point getP1(){
			return this.p1;
		}
		
		public Point getP2(){
			return this.p2;
		}
		
		//Setters
		public void setP1(float x, float y){
			this.p1.x = x;
			this.p1.y = y;
		}
		
		public void setP2(float x, float y){
			this.p2.x = x;
			this.p2.y = y;
		}
		
		public float length(){ // delegation? -- Yes, We can use the method of class Point (getX or getY) in here
			return (float) Math.sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
		}
	}
	
	public Point(float x, float y){
		this.x = x;
		this.y = y;
	}
	
	public static void main(String args[]){
		Point p = new Point(3, 4);
		Point p1 = new Point(2, 4);
		Point[] points = new Point[2];
		points[0] = p;
		points[1] = p1;
		Point bary = barycenter(points);
		System.out.printf("%f, %f\n", bary.x, bary.y);
		Segment s = new Segment(p, p1);
		System.out.println( s.length() );	
	}
	
	//Setters
	public void setX(float x){
		this.x=x;
	}
	
	public void setY(float y){
		this.y=y;
	}
	
	//Getters
	public float getX(){
		return this.x; //could be x simply
	}
	
	public float getY(){
		return this.y; //could be y simply
	}
	
	public float distance(){
		float d = (float)Math.sqrt(this.x*this.x+this.y*this.y);
		return d;
	}
	
	public float distance(Point point){
		return (float) Math.sqrt( (point.x-this.x)*(point.x-this.x)+(point.y-this.y)*(point.y-this.y) );
	}

	public void translate(float dx, float dy){
		this.x+=dx;
		this.y+=dy;
	}
	
	public static Point barycenter(Point[] points){
		float bx=0, by=0;
		Point bary = new Point(0, 0);
		for(int i=0;i<points.length;i++){
			bx+=points[i].x; 
			by+=points[i].y;
	}
	bary.x=bx/points.length;
	bary.y=by/points.length;

	return bary;
	}
}
