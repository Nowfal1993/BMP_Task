#include <iostream> 
#include <vector> 
#include <fstream> 
#include <inttypes.h>
#include "BMP_Reader.h"

int main() { 
	int w, h, i, j; 
	std::vector<unsigned char> img = read_bmp("1.bmp", w, h); 
	char bits[] = "10"; 
 
	//std::cout << " Width: " << w << "\n"; 
	//std::cout << "Height: " << h << "\n"; 
 
	for (j = 0; j < h; j++) 	{ 
		for (i = 0; i < w; i++) 
			std::cout << bits[img[j * w + i]] << " ";  
		std::cout << "\n"; 
	}

	std::cout << "Width: " << w << "\n"; 
	std::cout << "Height: " << h << "\n"; 

 
	return 0; 
}