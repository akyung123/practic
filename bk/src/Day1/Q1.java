package Day1;

import java.util.Scanner;

public class Q1 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int num = s.nextInt();
        s.nextLine();
        for(int i = 1; i < 10; i++) {
            System.out.println(num +" * "+i+ " = "+num*i);
        }
    }
}
