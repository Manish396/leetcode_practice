class Solution {
public:
    int square(int number)
    {
        int ans=0;
        while(number>0)
        {   int rem=number%10;
            ans+=rem*rem;
            number=number/10;  
            
        }
        return ans;
    }
    
    bool isHappy(int n) 
    {
        int slow=n;
        int fast=n;
        
        do
        {
            slow= square(slow);
            fast=square(square(fast));
        } while(slow!=fast);
        
        if(slow==1) 
            return true;
        
        return false; 
    }
};
