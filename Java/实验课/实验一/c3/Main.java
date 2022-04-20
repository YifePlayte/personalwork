/****
运行环境：OpenJDK 1.8
运行方式，在此目录下开启终端，逐行运行以下命令：
javac Main.java
appletviewer Main.java
****/

import java.applet.*;
import java.awt.*;

public class Main extends Applet {
	public void paint(Graphics g) {
		g.setColor(Color.blue);
		g.drawString("很喜欢学习Java", 25, 50);
		g.setColor(Color.green);
		g.drawString("正在上Java实验课", 25, 70);
	}
}
/*
<applet code="Main.class" width="150" height="130"></applet>
*/
