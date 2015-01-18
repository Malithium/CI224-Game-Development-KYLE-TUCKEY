#define GLM_FORCE_RADIANS
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>
#include <vector>
#include <string>

#include <boost/program_options.hpp>

#include <src/loadShaders.h>
#include <src/controls.h>
#include <src/Cube.h>

int main(int argc, char *argv[])
{
	Cube cube_system;
	int cubeLimit = 0;

	//initialise SDL
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	//setup the SDL window, context and event
	SDL_Window* window = SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(window);
	SDL_Event windowEvent;

	glewExperimental=true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
    	fprintf(stderr, "Failed to initialize GLEW\n");
    	return -1;
	}

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	glClearColor(0.0f, 0.5f, 0.0f, 0.0f);
	
	//initialises the Cubes buffers
	cube_system.initialiseCube();

	//SDL game loop
	while (true)
	{
		if (SDL_PollEvent(&windowEvent)){
			cube_system.initialiseDraw(window, windowEvent); ///binds buffers as well as calls keyboard and mouse input 
			
			///
			///Draw the cube plane and construct.
			///@bug
			///The cubes are not drawn in the built version of the program
			///They are however drawn in the Visual Studio Debugger,
			///the cause at the moment is not known.

			cube_system.drawPlane(); //draws a plane of red cubes
			cube_system.drawConstruction(); //draws a green cube
			cube_system.update(window); //updates the window
			cube_system.swapBuffers(window); //swaps the buffers

				
			if (windowEvent.type == SDL_KEYUP && ///give the ability to exit via the escape button
				windowEvent.key.keysym.sym == SDLK_ESCAPE) break;
			
		}
	}

	//Delete stuff to avoid memory leaks
	cube_system.destroyBuffers(); 
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}