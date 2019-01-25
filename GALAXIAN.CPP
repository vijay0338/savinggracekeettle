/***************************************************************/

  #include <stdio.h>
  #include <conio.h>
  #include <graphics.h>
  #include <dos.h>
  #include <stdlib.h>
  #define N 5
  #define M 8

/***************************************************************/
 void intro();
 void esh_();
 void eraseintro(int i);
 void enemy();
 void setone();
 void you();
 void eraseyou();
 int check_shoot(int i,int xx);
 void move();
 void emoving();
 void eraseenemy();
 void winner();
 int shoot();
 void e_name();
 void irgun();
 void score();
 void round();
 void gameover();
 void procent();
 void enemycenter();
 void eshoot();
 void eshmove(int i, int j);
 void justcount();
 void walls();
 void erasewalls(int color);
 void up();
 void enemyhelp();
 int e[N*2][M+1];     int back=0, bs=295,bx,bsh;
 int x=300;           int u=0;
 int kivun=1;         int st=0;
 int name[3];         int wall=0;
 int a=20,z=620;      int xx2=11,xx3=619,yy=300;
 int number;          int call=M*N;
 int aa=0,zz=M-1;     int ess[2];
 int scorr=0;         int i_sh=0, i_k=0;
 int roun_d=0;        char c_sh[2],c_k[2];
 char scor[7];        int num;
 char r0und[2];       char cnum[2];
 int esh, n1,n2;      int gova,g=0;
 int ck=0,m,n;        int ex=5,ea=5,ez=560,zu=0;
