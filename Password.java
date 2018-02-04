import java.util.*;
import java.io.Console;

class Password {
	public static void main(String[] args) {
		Console console = System.console();
		if(console == null) {
			System.out.println("Unable to get console instance");
		}
		System.out.println("Enter the password :");
		char[] password = console.readPassword();
		if(password.length <= 6) {
			System.out.println("Password size is less");
		}
		else {
			int length = password.length;
			int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
			for(int i=0;i<length;i++) {
				if(Character.isUpperCase(password[i]))
					count1 = 1;
				else if(Character.isLowerCase(password[i]))
					count2 = 1;
				else if(Character.isDigit(password[i]))
					count3 = 1;
				else
					count4 = 1;
			}
			int count = count1 + count2 + count3 + count4;
			if(count == 1)
				System.out.println("Weak");
			if(count == 2)
				System.out.println("Moderate");
			if(count == 3)
				System.out.println("Strong");
			if(count == 4)
				System.out.println("Very Strong");
		}
	}
}
