#include <GL/glut.h>
#include<math.h>
#include <stdbool.h>


//function declarations
void backgroundgreen();
void backgroundblue();
void tree();
void house(float wallR,float wallG,float wallB);
void fruittree();
void flowerpot();
void drawCircle(float cx, float cy, float r, int num_segments,float CircleR, float CircleG,float CircleB);
void horse();
void flowers();
void boat();
void drawyellowfish();
void drawbluefish();
void rightflowerpotsmall(float radius);
void sun(float a, float b, float c, int segments,float R, float G,float B);
void drawEllipse(float cx, float cy, float rx, float ry, int num_segments, float red, float green, float blue);

//setting variables
float boatPosition = 0.0;
bool boatMoving = false;
float horsePosition = 0.0;
bool horseMoving = false;
float horseDirection=0.0;
float tailAngle = -0.1;
bool rotateTail = false;
bool rotateHorse = false;
float horseRotationAngle = 0.0f;
bool horseMovingRight = false;
bool boatleft=false;
float flowerpotTolarge = 1.0;
float flowerTolarge=1.0;
float fishTolarge=1.0;
float fruittreesmall=1.0;
float sunPosition=0.0;
float rightTosmall=1.0;


//function for the draw ellipes
void drawEllipse(float cx, float cy, float rx, float ry, int num_segments, float red, float green, float blue) {
    int i;
    float theta, x, y;

    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
    for (i = 0; i < num_segments; i++) {
        theta = 2.0f * M_PI * (float)i / (float)num_segments;
        x = rx * cosf(theta);
        y = ry * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

//function for the get the input as keyboard key
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'b':
    case 'B':
        boatMoving = true;
        break;

    case 'f':
    case 'F':
        horseMoving = true;
        horseMovingRight=false;
        break;

    case 'Q':
    case 'q':
        rotateHorse = true;
        horseMoving=false;
        break;

    case 'r':
    case 'R':
        rotateTail=true;

     break;

    case 'w':
    case 'W':
        boatleft=true;
        boatMoving=false;
    break;


    case 'u':
    case 'U':
        flowerpotTolarge *=1.5;
        flowerTolarge *=1.5;
        fishTolarge *=1.5;
        glutPostRedisplay();
    break;

    case 'S':
    case 's':
        fruittreesmall *=0.5;
        glutPostRedisplay();
        break;

    case ' ':
        sunPosition -=0.1;
        rightTosmall *=0.5;
        glutPostRedisplay();
        break;


    }
}


//function for the sun
void sun(float a, float b, float c, int segments,float R, float G,float B){
glPushMatrix();
glTranslatef(sunPosition,0.0,0.0);
glColor3f(R,G,B);
glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926f * (float)i / (float)segments;
        float x = c * cosf(theta);
        float y = c * sinf(theta);
        glVertex2f(x + a, y + b);
    }
glEnd();
glPopMatrix();

}

//draw the rightside flowerpot
void rightflowerpotsmall(float radius) {

    glColor3f(1.0, 1.0, 0.941);
    drawEllipse(0.85, -0.45, 0.07, 0.025, 100, 0.9, 0.4, 0.1);
    drawEllipse(0.85, -0.35, 0.07, 0.025, 100, 0.9, 0.4, 0.1);

    glBegin(GL_QUADS);
    glVertex2f(0.78, -0.45);
    glVertex2f(0.78, -0.35);
    glVertex2f(0.92, -0.35);
    glVertex2f(0.92, -0.45);
    glEnd();

    glColor3f(0.212, 0.271, 0.310);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(0.85, -0.33);
    glVertex2f(0.85, -0.20);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.85, -0.30);
    glVertex2f(0.89, -0.22);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.85, -0.30);
    glVertex2f(0.81, -0.22);
    glEnd();

    drawCircle(0.85, -0.20, radius, 20, 1.0, 0.85, 0.9);
    drawCircle(0.89, -0.22, radius, 20, 0.5, 0.0, 0.5);
    drawCircle(0.81, -0.22, radius, 20, 1.0, 0.0, 0.0);



}

//draw a blue color fish
void drawbluefish() {
    glPushMatrix();
    glScalef(fishTolarge,fishTolarge,1.0);
    glColor3f(0.9569, 0.0078, 0.9020);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.07, 0.13);
    glVertex2f(0.05, 0.1);
    glVertex2f(0.03, 0.13);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.05, -0.05);
    glVertex2f(0.03, -0.13);
    glVertex2f(0.05, -0.1);
    glVertex2f(0.07, -0.13);
    glEnd();

    glColor3f(0.2902, 0.0078, 0.6902);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.05, -0.05);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.05, 0.05);
    glEnd();

    //tail of the fish
    glColor3f(0.9569, 0.0078, 0.9020);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.025, 0.03);
    glVertex2f(-0.025, -0.03);
    glEnd();

    //gl lines in the body
    glColor3f(0.9569, 0.0078, 0.9020);
    glBegin(GL_LINES);
    glVertex2f(0.05, -0.05);
    glVertex2f(0.05, 0.05);

    glVertex2f(0.032, -0.032);
    glVertex2f(0.032, 0.032);

    glVertex2f(0.016, -0.016);
    glVertex2f(0.016, 0.016);
    glEnd();

    //eyes
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(0.075, 0.0);
    glEnd();

    glPopMatrix();
}





