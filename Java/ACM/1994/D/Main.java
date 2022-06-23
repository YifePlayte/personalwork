/*
D.分数运算
Time Limit: 1000 MS	Memory Limit: 32768 K
Total Submit: 482 (289 users)	Total Accepted: 134 (133 users)	Special Judge: No

Description
设计一个分数类，分数的分子和分母用两个整型数表示，类中要定义方法能对分数进行加法、减法、乘法和除法运算。根据输入定义分数类的对象，然后进行运算并输出运算结果。（要求必须定义分数类）

Input
有多组数据，每组第一个字符表示具体的分数运算，然后是第一个分数的分子和分母，再然后是第二个分数的分子和分母。字符'a'表示分数加，'s'表示分数减法，'m'表示分数乘法，'d'表示分数除法。每组中的所有数据都是用空格分隔。

Output
多行，每行一个分数形式，样式是a/b（必须是最简分数形式，a是分子，b是分母），参见样例。

Sample Input
a 2 4  1 3
s 1 2  1 3
m 1 2 1 3
d 1 2 1 3
s 10 30  1 6

Sample Output
5/6
1/6
1/6
3/2
1/6
 */
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String mode = scanner.next();
            divNum a = new divNum(scanner.nextInt(),scanner.nextInt());
            divNum b = new divNum(scanner.nextInt(),scanner.nextInt());
            switch (mode){
                case "a":
                    a.add(b).print();
                    break;
                case "s":
                    a.minus(b).print();
                    break;
                case "m":
                    a.multiply(b).print();
                    break;
                case "d":
                    a.divide(b).print();
                    break;
            }
            System.out.println();
        }
    }
}

class divNum {
    int a, b;

    public divNum(int a, int b) {
        this.a = a;
        this.b = b;
        simplify();
    }

    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public divNum add(divNum b) {
        return new divNum(this.a * b.b + this.b * b.a, this.b * b.b).simplify();
    }

    public divNum minus(divNum b) {
        return new divNum(this.a * b.b - this.b * b.a, this.b * b.b).simplify();
    }

    public divNum multiply(divNum b) {
        return new divNum(this.a * b.a, this.b * b.b).simplify();
    }

    public divNum divide(divNum b) {
        return new divNum(this.a * b.b, this.b * b.a).simplify();
    }

    public divNum simplify() {
        int c = gcd(this.a, this.b);
        this.a = this.a / c;
        this.b = this.b / c;
        return this;
    }

    public void print() {
        System.out.printf("%d/%d", this.a, this.b);
    }
}
