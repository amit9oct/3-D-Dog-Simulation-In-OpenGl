/*
Amitayush Thakur	2012B4A7819P
*/
#include "animal.h"
#include <math.h>
#include <stdio.h>
void Utils::drawCube(float length, float width, float height, CubeType cubeType) {
	if (cubeType == SOLID) {
		Utils::drawSolidCube(length, width, height);
	}
	else {
		Utils::drawWireCube(length, width, height);
	}
}
void Utils::drawWireCube(float length/*x*/, float height/*y*/, float width/*z*/) {
	glBegin(GL_LINE_STRIP);
	glVertex3f(-0.50000*length, -0.50000*height, 0.50000*width);
	glVertex3f(0.50000*length, -0.50000*height, 0.50000*width);
	glVertex3f(0.50000*length, 0.50000*height, 0.50000*width);
	glVertex3f(-0.50000*length, 0.50000*height, 0.50000*width);
	glVertex3f(-0.50000*length, -0.50000*height, 0.50000*width);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-0.50000*length, 0.50000*height, 0.50000*width);
	glVertex3f(-0.50000*length, 0.50000*height, -0.50000*width);
	glVertex3f(0.50000*length, 0.50000*height, -0.50000*width);
	glVertex3f(0.50000*length, 0.50000*height, 0.50000*width);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-0.50000*length, 0.50000*height, -0.50000*width);
	glVertex3f(-0.50000*length, -0.50000*height, -0.50000*width);
	glVertex3f(0.50000*length, -0.50000*height, -0.50000*width);
	glVertex3f(0.50000*length, 0.50000*height, -0.50000*width);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-0.50000*length, -0.50000*height, -0.50000*width);
	glVertex3f(0.50000*length, -0.50000*height, -0.50000*width);
	glVertex3f(0.50000*length, -0.50000*height, 0.50000*width);
	glVertex3f(-0.50000*length, -0.50000*height, 0.50000*width);
	glVertex3f(-0.50000*length, -0.50000*height, -0.50000*width);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.500000*length, -0.50000*height, 0.50000*width);
	glVertex3f(0.50000*length, -0.50000*height, -0.50000*width);
	//glVertex3f(0.50000*length, 0.50000*height, -0.50000*width);
	//glVertex3f(0.50000*length, 0.50000*height, 0.50000*width);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-0.50000*length, -0.50000*height, -0.50000*width);
	glVertex3f(-0.50000*length, -0.50000*height, 0.50000*width);
	//glVertex3f(-0.50000*length, 0.50000*height, 0.50000*width);
	//glVertex3f(-0.50000*length, 0.50000*height, -0.50000*width);
	glEnd();

}
void Utils::drawSolidCube(float length/*x*/, float height/*y*/, float width/*z*/) {
	glBegin(GL_QUADS);
	glVertex3f(length / 2.0f, height / 2.0f, -width / 2.0f);
	glVertex3f(-length / 2.0f, height / 2.0f, -width / 2.0f);
	glVertex3f(-length / 2.0f, height / 2.0f, width / 2.0f);
	glVertex3f(length / 2.0f, height / 2.0f, width / 2.0f);

	glVertex3f(length / 2.0f, -height / 2.0f, width / 2.0f);
	glVertex3f(-length / 2.0f, -height / 2.0f, width / 2.0f);
	glVertex3f(-length / 2.0f, -height / 2.0f, -width / 2.0f);
	glVertex3f(length / 2.0f, -height / 2.0f, -width / 2.0f);

	glVertex3f(length / 2.0f, height / 2.0f, width / 2.0f);
	glVertex3f(-length / 2.0f, height / 2.0f, width / 2.0f);
	glVertex3f(-length / 2.0f, -height / 2.0f, width / 2.0f);
	glVertex3f(length / 2.0f, -height / 2.0f, -width / 2.0f);

	glVertex3f(length / 2.0f, -height / 2.0f, -width / 2.0f);
	glVertex3f(-length / 2.0f, -height / 2.0f, -width / 2.0f);
	glVertex3f(-length / 2.0f, height / 2.0f, -width / 2.0f);
	glVertex3f(length / 2.0f, height / 2.0f, -width / 2.0f);

	glVertex3f(-length / 2.0f, height / 2.0f, width / 2.0f);
	glVertex3f(-length / 2.0f, height / 2.0f, -width / 2.0f);
	glVertex3f(-length / 2.0f, -height / 2.0f, -width / 2.0f);
	glVertex3f(-length / 2.0f, -height / 2.0f, width / 2.0f);

	glVertex3f(length / 2.0f, height / 2.0f, -width / 2.0f);
	glVertex3f(length / 2.0f, height / 2.0f, width / 2.0f);
	glVertex3f(length / 2.0f, -height / 2.0f, width / 2.0f);
	glVertex3f(length / 2.0f, -height / 2.0f, -width / 2.0f);
	glEnd();
}
void Utils::drawSphere(float radius, float slices, float stacks, CubeType type) {
	if (type == SOLID) {
		glutSolidSphere(radius, slices, stacks);
	}
	else {
		glutWireSphere(radius, slices, stacks);
	}
}
float Utils::abs(float a) {
	return (a > 0) ? a : -a;
}

