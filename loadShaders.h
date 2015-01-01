#pragma once


#include <iostream>
#include <fstream>
#define GLEW_STATIC
#include <glew.h>
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <sdl/sdl.h>
#include <string>
#include <vector>

class loadShaders
{

public:

	GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
};

