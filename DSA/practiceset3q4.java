import java.util.Scanner;

public class practiceset3q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a year");
        double year = sc.nextDouble();
        if (year % 4 != 0) {
            System.out.println("Not Leap Year");
        }
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                System.out.println("Leap year");
            } else {
                System.out.println("Not leap year");
            }

        }

        else {
            if (year % 4 == 0) {
                System.out.println("Leap year");
            }
        }
        sc.close();
    }
}