float degreeToRadians(float degrees) {
	return degrees / 180 * PI;
}


Leg::Leg()
{
}

/*
****************************************************************************************************
Leg::Leg: Constructor of leg class. Responsible for setting up all leg angles and length.
****************************************************************************************************
*/
Leg::Leg(float UPPER_ANGLE, float LOWER_ANGLE, float FEET_ANGLE,
	float UPPER_LEN, float UPPER_THICKNESS, float UPPER_WIDTH,
	float LOWER_LEN, float LOWER_THICKNESS, float LOWER_WIDTH) {
	this->UPPER_ANGLE = UPPER_ANGLE;
	this->LOWER_ANGLE = LOWER_ANGLE;
	this->FEET_ANGLE = FEET_ANGLE;
	this->UPPER_LEN = UPPER_LEN;
	this->UPPER_THICKNESS = UPPER_THICKNESS;
	this->UPPER_WIDTH = UPPER_WIDTH;
	this->LOWER_LEN = LOWER_LEN;
	this->LOWER_THICKNESS = LOWER_THICKNESS;
	this->LOWER_WIDTH = LOWER_WIDTH;
}

void Leg::drawLeg() {
	glPushMatrix();
	//Drawing upper leg
	glRotatef(this->UPPER_ANGLE, 0.0, 0.0, 1.0);
	glTranslatef(this->UPPER_LEN / 2.0f, 0.0f, 0.0f);
	Utils::drawCube(this->UPPER_LEN, this->UPPER_THICKNESS, this->UPPER_WIDTH, this->type);
	//Drawing lower leg
	glTranslatef(this->UPPER_LEN / 2.0f, 0.0f, 0.0f);
	glRotatef(this->LOWER_ANGLE, 0.0, 0.0, 1.0);
	glTranslatef(this->LOWER_LEN / 2.0f, 0.0f, 0.0f);
	Utils::drawCube(this->LOWER_LEN, this->LOWER_THICKNESS, this->LOWER_WIDTH, this->type);
	//Drawing Feet
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(this->LOWER_LEN / 2.0f, -this->LOWER_THICKNESS / 2.0f, 0.0f);
	glRotatef(this->FEET_ANGLE, 0.0, 0.0, 1.0);
	glTranslatef(this->FEET_LEN / 2.0f, 0.0f, 0.0f);
	Utils::drawCube(this->FEET_LEN, this->FEET_THICKNESS, this->FEET_WIDTH, this->type);
	glPopMatrix();
}

float Animal::ROT_ANGLE = -70.0f; // Angle of ratation after taking one step ahead.
Animal::Animal() {} // Default construtor of Animal Class

					/*
					****************************************************************************************************
					Animal::resetAngle: Resets all NECK_ANGLE and HEAD_ANGLE.
					****************************************************************************************************
					*/
void Animal::resetParameters(int base) {
	this->NECK_ANGLE = 35.0;// Angle between neck and body in dergees
	this->HEAD_ANGLE = -this->NECK_ANGLE;
}

