#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/ext.hpp>
#include <SDL2/SDL.h>

class controls
{
public:
	void computeMatricesFromInputs(SDL_Window* window, SDL_Event & event);
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();

private:

};
