#pragma once

#include <vector>
using namespace std;

#include "..\glew\glew.h"		// include GL Extension Wrangler
#include "..\glfw\glfw3.h"  // include GLFW helper library
#include "glm.hpp"

#include "Shape.h"
#include "Sphere.h"
#include "Cube.h"
#include "Player.h"
#include "Light.h"
#include "Cam.h"

class World {

public:

	vector<Shape*> objects;
	Player player;
	Light light;
	Cam cam;
	Shape cubeTemplate;
	Shape sphereTemplate;
	World();
	World(GLuint shader_program);
	//void registerVAOS(vector<GLuint>* vaos);
	void draw();
	void rotateWorld(float speed);
	void translate(glm::vec3 translateBy);
	void generateShapeOnClickCallback(Shape *shape);
	void destroy();

};