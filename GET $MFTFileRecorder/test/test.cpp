// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <vector>

#define HIGH_BYTE(x)  (((x) & 0xf0)>>4)
#define LOW_BYTE(x)   ((x) & 0x0f)

typedef struct _MFT_MAP_
{
	//起始簇和数量
	UINT64 Startcluster;
	UINT64 ClusterCount;
}MFT_MAP, *PMFT_MAP;

int _tmain(int argc, _TCHAR* argv[])
{
	//获得$MFT中所有FileRecord
	WCHAR driver[] = L"\\\\.\\E:";
	LARGE_INTEGER li = { 0 };
	BYTE buffer[1024] = { 0 };
	HANDLE hFile = CreateFile(driver, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	li.QuadPart = 3221225472;
	SetFilePointer(hFile, li.LowPart, &li.HighPart, FILE_BEGIN);
	ReadFile(hFile, &buffer, 1024, NULL, NULL);
	UINT16 offset = 0;
	LARGE_INTEGER totaloffset = { 0 };
	std::vector<MFT_MAP> mftmap;

	if (buffer[0] == 'F' && buffer[1] == 'I' && buffer[2] == 'L' && buffer[3] == 'E' && buffer[4] == '0')
	{
		//第一属性偏移
		offset = buffer[0x14];
		//寻找80H
		while(offset < 1024)
		{
			if (buffer[offset] == 0x80)
			{
				break;
			}
			offset += buffer[offset + 0x4];
		}
	}

	//获得属性长度
	UINT16 attr_len = buffer[offset + 0x4];
	UINT16 DataRun_offset = buffer[offset + 0x20];
	UINT16 DataRun_start = offset + DataRun_offset;
	UINT16 DataRun_len = offset + attr_len - DataRun_start;
	
	//存储DataRun
	std::vector<BYTE> vecDataRun;
	for (size_t i = 0; i < DataRun_len; i++)
	{
		vecDataRun.push_back(buffer[DataRun_start + i]);
	}

	//分析Datarun
	UINT64 LatestStartCluster = 0x00;
	std::vector<BYTE>::size_type index = 0;
	while (index < vecDataRun.size() && vecDataRun[index] != 0)
	{
		//得到长度(低字节)和偏移簇序数(高字节)
		UINT16 high = HIGH_BYTE(vecDataRun[index]);
		UINT16 low = LOW_BYTE(vecDataRun[index]);

		//判断是否到尾部
		if (high == 0 && low == 0)
		{
			break;
		}
		if ((index + low + high) >= vecDataRun.size())
		{
			break;
		}

		//获取MFT区域长度
		UINT16 temp = low;
		UINT64 len = 0;
		while (temp)
		{
			len <<= 8;
			len += vecDataRun[index + temp];
			temp--;
		}

		////////计算VCN////////
		temp = high;
		INT64 startclusteroffser = 0;
		while (temp)
		{
			startclusteroffser <<= 8;
			startclusteroffser += vecDataRun[index + low + temp];
			temp--;
		}
		if (len == 0 || startclusteroffser == 0 )
		{
			break;
		}

		//HighbitIndex表示有几个字节有效
		size_t HighbitIndex = high;
		//有效最高位
		UINT16 Highbit = (startclusteroffser >> (8 * HighbitIndex - 1)) & 1;

		//若最高位为1则取补码
		if (Highbit)
		{
			//取反，+1
			std::vector<char> vecHex;
			UINT64 temp = ((~startclusteroffser) << (8 * (8 - HighbitIndex)));
			for (size_t i = 0; i < HighbitIndex ; i++)
			{
				vecHex.push_back(((temp) >> (8 * (8 - HighbitIndex + i))) & 0xff);
			}
			startclusteroffser = 0;
			for (std::vector<char>::size_type n = 0; n < vecHex.size(); ++n)
			{
				startclusteroffser <<= 8;
				startclusteroffser += vecHex[vecHex.size() - 1 - n];
			}
			startclusteroffser += 1;
			startclusteroffser = -startclusteroffser;
		}

		//保存MFT区域信息
		if (startclusteroffser <= 0 && (UINT64)abs(startclusteroffser) >= LatestStartCluster )
		{
			break;
		}
		LatestStartCluster += startclusteroffser;
		MFT_MAP MFTtemp{ LatestStartCluster, len };
		mftmap.push_back(MFTtemp);

		//下一循环
		index = ((index + high + low + 1) >= vecDataRun.size() ? vecDataRun.size() : (index + high + low + 1));
	}
	system("pause");
	return 0;
}

