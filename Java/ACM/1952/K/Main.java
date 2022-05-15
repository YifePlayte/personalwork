import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		Student s = new Student();
		Teacher t = new Teacher();
		while (cin.hasNextInt()) {
			if (cin.nextInt() == 1) {
				s.setIdNo(cin.next());
				s.setSNo(cin.next());
				s.setName(cin.next());
				s.setSex(cin.next());
				s.setAge(cin.nextInt());
				s.setDept(cin.next());
				s.setMGrade(cin.nextInt());
				s.setEGrade(cin.nextInt());
				s.setJGrade(cin.nextInt());
				s.printInfol();
			} else {
				t.setIdNo(cin.next());
				t.setTNo(cin.next());
				t.setName(cin.next());
				t.setSex(cin.next());
				t.setAge(cin.nextInt());
				t.setDept(cin.next());
				t.setJTitle(cin.next());
				t.setCNum(cin.nextInt());
				t.printInfol();
			}
		}
	}

}

class People {
	int age;
	String idNo, dept, name, sex;

	void printInfol() {
		System.out.println("People:" + idNo + " " + name + " " + sex + " " + age + " " + dept);
	}

	void setIdNo(String i) {
		idNo = i;
	}

	void setAge(int i) {
		age = i;
	}

	void setDept(String i) {
		dept = i;
	}

	void setName(String i) {
		name = i;
	}

	void setSex(String i) {
		sex = i;
	}

}

class Student extends People {
	int mGrade, eGrade, jGrade;
	String sNo;
	
	@Override
	void printInfol() {
		System.out.println("Student:" + idNo + " " + sNo + " " + name + " " + sex + " " + age + " " + dept + " " + mGrade + " " + eGrade + " " + jGrade);
	}

	void setSNo(String i) {
		sNo = i;
	}

	void setMGrade(int i) {
		mGrade = i;
	}

	void setEGrade(int i) {
		eGrade = i;
	}

	void setJGrade(int i) {
		jGrade = i;
	}

}

class Teacher extends People {
	int cNum;
	String tNo, jTitle;

	@Override
	void printInfol() {
		System.out.println("Teacher:" + idNo + " " + tNo + " " + name + " " + sex + " " + age + " " + dept + " " + jTitle + " " + cNum);
	}

	void setTNo(String i) {
		tNo = i;
	}

	void setJTitle(String i) {
		jTitle = i;
	}

	void setCNum(int i) {
		cNum = i;
	}

}
