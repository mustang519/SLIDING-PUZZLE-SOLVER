int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

struct Node{
    Node* par;
    int board[n][n];
    int x_0;
    int y_0;
    int level;
    int cost;
};

Node* newNode(int board[n][n] , int x_0 , int y_0 , int nx , int ny, int level , Node* par){

    Node* temp = new Node;
    temp->par = par;

    memcpy(temp->board , board , sizeof temp->board );
    swap(temp->board[x_0][y_0] , temp->board[nx][ny]);

    temp->level = level;
    temp->x_0 = nx;
    temp->y_0 = ny;
    temp->cost = 1e9;

    return temp;

}

int heuristic_manhattan(int b[n][n]){

    int dist=0;
    map<int,pair<int,int>> val;

    int x=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            val[x] = make_pair(i,j);
            x++;
        }
    }
    val[0] = make_pair(n-1,n-1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist += abs(i-val[b[i][j]].first) + abs(j-val[b[i][j]].second);
        }
    }

    return dist;

}


int heuristic_misplaced(int b[n][n]){
    int cost=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b[i][j] && b[i][j]!=final[i][j]){
                cost++;
            }
        }
    }
    return cost;
}


void print(int a[n][n]){  

    for(int i=0;i<n;i++){
        cout << "[ " ;
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << "]\n";
    }
cout << "\n\n";
    
}

void print_moves(Node* cur){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            moves[m][i][j] = cur->board[i][j];
        }
    }
    m++;

    int f=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cur->board[i][j]!= initial[i][j])
                f=0;
            }
        }
        if(f)
            return;

    
    print_moves(cur->par);
}

bool check(int x , int y){
    if(x>=0 && x<n && y>=0 && y<n){
        return 1;
    }
    return 0;
}