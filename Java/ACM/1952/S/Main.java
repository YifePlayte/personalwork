import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNextInt()) {
			int n = cin.nextInt();
			int base = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					System.out.printf("%6d", (j + base) % n + 1);
				}
				System.out.println();
				base++;
			}
		}
	}

}
