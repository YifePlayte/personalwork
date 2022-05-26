import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNextLine()) {
			String str = cin.nextLine();
			int[] num = new int[26];
			for (int i = 0; i < str.length(); i++) {
				if (str.charAt(i) >= 'a' && str.charAt(i) <= 'z') {
					num[str.charAt(i) - 'a']++;
				} else if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') {
					num[str.charAt(i) - 'A']++;
				}
			}
			for (int i = 0; i < 26; i++) {
				System.out.printf("%3d", num[i]);
			}
			System.out.println();
		}
	}

}
