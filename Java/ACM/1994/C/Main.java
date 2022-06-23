/*
C.抽奖
Time Limit: 1000 MS	Memory Limit: 32768 K
Total Submit: 520 (289 users)	Total Accepted: 164 (162 users)	Special Judge: No

Description
抽奖方法如下：所有人按1、2、3……n的顺序围坐一圈，从第1个人开始报数，报到m的退出圈子。如此循环报数，直到圈中只剩下一个人，即为幸运者。一个人需要抢占某个位置能确保自己是幸运者，请用Java编程实现输出该位置。

Input
有不确定组数的多组数据，每组两个整数，分别对应n和m，中间用空格分隔。

Output
每行一个正整数。参见样例。

Sample Input
8  7
12 3

Sample Output
4
10
 */
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            boolean[] people = new boolean[n];
            int i = -1;
            int num = n;
            while (num > 1) {
                for (int j = 0; j < m; j++) {
                    do {
                        i = (i + 1) % n;
                    } while (people[i]);
                }
                people[i] = true;
                num--;
            }
            for (int j = 0; j < people.length; j++) {
                if (!people[j]) System.out.println(j + 1);
            }
        }
    }
}
