#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;

void upLeft(char arr[9][12]){
    char temp[12];
    char tempp[3][3];

    tempp[0][0] = arr[2][3];tempp[0][2] = arr[0][3];tempp[2][2] = arr[0][5];tempp[2][0] = arr[2][5];
    tempp[0][1] = arr[1][3];tempp[1][2] = arr[0][4];tempp[2][1] = arr[1][5];tempp[1][0] = arr[2][4];
    tempp[1][1] = arr[1][4];

    temp[0] = arr[3][3];temp[1] = arr[3][4];temp[2] = arr[3][5];
    temp[3] = arr[3][6];temp[4] = arr[3][7];temp[5] = arr[3][8];
    temp[6] = arr[3][9];temp[7] = arr[3][10];temp[8] = arr[3][11];
    temp[9] = arr[3][0];temp[10] = arr[3][1];temp[11] = arr[3][2];

    for(int i=0; i<12; i++){
        arr[3][i] = temp[i];
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i][j+3] = tempp[i][j];
        }
    }
}

void upRight(char arr[9][12]){
    char temp[12];
    char tempp[3][3];

    tempp[0][0] = arr[0][5];tempp[0][2] = arr[2][5];tempp[2][2] = arr[2][3];tempp[2][0] = arr[0][3];
    tempp[0][1] = arr[1][5];tempp[1][2] = arr[2][4];tempp[2][1] = arr[1][3];tempp[1][0] = arr[0][4];
    tempp[1][1] = arr[1][4];

    temp[0] = arr[3][9];temp[1] = arr[3][10];temp[2] = arr[3][11];
    temp[3] = arr[3][0];temp[4] = arr[3][1];temp[5] = arr[3][2];
    temp[6] = arr[3][3];temp[7] = arr[3][4];temp[8] = arr[3][5];
    temp[9] = arr[3][6];temp[10] = arr[3][7];temp[11] = arr[3][8];

    for(int i=0; i<12; i++){
        arr[3][i] = temp[i];
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i][j+3] = tempp[i][j];
        }
    }
}

void leftDown(char arr[9][12]){
    char temp[12];
    char tempp[3][3];

    tempp[0][0] = arr[5][0];tempp[0][2] = arr[3][0];tempp[2][2] = arr[3][2];tempp[2][0] = arr[5][2];
    tempp[0][1] = arr[4][0];tempp[1][2] = arr[3][1];tempp[2][1] = arr[4][2];tempp[1][0] = arr[5][1];
    tempp[1][1] = arr[4][1];

    temp[0] = arr[5][11];temp[1] = arr[4][11];temp[2] = arr[3][11];
    temp[3] = arr[0][3];temp[4] = arr[1][3];temp[5] = arr[2][3];
    temp[6] = arr[3][3];temp[7] = arr[4][3];temp[8] = arr[5][3];
    temp[9] = arr[8][3];temp[10] = arr[7][3];temp[11] = arr[6][3];

    for(int i=0; i<9; i++){
        arr[i][3] = temp[i];
    }
    arr[3][11] = temp[9];arr[4][11] = temp[10]; arr[5][11] = temp[11];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i+3][j] = tempp[i][j];
        }
    }
}

void leftUp(char arr[9][12]){
    char temp[12];
    char tempp[3][3];

    tempp[0][0] = arr[3][2];tempp[0][2] = arr[5][2];tempp[2][2] = arr[5][0];tempp[2][0] = arr[3][0];
    tempp[0][1] = arr[4][2];tempp[1][2] = arr[5][1];tempp[2][1] = arr[4][0];tempp[1][0] = arr[3][1];
    tempp[1][1] = arr[4][1];

    temp[0] = arr[3][3];temp[1] = arr[4][3];temp[2] = arr[5][3];
    temp[3] = arr[6][3];temp[4] = arr[7][3];temp[5] = arr[8][3];
    temp[6] = arr[5][11];temp[7] = arr[4][11];temp[8] = arr[3][11];
    temp[9] = arr[2][3];temp[10] = arr[1][3];temp[11] = arr[0][3];

    for(int i=0; i<9; i++){
        arr[i][3] = temp[i];
    }
    arr[3][11] = temp[9];arr[4][11] = temp[10]; arr[5][11] = temp[11];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i+3][j] = tempp[i][j];
        }
    }
}

