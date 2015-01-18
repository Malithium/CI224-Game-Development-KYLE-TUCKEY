#pragma once

#include <glm.hpp>
#include <matrix_transform.hpp>
#include <transform.hpp>
#include <gtx/string_cast.hpp>
#include <sdl.h>
#include <iostream>

class controls
{
public:
	void computeMatricesFromInputs(SDL_Window* window, SDL_Event & event);
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();

private:

};

