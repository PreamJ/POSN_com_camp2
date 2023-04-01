    int arr[n+1][w+1];
    for(int i=0; i<n; i++){
        for(int j=0; j<w+1; j++){
            if(i==0 || j==0){
                arr[i][j] = 0;
            }
            else if(j < weight[i]){
                arr[i][j] = arr[i-1][j];
            }
            else{
                arr[i][j] = max(arr[i-1][j], value[i]+arr[i-1][j-weight[i]]);
            }
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << arr[n-1][w];