void frontRight(char arr[9][12]){
    char temp[12];
    char tempp[3][3];

    tempp[0][0] = arr[5][3];tempp[0][2] = arr[3][3];tempp[2][2] = arr[3][5];tempp[2][0] = arr[5][5];
    tempp[1][0] = arr[5][4];tempp[0][1] = arr[4][3];tempp[1][2] = arr[3][4];tempp[2][1] = arr[4][5];
    tempp[1][1] = arr[4][4];

    temp[0] = arr[5][2]; temp[1] = arr[4][2]; temp[2] = arr[3][2];
    temp[3] = arr[2][3]; temp[4] = arr[2][4]; temp[5] = arr[2][5];
    temp[6] = arr[3][6]; temp[7] = arr[4][6]; temp[8] = arr[5][6];
    temp[9] = arr[6][3]; temp[10] = arr[6][4]; temp[11] = arr[6][5];

    arr[2][3] = temp[0];arr[2][4] = temp[1];arr[2][5] = temp[2];
    arr[3][6] = temp[3];arr[4][6] = temp[4];arr[5][6] = temp[5];
    arr[6][5] = temp[6];arr[6][4] = temp[7];arr[6][3] = temp[8];
    arr[3][2] = temp[9];arr[4][2] = temp[10];arr[5][2] = temp[11];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i+3][j+3] = tempp[i][j];
        }
    }
}

void frontLeft(char arr[9][12]){
    char temp[12];
    char tempp[3][3];

    tempp[0][0] = arr[3][5];tempp[0][2] = arr[5][5];tempp[2][2] = arr[5][3];tempp[2][0] = arr[3][3];
    tempp[1][0] = arr[3][4];tempp[0][1] = arr[4][5];tempp[1][2] = arr[5][4];tempp[2][1] = arr[4][3];
    tempp[1][1] = arr[4][4];

    temp[8] = arr[5][2]; temp[7] = arr[4][2]; temp[6] = arr[3][2];
    temp[11] = arr[2][3]; temp[10] = arr[2][4]; temp[9] = arr[2][5];
    temp[0] = arr[3][6]; temp[1] = arr[4][6]; temp[2] = arr[5][6];
    temp[5] = arr[6][5]; temp[4] = arr[6][4]; temp[3] = arr[6][3];

    arr[2][3] = temp[0];arr[2][4] = temp[1];arr[2][5] = temp[2];
    arr[3][6] = temp[3];arr[4][6] = temp[4];arr[5][6] = temp[5];
    arr[6][3] = temp[6];arr[6][4] = temp[7];arr[6][5] = temp[8];
    arr[3][2] = temp[9];arr[4][2] = temp[10];arr[5][2] = temp[11];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i+3][j+3] = tempp[i][j];
        }
    }
}

void downRight(char arr[9][12]){
    char temp[12];
    char tempp[3][3];

    tempp[0][0] = arr[8][3];tempp[0][2] = arr[6][3];tempp[2][2] = arr[6][5];tempp[2][0] = arr[8][5];
    tempp[0][1] = arr[7][3];tempp[1][2] = arr[6][4];tempp[2][1] = arr[7][5];tempp[1][0] = arr[8][4];
    tempp[1][1] = arr[7][4];

    temp[0] = arr[5][9];temp[1] = arr[5][10];temp[2] = arr[5][11];
    temp[3] = arr[5][0];temp[4] = arr[5][1];temp[5] = arr[5][2];
    temp[6] = arr[5][3];temp[7] = arr[5][4];temp[8] = arr[5][5];
    temp[9] = arr[5][6];temp[10] = arr[5][7];temp[11] = arr[5][8];

    for(int i=0; i<12; i++){
        arr[5][i] = temp[i];
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i+6][j+3] = tempp[i][j];
        }
    }
}

