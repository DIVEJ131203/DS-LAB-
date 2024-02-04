import java.util.Scanner;

public class practiceset1q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter pencil ersaser and pen amount");
        int pencil = sc.nextInt();
        int eraser = sc.nextInt();
        int pen = sc.nextInt();
        int total = (pen + pencil + eraser) + (pen + pencil + eraser) * (18 / 100);
        System.out.println("Total Bill:" + total);
        sc.close();
    }

}
