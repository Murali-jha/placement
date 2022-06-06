bool static comp(Item a,Item b){
        return (double)a.value/(double)a.weight > (double)b.value/(double)b.weight;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        double ans = 0;
        for(int i=0;i<n;i++){
            if(arr[i].weight<W){
                W -= arr[i].weight;
                ans += (double)arr[i].value;
            }
            else{
                ans += (((double)W * (double)arr[i].value )/ (double)arr[i].weight);
                break;
            }
        }
        return ans;
    }
