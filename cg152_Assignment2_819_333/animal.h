/*
Amitayush Thakur	2012B4A7819P
*/
#include <GL/glut.h>
#define PI 3.1415926535897932384626433832795

typedef enum cubeType { SOLID, WIRED }CubeType; // enum defined for choosing btw SOLID and WIRED representation
												//The class defined forr constructing Legs of the animal
class Leg {
public:
	CubeType type;
	float upper_leg_x;		// x coordinate of the upper leg  in world coordinates
	float upper_leg_y;		// y coordinate of the upper leg in world coordinates
	float upper_leg_z;		// z coordinate of the upper leg in world coordinates
	float lower_leg_x;		// x coordinate of the lower leg in world coordinates
	float lower_leg_y;		// y coordinate of the lower leg in world coordinates
	float lower_leg_z;		// z coordinate of the lower leg in world coordinates
	float feet_x;			// x coordinate of the feet in world coordinates
	float feet_y;			// y coordinate of the feet  in world coordinates
	float feet_z;			// z coordinate of the feet leg in world coordinates
	float UPPER_ANGLE;		// Angle that upper leg makes with Torso Clock and negative
	float LOWER_ANGLE;		// Angle that lower leg makes with upper leg Clock and negative
	float FEET_ANGLE;		// Angle that feet makes with lower leg AntiClock and positive
	float FEET_LEN;			// length of feet
	float FEET_THICKNESS;	// thickness of feet
	float FEET_WIDTH;		// width of feet
	float UPPER_LEN;		// length of upper leg
	float UPPER_THICKNESS;	// thickness of upper leg
	float UPPER_WIDTH;		// width of upper leg
	float LOWER_LEN;		// length of lower leg
	float LOWER_THICKNESS;	// thickness of lower leg
	float LOWER_WIDTH;		// width of lower leg
	Leg();
	Leg(float UPPER_ANGLE, float LOWER_ANGLE, float FEET_ANGLE,
		float UPPER_LEN, float UPPER_THICKNESS, float UPPER_WIDTH,
		float LOWER_LEN, float LOWER_THICKNESS, float LOWER_WIDTH);
	void drawLeg();
};

// class that is used to construct the whole Animal
class Animal {
public:
	Leg legs[4];
	int moveNum;
	int direction;
	static float ROT_ANGLE;//angle made w.r.t hip when the animal moves
	float BASE;
	float SLICES;
	float STACKS;
	CubeType type;
	bool canMove;
	float LEG_X;//Distance of leg from the center of the body in X direction
	float LEG_Y;//Distance of leg from the center of the body in Y direction
	float LEG_Z;//Distance of leg from the center of the body in Z direction
	float BODY_LENGTH;
	float BODY_HEIGHT;
	float BODY_WIDTH;
	float NECK_ANGLE;
	float HEAD_ANGLE;
	float NECK_LENGTH;
	float NECK_HEIGHT;
	float NECK_WIDTH;
	float HEAD_HEIGHT;
	float HEAD_LENGTH;
	float HEAD_WIDTH;
	float UPPER_HEAD_HEIGHT;
	float UPPER_HEAD_LENGTH;
	float UPPER_HEAD_WIDTH;
	float EYE_RADIUS;
	float TAIL_LENGTH;
	float TAIL_WIDTH;
	float TAIL_HEIGHT;
	float x_pos;
	float y_pos;
	float z_pos;
	Animal();
	Animal(int base);
	void setPosition(float x, float y, float z);
	void resetParameters(int base);
	void drawAnimal();
	void drawTorso();
	void drawFace();
	void drawTail();
	void drawAllLegs();
	void move();
	void resetAngles();
};

// class of utility functions
class Utils {
public:
	static void drawCube(float length, float height, float width, CubeType cubeType);
	static void drawWireCube(float length, float height, float width);
	static void drawSolidCube(float length, float height, float width);
	static void drawSphere(float radius, float slices, float stacks, CubeType type);
	static float abs(float a);
};

