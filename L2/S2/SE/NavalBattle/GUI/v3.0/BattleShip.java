import java.awt.*;
import javax.swing.*;

public class BattleShip{
	public static final int WIDTH = 500;
	public static final int HEIGHT = 500;

	public static void main(String[] args) {
		JFrame window = new JFrame("Battle Ship");
		window.setSize (WIDTH, HEIGHT);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JLabel welcome = new JLabel("Welcome, choose the mode of the game");
		welcome.setFont(new Font("Courier", Font.BOLD, 22));
		
		window.setLayout(new GridLayout(5,1));
				
		Button b1 = new Button ("vs Computer");
		Button b2 = new Button ("2 players");
		Button b3 = new Button ("Online (not available)");
		Button b4 = new Button ("Exit");

		b1.addActionListener((c) -> {
			botButtonPressed(window);
	    });
		b2.addActionListener((c) -> {
			vsButtonPressed(window);
		});
		b4.addActionListener((c) -> {
			exitButtonPressed();
	    });
		
		window.add(welcome);
		window.add(b1); window.add(b2);
		window.add(b3);	window.add(b4);
		window.setVisible(true);
	}
	
	public static void arrangeShipsForUser() { //! for the versus computer version
		User u = new User("Player");
		JButton confirm = new JButton("Confirm");
		u.add(confirm); //!u.add(confirm, BorderLayout.EAST);
		addShipListeners(u);
		confirm.addActionListener((e) -> {
			confirmButtonPressed(u);
	    });
		u.setVisible(true);
	}

	public static void arrangeShipsForUsers() { //! for 2 players version
		User user1 = new User("Player1");
		User user2 = new User("Player2");	
		JButton confirm1 = new JButton("Confirm");
		JButton confirm2 = new JButton("Confirm");

		user1.add(confirm1, BorderLayout.EAST);
		addShipListeners(user1);
		confirm1.addActionListener((e) -> {
			confirmButton1Pressed(user1, user2);
	    });
		user1.setVisible(true);
		
		user2.add(confirm2, BorderLayout.EAST);
		addShipListeners(user2);
		confirm2.addActionListener((e) -> {
			confirmButton2Pressed(user1, user2);
		});
	}
	
	public static void addShipListeners(User user) {
		JButton ship5 = new JButton("Carrier/5");
		JButton ship4 = new JButton("Battleship/4");
		JButton ship3a = new JButton("Cruiser/3");
		JButton ship3b = new JButton("Submarine/3");
		JButton ship2 = new JButton("Destroyer/2");
		user.add(ship5);  user.add(ship4); user.add(ship3a);
		user.add(ship3b); user.add(ship2);
		
		ship5.addActionListener((e) -> {
			carrier(user);
	    });
		ship4.addActionListener((e) -> {
			battleship(user);
	    });
		ship3a.addActionListener((e) -> {
			cruiser(user);
	    });
		ship3b.addActionListener((e) -> {
			submarine(user);
	    });
		ship2.addActionListener((e) -> {
			destroyer(user);
	    });
	}
	
	public static void botButtonPressed(JFrame f) {
		f.getContentPane().removeAll();
		f.setVisible(false);
		arrangeShipsForUser();
	}
	
	public static void vsButtonPressed(JFrame f) {
		f.getContentPane().removeAll();
		f.setVisible(false);
		arrangeShipsForUsers();
	}
	
	public static void exitButtonPressed() {
		System.exit(1);
	}

	public static boolean _isValid(Grid grid) { //! checks whether a grid of ships is valid
		for(int i=0;i<5;i++){
			if(grid.ships[i].validity == false)
			return false;
		}
		return true;
	}

	public static void confirmButtonPressed(User u){
		if( _isValid(u.myGrid) )
			Game.startGame(u);
	}
	
	public static void confirmButton1Pressed(User u1, User u2) {
		if( _isValid(u1.myGrid) ) {
			u1.setVisible(false);
			u2.setVisible(true);
		}
	}
	
	public static void confirmButton2Pressed(User u1, User u2) {
		if( _isValid(u2.myGrid) ) {
			u2.setVisible(false);
			Game.startGame(u1,u2);
		}
	}

