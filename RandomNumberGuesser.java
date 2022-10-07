/*
 * Class: CMSC203 
 * Instructor:Monshi
 * Description: This program will ask a user to enter their guess 1-100 print out the result and
 * ask the user to guess again if it is wrong the user will be allowed 7 guesses when the user guesses correctly
 * the user will be asked if they want to play again if not the program will end.
 * Due: 09/29/2022
 * Platform/compiler: Eclipse
 * I pledge that I have completed the programming 
 * assignment independently. I have not copied the code 
 * from a student or any source. I have not given my code 
 * to any student.
   Print your Name here: Damaris Constante
*/

//This is a driver class
import java.util.Scanner;

public class RandomNumberGuesser {
	public static void main(String [] args) {
		
		int nextGuess=1;
		int lowGuess=1;
		int highGuess=100;
		final String YES="yes";
		final String NO="no";
		String userAnswer=YES;
		Scanner keyboard=new Scanner(System.in);
		//intro to program
		System.out.println("This application generates a random integer between 1 and 100 and asked the user to guess repeatedly "
															+ "untl they guess correctly.\nEnter your first guess: ");
		//call rand method to generate random number
		int randomNumber= RNG.rand();
		//beginning of loop
		do{
		nextGuess=keyboard.nextInt();//gets guess
		//input validation
		if(nextGuess>highGuess || nextGuess<lowGuess){
			RNG.inputValidation(nextGuess,lowGuess,highGuess);
		}
		RNG a=new RNG();
		System.out.println("Number of guesses: "+a.getCount());//prints out number of guesses
		//if guess is too high tell user guess should be between low guess and  high guess
		if(nextGuess>randomNumber && a.getCount()<7 && nextGuess<highGuess) {
			highGuess=nextGuess;
			System.out.println("Your guess is too high.");
			System.out.println("Your next guess should be in between: "+lowGuess+" and "+--nextGuess);
			highGuess=nextGuess;
		}
		//if guess is too low tell user guess should be between low guess and high guess
		else if(nextGuess<randomNumber && a.getCount()<7 && nextGuess>lowGuess) {
			lowGuess=nextGuess;
			System.out.println("Your guess is too low.");
			System.out.println("Your next guess should be in between: "+ ++nextGuess+" and "+ highGuess);
			lowGuess=nextGuess;
		}
		//if user answers correctly
		else if(nextGuess==randomNumber) {
			System.out.println("Congratulations! You guessed correctly\nTry again? (yes or no)");
			keyboard.nextLine();
			userAnswer=keyboard.nextLine();
			//if user wants to play again counter will reset and new number will be generated
			if(userAnswer.equalsIgnoreCase(YES)) {
				a.resetCount();
				highGuess=100;
				lowGuess=1;
				randomNumber=RNG.rand();
				System.out.println("Enter your first guess: ");
			}
			
		}
		//terminates program if count is 7
		if(a.getCount()>=7) {
			System.out.println("You have exceeded the maximum number of guesses, 7, Try again.");
			System.out.println("Thanks for playing...\nProgrammer name: Damaris Constante");
			System.exit(0);
		}
		}
		while(userAnswer.equalsIgnoreCase(YES));
		//End of program
		System.out.println("Thanks for playing...\nProgrammer name: Damaris Constante");
		
	}

}