void drawyellowfish() {

   //triangles
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.025, 0.1);
    glVertex2f(0.04, 0.01);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.05, -0.05);
    glVertex2f(0.04, 0.01);
    glVertex2f(0.025, -0.1);
    glEnd();

    //body of the fish
    glColor3f(1.0, 0.65, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.05, -0.05);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.05, 0.05);
    glEnd();

    //tail of the fish
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.025, 0.03);
    glVertex2f(-0.025, -0.03);
    glEnd();

   //gl lines of the fish
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.05, -0.05);
    glVertex2f(0.05, 0.05);

    glVertex2f(0.032, -0.032);
    glVertex2f(0.032, 0.032);

    glVertex2f(0.016, -0.016);
    glVertex2f(0.016, 0.016);
    glEnd();

    //eyes
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(0.075, 0.0);
    glEnd();
}

void boat(){

glPushMatrix();
glTranslatef(boatPosition, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);  // body
    glBegin(GL_POLYGON);
    glVertex2f(-0.4,-0.68);
    glVertex2f(-0.3, -0.68);
    glVertex2f(-0.32, -0.5);
    glVertex2f(-0.35, -0.5);
    glVertex2f(-0.3, -0.39);
    glVertex2f(-0.4, -0.39);
    glEnd();

    glColor3f(0.969, 0.502, 0.400);  // face
    glBegin(GL_POLYGON);
    glVertex2f(-0.38,-0.39);
    glVertex2f(-0.32, -0.39);
    glVertex2f(-0.32, -0.3);
    glVertex2f(-0.31, -0.3);
    glVertex2f(-0.32, -0.2);
    glVertex2f(-0.38, -0.2);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);  // black hair
    glBegin(GL_QUADS);
    glVertex2f(-0.38,-0.2);
    glVertex2f(-0.32, -0.2);
    glVertex2f(-0.29, -0.13);
    glVertex2f(-0.38, -0.15);
    glEnd();


    glColor3f(0.8, 0.5, 0.2);  //boat in the water
    glBegin(GL_QUADS);
    glVertex2f(-0.5, -0.85);
    glVertex2f(-0.1, -0.85);
    glVertex2f(-0.05, -0.68);
    glVertex2f(-0.55, -0.68);
    glEnd();



    glColor3f(0.0, 0.0, 0.0); //hub
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, -0.95);
    glVertex2f(-0.46, -0.95);
    glVertex2f(-0.32, -0.5);
    glEnd();

 glPopMatrix();

}

void horse(){


glPushMatrix();
glTranslatef(horsePosition, 0.0, 0.0);
glRotatef(horseRotationAngle, 0.0f, 1.0f, 0.0f);
glColor3f(0.65,0.16,0.16);//body of horse
    glBegin(GL_POLYGON);
    glVertex2f(-0.25,-0.18);
    glVertex2f(-0.1,-0.18);
    glVertex2f(-0.1,-0.32);
    glVertex2f(-0.25,-0.32);
    glEnd();

glColor3f(0.65,0.16,0.16);//face of horse
    glBegin(GL_POLYGON);
    glVertex2f(-0.23,-0.06);
    glVertex2f(-0.18,-0.18);
    glVertex2f(-0.25,-0.18);
    glVertex2f(-0.253,-0.16);
    glVertex2f(-0.27,-0.13);
    glVertex2f(-0.27,-0.10);

    glEnd();

glColor3f(0.0,0.0,0.0);
    glPointSize(3.0);//eye of horse
    glBegin(GL_POINTS);
    glVertex2f(-0.24,-0.1);
    glEnd();

glColor3f(0.65,0.16,0.16);
    glLineWidth(10.0);
    //front face part
    glBegin(GL_LINES);
    glVertex2f(-0.27,-0.13);
    glVertex2f(-0.27,-0.10);
    glEnd();

glColor3f(0.0,0.0,0.0);
    glLineWidth(5.0);//front face part
    glBegin(GL_LINES);
    glVertex2f(-0.27,-0.13);
    glVertex2f(-0.27,-0.10);
    glEnd();

glColor3f(1.0,1.0,1.0);//white hair
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.23,-0.06);
    glVertex2f(-0.15,-0.18);
    glVertex2f(-0.19,-0.18);
    glEnd();


