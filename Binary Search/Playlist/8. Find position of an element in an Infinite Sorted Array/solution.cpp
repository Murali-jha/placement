class InfinetArray{
    public int fun(int arry[],int key,int start,int end) {
        while (start <= end) {
            if (arry[end] < key) {
                start=end;
                end = end *2;
            }
            if (arry[end] == key) {
                return end;
            } 
            else if (arry[end] > key) {
                int mid = start + (end - start) / 2;
                if (arry[mid] == key) {
                    return mid;
                } 
                else if (arry[mid] > key) {
                    end = mid - 1;
                } 
                else {
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
}