void downLeft(char arr[9][12]){
    char temp[12];
    char tempp[3][3];

    tempp[0][0] = arr[6][5];tempp[0][2] = arr[8][5];tempp[2][2] = arr[8][3];tempp[2][0] = arr[6][3];
    tempp[0][1] = arr[7][5];tempp[1][2] = arr[8][4];tempp[2][1] = arr[7][3];tempp[1][0] = arr[6][4];
    tempp[1][1] = arr[7][4];

    temp[0] = arr[5][3];temp[1] = arr[5][4];temp[2] = arr[5][5];
    temp[3] = arr[5][6];temp[4] = arr[5][7];temp[5] = arr[5][8];
    temp[6] = arr[5][9];temp[7] = arr[5][10];temp[8] = arr[5][11];
    temp[9] = arr[5][0];temp[10] = arr[5][1];temp[11] = arr[5][2];

    for(int i=0; i<12; i++){
        arr[5][i] = temp[i];
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i+6][j+3] = tempp[i][j];
        }
    }
}

void rightUp(char arr[9][12]){
    char temp[12];
    char tempp[3][3];

    tempp[0][0] = arr[5][6];tempp[0][2] = arr[3][6];tempp[2][2] = arr[3][8];tempp[2][0] = arr[5][8];
    tempp[0][1] = arr[4][6];tempp[1][2] = arr[3][7];tempp[2][1] = arr[4][8];tempp[1][0] = arr[5][7];
    tempp[1][1] = arr[4][7];

    temp[0] = arr[3][5];temp[1] = arr[4][5];temp[2] = arr[5][5];
    temp[3] = arr[6][5];temp[4] = arr[7][5];temp[5] = arr[8][5];
    temp[6] = arr[5][11];temp[7] = arr[4][11];temp[8] = arr[3][11];
    temp[9] = arr[2][5];temp[10] = arr[1][5];temp[11] = arr[0][5];
    for(int i=0; i<9; i++){
        arr[i][6] = temp[i];
    }
    arr[3][11] = temp[9];arr[4][11] = temp[10]; arr[5][11] = temp[11];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i+3][j+6] = tempp[i][j];
        }
    }
}

void rightDown(char arr[9][12]){
    char temp[12];
    char tempp[3][3];

    tempp[0][0] = arr[3][8];tempp[0][2] = arr[5][8];tempp[2][2] = arr[5][6];tempp[2][0] = arr[3][6];
    tempp[0][1] = arr[4][8];tempp[1][2] = arr[5][7];tempp[2][1] = arr[4][6];tempp[1][0] = arr[3][7];
    tempp[1][1] = arr[4][7];

    temp[0] = arr[5][9];temp[1] = arr[4][9];temp[2] = arr[3][9];
    temp[3] = arr[0][5];temp[4] = arr[1][5];temp[5] = arr[2][5];
    temp[6] = arr[3][5];temp[7] = arr[4][5];temp[8] = arr[5][5];
    temp[9] = arr[8][5];temp[10] = arr[7][5];temp[11] = arr[6][5];

    for(int i=0; i<9; i++){
        arr[i][5] = temp[i];
    }
    arr[3][9] = temp[9];arr[4][9] = temp[10]; arr[5][9] = temp[11];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i+3][j+6] = tempp[i][j];
        }
    }
}

void backLeft(char arr[9][12]){
    char temp[12];
    char tempp[3][3];

    tempp[0][0] = arr[5][9];tempp[0][2] = arr[3][9];tempp[2][2] = arr[3][11];tempp[2][0] = arr[5][11];
    tempp[1][0] = arr[5][10];tempp[0][1] = arr[4][9];tempp[1][2] = arr[3][10];tempp[2][1] = arr[4][11];
    tempp[1][1] = arr[4][10];

    temp[6] = arr[5][0]; temp[7] = arr[4][0]; temp[8] = arr[3][0];
    temp[9] = arr[0][3]; temp[10] = arr[0][4]; temp[11] = arr[0][5];
    temp[0] = arr[3][8]; temp[1] = arr[4][8]; temp[2] = arr[5][8];
    temp[3] = arr[8][5]; temp[4] = arr[8][4]; temp[5] = arr[8][3];

    arr[0][3] = temp[0];arr[0][4] = temp[1];arr[0][5] = temp[2];
    arr[3][8] = temp[3];arr[4][8] = temp[4];arr[5][8] = temp[5];
    arr[8][5] = temp[6];arr[8][4] = temp[7];arr[8][3] = temp[8];
    arr[5][0] = temp[9];arr[4][0] = temp[10];arr[3][0] = temp[11];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i+3][j+9] = tempp[i][j];
        }
    }
}

