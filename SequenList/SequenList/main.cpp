//
//  main.cpp
//  SequenList
//
//  Created by 李海明 on 16/7/20. 老李飞刀
//  Copyright © 2016年 李海明. All rights reserved.
//

#include <iostream>
#define MAXSIZE 100
typedef int DataType;
using namespace std;
class SequenList
{
public:
     void Initiate(int n);//初始化
     int SetData(DataType x, int i);//设置链表元素
    int Length();//获取表厂
    int Insert(DataType x, int i);//插入
    int Deleted(int i);//删除
    int Locate(DataType x);//按值查找
    DataType Get(int i);//读取元素值
    void Out();//输出
private:
    DataType data[MAXSIZE];
    int len;//元素的个数
};

void SequenList::Initiate(int n)
{
    len = n;
}


int SequenList::Insert(DataType x, int i)
{
    int j;
    if(len>=MAXSIZE)
        {
        cout<<"overflow!"<<endl;
        return 0;
            }else if ((i<1)||(i>len+1))
                {
                    cout<<"位置不对！" <<endl;
                    return 0;
                    }else{
                        for(j=len; j>=i; j--)
                            {
                            data[j]=data[j-1];
                                }
                        data[i-1]=x;
                        len++;
                        return 1;
                        }
}

int SequenList::Deleted(int i)
{
    int j;
    if ((i<1)||(i>len))
        {
            cout<<"位置不对！" <<endl;
            return 0;
            }else{
                for(j=i;j<=len;j++)
                    {
                        data[j-1]=data[j];
                        }
                len--;
                return 1;
                }
}


int SequenList::Locate(DataType x)
{
int j=0;
    while((j<len)&&(data[j]!=x)) j++;
    if(j<len) return j+1;
    else return 0;
}

int SequenList::Get(int i)
{
    if ((i<1)||(i>len))
        {
            cout<<"位置不对！" <<endl;
            return NULL;
    }else return data[i-1];
}

int SequenList::Length()
{
    return len;
}

void SequenList::Out()//对的
{
    for(int i=0;i<len;i++)
        {
            cout<<data[i]<<endl;
            }
}

int SequenList::SetData(DataType x, int i)
{
    if(len>=MAXSIZE)
        {
            cout<<"overflow!"<<endl;
    return 0;
            }else if ((i<0)||(i>len))
                {
        cout<<"位置不对！" <<endl;
        return 0;
            }else{
                
                        data[i-1]=x;
                    //        len++;
                        return 1;
                }
}

int main(int argc, const char * argv[]) {
 // insert code here...
    //    std::cout << "Hello, World!\n";
    SequenList L;
    L.Initiate(3);
    //    L.Insert(20, 3);
    //    L.Insert(12, 1);
    L.SetData(11, 1);
    L.SetData(12, 2);
    L.SetData(13, 3);
    L.Insert(1, 3);
    //    L.Deleted(2);
    L.Out();
    int length,locate,value;
    length=L.Length();
    locate=L.Locate(12);
    value=L.Get(1);
    cout<<"表长＝"<<length<<endl;
    cout<<"位置＝"<<locate<<endl;
    cout<<"数值＝"<<value<<endl;
    return 0;
}

