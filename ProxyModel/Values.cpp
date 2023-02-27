#include <vector>
#include "Values.h"

TableData::TableData()
{
};

QVariant TableData::getField1() const
 {
     return Field1;
 }
void TableData::setField1(float value)
 {
     Field1 = value;
 }
QVariant TableData::getField2() const
 {
     return Field2;
 }
void TableData::setField2(float value)
 {
     Field2 = value;
 }
QVariant TableData::getField3() const
 {
    return Field3;
 }
void TableData::setField3(float value)
 {
     Field3 = value;
 }

 QVariant TableData::getCheck(int id) const
 {
     if (chk.find(id)!= chk.end())
        return chk.at(id);
     else
        return false;
 }

 void TableData::setCheck(int rw, bool value)
 {
     chk[rw] = value;
     if (value == false)
        chk.erase(rw);
 }

 QVariant TableData::getValueByIndex(const int idx) const
 {
     //idx-=9;
     switch (idx)
     {
         case 1:
            {return getField1(); break;}
         case 2:
            {return getField2(); break;}
         case 3:
            {return getField3(); break;}
     default: break;
     }
 }

 void TableData::setValueByIndex(const int idx, float value)
 {
    switch (idx)
    {
        case 1:
            {setField1(value); break;}
        case 2:
            {setField2(value); break;}
        case 3:
            {setField3(value); break;}
    default: break;
    }
 }
