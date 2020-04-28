import java.util.Scanner;

public class User {
	Grid myGrid = new Grid();           // user's grid
	Grid enemyGrid = new Grid();        // user's enemy's grid
	
	Scanner input = new Scanner(System.in);
	
	int userNo;         				// each user has its number
	int nDestroyed = 0;				    // how many boats this user destroyed
	
	public User(int num) {
		myGrid.initGrid();              // initializing grid with -1's
		enemyGrid.initGrid();
		userNo = num;
	}
	
	// user puts boats in his grid
	public void putBoats() {
		System.out.println("USER"+userNo+" : ");
		int []nBoats = {1,2,1,1} ;
		Boat b ;
		 
		for(int i=2; i <= 5; i++) {                         // change it // it is length
			for(int j =0; j< nBoats[i-2]; j++){ 								
																	
				int x1,x2,y1,y2;
				char c1,c2;
				if(i == 1)
					System.out.println("Enter starting and ending coordinates(of boat of length "+i+") \nExample: 1 A");
				else
					System.out.println("Enter starting and ending coordinates(of boat of length "+i+") \nExample: 1 A 1 B");

				x1 = input.nextInt(); //y1 = input.nextInt();
				c1 = input.next(".").charAt(0);
				y1 = c1 - 'A' + 1 ;

				if(i == 1) { 
					x2= x1;  y2 = y1;
				}
				else {
					 x2 = input.nextInt();  c2 =input.next(".").charAt(0);
					 y2 = c2 - 'A' + 1 ;	 
				}
				b = new Boat();
				boolean boo = b.createBoat(x1-1, y1-1, x2-1, y2-1);
				if(boo == true) {
					if(myGrid.canAdd(b) == true && b.length == i)
						myGrid.addBoat(b);
					else {
						System.out.println("Can't add this boat.Enter the coordinates again.\nMake sure the length is correct and the boat is not overlapping with other boats.\n");
						j--;
					}
				}
				else {
					System.out.println("Can't add this boat.Enter the coordinates again.\nMake sure you are entering coordinates according to example\n");
					j--;
				}
				
			}
		}
		System.out.println("User"+userNo+" , "+"Your board :");
		myGrid.showGrid();
	}
	// user makes a shoot
	public int shoot(User otherUser) {
		int x,y;
		char c;
		System.out.println("USER"+userNo+" ,your turn to shoot.Enter coordinates:\nExample: 1 A");
		x = input.nextInt(); 
		c = input.next(".").charAt(0);
		y = c - 'A' + 1 ;
		if(x <= 0 || y <=0  || x>10 || y>10) return 3; 					// error return 
		int sank = otherUser.myGrid.checkShoot(x-1,y-1,this.enemyGrid); // check the user's shoot 
		return sank;
	}
	
}

