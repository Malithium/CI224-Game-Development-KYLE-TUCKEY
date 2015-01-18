#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include "loadShaders.h"
#include "controls.h"
class Cube
{
public:
	void initialiseCube(); /// This method generates our cubes buffers
	void initialiseDraw(SDL_Window* window, SDL_Event& SDLevent); /// binds out buffers and sends them to our GPU
	void drawConstruction(); ///stores our cubes into a vector of 4x4 matrices, used to construct the green construct
	void update(SDL_Window* window); ///updates our SDL window
	void swapBuffers(SDL_Window* window);
	void drawPlane(); ///calls the storePlatform method and draws our cubes
	void destroyBuffers(); ///destroys the buffers and the programID

private:
	loadShaders shader; ///Call in our shader class
	controls controller; ///call in our controller class

	float cubeOffsetZ = 0.01f;
	float cubeOffsetX = 0.01f;
	int vectorPos = 0;
	int size;

	GLuint VertexArrayID;
	GLuint programID;
	GLuint MatrixID;

	glm::mat4 ProjectionMatrix;
	glm::mat4 ViewMatrix;
	glm::mat4 ModelMatrix;
	glm::mat4 MVP;

	GLuint vertex_buffer;
	GLuint element_buffer;
	GLuint colour_buffer;
	GLuint colour_buffer_2;
};
