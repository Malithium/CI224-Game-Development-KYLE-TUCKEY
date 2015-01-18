#pragma once


#include <iostream>
#include <fstream>
#include <glew.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <sdl.h>
#include <string>
#include <vector>

class loadShaders
{

public:
	GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
private:
	// Create the shaders
	GLuint VertexShaderID;
	GLuint FragmentShaderID;

	std::string VertexShaderCode;
	std::string FragmentShaderCode;
	
	GLint Result = GL_FALSE;
	int InfoLogLength;

};

