public class Boat {
	int [][]positions = new int[2][2];
	int length;
	boolean vertical;
	
	//creating a new boat by giving it's starting and ending coordinates 
	public boolean createBoat(int x1,int y1, int x2,int y2) {
		if( (x1 == x2 || y1 == y2) && x1>=0 && x2>=0 && y1>=0 && y2>=0 && x1<10 && x2<10 && y1<10 && y2<10 ) {

			if(x1 == x2) {                            // boat is vertical 
				this.length = Math.abs(y2-y1)+1;
				this.vertical = true;
				if(y1>y2) {
					int y = y1;
					int x = x1;
					x1 = x2; y1 = y2;
					x2 = x; y2 = y;
					
				}
			}
			else {									  // boat is horizontal
				this.length = Math.abs(x2-x1)+1;
				this.vertical = false;
				if(x1 > x2) {
					int y = y1;
					int x = x1;
					x1 = x2; y1 = y2;
					x2 = x; y2 = y;
				}
			}
			this.positions[0][0] = x1;
			this.positions[0][1] = y1;
			this.positions[1][0] = x2;
			this.positions[1][1] = y2;
			return true;
		}
		else
			return false;
	}
}
