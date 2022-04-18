import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int a;
		while (cin.hasNextInt()) {
			a = cin.nextInt();
			a = a / 2;
			for (int i = 0; i <= a; i++) {
				for (int j = 0; j < a - i; j++) System.out.print(" ");
				System.out.print("*");
				if (i > 0) {
					for (int j = 0; j < i * 2 - 1; j++) System.out.print(" ");
					System.out.print("*");
				}
				System.out.print("\n");
			}
			for (int i = a - 1; i >= 0; i--) {
				for (int j = 0; j < a - i; j++) System.out.print(" ");
				System.out.print("*");
				if (i > 0) {
					for (int j = 0; j < i * 2 - 1; j++) System.out.print(" ");
					System.out.print("*");
				}
				System.out.print("\n");
			}
		}
	}
}
