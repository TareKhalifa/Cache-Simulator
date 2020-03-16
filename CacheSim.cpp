#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
using namespace std;

#define DRAM_SIZE (64*1024*1024)
#define CACHE_SIZE (64*1024)
int timee;
int L1cache, L2cache, L3cache;
enum cacheResType { MISS = 0, HIT = 1 };
int iter;
unsigned int m_w = 0xABABAB55; /* must not be zero, nor 0x464fffff */
unsigned int m_z = 0x05080902; /* must not be zero, nor 0x9068ffff */
int cache[3][1000000];
int L1cash[3][1000000];
int L11cash[3][1000000];
int L22cash[3][1000000];
int L111cash[3][1000000];
int L222cash[3][1000000];
int L333cash[3][1000000];
int fcash[3][10000000];
int f4[5][10000000];
int f5[4][10000000];
int f51[4][10000000];
int f511[4][10000000];
int f522[4][10000000];
int f5111[4][10000000];
int f5222[4][10000000];
int f5333[4][10000000];
int recentt, cursor, recentcounter, recentline;
int* firstcounter1;
int* firstcounter11;
int* firstcounter22;
int* firstcounter111;
int* firstcounter222;
int* firstcounter333;
int* firstcounter;

bool exitflag = true;
int resetter;
int offset, indexx, tag, shiftamount, blocksize, lines, hits = 0, misses = 0, compmiss = 0, capmiss = 0, conmiss = 0, countt = 0;
unsigned int rand_()
{
	m_z = 36969 * (m_z & 65535) + (m_z >> 16);
	m_w = 18000 * (m_w & 65535) + (m_w >> 16);
	return (m_z << 16) + m_w; /* 32-bit result */
}


unsigned int memGen1()
{
	static unsigned int addr = 0;
	return (addr += (16 * 1024)) % (256 * 1024);
}
unsigned int memGen2()
{
	static unsigned int addr = 0;
	return (addr += 4) % (DRAM_SIZE);
}

unsigned int memGen3()
{

	return rand_() % (256 * 1024);
}

// Cache Simulator
cacheResType cacheSim(unsigned int addr)
{
	lines = CACHE_SIZE / blocksize;
	shiftamount = log2(blocksize);
	indexx = (addr >> shiftamount);
	indexx = indexx % lines;
	shiftamount = log2(CACHE_SIZE);
	tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
	if (cache[2][indexx] == 0)
	{
		cache[1][indexx] = tag;
		cache[0][indexx] = addr;
		compmiss++;
		cache[2][indexx] = 1;
		return MISS;
	}
	else
	{
		if (tag == cache[1][indexx])

		{
			hits++;
			cache[2][indexx] = 1;
			return HIT;
		}
		else {
			cache[1][indexx] = tag;
			cache[0][indexx] = addr;
			conmiss++;
			cache[2][indexx] = 1;
			return MISS;
		}
	}
}
void Exp5(unsigned int addr, int ways)
{
	lines = 16384 / (8 * ways);
	shiftamount = log2(8);
	indexx = (addr >> shiftamount);
	indexx = indexx % lines;
	shiftamount = log2(lines * 8);
	tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
	int set = indexx;
	indexx *= ways;
	int xya = 9999999;
	int gg;
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f5[3][lkj] < xya)
		{
			xya = f5[3][lkj];
			gg = lkj;
		}
	}
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f5[2][lkj] == 0)
		{
			f5[1][lkj] = tag;
			f5[0][lkj] = addr;
			misses++;
			f5[2][lkj] = 1;
			f5[3][lkj] = firstcounter[set];
			firstcounter[set]++;
			goto label33;
		}
		else if (tag == f5[1][lkj])
		{
			hits++;
			f5[2][lkj] = 1;
			goto label33;

		}
	}
	if (tag == f5[1][gg])

	{
		hits++;
		f5[2][gg] = 1;
		goto label33;
	}
	else {
		f5[1][gg] = tag;
		f5[0][gg] = addr;
		misses++;
		f5[2][gg] = 1;
		f5[3][gg] = firstcounter[set];
		firstcounter[set]++;
		goto label33;
	}
