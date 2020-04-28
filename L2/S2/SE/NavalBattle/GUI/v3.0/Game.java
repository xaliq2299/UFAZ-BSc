import java.awt.Color;
import java.awt.FlowLayout;
import javax.swing.JButton;

public class Game {
	public static void startGame(User u) {
		u.removeUserListeners(); //! removing ActionListeners from Grid Table of the user
		u.getContentPane().removeAll();
		u.setLayout(new FlowLayout());
		u.add(u.myGrid.getContentPane());
		u.myGrid.table = new int [10][10];
		
		Bot bot = new Bot();
		
		u.add(bot.myGrid.getContentPane());
		u.revalidate();
		u.repaint();
		
		//! filling the table of indexes with 1 for myGrid where there's ship cell
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				Color col = u.myGrid.cells[i][j].getBackground();
				if ( col == Color.BLACK   || 
					 col == Color.BLUE    ||
					 col == Color.YELLOW  ||
					 col == Color.MAGENTA ||
					 col == Color.PINK
				   )
					u.myGrid.table[i][j]=1;
			}
		}

		//! adding shoot method of user as listener for bot cells
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				int hold = bot.myGrid.table[i][j]; //! had to do this
				JButton button = bot.myGrid.cells[i][j];
				bot.myGrid.cells[i][j].addActionListener((c) -> {
					u.shoot(u, bot, hold, button);
			    });
			}
		}
	}
	
	public static void startGame(User u1, User u2) {
		u1.removeUserListeners(); //! removing ActionListeners from Grid Table of the user1
		u2.removeUserListeners(); //! removing ActionListeners from Grid Table of the user2
		u1.turn=true;  //! by default
		u2.turn=false; //! by default
		
		//! User 1
		u1.getContentPane().removeAll();
		u1.setLayout(new FlowLayout());
		u1.add(u1.myGrid.getContentPane());
		u1.myGrid.table = new int [10][10];
		u1.enemyGrid=new Grid();
		u1.add(u1.enemyGrid.getContentPane());
		
		//! filling the table of indexes with 1 for myGrid
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				Color col = u2.myGrid.cells[i][j].getBackground();
				if ( col == Color.BLACK   || 
					 col == Color.BLUE    ||
					 col == Color.YELLOW  ||
					 col == Color.MAGENTA ||
					 col == Color.PINK
					)
					u1.enemyGrid.table[i][j]=1;
			}
		}

		//! User 2
		u2.getContentPane().removeAll();
		u2.setLayout(new FlowLayout());
		u2.add(u2.myGrid.getContentPane());
		u2.myGrid.table = new int [10][10];
		u2.enemyGrid=new Grid();
		u2.add(u2.enemyGrid.getContentPane());;

		//! filling the table of indexes with 1 for myGrid
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				Color col = u1.myGrid.cells[i][j].getBackground();
				if ( col == Color.BLACK   || 
					 col == Color.BLUE    ||
					 col == Color.YELLOW  ||
					 col == Color.MAGENTA ||
					 col == Color.PINK
					)
					u2.enemyGrid.table[i][j]=1;
			}
		}

		//! adding Action Listeners
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				int hold = u1.enemyGrid.table[i][j]; //! had to do this
				JButton button = u1.enemyGrid.cells[i][j];
				u1.enemyGrid.cells[i][j].addActionListener((c) -> {
					u1.shoot(u1, u2, hold, button);
			    });
			}
		}

		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				int hold = u2.enemyGrid.table[i][j]; //! had to do this
				JButton button = u2.enemyGrid.cells[i][j];
				u2.enemyGrid.cells[i][j].addActionListener((c) -> {
					u2.shoot(u1, u2, hold, button);
			    });
			}
		}

		u1.setVisible(true); //! first user's turn
	}
}
