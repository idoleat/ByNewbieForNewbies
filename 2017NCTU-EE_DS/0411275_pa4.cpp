#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;
//int CountLine(char filename[]);

int main(int argc,char *argv[])
{
    ifstream fin;
    ofstream fout;
    fin.open(argv[1]);
    fout.open(argv[2]);

    bool nega=false,NoPath=false;
    int i,j,a,b,from,to,fuck;
    int data_length;
    int **data;
    fin >> data_length;
    //setup 2d array
    data = new int*[data_length];
    int *Dis=new int[data_length];//Dis is the the shortest distance from root.
    int *root=new int[data_length];
    for(i = 0; i < data_length; i++)
        data[i] = new int[data_length];
    //initial
    for(i=0; i < data_length; i++)
    {
        for(j=0; j < data_length; j++)
        {
            data[i][j] = 2000000000;
        }
    }
    //input edge weight.
    int A=0, B, C;
    string s;
    while(1)
    {
        //cout<<"hi"<<endl;
        fin >> s;
        if(s == "#")
        {
            break;
        }
        for(i=(s.length()-1);i>=0;i--){
            A*=10;
            A+=(s[i]-48);
        }
        fin >> B >> C;
        data[A-1][B-1] = C;
        //cout<<A<<B<<C<<endl;
        A=0;
    }


    int tempt;
    stack<int> mystack;
    //int sum=0;
    //int line=CountLine(argv[1]);
    //cout<<line;
    while(fin>>from>>to)
    {
        //cout<<"from: "<<from<<" to: "<<to<<endl;
        for (i=0; i<data_length; i++) Dis[i] = 2000000000;
        for (i=0; i<data_length; i++) root[i] = -1;

        Dis[from-1] = 0;        //Dis is the the shortest distance from root.
        root[from-1] = from;    //set root

        for (i=0; i<(data_length-1); i++)
            for (a=0; a<data_length; a++)
                for (b=0; b<data_length; b++)
                    if (Dis[a] != 2000000000 && data[a][b] != 2000000000)
                        if (Dis[a] + data[a][b] < Dis[b])//update the distance.
                        {
                            Dis[b] = Dis[a] + data[a][b];
                            root[b] = a;
                        }
        //cout<<"1";
        //Have negative cycle?
        for (a=0; a<data_length; a++)

            for (b=0; b<data_length; b++)
                if (Dis[a] != 2000000000 && data[a][b] != 2000000000)
                    if (Dis[a] + data[a][b] < Dis[b])
                        nega = true;
        //cout<<"2";
        if(nega)
        {
            //cout<<"3";
            fout<<"Negative cycle";
            return 0;
        }
        //cout<<"4";

        //If no, print out the path
        tempt=to-1;
        NoPath = false;
        for(i=0; i<data_length; i++)
        {
            //sum+=data[root[tempt]][tempt];
            mystack.push(tempt+1);
            tempt=root[tempt];
            //cout<<"yoo"<<endl;
            if(tempt==(from-1))//stop when it reach the root.
            {
                mystack.push(tempt+1);
                mystack.push(Dis[to-1]);
                //sum=0;
                //cout<<"break"<<endl;
                break;
            }
            if(tempt==-1)//if there is no path between root and destination.
            {
                //cout<<"Big no no"<<endl;
                fout<<"no path";
                while(!mystack.empty())
                {
                    mystack.pop();
                }
                NoPath = true;
                break;
            }
        }
        while(!mystack.empty() && NoPath==false)
        {
            //cout<<"after break"<<endl;
            fout<<mystack.top()<<" ";
            mystack.pop();
        }
        fout<<endl;

    }

    //release memory
    for(i = 0; i < data_length; i++)
        delete [] data[i];
    delete [] data;

    fin.close();
    fout.close();
}

/*int CountLine(char filename[])
{
    int countt=0;
    ifstream infile;
    string s;
    infile.open(filename);

    getline(infile,s);
    countt+=1;

    infile.close();
    return countt;
}*/

/*void bellman_ford(int source, int n, int data[], int Dis[],int root)
{
    for (int i=0; i<n; i++) Dis[i] = 2000000000;

    Dis[source] = 0;              // 設定起點的最短路徑長度
    root[source] = source;    //set root

    for (int i=0; i<n-1; i++)   // 重覆步驟V-1次
        for (int a=0; a<n; ++a) // 全部的邊都當作捷徑
            for (int b=0; b<n; ++b)
                if (Dis[a] != 2000000000 && data[a][b] != 2000000000)
                    if (Dis[a] + data[a][b] < Dis[b])
                    {
                        Dis[b] = Dis[a] + w[a][b];
                        root[b] = a;
                    }
}*/

/*bool negative_cycle(int n, int data[],int Dis[])
{
    for (int a=0; a<n; ++a)
        for (int b=0; b<n; ++b)
            if (Dis[a] != 2000000000 && data[a][b] != 2000000000)
                if (Dis[a] + data[a][b] < Dis[b])
                    return true;
    return false;
}*/

/*void find_path(int x, int parent[],char filename[])
{
    ifstream infile;
    infile.open(filename);

    if (x != parent[x])
        find_path(parent[x]);
    infile << x << endl;
}*/

