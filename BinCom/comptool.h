#ifndef COMPTOOL_H
#define COMPTOOL_H

#include <QString>
class CompTool
{
public:
    CompTool(QString str1,QString str2);
    int compare();
    inline int matchOffset()
    {
        return m_nOffset;
    }
private:
    QString m_str1;//�ַ�1
    QString m_str2;//�ַ�2
    int m_nOffset;//�ﵽ���ƥ����ʱ �ַ�1 ��������
    int m_nMatch;//
};

#endif // COMPTOOL_H
