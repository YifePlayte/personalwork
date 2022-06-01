import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNextLine()) {
			String str = cin.nextLine();
			int[] numa = new int[26];
			int[] numA = new int[26];
			for (int i = 0; i < str.length(); i++) {
				if (str.charAt(i) >= 'a' && str.charAt(i) <= 'z') {
					numa[str.charAt(i) - 'a']++;
				} else if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') {
					numA[str.charAt(i) - 'A']++;
				}
			}
			for (int i = 0; i < 26; i++) {
				System.out.printf("%3d", numA[i]);
			}
			System.out.println();
			for (int i = 0; i < 26; i++) {
				System.out.printf("%3d", numa[i]);
			}
			System.out.println();
		}
	}

}
