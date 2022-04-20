import javax.swing.JOptionPane;

public class GuessNumber {
	public static void main(String[] args) {
		System.out.println("给你一个1至100之间的整数，请猜测这个数");
		int realNumber = (int)(Math.random() * 100) + 1;
		int yourGuess = 0;
		String str = JOptionPane.showInputDialog("输入您的猜测：");
		yourGuess = Integer.parseInt(str);
		while (yourGuess != realNumber) {
			if (yourGuess > realNumber) {
				str = JOptionPane.showInputDialog("猜大了，再输入你的猜测：");
				yourGuess = Integer.parseInt(str);
			} else if (yourGuess < realNumber) {
				str = JOptionPane.showInputDialog("猜小了，再输入你的猜测：");
				yourGuess = Integer.parseInt(str);
			}
		}
		System.out.println("猜对了！");
	}
}
