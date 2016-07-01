/*
Amitayush Thakur	2012B4A7819P
Akath Singh Dua		2012B4A7333P
*/
#include <GL/glut.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "animal.h"
using namespace std;
#define NUM_ANIMALS 5  
#define MAX_TEXURES 2

class Window {
public:
	static int WIDTH;
	static int HEIGHT;
	static int TOP;
	static int LEFT;
	static float ASPECT;
	static float WORLD_FRONT_HEIGHT;
	static float WORLD_FRONT_WIDTH;
	static float WORLD_BACK_HEIGHT;
	static float WORLD_BACK_WIDTH;
};
int Window::WIDTH = 640;
int Window::HEIGHT = 480;
int Window::TOP = 0;
int Window::LEFT = 0;
float Window::WORLD_FRONT_HEIGHT = 480;
float Window::WORLD_FRONT_WIDTH = 640;
float Window::WORLD_BACK_HEIGHT = 480;
float Window::WORLD_BACK_WIDTH = 640;
float Window::ASPECT = 0.0;

float radians(float degrees) {
	return degrees / 180 * PI;
}

class Camera {
public:
	static float EYE_X;
	static float EYE_Y;
	static float EYE_Z;
	static float LOOK_AT_X;
	static float LOOK_AT_Y;
	static float LOOK_AT_Z;
	static float VUP_X;
	static float VUP_Y;
	static float VUP_Z;
	static float ANGLE;
	static float Z_NEAR;
	static float Z_FAR;
	static float CAMERA_ANGLE;
	static float CAMERA_ANGLE_DEGREE;
	static float THETA;
	static float PHI;
	static void rotate(int dim) {
		if (dim == 1) {
			THETA += 15.0f;
			THETA = (int)THETA % 360;
			CAMERA_ANGLE = PI / 12;
			CAMERA_ANGLE_DEGREE = ((int)CAMERA_ANGLE_DEGREE + (int)(CAMERA_ANGLE / PI * 180) % 360) % 360;
			float xNew = EYE_X*cos(-CAMERA_ANGLE) - EYE_Z*sin(-CAMERA_ANGLE);
			float yNew = EYE_X*sin(-CAMERA_ANGLE) + EYE_Z*cos(-CAMERA_ANGLE);
			EYE_X = xNew;
			EYE_Z = yNew;
		}
		else {
			PHI += 15.0f;
			PHI = (int)PHI % 360;
			float radius = sqrt(EYE_X*EYE_X + EYE_Y*EYE_Y + EYE_Z*EYE_Z);
			float xNew = radius * sin(radians(THETA))*cos(radians(PHI));
			float yNew = radius * sin(radians(PHI));
			float zNew = radius * cos(radians(THETA))*cos(radians(PHI));
			cout << PHI << "\n";
			EYE_X = xNew;
			EYE_Y = yNew;
			EYE_Z = zNew;
		}
	}
	static void lookAt() {
		gluLookAt(
			Camera::EYE_X, Camera::EYE_Y, Camera::EYE_Z,
			Camera::LOOK_AT_X, Camera::LOOK_AT_Y, Camera::LOOK_AT_Z,
			Camera::VUP_X, Camera::VUP_Y, Camera::VUP_Z
			);
	}
};
float Camera::CAMERA_ANGLE = 0.0;
float Camera::CAMERA_ANGLE_DEGREE = 0.0;
float Camera::ANGLE = 90.0;
float Camera::Z_NEAR = 5.0;
float Camera::Z_FAR = 205.0;
float Camera::EYE_X = 0;
float Camera::EYE_Y = 0;
float Camera::EYE_Z = 55;
float Camera::LOOK_AT_X = 0;
float Camera::LOOK_AT_Y = 0;
float Camera::LOOK_AT_Z = 0;
float Camera::VUP_X = 0;
float Camera::VUP_Y = 1;
float Camera::VUP_Z = 0;
float Camera::THETA = 165.00f;
float Camera::PHI = 00.00f;
typedef enum color { BLUE, GREEN, RED, BLACK, WHITE, MAGENTA, YELLOW }Color;

