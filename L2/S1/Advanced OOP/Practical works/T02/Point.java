public class Point
{
	private float x,y;
	public Point(float x, float y)
	{
		this.x=x;
		this.y=y;
	}
	public float getX()
	{
		return x;
	}
	public float getY()
	{
		return y;
	}
	public void setX(float x)
	{
		this.x=x;
	}
	public void setY(float y)
	{
		this.y=y;
	}
	public float distance()
	{
		return (float) Math.sqrt(x*x+y*y);
	}
	public float distance(Point point) // a) Overloading. b) Overriding is when a subclass redefines a function.
	{
		return (float) Math.sqrt((point.getX()-x)*(point.getX()-x)+(point.getY()-y)*(point.getY()-y));
	}
	public void translate(float dx, float dy)
	{
		x*=dx;
		y*=dy;
	}
	public static Point barycenter(Point[] points) // It should be static, because it does not operate on a particular instance of point.
	{
		float sumX=0, sumY=0;
		for(int i=0; i<points.length; i++)
		{
			sumX+=points[i].getX();
			sumY+=points[i].getY();
		}
		return new Point(sumX/points.length, sumY/points.length);
	}
}