label33:
	int yjgtb = 9;
}
void Exp51(unsigned int addr, int ways)
{
	lines = (256 * 1024) / (64 * ways);
	shiftamount = log2(64);
	indexx = (addr >> shiftamount);
	indexx = indexx % lines;
	shiftamount = log2(lines * ways);
	tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
	int set = indexx;
	indexx *= ways;
	int xya = 9999999;
	int gg;
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f51[3][lkj] < xya)
		{
			xya = f51[3][lkj];
			gg = lkj;
		}
	}
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f51[2][lkj] == 0)
		{
			f51[1][lkj] = tag;
			f51[0][lkj] = addr;
			f51[2][lkj] = 1;
			f51[3][lkj] = firstcounter1[set];
			firstcounter1[set]++;
			timee += 111;
			return;
		}
		else if (tag == f51[1][lkj])
		{
			timee += 11;
			f51[2][lkj] = 1;
			return;

		}
	}
	if (tag == f51[1][gg])

	{
		timee += 11;
		f51[2][gg] = 1;
		return;
	}
	else {
		f51[1][gg] = tag;
		f51[0][gg] = addr;
		f51[2][gg] = 1;
		f51[3][gg] = firstcounter1[set];
		firstcounter1[set]++;
		timee += 111;
		return;
	}
}
void Exp522(unsigned int addr, int ways)
{
	lines = (256 * 1024) / (64 * ways);
	shiftamount = log2(64);
	indexx = (addr >> shiftamount);
	indexx = indexx % lines;
	shiftamount = log2(lines * ways);
	tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
	int set = indexx;
	indexx *= ways;
	int xya = 9999999;
	int gg;
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f522[3][lkj] < xya)
		{
			xya = f522[3][lkj];
			gg = lkj;
		}
	}
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f522[2][lkj] == 0)
		{
			f522[1][lkj] = tag;
			f522[0][lkj] = addr;
			timee += 115;
			f522[2][lkj] = 1;
			f522[3][lkj] = firstcounter22[set];
			firstcounter22[set]++;
			return;
		}
		else if (tag == f522[1][lkj])
		{
			timee += 15;
			f522[2][lkj] = 1;
			return;

		}
	}
	if (tag == f522[1][gg])

	{
		timee += 15;
		f522[2][gg] = 1;
		return;
	}
	else {
		f522[1][gg] = tag;
		f522[0][gg] = addr;
		f522[2][gg] = 1;
		f522[3][gg] = firstcounter22[set];
		firstcounter22[set]++;
		timee += 115;
		return;
	}
}

void Exp511(unsigned int addr, int ways)
{
	lines = (32 * 1024) / (64 * ways);
	shiftamount = log2(64);
	indexx = (addr >> shiftamount);
	indexx = indexx % lines;
	shiftamount = log2(lines * ways);
	tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
	int set = indexx;
	indexx *= ways;
	int xya = 9999999;
	int gg;
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f511[3][lkj] < xya)
		{
			xya = f511[3][lkj];
			gg = lkj;
		}
	}
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f511[2][lkj] == 0)
		{
			f511[1][lkj] = tag;
			f511[0][lkj] = addr;
			f511[2][lkj] = 1;
			f511[3][lkj] = firstcounter11[set];
			firstcounter11[set]++;
			Exp522(addr, ways);
			return;
		}
		else if (tag == f511[1][lkj])
		{
			timee += 4;
			f511[2][lkj] = 1;
			return;

		}
	}
	if (tag == f511[1][gg])

	{
		timee += 4;
		f511[2][gg] = 1;
		return;
	}
	else {
		f511[1][gg] = tag;
		f511[0][gg] = addr;
		f511[2][gg] = 1;
		f511[3][gg] = firstcounter11[set];
		firstcounter11[set]++;
		Exp522(addr, ways);
		return;
	}
}
void Exp5333(unsigned int addr, int ways)
{
	lines = (8192 * 1024) / (64 * ways);
	shiftamount = log2(64);
	indexx = (addr >> shiftamount);
	indexx = indexx % lines;
	shiftamount = log2(lines*ways);
	tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
	int set = indexx;
	indexx *= ways;
	int xya = 9999999;
	int gg;
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f5333[3][lkj] < xya)
		{
			xya = f5333[3][lkj];
			gg = lkj;
		}
	}
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f5333[2][lkj] == 0)
		{
			f5333[1][lkj] = tag;
			f5333[0][lkj] = addr;
			timee += 145;
			f5333[2][lkj] = 1;
			f5333[3][lkj] = firstcounter333[set];
			firstcounter333[set]++;
			return;
		}
		else if (tag == f5333[1][lkj])
		{
			timee += 45;
			f5333[2][lkj] = 1;
			return;

		}
	}
	if (tag == f5333[1][gg])

	{
		timee += 45;
		f5333[2][gg] = 1;
		return;
	}
	else {
		timee += 145;
		return;
	}
}

void Exp5222(unsigned int addr, int ways)
{
	lines = (256 * 1024) / (64 * ways);
	shiftamount = log2(64);
	indexx = (addr >> shiftamount);
	indexx = indexx % lines;
	shiftamount = log2(lines * ways);
	tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
	int set = indexx;
	indexx *= ways;
	int xya = 9999999;
	int gg;
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f5222[3][lkj] < xya)
		{
			xya = f5222[3][lkj];
			gg = lkj;
		}
	}
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f5222[2][lkj] == 0)
		{
			f5222[1][lkj] = tag;
			f5222[0][lkj] = addr;
			f5222[2][lkj] = 1;
			f5222[3][lkj] = firstcounter222[set];
			firstcounter222[set]++;
			Exp5333(addr, 16);
			return;
		}
		else if (tag == f5222[1][lkj])
		{
			timee += 15;
			f5222[2][lkj] = 1;
			return;

		}
	}
	if (tag == f5222[1][gg])

	{
		timee += 15;
		f5222[2][gg] = 1;
		return;
	}
	else {
		f5222[1][gg] = tag;
		f5222[0][gg] = addr;
		f5222[2][gg] = 1;
		f5222[3][gg] = firstcounter222[set];
		firstcounter222[set]++;
		Exp5333(addr, 16);
		return;
	}
}