class Texture {
public:
	static int texCount;
	static int texID[MAX_TEXURES];
	static unsigned char* texData[MAX_TEXURES];
	static GLuint LoadTexture(const char * filename, int width, int height)
	{
		GLuint texture;
		//		int width, height;
		FILE * file;
		file = fopen(filename, "rb");
		if (file == NULL) return 0;
		//width = 1639;
		//height = 800;
		texData[texCount] = (unsigned char *)malloc(width * height * 3);
		//int size = fseek(file,);
		fread(texData[texCount], 54, 1, file);
		fread(texData[texCount], width * height * 3, 1, file);
		fclose(file);
		for (int i = 0; i < width * height; ++i)
		{
			int index = i * 3;
			unsigned char B, R;
			B = texData[texCount][index];
			R = texData[texCount][index + 2];
			texData[texCount][index] = R;
			texData[texCount][index + 2] = B;
		}
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, texData[texCount]);
		texCount++;
		printf("Exiting\n");
		return texture;
	}
	static void bindToTexture(int texture) {
		glBindTexture(GL_TEXTURE_2D, texID[texture]);
	}
};
int Texture::texCount = 0;
int Texture::texID[MAX_TEXURES];
unsigned char* Texture::texData[MAX_TEXURES];

void changeColor(Color color) {
	switch (color) {
	case BLUE:	glColor3f(0.0, 0.0, 1.0);
		break;
	case GREEN: glColor3f(0.0, 1.0, 0.0);
		break;
	case RED: glColor3f(1.0, 0.0, 0.0);
		break;
	case BLACK: glColor3f(0.0, 0.0, 0.0);
		break;
	case WHITE: glColor3f(1.0, 1.0, 1.0);
		break;
	case MAGENTA: glColor3f(1.0, 0.0, 1.0);
		break;
	case YELLOW: glColor3f(1.0, 1.0, 0.0);
	default: glColor3f(0.0, 0.0, 0.0);
	}
}
void print(int x, int y, char *string)
{
	changeColor(BLACK);
	glRasterPos3f(x, y, -Camera::Z_FAR / 2 + 3);
	int len, i;
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
	}
}

void drawCube() {
	glColor3f(1.0f, 1.0f, 1.0f);

	// draw a cube (6 quadrilaterals)
	glBegin(GL_QUADS);				// start drawing the cube.

									// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Left Of The Texture and Quad

																// Back Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad

																// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Top Right Of The Texture and Quad

																// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Bottom Right Of The Texture and Quad

																// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// Bottom Left Of The Texture and Quad

																// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Top Left Of The Texture and Quad

	glEnd();					// Done Drawing The Cube
}
void printCameraAngle() {
	char textToBePrinted[100];
	sprintf(textToBePrinted, "Camera Angle Y: %.2f.\n Press 'r' to rotate.", Camera::THETA);
	glPushMatrix();
	glRotatef(Camera::THETA, 0.0, 1.0, 0.0);
	glRotatef(-Camera::PHI, 1.0, 0.0, 0.0);
	print(Window::WORLD_BACK_WIDTH / 3 - 75, Window::WORLD_BACK_HEIGHT / 3, textToBePrinted);
	glPopMatrix();
	sprintf(textToBePrinted, "Camera Angle X: %.2f.\n Press 't' to rotate.", Camera::PHI);
	glPushMatrix();
	glRotatef(Camera::THETA, 0.0, 1.0, 0.0);
	glRotatef(-Camera::PHI, 1.0, 0.0, 0.0);
	print(Window::WORLD_BACK_WIDTH / 3 - 75, Window::WORLD_BACK_HEIGHT / 3 - 5, textToBePrinted);
	glPopMatrix();
}

Animal animals[NUM_ANIMALS];


