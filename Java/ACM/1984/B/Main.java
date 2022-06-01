import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int[][] n;
		int i;
		while (cin.hasNextInt()) {
			i = cin.nextInt();
			n = new int[i + 1][i + 1];
			n[0][0] = 1;
			for (int j = 1; j <= i; j++) {
				for (int k = 1; k <= j; k++) {
					n[j][k] = n[j - 1][k - 1] + n[j - 1][k];
					System.out.printf("%5d", n[j][k]);
				}
				System.out.println();
			}
		}
	}

}
