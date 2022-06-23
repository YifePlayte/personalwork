/*
 A.计算年收入
 Time Limit: 1000 MS	Memory Limit: 32768 K
 Total Submit: 627 (305 users)	Total Accepted: 262 (260 users)	Special Judge: No
 Description
 工人按月领薪，辛苦一年后想知道一年的总收入。已知每个工人每月的收入，要求用java实现输出年收入。

 Input
 有不定行数的数据，每行12个整数，数据用空格分隔。

 Output
 每行为一个整数。每行都有换行，参见样例。

 Sample Input
 5000 5000 5000 5000 5000 5000 5000 5000 5000 5000 5000 5000

 5000 5000 5000 6000 5000 5000 6000 5000 5000 6000 5000 5000

 8000 8000 8000 8000 9000 9000 9000 9000 9000 9000 9000 9000

 Sample Output
 60000
 63000
 104000
 */
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int sum = 0;
            for (int i = 0; i < 12; i++) {
                sum += scanner.nextInt();
            }
            System.out.println(sum);
        }
    }
}
