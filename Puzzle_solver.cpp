# include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using lli =  int long long;
//#define ld long double;

const lli tot = 1e5+100;
const lli mod = 1e9+7;

const int n = 3;
int m;

int moves[10007][n][n];
int initial[n][n];
int final[n][n];

int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    IOS

    clock_t start  = clock();

    int x1,y1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            initial[i][j]=x;
            if(x==0){
                x1=i;
                y1=j;
            }
        }
    }

    int x=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            final[i][j] = x;
            x++;
        }
    }

    final[n-1][n-1]=0;

    Node* rt = newNode(initial,x1,y1,x1,y1,0,NULL);

    int choice;
    cout << "Enter 1 for BFS ." << "\n" << "Enter 2 for A* ." << "\n" << "Enter 3 for IDA* ." << "\n";
    cin >> choice;

    if(!isSolvable()){ 
        cout << "SORRY NOT SOLVABLE" << "\n";
        return 0;
    }
    else{
        cout << ":) SOLVABLE" << "\n";
    }
        
    if(choice==1){
        bfs(rt)
        clock_t end = clock();
        cout<<"Time taken to execute "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
    }
    else if(choice==2){
        A_Star(rt)
        clock_t end = clock();
        cout<<"Time taken to execute "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
    }
    else if(choice==3){
        IDA_star(rt)
        clock_t end = clock();
        cout<<"Time taken to execute "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
    }
    else{
        cout << "Wrong Choice" << "\n";
    }

    return 0;

}