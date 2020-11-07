#include <iostream> 
#include <vector> 
#include <fstream> 
#include <inttypes.h>
#include "BMP_Reader.h"
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main()
{
	int w, h, i, j;
	std::vector<unsigned char> img;
    std::string path("/home/nowfal/Coding_task/BMP_task/bmp_images");
    std::string ext(".bmp");
    for (auto &p : fs::recursive_directory_iterator(path))
    {
        if (p.path().extension() == ext)
        {	
        	std::cout << "in if"<< "\n"; 

        	//img = read_bmp(p.path().stem().string()+".bmp", w, h); 
        	img = read_bmp(path+"/"+ p.path().stem().string()+".bmp", w, h);
			char bits[] = "10";


			for (j = 0; j < h; j++)
			{ 
				for (i = 0; i < w; i++) 
				std::cout << bits[img[j * w + i]] << " ";  
			std::cout << "\n"; 
			}

			std::cout << "Width_o: " << w << "\n"; 
			std::cout << "Height_o: " << h << "\n";
            std::cout << path+"/"+ p.path().stem().string()+".bmp" << '\n';
            //std::string filename = p.path().stem().string()+".bmp";
        	//std::cout << filename << '\n';
        }

    }
    return 0;
}

/*int main() { 
	int w, h, i, j; 
	std::vector<unsigned char> img = read_bmp("/home/nowfal/Coding_task/BMP_task/bmp_images/1.bmp", w, h); 
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
}*/