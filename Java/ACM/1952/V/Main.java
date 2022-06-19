import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        while (n > 0) {
            int m = cin.nextInt();
            for (int i = 1; i <= m; i++) {
                printLine(m, i);
            }
            for (int i = m - 1; i > 0; i--) {
                printLine(m, i);
            }
            n--;
        }
    }

    private static void printLine(int m, int line) {
        for (int j = 1; j <= m; j++) {
            System.out.printf("%4d", Math.min(j, line));
        }
        for (int j = m - 1; j > 0; j--) {
            System.out.printf("%4d", Math.min(j, line));
        }
        System.out.println();
    }

}
