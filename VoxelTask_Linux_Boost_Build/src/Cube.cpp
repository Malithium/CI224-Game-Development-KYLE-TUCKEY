#include "Cube.h"


void Cube::initialiseCube()
{
	
	static const GLfloat cube_vertex_array[] = {
		-1.0f, -1.0f, -1.0f, // triangle 1 : begin
		-1.0f, -1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, // triangle 1 : end
		1.0f, 1.0f, -1.0f, // triangle 2 : begin
		-1.0f, -1.0f, -1.0f,
		-1.0f, 1.0f, -1.0f, // triangle 2 : end
		1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, 1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, -1.0f,
		1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, 1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, -1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, -1.0f, 1.0f
	};

	
	static const GLfloat cube_color_array[] = {///this is to be used for the color of our plane

		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
	};
	
	
	static const GLfloat cube_color_array_2[] = {///this is to be used for the color of our construct

		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,

		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,

		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,

		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,

		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,

		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,

		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,

		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,

		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
	};



	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	
	programID = shader.LoadShaders("shaders/VertexShader.vertexshader", "shaders/FragmentShader.fragmentshader"); ///load in the Vertex shader and the fragement shader
	MatrixID = glGetUniformLocation(programID, "MVP"); 


	glGenBuffers(1, &vertex_buffer); 	//Vertex Buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertex_array), cube_vertex_array, GL_STATIC_DRAW);


	glGenBuffers(1, &colour_buffer); 	//Red Colour Buffer
	glBindBuffer(GL_ARRAY_BUFFER, colour_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_color_array), cube_color_array, GL_STATIC_DRAW);


	glGenBuffers(1, &colour_buffer_2);	//Green Colour Buffer
	glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_color_array_2), cube_color_array_2, GL_STATIC_DRAW);
}

/*
*binds out buffers and sends them to our GPU
*/

void Cube::initialiseDraw(SDL_Window* window, SDL_Event& SDLevent){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);/// Clear the screen

	
	glUseProgram(programID);/// Use our shader

	
	controller.computeMatricesFromInputs(window,SDLevent);/// Compute the MVP matrix from keyboard and mouse input

	// 1st attribute buffer : verteces
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glVertexAttribPointer(
		0,                  // attribute.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
		);

	// 2nd attribute buffer : colours
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colour_buffer);
	glVertexAttribPointer(
		1,                                // attribute.
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
		);

}

void Cube::drawPlane(){ ///Draws our red cube plane
	ProjectionMatrix = controller.getProjectionMatrix();
	ViewMatrix = controller.getViewMatrix();
	float xOffset = 0.0f;
	float zOffset = 0.0f;
	for (int i = 0; i < 10; i++){
		for (int p = 0; p < 10; p++){
			ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(xOffset,-2.0f,zOffset));
			MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
			MatrixID = glGetUniformLocation(programID, "MVP");
			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
			glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
			xOffset = xOffset + 2.0f;
		}
		xOffset = 0.0f;
		zOffset = zOffset + 2.0f;
	}
}


void Cube::drawConstruction(){ ///draws our green construction
	// 2nd attribute buffer : colours
	glDisableVertexAttribArray(1);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_2);
	glVertexAttribPointer(
		1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
		);
	
	ProjectionMatrix = controller.getProjectionMatrix();
	ViewMatrix = controller.getViewMatrix();
	float xOffset = 2.1f;
	float zOffset = 2.1f;
	float yOffset = 2.1f;

	ModelMatrix = glm::translate(glm::mat4(1.1f), glm::vec3(xOffset, yOffset, zOffset));
	MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
	MatrixID = glGetUniformLocation(programID, "MVP");
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
}

void Cube::update(SDL_Window* window){ ///updates our window
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	SDL_UpdateWindowSurface(window);
	
}

void Cube::swapBuffers(SDL_Window* window){
	SDL_GL_SwapWindow(window);
}

void Cube::destroyBuffers(){ ///destroys our buffers and deletes the programID
	glDeleteBuffers(1, &vertex_buffer);
	glDeleteBuffers(1, &colour_buffer);
	glDeleteBuffers(1, &colour_buffer_2);
	glDeleteBuffers(1, &element_buffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(programID);
}


