// MyPrintf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define _ADDRESSOF(v) (&reinterpret_cast<const char &>(v))
typedef char* va_list;
#define _INTSIZEOF(n)  ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) -1))
#define va_start(ap,v) ( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v))
#define va_arg(ap,t) ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
#define va_end(ap)  (ap = (va_list)0)

int __cdecl MyPrintf(const char *fmt, ...)
{
	va_list vaptr;
	va_start(vaptr, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			switch (*++fmt)
			{			
			case 'c':
			{
				char value;
				//value = va_arg(vaptr, char);  错误 在可变长参数中，应用的是"加宽"原则。也就是float类型被扩展成double；char, short被扩展成int。
				value = (char)va_arg(vaptr, int);
				putchar(value);
				break;
			}
			case 'd':
			{
				int value;
				char buf[12];
				char *pBuf = buf;
				value = va_arg(vaptr, int);
				if (value < 0)
				{
					value = -value;
					buf[0] = '-';
					pBuf = buf + 1;
				}

				int len = 1;
				int temp = value;
				while (temp / 10)
				{
					temp /= 10;
					len++;
				}
				temp = value;
				*(pBuf + len) = 0;

				while (len)
				{
					int t = temp % 10;
					*(pBuf - 1 + len--) = t + '0';
					temp /= 10;
				}
				fputs(buf, stdout);
				break;
			}
			case 'f':
			{
				float value;
				char buf[32];
				char *pBuf = buf;
				value = (float)va_arg(vaptr, double);
				if (value < 0)
				{
					value = -value;
					buf[0] = '-';
					pBuf = buf + 1;
				}

				//处理整数位
				int intergerlen = 1;
				int  integer = (int)value;
				while (integer / 10)
				{
					integer /= 10;
					intergerlen++;
				}
				integer = (int)value;

				int len = intergerlen;
				while (len)
				{
					int t = integer % 10;
					*(pBuf - 1 + len--) = t + '0';
					integer /= 10;
				}

				*(pBuf + intergerlen) = '.';
				pBuf = pBuf + intergerlen + 1;
				//处理小数位
				float decimals = value - (int)value;
				//8位小数
				decimals *= 100000000;
				int decimalslen = 8;
				int  int_decimals = (int)decimals;
				*(pBuf + decimalslen) = 0;
				while (decimalslen)
				{
					int t = int_decimals % 10;
					*(pBuf - 1 + decimalslen--) = t + '0';
					int_decimals /= 10;
				}
				fputs(buf, stdout);
				break;
			}
			case 's':
			{
				char *pValue;
				//此处传参为地址 lea eax,[str]
				pValue = (char *)va_arg(vaptr, int);
				fputs(pValue, stdout);
				break;
			}
			default:
				break;
			}
		}
		else
		{
			putchar(*fmt);
		}
		++fmt;
	}
	va_end(vaptr);
	return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = -120;
	char b = 'a';
	char str[] = "I'm Jovi";
	float f = 123.1415f;
	MyPrintf("输出为:a=%d , b=%c , str=%s , f=%f ",a,b,str,f);
	getchar();
	return 0;
}

