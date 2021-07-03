int IDDFS(Node *cur , int level , int threshold){

    int f = level + heuristic_manhattan(cur->board);

    if(f > threshold)
        return f;

    if(heuristic_manhattan(cur->board) == 0){
            cout << "SOLUTION STATE using IDA* star: " ;
            cout << " No. of moves ";
            cout << cur->level << "\n\n";
            m=0;
            print_moves(cur);
            int x=0;

            for(int i=m-1;i>=0;i--){
                cout << "Move : " << x++ << "\n";
                print(moves[i]);
            }
        return 0;
    }

    int mini = INT_MAX;

    for(int k=0;k<4;k++){
        int nx = cur->x_0 + dx[k];
        int ny = cur->y_0 + dy[k];

        if(check(nx,ny)){

            Node* temp = newNode(cur->board , cur->x_0 , cur->y_0 , nx , ny , cur->level+1 , cur);
                
            int bound = IDDFS(temp , level+1 , threshold);


            if(bound == 0){
                return 0;
            }

            mini = min(mini , bound);

        }
    }

    return mini;
}

void IDA_star(Node* src){

    Node* root = newNode(src->board , src->x_0 , src->y_0 , src->x_0 , src->y_0 , src->level , src->par);

    root->cost = heuristic_manhattan(root->board);

    int threshold = heuristic_manhattan(src->board);

    while(1){

        int temp_threshold = IDDFS(root , root->level , threshold);

        if(temp_threshold == 0){

            return;
        }

        threshold = temp_threshold;
    }

}

//** 
// TIME COMPLEXITY - O(b^d) b is branching fator and d is maximum depth.
// MEMORY COMPLEXITY - O(bd) b is branching fator and d is maximum depth.
**//
