#include <iostream> 
#include <vector> 
#include <fstream> 
#include <inttypes.h>
#include <string>
#include <experimental/filesystem>
#include "BMP_Reader.h" 

std::vector<unsigned char> read_bmp(std::string const &fname, int& w, int& h) { 
	bmp_header head; 
	std::ifstream f(fname, std::ios::binary); 
 
	f.read((char *)&head, sizeof(head)); 
 
	if (head.bits_per_pixel != 1) 
		return{}; 
 
	w = head.width; 
	h = head.height; 
	std::cout <<"in the loop"<< "\n"; 
	std::cout << "Width_i: " << w << "\n"; 
	std::cout << "Height_i: " << h << "\n";
 
	// lines are aligned on 4-byte boundary 
	int lineSize = (w / 8 + (w / 8) % 4); 
	int fileSize = lineSize * h; 
 
	std::vector<unsigned char> img(w*h); 
	std::vector<unsigned char> data(fileSize); 
 
	// find bits 
	f.seekg(head.offset); 
 
	// read data 
	f.read((char *)&data[0], fileSize); 

	/*for (j = 0; j < h; j++) 	{ 
		for (i = 0; i < w; i++) 
			//std::cout << bits[img[j * w + i]] << " "; 
			std::cout << head.GetPixel(i,j) << "\n"; 
		std::cout << "\n"; 
	}*/
 
	// decode bits 
	int i, j, k, rev_j; 
	for (j = 0, rev_j = h - 1; j < h; j++, rev_j--) { 
		for (i = 0; i < w / 8; i++) { 
			int fpos = j * lineSize + i, pos = rev_j * w + i * 8; 
			for (k = 0; k < 8; k++) 
				img[pos + (7 - k)] = (data[fpos] >> k) & 1; 
		} 
	} 
	return img; 
} 