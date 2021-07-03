void bfs(Node* src){

    vector<int> dest;
    for(int i=0;i<n*n-1;i++){
        dest.push_back(i+1);
    }    

    dest.push_back(0);
    Node* root = newNode(src->board , src->x_0 , src->y_0 , src->x_0 , src->y_0 , src->level , src->par);

    queue<Node*> q;
    q.push(root);

    map<vector<int>,int> vis;

    while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        int x = cur->x_0;
        int y = cur->y_0;

        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans.push_back(cur->board[i][j]);
            }
        }

        vis[ans]=1;

        if(ans == dest){

            cout << "SOLUTION STATE using BFS: " ;
            cout << " No. of moves ";
            cout << cur->level << "\n\n";
            m=0;
            print_moves(cur);
            int x=0;

            for(int i=m-1;i>=0;i--){
                cout << "Move : " << x++ << "\n";
                print(moves[i]);
            }

            return;
        }

        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];

            if(check(nx,ny) ){

                Node* temp = newNode(cur->board , cur->x_0 , cur->y_0 , nx , ny , cur->level+1 , cur);

                vector<int> tmp;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        tmp.push_back(temp->board[i][j]);
                    }
                }

                if(!vis[tmp]){
                    q.push(temp);
                }
            }

        }

    }
}
//** 
// TIME COMPLEXITY - O(b^d) b is branching fator and d is maximum depth.
// MEMORY COMPLEXITY - O(b^d) b is branching fator and d is maximum depth.
//
