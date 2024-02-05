#include <bits/stdc++.h>

using namespace std;

const int MAP_SIZE_X = 27;
const int MAP_SIZE_Y = 27;


float d_e(float a, float b){
    float ans = 0;
    float dx = MAP_SIZE_X / 2 - a;
    float dy = MAP_SIZE_Y /2 - b;
    ans = sqrt(dx * dx + dy * dy);
    return ans;
}

float d_t(float a, float b){
    float ans = 0;
    float dx = MAP_SIZE_X / 2 - a;
    float dy = MAP_SIZE_Y /2 - b;
    if(dx < 0){
        dx = -dx;
    }if(dy < 0){
        dy = -dy;
    }
    ans = dx + dy;
    return ans;
}

int print_gamestate(char arr[MAP_SIZE_X][MAP_SIZE_Y]){
    for(int a = 0; a < MAP_SIZE_X; a++){
        for(int b = 0; b < MAP_SIZE_Y; b++){
            cout << arr[a][b];
        }
        cout << endl;
    }
}

int main(){

    srand(time(0));

    /**
    # - wall
    X - box
    O - player
    o - orb
    x - orb on a box
      - air
    * - unassigned

    */
    char arr[MAP_SIZE_X][MAP_SIZE_Y];
    for(int a = 0; a < MAP_SIZE_X; a++){
        for(int b = 0; b < MAP_SIZE_Y; b++){
            arr[a][b] = '#';
        }
    }

    for(int a = 1; a < MAP_SIZE_X - 1; a++){
        for(int b = 1; b < MAP_SIZE_Y - 1; b++){
            arr[a][b] = '*';
        }
    }

    print_gamestate(arr);


    /// z[i] = b[i] * sin(a[i] * x + y)

    ///int t = 5;
    int t = 5;

    float f_a[t];
    float f_b[t];


    float r = 0;

    for(int a = 0; a < t; a++){
        float temp1 = rand() % 4 + 1;
        float temp2 = rand() % 4 + 1;

        f_a[a] = (temp1 + 0.2f * temp2);
        temp1 = rand() % 600 + 1;
        temp2 = rand() % 600 + 1;
        f_b[a] = (temp1 + 0.2f * temp2);
    }


    float z[MAP_SIZE_X][MAP_SIZE_Y];

    for(int a = 0; a < MAP_SIZE_X; a++){
        for(int b = 0; b < MAP_SIZE_Y; b++){
            z[a][b] = 0;
        }
    }

    for(int a = 1; a < MAP_SIZE_X - 1; a++){
        for(int b = 1; b < MAP_SIZE_Y - 1; b++){
            float f_z = 0;
            for(int c = 0; c < t; c++){
                ///cout << c << " ";
                f_z += f_b[c] * sin(f_a[c] * a + b);
            }
            f_z += -(t * 50.f) *(d_t(a, b) + d_e(a, b)) + (t * 1000);
            //cout << fixed << setprecision(2);
            ///cout << (int)f_z << " ";
            z[a][b] = f_z;
        }
        ///cout << endl;
    }

    float z_f[MAP_SIZE_X][MAP_SIZE_Y];

    for(int a = 1; a < MAP_SIZE_X - 1; a++){
        for(int b = 1; b < MAP_SIZE_Y - 1; b++){
            z_f[a][b] = 0;
            for(int a1 = -1; a1 <= 1; a1++){
                for(int b1 = -1; b1 <= 1; b1++){
                    z_f[a][b] = z[a + a1][b + b1];
                }
            }
        z_f[a][b] /= 9;
        }
    }


    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;

    for(int a = 1; a < MAP_SIZE_X - 1; a++){
        for(int b = 1; b < MAP_SIZE_Y - 1; b++){
            if(z_f[a][b] > 0){
                cout << " ";
            }else{
                cout << "#";
            }
        }
        cout << endl;
    }



    return 0;
}