void backRight(char arr[9][12]){
    char temp[12];
    char tempp[3][3];

    tempp[0][0] = arr[3][11];tempp[0][2] = arr[5][11];tempp[2][2] = arr[5][9];tempp[2][0] = arr[3][9];
    tempp[1][0] = arr[3][10];tempp[0][1] = arr[4][11];tempp[1][2] = arr[5][10];tempp[2][1] = arr[4][9];
    tempp[1][1] = arr[4][10];

    temp[0] = arr[5][0]; temp[1] = arr[4][0]; temp[2] = arr[3][0];
    temp[3] = arr[0][3]; temp[4] = arr[0][4]; temp[5] = arr[0][5];
    temp[6] = arr[3][8]; temp[7] = arr[4][8]; temp[8] = arr[5][8];
    temp[9] = arr[8][5]; temp[10] = arr[8][4]; temp[11] = arr[8][3];

    arr[0][3] = temp[0];arr[0][4] = temp[1];arr[0][5] = temp[2];
    arr[3][8] = temp[3];arr[4][8] = temp[4];arr[5][8] = temp[5];
    arr[8][5] = temp[6];arr[8][4] = temp[7];arr[8][3] = temp[8];
    arr[5][0] = temp[9];arr[4][0] = temp[10];arr[3][0] = temp[11];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i+3][j+9] = tempp[i][j];
        }
    }
}

string arrToString(char arr[9][12]){
    char a;
    string str;
    str.clear();
    for(int i=0; i<9; i++){
        for(int j=0; j<12; j++) {
            a=arr[i][j];
            str += a;
        }
    }

    return str;
}

