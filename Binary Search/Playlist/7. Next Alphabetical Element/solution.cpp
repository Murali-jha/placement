char nextGreatestLetter(vector<char>& letters, char target) {
        int res=-1;
        int n=letters.size();
        int first=0,last=n-1,mid;
        while(first<=last)
        {
            mid=first +(last-first)/2;
            if(letters[mid]>target)
            {
                res=mid;
                last=mid-1;
            }
            else
                first=mid+1;
        }
        if(res==-1)
            return letters[0];
        return letters[res];
    }
