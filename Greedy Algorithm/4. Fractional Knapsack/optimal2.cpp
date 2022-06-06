bool static comp(Item a,Item b){
        return ((double)a.value/(double)a.weight) > ((double)b.value/(double)b.weight);
    }
    
    
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        double totalValue = 0;
        double currentWeight = 0;
        for(int i=0;i<n;i++){
            if(currentWeight + arr[i].weight <= W){
                totalValue+=(double)arr[i].value;
                currentWeight+= arr[i].weight;
            }
            else{
                double remaining = (double)W-currentWeight;
                totalValue+= (remaining * (double)arr[i].value) / (double)arr[i].weight;
                break;
                
            }
        }
        
        return totalValue;
    }
