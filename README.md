# CI224-Game-Development-KYLE-TUCKEY
Current C++ Assignment

Some of my work was the result of me following a tutorial:
http://www.opengl-tutorial.org/

He states that we can do whatever we want with his work here:
http://www.opengl-tutorial.org/download/

but rather than outright copy his work I decided to follow, learn,understand, and create my own work using SDL2 and build
it with boost.

the boost make files were created by my Tutor Aidan Delaney, and I have left in his readme file within the linux directory
to explain how to install.

you can find his gitHub account at:
https://github.com/AidanDelaney
# Running on windows:

the .exe in the debug folder should allow you to run it on any windows platform, however if you wish to run it in Visual
Studio, you will need to have a few things.

- updated Drivers
- SDL2 installed
- glew installed

you will also need to change the project settings that allow you to run the librarys and header files, to do this you:

1.) Open the project in visual studio
2.) right click your project solution > go to properties
3.) under "Configuration Properties" go to "C/C++"
4.) change the additional include directorys to the needed librarys that can be found in the folder you downloaded
  
    Currently they will be:
        C:\Users\Kyle\Documents\Visual Studio 2013\Projects\VoxelTask\glm\gtx
        C:\Users\Kyle\Documents\Visual Studio 2013\Projects\VoxelTask\glm\gtc
        C:\Users\Kyle\Documents\Visual Studio 2013\Projects\VoxelTask\glm
        C:\Users\Kyle\Documents\Visual Studio 2013\Projects\VoxelTask\glew-1.11.0\include\GL
        C:\Users\Kyle\Documents\Visual Studio 2013\Projects\VoxelTask\SDL2.0.3\include
        
5.) next go to linker > Additional Library Directories and again change them to match you current directory 

    Currently they will be:
      C:\Users\Kyle\Documents\Visual Studio 2013\Projects\VoxelTask\glew-1.11.0\lib\Release MX\Win32
      C:\Users\Kyle\Documents\Visual Studio 2013\Projects\VoxelTask\glew-1.11.0\lib\Release\Win32
      C:\Users\Kyle\Documents\Visual Studio 2013\Projects\VoxelTask\SDL2-2.0.3\lib\x86
      
