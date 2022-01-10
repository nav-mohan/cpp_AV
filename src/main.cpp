#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "read_md.hpp"
#include "encode.hpp"
#include "encode.hpp"
#include <GLFW/glfw3.h>

int main(void){
	printf("Hello World\n");
	char* filename = "/Users/nav/Documents/Vegan Sushi.mp3";
	read_md(filename);

	encode_audio("hahah.mp3");

//
//GLFW
//STUFF
//
	GLFWwindow* window;
	
	if(!glfwInit()){
		printf("Couldn't init window\n");
		return 1;
	}
	
	window = glfwCreateWindow(800, 480, "Hello World", NULL, NULL);
	if(!window){
		printf("Couldn't open window\n");
		return 1;
	}

	glfwMakeContextCurrent(window);

	while(!glfwWindowShouldClose(window)){
		//Swap Buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	
	return 0;
}
