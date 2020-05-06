public class Node
{
	String label;
	Node left, right;
	public Node(String label)
	{
		this.label=new String(label);
		this.left=null;
		this.right=null;
	}
	public String toString()
	{
		return new String(this.label);
	}
	public void addChild(Node n)
	{
		if(this.left==null)
		{
			this.left=n;
			return;
		}
		if(this.right==null)
		{
			this.right=n;
			return;
		}
	}
	static void printDescendant(Node n)
	{
		System.out.print("[ ");
		if(n!=null)
		{
			System.out.print(n.toString());
			printDescendant(n.left);
			System.out.print(", ");
			printDescendant(n.right);
		}
		System.out.print(" ]");
	}
}
