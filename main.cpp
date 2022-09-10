#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>
#include <mmsystem.h>

void init(void){
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1000,600,0);
}

float left_to_right=-800;
float right_to_left = 100;

static float tx	= 0.0;
static float ty	= 0.0;

void circleRain(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy){

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=100;i++){
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

void rain(){
    for(int i=0;i<20;i++){
        for(int j=0;j<15;j++){
            glColor3ub(242,242,242);
            circleRain(1,2,(i*1)+rand()%1000+0,(i*1)+rand()%600+0);
            glFlush();
        }
    }
}

void spe_key(int key, int x, int y){
	switch (key) {

		case GLUT_KEY_LEFT:
				tx -=0.5;
				glutPostRedisplay();
				break;
		case GLUT_KEY_RIGHT:
				tx +=0.5;
				glutPostRedisplay();
				break;
		case GLUT_KEY_DOWN:
				ty +=0.5;
				glutPostRedisplay();
				break;
		case GLUT_KEY_UP:
				ty -=0.5;
				glutPostRedisplay();
				break;
	  default:
			break;
	}
}

void my_keyboard(unsigned char key, int x, int y){

	switch (key) {

		case 'p':
			PlaySound("Faana.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
			break;

		case 'P':
			PlaySound("Faana.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
			break;

        case 'r':
			PlaySound("Barish.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
			break;

		case 'R':
			PlaySound("Barish.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
			break;


		case 's':
			 PlaySound("mute.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
			 break;

        case 'S':
			 PlaySound("mute.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
			 break;

	  default:
			break;
	}
}

void my_mouse(int button, int state, int x, int y){
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            sndPlaySound("Barish.wav",SND_ASYNC);
            glutIdleFunc(rain);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
            sndPlaySound("Faana.wav",SND_ASYNC);
         break;
      default:
         break;
   }
}



void lefttoright_cloud(){
    if(left_to_right<=1000){
        left_to_right=left_to_right+.01;
    }else{
        left_to_right=-800;
    }
    glutPostRedisplay();
}

void righttoleft_cloud(){
    if(right_to_left>=-1000){
        right_to_left=right_to_left-.01;
    }else{
        right_to_left=100;
    }
    glutPostRedisplay();
}

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy){

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=100;i++){
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

void circle1(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy){
    lefttoright_cloud();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(left_to_right+cx,cy);

    for(int i=0;i<=100;i++){
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+left_to_right+cx),(y+cy));
    }
    glEnd();
}

void circle2(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy){

    righttoleft_cloud();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(right_to_left+cx,cy);

    for(int i=0;i<=100;i++){
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+right_to_left+cx),(y+cy));
    }
    glEnd();
}

void circle3(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy){

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=100;i++){
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

void fullSky(){
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor3ub(50,60,130);

    glBegin(GL_POLYGON);
    glVertex2f(0,300);
    glVertex2f(1000,300);

    glColor3ub(0,0,0);

    glVertex2f(1000,0);
    glVertex2f(0,0);
    glEnd();
}

void fullBottom(){
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,600);
    glVertex2f(1000,600);
    glVertex2f(1000,300);
    glVertex2f(0,300);
    glEnd();
}

void moon(){
    glColor3ub(255,255,255);
    circle(192,192,500,280);
}

void cloud1(){
    glColor3ub(212,212,212);
    circle1(80,5,100,260);
    circle1(35,5,75,250);
    circle1(20,20,90,240);
    circle1(20,10,115,250);
}
void cloud2(){
    glColor3ub(255,255,255);
    circle1(80,5,620,70);
    circle1(35,5,595,60);
    circle1(20,20,610,50);
    circle1(20,10,635,60);
}

void cloud3(){
    glColor3ub(164,164,164);
    circle2(100,10,900,150);
    circle2(35,5,875,160);
    circle2(20,15,890,160);
    circle2(20,10,920,165);
    circle2(80,10,910,135);
}

void bridge_pillar(){
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(490,280);
    glVertex2f(500,280);
    glVertex2f(500,205);
    glVertex2f(490,205);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(520,280);
    glVertex2f(530,280);
    glVertex2f(530,195);
    glVertex2f(520,195);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(500,250);
    glVertex2f(520,250);
    glVertex2f(520,240);
    glVertex2f(500,240);
    glEnd();

    glColor3ub(44,33,41);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(480,280);
    glVertex2f(490,270);

    glVertex2f(460,280);
    glVertex2f(490,250);

    glVertex2f(440,280);
    glVertex2f(490,230);

    glVertex2f(420,280);
    glVertex2f(490,210);

    glVertex2f(530,260);
    glVertex2f(550,280);

    glVertex2f(530,240);
    glVertex2f(570,280);

    glVertex2f(530,220);
    glVertex2f(580,270);

    glVertex2f(530,200);
    glVertex2f(580,250);
    glEnd();
}

void bridge_road(){
    glColor3ub(166,166,166);
    glBegin(GL_POLYGON);
    glVertex2f(390,320);
    glVertex2f(580,320);
    glVertex2f(580,280);
    glVertex2f(390,280);
    glEnd();
}
void person(){
    glColor3ub(44,33,41);
    circle3(7,7,410,255);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(410, 262);
    glVertex2f(410, 271);

    glVertex2f(410, 271);
    glVertex2f(404, 280);

    glVertex2f(410, 271);
    glVertex2f(418, 280);

    glVertex2f(410, 265);
    glVertex2f(420, 271);

    glVertex2f(410, 265);
    glVertex2f(402, 271);
    glEnd();

}

void bridge_body(){
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(390,330);
    glVertex2f(580,330);
    glVertex2f(580,290);
    glVertex2f(390,290);
    glEnd();
}

void bridge_under(){
    glColor3ub(19,17,96);
    circle(95,20,485,330);
}

void left_city(){
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(340,330);
    glVertex2f(390,330);
    glVertex2f(390,180);
    glVertex2f(340,210);
    glEnd();

    glColor3ub(38,62,110);
    glBegin(GL_POLYGON);
    glVertex2f(240,380);
    glVertex2f(300,350);
    glVertex2f(300,170);
    glVertex2f(240,190);
    glEnd();

    glColor3ub(76,86,112);
    glBegin(GL_POLYGON);
    glVertex2f(230,370);
    glVertex2f(280,290);
    glVertex2f(280,180);
    glVertex2f(230,150);
    glEnd();

    glColor3ub(38,62,110);
    glBegin(GL_POLYGON);
    glVertex2f(150,250);
    glVertex2f(190,230);
    glVertex2f(190,190);
    glVertex2f(150,190);
    glEnd();

    glColor3ub(38,62,110);
    glBegin(GL_POLYGON);
    glVertex2f(40,380);
    glVertex2f(110,380);
    glVertex2f(110,190);
    glVertex2f(40,230);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(240,380);
    glVertex2f(280,360);
    glVertex2f(280,240);
    glVertex2f(240,260);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(280,360);
    glVertex2f(330,360);
    glVertex2f(330,230);
    glVertex2f(280,230);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(330,360);
    glVertex2f(370,340);
    glVertex2f(370,260);
    glVertex2f(330,230);
    glEnd();

    glColor3ub(76,86,112);
    glBegin(GL_POLYGON);
    glVertex2f(90,370);
    glVertex2f(140,370);
    glVertex2f(140,240);
    glVertex2f(90,240);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(130,410);
    glVertex2f(170,410);
    glVertex2f(170,220);
    glVertex2f(130,250);
    glEnd();

    glColor3ub(251, 252, 164);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(130,270);
    glVertex2f(170,240);

    glVertex2f(130,290);
    glVertex2f(170,270);

    glVertex2f(130,310);
    glVertex2f(170,300);

    glVertex2f(130,330);
    glVertex2f(170,330);

    glVertex2f(130,350);
    glVertex2f(170,360);

    glVertex2f(130,370);
    glVertex2f(170,390);
    glEnd();

    glColor3ub(251, 252, 164);
    //glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(170,410);
    glVertex2f(170,220);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(170,410);
    glVertex2f(220,390);
    glVertex2f(220,220);
    glVertex2f(170,220);
    glEnd();

    glColor3ub(251, 252, 164);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(170,240);
    glVertex2f(220,240);

    glVertex2f(170,270);
    glVertex2f(220,270);

    glVertex2f(170,300);
    glVertex2f(220,300);

    glVertex2f(170,330);
    glVertex2f(220,330);

    glVertex2f(170,360);
    glVertex2f(220,360);

    glVertex2f(170,390);
    glVertex2f(220,390);
    glEnd();

    glColor3ub(76,86,112);
    glBegin(GL_POLYGON);
    glVertex2f(0,520);
    glVertex2f(60,470);
    glVertex2f(60,300);
    glVertex2f(0,300);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(100,450);
    glVertex2f(150,450);
    glVertex2f(150,310);
    glVertex2f(100,310);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(70,480);
    glVertex2f(110,480);
    glVertex2f(110,360);
    glVertex2f(70,360);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(20,540);
    glVertex2f(70,520);
    glVertex2f(70,350);
    glVertex2f(20,390);
    glEnd();

    glColor3ub(251, 252, 164);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(20,540);
    glVertex2f(20,390);

    glVertex2f(20,390);
    glVertex2f(70,350);

    glVertex2f(70,350);
    glVertex2f(70,520);

    glVertex2f(70,360);
    glVertex2f(110,360);

    glVertex2f(70,380);
    glVertex2f(110,380);

    glVertex2f(70,400);
    glVertex2f(110,400);

    glVertex2f(70,420);
    glVertex2f(110,420);


    glVertex2f(70,440);
    glVertex2f(110,440);

    glVertex2f(70,460);
    glVertex2f(110,460);

    glVertex2f(110,360);
    glVertex2f(110,460);


    glVertex2f(100,360);
    glVertex2f(100,310);

    glVertex2f(100,310);
    glVertex2f(150,310);

    glVertex2f(150,310);
    glVertex2f(150,450);

    glVertex2f(130,310);
    glVertex2f(130,250);

    glVertex2f(130,250);
    glVertex2f(170,220);

    glVertex2f(170,220);
    glVertex2f(220,220);

    glVertex2f(220,220);
    glVertex2f(220,400);

    glVertex2f(240,380);
    glVertex2f(240,260);

    glVertex2f(240,260);
    glVertex2f(280,260);

    glVertex2f(280,260);
    glVertex2f(280,240);

    glVertex2f(280,240);
    glVertex2f(240,260);

    glVertex2f(280,370);
    glVertex2f(280,230);

    glVertex2f(280,230);
    glVertex2f(330,230);

    glVertex2f(330,230);
    glVertex2f(330,360);

    glVertex2f(330,230);
    glVertex2f(370,260);

    glVertex2f(370,260);
    glVertex2f(370,330);
    glEnd();
}


void right_city(){
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(610,270);
    glVertex2f(660,270);
    glVertex2f(660,180);
    glVertex2f(610,180);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(580,330);
    glVertex2f(640,340);
    glVertex2f(640,200);
    glVertex2f(580,230);
    glEnd();

    glColor3ub(38,62,110);
    glBegin(GL_POLYGON);
    glVertex2f(750,300);
    glVertex2f(790,300);
    glVertex2f(790,150);
    glVertex2f(750,150);
    glEnd();

    glColor3ub(38,62,110);
    glBegin(GL_POLYGON);
    glVertex2f(810,250);
    glVertex2f(850,250);
    glVertex2f(850,190);
    glVertex2f(810,190);
    glEnd();

    glColor3ub(38,62,110);
    glBegin(GL_POLYGON);
    glVertex2f(860,270);
    glVertex2f(910,270);
    glVertex2f(910,155);
    glVertex2f(860,155);
    glEnd();

    glColor3ub(38,62,110);
    glBegin(GL_POLYGON);
    glVertex2f(920,300);
    glVertex2f(980,300);
    glVertex2f(980,180);
    glVertex2f(920,180);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(640,340);
    glVertex2f(670,340);
    glVertex2f(670,255);
    glVertex2f(640,255);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(690,370);
    glVertex2f(750,380);
    glVertex2f(750,220);
    glVertex2f(690,220);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(700,220);
    glVertex2f(740,220);
    glVertex2f(740,200);
    glVertex2f(700,200);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(710,200);
    glVertex2f(730,200);
    glVertex2f(730,180);
    glVertex2f(710,180);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(720,180);
    glVertex2f(720,150);
    glEnd();

    glColor3ub(76,86,112);
    glBegin(GL_POLYGON);
    glVertex2f(780,390);
    glVertex2f(840,390);
    glVertex2f(840,240);
    glVertex2f(780,240);
    glEnd();

    glColor3ub(76,86,112);
    glBegin(GL_POLYGON);
    glVertex2f(795,240);
    glVertex2f(825,240);
    glVertex2f(825,220);
    glVertex2f(795,220);
    glEnd();

    glColor3ub(76,86,112);
    glBegin(GL_POLYGON);
    glVertex2f(805,220);
    glVertex2f(815,220);
    glVertex2f(815,205);
    glVertex2f(805,205);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(840,390);
    glVertex2f(900,390);
    glVertex2f(900,230);
    glVertex2f(840,230);
    glEnd();
    glColor3ub(251, 252, 164);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(840,260);
    glVertex2f(900,260);

    glVertex2f(840,290);
    glVertex2f(900,290);

    glVertex2f(840,320);
    glVertex2f(900,320);

    glVertex2f(840,350);
    glVertex2f(900,350);

    glVertex2f(840,380);
    glVertex2f(900,380);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(770,410);
    glVertex2f(820,420);
    glVertex2f(820,270);
    glVertex2f(770,270);
    glEnd();

    glColor3ub(222,255,122);
    glBegin(GL_POLYGON);
    glVertex2f(895,465);
    glVertex2f(965,465);
    glVertex2f(965,265);
    glVertex2f(895,265);
    glEnd();

    glColor3ub(76,86,112);
    glBegin(GL_POLYGON);
    glVertex2f(895,465);
    glVertex2f(965,465);
    glVertex2f(965,265);
    glVertex2f(895,265);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(725,400);
    glVertex2f(770,400);
    glVertex2f(770,295);
    glVertex2f(725,295);
    glEnd();

    glColor3ub(76,86,112);
    glBegin(GL_POLYGON);
    glVertex2f(965,470);
    glVertex2f(1000,470);
    glVertex2f(1000,300);
    glVertex2f(965,300);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(830,470);
    glVertex2f(875,470);
    glVertex2f(875,330);
    glVertex2f(830,300);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(880,490);
    glVertex2f(940,490);
    glVertex2f(940,325);
    glVertex2f(880,370);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(950,520);
    glVertex2f(1000,520);
    glVertex2f(1000,400);
    glVertex2f(950,400);
    glEnd();

    glColor3ub(251, 252, 164);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(640,340);
    glVertex2f(640,255);

    glVertex2f(670,340);
    glVertex2f(670,255);

    glVertex2f(640,255);
    glVertex2f(670,255);

    glVertex2f(640,270);
    glVertex2f(670,270);

    glVertex2f(640,285);
    glVertex2f(670,285);

    glVertex2f(640,300);
    glVertex2f(670,300);

    glVertex2f(640,315);
    glVertex2f(670,315);

    glVertex2f(640,330);
    glVertex2f(670,330);

    glVertex2f(725,400);
    glVertex2f(725,295);

    glVertex2f(725,295);
    glVertex2f(770,295);

    glVertex2f(725,315);
    glVertex2f(770,315);

    glVertex2f(725,335);
    glVertex2f(770,335);

    glVertex2f(725,355);
    glVertex2f(770,355);

    glVertex2f(725,375);
    glVertex2f(770,375);

    glVertex2f(725,395);
    glVertex2f(770,395);

    glVertex2f(770,410);
    glVertex2f(770,270);

    glVertex2f(770,270);
    glVertex2f(820,270);

    glVertex2f(820,270);
    glVertex2f(820,420);

    glVertex2f(770,290);
    glVertex2f(820,290);

    glVertex2f(770,310);
    glVertex2f(820,310);

    glVertex2f(770,330);
    glVertex2f(820,330);

    glVertex2f(770,350);
    glVertex2f(820,350);

    glVertex2f(770,370);
    glVertex2f(820,370);

    glVertex2f(770,390);
    glVertex2f(820,390);

    glVertex2f(950,520);
    glVertex2f(950,400);

    glVertex2f(950,400);
    glVertex2f(1000,400);

    glVertex2f(880,490);
    glVertex2f(880,370);

    glVertex2f(880,370);
    glVertex2f(940,325);

    glVertex2f(940,325);
    glVertex2f(940,490);

    glVertex2f(830,470);
    glVertex2f(830,300);

    glVertex2f(830,300);
    glVertex2f(875,330);

    glVertex2f(875,330);
    glVertex2f(875,470);

    glVertex2f(875,330);
    glVertex2f(875,470);

    glVertex2f(960,400);
    glVertex2f(960,300);

    glVertex2f(960,300);
    glVertex2f(1000,300);

    glVertex2f(840,305);
    glVertex2f(840,230);

    glVertex2f(840,230);
    glVertex2f(900,230);

    glVertex2f(900,230);
    glVertex2f(900,265);
    glEnd();
}

void lake(){
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor3ub(19,17,96);
    glBegin(GL_POLYGON);
    glVertex2f(0,600);
    glVertex2f(1000,600);
    glColor3ub(13,16,34);
    glVertex2f(580,330);
    glVertex2f(390,330);
    glEnd();

     glColor3ub(255,255,255);
    circle(95,2,485,335);

    glColor3ub(210, 229, 252);
    circle(95,2,485,335);
    circle(50,1,430,340);
    circle(95,2,495,345);
    circle(50,1,450,320);
    circle(50,1,465,323);
    circle(50,1,495,315);
    circle(95,2,488,330);
    circle(50,1,480,350);
    circle(80,2,485,355);
    circle(95,2,510,365);
    circle(95,2,480,375);
    circle(70,1,483,383);
    circle(95,2,520,390);
    circle(95,2,420,390);
    circle(95,2,425,395);
    circle(70,1,483,400);
    circle(50,1,483,405);
    circle(50,2,490,410);
    circle(65,1,490,420);
    circle(35,1,490,425);
    circle(20,2,490,430);
    circle(30,1,490,435);
    circle(18,1,490,440);
    circle(10,1,490,445);
    circle(5,1,490,450);
}

void boat(){
    glColor3ub(210, 229, 252);
    circle3(3,3,tx+145,ty+522);
    circle3(4,8,tx+145,ty+533);

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(tx+130,ty+560);
    glVertex2f(tx+200,ty+555);
    glVertex2f(tx+195,ty+535);
    glVertex2f(tx+130,ty+545);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(tx+127,ty+545);
    glVertex2f(tx+137,ty+545);
    glVertex2f(tx+136,ty+538);
    glVertex2f(tx+127,ty+534);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(tx+195,ty+535);
    glVertex2f(tx+215,ty+525);
    glVertex2f(tx+200,ty+555);
    glEnd();
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    fullSky();
    moon();
    fullBottom();
    cloud1();
    cloud2();
    cloud3();
    bridge_pillar();
    bridge_road();
    bridge_body();
    bridge_under();
    person();
    left_city();
    right_city();
    lake();

    glPushMatrix();
	glTranslatef(tx,ty,0);
	boat();
	glPopMatrix();

    glFlush();
}
int main(){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(100, 0);
    glutCreateWindow("Enjoying the city view at MoonLight night | Final Project");

    init();

    glutDisplayFunc(Draw);

    glutSpecialFunc(spe_key);
    glutKeyboardFunc(my_keyboard);
    glutMouseFunc(my_mouse);

    PlaySound("Faana.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

    glutMainLoop();
    return 0;
}
