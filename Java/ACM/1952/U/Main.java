import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNextLine()) {
            String in = cin.nextLine();
            int i = 0, num = 0, ans = 0;
            while (i < in.length()) {
                if (in.charAt(i) >= '0' && in.charAt(i) <= '9') {
                    num = num * 10 + in.charAt(i) - '0';
                } else {
                    ans += num;
                    num = 0;
                }
                i++;
            }
            ans += num;
            System.out.println(ans);
        }
    }

}
