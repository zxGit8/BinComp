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
    QString m_str1;//字符1
    QString m_str2;//字符2
    int m_nOffset;//达到最大匹配数时 字符1 的左移数
    int m_nMatch;//
};

#endif // COMPTOOL_H
