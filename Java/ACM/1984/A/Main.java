import java.util.ArrayList;
import java.util.Scanner;

import static java.util.Collections.reverse;
import static java.util.Collections.sort;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int num, i, a, b;
		ArrayList<Integer> n;
		while (cin.hasNextInt()) {
			num = cin.nextInt();
			i = 0;
			while (num != 6174 && i <= 10 && num > 999 && num < 10000) {
				i++;
				n = new ArrayList<>();
				a = b = 0;
				for (int j = 0; j < 4; j++) {
					n.add(num % 10);
					num = num / 10;
				}
				sort(n);
				for (int j : n) {
					a = a * 10 + j;
				}
				reverse(n);
				for (int j : n) {
					b = b * 10 + j;
				}
				num = b - a;
			}
			if (num == 6174) {
				System.out.printf("%d\n", i);
			} else {
				System.out.println("No");
			}
		}
	}

}
