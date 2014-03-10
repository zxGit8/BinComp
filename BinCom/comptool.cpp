#include "comptool.h"


CompTool::CompTool(QString str1,QString str2)
{
    m_str1 = str1;
    m_str2 = str2;
    m_nMatch = -1;
}

//比较str1和str2
//返回最大匹配长度
//将匹配的位置存入数组
int CompTool::compare()
{
    int len1 = m_str1.length();
    int len2 = m_str2.length();


    //str1的起始位置为0，str2的起始位置为 len1-1

    for(int i=0; i< len1+len2-2; i++)
    {
        //1,2有效的比较部分左边界为 (len1-1)>i?(len1-1):i
        //右边界为 i<(len2-2)?(i+len1):(len1+len2-2)

        //B从第（）开始
        int startPos = (len1-1)>i?(len1-1):i;
        int endPos = i<(len2-1)?(i+len1):(len1+len2-1);

        //str1的 开始位置
        int startIndex1 = (len1-1)<i?0:(len1-1-i);

        //str2的开始位置
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
        else if(m_nMatch == matchLen)//取偏移最小的匹配情况
        {
            m_nOffset= qAbs(i+1-len1)<qAbs(m_nOffset)?(i+1-len1):m_nOffset;
        }

    }
    return m_nMatch;
}

