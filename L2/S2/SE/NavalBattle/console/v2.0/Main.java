// -1 -- nothing there 
// -2 -- a boat
// 1  -- shoot a boat
// 2  -- sanked a boat
// 0  -- incorrect shoot

import java.io.IOException;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {		
		Scanner input = new Scanner(System.in);
		int nbBoats = 5;
		// creating two new users
		User user1 = new User(1);
		User user2 = new User(2);
		
		// allowing users to put their boats
		user1.putBoats();		
		changeTurn(2);
		clearScreen();

		user2.putBoats();
		changeTurn(1);
		clearScreen();

		System.out.println("Now the game starts.. ");
		
		// start of the game itself
		// while there are still boats to shoot continue the game
		while(user1.nDestroyed != nbBoats && user2.nDestroyed != nbBoats) {  			
			int us1 = 1,us2 = 1;
			while( us1 == 1 || us1 == 2 || us1 == 3) {
				us1 = user1.shoot(user2);
				if(us1 != 3) {									// if it is not an error 
					System.out.println("USER1: your board:");
					user1.myGrid.showGrid();
					System.out.println("USER1: your enemies board:");
					user1.enemyGrid.showGrid();
					if( us1 == 1 ) System.out.println("USER1: you shot a boat ! You make a move again.");
					if ( us1 == 2) { user1.nDestroyed++; System.out.println("USER1: you sanked a boat!!! You make a move again. ");}
					if(user1.nDestroyed == nbBoats) {             					
						System.out.println("USER1 won! Congratulations!");
						System.exit(0);
					}
					if(us1 != 1 && us1 != 2) {
						System.out.println("USER1: you didnt shoot a boat");
						changeTurn(2);
						clearScreen();
					}
				}
			}
			while( us2 == 1 || us2 == 2 || us2 == 3) {
				us2 = user2.shoot(user1);
				if(us2 != 3) {									// if it is not an error 
					if ( us2 == 2) user2.nDestroyed++;
					user2.myGrid.showGrid();
					System.out.println("USER2: your enemies board:");
					user2.enemyGrid.showGrid();
					if( us2 == 1 ) System.out.println("USER2: you shot a boat ! You make a move again.");
					if ( us2 == 2) { user2.nDestroyed++; System.out.println("USER2: you sanked a boat!!! You make a move again. ");}
					if(user2.nDestroyed == nbBoats) {                                 
						System.out.println("USER2 won! Congratulations!");
						System.exit(0);
					}
					if(us2 != 1 && us2 != 2) {
						System.out.println("USER2: you didnt shoot a boat");
						changeTurn(1);
						clearScreen();
					}
				}
			}				
		}

		
	}	
	public static void clearScreen() {  
	    System.out.print("\033[H\033[2J");  
	    System.out.flush();  
	} 
	public static void changeTurn(int userNo) {
		System.out.println("Press enter to change turn to  USER"+userNo);
		try {
			System.in.read();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
