struct prioritize
{
    bool operator()(const Node* p1, const Node* p2) const
    {
        return (p1->cost + p1->level) > (p2->cost + p2->level);
    }
};


void A_Star(Node* src){

    priority_queue<Node* , std::vector<Node*> , prioritize> pq;

    Node* root = newNode(src->board , src->x_0 , src->y_0 , src->x_0 , src->y_0 , src->level , src->par);

    root->cost = heuristic_manhattan(root->board);
    pq.push(root);

    map<vector<int>,int> vis;
    while(!pq.empty()){

        Node* cur = pq.top();
        pq.pop();
        int x = cur->x_0;
        int y = cur->y_0;

        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans.push_back(cur->board[i][j]);
            }
        }

        vis[ans]=1;
       if(cur->cost == 0){

            cout << "SOLUTION STATE using A* star: " ;
            cout << " No. of moves ";
            cout << cur->level << "\n";
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

            if(check(nx,ny)){

                Node* temp = newNode(cur->board , cur->x_0 , cur->y_0 , nx , ny , cur->level+1 , cur);
                temp->cost = heuristic_manhattan(temp->board);

                vector<int> tmp;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        tmp.push_back(temp->board[i][j]);
                    }
                }

                if(!vis[tmp]){
                    
                    pq.push(temp);
                }
            }

        }

    }
}

//** 
// TIME COMPLEXITY - O(b^d) b is branching fator and d is maximum depth.
// MEMORY COMPLEXITY - O(b^d) b is branching fator and d is maximum depth.
//
