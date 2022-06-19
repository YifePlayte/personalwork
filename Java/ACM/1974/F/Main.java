import java.util.Arrays;
import java.util.Scanner;

import static java.util.Arrays.sort;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            String a = cin.next();
            String b = cin.next();
            char[] aList = a.toCharArray();
            char[] bList = b.toCharArray();
            sort(aList);
            sort(bList);
            if (Arrays.toString(aList).equals(Arrays.toString(bList))) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}
