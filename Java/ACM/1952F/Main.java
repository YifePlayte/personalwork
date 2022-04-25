import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n;
		while (cin.hasNextInt()) {
			n = cin.nextInt();
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					System.out.printf("%3d", Math.min(i, j));
				}
				System.out.print("\n");
			}
		}
	}
}
