#include<bits/stdc++.h>
using namespace std;

int  main(){
    int low ,high,ans = 0;
    cin >> low >> high;
    for(int i = low ; i <= high ;++i)
{
    int t1 = 0,t2 = 0,cnt = 0,j = i;
    while(j>0){
        j/=10;
        cnt++;
    }
    if(cnt%2 != 0)continue;
    if(cnt == 2){
        t1 = i/10;
        t2 = i%10;
    }
    else if(cnt == 4){
        t1 = i/100%10 + i/1000;
        t2 = i %10 + i/10%10;
    }

    if(t1 == t2)ans++;
}
cout << ans;

return 0;

}