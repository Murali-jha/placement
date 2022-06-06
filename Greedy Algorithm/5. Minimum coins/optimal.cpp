int findMinimumCoins(int amount) 
{
    // Write your code here
    int arr[] = {1,2,5,10,20,50,100,500,1000};
    int n = 8;
    int count=  0;
    while(amount>0){
        if(arr[n]<=amount){
            amount-=arr[n];
            count++;
        }
        else{
            n--;
        }
    }
    return count;
}
