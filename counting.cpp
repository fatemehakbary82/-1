#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int range) 
{
    int output[n];  //برای ذخیره نتایج مرتب سازی ایجاد میشوند
    int count[range+1] = {0};  //برای ذخیره تعداد تکرار هر عنصر ایجاد میشوند

    for (int i = 0; i < n; i++) //برای محاسبه تعداد تکرار هر عنصر از آرایه ورودی اجرا میشود
    {
        count[arr[i]]++;
    }

    for (int i = 1; i<= range; i++)  //برای محاسبه مقدار واقعی هر عنصر در آرایه خروجی اجرا میشود
    {
        count[i] += count[i-1];  //محاسبه تعداد عناصر کوچکتر یا مساوی هر عنصر
    }

    for (int i = n-1; i >= 0; i--) //برای انتقال اعضای آرایه خروجی به آرایه ورودی اجرا میشود
    {
        output[count[arr[i]]-1] = arr[i];   //مرتب سازی عناصر براساس مقادیر شمارش شده
        count[arr[i]]--;
    }

    for (int i = 0; i<n; i++)  //انتقال مقادیر مرتب شده به آرایه اصلی
    {
        arr[i] = output[i];
    }
}