void Exp5111(unsigned int addr, int ways)
{
	lines = (32 * 1024) / (64 * ways);
	shiftamount = log2(64);
	indexx = (addr >> shiftamount);
	indexx = indexx % lines;
	shiftamount = log2(lines * ways);
	tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
	int set = indexx;
	indexx *= ways;
	int xya = 9999999;
	int gg;
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f5111[3][lkj] < xya)
		{
			xya = f5111[3][lkj];
			gg = lkj;
		}
	}
	for (int lkj = indexx; lkj < indexx + ways; lkj++)
	{
		if (f5111[2][lkj] == 0)
		{
			f5111[1][lkj] = tag;
			f5111[0][lkj] = addr;
			f5111[2][lkj] = 1;
			f5111[3][lkj] = firstcounter111[set];
			firstcounter111[set]++;
			Exp5222(addr, ways);
			return;
		}
		else if (tag == f5111[1][lkj])
		{
			timee += 4;
			f5111[2][lkj] = 1;
			return;

		}
	}
	if (tag == f5111[1][gg])

	{
		timee += 4;
		f5111[2][gg] = 1;
		return;
	}
	else {
		f5111[1][gg] = tag;
		f5111[0][gg] = addr;
		f5111[2][gg] = 1;
		f5111[3][gg] = firstcounter111[set];
		firstcounter111[set]++;
		Exp5222(addr, ways);
		return;
	}
}

void Fully(unsigned int addr, int cachesize)
{
	lines = cachesize / 16;
	tag = addr >> (4); // shifted the amount the offset and the index sizes
	for (int k = 0; k < lines; k++)
	{
		if (fcash[2][lines - 1] == 1)
		{
			int aqw = 0;
			while (fcash[2][aqw] == 1)
			{
				if (tag == fcash[1][aqw])
				{
					hits++;
					recentt = k;
					goto label;

				}
				aqw++;
			}
			fcash[1][recentt] = tag;
			fcash[2][recentt] = 1;
			fcash[0][recentt] = addr;
			misses++;
			goto label;
		}
		else {
			while (fcash[2][k] == 1)
			{
				// cout << "WHILE" << endl;
				if (tag == fcash[1][k])
				{
					hits++;
					recentt = k;
					goto label;

				}
				else
					k++;
			}
			fcash[1][k] = tag;
			fcash[2][k] = 1;
			fcash[0][k] = addr;
			misses++;
			recentt = k;
			goto label;
		}

	}
label:
	int bbb = 1;
}
void Fully4(unsigned int addr, int cachesize)
{
	lines = cachesize / 32;
	tag = addr >> (5); // shifted the amount the offset and the index sizes
	for (int k = 0; k < lines; k++)
	{
		// cout << k << endl;
		if (f4[2][lines - 1] == 1)
		{
			int aqw = 0;
			while (f4[2][aqw] == 1)
			{
				//cout << "WHILE" << endl;
				if (tag == f4[1][aqw])
				{
					hits++;
					goto label2;
				}
				aqw++;
			}
			recentt = rand() % lines;
			f4[1][recentt] = tag;
			f4[2][recentt] = 1;
			f4[0][recentt] = addr;
			misses++;
			goto label2;
		}
		else {
			while (f4[2][k] == 1)
			{
				// cout << "WHILE" << endl;
				if (tag == f4[1][k])
				{
					hits++;
					goto label2;

				}
				else
					k++;
			}
			f4[1][k] = tag;
			f4[2][k] = 1;
			f4[0][k] = addr;
			misses++;
			goto label2;
		}
		cout << "FOR" << endl;
	}
label2:
	int bbb = 1;
}
void Fully42(unsigned int addr, int cachesize, int type)
{
	lines = cachesize / 32;
	tag = addr >> (5); // shifted the amount the offset and the index sizes
	for (int k = 0; k < lines; k++)
	{
		// cout << k << endl;
		if (f4[2][lines - 1] == 1)
		{
			int aqw = 0;
			while (f4[2][aqw] == 1)
			{
				//cout << "WHILE" << endl;
				if (tag == f4[1][aqw])
				{
					f4[3][aqw] = recentcounter;
					recentcounter++;
					f4[4][aqw]++;
					hits++;
					goto label2;
				}
				aqw++;
			}
			if (type % 2 == 0)
			{
				for (int rr = 0; rr < lines && f4[2][rr] == 1; rr++)
				{
					if (recentt > f4[3][rr])
						recentt = f4[3][rr];
					recentline = rr;
				}
			}
			else
			{
				for (int rr = 0; rr < lines && f4[2][rr] == 1; rr++)
				{
					if (recentt > f4[4][rr])
						recentt = f4[4][rr];
					recentline = rr;
				}
			}
			f4[1][recentline] = tag;
			f4[2][recentline] = 1;
			f4[0][recentline] = addr;
			f4[3][recentline] = recentcounter;
			recentcounter++;
			f4[4][recentt] = 1;
			misses++;
			goto label2;
		}
		else {
			while (f4[2][k] == 1)
			{
				// cout << "WHILE" << endl;
				if (tag == f4[1][k])
				{
					f4[3][k] = recentcounter;
					recentcounter++;
					f4[4][k]++;
					hits++;
					goto label2;

				}
				else
					k++;
			}
			f4[1][k] = tag;
			f4[2][k] = 1;
			f4[0][k] = addr;
			misses++;
			f4[3][k] = recentcounter;
			recentcounter++;
			f4[4][k]++;
			goto label2;
		}
		cout << "FOR" << endl;
	}
label2:
	int bbb = 1;
}
void L2cachewhat(unsigned int addr)
{
	lines = (256 * 1024) / 64;
	shiftamount = log2(64);
	indexx = (addr >> shiftamount);
	indexx = indexx % lines;
	shiftamount = log2(256 * 1024);
	tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
	if (L22cash[2][indexx] == 0)
	{
		L22cash[1][indexx] = tag;
		L22cash[0][indexx] = addr;
		compmiss++;
		L22cash[2][indexx] = 1;
		timee += 115;
	}
	else
	{
		if (tag == L22cash[1][indexx])

		{
			L22cash[2][indexx] = 1;
			timee += 15;
		}
		else {
			L22cash[1][indexx] = tag;
			L22cash[0][indexx] = addr;
			L22cash[2][indexx] = 1;
			timee += 115;
		}
	}
}
void L33cachewhat(unsigned int addr)
{
	lines = (8192 * 1024) / 64;
	shiftamount = log2(64);
	indexx = (addr >> shiftamount);
	indexx = indexx % lines;
	shiftamount = log2(8192 * 1024);
	tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
	if (L333cash[2][indexx] == 0)
	{
		L333cash[1][indexx] = tag;
		L333cash[0][indexx] = addr;
		L333cash[2][indexx] = 1;
		timee += 145;
	}
	else
	{
		if (tag == L333cash[1][indexx])

		{
			L333cash[2][indexx] = 1;
			timee += 45;
		}
		else {
			L333cash[1][indexx] = tag;
			L333cash[0][indexx] = addr;
			L333cash[2][indexx] = 1;
			timee += 145;
		}
	}
}