/*
****************************************************************************************************
Animal::resetAngle: Resets all leg angle.
****************************************************************************************************
*/
void Animal::resetAngles() {
	for (int i = 0; i < 4; i++) {
		legs[i] = Leg(-90.0, 25.0, -90.0, this->BODY_LENGTH*0.40, this->BODY_HEIGHT*0.4, this->BODY_WIDTH*0.4,
			this->BODY_LENGTH*0.25, this->BODY_HEIGHT*0.4, this->BODY_WIDTH*0.4);// Run a for loop here
		legs[i].FEET_ANGLE = -legs[i].UPPER_ANGLE - legs[i].LOWER_ANGLE;
		legs[i].FEET_LEN = legs[i].LOWER_THICKNESS*1.5;
		legs[i].FEET_THICKNESS = legs[i].LOWER_LEN*0.4f;
		legs[i].FEET_WIDTH = legs[i].LOWER_WIDTH;
		legs[i].type = this->type;
		if (i % 2 == 0) {
			legs[i].LOWER_ANGLE = 0.0f;
		}
	}

}
/*
****************************************************************************************************
Animal::Animal: Constructor of animal class. It takes the base length(Torso legth). It responsible
for setting up all angles.
****************************************************************************************************
*/
Animal::Animal(int base) {
	this->BASE = base;
	this->canMove = false;
	this->type = SOLID;
	this->SLICES = 10;
	this->STACKS = 10;
	this->moveNum = 1;
	this->BODY_LENGTH = this->BASE;
	this->BODY_HEIGHT = this->BASE*0.3;
	this->BODY_WIDTH = this->BASE*0.3;
	this->TAIL_LENGTH = this->BODY_LENGTH*0.6;
	this->TAIL_WIDTH = this->BODY_WIDTH*0.2;
	this->TAIL_HEIGHT = this->TAIL_WIDTH;
	this->LEG_X = this->BODY_LENGTH*0.3f;
	this->LEG_Y = 0.0f;
	this->LEG_Z = this->BODY_WIDTH*0.5f;
	for (int i = 0; i < 4; i++) {
		legs[i] = Leg(-90.0, 25.0, -90.0, this->BODY_LENGTH*0.30, this->BODY_HEIGHT*0.2, this->BODY_WIDTH*0.2,
			this->BODY_LENGTH*0.20, this->BODY_HEIGHT*0.2, this->BODY_WIDTH*0.2);// Run a for loop here
		legs[i].FEET_ANGLE = -legs[i].UPPER_ANGLE - legs[i].LOWER_ANGLE;
		legs[i].FEET_LEN = legs[i].LOWER_THICKNESS*1.5;
		legs[i].FEET_THICKNESS = legs[i].LOWER_LEN*0.4f;
		legs[i].FEET_WIDTH = legs[i].LOWER_WIDTH;
		legs[i].type = this->type;
		if (i % 2 == 0) {
			legs[i].LOWER_ANGLE = 0.0f;
		}
	}
	this->NECK_LENGTH = BASE*0.45f;
	this->NECK_WIDTH = this->BODY_WIDTH;
	this->NECK_HEIGHT = this->BODY_HEIGHT*0.4f;
	this->HEAD_LENGTH = this->NECK_LENGTH*0.5f;
	this->HEAD_HEIGHT = this->NECK_HEIGHT;
	this->HEAD_WIDTH = this->NECK_WIDTH;
	this->UPPER_HEAD_LENGTH = this->NECK_LENGTH / 2;
	this->UPPER_HEAD_HEIGHT = this->NECK_HEIGHT * 2;
	this->UPPER_HEAD_WIDTH = this->NECK_WIDTH;
	this->EYE_RADIUS = this->UPPER_HEAD_HEIGHT*0.20;
	this->resetParameters(base);
}

/*
***********************************************************************************************
Animal::drawAnimal: This function is used to draw the whole animal.
***********************************************************************************************
*/
void Animal::drawAnimal() {
	glPushMatrix();
	glTranslatef(x_pos, y_pos, z_pos);
	this->drawTorso();
	this->drawTail();
	this->drawFace();
	this->drawAllLegs();
	glPopMatrix();
}