int main(void){
    int T;
    int countt = 2;
    char com[9][12] = {
        {'0','0','0','1','1','1','0','0','0','0','0','0'},
        {'0','0','0','1','1','1','0','0','0','0','0','0'},
        {'0','0','0','1','1','1','0','0','0','0','0','0'},
        {'2','2','2','3','3','3','4','4','4','5','5','5'},
        {'2','2','2','3','3','3','4','4','4','5','5','5'},
        {'2','2','2','3','3','3','4','4','4','5','5','5'},
        {'0','0','0','6','6','6','0','0','0','0','0','0'},
        {'0','0','0','6','6','6','0','0','0','0','0','0'},
        {'0','0','0','6','6','6','0','0','0','0','0','0'}
    };
    char arr[9][12];
    char *ar = &arr[0][0];
    char step[12] = {'U','u','L','l','F','f','D','d','R','r','B','b'};
    //char white[3][3], green[3][3], red[3][3], blue[3][3], orange[3][3], yellow[3][3];
    char com1[9][12];
    char arr1[9][12];
    char dummy[3];
    bool jump = false;
    vector<string> Case, Complete;
    string temp;
    Case.push_back("dummy");
    Case.push_back("dummy");
    Case.push_back("U");Case.push_back("u");Case.push_back("L");Case.push_back("l");Case.push_back("F");Case.push_back("f");
    Case.push_back("D");Case.push_back("d");Case.push_back("R");Case.push_back("r");Case.push_back("B");Case.push_back("b");
    Complete.push_back("dummy");
    Complete.push_back("dummy");
    Complete.push_back("U");Complete.push_back("u");Complete.push_back("L");Complete.push_back("l");Complete.push_back("F");Complete.push_back("f");
    Complete.push_back("D");Complete.push_back("d");Complete.push_back("R");Complete.push_back("r");Complete.push_back("B");Complete.push_back("b");
    //build search tree
    while(Case[countt].length() <= 4){
        for(int i=0; i<12; i++){
            temp =Case[countt];
            Case.push_back(temp+=step[i]);
        }
        countt += 1;
    }
    //cout << Case.back();
    Complete = Case;
    map<string, int> fromCase, fromComplete;

    scanf("%d", &T);
    fgets(dummy, 15, stdin);
    for(int tt=0; tt<T; tt++){
        //initial
        fgets(dummy, 15, stdin);
        countt = 2;
        jump = false;
        //input
        for(int i=0; i<9; i++){
            fgets(ar+12*i, 15, stdin);
        }

        //using "meet in the middle"
        //I tried to use A* but I failed eventually. Because I can't find proper h(n).
        for(int i=0; i<5; i++){
            if(jump)break;
            while(Case[countt].length() <= i+1){
                for(int m=0; m<9; m++){
                    for(int n=0; n<12; n++){
                        arr1[m][n] = arr[m][n];
                    }
                }
                countt += 1;
                for(int j=0; j<Case[countt].length(); j++){
                    if(Case[countt][j] == 'U')upLeft(arr1);
                    else if(Case[countt][j] == 'u')upRight(arr1);
                    else if(Case[countt][j] == 'L')leftDown(arr1);
                    else if(Case[countt][j] == 'l')leftUp(arr1);
                    else if(Case[countt][j] == 'F')frontRight(arr1);
                    else if(Case[countt][j] == 'f')frontLeft(arr1);
                    else if(Case[countt][j] == 'D')downRight(arr1);
                    else if(Case[countt][j] == 'd')downLeft(arr1);
                    else if(Case[countt][j] == 'R')rightUp(arr1);
                    else if(Case[countt][j] == 'r')rightDown(arr1);
                    else if(Case[countt][j] == 'B')backLeft(arr1);
                    else if(Case[countt][j] == 'b')backRight(arr1);
                }
                fromCase.insert(pair<string, int>(arrToString(arr1),Case[countt].length()));
            }
            while(Complete[countt].length() <= i+1){
                for(int m=0; m<9; m++){
                    for(int n=0; n<12; n++){
                        com1[m][n] = com[m][n];
                    }
                }
                for(int j=0; j<Complete[countt].length(); j++){
                    if(Complete[countt][j] == 'U')upLeft(com1);
                    else if(Complete[countt][j] == 'u')upRight(com1);
                    else if(Complete[countt][j] == 'L')leftDown(com1);
                    else if(Complete[countt][j] == 'l')leftUp(com1);
                    else if(Complete[countt][j] == 'F')frontRight(com1);
                    else if(Complete[countt][j] == 'f')frontLeft(com1);
                    else if(Complete[countt][j] == 'D')downRight(com1);
                    else if(Complete[countt][j] == 'd')downLeft(com1);
                    else if(Complete[countt][j] == 'R')rightUp(com1);
                    else if(Complete[countt][j] == 'r')rightDown(com1);
                    else if(Complete[countt][j] == 'B')backLeft(com1);
                    else if(Complete[countt][j] == 'b')backRight(com1);
                }
                if(fromCase.find(arrToString(com1)) == fromCase.end()){
                    fromComplete.insert(pair<string ,int>(arrToString(com1), Complete[countt].length()));
                }
                else{
                    printf("%d\n", fromCase.find(arrToString(com1))->second + Complete[countt].length() );
                    jump = true;
                    break;
                }

            }
        }
        if(jump == false)printf("-1\n");
        if(jump == true)printf("wtf\n");
    }


    /*cout << endl;
    cout << "back left: " << endl;
    backLeft(arr);
    for(int i=0; i<9; i++){
        for(int j=0; j<12; j++){
            cout << arr[i][j];
        }
        cout <<endl;
    }
    cout <<endl;*/

    return 0;
}
//assign
    /*
    for(int i=0; i<3; i++){
        for(int j=3;j<6;j++){
            white[i][j-3] = arr[i][j]-48;
        }
    }

    for(int i=3; i<6; i++){
        for(int j=0;j<3;j++){
            orange[i-3][j] = arr[i][j]-48;
        }
        for(int j=3;j<6;j++){
            green[i-3][j-3] = arr[i][j]-48;
        }
        for(int j=6;j<9;j++){
            red[i-3][j-6] = arr[i][j]-48;
        }
        for(int j=9;j<12;j++){
            blue[i-3][j-9] = arr[i][j]-48;
        }
    }
    for(int i=6; i<9; i++){
        for(int j=3;j<6;j++){
            yellow[i-6][j-3] = arr[i][j]-48;
        }
    }*/
