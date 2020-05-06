public class Segment
{
	private Point p1, p2;
	public Point getP1()
	{
		return new Point(p1.getX(), p1.getY());
	}
	public Point getP2()
	{
		return new Point(p2.getX(), p2.getY());
	}
	public void setP1(Point p1)
	{
		this.p1.setX(p1.getX());
		this.p1.setY(p1.getX());
	}
	public void setP2(Point p2)
	{
		this.p2.setX(p2.getX());
		this.p2.setY(p2.getY());
	}
	public Segment(Point p1, Point p2)
	{
		this.p1=new Point(p1.getX(), p1.getY());
		this.p2=new Point(p2.getX(), p2.getY());
	}
	public float length() // This method uses distance(),  method from class Point.
	{
		return p1.distance(p2);
	}
}
