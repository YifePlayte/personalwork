import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            String string = scanner.next();
            boolean result = true;
            for (int i = 1; i < string.length(); i++) {
                if (string.charAt(i - 1) > string.charAt(i)) {
                    result = false;
                    break;
                }
            }
            if (result) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }
}
