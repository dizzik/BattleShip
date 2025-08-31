#include <bits/stdc++.h>

using namespace std;

#define DIM 17

int horizont,vert,ishit,isfull,rr,ss;
int a[DIM][DIM], used[DIM][DIM];
typedef pair<long long, long long> pll;
queue <pll> Q;
pll v;

void bfs(long long r, long long s, long long prevr, long long prevs, long long quantity){
    if(r<1 || r>10 || s<1 || s>10 || used[r][s]!=0) return;
    Q.push( {r,s} );

    used[r][s] = used[prevr][prevs]++;
}

void quadro(){
    while(!Q.empty())
        {
            v=Q.front();
            Q.pop();
            rr=v.first; ss=v.second;

            bfs(rr, ss+1, rr, ss, 4);
            bfs(rr, ss-1, rr, ss, 4);
            bfs(rr+1, ss, rr, ss, 4);
            bfs(rr-1, ss, rr, ss, 4);

            if(used[10][10] > 1) break;
        }
    cout << "Ended" << endl;
}

void triple(){

}

void duo(){
    while(!Q.empty())
        {
            v=Q.front();
            Q.pop();
            rr=v.first; ss=v.second;

            bfs(rr, ss+1, rr, ss, 2);
            bfs(rr, ss-1, rr, ss, 2);
            bfs(rr+1, ss, rr, ss, 2);
            bfs(rr-1, ss, rr, ss, 2);

            if(used[10][10] > 1) break;
        }
    cout << "Ended" << endl;
}

void FillCells(){

}

void DrawMap(){
    for (int i=1; i<=10; i++){
        for (int j=1; j<=10; j++){
            cout << used[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    while (1){
        cin >> vert >> horizont >> ishit >> isfull;
        Q.push({1,1});
        if (ishit == 1 && isfull == 0){
            a[vert][horizont] = -1;
            used[vert][horizont] = -1;
            duo();
        }

        if (ishit == 1 && isfull == 1){

        }
        DrawMap();
    }
    return 0;
}
