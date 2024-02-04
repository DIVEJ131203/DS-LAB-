import java.util.Scanner;

public class practiceset4q3 {
    public static boolean isPalindrome(int number) {
        int orgnum = number;
        int revnum = 0;
        while (number > 0) {
            int temp = number % 10;
            revnum = temp + revnum * 10;
            number /= 10;
        }
        return orgnum == revnum;
    }

    public static void main(String[] args) {
        System.out.println("Enter a number");
        Scanner s = new Scanner(System.in);
        int number = s.nextInt();
        if (isPalindrome(number))
            System.out.println("is palindrome");
        else
            System.out.println("not palindrome");
        s.close();
    }
}
