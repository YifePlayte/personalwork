public class Alphabet {
	public static void main(String[] args) {
		int startPosition = 0, endPosition = 0;
		char cStart = 'A', cEnd = 'Z';
		startPosition = (int)cStart;
		endPosition = (int)cEnd;
		System.out.println("英语字母A在Unicode表中的位置：" + startPosition);
		System.out.println("英语字母表");
		for (int i = startPosition; i <= endPosition; i++) {
			char c = '\0';
			c = (char)i;
			System.out.print(" " + c);
			if ((i - startPosition + 1) % 10 == 0)
				System.out.println(" ");
		}
	}
}
