class People {
	protected double weight, height;

	public void speakHello() {
		System.out.println("yayawawa");
	}

	public void averageHeight() {
		height = 173;
		System.out.println("average height: " + height);
	}

	public void averageWeight() {
		weight = 70;
		System.out.println("average weight: " + weight);
	}

}

class ChinaPeople extends People {
	@Override
	public void speakHello() {
		System.out.println("你好，吃了吗");
	}

	@Override
	public void averageHeight() {
		height = 168.78;
		System.out.printf("中国人的平均身高：%.2f厘米\n", height);
	}

	@Override
	public void averageWeight() {
		weight = 65;
		System.out.printf("中国人的平均体重：%.2f公斤\n", weight);
	}

	public void chinaKongfu() {
		System.out.println("坐如钟,站如松,睡如弓");
	}

}

class AmericanPeople extends People {
	@Override
	public void speakHello() {
		System.out.println("How do you do");
	}

	@Override
	public void averageHeight() {
		height = 170;
		System.out.printf("American people's average height: %.2f cm\n", height);
	}

	@Override
	public void averageWeight() {
		weight = 70;
		System.out.printf("American people's average weight: %.2f kg\n", weight);
	}

	public void americanBoxing() {
		System.out.println("直拳，勾拳");
	}

}

class BeijingPeople extends ChinaPeople {
	@Override
	public void speakHello() {
		System.out.println("您好");
	}

	@Override
	public void averageHeight() {
		height = 168.78;
		System.out.printf("北京人的平均身高：%.2f厘米\n", height);
	}

	@Override
	public void averageWeight() {
		weight = 65;
		System.out.printf("北京人的平均体重：%.2f公斤\n", weight);
	}

	public void beijingOpera() {
		System.out.println("可叹～～～");
	}

}

public class Example {
	public static void main(String[] args) {
		ChinaPeople chinaPeople = new ChinaPeople();
		AmericanPeople americanPeople = new AmericanPeople();
		BeijingPeople beijingPeople = new BeijingPeople();
		chinaPeople.speakHello();
		americanPeople.speakHello();
		beijingPeople.speakHello();
		chinaPeople.averageHeight();
		americanPeople.averageHeight();
		beijingPeople.averageHeight();
		chinaPeople.averageWeight();
		americanPeople.averageWeight();
		beijingPeople.averageWeight();
		chinaPeople.chinaKongfu();
		americanPeople.americanBoxing();
		beijingPeople.beijingOpera();
		beijingPeople.chinaKongfu();
	}

}