	public static void carrier(User u) {
		u.myGrid.ships[0].validity=false;
		addCellListeners(u,"Carrier");
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				if(u.myGrid.cells[i][j].getBackground() == Color.BLUE)
					u.myGrid.cells[i][j].setBackground(null);
				else if(u.myGrid.cells[i][j].getBackground() == Color.YELLOW || 
						u.myGrid.cells[i][j].getBackground() == Color.PINK || 
						u.myGrid.cells[i][j].getBackground() == Color.MAGENTA ||
						u.myGrid.cells[i][j].getBackground() == Color.BLACK)
							u.myGrid.cells[i][j].removeActionListener(u.ul[i][j]);
			}
		}
	}

	public static void battleship(User u) {
		u.myGrid.ships[1].validity=false;
		addCellListeners(u,"Battleship");
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				if(u.myGrid.cells[i][j].getBackground() == Color.YELLOW)
					u.myGrid.cells[i][j].setBackground(null);
				else if(u.myGrid.cells[i][j].getBackground() == Color.BLUE || 
						u.myGrid.cells[i][j].getBackground() == Color.PINK || 
						u.myGrid.cells[i][j].getBackground() == Color.MAGENTA ||
						u.myGrid.cells[i][j].getBackground() == Color.BLACK)
							u.myGrid.cells[i][j].removeActionListener(u.ul[i][j]);
			}
		}
	}

	public static void cruiser(User u) {
		u.myGrid.ships[2].validity=false;
		addCellListeners(u,"Cruiser");
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				if(u.myGrid.cells[i][j].getBackground() == Color.MAGENTA)
					u.myGrid.cells[i][j].setBackground(null);
				else if(u.myGrid.cells[i][j].getBackground() == Color.YELLOW || 
						u.myGrid.cells[i][j].getBackground() == Color.PINK || 
						u.myGrid.cells[i][j].getBackground() == Color.BLUE ||
						u.myGrid.cells[i][j].getBackground() == Color.BLACK)
							u.myGrid.cells[i][j].removeActionListener(u.ul[i][j]);
			}
		}
	}
	
	public static void submarine(User u) {
		u.myGrid.ships[3].validity=false;
		addCellListeners(u,"Submarine");
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				if(u.myGrid.cells[i][j].getBackground() == Color.PINK)
					u.myGrid.cells[i][j].setBackground(null);
				else if(u.myGrid.cells[i][j].getBackground() == Color.YELLOW || 
						u.myGrid.cells[i][j].getBackground() == Color.BLUE || 
						u.myGrid.cells[i][j].getBackground() == Color.MAGENTA ||
						u.myGrid.cells[i][j].getBackground() == Color.BLACK)
							u.myGrid.cells[i][j].removeActionListener(u.ul[i][j]);
			}
		}
	}

	public static void destroyer(User u) {
		u.myGrid.ships[4].validity=false;
		addCellListeners(u,"Destroyer");
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				if(u.myGrid.cells[i][j].getBackground() == Color.BLACK)
					u.myGrid.cells[i][j].setBackground(null);
				else if(u.myGrid.cells[i][j].getBackground() == Color.YELLOW || 
						u.myGrid.cells[i][j].getBackground() == Color.PINK || 
						u.myGrid.cells[i][j].getBackground() == Color.MAGENTA ||
						u.myGrid.cells[i][j].getBackground() == Color.BLUE)
							u.myGrid.cells[i][j].removeActionListener(u.ul[i][j]);
			}
		}
	}

	public static void addCellListeners(User user, String shipName) {
		if(user.ul!=null) { //! this if condition is needed to remove all listeners from all buttons
							//! otherwise caused many problems with cell clicks
			for(int i=0;i<10;i++) {
				for(int j=0;j<10;j++) {
					if(user.ul[i][j] != null)
						user.myGrid.cells[i][j].removeActionListener(user.ul[i][j]);
				}
			}
		}
		user.ul = new UserListener [10][10];
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				user.ul[i][j] = new UserListener(user,shipName);
				user.myGrid.cells[i][j].addActionListener(user.ul[i][j]);
			}
		}
	}
}