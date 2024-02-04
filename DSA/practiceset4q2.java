import java.util.Scanner;

public class practiceset4q2 {
    public static boolean isEven(int number) {
        return number % 2 == 0;
    }

    public static void main(String[] args) {
        System.out.println("Enter a number");
        Scanner s = new Scanner(System.in);
        int number = s.nextInt();
        boolean result = isEven(number);
        System.out.println(result);
        s.close();
    }
}
