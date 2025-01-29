import java.util.Scanner;

public class bublesort {
    public static void main(String[] args) throws Exception {
        System.out.println("Enter the array size: ");
        Scanner input=new Scanner(System.in);
        int n=input.nextInt();
        int[] a = new int[n];

        System.out.println("Enter the array: ");
        for(int i=0;i<n;i++)
        {
            a[i]=input.nextInt();
        }

        int flag,temp;
        for (int i=0;i<n;i++)
        {
            flag=0;
            for (int j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    flag=1;
                }
            }
            if(flag==0)
            {
                break;
            }
        }
        
        System.out.println("After Sort:");
        for(int k=0;k<n;k++)
        {
            System.out.print(", "+a[k]);
        }
    }
}