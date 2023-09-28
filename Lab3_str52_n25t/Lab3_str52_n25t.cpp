// Lab3_str52_n25t.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<stdio.h>
#include<stdlib.h>


using namespace std;

double getLen(double x1, double x2, double y1,double y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}
int main()
{
    setlocale(LC_ALL, "Russian");
    char a[90][1000] = {
        "42) цвет : зеленый; x1 = 5 , y1 = 20 ; x2 = 12 , y2 = 20,8 ; x3 = 40,6, y3 = 32;",
        "23) цвет : зеленый; x1 = 5 , y1 = 20 ; x2 = 12 , y2 = 20,8 ; x3 = 40,6, y3 = 32;",
        "23) цвет : зеленый; x1 = 3 , y1 = 3 ; x2 = 0 , y2 = 0 ; x3 = 3, y3 = 0;"
    };
    double s[1000];
    double maxSCount = 0;
    double maxS = 0;
    for (int i = 0; i < 2; i++) {
        int nextY = 0;
        int xCount = 0;
        int yCount = 0;
        float x1, x2, x3, y1, y2, y3;
        for (int j = 0; a[i][j] != '\0'; j++) {
          
            if (a[i][j] == 'x') {
                //cout << xCount << endl;
                double x = atof(&a[i][j + 4]);
                //cout << x << "x" << endl;
                if (x <= 21.0) { //21.0
                    switch (xCount)
                    {
                    case 0:
                        x1 = x;
                        //cout << x1 << "x1" << endl;
                        xCount += 1;
                        
                        break;
                    case 1:
                        x2 = x;
                        xCount += 1;
                        break;
                    case 2:
                        x3 = x;
                        xCount += 1;
                        break;
                    default:
                        break;
                    }
                    for (int k = j; a[i][k] != 'y'; k++) {
                        nextY = k + 1;
                    }
                    double y = atof(&a[i][nextY + 4]);
                    if (y <= 29.7) { //29.7
                        //cout << y << "y" << endl;
                        switch (yCount)
                        {
                        case 0:
                            y1 = y;
                            //cout << y1 << "y1" << endl;
                            yCount += 1;
                            break;
                        case 1:
                            y2 = y;
                            yCount += 1;
                            break;
                        case 2:
                            y3 = y;
                            yCount += 1;
                            break;
                        default:
                            break;
                        }
                    }
                    else {
                        cout << "Point are not in borders" << endl;
                        break;
                    }
                }
                else {
                    cout << "Point are not in borders" << endl;
                    break;
                }
                
            }
        }
        if (&x1 != nullptr and &x2 != nullptr and &x3 != nullptr and &y1 != nullptr and &y2 != nullptr and &y3 != nullptr) {
          

            double len1 = getLen(x1, x2, y1, y2);
            double len2 = getLen(x1, x3, y1, y3);
            double len3 = getLen(x2, x3, y2, y3);
            //cout << x1 << '\t' << x2 << '\t' << x3 << '\t' << y1 << '\t' << y2 << '\t' << y3 << endl;
            //cout << len1 << '\t' << len2 << '\t' << len3 << endl;
            if ((len1 + len2) > len3 and (len1 + len3) > len2 and (len2 + len3) > len1) {
                double p = (len1 + len2 + len3) / 2.;
                double s = sqrt(p * (p - len1) * (p - len2) * (p - len3));
                if (s > maxS) {
                    maxS = s;
                    maxSCount = 0;
                }
                else if (s == maxS) {
                    //cout << maxS << '\t' << s << endl;
                    maxSCount += 1;
                }

            }
    
        }
    }
    cout << maxSCount << endl;
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