/***************************************************************/

 void main()
 {  int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "c:/borlandc/bgi");
    cleardevice();
    setbkcolor(0);
    intro();
    setone();
    enemy();
    you();
    move();
 }


 void checkback()
 { int i;
   for (i=x;i<x+21;i++)
   if (i==bx)
   gameover();
 }

 void backshoot()
 {  if (bs+2>=430 && bs-2<=430)
    { setcolor(0);  bsh=0; line (bx,bs-2,bx,bs+2); checkback(); back=0; bs=300; move(); }
    setcolor(0);  line (bx,bs-2,bx,bs+2);
    setcolor(15); line (bx,bs+=2,bx,bs);
 }



 void enemyhelp()
 { setfillstyle(0,0);
   bar(ex-3,243,ex+83,227);
   setfillstyle (6,6);
   if (ex==ez)
   { ex--; zu=1; } else if (ex==ea) { ex++; zu=0; } else if (zu==1) ex--; else ex++;
   bar (ex,240,ex+80,230);
 }



 void enemycenter()
 { int i,j;
   randomize();
   for (i=0;i<N;i++)
   for(j=0;j<M;j++)
   if (e[i][j]!=0) break;
   if (i==N-1 && j==M-1)
   setone();
   esh=rand();
   if (esh%2!=0  || esh%3==0)
   eshoot();
   else wall=1;
 }


 void walls()
 {  erasewalls(0);
    char ch;
    if(yy>380) st=-1;
    if (yy>442)
    { xx2=11; xx3=619; yy=300; number=0; wall=0; st=0; emoving(); move(); }
    else
    if (yy>420)
    if ( (x<=xx2 && x+20>=xx2) || (x<=xx3 && x+20>=xx3) )
    gameover();
    wall=1;
    if (xx2<180  && yy==300)
    { xx2++; xx3--; }
    else { yy++;
    if (x+10>xx2) xx2++; else xx2--;
    if (x+10>xx3) xx3++; else xx3--;
	 }
    erasewalls(14);
 }

 void erasewalls ( int color)
 {  setcolor (color);
    circle (xx2,yy,2);
    circle (xx3+10,yy,2);
 }


 void eshoot()
 { int i;
   for (;;)
    { n1=random (N);  n2=random (M);
      if (e[n1][n2]!=0)
      break;
    }
    e[n1][n2]=2;
 }

 void eshmove(int i, int j)
 {  int c;
    ck++; g=1;
    if(ess[1]<430)    {
    if (ess[0]<x+10)  ess[0]++; else if (ess[0]>x+10) ess[0]--;
    if ( (ess[1]<222 && ess[1]+5>222) && (ess[0]-90<ex && ess[0]+15>ex)); else
    ess[1]+=2;
      setfillstyle(1,0);
      bar(ess[0]-9,ess[1]-9,ess[0]+9,ess[1]+9);
      setfillstyle(4,i+11);
      fillellipse(ess[0],ess[1], 7, 7);
    }
    else {
    if (ess[0]+20>x && ess[0]-20<x) gameover();;
    e[i][j]=1; if (i==0) e[i+N][j]=e[i+N+1][j]; else  e[i+N][j]=e[i+N-1][j];
    ess[0]=0 ; ess[1]=0; g=0;
    setcolor(0);
    for (c=3;c<648;c++)
    line (c,441,c,410);
    ck=0;
    you();
    }
    if(i==-11)
    {  setfillstyle(0,0);  bar(ess[0]-9,ess[1]-9,ess[0]+9,ess[1]+9); }
 }


 void winner()
  { int x,y,g,i;
    cleardevice();
    randomize();
    for(;;)
    {   x=random(640);
	y=random(480);
	g=random(100);
      setcolor (random(15));
      for (i=1;i<g;i++)
      circle (x,y,i);
    }
   }



 void procent()
 {  int i;
    setcolor (0);
    for (i=560;i<610;i++)
    line (i,448,i,480);
    num=(i_k*100/i_sh);
    itoa(num,cnum,10);
    setcolor(14);
    settextstyle(1,HORIZ_DIR,1);
    outtextxy(560,448,cnum);
 }

 void round()
 { int i;
   setcolor(0);
   settextstyle(1,HORIZ_DIR,2);
   outtextxy(273,448,r0und);
   roun_d++;
   if (roun_d==11)
   winner();
   itoa (roun_d,r0und,10);
   setcolor (14);
   settextstyle (9,HORIZ_DIR,4);
   outtextxy( 310,200,r0und);
   delay (3000);
   setcolor (0);
   for (i=20;i<300;i++)
   line (20,i,620,i);  setcolor(14);
   settextstyle(1,HORIZ_DIR,2);
   outtextxy(273,448,r0und);
   outtextxy(180,448,"Round :");
   outtextxy(610,448,"%");
 }


 void score()
 { int i,j,count;
   int q=1; if (g==2) { g=0; q=2; }
   setcolor (0);
   settextstyle(1,HORIZ_DIR,2);
   itoa (scorr,scor,10);
   outtextxy(30,448,scor);
   for (i=0;i<N;i++)
   {
   for (count=0,j=0;j<M;j++)
   if (e[i][j]==1) count++;
   if (count!=e[i][M])
   { scorr+=(100-i*20)*q; e[i][M]--; break; }
   }
   setcolor (14);
   itoa (scorr,scor,10);
   settextstyle(1,HORIZ_DIR,2);
   outtextxy(30,448,scor);
 }


 void intro()
 { int i,num;
   for (i=0;i<640;i++)
   { line (i,0,i,15);
     line (i,480,i,465); }
   setcolor (14);
   settextstyle (4,HORIZ_DIR,8);
   outtextxy (75,50,"GALAXIAN 2");
   settextstyle(3,HORIZ_DIR,3);
   outtextxy(210,20,"made by SERGUKI");
   for (i=450;i>200;i--)
   {
   setcolor(15);
   line (x,i,x,i-20);
   line (x+20,i,x+20,i-20);
   line (x,i-20,x+10,i-30);
   line (x+20,i-20,x+10,i-30);
   line (x,i,x+20,i);
   delay (4);
   if (i==201)
   delay (1000);
   eraseintro(i);
   }
   settextstyle(1,HORIZ_DIR,1);
   for (i=11;i<16;i++)
   { delay (1);
     setcolor (i);
     circle (240,i*30-(i-11)-150,7);
     outtextxy(247,i*29-(i-11)-150,"  -");
     outtextxy(350,i*29-(i-11)-150,"pts");
   }
   setcolor (11);
   outtextxy(294,172,"100"); setcolor (12);
   outtextxy(299,200,"80"); setcolor (13);
   outtextxy(299,228,"60"); setcolor (14);
   outtextxy(299,256,"40"); setcolor (15);
   outtextxy(299,284,"20"); setcolor (7);
   outtextxy(232,312,"Fly  *  2    pts"); setcolor (14);
   settextstyle(8,HORIZ_DIR,1);
   outtextxy(30,400,"10 rounds ; controls: 4,5,6 ; Good Luck & Have Fun");
   getch(); setcolor(0);
   for (i=0;i<481;i++)
   { delay (3);
     line (0,i,640,i);
   }
   delay (1400); setcolor (14);
   setcolor (14);
   line (0,441,640,441);
   line (0,479,640,479);
   line (0,479,0,0);
   line (639,479,639,0);
   line (0,0,640,0);
   line (155,442,155,480);
   line (310,442,310,480);
   line (540,442,540,480);
   line (1,300,10,300);
   line (639,300,629,300);
 }

 void eraseintro(int i)
 { setcolor(0);
   line (x,i,x,i-20);
   line (x+20,i,x+20,i-20);
   line (x,i-20,x+10,i-30);
   line (x+20,i-20,x+10,i-30);
   line (x,i,x+20,i);
 }

 void setone()
 { int i,j;
   a=20; z=620; aa=0; zz=M-1;
   for (i=0;i<N;i++)
   { e[i][M]=M;
   for (j=0;j<M;j++)
    {  e[i][j]=1; e[i+N][j]=j*65+65;  }
   }
   round(); setcolor(14);
   settextstyle(1,HORIZ_DIR,2);
   outtextxy(273,448,r0und);
   outtextxy(330,448,"S/K:        ");
   line (457,480,470,442);
 }

 void irgun()
 {  int b,i,j,count;
    for (i=0;i<N;i++)
    if (e[i][aa]!=0)
    break;
    if (i==N)
    {  a-=65; aa++; }
    for(i=0;i<N+1;i++)
    if (e[i][zz]!=0)
    break;
    if (i==N)
    {  z+=65; zz--; }
    for (call=0,count=0,i=0;i<N;i++)
    for (j=0;j<M;j++)
    {  if (e[i][j]!=1) call++ ; count+=e[i][j];  }
    if (count==0)
    setone();

  }

 void enemy()
 {  int i,j;
   setcolor (14);
   line (0,441,640,441);
   line (0,479,640,479);
   line (0,479,0,0);
   line (639,479,639,0);
    for (i=0;i<N;i++)
     { setcolor (i+11);
       for (j=0;j<M;j++)
      { if (e[i][j]==2)
	{ if (g==0 || e[0]==0) { ess[0] = e[i+N][j], ess[1]=i*30+30; }  eshmove(i,j); }
      else if (e[i][j]==1)
      circle (e[i+N][j],i*30+30, 6);
      }
     setcolor(14); line (0,0,640,0);
     }
 }

 void eraseenemy()
 {  int i,j;
    setcolor (14);
   line (0,441,640,441);
   line (0,479,640,479);
   line (0,479,0,0);
   line (639,479,639,0);
    setcolor(0);
    for (i=0;i<N;i++)
      for (j=0;j<M;j++)
      circle ( e[i+N][j],i*30+30, 7);
 }


 void emoving()
 { int i,j;
   eraseenemy();
   if (e[N+1][0]==a)
   kivun=1;
   else if (e[N+1][M-1]==z)
   kivun=-1;
   enemy();
   delay (10);
   enemyhelp();
   if (back==1)
   backshoot();
   for (i=N;i<N*2;i++)
    for (j=0;j<M;j++)
    e[i][j]+=kivun;
   if (wall==1)  walls();
   else {
   if (ck==0) number++;
   if (ck==0 && number==130-roun_d*10)
   { enemycenter(); number=0;}   }
 }




 void you()
 {  setcolor (15);
   line (x,440,x,420);
   line (x+20,440,x+20,420);
   line (x,420,x+10,410);
   line (x+20,420,x+10,410);
 }


 void eraseyou()
 {  setcolor(0);
   line (x,440,x,420);
   line (x+20,440,x+20,420);
   line (x,420,x+10,410);
   line (x+20,420,x+10,410);
 }

 int shoot()
 { int i,xx=x+10,ck;
   char ch;
   setcolor(0);
   settextstyle(1,HORIZ_DIR,1);
   outtextxy(390,448,c_sh);
   i_sh++;
   itoa(i_sh,c_sh,10);
   setcolor (14);
   outtextxy(390,448,c_sh);
   for (i=408;i>-15;i-=3)
   {
       if ( (i-23<230 && i+13>230)  && (xx>ex && xx-81<ex) )
       { setcolor (0); line (xx,i,xx,i+15); bsh=1; bx=xx; back=1; backshoot(); break; }
      if (i%2!=0)
      { setcolor (0); line (xx,i,xx,i+15); emoving();  }
	else
      { setcolor (15);  line (xx,i-5,xx,i+10); }
       if (kbhit())
      { ch=getch();
	if (ch=='4')
	{  if (x>10)   { eraseyou(); x-=5; you(); } }
	else if (ch=='6')
	{  if (x<600)  { eraseyou(); x+=5; you(); } }
	else if (ch=='p')  getch();
      }
	ck=check_shoot(i*2,xx); if (ck==1)
      { score(); setcolor (0); line (xx,i-25,xx,i+15); settextstyle(1,HORIZ_DIR,1);
	for (i=480;i<540;i++)
	line (i,448,i,478); i_k++;
	itoa(i_k,c_k,10); setcolor (14); outtextxy(482,448,c_k);
	ck = 0; break; }


    }
    st=0;
    irgun();
    procent();
    return 0;
 }


 int check_shoot (int ii,int xx)
 {   int i,j;
     for (i=N;i<N*2;i++)
     for (j=0;j<M;j++)
     if (e[i-N][j]==2)
   {  if ( (xx+8>ess[0] && xx-8<ess[0] )  && ( ii/2+10>ess[1] && ii/2-10<ess[1] ) )
     { e[i-N][j]=0; eshmove(-11,j) ; g=2; ess[0]=ess[1]=0; ck=0; return 1; }  }
     else
     if ( ( xx<e[i][j]+15 && xx>e[i][j]-15 ) && ( ii>i*30+30-5 && ii<i*30+30+5 ) && e[i-N][j]!=0)
     { e[i-N][j]=0; eraseenemy(); return 1; }

     return 0;
 }

 void move()
 { char ch;
   for (;ch!=27;)
   { if (kbhit())
     {
     ch=getch();
     switch (ch)  {
     case '4': if (x>10)   { eraseyou(); x-=5; you(); } break;
     case '6': if (x<600)  { eraseyou(); x+=5; you(); } break;
     case '5': if(st!=-1 && bsh!=1)  { st=1; shoot(); } break;
     case 'p': getch(); break;
     case 27 : gameover();
		  }
     }
     else emoving();
   }
 }


 void gameover()
   { cleardevice();
     setcolor(12);
     settextstyle(5,HORIZ_DIR,7);
     outtextxy(130,180,"GAME OVER");
     getch();
     getch();
     exit(1);
   }