
int merge(int a[n*n-1] , int start,int mid,int end){
    int temp[n*n-1];
    int pos = start;
    int i = start , j = mid+1;

    int invCount=0;

    while(i<=mid && j <= end){
        if(a[i]>a[j]){
            temp[pos++] = a[j++];
            invCount += (mid-i+1);
        }
        else{
            temp[pos++] = a[i++];
        }
    }

    while(i<=mid){
        temp[pos++]= a[i++];
    }
    while(j<=end){
        temp[pos++]= a[j++];
    }

    for(lli i=start;i<=end;i++){
        a[i] = temp[i];
    }

    return invCount;    

}


int mergesort(int start, int end , int a[n*n-1]){
    if(start>=end){
        return 0;
    }

    int mid = start + (end-start)/2;
    int invCount = 0;

    invCount += mergesort(start,mid,a);
    invCount += mergesort(mid+1,end,a);

    invCount += merge(a,start,mid,end);

    return invCount;

}

//Finds row position of blank cell from bottom
int find_blankRow_pos(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(initial[i][j]==0){
                return n-i;  
            }
        }
    }

    return -1;
}

// Checks if the current instance of sliding puzzle is solvable or not. 
bool isSolvable(){
    int a[n*n];
    int p=0;
    int zero;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(initial[i][j]==0)
                continue;
            a[p++] = initial[i][j];
        }
    }
    int inv_cnt=0;
    int x = n*n-1;
    int inv_cnt = mergesort(0,x-1,a);     // Returns the inversion count of the array in O(n^2log(n)) time complexity
    int pos = find_blankRow_pos();

    // For a grid of odd width , number of inversions should be even for the current instance of puzzle to be solvable
    if(n&1){
        if(inv_cnt&1){
            return 0;
        }
        else{
               return 1;
        }
    }
// For a grid of even width, the following is invariant: (#inversions even) == (blank on odd row from bottom). 
    else{
        int flag =pos+inv_cnt;
        if(flag&1){
               return 1;
        }
        else{
               return 0;
        }
    }


}