glPushMatrix();
glTranslatef(-0.1, -0.18, 0.0); //tail translate
glRotatef(tailAngle, 0.0, 0.0, 1.0);  // around x axis
glTranslatef(0.1, 0.18, 0.0);
glColor3f(1.0,1.0,1.0);//white tail
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.1,-0.18);
    glVertex2f(-0.08,-0.31);
    glVertex2f(-0.06,-0.18);
    glEnd();
glPopMatrix();

glColor3f(1.0,1.0,1.0);//left leg
    glBegin(GL_QUADS);
    glVertex2f(-0.25,-0.32);
    glVertex2f(-0.23,-0.32);
    glVertex2f(-0.23,-0.40);
    glVertex2f(-0.25,-0.40);
    glEnd();

glColor3f(1.0,1.0,1.0);//right leg
    glBegin(GL_QUADS);
    glVertex2f(-0.12,-0.32);
    glVertex2f(-0.10,-0.32);
    glVertex2f(-0.10,-0.40);
    glVertex2f(-0.12,-0.40);
    glEnd();

 glPopMatrix();


}

//function for the draw the circle
void drawCircle(float cx, float cy, float r, int num_segments,float CircleR, float CircleG,float CircleB) {
    glColor3f( CircleR,CircleG, CircleB);
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * (float)i / (float)num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
   glEnd();
}