void L22cachewhat(unsigned int addr)
{
	lines = (256 * 1024) / 64;
	shiftamount = log2(64);
	indexx = (addr >> shiftamount);
	indexx = indexx % lines;
	shiftamount = log2(256 * 1024);
	tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
	if (L222cash[2][indexx] == 0)
	{
		L222cash[1][indexx] = tag;
		L222cash[0][indexx] = addr;
		L222cash[2][indexx] = 1;
		L33cachewhat(addr);
	}
	else
	{
		if (tag == L222cash[1][indexx])

		{
			L222cash[2][indexx] = 1;
			timee += 15;
		}
		else {
			L222cash[1][indexx] = tag;
			L222cash[0][indexx] = addr;
			L222cash[2][indexx] = 1;
			L33cachewhat(addr);
		}
	}
}
void cacheSimExp2(unsigned int addr, int x)
{
	if (x == 1)
	{
		lines = L1cache / 64;
		shiftamount = log2(64);
		indexx = (addr >> shiftamount);
		indexx = indexx % lines;
		shiftamount = log2(L1cache);
		tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
		if (L1cash[2][indexx] == 0)
		{
			L1cash[1][indexx] = tag;
			L1cash[0][indexx] = addr;
			L1cash[2][indexx] = 1;
			timee += 111;
		}
		else
		{
			if (tag == L1cash[1][indexx])

			{
				hits++;
				L1cash[2][indexx] = 1;
				timee += 11;
			}
			else {
				L1cash[1][indexx] = tag;
				L1cash[0][indexx] = addr;
				L1cash[2][indexx] = 1;
				timee += 111;
			}
		}
	}
	else if (x == 2)
	{
		lines = (32 * 1024) / 64;
		shiftamount = log2(64);
		indexx = (addr >> shiftamount);
		indexx = indexx % lines;
		shiftamount = log2(32 * 1024);
		tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
		if (L11cash[2][indexx] == 0)
		{
			L11cash[1][indexx] = tag;
			L11cash[0][indexx] = addr;
			L11cash[2][indexx] = 1;
			L2cachewhat(addr);
		}
		else
		{
			if (tag == L11cash[1][indexx])

			{
				hits++;
				L11cash[2][indexx] = 1;
				timee += 4;
			}
			else {
				conmiss++;
				L11cash[1][indexx] = tag;
				L11cash[0][indexx] = addr;
				L11cash[2][indexx] = 1;
				L2cachewhat(addr);
			}
		}
	}
	else if (x == 3)
	{
		lines = (32 * 1024) / 64;
		shiftamount = log2(64);
		indexx = (addr >> shiftamount);
		indexx = indexx % lines;
		shiftamount = log2(32 * 1024);
		tag = addr >> (shiftamount); // shifted the amount the offset and the index sizes
		if (L111cash[2][indexx] == 0)
		{
			L111cash[1][indexx] = tag;
			L111cash[0][indexx] = addr;
			L111cash[2][indexx] = 1;
			L22cachewhat(addr);
		}
		else
		{
			if (tag == L111cash[1][indexx])

			{
				L111cash[2][indexx] = 1;
				timee += 4;
			}
			else
			{
				L111cash[1][indexx] = tag;
				L111cash[0][indexx] = addr;
				L111cash[2][indexx] = 1;
				L22cachewhat(addr);
			}
		}
	}

}
//char* msg[2] = { "Miss","Hit" };

