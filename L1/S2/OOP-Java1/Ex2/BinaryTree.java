public class BinaryTree{

	private static class Node{
		private String label;
		private Node left;
		private Node right;
		
		public String toString(){
			return this.label;
		}
	
		public void addChild(Node n){
			Node cur = this;
			while(cur.left != null){
				cur = cur.left;	
			}
			cur.left = n;
		}
	
		public void printDescendant(){
			Node cur = this;
			while(cur != null){
				System.out.println(cur);
				cur = cur.left;
			}
		}
	}
	
	public static void main(String args[]){
		Node myTree = new Node();
		myTree.label = "UFAZ";
		myTree.left=myTree.right=null;
		
		Node n = new Node();		
		n.label = "CS";
		n.left = n.right = null;
		myTree.addChild(n);
		Node n2 = new Node();
		n2.label = "Algebra";
		n2.left=n2.right = null;
		n.addChild(n2);
		
		myTree.printDescendant();
	}
}
