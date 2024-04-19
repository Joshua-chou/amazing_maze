#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>

//#include<Mmsystem.h>
//#pragma comment(lib,"WINMM.LIB")
#define pace 1 //the length of each step is pace
enum get { right, left, up, down }pch;
//make a people
using namespace std;
struct PEOPLE
{
	int pcr[2];
	enum get pch;//zl's direction      receive  players' order
}heartzl;
void initGame()//produce a window and zeng long
{
	initgraph(600, 400);
	heartzl.pcr[0] = 50;
	heartzl.pcr[1] = 95;
}
void drawpeople()                                                                         //draw zenglong
{
	IMAGE people;
	loadimage(&people, _T("IMAGE"), _T("character"), 10, 10, 1);
	putimage(heartzl.pcr[0], heartzl.pcr[1], &people);
}
void drawstart()//开始界面
{

	setbkcolor(LIGHTGRAY);
	cleardevice();
	//标题
	settextcolor(BROWN);
	settextstyle(100, 0, _T("华文琥珀"), 0, 0, 0, false, false, false);
	TCHAR tl[] = _T("迷之宫");
	outtextxy(165, 80, tl);
	//开始
	float H = 200;		// 色相
	float S = 1;		// 饱和度
	float L = 0.51f;	    // 亮度
	int y;
	for (y = 240; y <= 290; y++)
	{
		L += 0.006f;
		setlinecolor(HSLtoRGB(H, S, L));
		line(267, y, 350, y);
	}//设置按钮
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(35, 0, _T("华文彩云"), 0, 0, 900, false, false, false);
	TCHAR st[] = _T("开始");
	outtextxy(275, 250, st);//设置文字
	//帮助，关于
	settextcolor(BLACK);
	settextstyle(20, 0, _T("黑体"), 0, 0, 0, false, true, false);
	TCHAR hp[] = _T("帮助");
	TCHAR ab[] = _T("关于");
	outtextxy(490, 350, hp);
	outtextxy(540, 350, ab);
	//版本
	TCHAR vs[] = _T("版本");
	settextstyle(12, 0, _T("黑体"), 0, 0, 0, true, true, false);
	outtextxy(20, 360, vs);
}
void drawhelp()
{
	cleardevice();
	settextcolor(BLACK);
	settextstyle(60, 0, _T("宋体"));
	TCHAR hp[] = _T("帮助");
	outtextxy(236, 30, hp);
	settextstyle(22, 0, _T("黑体"), 0, 0, 0, false, false, false);
	RECT h = { 150, 120, 450, 300 };
	RECT H = { 150, 245, 450, 400 };
	drawtext(_T("这是一款高端的迷宫游戏，\n\n你将扮演一位迷路的人，\n\n寻找回家的方向。"), &h, DT_CENTER);
	drawtext(_T("操作说明：← 向左\n          ↑ 向上\n          →  向右\n          ↓ 向下\n          按“Esc”退出游戏"), &H, DT_LEFT);
	//返回按钮
	settextcolor(BLACK);
	settextstyle(20, 0, _T("黑体"), 0, 0, 0, false, true, false);
	TCHAR rt[] = _T("返回");
	outtextxy(540, 350, rt);
}
void drawabout()
{
	cleardevice();
	settextstyle(60, 0, _T("宋体"));
	TCHAR ab[] = _T("关于");
	outtextxy(236, 30, ab);
	settextstyle(18, 0, _T("方正兰亭超细黑简体"), 0, 0, 0, false, false, false);
	RECT ab1 = { 200, 100, 450, 280 };
	drawtext(_T("策划：\n周爽\n内容设计：\n曾龙\n脚本：\n周爽、曾龙\n邮箱：\n1416727565@qq.com\n特别鸣谢：\n陈璟、曾鑫、曾宪求、陈博耀"), &ab1, DT_LEFT);
	RECT ab2 = { 200, 290, 400, 390 };
	drawtext(_T("      这是我们工作室第一次制作游戏，有些bug请大家见谅，后期我们会更新版本，进行优化，感谢您体验我们的游戏。"), &ab2, DT_WORDBREAK);
	//返回按钮	            
	settextcolor(BLACK);
	settextstyle(20, 0, _T("黑体"), 0, 0, 0, false, true, false);
	TCHAR rt[] = _T("返回");
	outtextxy(540, 350, rt);
}
void drawmaze()//draw the maze!!!!!!!!!!!
{
	//绘制墙体
	setbkcolor(LIGHTGRAY);
	cleardevice();
	IMAGE wall(15, 12);// 定义墙体填充单元
	// 绘制墙体填充单元
	setbkcolor(DARKGRAY);
	SetWorkingImage(&wall);	// 设置绘图目标为 wall 对象
	solidroundrect(2, 2, 13, 10, 1, 1);
	SetWorkingImage(NULL);	// 恢复绘图目标为默认绘图窗口
	setfillstyle(3, NULL, &wall);// 设置填充样式为wall
	settextcolor(BROWN);// 设置wall的填充颜色
	//绘制墙体
	solidrectangle(50, 110, 90, 350);//1
	solidrectangle(90, 310, 450, 350);//2
	solidrectangle(410, 50, 450, 290);//3
	solidrectangle(50, 50, 410, 90);//4
	solidrectangle(110, 90, 120, 140);//5
	solidrectangle(170, 90, 180, 140);//6
	solidrectangle(230, 90, 240, 140);//7
	solidrectangle(240, 110, 270, 120);//8
	solidrectangle(290, 90, 300, 170);//9
	solidrectangle(350, 90, 360, 170);//10
	solidrectangle(90, 160, 140, 170);//11
	solidrectangle(140, 110, 150, 190);//12
	solidrectangle(200, 110, 210, 200);//13
	solidrectangle(260, 140, 270, 190);//14
	solidrectangle(320, 110, 330, 190);//15
	solidrectangle(380, 110, 390, 190);//16
	solidrectangle(170, 160, 200, 170);//17
	solidrectangle(210, 160, 260, 170);//18
	solidrectangle(110, 190, 120, 220);//19
	solidrectangle(110, 220, 180, 230);//20
	solidrectangle(170, 170, 180, 220);//21
	solidrectangle(200, 220, 230, 230);//22
	solidrectangle(230, 190, 240, 280);//23
	solidrectangle(290, 200, 300, 280);//24
	solidrectangle(320, 220, 410, 230);//25
	solidrectangle(90, 250, 210, 260);//26
	solidrectangle(260, 220, 270, 310);//27
	solidrectangle(350, 250, 380, 260);//28
	solidrectangle(380, 250, 390, 280);//29
	solidrectangle(110, 280, 240, 290);//30
	solidrectangle(290, 280, 390, 290);//31
	solidrectangle(320, 230, 330, 260);//33
	solidrectangle(260, 190, 390, 200);//34
	//设定为固实填充
	setfillstyle(0);
	setfillcolor(DARKGRAY);
	//设置特殊墙
	fillroundrect(210, 253, 213, 257, 1, 1);
	fillroundrect(213, 251, 218, 259, 1, 1);
	fillroundrect(218, 253, 222, 257, 1, 1);
	fillroundrect(222, 251, 227, 259, 1, 1);
	fillroundrect(227, 253, 230, 257, 1, 1);
	fillroundrect(203, 290, 207, 293, 1, 1);
	fillroundrect(201, 293, 209, 298, 1, 1);
	fillroundrect(203, 298, 207, 302, 1, 1);
	fillroundrect(201, 302, 209, 307, 1, 1);
	fillroundrect(203, 307, 207, 310, 1, 1);
	setfillcolor(RED);
	//设置边框
	bar3d(35, 50, 40, 360, 3, 1);
	bar3d(35, 40, 450, 45, 3, 1);
	bar3d(455, 40, 460, 350, 3, 1);
	bar3d(45, 355, 460, 360, 3, 1);
	//设置出口
	setfillcolor(GREEN);
	POINT exit[] = { {430, 294},{430, 306},{450, 300} };
	fillpolygon(exit, 3);
	//设置游戏空白区
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(14, 0, _T("黑体"), 0, 0, 0, false, false, false);
	RECT H2 = { 472, 200, 600, 355 };
	drawtext(_T("操作说明：\n← 向左\n↑ 向上\n→或“D”向右\n↓ 向下\n按“Esc”退出游戏"), &H2, DT_LEFT);
}
//no hit
void alldirection()
{
	switch (heartzl.pch)
	{
	case up:
		heartzl.pcr[1] -= pace;
		break;
	case down:
		heartzl.pcr[1] += pace;
		break;
	case right:
		heartzl.pcr[0] += pace;
		break;
	case left:
		heartzl.pcr[0] -= pace;
		break;
	default:
		break;
	}
}
//hit the wall .......
void zs()
{
	switch (heartzl.pch)
	{
	case down:
		heartzl.pcr[1] += pace;
		break;
	case right:
		heartzl.pcr[0] += pace;
		break;
	default:
		break;
	}
}
void ys()
{
	switch (heartzl.pch)
	{
	case down:
		heartzl.pcr[1] += pace;
		break;
	case left:
		heartzl.pcr[0] -= pace;
		break;
	default:
		break;
	}
}
void zx()
{
	switch (heartzl.pch)
	{
	case up:
		heartzl.pcr[1] -= pace;
		break;
	case right:
		heartzl.pcr[0] += pace;
		break;
	default:
		break;
	}
}
void yx()
{
	switch (heartzl.pch)
	{
	case up:
		heartzl.pcr[1] -= pace;
		break;
	case left:
		heartzl.pcr[0] -= pace;
		break;
	default:
		break;
	}
}
void no_up()
{
	switch (heartzl.pch)
	{
	case down:
		heartzl.pcr[1] += pace;
		break;
	case right:
		heartzl.pcr[0] += pace;
		break;
	case left:
		heartzl.pcr[0] -= pace;
		break;
	default:
		break;
	}
}
void no_down()
{
	switch (heartzl.pch)
	{
	case up:
		heartzl.pcr[1] -= pace;
		break;
	case right:
		heartzl.pcr[0] += pace;
		break;
	case left:
		heartzl.pcr[0] -= pace;
		break;
	default:
		break;
	}
}
void no_left()
{
	switch (heartzl.pch)
	{
	case up:
		heartzl.pcr[1] -= pace;
		break;
	case down:
		heartzl.pcr[1] += pace;
		break;
	case right:
		heartzl.pcr[0] += pace;
		break;
	default:
		break;
	}
}
void no_right()
{
	switch (heartzl.pch)
	{
	case up:
		heartzl.pcr[1] -= pace;
		break;
	case down:
		heartzl.pcr[1] += pace;
		break;
	case left:
		heartzl.pcr[0] -= pace;
		break;
	default:
		break;
	}
}
void peoplemove(int k)//rules of move
{//que ding zeng long de wei zhi
	int x, y, n = 999;
	x = heartzl.pcr[0];
	y = heartzl.pcr[1];
	if (x >= 40 && y == 90)//                                         ceiling
		n = 0;
	if (x == 100 && y <= 140 && y >= 91)
		n = 1;
	if (x >= 100 && x <= 120 && y == 140)
		n = 2;
	if (x >= 40 && x <= 90 && y == 100)
		n = 3;
	if (x == 90 && y >= 100)//                                        left wall
		n = 4;
	if (x > 89 && y == 150 && x <= 130)
		n = 5;
	if (x == 130 && y <= 150 && y >= 100)
		n = 6;
	if (x == 120 && y <= 140)
		n = 7;
	if (x >= 130 && x <= 150 && y == 100)
		n = 8;
	if (x == 160 && y >= 90 && y <= 140)
		n = 9;
	if (x == 150 && y >= 100 && y <= 190)
		n = 10;
	if (x >= 160 && x <= 181 && y == 140)
		n = 11;
	if (x == 181 && y <= 140 && y >= 91)
		n = 12;
	if (y == 150 && x >= 160 && x <= 190)
		n = 13;
	if (x == 190 && y <= 200 && y >= 100)
		n = 14;
	if (y == 100 && x >= 190 && x <= 210)
		n = 15;
	if (x == 220 && y >= 90 && y <= 140)
		n = 16;
	if (x == 210 && y >= 100 && y <= 200)
		n = 17;
	if (y == 150 && x >= 210 && x <= 250)
		n = 18;
	if (y == 140 && x >= 220 && x <= 240)
		n = 19;
	if (x == 250 && y <= 200 && y >= 130)
		n = 20;
	if (y == 120 && x >= 240 && x <= 270)
		n = 21;
	if (x == 241 && y >= 120 && y <= 140)
		n = 22;
	if (y == 130 && x >= 250 && x <= 270)
		n = 23;
	if (x == 280 && y <= 170 && y >= 90)
		n = 24;
	if (x == 270 && y >= 100 && y <= 120)
		n = 25;
	if (x == 240 && y >= 90 && y <= 110)
		n = 26;
	if (y == 100 && x >= 240 && x <= 270)
		n = 27;
	if (x == 270 && y >= 130 && y <= 180)
		n = 28;
	if (y == 180 && x >= 270 && x <= 310)
		n = 29;
	if (y == 170 && x >= 280 && x <= 300)
		n = 30;
	if (x == 310 && y >= 100 && y <= 180)
		n = 31;
	if (x == 300 && y >= 90 && y <= 170)
		n = 32;
	if (y == 100 && x >= 310 && x <= 330)
		n = 33;
	if (x == 340 && y >= 90 && y <= 170)
		n = 34;
	if (x == 330 && y >= 100 && y <= 180)
		n = 35;
	if (y == 180 && x >= 270 && x <= 370)
		n = 36;
	if (y == 170 && x >= 340 && x <= 360)
		n = 37;
	if (x == 370 && y >= 100 && y <= 180)
		n = 38;
	if (x == 360 && y >= 90 && y <= 170)
		n = 39;
	if (y == 100 && x >= 370 && x <= 390)
		n = 40;
	if (x == 400 && y >= 90 && y <= 290)
		n = 41;
	if (x == 390 && y >= 100 && y <= 200)
		n = 42;
	if (y == 210 && x >= 310 && x <= 400)
		n = 43;
	if (y == 200 && x >= 250 && x <= 390)
		n = 44;
	if (x == 300 && y >= 200 && y <= 270)
		n = 45;
	if (x == 310 && y >= 220 && y <= 260)
		n = 46;
	if (y == 270 && x >= 300 && x <= 380)
		n = 47;
	if (y == 260 && x >= 310 && x <= 330)
		n = 48;
	if (x == 370 && y >= 260 && y <= 270)
		n = 49;
	if (y == 260 && x >= 340 && x <= 370)
		n = 50;
	if (x == 330 && y >= 230 && y <= 260)
		n = 51;
	if (x == 340 && y >= 240 && y <= 260)
		n = 52;
	if (y == 230 && x >= 320)
		n = 53;
	if (y == 240 && x >= 340 && x <= 390)
		n = 54;
	if (x == 390 && y >= 240 && y <= 290)
		n = 55;
	if (y == 290 && x >= 280 && x <= 390)
		n = 57;
	if (x == 270 && y >= 220)
		n = 59;
	if (x == 280 && y >= 200 && y <= 290)
		n = 60;
	if (y == 210 && x >= 250 && x <= 270)
		n = 61;
	if (x == 160 && y >= 160 && y <= 220)
		n = 62;
	if (y == 210 && x >= 120 && x <= 180)
		n = 63;
	if (y == 190 && x >= 130 && x <= 150)
		n = 64;
	if (x == 120 && y >= 180 && y <= 210)
		n = 65;
	if (x == 130 && y >= 170 && y <= 190)
		n = 66;
	if (y == 170 && x <= 130)
		n = 67;
	if (y == 180 && x >= 100 && x <= 120)
		n = 68;
	if (x == 100 && y >= 180 && y <= 230)
		n = 69;
	if (y == 240 && x <= 220)
		n = 70;
	if (y == 230 && x >= 100 && x <= 180)
		n = 71;
	if (x == 180 && y >= 170 && y <= 230)
		n = 72;
	if (x == 190 && y >= 210 && y <= 230)
		n = 73;
	if (y == 170 && x >= 180 && x <= 250)
		n = 74;
	if (y == 200 && x >= 190 && x <= 210)
		n = 75;
	if (y == 210 && x >= 190 && x < 220)
		n = 76;
	if (x == 220 && y >= 180 && y <= 270)
		n = 77;
	if (y == 180 && x >= 220 && x <= 240)
		n = 78;
	if (x == 240 && y >= 190 && y <= 290)
		n = 79;
	if (x == 250 && y >= 210)
		n = 80;
	if (y == 290 && x >= 100 && x <= 240)
		n = 81;
	if (x == 210 && y >= 290 && y <= 300)
		n = 82;
	if (x == 210 && y >= 240 && y <= 260)
		n = 83;
	if (y == 270 && x >= 100 && x < 220)
		n = 84;
	if (y == 260 && x > 90 && x < 220)
		n = 85;
	if (x == 100 && y >= 270 && y <= 290)
		n = 86;
	if (y == 290 && x > 200 && x <= 240)
		n = 87;
	if (x == 90 && y == 260)
		n = 88;
	if (x == 90 && y == 300)
		n = 89;
	if (x == 190 && y == 290)
		n = 90;
	if (x == 190 && y == 300)
		n = 91;
	if (x == 90 && y == 240)
		n = 92;
	if (x == 220 && y == 270)
		n = 93;
	if (x == 220 && y == 240)
		n = 94;
	if (x == 90 && y == 240)
		n = 95;
	if (x == 220 && y == 230)
		n = 96;
	if (y == 230 && x >= 190 && x < 220)
		n = 97;
	if (x == 120 && y == 210)
		n = 98;
	if (x == 160 && y == 210)
		n = 99;
	if (x == 220 && y == 210)
		n = 100;
	if (x == 90 && y == 170)
		n = 101;
	if (x == 130 && y == 170)
		n = 102;
	if (x == 180 && y == 170)
		n = 103;
	if (x == 190 && y == 170)
		n = 104;
	if (x == 210 && y == 170)
		n = 105;
	if (x == 90 && y == 150)
		n = 106;
	if (x == 130 && y == 150)
		n = 107;
	if (x == 190 && y == 150)
		n = 108;
	if (x == 100 && y == 90)
		n = 109;
	if (x == 120 && y == 90)
		n = 110;
	if (x == 160 && y == 90)
		n = 111;
	if (x == 180 && y == 90)
		n = 112;
	if (x == 140 && y == 110)
		n = 113;
	if (x == 210 && y == 150)
		n = 114;
	if (x == 250 && y == 150)
		n = 115;
	if (x == 240 && y == 120)
		n = 116;
	if (x == 240 && y == 100)
		n = 117;
	if (x == 240 && y == 90)
		n = 118;
	if (x == 280 && y == 90)
		n = 119;
	if (x == 270 && y == 180)
		n = 120;
	if (x == 310 && y == 180)
		n = 121;
	if (x == 300 && y == 90)
		n = 122;
	if (x == 340 && y == 90)
		n = 123;
	if (x == 330 && y == 180)
		n = 124;
	if (x == 370 && y == 180)
		n = 125;
	if (x == 360 && y == 90)
		n = 126;
	if (x == 400 && y == 90)
		n = 127;
	if (x == 400 && x == 210)
		n = 128;
	if (x == 300 && y == 200)
		n = 129;
	if (x == 300 && y == 270)
		n = 130;
	if (x == 370 && y == 270)
		n = 131;
	if (x == 370 && y == 260)
		n = 132;
	if (x == 330 && y == 230)
		n = 133;
	if (x == 400 && y == 230)
		n = 134;
	if (x == 270 && y == 300)
		n = 135;
	if (x == 280 && y == 200)
		n = 136;
	if (x == 250 && y == 170)
		n = 137;
	if (x == 250 && y == 300)
		n = 138;
	if (x == 50 && y > 90 && y < 100)
		n = 139;
	if (x == 50 && y == 90)
		n = 140;
	if (x == 50 && y == 100)
		n = 141;
	if (y >= 290 && y <= 300 && x == 400)
	{
		if (k == 1)
		{
			if (y == 300)
				n = 56;
			if (y == 290 && x >= 400)
				n = 58;
		}
		else
		{
			if (x == 400 && y == 300)
				n = 143;
			else
				n = 144;
		}
	}

	switch (n) {
	case 0:
		no_up();
		break;
	case 1:
		no_right();
		break;
	case 2:
		no_up();
		break;
	case 3:
		no_down();
		break;
	case 4:
		no_left();
		break;
	case 5:
		no_down();
		break;
	case 6:
		no_right();
		break;
	case 7:
		no_left();
		break;
	case 8:
		no_down();
		break;
	case 9:
		no_right();
		break;
	case 10:
		no_left();
		break;
	case 11:
		no_up();
		break;
	case 12:
		no_left();
		break;
	case 13:
		no_down();
		break;
	case 14:
		no_right();
		break;
	case 15:
		no_down();
		break;
	case 16:
		no_right();
		break;
	case 17:
		no_left();
		break;
	case 18:
		no_down();
		break;
	case 19:
		no_up();
		break;
	case 20:
		no_right();
		break;
	case 21:
		no_up();
		break;
	case 22:
		no_left();
		break;
	case 23:
		no_down();
		break;
	case 24:
		no_right();
		break;
	case 25:
		no_left();
		break;
	case 26:
		no_left();
		break;
	case 27:
		no_down();
		break;
	case 28:
		no_left();
		break;
	case 29:
		no_down();
		break;
	case 30:
		no_up();
		break;
	case 31:
		no_right();
		break;
	case 32:
		no_left();
		break;
	case 33:
		no_down();
		break;
	case 34:
		no_right();
		break;
	case 35:
		no_left();
		break;
	case 36:
		no_down();
		break;
	case 37:
		no_up();
		break;
	case 38:
		no_right();
		break;
	case 39:
		no_left();
		break;
	case 40:
		no_down();
		break;
	case 41:
		no_right();
		break;
	case 42:
		no_left();
		break;
	case 43:
		no_down();
		break;
	case 44:
		no_up();
		break;
	case 45:
		no_left();
		break;
	case 46:
		no_right();
		break;
	case 47:
		no_down();
		break;
	case 48:
		no_up();
		break;
	case 49:
		no_right();
		break;
	case 50:
		no_up();
		break;
	case 51:
		no_left();
		break;
	case 52:
		no_right();
		break;
	case 53:
		no_up();
		break;
	case 54:
		no_down();
		break;
	case 55:
		no_left();
		break;
	case 56:
		no_down();
		break;
	case 57:
		no_up();
		break;
	case 58:
		no_up();
		break;
	case 59:
		no_left();
		break;
	case 60:
		no_right();
		break;
	case 61:
		no_down();
		break;
	case 62:
		no_right();
		break;
	case 63:
		no_down();
		break;
	case 64:
		no_up();
		break;
	case 65:
		no_left();
		break;
	case 66:
		no_right();
		break;
	case 67:
		no_up();
		break;
	case 68:
		no_down();
		break;
	case 69:
		no_right();
		break;

	case 70:
		no_down();
		break;
	case 71:
		no_up();
		break;
	case 72:
		no_left();
		break;
	case 73:
		no_right();
		break;
	case 74:
		no_up();
		break;
	case 75:
		no_up();
		break;
	case 76:
		no_down();
		break;
	case 77:
		no_right();
		break;
	case 78:
		no_down();
		break;
	case 79:
		no_left();
		break;
	case 80:
		no_right();
		break;
	case 81:
		no_up();
		break;
	case 82:
		no_right();
		break;
	case 83:
		no_left();
		break;
	case 84:
		no_down();
		break;
	case 85:
		no_up();
		break;
	case 86:
		no_right();
		break;
	case 87:
		no_up();
		break;
	case 88:
		zs();
		break;
	case 89:
		zx();
		break;
	case 90:
		ys();
		break;
	case 91:
		yx();
		break;
	case 92:
		zx();
		break;
	case 93:
		yx();
		break;
	case 94:
		yx();
		break;
	case 95:
		zx();
		break;
	case 96:
		ys();
		break;
	case 97:
		no_up();
		break;
	case 98:
		zx();
		break;
	case 99:
		yx();
		break;
	case 100:
		yx();
		break;
	case 101:
		zs();
		break;
	case 102:
		ys();
		break;
	case 103:
		zs();
		break;
	case 104:
		ys();
		break;
	case 105:
		zs();
		break;
	case 106:
		zx();
		break;
	case 107:
		yx();
		break;
	case 108:
		yx();
		break;
	case 109:
		ys();
		break;
	case 110:
		zs();
		break;
	case 111:
		ys();
		break;
	case 112:
		zs();
		break;
	case 113:
		ys();
		break;
	case 114:
		zx();
		break;
	case 115:
		yx();
		break;
	case 116:
		zs();
		break;
	case 117:
		zx();
		break;
	case 118:
		zs();
		break;
	case 119:
		ys();
		break;
	case 120:
		zx();
		break;
	case 121:
		yx();
		break;
	case 122:
		zs();
		break;
	case 123:
		ys();
		break;
	case 124:
		zx();
		break;
	case 125:
		yx();
		break;
	case 126:
		zs();
		break;
	case 127:
		ys();
		break;
	case 128:
		yx();
		break;
	case 129:
		zs();
		break;
	case 130:
		zx();
		break;
	case 131:
		yx();
		break;
	case 132:
		ys();
		break;
	case 133:
		zs();
		break;
	case 134:
		ys();
		break;
	case 135:
		zx();
		break;
	case 136:
		ys();
		break;
	case 137:
		ys();
		break;
	case 138:
		yx();
		break;
	case 139:
		no_left();
		break;
	case 140:
		zs();
		break;
	case 141:
		zx();
		break;
	case 142:
		alldirection();
		break;
	case 143:
		yx();
		break;
	case 144:
		no_right();
		break;
	default:
		alldirection();
		break;

	}
}
void controlzl()
{
	char con;
	con = _getch();
	switch (con)
	{
	case 72:
		heartzl.pch = up;
		break;
	case 80:
		heartzl.pch = down;
		break;
	case 75:
		heartzl.pch = left;
		break;
	case 77:
		heartzl.pch = right;
		break;
	default:
		break;
	}
	while (_kbhit())//清除键盘输入缓存
	{
		_getch();
	}
}
int box()
{
	setfillcolor(BROWN);
	POINT box1[] = { {90, 262},{90, 270},{100, 270},{100, 262},{98, 260},{92,260} };
	fillpolygon(box1, 6);
	setfillcolor(YELLOW);
	POINT box2[] = { {90, 264},{90, 266},{100, 266},{100, 264},{96, 264},{96, 260},{94, 260},{94, 264} };
	solidpolygon(box2, 8);
	setfillcolor(DARKGRAY);
	solidrectangle(94, 265, 96, 267);
	return 1;
}
void victory()
{
	setfillcolor(YELLOW);
	fillrectangle(472, 50, 590, 150);
	setbkmode(TRANSPARENT);
	settextcolor(BLUE);
	settextstyle(50, 0, _T("华文行楷"), 0, 0, 0, false, false, false);
	RECT V = { 472, 50, 600, 200 };
	drawtext(_T("成功\n逃出！"), &V, DT_LEFT);
}
void findkey()
{
	setfillcolor(YELLOW);
	setbkmode(TRANSPARENT);
	fillrectangle(472, 50, 590, 150);
	settextcolor(RED);
	settextstyle(35, 0, _T("华文行楷"), 0, 0, 0, false, false, false);
	RECT V = { 472, 50, 600, 200 };
	drawtext(_T("出口\n好像\n上锁了！"), &V, DT_LEFT);
}
void getkey()
{
	setfillcolor(YELLOW);
	setbkmode(TRANSPARENT);
	fillrectangle(472, 50, 590, 180);
	settextstyle(32, 0, _T("华文行楷"), 0, 0, 0, false, false, false);
	RECT G = { 472, 50, 600, 200 };
	drawtext(_T("这箱子\n。。？\n啊！一把\n钥匙！"), &G, DT_LEFT);
}
int main()
{
	bool a;
	int k = 0;
	int x, y;
	initgraph(600, 400);
loop:drawstart();
	//PlaySound(NULL,NULL,NULL);
	//PlaySound("C:\\Users\\ASUS\\Desktop\\bgm\\迷之宫bgm3.wav",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
	//鼠标控制开始界面
	MOUSEMSG s;
	MOUSEMSG r;
	a = MouseHit();//通用判断是否有鼠标缓存的变量
	do {
		s = GetMouseMsg();
		if (s.x <= 350 && s.x >= 267 && s.y <= 290 && s.y >= 240)//“开始”判断
		{
			switch (s.uMsg)
			{
			case WM_LBUTTONDOWN:
				//PlaySound(NULL, NULL, NULL);
				//PlaySound((LPCTSTR)"bgm2", GetModuleHandle(0), SND_RESOURCE | SND_ASYNC | SND_LOOP);
				initGame();
				drawmaze();
				drawpeople();
				FlushMouseMsgBuffer();
				a = MouseHit();
				while (_kbhit())//清除键盘输入缓存
				{
					_getch();
				}
				while (1)
				{

					while (_kbhit())
					{
						if (_getch() == 27)
						{
							goto loop;
						}
						//PlaySound(NULL, NULL, NULL);
						//PlaySound((LPCTSTR)"bgm1", GetModuleHandle(0), SND_RESOURCE | SND_ASYNC | SND_LOOP);
						x = heartzl.pcr[0];
						y = heartzl.pcr[1];
						controlzl();
						peoplemove(k);
						drawmaze();
						drawpeople();
						if (x <= 100 && x >= 90 && y <= 270 && y >= 260)
						{
							k = box();
							getkey();
						}
						if (x >= 400 && y > 291 && y < 300)
						{
							if (k == 1)
								victory();
							else
								findkey();
						}
					}
				}
			}
		}
		if (s.x <= 530 && s.x >= 490 && s.y <= 370 && s.y >= 350)//“帮助”判断
		{
			switch (s.uMsg)
			{
			case WM_LBUTTONDOWN:
				drawhelp();
				FlushMouseMsgBuffer();
				a = MouseHit();
				do {
					r = GetMouseMsg();
					if (r.x <= 580 && r.x >= 540 && r.y <= 370 && r.y >= 350)
					{
						switch (r.uMsg)
						{
						case WM_LBUTTONDOWN:
							FlushMouseMsgBuffer();
							goto loop;
						}
					}
					FlushMouseMsgBuffer();
					a = MouseHit();
				} while (a == false);
			}
		}
		if (s.x <= 580 && s.x >= 540 && s.y <= 370 && s.y >= 350)//“关于”判断
		{
			switch (s.uMsg)
			{
			case WM_LBUTTONDOWN:
				drawabout();
				FlushMouseMsgBuffer();
				a = MouseHit();
				do {
					r = GetMouseMsg();
					if (r.x <= 580 && r.x >= 540 && r.y <= 370 && r.y >= 350)
					{
						switch (r.uMsg)
						{
						case WM_LBUTTONDOWN:
							FlushMouseMsgBuffer();
							goto loop;
						}
					}
					FlushMouseMsgBuffer();
					a = MouseHit();
				} while (a == false);
			}
		}
		FlushMouseMsgBuffer();
		a = MouseHit();
	} while (a == false);
	_getch();              // 按任意键继续
	closegraph();          // 关闭绘图窗口

}
