/*
B.输出数字矩阵
Time Limit: 1000 MS	Memory Limit: 32768 K
Total Submit: 853 (303 users)	Total Accepted: 247 (246 users)	Special Judge: No

Description
数字规则排序是经常出现的。现在想要实现给定一个自然数，输出一个三角形矩阵。如输入6，则输出：

  1  2  3  4  5  6
  2  3  4  5  6
  3  4  5  6
  4  5  6
  5  6
  6

Input
有多组数据，每组数据只有一个自然数，不超过99。

Output
输出多组三角矩阵，每个数占3位宽度。参见样例。

Sample Input
6
7

Sample Output
  1  2  3  4  5  6
  2  3  4  5  6
  3  4  5  6
  4  5  6
  5  6
  6

  1  2  3  4  5  6  7
  2  3  4  5  6  7
  3  4  5  6  7
  4  5  6  7
  5  6  7
  6  7
  7
 */
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int in = scanner.nextInt();
            for (int i = 1; i <= in; i++) {
                for (int j = i; j <= in; j++) {
                    System.out.printf("%3d", j);
                }
                System.out.println();
            }
        }
    }
}
