#ifndef VALUES_H
#define VALUES_H

#include <string>
#include <vector>
#include <QString>
#include <QVariant>

struct TableData
{
    private:
        QVariant Check;
        QVariant Field1;
        QVariant Field2;
        QVariant Field3;

    public:
        TableData();
        std::map <int, bool> chk;

    QVariant getField1() const;
    void setField1(float value);
    QVariant getField2() const;
    void setField2(float value);
    QVariant getField3() const;
    void setField3(float value);
    QVariant getCheck(int id) const;
    void setCheck(int rw, bool value);
    QVariant getValueByIndex(const int idx) const;
    void setValueByIndex(const int idx, float value);
};

class Value
{
    public:
    TableData mean;

};

#endif // VALUES_H
