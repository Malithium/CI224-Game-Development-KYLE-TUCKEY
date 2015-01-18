#include "stdafx.h"
#include "controls.h"


glm::mat4 viewMatrix;
glm::mat4 projectionMatrix;

///This method returns the ViewMatrix as its being changed
glm::mat4 controls::getViewMatrix(){
	return viewMatrix;
}

///This method returns the ProjectionMatrix as its being changed
glm::mat4 controls::getProjectionMatrix(){
	return projectionMatrix;
}
/// Initial position : on +Z
glm::vec3 position = glm::vec3(0, 0, 5);
/// Initial horizontal angle : toward -Z
float horizontalAngle = 3.14f;
/// Initial vertical angle : none
float verticalAngle = 0.0f;
/// Initial Field of View
float initialFoV = 45.0f;


///This method handles the various calculations needed in order to
///make the camera move and look around.
void controls::computeMatricesFromInputs(SDL_Window* window, SDL_Event& event){
	
	float speed = 3.0f;
	float mouseSpeed = 0.003f;
	int xpos, ypos;
	int midX, midY;

	///store the window sizes in these values
	SDL_GetWindowSize(window, &midX, &midY);

	///set thes values to hold the cordinates for the screens center
	midX = midX / 2;
	midY = midY / 2;
		
	static double lastTime = SDL_GetTicks(); ///get the time of the last frame
	double currentTime = SDL_GetTicks(); ///get the time of the current frame
	float deltaTime = (float)(currentTime - lastTime)/1000; ///minus the current time by the last time in order to get delta time

	///get the X and Y position of our mouse
	SDL_GetMouseState(&xpos, &ypos);
	///warp the mouse to the center of the screen
	SDL_WarpMouseInWindow(window, midX, midY);
	///disable the cursor so it isnt visible;
	SDL_ShowCursor(SDL_DISABLE);

	
	horizontalAngle += mouseSpeed * float(midX - xpos);///calculate the screens new angle
	verticalAngle += mouseSpeed * float(midY - ypos);

	///stops the camera from going upside down
	if (verticalAngle < -0.6f){
		verticalAngle = -0.6f;
	}
	else if (verticalAngle > 0.6f){
		verticalAngle = 0.6f;
	}

	glm::vec3 direction(cos(verticalAngle) * sin(horizontalAngle), sin(verticalAngle), cos(verticalAngle) * cos(horizontalAngle));
	glm::vec3 right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f), 0, cos(horizontalAngle - 3.14f / 2.0f));
	glm::vec3 up = glm::cross(right, direction);

	///detect wether the w,a,s,d keys have been pressed or are being held, and move the camera
	if (event.type == SDL_KEYDOWN){
		switch (event.key.keysym.sym){
		case SDLK_w:
			std::cout << "Pressed Up!:\n" << glm::to_string(position) << std::endl;
			position += direction * deltaTime * speed;
			std::cout << "\n Changed Matrix:\n" << glm::to_string(position) + "\n" << std::endl;
			break;
		case SDLK_s:
			std::cout << "Pressed Down!:\n" << glm::to_string(position) << std::endl;
			position -= direction * deltaTime * speed;
			std::cout << "\n Changed Matrix:\n" << glm::to_string(position) + "\n" << std::endl;
			break;
		case SDLK_d:
			std::cout << "Pressed Right!:\n" << glm::to_string(position) << std::endl;
			position += right * deltaTime * speed;
			std::cout << "\n Changed Matrix:\n" << glm::to_string(position) + "\n" << std::endl;
			break;
		case SDLK_a:
			std::cout << "Pressed Left!:\n" << glm::to_string(position) << std::endl;
			position -= right * deltaTime * speed;
			std::cout << "\n Changed Matrix:\n" << glm::to_string(position) + "\n" << std::endl;
			break;
		}

	}
	
	float FoV = initialFoV;
	projectionMatrix = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);
	viewMatrix = glm::lookAt(position, position + direction, up);

	///set the value of LastTime to be currentTime
	lastTime = currentTime;
	std::cout << verticalAngle << std::endl;
	std::cout << horizontalAngle << std::endl;
}


