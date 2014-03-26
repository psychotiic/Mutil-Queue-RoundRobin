#include<stdio.h>
#include<stdio.h>

    void main()
    {
            int i,j,Wt[10],B[10],A[10],Tt=0,temp,n,Bu[10],Pr[10];
            char S[20];
            float Twt=0.0,Awt;
            printf("Enter the number of processes");
           // cin>>n;
 	    scanf("%d",&n);
            for(i=1;i<=n;i++)
    {
           // cout<<"Enter the burst time for process P"<<i<<" ";
    	    printf("Enter the burst time for process P");
	    printf("%d\n",	i);
           // cin>>Bu[i];
 		scanf("%d",&Bu[i]);
    }
            for(i=1;i<=n;i++)
    {
            B[i]=Bu[i];
            Wt[i]=0;
            S[i]='T';
            Tt=Tt+B[i];
            //cout<<"\n Enter the arrival time for "<<i<<"th process ";
 	    printf("Enter the arival time for process P");
	    printf("%dth process\n",	i);
            //cin>>A[i];
	    scanf("%d",&A[i]);
    }
            for(i=1;i<=n;i++)
    {
           // cout<<"Enter the priority for process P"<<i<<" ";
            printf("Enter the priority for process P");
	    printf("%d\n",	i);
           // cin>>Pr[i];
	   scanf("%d",&Pr[i]);
    }
            int flag=0,t=0;
            temp=i=1;
            while(t<Tt)
    {
          //  cout<<"\n"<<B[i]<<"\t"<<i;
	    printf("\n  %d  %d",B[i],i);
            if(temp!=i)
    {
            Wt[i]=t-(Bu[i]-B[i]);
            temp=i;
    }
            B[i]=B[i]-1;
            if(B[i]==0)
            S[i]='F';
            t=t+1;
            if(S[i]!='F')
    {
            j=1;
            while(j<=n)
    {
            if(S[j]!='F' && A[j]<=t && i!=j &&Pr[j]==i)
    {
            i=j;
    }
            else
            j++;
    }
    }
            else
    {
            i++;
            if(i>n)
            i=1;
    }
    }
            for(i=1;i<=n;i++)
    {
          //  cout<<"\nWaiting time for process P "<<i<<" ="<<(Wt[i]-A[i]);
printf("\nWaiting time for process P");
printf("%d: ",i);
printf("%d",Wt[i]-A[i]);
            Twt+=(Wt[i]-A[i]);
printf(" milla-seconds \n");
    }
            Awt=Twt/n;
           // cout<<"\n The average waiting time is "<<Awt;
printf("\n The average waiting time is %lg\n",Awt);
}

  
