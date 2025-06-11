#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    // unordered map hash[0, 1, 2, ,4,8,16,24]
    //                     [0, 0, 2, 0, 0, 0, 2]
    /*
    aab = 2      2^2=0
    abcac= 2     2^24 = 26
    dffe = 24    2^0=2
    ed = 24      24^24 = 0
    aa = 0
    aade = 24
    
    */
    //a/ab
    /*
    int x = c;
    for(int i = 0; i < S.size(); ++i)
    x^=(1<<S[i]-'a')
    */
    vector<string> palavras(N);
    for(int i = 0; i<N;i++){
        cin>>palavras[i];
    }
    count = 0;
    count += 
    return 0;
}