void InitTexture()
{	// Bind the texture
	glEnable(GL_TEXTURE_2D);
	Texture::texID[0] = Texture::LoadTexture("grass1.bmp", 960, 683);
	Texture::texID[1] = Texture::LoadTexture("soil.bmp", 176, 117);
}
void init() {
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	Window::WIDTH = glutGet(GLUT_SCREEN_WIDTH);
	Window::HEIGHT = glutGet(GLUT_SCREEN_HEIGHT);
	Window::ASPECT = (float)Window::WIDTH / Window::HEIGHT;
	glutInitWindowSize(Window::WIDTH, Window::HEIGHT);
	Window::TOP = 0;
	Window::LEFT = 0;
	Window::WORLD_FRONT_HEIGHT = 2 * (tan(radians(Camera::ANGLE / 2)))*(Camera::Z_NEAR);
	Window::WORLD_FRONT_WIDTH = Window::WORLD_FRONT_HEIGHT*Window::ASPECT;
	Window::WORLD_BACK_HEIGHT = 2 * (tan(radians(Camera::ANGLE / 2)))*(Camera::Z_FAR);
	Window::WORLD_BACK_WIDTH = Window::WORLD_BACK_HEIGHT*Window::ASPECT;
	glutInitWindowPosition(Window::TOP, Window::LEFT);
	glutCreateWindow("Animation");
	glDepthFunc(GL_LESS);
	glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading
	glEnable(GL_DEPTH_TEST);
	InitTexture();
}
void display() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	float aspect = (float)w / h;
	gluPerspective(Camera::ANGLE, aspect, Camera::Z_NEAR, Camera::Z_FAR);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Camera::lookAt();
	glEnable(GL_TEXTURE_2D);
	Texture::bindToTexture(0);
	glPushMatrix();
	glColor3f(0.1372255, 0.556863, 0.1372);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glScalef(250, 1, 250);
	drawCube();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glColor3f(1, 1, 0);
	glTranslatef(0.0f, 35.0f, 45.0f);
	glutSolidSphere(4, 10, 10);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	Texture::bindToTexture(1);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glScalef(250, 1, 20);
	drawCube();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	printCameraAngle();
	for (int i = 0; i < NUM_ANIMALS; i++)
		animals[i].drawAnimal();
	glutSwapBuffers();
}

void reshape(int width, int height) {							/*Preventing distortion due to rescaling*/
	Window::WIDTH = width;
	Window::HEIGHT = height;
	Window::ASPECT = (float)Window::WIDTH / Window::HEIGHT;
	Window::WORLD_FRONT_HEIGHT = 2 * (tan(radians(Camera::ANGLE / 2)))*(Camera::Z_NEAR);
	Window::WORLD_FRONT_WIDTH = Window::WORLD_FRONT_HEIGHT*Window::ASPECT;
	Window::WORLD_BACK_HEIGHT = 2 * (tan(radians(Camera::ANGLE / 2)))*(Camera::Z_FAR);
	Window::WORLD_BACK_WIDTH = Window::WORLD_BACK_HEIGHT*Window::ASPECT;
	glViewport(0, 0, Window::WIDTH, Window::HEIGHT);
}
void onKeyPress(unsigned char key, int x, int y) {
	static int w_press_cnt = 0;
	switch (key) {
	case 'r':Camera::rotate(1);
		Camera::lookAt();
		display();
		break;
	case 't':Camera::rotate(0);
		Camera::lookAt();
		display();
		break;
	case 'f':for (int i = 0; i < NUM_ANIMALS; i++) {
		if (animals[i].canMove) {
			animals[i].direction = 1;
			animals[i].move();
		}
	}
			 display();
			 break;
	case 'b':for (int i = 0; i < NUM_ANIMALS; i++) {
		if (animals[i].canMove) {
			animals[i].direction = -1;
			animals[i].move();
		}
	}
			 display();
			 break;
	case 'w':for (int i = 0; i < NUM_ANIMALS; i++) {
		if (!w_press_cnt) {
			animals[i].type = WIRED;
		}
		else {
			animals[i].type = SOLID;
		}
	}
			 w_press_cnt++;
			 w_press_cnt %= 2;
			 display();
			 break;
	}
}
int main(int argc, char **argv)
{
	///Camera::rotate(1);
	Camera::rotate(0);
	glutInit(&argc, argv);
	init();
	animals[0] = Animal(15);
	animals[1] = Animal(10);
	animals[2] = Animal(10);
	animals[3] = Animal(10);
	animals[4] = Animal(10);
	for (int i = 0; i < NUM_ANIMALS; i++)
		animals[i].canMove = false;
	animals[0].canMove = true;
	animals[0].setPosition(-150.0, 0.0, 0.0);
	animals[1].setPosition(10.0, 0.0, -40.0);
	animals[2].setPosition(50.0, 0.0, 80.0);
	animals[3].setPosition(-8.0, 0.0, -30.0);
	animals[4].setPosition(5.0, 0.0f, 30.0);
	for (int i = 0; i < NUM_ANIMALS; i++) {
		animals[i].y_pos = animals[i].legs[0].UPPER_LEN + animals[i].legs[0].LOWER_LEN + animals[i].BODY_HEIGHT / 2.0f;
	}
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(onKeyPress);
	glutMainLoop();
	return 0;
}