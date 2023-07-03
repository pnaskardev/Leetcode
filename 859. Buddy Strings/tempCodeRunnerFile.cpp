int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]!=goal[i])
            {
                for(int j=i+1;j<n;j++)
                {
                    if(s[j]!=goal[j])
                    {
                        swap(s[i],s[j]);
                        if(s==goal)
                            return true;
                        else
                            return false;
                    }
                }
            }
        }    
        return false;