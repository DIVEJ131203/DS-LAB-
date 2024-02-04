import java.util.Scanner;

public class practiceset1q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 3 numbers:");
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        int num3 = sc.nextInt();
        int avg = (num1 + num2 + num3) / 3;
        System.out.println(avg);
        sc.close();
    }
}
