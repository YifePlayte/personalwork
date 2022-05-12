class Trangle {
	double sideA, sideB, sideC, area, length;
	boolean boo;

	public Trangle(double a, double b, double c) {
		sideA = a;
		sideB = b;
		sideC = c;
		if (sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA) {
			boo = true;
		} else {
			boo = false;
		}
	}

	double getLength() {
		length = sideA + sideB + sideC;
		return length;
	}

	double getArea() {
		if (boo) {
			double p = (sideA + sideB + sideC) / 2.0;
			area = Math.sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
			return area;
		} else {
			System.out.println("不是一个三角形,不能计算面积");
			return 0;
		}
	}

	public void setABC(double a, double b, double c) {
		sideA = a;
		sideB = b;
		sideC = c;
		if (sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA) {
			boo = true;
		} else {
			boo = false;
		}
	}

}

class Lader {
	double above, bottom, height, area;

	Lader(double a, double b, double h) {
		above = a;
		bottom = b;
		height = h;
	}

	double getArea() {
		area = (above + bottom) * height / 2.0;
		return area;
	}

}

class Circle {
	double radius, area;

	Circle(double r) {
		radius = r;
	}

	double getArea() {
		area = Math.PI * radius * radius;
		return area;
	}

	double getLength() {
		return Math.PI * radius * 2.0;
	}

	void setRadius(double newRadius) {
		radius = newRadius;
	}

	double getRadius() {
		return radius;
	}

}

public class AreaAndLength {
	public static void main(String[] args) {
		double length, area;
		Circle circle;
		Trangle trangle;
		Lader lader;
		circle = new Circle(10);
		trangle = new Trangle(3, 4, 5);
		lader = new Lader(3, 4, 5);
		length = circle.getLength();
		System.out.println("圆的周长:"+length);
		area = circle.getArea();
		System.out.println("圆的面积:"+area);
		length = trangle.getLength();
		System.out.println("三角形的周长:"+length);
		area = trangle.getArea();
		System.out.println("三角形的面积:"+area);
		area = lader.getArea();
		System.out.println("梯形的面积:"+area);
		trangle.setABC(12,34,1);
		length = trangle.getLength();
		System.out.println("三角形的周长:"+length);
		area = trangle.getArea();
		System.out.println("三角形的面积:"+area);
		circle.setRadius(15);
		System.out.println("圆的半径:"+circle.getRadius());
		length = circle.getLength();
		System.out.println("圆的周长:"+length);
		area = circle.getArea();
		System.out.println("圆的面积:"+area);
	}

}