void flowerpot(){   //another flower pot of left
glPushMatrix();
glScalef(flowerpotTolarge, flowerpotTolarge, 1.0);

glColor3f(1.0,0.65,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.78,-0.35);

    glVertex2f(-0.7,-0.35);
    glVertex2f(-0.72,-0.45);
    glVertex2f(-0.76,-0.45);
    glEnd();

glPopMatrix();
}
void flowers(){  // set of flowers in a pot


glPushMatrix();
glScalef(flowerTolarge, flowerTolarge, 1.0);
    glColor3f(1.0,0.65,0.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(-0.74,-0.35);

    glVertex2f(-0.74,-0.25);
    glEnd();

glColor3f(1.0,0.65,0.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(-0.74,-0.32);
    glVertex2f(-0.70,-0.28);
    glEnd();

glColor3f(1.0,0.65,0.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(-0.74,-0.335);
    glVertex2f(-0.78,-0.28);
    glEnd();
drawCircle(-0.74,-0.25,0.02,20,1.0,0.75,0.8);
drawCircle(-0.70,-0.28,0.02,20,0.5,0.0,0.5);
drawCircle(-0.78,-0.30,0.02,20,1.0,0.0,0.0);

glPopMatrix();
}

void fruittree(){
glPushMatrix();
glScalef(fruittreesmall,fruittreesmall,1.0);
glColor3f(0.0,0.5,0.0);//leaves of the tree
    glBegin(GL_POLYGON);
    glVertex2f(-0.1,0.8);
    glVertex2f(-0.05,0.65);
    glVertex2f(-0.075,0.65);
    glVertex2f(-0.025,0.45);
    glVertex2f(-0.075,0.45);
    glVertex2f(0.0,0.2);
    glVertex2f(-0.2,0.2);
    glVertex2f(-0.125,0.45);
    glVertex2f(-0.175,0.45);
    glVertex2f(-0.125,0.65);
    glVertex2f(-0.150,0.65);

    glEnd();

glColor3f(0.4,0.2,0.0);//trunk of the fruittree
    glBegin(GL_QUADS);
    glVertex2f(-0.125,0.2);
    glVertex2f(-0.075,0.2);
    glVertex2f(-0.075,-0.120);
    glVertex2f(-0.125,-0.120);
    glEnd();

glColor3f(0.4,0.2,0.0);//right fruit
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(-0.050,0.2);
    glVertex2f(-0.050,0.1);
    glEnd();
drawCircle(-0.050,0.1,0.02,20,1.0,0.0,0.0);



glColor3f(0.4,0.2,0.0);
    glBegin(GL_LINES);
    glVertex2f(-0.150,0.2);
    glVertex2f(-0.150,0.1);
    glEnd();


drawCircle(-0.150,0.1,0.02,20,1.0,0.0,0.0);

glPopMatrix();
}

void house(float wallR,float wallG,float wallB){
glColor3f(1.0,0.0,0.0);//roof of the house
    glBegin(GL_QUADS);
    glVertex2f(-0.53,0.35);
    glVertex2f(-0.37,0.35);
    glVertex2f(-0.3,0.25);
    glVertex2f(-0.6,0.25);
    glEnd();

glColor3f(wallR,wallG,wallB);// wall of the house
    glBegin(GL_QUADS);
    glVertex2f(-0.56,0.25);
    glVertex2f(-0.34,0.25);
    glVertex2f(-0.34,-0.1);
    glVertex2f(-0.56,-0.1);
    glEnd();

glColor3f(0.5,0.0,0.5);//door of the house
        glBegin(GL_QUADS);
        glVertex2f(-0.5,0.1);
        glVertex2f(-0.4,0.1);
        glVertex2f(-0.4,-0.1);
        glVertex2f(-0.5,-0.1);
        glEnd();
}






void tree(){
glColor3f(0.0,0.5,0.0); //leaves of the tree
    glBegin(GL_POLYGON);
    glVertex2f(-0.8,0.6);
    glVertex2f(-0.75,0.4);
    glVertex2f(-0.775,0.4);
    glVertex2f(-0.725,0.2);
    glVertex2f(-0.775,0.2);
    glVertex2f(-0.7,-0.0);
    glVertex2f(-0.9,-0.0);
    glVertex2f(-0.825,0.2);
    glVertex2f(-0.875,0.2);
    glVertex2f(-0.825,0.4);
    glVertex2f(-0.85,0.4);

    glEnd();


    glColor3f(0.4,0.2,0.0);//trunk of the tree
    glBegin(GL_QUADS);
    glVertex2f(-0.825,0.0);
    glVertex2f(-0.775,0.0);
    glVertex2f(-0.775,-0.2);
    glVertex2f(-0.825,-0.2);
    glEnd();

}

void backgroundblue(){
glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.5);
    glVertex2f(1.0, -0.5);
    glVertex2f(1.0, -1.0);
    glVertex2f(-1.0, -1.0);
    glEnd();
}

void backgroundgreen(){
glColor3f(0.0, 1.0, 0.0); // green color
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -0.5);
    glVertex2f(-1.0, -0.1);
    glVertex2f(-0.4, 0.02);
    glVertex2f(1.0, -0.1);
    glVertex2f(1.0, -0.5);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    backgroundblue();
    backgroundgreen();
    tree();
    house(1.0,0.647,0.0);
    fruittree();
    flowerpot();
    flowers();
    horse();
    boat();
    rightflowerpotsmall(0.03);

    sun(0.8,0.8,0.1,40,1.0,0.647,0.0);


    glPushMatrix();
    glTranslatef(0.3,-0.8,0.0);
    glRotatef(180.0,0.0,0.0,1.0);
    drawbluefish();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.6,-0.65,0.0);
    glRotatef(180.0,0.0,0.0,1.0);
    drawbluefish();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.88,-0.8,0.0);
    drawyellowfish();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.65,-0.65,0.0);
    glRotatef(180.0,0.0,0.0,1.0);
    drawyellowfish();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6,0.05,0.0);
    fruittree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.75,-0.05,0.0);
    house(1.0,0.75,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15,0.1,0.0);
    flowerpot();
    flowers();
    glPopMatrix();



    glPushMatrix(); // reducing the scale of the right flower pot
    glScalef(rightTosmall,rightTosmall,1.0);
    glTranslatef(-0.25,0.1,0.0);
    rightflowerpotsmall(0.04);
    glPopMatrix();

    glFlush();
}


void update(int value) {

    if (boatMoving) { //boat to right
        boatPosition += 0.01;
        if (boatPosition > 1.0) {
            boatPosition = -1.0;
        }
    }


    if(boatleft){
        boatPosition -= 0.01; //boat to left
        if (boatPosition <- 1.0) {
        boatPosition = 1.0;

      }
    }

   if (horseMoving) { //horse to left
    horsePosition -= 0.01;
    if (horsePosition <- 1.0) {
        horsePosition = 1.0;

      }
   }


   if (rotateTail) { //rotate the tail
        tailAngle += 2.0;
        if (tailAngle >= 360.0) {
            tailAngle -= 360.0;
        }
    }

    if (rotateHorse) { //rotate the horse by 180 degress
        horseRotationAngle += 2.0f;
        if (horseRotationAngle >= 180.0f) {
            horseRotationAngle = 180.0f;
            rotateHorse = false;
            horseMovingRight = true;

        }
    }

    if (horseMovingRight) { //horse to right
        horsePosition += 0.01;
        if (horsePosition > 1.0) {
            horsePosition = -1.0;

        }
    }


    glutPostRedisplay(); // draw the scene again
    glutTimerFunc(16, update, 0);//next round
}


//create the yellow background
void init() {
    glClearColor(1.0, 1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glutKeyboardFunc(keyboard);

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("22020411 Take Home");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, update, 0);
    glutMainLoop();

    return 0;
}

