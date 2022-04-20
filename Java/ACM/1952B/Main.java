import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int a, aa, b, s;
		Scanner cin = new Scanner(System.in);
		while (cin.hasNextInt()) {
			a = cin.nextInt();
			b = cin.nextInt();
			aa = 0;
			s = 0;
			for (int i = 0; i < b; i++) {
				aa = aa * 10 + a;
				s += aa;
				if (i != 0) System.out.print("+");
				System.out.print(aa);
			}
			System.out.printf("=%s\n", s);
		}
	}
}