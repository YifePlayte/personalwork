import javax.swing.JOptionPane;

public class Number {
	public static void main(String[] args) {
		int number = 0, d5, d4, d3, d2, d1;
		for (int i = 5; i > 0; i--) {
			String str = JOptionPane.showInputDialog("输入一个1至99999之间的数");
			number = Integer.parseInt(str);
			if (number > 0 && number < 100000) {
				d5 = number / 10000;
				d4 = number % 10000 / 1000;
				d3 = number % 1000 / 100;
				d2 = number % 100 / 10;
				d1 = number % 10;
				if (d5 > 0) {
					System.out.println(number + "是5位数");
					if (d5 == d1 && d4 == d2) {
						System.out.println(number + "是回文数");
					} else {
						System.out.println(number + "不是回文数");
					}
				} else if (d4 > 0) {
					System.out.println(number + "是4位数");
					if (d4 == d1 && d3 == d2) {
						System.out.println(number + "是回文数");
					} else {
						System.out.println(number + "不是回文数");
					}
				} else if (d3 > 0) {
					System.out.println(number + "是3位数");
					if (d3 == d1) {
						System.out.println(number + "是回文数");
					} else {
						System.out.println(number + "不是回文数");
					}
				} else if (d2 > 0) {
					System.out.println(number + "是2位数");
					if (d2 == d1) {
						System.out.println(number + "是回文数");
					} else {
						System.out.println(number + "不是回文数");
					}
				} else {
					System.out.println(number + "是1位数");
					System.out.println(number + "是回文数");
				}
			} else {
				System.out.printf("%d不在1至99999之间\n", number);
			}
		}
	}
}
