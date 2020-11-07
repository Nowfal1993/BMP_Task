#include <iostream> 
#include <vector> 
#include <fstream> 
#include <inttypes.h>
#include <ctime> 
#include <experimental/filesystem>
#include "BMP_Reader.h"

namespace fs = std::experimental::filesystem;

int main()
{
	int w, h, i, j;
	std::vector<unsigned char> img;
	// Start measuring time
	std::clock_t c_start = std::clock();

    std::string path("/home/nowfal/Coding_task/BMP_task/bmp_images");
    std::string ext(".bmp");
    for (auto &p : fs::recursive_directory_iterator(path))
    {
        if (p.path().extension() == ext)
        {	
        	img = read_bmp(path+"/"+ p.path().stem().string()+".bmp", w, h);
			char bits[] = "10";


			for (j = 0; j < h; j++)
			{ 
				for (i = 0; i < w; i++) 
				std::cout << bits[img[j * w + i]] << " ";  
			std::cout << "\n"; 
			}

			std::cout << "Width: " << w << "\n"; 
			std::cout << "Height: " << h << "\n";
            std::cout << path+"/"+ p.path().stem().string()+".bmp" << '\n';
            
        }

    }
    // Stop measuring time and calculate the elapsed time
	std::clock_t c_end = std::clock();

	long double time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
	std::cout << "CPU time used: " << time_elapsed_ms << " ms\n";

    return 0;
}
