

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
    int cnt = mergesort(0,x-1,a);
    int pos = find_blankRow_pos();

    if(n&1){
        if(cnt&1){
            return 0;
        }
        else{
               return 1;
        }
    }

    else{
        int flag =pos+cnt;
        if(flag&1){
               return 1;
        }
        else{
               return 0;
        }
    }


}