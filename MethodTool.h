#pragma once
#include <stdlib.h> 
#include "DTCWT_BAND.h"
#include "WaterEncode.h"

class MethodTool
{
public:
	MethodTool();
	~MethodTool();
	void get16arr(int mlen, int flen);    //����16������   �����ݴ������� ȷ��Ƕ����һ������
	void getsrand(vector<double>& in, int num, int m_wwidth, int m_wheight);

	//16���������,Ƕ���ַ��� 
	vector<vector<double>> m_seq;
	vector<vector<double>>  f_seq;
	WaterEncode* encode;
	vector<vector<double>> m_seq_mid;
	vector<vector<double>> f_seq_mid;
	double energyCalc(vector<double>& v, int index, int len);
	double eng_ave;

};

