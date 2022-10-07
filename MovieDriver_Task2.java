import java.util.Scanner;
public class MovieDriver {
	public static void main(String []args) {
		
		Scanner keyboard=new Scanner(System.in);
		/* 
		 * This code will ask the user to enter a movie, rating, tickets sold, and if they want
		 * the questions to be asked again if not the program will end
		 * 
		 */
		String title,
			    rating;
		int soldTickets;
		final String YES="Y";
		final String NO="N";
		String userAnswer;
		Movie movies=new Movie(); //create new movie object 
		/*
		 * start loop to get info from user and save each in movie object
		 */
		do {
		System.out.println("Enter the name of the movie");
		title = keyboard.nextLine();
		movies.setTitle(title); //saves title to movies object 
		System.out.println("Enter the movie's rating");
		rating=keyboard.nextLine();
		movies.setRating(rating); //saves rating to movies object
		System.out.println("Enter the number of tickets sold at a (unnamed) theater");
		soldTickets=keyboard.nextInt();
		movies.setSoldTickets(soldTickets); //saves soldTickets to movies object
		System.out.println(movies.toString()); //prints out using movie object and class
		System.out.println("Do you want to enter another? (y or n)");
		keyboard.nextLine();//Prevents program from skipping
		userAnswer=keyboard.nextLine();
		}
		while(userAnswer.equalsIgnoreCase(YES)); //loop if user wants questions asked again
		System.out.println("Goodbye!");
	}
}

