#pragma once
class bitmap
{
private:

public:
	
	bitmap();
	~bitmap();

	unsigned int height;
	unsigned int width;
	unsigned char *Rdata;
	unsigned char *Gdata;
	unsigned char *Bdata;

	//取得に成功すればポインタを失敗すればNULLを返す
	bool read_bmp(char* filename);
};

