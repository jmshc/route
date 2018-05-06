#include"map_.h"

//map_ ��ʼ�������ļ��ж�ȡmap_��Ϣ
void CMap::InitCMap()
{
	LoadPoinInfo(POIN_FILENAME);
	LoadLineInfo(LINE_FILENAME);

}

// load poininfo
void CMap::LoadPoinInfo(const std::string& filename)
{
	char szBuf[256] = { 0 };
	char szTemp[256] = { 0 };
	int iTempIndex = 0;
	double x = 0.0;
	double y = 0.0;
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cout << "�޷����ļ�" << filename.c_str() << std::endl;
		exit(1);
	}

	while (!file.eof())
	{
		iTempIndex = 0, x = 0.0, y = 0.0;
		memset((void *)szTemp, 0x00, sizeof(szTemp));
		memset((void *)szBuf, 0x00, sizeof(szBuf));

		file.getline(szBuf, sizeof(szBuf) - 1, '\n');
		if(szBuf[0] == NULL)
		{
			continue;
		}

		// ��������1�ģ��빹���ļ���ʱ���һ�е��ַ���������< 255
		for (int index = 0; index <= (int)strlen(szBuf); index++)
		{
			if (szBuf[index] != ' ' && szBuf[index] != '\0' && szBuf[0] != '\n')
			{
				szTemp[iTempIndex++] = szBuf[index];
			}else
			{
				if (szTemp[0] != '\0')
				{
					if(x == 0.0)
					{
						x = atof(szTemp);
					}else
					{
						y = atof(szTemp);
						AddPoin(x, y);
						break;
					}
				}
				iTempIndex = 0;
				memset((void *)szTemp, 0x00, sizeof(szTemp));
			}
		}// end for
	}//end while
	file.close();
}

// load lineinfo
void CMap::LoadLineInfo(const std::string& filename)
{
	char szBuf[256] = { 0 };
	char szTemp[256] = { 0 };
	int iTempIndex = 0;
	int ssno = 0;
	int esno = 0;
	double weight = 0.0;

	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cout << "�޷����ļ�" << filename.c_str() << std::endl;
		exit(1);
	}

	while (!file.eof())
	{
		iTempIndex = 0, ssno = 0, esno = 0, weight = 0.0;
		memset((void *)szTemp, 0x00, sizeof(szTemp));
		memset((void *)szBuf, 0x00, sizeof(szBuf));

		file.getline(szBuf, sizeof(szBuf) - 1, '\n');
		if(szBuf[0] == NULL)
		{
			continue;
		}

		// ��������1�ģ��빹���ļ���ʱ��ÿһ�е��ַ���������< 255
		for (int index = 0; index < (int)strlen(szBuf) + 1; index++)
		{
			if (szBuf[index] != ' ' && szBuf[index] != '\0' && szBuf[0] != '\n')
			{
				szTemp[iTempIndex++] = szBuf[index];
			}else
			{
				if (szTemp[0] != '\0')
				{
					if(ssno == 0)
					{
						ssno = atoi(szTemp);
					}else if (esno == 0)
					{
						esno = atoi(szTemp);
					}else
					{
						weight = atof(szTemp);
						AddLine(ssno,esno, weight);
						break;
					}
				}

				iTempIndex = 0;
				memset((void *)szTemp, 0x00, sizeof(szTemp));
			}
		}// end for
	}// end while
	file.close();
}

//add poin
void CMap::AddPoin(double x, double y)
{
	poin_list.push_back(Poin(x, y));
}

//add line
void CMap::AddLine(int startpoinsno, int endpoinsno, double weight)
{
	line_list.push_back(Line(startpoinsno, endpoinsno, weight));
}

// ���ش洢poin��vector
std::vector<Poin> CMap::GetPoinList()
{
	return poin_list;
}

// ���ش洢Line��vector
std::vector<Line> CMap::GetLineList()
{
	return line_list;
}