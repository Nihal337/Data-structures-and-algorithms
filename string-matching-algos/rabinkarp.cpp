 vector<int> RabinKarp(const string& a, const string& s) { 
   
    int k = a.size(), n = s.size();
    vector<ll> p_pow(max(k, n)); 
    vector<int> occurrences;
    ll hashValue = 0; 
    vector<ll> pre(n + 1, 0); 
   
    p_pow[0] = 1; 
    for (int i = 1; i < p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * P) % MOD;

   
    for (int i = 0; i < n; i++)
        pre[i+1] = (pre[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD; 
    
   
    for (int i = 0; i < k; i++) 
        hashValue = (hashValue + (a[i] - 'a' + 1) * p_pow[i]) % MOD; 

    
    for (int i = 0; i + k - 1 < n; i++) {
        ll cur_hash = (pre[i+k] + MOD - pre[i]) % MOD;
        if (cur_hash == hashValue * p_pow[i] % MOD)
            occurrences.push_back(i);
    }
    return occurrences;
}
