bool isPalindrome(int x) {
    
    int n = x; long s = 0;
    if (x<0)
    {
        return false;
    }

    
    while (n!=0)
    {
        int p = n%10;
     s = s*10+p;
        n=n/10;
    }

    if (s==x)
    return true;

    else
    return false;
    
    


}
