import java.util.Scanner;

public class JavaBasics5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 2 number");
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        int prod = num1 * num2;
        System.out.println("product:" + prod);
        sc.close();
    }
}