int main()
{
	srand(time(NULL));
	int experiment;
	cout << "enter the number of the experiment you want to run: ";
	cin >> experiment;

	switch (experiment)
	{
		//EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1
		//EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1 EXP1

	case 1:
		unsigned int addr;
		cout << "Cache Simulator\n";
		cacheResType r;

		// change the number of iterations into a minimum of 1,000,000
		for (int d = 4; d < 129; d *= 2)
		{
			blocksize = d;
			lines = CACHE_SIZE / blocksize;
			cout << "Results for block size = " << d << " and memgen1" << endl;
			for (int lol1 = 0; lol1 < 3; lol1++)
				for (int lol = 0; lol < lines; lol++)
					cache[lol1][lol] = 0;
			compmiss = 0; conmiss = 0; hits = 0; countt = 0;
			for (iter = 0; iter < 1000000; iter++)
			{
				addr = memGen1();
				r = cacheSim(addr);
			}
			misses = compmiss + conmiss + capmiss;
			cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;
			cout << "Results for block size = " << d << " and memgen2" << endl;
			compmiss = 0; conmiss = 0; hits = 0; countt = 0;
			for (int lol1 = 0; lol1 < 3; lol1++)
				for (int lol = 0; lol < lines; lol++)
					cache[lol1][lol] = 0;
			for (iter = 0; iter < 1000000; iter++)

			{
				addr = memGen2();
				r = cacheSim(addr);
			}
			misses = compmiss + conmiss + capmiss;
			cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;

			cout << "Results for block size = " << d << " and memgen3" << endl;
			compmiss = 0; conmiss = 0; hits = 0; countt = 0;
			for (int lol1 = 0; lol1 < 3; lol1++)
				for (int lol = 0; lol < lines; lol++)
					cache[lol1][lol] = 0;
			for (iter = 0; iter < 1000000; iter++)
			{
				addr = memGen3();
				r = cacheSim(addr);
			}
			misses = compmiss + conmiss + capmiss;
			cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;
		}
		break;
		//ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1
		//ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1 ENDOFEXP1
	case 2:

		L1cache = (256 * 1024);
		timee = 0;
		for (int rrr = 0; rrr < 3; rrr++)
			for (int rr = 0; rr < 1000000; rr++)
				L1cash[rrr][rr] = 0;

		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen1();
			cacheSimExp2(addr, 1);
		}
		cout << "The total time of L1 memgen1 = " << timee << endl;

		for (int rrr = 0; rrr < 3; rrr++)
			for (int rr = 0; rr < 1000000; rr++)
			{
				L11cash[rrr][rr] = 0;
				L22cash[rrr][rr] = 0;
			}
		timee = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen1();
			cacheSimExp2(addr, 2);
		}
		cout << "The total time of L2 memgen1 = " << timee << endl;
		for (int rrr = 0; rrr < 3; rrr++)
			for (int rr = 0; rr < 1000000; rr++)
			{
				L111cash[rrr][rr] = 0;
				L222cash[rrr][rr] = 0;
				L333cash[rrr][rr] = 0;
			}
		timee = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen1();
			cacheSimExp2(addr, 3);
		}
		cout << "The total time of L3 memgen1 = " << timee << endl;
		timee = 0;
		for (int rrr = 0; rrr < 3; rrr++)
			for (int rr = 0; rr < 1000000; rr++)
				L1cash[rrr][rr] = 0;

		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen2();
			cacheSimExp2(addr, 1);
		}
		cout << "The total time of L1 memgen2 = " << timee << endl;


		for (int rrr = 0; rrr < 3; rrr++)
			for (int rr = 0; rr < 1000000; rr++)
			{
				L11cash[rrr][rr] = 0;
				L22cash[rrr][rr] = 0;
			}

		timee = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen2();
			cacheSimExp2(addr, 2);
		}
		cout << "The total time of L2 memgen2 = " << timee << endl;
		for (int rrr = 0; rrr < 3; rrr++)
			for (int rr = 0; rr < 1000000; rr++)
			{
				L111cash[rrr][rr] = 0;
				L222cash[rrr][rr] = 0;
				L333cash[rrr][rr] = 0;
			}
		timee = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen2();
			cacheSimExp2(addr, 3);
		}
		cout << "The total time of L3 memgen2 = " << timee << endl;
		timee = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen3();
			cacheSimExp2(addr, 1);
		}
		for (int rrr = 0; rrr < 3; rrr++)
			for (int rr = 0; rr < 1000000; rr++)
				L1cash[rrr][rr] = 0;

		cout << "The total time of L1 memgen3 = " << timee << endl;
		for (int rrr = 0; rrr < 3; rrr++)
			for (int rr = 0; rr < 1000000; rr++)
			{
				L11cash[rrr][rr] = 0;
				L22cash[rrr][rr] = 0;
			}

		timee = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen3();
			cacheSimExp2(addr, 2);
		}
		cout << "The total time of L2 memgen3 = " << timee << endl;

		for (int rrr = 0; rrr < 3; rrr++)
			for (int rr = 0; rr < 1000000; rr++)
			{
				L111cash[rrr][rr] = 0;
				L222cash[rrr][rr] = 0;
				L333cash[rrr][rr] = 0;
			}
		timee = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen3();
			cacheSimExp2(addr, 3);
		}
		cout << "The total time of L3 memgen3 = " << timee << endl;

		break;
	case 3:
		for (int xx = 4096; xx <= (64 * 1024); xx *= 2)
		{
			misses = 0; hits = 0; recentt = 0;
			for (int df = 0; df < 3; df++)
				for (int dff = 0; dff < 10000000; dff++)
					fcash[df][dff] = 0;
			for (iter = 0; iter < 1000000; iter++)
			{
				addr = memGen1();
				Fully(addr, xx);
			}
			cout << "Cache size : " << xx << "" << "\nmemgen1: " << endl;
			cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;
		}

		for (int xx = 4096; xx <= (64 * 1024); xx *= 2)
		{
			for (int df = 0; df < 3; df++)
				for (int dff = 0; dff < 10000000; dff++)
					fcash[df][dff] = 0;
			misses = 0; hits = 0; recentt = 0;
			for (iter = 0; iter < 1000000; iter++)
			{
				addr = memGen2();
				Fully(addr, xx);
			}
			cout << "Cache size : " << xx << "" << "\nmemgen2: " << endl;
			cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;
		}
		for (int xx = 4096; xx <= (64 * 1024); xx *= 2)
		{
			for (int df = 0; df < 3; df++)
				for (int dff = 0; dff < 10000000; dff++)
					fcash[df][dff] = 0;
			misses = 0; hits = 0; recentt = 0;
			for (iter = 0; iter < 1000000; iter++)
			{
				addr = memGen3();
				Fully(addr, xx);
			}
			cout << "Cache size : " << xx << "" << "\nmemgen3: " << endl;
			cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;
		}
		break;
	case 4:
	{
		srand(time(NULL));
		for (int df = 0; df < 5; df++)
			for (int dff = 0; dff < 10000000; dff++)
				f4[df][dff] = 0;
		misses = 0; hits = 0; recentt = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen1();
			//cout << iter << endl;
			Fully4(addr, 256 * 1024);
		}
		cout << "Experiment 4 random " << "memgen1: " << endl;
		cout << setfill('0') << setw(8) << dec << /*iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << */"Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;

		for (int df = 0; df < 5; df++)
			for (int dff = 0; dff < 10000000; dff++)
				f4[df][dff] = 0;
		misses = 0; hits = 0; recentt = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen2();
			//cout << iter << endl;
			Fully4(addr, 256 * 1024);
		}
		cout << "Experiment 4 random " << "memgen2: " << endl;
		cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;

		for (int df = 0; df < 5; df++)
			for (int dff = 0; dff < 10000000; dff++)
				f4[df][dff] = 0;
		misses = 0; hits = 0; recentt = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen3();
			//cout << iter << endl;
			Fully4(addr, 256 * 1024);
		}
		cout << "Experiment 4 random " << "memgen3: " << endl;
		cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;


		recentcounter = 0;
		for (int df = 0; df < 5; df++)
			for (int dff = 0; dff < 10000000; dff++)
				f4[df][dff] = 0;
		misses = 0; hits = 0; recentt = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen1();
			//cout << iter << endl;
			Fully42(addr, 256 * 1024, 0);
		}
		cout << "Experiment 4 LRU " << "memgen1: " << endl;
		cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;
		recentcounter = 0;
		for (int df = 0; df < 5; df++)
			for (int dff = 0; dff < 10000000; dff++)
				f4[df][dff] = 0;
		misses = 0; hits = 0; recentt = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen2();
			//cout << iter << endl;
			Fully42(addr, 256 * 1024, 0);
		}
		cout << "Experiment 4 LRU " << "memgen2: " << endl;
		cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;
		recentcounter = 0;
		for (int df = 0; df < 5; df++)
			for (int dff = 0; dff < 10000000; dff++)
				f4[df][dff] = 0;
		misses = 0; hits = 0; recentt = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen3();
			//cout << iter << endl;
			Fully42(addr, 256 * 1024, 0);
		}
		cout << "Experiment 4 LRU " << "memgen3: " << endl;
		cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;



		for (int df = 0; df < 5; df++)
			for (int dff = 0; dff < 10000000; dff++)
				f4[df][dff] = 0;
		misses = 0; hits = 0; recentt = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen1();
			//cout << iter << endl;
			Fully42(addr, 256 * 1024, 1);
		}
		cout << "Experiment 4 LFU " << "memgen1: " << endl;
		cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;

		for (int df = 0; df < 5; df++)
			for (int dff = 0; dff < 10000000; dff++)
				f4[df][dff] = 0;
		misses = 0; hits = 0; recentt = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen2();
			//cout << iter << endl;
			Fully42(addr, 256 * 1024, 1);
		}
		cout << "Experiment 4 LFU " << "memgen2: " << endl;
		cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;

		for (int df = 0; df < 5; df++)
			for (int dff = 0; dff < 10000000; dff++)
				f4[df][dff] = 0;
		misses = 0; hits = 0; recentt = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen3();
			//cout << iter << endl;
			Fully42(addr, 256 * 1024, 1);
		}
		cout << "Experiment 4 LFU " << "memgen3: " << endl;
		cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;


		recentcounter = 0;
		for (int df = 0; df < 5; df++)
			for (int dff = 0; dff < 10000000; dff++)
				f4[df][dff] = 0;
		misses = 0; hits = 0; recentt = 0; int mode = 0;
		double ratio;

		for (iter = 0; iter < 50000; iter++)
		{
			addr = memGen1();
			//cout << iter << endl;
			Fully42(addr, 256 * 1024, 0);
		}
		ratio = double(hits) / double(double(hits) + double(misses));
		mode += 1;
		for (iter = 0; iter < 950000; iter++)
		{
			if (iter % 10000 == 0)
				if (double(hits) / (double(hits) + double(misses)) < ratio)
					mode += 1;

			addr = memGen1();
			//cout << iter << endl;
			Fully42(addr, 256 * 1024, mode);
		}
		cout << "Experiment 4 Adaptive LRU/LFU " << "memgen1: " /*<< endl*/;
		cout << setfill('0') << setw(8) << dec << iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << "Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;

		recentcounter = 0;
		for (int df = 0; df < 5; df++)
			for (int dff = 0; dff < 10000000; dff++)
				f4[df][dff] = 0;
		misses = 0; hits = 0; recentt = 0; mode = 0;

		for (iter = 0; iter < 100; iter++)
		{
			addr = memGen2();
			//cout << iter << endl;
			Fully42(addr, 256 * 1024, 0);
		}
		ratio = double(hits) / double(double(hits) + double(misses));
		mode += 1;
		for (iter = 0; iter < 950000; iter++)
		{
			if (iter % 10000 == 0)
				if (double(hits) / (double(hits) + double(misses)) < ratio)
					mode += 1;
			addr = memGen2();
			//cout << iter << endl;
			Fully42(addr, 256 * 1024, mode);
		}
		cout << "Experiment 4 Adaptive LRU/LFU " << "memgen2: " /*<< endl*/;
		cout << setfill('0') << setw(8) << dec <</* iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << */"Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;

		recentcounter = 0;
		for (int df = 0; df < 5; df++)
			for (int dff = 0; dff < 10000000; dff++)
				f4[df][dff] = 0;
		misses = 0; hits = 0; recentt = 0; mode = 0;

		for (iter = 0; iter < 50000; iter++)
		{
			addr = memGen3();
			//cout << iter << endl;
			Fully42(addr, 256 * 1024, 0);
		}
		ratio = double(hits) / double(double(hits) + double(misses));
		mode += 1;
		for (iter = 0; iter < 950000; iter++)
		{
			if (iter % 10000 == 0)
				if (double(hits) / (double(hits) + double(misses)) < ratio)
					mode += 1;

			addr = memGen3();
			if (iter == 949999)
				cout << addr << endl;
			//cout << iter << endl;
			Fully42(addr, 256 * 1024, mode);
		}
		cout << "Experiment 4 Adaptive LRU/LFU " << "memgen3: " /*<< endl*/;
		cout << setfill('0') << setw(8) << dec << /*iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "\n" << */"Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;
	}
	break;

	case 5:

		for (int wayss = 2; wayss <= 16; wayss *= 2)
		{
			firstcounter = new int[2048 / wayss];
			misses = 0; hits = 0; recentt = 0;
			for (int ii = 0; ii < 2048 / wayss; ii++)
				firstcounter[ii] = 0;
			for (int df = 0; df < 4; df++)
				for (int dff = 0; dff < 10000000; dff++)
					f5[df][dff] = 0;
			for (iter = 0; iter < 1000000; iter++)
			{
				addr = memGen1();
				Exp5(addr, wayss);
			}
			cout << hits << "\n" << misses << endl;
			cout << setfill('0') << setw(8) << dec << "Number of ways = " << wayss << " memgen1 " <</*iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "EXP5 " << */"Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;
		}

		for (int wayss = 2; wayss <= 16; wayss *= 2)
		{
			firstcounter = new int[2048 / wayss];
			misses = 0; hits = 0; recentt = 0;
			for (int ii = 0; ii < 2048 / wayss; ii++)
				firstcounter[ii] = 0;
			for (int df = 0; df < 4; df++)
				for (int dff = 0; dff < 10000000; dff++)
					f5[df][dff] = 0;
			for (iter = 0; iter < 1000000; iter++)
			{
				addr = memGen2();
				Exp5(addr, wayss);
			}
			cout << hits << "\n" << misses << endl;

			cout << setfill('0') << setw(8) << dec << "Number of ways = " << wayss << " memgen2 " <</*iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "EXP5 " << */"Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;
		}

		for (int wayss = 2; wayss <= 16; wayss *= 2)
		{
			firstcounter = new int[2048 / wayss];
			misses = 0; hits = 0; recentt = 0;
			for (int ii = 0; ii < 2048 / wayss; ii++)
				firstcounter[ii] = 0;
			for (int df = 0; df < 4; df++)
				for (int dff = 0; dff < 10000000; dff++)
					f5[df][dff] = 0;
			for (iter = 0; iter < 1000000; iter++)
			{
				addr = memGen3();
				Exp5(addr, wayss);
			}
			cout << hits << "\n" << misses << endl;

			cout << setfill('0') << setw(8) << dec << "Number of ways = " << wayss << " memgen3 " <</*iter << "\n" << "Hits: " << hits << "\n" << "Misses: " << misses << "EXP5 " << */"Hit ratio = " << (double(hits) / double(misses + hits)) * 100 << "%" << endl << endl;
		}

		break;
	case 6:
		firstcounter1 = new int[1000000];
		firstcounter11 = new int[1000000];
		firstcounter111 = new int[1000000];
		firstcounter22 = new int[1000000];
		firstcounter222 = new int[1000000];
		firstcounter333 = new int[1000000];
		timee = 0; hits = 0; misses = 0;
		for (int batata = 0; batata < 4; batata++)
			for (int iba = 0; iba < 1000000; iba++)
				f51[batata][iba] = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen1();
			Exp51(addr, 8);
		}
		cout << "EXP 6 1 level memgen1: \nThe time is: " << timee << "\n" << "\n";

		timee = 0; hits = 0; misses = 0;
		for (int batata = 0; batata < 4; batata++)
			for (int iba = 0; iba < 1000000; iba++)
				f51[batata][iba] = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen2();
			Exp51(addr, 8);
		}
		cout << "EXP 6 1 level memgen2: \nThe time is: " << timee << "\n" << "\n";

		timee = 0; hits = 0; misses = 0;
		for (int batata = 0; batata < 4; batata++)
			for (int iba = 0; iba < 1000000; iba++)
				f51[batata][iba] = 0;
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen3();
			Exp51(addr, 8);
		}
		cout << "EXP 6 1 level memgen3: \nThe time is: " << timee << "\n" << "\n";
		timee = 0;

		for (int batata = 0; batata < 4; batata++)
			for (int iba = 0; iba < 1000000; iba++)
			{
				f511[batata][iba] = 0;
				f522[batata][iba] = 0;
			}
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen1();
			Exp511(addr, 8);
		}
		cout << "EXP 6 2 level memgen1: \nThe time is: " << timee << "\n" << "\n";

		timee = 0; hits = 0; misses = 0;

		for (int batata = 0; batata < 4; batata++)
			for (int iba = 0; iba < 1000000; iba++)
			{
				f511[batata][iba] = 0;
				f522[batata][iba] = 0;
			}
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen2();
			Exp511(addr, 8);
		}
		cout << "EXP 6 2 level memgen2: \nThe time is: " << timee << "\n" << "\n";

		timee = 0; hits = 0; misses = 0;

		for (int batata = 0; batata < 4; batata++)
			for (int iba = 0; iba < 1000000; iba++)
			{
				f511[batata][iba] = 0;
				f522[batata][iba] = 0;
			}
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen3();
			Exp511(addr, 8);
		}
		cout << "EXP 6 2 level memgen3: \nThe time is: " << timee << "\n" << "\n";


		timee = 0;
		for (int batata = 0; batata < 4; batata++)
			for (int iba = 0; iba < 1000000; iba++)
			{
				f5111[batata][iba] = 0;
				f5222[batata][iba] = 0;
				f5333[batata][iba] = 0;

			}
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen1();
			Exp5111(addr, 8);
		}
		cout << "EXP 6 3 level memgen1: \nThe time is: " << timee << "\n" << "\n";

		timee = 0; hits = 0; misses = 0;
		for (int batata = 0; batata < 4; batata++)
			for (int iba = 0; iba < 1000000; iba++)
			{
				f5111[batata][iba] = 0;
				f5222[batata][iba] = 0;
				f5333[batata][iba] = 0;
			}
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen2();
			Exp5111(addr, 8);
		}
		cout << "EXP 6 3 level memgen2: \nThe time is: " << timee << "\n" << "\n";

		timee = 0; hits = 0; misses = 0;
		for (int batata = 0; batata < 4; batata++)
			for (int iba = 0; iba < 1000000; iba++)
			{
				f5111[batata][iba] = 0;
				f5222[batata][iba] = 0;
				f5333[batata][iba] = 0;
			}
		for (iter = 0; iter < 1000000; iter++)
		{
			addr = memGen3();
			Exp5111(addr, 8);
		}
		cout << "EXP 6 3 level memgen3: \nThe time is: " << timee << "\n" << "\n";
		break;

	}
}