#pragma once

#include <cmath>

#include "..\glew\glew.h"		// include GL Extension Wrangler
#include "..\glfw\glfw3.h"  
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "gtc/constants.hpp"
using namespace glm;

#include <vector>
using namespace std;
#include "GLOBALS.h"
#include "Shape.h"
#include "World.h"

void computeMatricesFromInputs();

void keypress_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
void watchCursorCallback(GLFWwindow *window, double xpos, double ypos);
void mouseButtonCallback();
void mouseScrollCallback(GLFWwindow *window, double xoffset, double yoffset);
void toggleShader();

