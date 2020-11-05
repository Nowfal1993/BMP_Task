#ifndef BMP_READER_H_
#define BMP_READER_H_

#pragma pack(push, 1) 
struct bmp_header { 
	char magic[2];	 
	uint32_t fileSize; 
	uint32_t res; 
	uint32_t offset; 
	uint32_t header_size; 
	uint32_t width; 
	uint32_t height; 
	uint16_t bits_per_pixel; 
}; 
#pragma pack(pop) 

std::vector<unsigned char> read_bmp(std::string const &fname, int& w, int& h);

#endif