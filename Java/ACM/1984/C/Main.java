import java.util.ArrayList;
import java.util.Scanner;

import static java.util.Collections.sort;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		ArrayList<Integer> n;
		int num;
		while (cin.hasNextInt()) {
			num = 0;
			n = new ArrayList<>();
			n.add(cin.nextInt());
			n.add(cin.nextInt());
			sort(n);
			for (int i = n.get(0); i < n.get(1); i++) {
				if (utils.isPrimeNum(i) && utils.isSymmetryNum(i)) {
					System.out.printf("%6d", i);
					num++;
					if (num % 5 == 0)
						System.out.println();
				}
			}
			if (num % 5 != 0)
				System.out.println();
		}
	}

	static class utils {
		public static boolean isPrimeNum(int n) {
			if (n == 1 || n % 2 == 0) {
				return false;
			}
			for (int i = 3; i <= Math.sqrt(n); i += 2) {
				if (n % i == 0)
					return false;
			}
			return true;
		}

		public static boolean isSymmetryNum(int n) {
			ArrayList<Integer> num = new ArrayList<>();
			while (n != 0) {
				num.add(n % 10);
				n /= 10;
			}
			for (int i = 0; i < num.size() / 2; i++) {
				if (num.get(i) != num.get(num.size() - i - 1))
					return false;
			}
			return true;
		}
	}

}
