/*
 * Class: CMSC203 
 * Instructor:Dr.Grinberg
 * Description: Ceaser cipher and bellaso cipher encryption followed by decryption methods as well as
 * a in bounds checker
 * Due: 03/12/2023
 * Platform/compiler:
 * I pledge that I have completed the programming 
 * assignment independently. I have not copied the code 
 * from a student or any source. I have not given my code 
 * to any student.
   Print your Name here: Damaris Constante
*/

/**
 * This is a utility class that encrypts and decrypts a phrase using two
 * different approaches. The first approach is called the Caesar Cipher and is a
 * simple �substitution cipher� where characters in a message are replaced by a
 * substitute character. The second approach, due to Giovan Battista Bellaso,
 * uses a key word, where each character in the word specifies the offset for
 * the corresponding character in the message, with the key word wrapping around
 * as needed.
 * 
 * @author Farnaz Eivazi
 * @version 7/16/2022
 */
public class CryptoManager {
	
	private static final char LOWER_RANGE = ' ';
	private static final char UPPER_RANGE = '_';
	private static final int RANGE = UPPER_RANGE - LOWER_RANGE + 1;

	/**
	 * This method determines if a string is within the allowable bounds of ASCII codes 
	 * according to the LOWER_RANGE and UPPER_RANGE characters
	 * @param plainText a string to be encrypted, if it is within the allowable bounds
	 * @return true if all characters are within the allowable bounds, false if any character is outside
	 */
	public static boolean isStringInBounds (String plainText) {
		 boolean status = true;
		    for (int a= 0; a< plainText.length(); a++) {
		      if (!(plainText.charAt(a) >= LOWER_RANGE && plainText.charAt(a) <= 
		    		  UPPER_RANGE)) {
		        status = false;
		      }
		    }
			return status;
	}

	/**
	 * Encrypts a string according to the Caesar Cipher.  The integer key specifies an offset
	 * and each character in plainText is replaced by the character \"offset\" away from it 
	 * @param plainText an uppercase string to be encrypted.
	 * @param key an integer that specifies the offset of each character
	 * @return the encrypted string
	 */
	public static String caesarEncryption(String plainText, int key) {
		String encrypted="";
		int addKey=0;
		char changeToChar=0;
		for(int b=0;b<plainText.length();b++) {
			addKey= plainText.charAt(b)+key;
			while(addKey>95){
				addKey-=64;
			}
			changeToChar=(char)addKey;
			encrypted+=changeToChar;
		}
		return encrypted;
	}
	
	/**
	 * Encrypts a string according the Bellaso Cipher.  Each character in plainText is offset 
	 * according to the ASCII value of the corresponding character in bellasoStr, which is repeated
	 * to correspond to the length of plainText
	 * @param plainText an uppercase string to be encrypted.
	 * @param bellasoStr an uppercase string that specifies the offsets, character by character.
	 * @return the encrypted string
	 */
	public static String bellasoEncryption (String plainText, String bellasoStr) {
		String addKey = "";
		String numEncrypt ="";
		int encrypt = 0;
		char changeToChar = 0;
		int c=0;
		for(int a=0;a<plainText.length();a++) { //setting bellaso string to length of plainText
			addKey+= bellasoStr.charAt(c);
			c++;
			if(c>=5) {
				c=0;
			}
		}
		for(int b=0;b<plainText.length();b++) {
			encrypt=plainText.charAt(b)+addKey.charAt(b);
			while(encrypt>95) {
				encrypt-=64;
				changeToChar=(char)encrypt;
			}
			numEncrypt+=changeToChar;
		}
		
		return numEncrypt;
	}
	
	/**
	 * Decrypts a string according to the Caesar Cipher.  The integer key specifies an offset
	 * and each character in encryptedText is replaced by the character \"offset\" characters before it.
	 * This is the inverse of the encryptCaesar method.
	 * @param encryptedText an encrypted string to be decrypted.
	 * @param key an integer that specifies the offset of each character
	 * @return the plain text string
	 */
	public static String caesarDecryption (String encryptedText, int key) {
		String decrypted="";
		int addKey=0;
		char changeToChar=0;
		for(int b=0;b<encryptedText.length();b++) {
			addKey=encryptedText.charAt(b)-key;
			while(addKey<32) {
				addKey+=64;
			}
			changeToChar=(char)addKey;
			decrypted+=changeToChar;
			
		}
		return decrypted;
	}
	
	/**
	 * Decrypts a string according the Bellaso Cipher.  Each character in encryptedText is replaced by
	 * the character corresponding to the character in bellasoStr, which is repeated
	 * to correspond to the length of plainText.  This is the inverse of the encryptBellaso method.
	 * @param encryptedText an uppercase string to be encrypted.
	 * @param bellasoStr an uppercase string that specifies the offsets, character by character.
	 * @return the decrypted string
	 */
	public static String bellasoDecryption(String encryptedText, String bellasoStr) {

		String addKey = "";
		String numDecrypt ="";
		int decrypt = 0;
		char changeToChar = 0;
		int c=0;
		for(int a=0;a<encryptedText.length();a++) { //setting bellaso string to length of plainText
			addKey+= bellasoStr.charAt(c);
			c++;
			if(c>=5) {
				c=0;
			}
		}
		for(int b=0;b<encryptedText.length();b++) {
			decrypt=encryptedText.charAt(b)-addKey.charAt(b);
			while(decrypt<32) {
				decrypt+=64;
				changeToChar=(char)decrypt;
			}
			numDecrypt+=changeToChar;
		}
		return numDecrypt;
	}
}