/*
***********************************************************************************************
Animal::drawTorso: This function is used to draw the main body of the animal
***********************************************************************************************
*/
void Animal::drawTorso() {
	glPushMatrix();
	glColor3f(0.5f, 0.35f, 0.05f);
	Utils::drawCube(BODY_LENGTH, BODY_HEIGHT, BODY_WIDTH, this->type);
	glPopMatrix();
}
/*
***********************************************************************************************
Animal::drawFace: This function is used to draw the face of the animal
***********************************************************************************************
*/
void Animal::drawFace() {
	glPushMatrix();
	//Creating Neck
	glTranslatef(this->BODY_LENGTH*0.65, BODY_HEIGHT / 2.0f, 0.0f);
	glRotatef(this->NECK_ANGLE, 0.0f, 0.0f, 1.0f);
	glColor3f(0.5f, 0.35f, 0.05f);
	Utils::drawCube(NECK_LENGTH, NECK_HEIGHT, NECK_WIDTH, this->type);
	//Creating Face
	glRotatef(this->HEAD_ANGLE, 0.0f, 0.0f, 1.0f);
	glTranslatef(this->NECK_LENGTH*0.75, NECK_HEIGHT, 0.0f);
	glColor3f(0.5f, 0.35f, 0.05f);
	Utils::drawCube(HEAD_LENGTH, HEAD_HEIGHT, HEAD_WIDTH, this->type);
	//Creating Mouth
	glPushMatrix();
	glTranslatef(this->HEAD_LENGTH*0.5, 0.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	Utils::drawCube(HEAD_LENGTH*0.2, HEAD_HEIGHT, HEAD_WIDTH, this->type);
	glColor3f(0.5f, 0.35f, 0.05f);
	Utils::drawCube(HEAD_LENGTH*0.2, HEAD_HEIGHT*0.1, HEAD_WIDTH, this->type);
	glPopMatrix();
	//Drawing upper head
	glTranslatef(-1 * this->NECK_LENGTH*0.5, this->NECK_HEIGHT*0.25f, 0.0f);
	glColor3f(0, 0, 0);
	glPointSize(10);
	glColor3f(0.5f, 0.35f, 0.05f);
	Utils::drawCube(UPPER_HEAD_LENGTH, UPPER_HEAD_HEIGHT, UPPER_HEAD_WIDTH, this->type);
	//Drawing Eyes
	glPushMatrix();
	glTranslatef(this->UPPER_HEAD_LENGTH*0.5, this->UPPER_HEAD_HEIGHT*0.25, -this->UPPER_HEAD_WIDTH*0.40);
	glColor3f(0.0f, 0.0f, 0.0f);
	Utils::drawSphere(this->EYE_RADIUS, this->SLICES, this->STACKS, this->type);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(this->UPPER_HEAD_LENGTH*0.5, this->UPPER_HEAD_HEIGHT*0.25, this->UPPER_HEAD_WIDTH*0.40);
	glColor3f(0.0f, 0.0f, 0.0f);
	Utils::drawSphere(this->EYE_RADIUS, this->SLICES, this->STACKS, this->type);
	glPopMatrix();
	glPopMatrix();
}
/*
***********************************************************************************************
Animal::drawTail: This function is used to draw the tail of the animal
***********************************************************************************************
*/
void Animal::drawTail() {
	glPushMatrix();
	glTranslatef(-this->BODY_LENGTH / 2.0f - this->TAIL_LENGTH / 2.0f, 0.0f, 0.0f);
	glColor3f(0.5f, 0.35f, 0.05f);
	Utils::drawCube(this->TAIL_LENGTH, this->TAIL_HEIGHT, this->TAIL_WIDTH, this->type);
	glPopMatrix();
}
/*
***********************************************************************************************
Animal::drawAllLegs: This function is used to draw all 4 legs of the animal
***********************************************************************************************
*/
void Animal::drawAllLegs() {
	//For storing the legs in order
	int v[4][3] = {
		{ 1,1,1 },
		{ -1,-1,1 },
		{ 1,1,-1 },
		{ -1,-1,-1 }
	};
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.5f);
		glTranslatef(v[i][0] * LEG_X, v[i][1] * LEG_Y, v[i][2] * LEG_Z);
		legs[i].FEET_ANGLE = -legs[i].LOWER_ANGLE - legs[i].UPPER_ANGLE;
		legs[i].type = this->type;
		legs[i].drawLeg();
		glPopMatrix();
	}
}

