#include <iostream>
#include <cmath>         // sin(.), cos(..)
#include <vector>

#define  PI  3.1415926535

using namespace std;
vector < vector<int> >target = { {0, 1},{-1, 1},{1, 0},{-2, 2} };
void rotate(float* nx, float* ny, float tx, float ty,  float q)
{
    float cosq = cos(q), sinq = sin(q);
    cout << cos(q) << endl;
    // 원점 O에 대하여 회전할 점 T를 q라디안 만큼 회전
    *nx = tx * cosq - ty * sinq;
    *ny = ty * cosq + tx * sinq;

    
    
    
}
double getDegree(double y, double x) {
    return atan2(y, x) * 180 / PI;
}



int main(void)
{
    float tx, ty, cx, cy, nx, ny;
    float deg, q;
    tx = -1;
    ty = 2;

    deg = 60;
    q = deg * PI / 180;

    int mx;
    int my;
    int mr;
    int r = 2;
    double target_d = atan2(ty, tx) * 180 / PI;
    cout << target_d << endl;
    for (int i = 0; i < target.size(); i++) {
        mx = target[i][0];
        my = target[i][1];
        cout << "mx :" << mx << endl;
        cout << "my :" << my << endl;
        
        if (pow(r,2) >= pow(mx,2)+ pow(my,2)) {
            // 회전 반경 구하기
            cout << "길이 맞음" << endl;
            double monster_d = atan2(my, mx) * 180 / PI;
            cout << monster_d << endl;
            if (monster_d < target_d + deg && monster_d > target_d - deg) {
                cout << "속함" << endl;
           }
        }

        cout << "----------" << endl;
    }

    rotate(&nx, &ny, tx, ty,  q);
    printf("\n점(%.0f,%.0f)을  \n%.f도 만큼 회전한 위치는 (%.0f,%.0f)입니다.\n", tx, ty,  deg, nx, ny);
    rotate(&nx, &ny, tx, ty,  -q);
    
    printf("\n점(%f,%f)을  \n%f도 만큼 회전한 위치는 (%.2f,%.2f)입니다.\n", tx, ty,  deg, nx, ny);
    return 0;
}