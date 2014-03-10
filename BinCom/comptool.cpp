#include "comptool.h"


CompTool::CompTool(QString str1,QString str2)
{
    m_str1 = str1;
    m_str2 = str2;
    m_nMatch = -1;
}

//�Ƚ�str1��str2
//�������ƥ�䳤��
//��ƥ���λ�ô�������
int CompTool::compare()
{
    int len1 = m_str1.length();
    int len2 = m_str2.length();


    //str1����ʼλ��Ϊ0��str2����ʼλ��Ϊ len1-1

    for(int i=0; i< len1+len2-2; i++)
    {
        //1,2��Ч�ıȽϲ�����߽�Ϊ (len1-1)>i?(len1-1):i
        //�ұ߽�Ϊ i<(len2-2)?(i+len1):(len1+len2-2)

        //B�ӵڣ�����ʼ
        int startPos = (len1-1)>i?(len1-1):i;
        int endPos = i<(len2-1)?(i+len1):(len1+len2-1);

        //str1�� ��ʼλ��
        int startIndex1 = (len1-1)<i?0:(len1-1-i);

        //str2�Ŀ�ʼλ��
        int startIndex2 = (len1-1)<i?(i-len1+1):0;

        int compLen = endPos - startPos;

        int matchLen = 0;
        for(int j=0; j< compLen; j++)
        {
            if(m_str1.at(startIndex1+j) == m_str2.at(startIndex2+j))
            {
                matchLen++;
            }

        }
        if(m_nMatch < matchLen)
        {
            m_nMatch = matchLen;
            m_nOffset= i+1-len1;

        }
        else if(m_nMatch == matchLen)//ȡƫ����С��ƥ�����
        {
            m_nOffset= qAbs(i+1-len1)<qAbs(m_nOffset)?(i+1-len1):m_nOffset;
        }

    }
    return m_nMatch;
}

