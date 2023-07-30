#include<graphics.h>
#include<stdio.h>
#include<unistd.h>
#include<windows.h>
void displayendWindow(int s);
void myname()
{    int p=85,q=90;
     setcolor(BLUE); 
	//mathi ko line 
    line(65+p,100+q,380+p,100+q); 
	//ba ko danda
	setcolor(YELLOW);
	line(165+p,100+q,165+p,200+q);
	line(110+p,137+q,158+p,167+q);   
	//ba ko golo
	circle(135+p,150+q,30);
    //be ikar ko danda
    setcolor(GREEN);
    line(90+p,100+q,90+p,200+q);
    //pi ko ikar ko danda
    setcolor(MAGENTA);
    line(185+p,100+q,185+p,200+q);
    //pa ko lagi 3 line
     setcolor(CYAN);
    line(200+p,100+q,200+p,140+q);
   // line(200,150,260,150);
    arc(230+p,140+q,180,0,30);
    line(260+p,100+q,260+p,200+q);
    //na ko lagi 2 ta line 
    setcolor(BROWN);
    line(285+p,150+q,340+p,150+q);
    line(340+p,100+q,340+p,200+q);
    //na ko circle
    circle(285+p,160+q,10);
    //mathi ikar ko arc
    setcolor(GREEN);
     arc(128+p,100+q,0,180,38); 
     setcolor(MAGENTA);
	 arc(223+p,100+q,0,180,38); 
	 setcolor(WHITE);
}
void displayStartWindow()
 {
    int gd = DETECT, gm,a,b,c,xx,i ;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); 
    cleardevice();
    myname();
    setcolor(LIGHTGREEN);
    outtextxy(285,340, "Play");
    setcolor(LIGHTBLUE);
    rectangle(250,320,350,370); // Play button
     setcolor(WHITE);
     for(i=0;i<=35;i++)
	 {   a=rand()%600;
        b=rand()%400;
        c=rand()%20;
        xx=rand()%16;
        delay(100);
        if((a<250||a>350)&&(b<320||b>370))
        {
    	setfillstyle(HATCH_FILL,xx);
        circle(a,b,c);
        floodfill(a,b,WHITE);
	    }
	}
	int x, y;
    while (1) 
	{
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x >= 250 && x <= 350 && y >= 320 && y <= 370) {
                break;
            }
        }
    }
    closegraph();
}
void playGame()
 {
  	int x1=50,y1=50,i=17,j=17,x=0,y=0,r=5,s=0,a=0,ch,gd=DETECT,xx,gm,p,q;
    initgraph(&gd,&gm,"c:\\TURBOC3\\BGI"); 
    int page=0;
    char buffer[10];
while(1)
{   
   setactivepage(page);//this is for the flickering probelm
   setvisualpage(1-page); 
   cleardevice();
   rectangle(3,3,635,450);//the outside boundary(yeslai choyesi gameover hunchaa)
   rectangle(5,5,633,448);
   setfillstyle(SOLID_FILL,xx);
   circle(x1,y1,7);
   floodfill(x1,y1, WHITE);
   setcolor(WHITE);
   circle(i,j,r); 
   setfillstyle(HATCH_FILL,RED); 
   floodfill(i,j, WHITE);
   setcolor(RED);
   outtextxy(10,460,"Press Esc to Exit");
   setcolor(WHITE);
   setcolor(LIGHTBLUE);
   outtextxy(200,460,"Hungry circle by Bipin Poudel");
   setcolor(WHITE);
   setcolor(LIGHTGREEN);
   sprintf(buffer,"%d", s);     //outtextxy le character matra lincha so p lai char ma change gareko 
   outtextxy(560,460,"Score:");
   setcolor(WHITE);
   outtextxy(603,460,buffer);    //yele score dekhaucha
   if(kbhit())                                            //check if a key is pressed
   {
    ch=getch();
    if(ch=='w'||ch==72)                           //move upward (75 72 77 80)
    {
        x=0;
        y=-1;
    }
    if(ch=='a'||ch==75)                           //move left
    {
        x=-1;
        y=0;
    }
    if(ch=='d'||ch==77)                           //move right
    {
     x=1;
     y=0;
    }
    if(ch=='s'||ch==80)                           //move downward
    {
    x=0;
    y=1;
    } 
    if(ch==27)                           //exit when esc key pressed
    {
	exit(0);
    }
}
    i=i+x;
    j=j+y;
    usleep(10000-a);          // delay use garda millisecond ma matra time ghatauna milyo yele micro ma milcha
if((i+r>=x1-7&&i-r<=x1+7) && (j+r>=y1-7&&j-r<=y1+7))  //condition to generate random circles
   { Beep(700,80);
    printf("\a");
    x1=rand()%620 + 17;
    y1=rand()%430 + 17;
    r=r+2;
    s=s+1;
    a=a+400;
    xx=rand()%16;
   }
if (i==5+r||j==5+r||i==633-r||j==448-r)         // condition when the ball hits the wall 
   {   printf("Game over!!!\n");
        printf("your score is %d\n",s); 
        displayendWindow(s);
    //	exit(0);
   }
  page=1-page;                                  // for the flickering problem
}
}
void displayendWindow( int s)
 {
    int gd = DETECT, gm,a,b,c,xx,i ;
    char buffer[10];
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); 
    cleardevice();
    setcolor(LIGHTGREEN);
    outtextxy(275,340, "Try again");
    setcolor(LIGHTGREEN);
    sprintf(buffer,"%d",s);
    outtextxy(350,220,buffer);
    outtextxy(250,220,"Your score is:");
    settextstyle(1,0,5);
    setcolor(GREEN);
    outtextxy(135,130,"Game over");
    setcolor(LIGHTBLUE);
    rectangle(250,320,350,370); // game over button
    setcolor(WHITE);
    int x, y;
    while (1) 
	{
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x >= 250 && x <= 350 && y >= 320 && y <= 370) {
                playGame();
            }
        }
    }
    closegraph();
}
int main()
 {
    displayStartWindow();
    playGame();
    return 0;
}

