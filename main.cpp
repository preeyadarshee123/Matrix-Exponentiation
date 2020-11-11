// Matrix Exponentiation

vector<vector<ll>> matrixMultiply(vector<vector<ll>> a,vector<vector<ll>> b){
    int sz = (int) a.size();
    vector<vector<ll>> c(sz,vector<ll> (sz,0));
    int n=(int)a.size();
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            for(int j=0;j<n;j++){
                c[i][j] += (a[i][k]*b[k][j]);
                c[i][j] %= inf;
            }
        }
    }
    return c;
}
vector<vector<ll>> matrixExp(vector<vector<ll>> t,ll n){
    int sz=(int)t.size();
    vector<vector<ll>> res(sz,vector<ll> (sz,0));
    for(int i=0;i<sz;i++){
        res[i][i]=1;
    }
    while(n){
        if(n%2){
            res=matrixMultiply(res,t);
        }
        t=matrixMultiply(t,t);
        n=n/2;
    }
    return res;
}
