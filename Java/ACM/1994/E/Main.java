/*
E.信息处理
Time Limit: 1000 MS	Memory Limit: 32768 K
Total Submit: 313 (205 users)	Total Accepted: 10 (10 users)	Special Judge: No

Description
现有多行字符串，需要从里面提取并处理各种信息。具体提取与处理，是先给定标志，而后给定字符串。如是“sum”标志，从字符串中提取数据求和；是“num”标志，计算字符串中非数字、非大小写字母的字符数量；是“id”标志，提取身份证号（满足连续的15或18位的数字组合）；是“sort”标志，则对从字符串中把所有非英文字母作为分隔符而得到的字符串排序。

Input
给定不定组数的数据，每组数据中有两行，第一行是提取处理标识；第二行是待处理的字符串。

Output
对于标志是sum的，输出从字符串中提取的数据和，保留两位小数；
对于标志是num的，输出字符串中非数字、非大小写字母的字符数量；
对于标志是id的，输出字符串中所有的身份证号，中间用英文“;”分隔。
对于标志是sort的，输出字符串中把所有非英文字母作为分隔符而得到的排序后的字符串（按字典顺序排序），中间用一个英文“;”分隔。参见样例。

Sample Input
sum
tv:1000.0$; phone:300$;car:2000.0$;
num
Total Submit:102(62 users)
id
123,123456712423355,123456712423355,321123456712423355, 123321123456712423355
sort
tv:1000.0$; phone:300$;car:2000.0$;

Sample Output
3300.00
5
123456712423355;123456712423355;321123456712423355
car;phone;tv
 */
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String s = scanner.nextLine();
            String l = scanner.nextLine();
            switch (s) {
                case "sum":
                    utils.sum(l);
                    break;
                case "num":
                    utils.num(l);
                    break;
                case "id":
                    utils.id(l);
                    break;
                case "sort":
                    utils.sort(l);
                    break;
            }
        }
    }
}

class utils {
    public static void sum(String s) {
        boolean isNum = false;
        boolean isSmall = false;
        int weight = 0;
        double temp = 0;
        double ans = 0;
        for (char c : s.toCharArray()) {
            if (c >= '0' && c <= '9') {
                isNum = true;
                temp = temp * 10 + c - '0';
                if (isSmall) {
                    weight++;
                }
            } else if (c == '.' && isNum && !isSmall) {
                isSmall = true;
            } else if (isNum) {
                if (isSmall) {
                    temp = temp / Math.pow(10, weight);
                }
                ans += temp;
                isNum = false;
                isSmall = false;
                weight = 0;
                temp = 0;
            }
        }
        System.out.printf("%.2f\n", ans);
    }

    public static void num(String s) {
        int num = 0;
        for (char c : s.toCharArray()) {
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
                num++;
            }
        }
        System.out.println(num);
    }

    public static void id(String s) {
        List<String> ids = new ArrayList<>();
        String temp = "";
        for (char c : s.toCharArray()) {
            if (c >= '0' && c <= '9') {
                temp += c;
            } else {
                if (temp.length() == 15 || temp.length() == 18) {
                    ids.add(temp);
                }
                temp = "";
            }
        }
        boolean isFirst = true;
        for (String id : ids) {
            if (isFirst) {
                isFirst = false;
            } else {
                System.out.print(';');
            }
            System.out.print(id);
        }
        System.out.println();
    }

    public static void sort(String s) {
        List<String> ss = new ArrayList<>();
        String temp = "";
        for (char c : s.toCharArray()) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                temp += c;
            } else {
                if (!temp.isEmpty()) ss.add(temp);
                temp = "";
            }
        }
        Collections.sort(ss);
        boolean isFirst = true;
        for (String sd : ss) {
            if (isFirst) {
                isFirst = false;
            } else {
                System.out.print(';');
            }
            System.out.print(sd);
        }
        System.out.println();
    }
}