/*
***********************************************************************************************
Animal::setPosition: This function is used to set the animals position (center of mass position)
***********************************************************************************************
*/
void Animal::setPosition(float x, float y, float z) {
	this->x_pos = x;
	this->y_pos = y;
	this->z_pos = z;
}

/*
***********************************************************************************************
Animal::move: This function is used to change the angle between legs while animal moves.
It is responsible of the movement of the animal.
***********************************************************************************************
*/
void Animal::move() {
	int v[4][3] = {
		{ 1,1,1 },
		{ -1,-1,1 },
		{ 1,1,-1 },
		{ -1,-1,-1 }
	};
	//First move the Torso
	this->x_pos += this->direction*this->legs[0].UPPER_LEN / tan(degreeToRadians(Utils::abs(Animal::ROT_ANGLE)));
	if (moveNum == 1 && this->direction == 1) {
		//Move Front Face
		legs[0].UPPER_ANGLE = Animal::ROT_ANGLE;
		legs[0].LOWER_ANGLE = -90.0f - Animal::ROT_ANGLE;
		legs[1].UPPER_ANGLE = Animal::ROT_ANGLE;

		//Keep back face as it is
		legs[2].LOWER_ANGLE = -90.0f - Animal::ROT_ANGLE;
		legs[2].UPPER_ANGLE = -180.0f - Animal::ROT_ANGLE;
		legs[3].UPPER_ANGLE = -180.0f - Animal::ROT_ANGLE;
	}
	if ((moveNum == 0 && this->direction == 1)) {
		//Move Front Face
		legs[2].UPPER_ANGLE = Animal::ROT_ANGLE;
		legs[2].LOWER_ANGLE = -90.0f - Animal::ROT_ANGLE;
		legs[3].UPPER_ANGLE = Animal::ROT_ANGLE;

		//Keep back face as it is
		legs[0].LOWER_ANGLE = -90.0f - Animal::ROT_ANGLE;
		legs[0].UPPER_ANGLE = -180.0f - Animal::ROT_ANGLE;
		legs[1].UPPER_ANGLE = -180.0f - Animal::ROT_ANGLE;
		//this->resetAngles();
	}
	if (moveNum == 0 && this->direction == -1) {
		//Move Front Face
		legs[0].UPPER_ANGLE = Animal::ROT_ANGLE;
		legs[0].LOWER_ANGLE = -90.0f - Animal::ROT_ANGLE;
		legs[1].UPPER_ANGLE = Animal::ROT_ANGLE;

		//Keep back face as it is
		legs[2].LOWER_ANGLE = -90.0f - Animal::ROT_ANGLE;
		legs[2].UPPER_ANGLE = -180.0f - Animal::ROT_ANGLE;
		legs[3].UPPER_ANGLE = -180.0f - Animal::ROT_ANGLE;
	}
	if ((moveNum == 1 && this->direction == -1)) {
		//Move Front Face
		legs[2].UPPER_ANGLE = Animal::ROT_ANGLE;
		legs[2].LOWER_ANGLE = -90.0f - Animal::ROT_ANGLE;
		legs[3].UPPER_ANGLE = Animal::ROT_ANGLE;

		//Keep back face as it is
		legs[0].LOWER_ANGLE = -90.0f - Animal::ROT_ANGLE;
		legs[0].UPPER_ANGLE = -180.0f - Animal::ROT_ANGLE;
		legs[1].UPPER_ANGLE = -180.0f - Animal::ROT_ANGLE;
		//this->resetAngles();
	}
	if (moveNum == 2) {
		//Set back to the original position
		this->resetAngles();
	}
	moveNum++;
	moveNum %= 3;
	//this->drawAnimal();
}