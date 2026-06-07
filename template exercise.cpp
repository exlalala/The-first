#include <iostream>
using namespace std;

template<class T>
int Find(T* data, int size, T goal)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == goal)
            return i;
    }
    return -1;
}

template<class T>
void Sort(T* data, int size)
{
    for (int i = 0;i < size;i++)
    {
        for (int j = i+1;j < size;j++)
        {
            if (data[i] < data[j])
            {
                T temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

template<class T>
int FindMax(T* data, int size)
{
    int g = 0;
    for (int i = 1; i < size; i++)
    {
        if (data[i - 1] < data[i])
            g = data[i];
    }
    return g;
}


template<class A>
void SumandAver(A* data, int size)
{
    A sum = 0, aver = 0;
    for (int i = 0; i < size; i++)
    {
        sum += data[i];
    }
    aver = sum / size;
    cout << "sum=" << sum << "  aver=" << aver << endl;
}

template<class A>
void Output(A* data,int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i]<<"  ";
    }
    cout << endl;
}

int main()
{
    double data[] = { 12,56.2,178,5.6,1,100.5 };
    cout << "原数组：";
    Output(data, sizeof(data) / sizeof(data[0]));

    int result = Find(data, sizeof(data) / sizeof(data[0]), 5.6);
    if (result > -1)
        cout << "目标是第" << result + 1 << "个数" << endl;
    else   cout << "未找到目标！" << endl;

    Sort(data, sizeof(data) / sizeof(data[0]));
    cout << "排序后：";
    Output(data, sizeof(data) / sizeof(data[0]));

    int r2 = FindMax(data, sizeof(data) / sizeof(data[0]));
    cout << "最大值为第" << r2 + 1 << "个" << endl;

    SumandAver(data, sizeof(data) / sizeof(data[0]));
}
